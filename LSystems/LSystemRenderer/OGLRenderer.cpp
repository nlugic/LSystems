
#include "OGLRenderer.h"
#include "..\..\include\glm\gtc\matrix_transform.hpp"
#include <iostream>

#pragma comment (lib, "..\\..\\lib\\glfw3d.lib")

namespace lrend
{

	using OGLR = OGLRenderer;

	int OGLR::width = defaultWidth;
	int OGLR::height = defaultHeight;
	GLFWwindow *OGLR::glWindow = nullptr;
	bool OGLR::mouseMoved = false;
	double OGLR::lastXPos = defaultWidth / 2.0;
	double OGLR::lastYPos = defaultHeight / 2.0;
	float OGLR::deltaTime = 0.0f;
	float OGLR::lastFrame = 0.0f;
	OGLCamera *OGLR::camera = nullptr;
	unsigned OGLR::vao = 0U;
	unsigned OGLR::vbo = 0U;
	unsigned OGLR::ebo = 0U;
	unsigned OGLR::ssbo = 0U;
	size_t OGLR::vertexBufSize = 0ULL;
	size_t OGLR::elementBufSize = 0ULL;
	size_t OGLR::shaderStorageBufSize = 0ULL;
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
		glDeleteBuffers(1, &OGLR::ebo);
		glDeleteBuffers(1, &OGLR::vbo);
		glDeleteVertexArrays(1, &OGLR::vao);
		glfwTerminate();

		OGLR::width = defaultWidth;
		OGLR::height = defaultHeight;
		OGLR::glWindow = nullptr;
		OGLR::mouseMoved = false;
		OGLR::lastXPos = defaultWidth / 2U;
		OGLR::lastYPos = defaultHeight / 2U;
		OGLR::deltaTime = 0.0f;
		OGLR::lastFrame = 0.0f;
		OGLR::camera = nullptr;
		OGLR::vao = 0U;
		OGLR::vbo = 0U;
		OGLR::ebo = 0U;
		OGLR::ssbo = 0U;
		OGLR::vertexBufSize = 0ULL;
		OGLR::elementBufSize = 0ULL;
		OGLR::shaderStorageBufSize = 0ULL;
		OGLR::shaderProgram = nullptr;
		OGLR::textures = nullptr;
	}

	void OGLRenderer::initBuffers(const std::vector<float>& vertData, const std::vector<unsigned>& elemData,
		const std::vector<glm::mat4>& transformData)
	{
		OGLR::vertexBufSize = vertData.size();
		OGLR::elementBufSize = elemData.size();
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

		glGenBuffers(1, &OGLR::ebo);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, OGLR::elementBufSize * sizeof(float), elemData.data(), GL_STATIC_DRAW);
		
		glGenBuffers(1, &OGLR::ssbo);
		glBindBuffer(GL_SHADER_STORAGE_BUFFER, OGLR::ssbo);
		glBufferData(GL_SHADER_STORAGE_BUFFER, OGLR::shaderStorageBufSize * sizeof(glm::mat4), transformData.data(), GL_STATIC_DRAW);
		glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 0, OGLR::ssbo);

		glBindVertexArray(0U);
		glBindBuffer(GL_ARRAY_BUFFER, 0U);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0U);
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

	void OGLRenderer::processInput(GLFWwindow *wnd)
	{
		if (glfwGetKey(wnd, GLFW_KEY_ESCAPE) == GLFW_PRESS)
			glfwSetWindowShouldClose(wnd, true);

		if (glfwGetKey(wnd, GLFW_KEY_W) == GLFW_PRESS)
			OGLR::camera->move(FORWARD, OGLR::deltaTime);
		if (glfwGetKey(wnd, GLFW_KEY_S) == GLFW_PRESS)
			OGLR::camera->move(BACKWARDS, OGLR::deltaTime);
		if (glfwGetKey(wnd, GLFW_KEY_A) == GLFW_PRESS)
			OGLR::camera->move(LEFT, OGLR::deltaTime);
		if (glfwGetKey(wnd, GLFW_KEY_D) == GLFW_PRESS)
			OGLR::camera->move(RIGHT, OGLR::deltaTime);
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
	
	void OGLRenderer::renderScene(const std::vector<float>& vBuf, const std::vector<unsigned>& eBuf,
		const std::vector<const char *>& texPaths, const std::vector<glm::mat4>& transMats,
		unsigned w, unsigned h, int texW, int texH, const glm::vec3& cPos, const char *vSh, const char *fSh, const char *cap)
	{
		OGLR::width = w;
		OGLR::height = h;
		OGLR::lastXPos = w / 2.0;
		OGLR::lastYPos = h / 2.0;

		OGLR::initGLWindow(cap);
		OGLR::initBuffers(vBuf, eBuf, transMats);
		glBindVertexArray(OGLR::vao);
		OGLR::initCamera(cPos);
		OGLR::initShader(vSh, fSh);
		OGLR::shaderProgram->use();
		OGLR::initTextures(texPaths, texW, texH);

		glEnable(GL_DEPTH_TEST);
		glFrontFace(GL_CCW);
		glEnable(GL_CULL_FACE);
		glCullFace(GL_BACK);
		glPolygonMode(GL_FRONT, GL_FILL);

		glm::mat4 projection = glm::perspective(glm::radians(OGLR::camera->getFOV()),
			(float)OGLR::width / OGLR::height, 0.1f, 100.0f);
		glm::mat4 view = OGLR::camera->getViewMatrix();

		OGLR::shaderProgram->setFloatMx4("proj", projection);
		OGLR::shaderProgram->setFloatMx4("view", view);

		while (!glfwWindowShouldClose(OGLR::glWindow))
		{
			processInput(OGLR::glWindow);

			glClearColor(0.8f, 0.8f, 0.8f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			projection = glm::perspective(glm::radians(OGLR::camera->getFOV()),
				(float)OGLR::width / OGLR::height, 0.1f, 100.0f);
			view = OGLR::camera->getViewMatrix();

			OGLR::shaderProgram->setFloatMx4("proj", projection);
			OGLR::shaderProgram->setFloatMx4("view", view);

			float currentFrame = (float)glfwGetTime();
			OGLR::deltaTime = currentFrame - OGLR::lastFrame;
			OGLR::lastFrame = currentFrame;
			
			glm::mat4 model = glm::mat4(1.0f);
			model = glm::translate(model, glm::vec3(0.0f, 0.0f, -3.0f));
			model = glm::rotate(model, (float)glfwGetTime() / 2.0f, glm::vec3(0.0f, 1.0f, 0.0f));
			shaderProgram->setFloatMx4("model", model);

			glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(OGLR::elementBufSize), GL_UNSIGNED_INT, nullptr);

			glfwSwapBuffers(OGLR::glWindow);
			glfwPollEvents();
		}

		OGLR::destroyGLWindow();
	}

}
