
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

	void OGLRenderer::initGLWindow(const char *caption)
	{
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		GLFWwindow *tWnd = glfwCreateWindow(OGLR::width, OGLR::height, caption, nullptr, nullptr);
		if (!tWnd)
		{
			std::cout << "An error ocurred while creating the GLFW window." << std::endl;
			glfwTerminate();
			return;
		}

		glfwMakeContextCurrent(tWnd);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			std::cout << "An error ocurred while loading functions with GLAD." << std::endl;
			return;
		}

		glViewport(0, 0, OGLR::width, OGLR::height);

		glfwSwapInterval(1);
		glfwSetInputMode(tWnd, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
		glfwSetKeyCallback(tWnd, OGLR::onKeyPress);
		glfwSetWindowSizeCallback(tWnd, OGLR::onWindowResize);
		glfwSetCursorPosCallback(tWnd, OGLR::onMouseMove);
		glfwSetScrollCallback(tWnd, OGLR::onMouseScroll);

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
		OGLR::mouseMoved = false;
		OGLR::lastXPos = OGLR::width / 2.0;
		OGLR::lastYPos = OGLR::height / 2.0;
		OGLR::deltaTime = OGLR::lastFrame = 0.0f;
		OGLR::camera = nullptr;
		OGLR::vao = OGLR::vbo = OGLR::ssbo = 0U;
		OGLR::vertexBufSize = OGLR::shaderStorageBufSize = 0ULL;
		OGLR::shaderProgram = nullptr;
		OGLR::textures = nullptr;
	}

	void OGLRenderer::initBuffers(const std::vector<float>& vertData, const std::vector<glm::mat4>& transformData)
	{
		OGLR::vertexBufSize = vertData.size();
		OGLR::shaderStorageBufSize = transformData.size();

		glGenVertexArrays(1, &OGLR::vao);
		glBindVertexArray(OGLR::vao);

		glGenBuffers(1, &OGLR::vbo);
		glBindBuffer(GL_ARRAY_BUFFER, OGLR::vbo);
		glBufferData(GL_ARRAY_BUFFER, OGLR::vertexBufSize * sizeof(float), vertData.data(), GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 10 * sizeof(float), nullptr);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 10 * sizeof(float), (const void *)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 10 * sizeof(float), (const void *)(6 * sizeof(float)));
		glEnableVertexAttribArray(2);
		glVertexAttribPointer(3, 1, GL_FLOAT, GL_FALSE, 10 * sizeof(float), (const void *)(9 * sizeof(float)));
		glEnableVertexAttribArray(3);

		glGenBuffers(1, &OGLR::ssbo);
		glBindBuffer(GL_SHADER_STORAGE_BUFFER, OGLR::ssbo);
		glBufferData(GL_SHADER_STORAGE_BUFFER, OGLR::shaderStorageBufSize * sizeof(glm::mat4), transformData.data(), GL_STATIC_DRAW);
		glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 0, OGLR::ssbo);

		glBindVertexArray(0U);
		glBindBuffer(GL_ARRAY_BUFFER, 0U);
		glBindBuffer(GL_SHADER_STORAGE_BUFFER, 0U);
	}

	void OGLRenderer::initCamera(const glm::vec3& cameraPosition)
	{
		if (OGLR::camera)
			delete OGLR::camera;
		OGLR::camera = new OGLCamera(cameraPosition);
	}

	void OGLRenderer::initShader(const char *vertexPath, const char *fragmentPath)
	{
		if (OGLR::shaderProgram)
			delete OGLR::shaderProgram;
		OGLR::shaderProgram = new OGLShader(vertexPath, fragmentPath);
	}

	void OGLRenderer::initTextures(const std::vector<const char *>& texturePaths, int w, int h)
	{
		if (OGLR::textures)
			delete OGLR::textures;

		OGLR::textures = new OGLArrayTexture(texturePaths, w, h);
		OGLR::shaderProgram->setInt("texLayers", static_cast<int>(texturePaths.size()));
	}

	void OGLRenderer::initLighting(const glm::vec3& lightPosition, const glm::vec3& lightAttenuation, 
		const glm::vec3& lightAmbient, const glm::vec3& lightDiffuse, const glm::vec3& lightSpecular, float shininess)
	{
		OGLR::shaderProgram->setFloatVx3("light.position", lightPosition);
		OGLR::shaderProgram->setFloatVx3("light.attenuation", lightAttenuation);
		OGLR::shaderProgram->setFloatVx3("light.ambient", lightAmbient);
		OGLR::shaderProgram->setFloatVx3("light.diffuse", lightDiffuse);
		OGLR::shaderProgram->setFloatVx3("light.specular", lightSpecular);
		OGLR::shaderProgram->setFloat("light.shininess", shininess);
	}

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

		glBindVertexArray(OGLR::vao);
		glBindBuffer(GL_ARRAY_BUFFER, OGLR::vbo);
		glBindBuffer(GL_SHADER_STORAGE_BUFFER, OGLR::ssbo);

		glBufferSubData(GL_ARRAY_BUFFER, 0, OGLR::vertexBufSize * sizeof(float), vertData.data());
		glBufferSubData(GL_SHADER_STORAGE_BUFFER, 0, OGLR::shaderStorageBufSize * sizeof(glm::mat4), transformData.data());

		glBindVertexArray(0U);
		glBindBuffer(GL_ARRAY_BUFFER, 0U);
		glBindBuffer(GL_SHADER_STORAGE_BUFFER, 0U);
	}

	void OGLRenderer::renderScene(void *owner, const std::vector<float>& vBuf, const std::vector<const char *>& texPaths,
		const std::vector<glm::mat4>& transMats, const OGLRendererConfig& config)
	{
		OGLR::owner = owner;
		OGLR::width = config.windowWidth;
		OGLR::height = config.windowHeight;
		OGLR::lastXPos = OGLR::width / 2.0;
		OGLR::lastYPos = OGLR::height / 2.0;

		OGLR::initGLWindow(config.windowCaption);
		OGLR::initBuffers(vBuf, transMats);
		OGLR::initCamera(config.cameraPosition);
		OGLR::initShader(config.vertShaderPath, config.fragShaderPath);
		OGLR::shaderProgram->use();
		OGLR::initLighting(config.lightPosition, config.lightAttenuation, config.lightAmbient,
			config.lightDiffuse, config.lightSpecular, config.specularShininess);
		OGLR::initTextures(texPaths, config.textureWidth, config.textureHeight);

		glEnable(GL_DEPTH_TEST);
		glFrontFace(GL_CCW);
		glEnable(GL_CULL_FACE);
		glCullFace(GL_BACK);
		glPolygonMode(GL_FRONT, GL_FILL);

		glm::mat4 projection(glm::perspective(glm::radians(OGLR::camera->getFOV()),
			static_cast<float>(OGLR::width) / OGLR::height, 0.1f, 100.0f));
		glm::mat4 view(OGLR::camera->getViewMatrix());
		glm::mat4 model(1.0f);

		OGLR::shaderProgram->setFloatMx4("proj", projection);
		OGLR::shaderProgram->setFloatMx4("view", view);
		OGLR::shaderProgram->setFloatMx4("model", model);

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

			glDrawArrays(GL_TRIANGLES, 0,
				static_cast<GLsizei>(OGLR::vertexBufSize / (sizeof(lsys::Vertex) / sizeof(float) + 1U)));

			glfwSwapBuffers(OGLR::glWindow);
			glfwPollEvents();
		}

		OGLR::destroyGLWindow();
	}

}
