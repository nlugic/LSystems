
#include "LSystemRenderer.h"
#include "..\..\include\glm\gtc\matrix_transform.hpp"
#include "..\..\include\stb_image_write.h"
#include <iostream>

#ifdef _DEBUG
#pragma comment (lib, "..\\..\\lib\\glfw3d.lib")
#else
#pragma comment (lib, "..\\..\\lib\\glfw3r.lib")
#endif

namespace lrend
{

	using OGLR = OGLRenderer;

	void *OGLR::owner = nullptr;
	int OGLR::width = defaultOGLRendererConfig.windowWidth;
	int OGLR::height = defaultOGLRendererConfig.windowHeight;
	GLFWwindow *OGLR::glWindow = nullptr;
	//bool OGLR::enableWireframe = false;
	bool OGLR::mouseMoved = false;
	double OGLR::lastXPos = OGLR::width / 2.0;
	double OGLR::lastYPos = OGLR::height / 2.0;
	float OGLR::deltaTime = 0.0f;
	float OGLR::lastFrame = 0.0f;
	OGLCamera *OGLR::camera = nullptr;
	unsigned OGLR::vao = 0U;
	unsigned OGLR::vbo = 0U;
	unsigned OGLR::ssbo = 0U;
	std::size_t OGLR::vertexBufSize = 0ULL;
	std::size_t OGLR::shaderStorageBufSize = 0ULL;
	OGLShader *OGLR::shaderProgram = nullptr;
	OGLArrayTexture *OGLR::textures = nullptr;

#ifdef _DEBUG
	unsigned OGLR::tqo = 0U;
#endif

	void OGLRenderer::initGLWindow(const char *caption)
	{
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

#ifdef _DEBUG
		glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);
#endif

		GLFWwindow *tWnd = glfwCreateWindow(OGLR::width, OGLR::height, caption, nullptr, nullptr);
		if (!tWnd)
		{
			std::cerr << "An error ocurred while creating the GLFW window." << std::endl;
			glfwTerminate();
			return;
		}

		glfwMakeContextCurrent(tWnd);

		if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress)))
		{
			std::cerr << "An error ocurred while loading functions with GLAD." << std::endl;
			return;
		}

		glViewport(0, 0, OGLR::width, OGLR::height);

		glfwSwapInterval(1);
		glfwSetInputMode(tWnd, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

		glfwSetKeyCallback(tWnd, OGLR::onKeyPress);
		glfwSetWindowSizeCallback(tWnd, OGLR::onWindowResize);
		glfwSetCursorPosCallback(tWnd, OGLR::onMouseMove);
		glfwSetScrollCallback(tWnd, OGLR::onMouseScroll);

#ifdef _DEBUG
		glGenQueries(1, &OGLR::tqo);
		glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
		glDebugMessageCallback(OGLR::processDebugMessage, nullptr);
#endif

		OGLR::glWindow = tWnd;
	}

	void OGLRenderer::destroyGLWindow()
	{
		if (OGLR::camera)
			delete OGLR::camera;
		if (OGLR::shaderProgram)
			delete OGLR::shaderProgram;
		if (OGLR::textures)
			delete OGLR::textures;

		glDeleteBuffers(1, &OGLR::ssbo);
		glDeleteBuffers(1, &OGLR::vbo);
		glDeleteVertexArrays(1, &OGLR::vao);
		glfwTerminate();

		OGLR::owner = nullptr;
		OGLR::width = defaultOGLRendererConfig.windowWidth;
		OGLR::height = defaultOGLRendererConfig.windowHeight;
		OGLR::glWindow = nullptr;
		//OGLR::enableWireframe = false;
		OGLR::mouseMoved = false;
		OGLR::lastXPos = OGLR::width / 2.0;
		OGLR::lastYPos = OGLR::height / 2.0;
		OGLR::deltaTime = OGLR::lastFrame = 0.0f;
		OGLR::camera = nullptr;
		OGLR::vao = OGLR::vbo = OGLR::ssbo = 0U;
		OGLR::vertexBufSize = OGLR::shaderStorageBufSize = 0ULL;
		OGLR::shaderProgram = nullptr;
		OGLR::textures = nullptr;

#ifdef _DEBUG
		glDeleteQueries(1, &OGLR::tqo);
		OGLR::tqo = 0U;
#endif
	}

	void OGLRenderer::initBuffers(const std::vector<float>& vertData, const std::vector<glm::mat4>& transformData)
	{
		OGLR::vertexBufSize = vertData.size();
		OGLR::shaderStorageBufSize = transformData.size();

#ifdef _DEBUG
		glBeginQuery(GL_TIME_ELAPSED, OGLR::tqo);
#endif

		glGenVertexArrays(1, &OGLR::vao);
		glBindVertexArray(OGLR::vao);

		glGenBuffers(1, &OGLR::vbo);
		glBindBuffer(GL_ARRAY_BUFFER, OGLR::vbo);
		glBufferData(GL_ARRAY_BUFFER, OGLR::vertexBufSize * sizeof(float), vertData.data(), GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(lsys::Vertex) + sizeof(float), nullptr);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(lsys::Vertex) + sizeof(float),
			reinterpret_cast<const void *>(3 * sizeof(float)));
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(lsys::Vertex) + sizeof(float),
			reinterpret_cast<const void *>(6 * sizeof(float)));
		glEnableVertexAttribArray(2);
		glVertexAttribPointer(3, 1, GL_FLOAT, GL_FALSE, sizeof(lsys::Vertex) + sizeof(float),
			reinterpret_cast<const void *>(9 * sizeof(float)));
		glEnableVertexAttribArray(3);

		glGenBuffers(1, &OGLR::ssbo);
		glBindBuffer(GL_SHADER_STORAGE_BUFFER, OGLR::ssbo);
		glBufferData(GL_SHADER_STORAGE_BUFFER, OGLR::shaderStorageBufSize * sizeof(glm::mat4),
			transformData.data(), GL_STATIC_DRAW);
		glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 0, OGLR::ssbo);

#ifdef _DEBUG
		glEndQuery(GL_TIME_ELAPSED);

		GLuint64 elapsedTime = 0ULL;
		glGetQueryObjectui64v(OGLR::tqo, GL_QUERY_RESULT, &elapsedTime);

		std::clog << "Initializing the buffers took " << elapsedTime << " nanoseconds." << std::endl;

		glObjectLabel(GL_VERTEX_ARRAY, OGLR::vao, 9, "Main VAO");
		glObjectLabel(GL_BUFFER, OGLR::vbo, 9, "Mesh VBO");
		glObjectLabel(GL_BUFFER, OGLR::ssbo, 21, "Mesh transforms SSBO");
#endif

		glBindVertexArray(0U);
		glBindBuffer(GL_ARRAY_BUFFER, 0U);
		glBindBuffer(GL_SHADER_STORAGE_BUFFER, 0U);
	}

	void OGLRenderer::initCamera(const OGLCameraConfig& cameraConfig)
	{
		if (OGLR::camera)
			delete OGLR::camera;
		OGLR::camera = new OGLCamera(cameraConfig);
	}

	void OGLRenderer::initShader(const char *vertexPath, const char *tessCtrlPath, const char *tessEvalPath,
		const char *geometryPath, const char *fragmentPath)
	{
		if (OGLR::shaderProgram)
			delete OGLR::shaderProgram;
		OGLR::shaderProgram = new OGLShader(vertexPath, tessCtrlPath, tessEvalPath,
			geometryPath, fragmentPath);
	}

	void OGLRenderer::initTextures(const std::vector<const char *>& texturePaths, int w, int h)
	{
		if (OGLR::textures)
			delete OGLR::textures;

		OGLR::textures = new OGLArrayTexture(texturePaths, w, h);
	}

	void OGLRenderer::initLighting(const glm::vec4& lightPosition, const glm::vec3& lightAttenuation, 
		const glm::vec3& lightAmbient, const glm::vec3& lightDiffuse, const glm::vec3& lightSpecular, float shininess)
	{
		OGLR::shaderProgram->setFloatVx4("light.position", lightPosition);
		OGLR::shaderProgram->setFloatVx3("light.attenuation", lightAttenuation);
		OGLR::shaderProgram->setFloatVx3("light.ambient", lightAmbient);
		OGLR::shaderProgram->setFloatVx3("light.diffuse", lightDiffuse);
		OGLR::shaderProgram->setFloatVx3("light.specular", lightSpecular);
		OGLR::shaderProgram->setFloat("light.shininess", shininess);
	}
	
#ifdef _DEBUG
	void APIENTRY OGLRenderer::processDebugMessage(GLenum source, GLenum type, GLenum id, GLenum severity,
		GLsizei length, const GLchar *message, const void *param)
	{
		std::cerr << std::hex << ((type == GL_DEBUG_TYPE_ERROR) ? "Error [" : "Message [")
			<< "src = " << source << ", type = " << type << ", severity = " << severity << "]:"
			<< std::dec << std::endl << message << std::endl;
	}
#endif

	void OGLRenderer::takeScreenshot()
	{
		unsigned char *data = new unsigned char[OGLR::width * OGLR::height * 3];

		glReadPixels(0, 0, OGLR::width, OGLR::height, GL_RGB, GL_UNSIGNED_BYTE, data);

		std::string time(std::to_string(glfwGetTime()));
		time += ".jpg";

		stbi_flip_vertically_on_write(true);
		stbi_write_jpg(time.c_str(), OGLR::width, OGLR::height, 3, data, 0);

		delete[] data;
	}

	void OGLRenderer::processMoveKeys(GLFWwindow *wnd)
	{
		if (glfwGetKey(wnd, GLFW_KEY_W) == GLFW_PRESS)
			OGLR::camera->move(FORWARD, OGLR::deltaTime);
		if (glfwGetKey(wnd, GLFW_KEY_S) == GLFW_PRESS)
			OGLR::camera->move(BACKWARDS, OGLR::deltaTime);
		if (glfwGetKey(wnd, GLFW_KEY_A) == GLFW_PRESS)
			OGLR::camera->move(LEFT, OGLR::deltaTime);
		if (glfwGetKey(wnd, GLFW_KEY_D) == GLFW_PRESS)
			OGLR::camera->move(RIGHT, OGLR::deltaTime);
	}
	
	void OGLRenderer::onKeyPress(GLFWwindow *wnd, int key, int scancode, int action, int mode)
	{
		if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
			glfwSetWindowShouldClose(wnd, true);

		if (key == GLFW_KEY_PRINT_SCREEN && action == GLFW_PRESS)
			takeScreenshot();

		/*
		if (key == GLFW_KEY_F && action == GLFW_PRESS)
		{
			OGLR::enableWireframe = !OGLR::enableWireframe;
			OGLR::shaderProgram->setBool("enableWireframe", OGLR::enableWireframe);
		}
		*/

		if (key == GLFW_KEY_KP_ADD && action == GLFW_PRESS)
			static_cast<LSystemRenderer *>(OGLR::owner)->levelUp();
		if (key == GLFW_KEY_KP_SUBTRACT && action == GLFW_PRESS)
			static_cast<LSystemRenderer *>(OGLR::owner)->levelDown();
	}

	void OGLRenderer::onWindowResize(GLFWwindow *wnd, int w, int h)
	{
		OGLR::width = w;
		OGLR::height = h;

		glViewport(0, 0, w, h);
	}

	void OGLRenderer::onMouseMove(GLFWwindow *wnd, double xPos, double yPos)
	{
		if (!OGLR::mouseMoved)
		{
			OGLR::lastXPos = xPos;
			OGLR::lastYPos = yPos;
			OGLR::mouseMoved = true;
		}

		double xOff = xPos - OGLR::lastXPos;
		double yOff = OGLR::lastYPos - yPos;
		
		OGLR::lastXPos = xPos;
		OGLR::lastYPos = yPos;

		OGLR::camera->look(static_cast<float>(xOff), static_cast<float>(yOff));
	}

	void OGLRenderer::onMouseScroll(GLFWwindow *wnd, double xOff, double yOff)
	{
		OGLR::camera->zoom(static_cast<float>(yOff));
	}
	
	void OGLRenderer::updateVertexData(const std::vector<float>& vertData, const std::vector<glm::mat4>& transformData)
	{
		OGLR::vertexBufSize = vertData.size();
		OGLR::shaderStorageBufSize = transformData.size();

#ifdef _DEBUG
		glBeginQuery(GL_TIME_ELAPSED, OGLR::tqo);
#endif

		glBindVertexArray(OGLR::vao);
		glBindBuffer(GL_ARRAY_BUFFER, OGLR::vbo);
		glBindBuffer(GL_SHADER_STORAGE_BUFFER, OGLR::ssbo);

		glBufferSubData(GL_ARRAY_BUFFER, 0, OGLR::vertexBufSize * sizeof(float), vertData.data());
		glBufferSubData(GL_SHADER_STORAGE_BUFFER, 0, OGLR::shaderStorageBufSize * sizeof(glm::mat4), transformData.data());

#ifdef _DEBUG
		glEndQuery(GL_TIME_ELAPSED);

		GLuint64 elapsedTime = 0ULL;
		glGetQueryObjectui64v(OGLR::tqo, GL_QUERY_RESULT, &elapsedTime);

		std::clog << "Updating the buffers took " << elapsedTime << " nanoseconds." << std::endl;
#endif

		glBindVertexArray(0U);
		glBindBuffer(GL_ARRAY_BUFFER, 0U);
		glBindBuffer(GL_SHADER_STORAGE_BUFFER, 0U);
	}

	void OGLRenderer::renderScene(void *owner, std::vector<float>& vBuf, const std::vector<const char *>& texPaths,
		const std::vector<glm::mat4>& transMats, const OGLRendererConfig& config)
	{
		OGLR::owner = owner;
		OGLR::width = config.windowWidth;
		OGLR::height = config.windowHeight;
		OGLR::lastXPos = OGLR::width / 2.0;
		OGLR::lastYPos = OGLR::height / 2.0;

		OGLR::initGLWindow(config.windowCaption);
		OGLR::initBuffers(vBuf, transMats);
		std::swap(vBuf, std::vector<float> { });

		OGLR::initCamera(config.cameraConfig);
		OGLR::initShader(config.vertShaderPath, config.tessCtrlPath, config.tessEvalPath,
			config.geometryPath, config.fragShaderPath);
		OGLR::shaderProgram->use();
		OGLR::initLighting(config.lightPosition, config.lightAttenuation, config.lightAmbient,
			config.lightDiffuse, config.lightSpecular, config.specularShininess);
		if (!texPaths.empty())
			OGLR::initTextures(texPaths, config.textureWidth, config.textureHeight);

		glEnable(GL_DEPTH_TEST);
		glFrontFace(GL_CCW);
		glEnable(GL_CULL_FACE);
		glCullFace(GL_BACK);

		//glPatchParameteri(GL_PATCH_VERTICES, 4);

		glm::mat4 projection(glm::perspective(glm::radians(OGLR::camera->getFOV()),
			static_cast<float>(OGLR::width) / OGLR::height, 0.1f, 100.0f));
		glm::mat4 view(OGLR::camera->getViewMatrix());

		OGLR::shaderProgram->setFloatMx4("proj", projection);
		OGLR::shaderProgram->setFloatMx4("view", view);
		OGLR::shaderProgram->setFloatMx4("model", glm::mat4(1.0f));

		/*
		OGLR::shaderProgram->setFloat("outerX", 8.0f);
		OGLR::shaderProgram->setFloat("outerY", 6.0f);
		OGLR::shaderProgram->setFloat("innerX", 4.0f);
		OGLR::shaderProgram->setFloat("innerY", 3.0f);

		OGLR::shaderProgram->setBool("enableWireframe", OGLR::enableWireframe);
		OGLR::shaderProgram->setFloatVx3("viewport", glm::vec3(config.windowWidth, config.windowHeight, 1.0f));
		*/

		while (!glfwWindowShouldClose(OGLR::glWindow))
		{
			processMoveKeys(OGLR::glWindow);

			glClearColor(config.backgroundColor.x, config.backgroundColor.y, config.backgroundColor.z, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			glBindVertexArray(OGLR::vao);

			projection = glm::perspective(glm::radians(OGLR::camera->getFOV()),
				static_cast<float>(OGLR::width) / OGLR::height, 0.1f, 100.0f);
			view = OGLR::camera->getViewMatrix();

			OGLR::shaderProgram->setFloatMx4("proj", projection);
			OGLR::shaderProgram->setFloatMx4("view", view);

			OGLR::shaderProgram->setFloatVx3("viewPosition", OGLR::camera->getPosition());

			float currentFrame = static_cast<float>(glfwGetTime());
			OGLR::deltaTime = currentFrame - OGLR::lastFrame;
			OGLR::lastFrame = currentFrame;

			glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(OGLR::vertexBufSize
				/ (sizeof(lsys::Vertex) / sizeof(float) + 1U)));

			//glDrawArrays(GL_PATCHES, 0, static_cast<GLsizei>(OGLR::vertexBufSize
			//	/ (sizeof(lsys::Vertex) / sizeof(float) + 1U)));

			glfwSwapBuffers(OGLR::glWindow);
			glfwPollEvents();
		}

		OGLR::destroyGLWindow();
	}

}
