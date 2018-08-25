
#include "OGLRenderer.h"

#include "..\..\include\glm\gtc\matrix_transform.hpp"

#include <iostream>

#pragma comment (lib, "..\\..\\lib\\glfw3d.lib")

namespace lrend
{

	int OGLRenderer::width = defaultWidth;
	int OGLRenderer::height = defaultHeight;
	GLFWwindow *OGLRenderer::glWindow = nullptr;
	bool OGLRenderer::mouseMoved = false;
	int OGLRenderer::lastXPos = defaultWidth / 2;
	int OGLRenderer::lastYPos = defaultHeight / 2;
	float OGLRenderer::deltaTime = 0.0f;
	float OGLRenderer::lastFrame = 0.0f;
	OGLCamera *OGLRenderer::camera = nullptr;
	unsigned OGLRenderer::vao = 0U;
	unsigned OGLRenderer::vbo = 0U;
	std::vector<float> OGLRenderer::vertexBuffer;
	OGLShader *OGLRenderer::shaderProgram = nullptr;
	std::vector<OGLTexture *> OGLRenderer::textures;

	void OGLRenderer::initGLWindow(const char *caption)
	{
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		GLFWwindow *tWnd = glfwCreateWindow(OGLRenderer::width, OGLRenderer::height, caption, nullptr, nullptr);
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

		glViewport(0, 0, OGLRenderer::width, OGLRenderer::height);

		glfwSwapInterval(1);
		glfwSetInputMode(tWnd, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
		glfwSetWindowSizeCallback(tWnd, OGLRenderer::onWindowResize);
		glfwSetCursorPosCallback(tWnd, OGLRenderer::onMouseMove);
		glfwSetScrollCallback(tWnd, OGLRenderer::onMouseScroll);

		OGLRenderer::glWindow = tWnd;
	}

	void OGLRenderer::destroyGLWindow()
	{
		if (OGLRenderer::camera)
			delete OGLRenderer::camera;
		if (OGLRenderer::shaderProgram)
			delete OGLRenderer::shaderProgram;

		glDeleteVertexArrays(1, &OGLRenderer::vbo);
		glDeleteVertexArrays(1, &OGLRenderer::vao);
		glfwTerminate();

		OGLRenderer::width = defaultWidth;
		OGLRenderer::height = defaultHeight;
		OGLRenderer::glWindow = nullptr;
		OGLRenderer::mouseMoved = false;
		OGLRenderer::lastXPos = defaultWidth / 2;
		OGLRenderer::lastYPos = defaultHeight / 2;
		OGLRenderer::deltaTime = 0.0f;
		OGLRenderer::lastFrame = 0.0f;
		OGLRenderer::camera = nullptr;
		OGLRenderer::vao = 0U;
		OGLRenderer::vbo = 0U;
		OGLRenderer::shaderProgram = nullptr;
	}

	void OGLRenderer::initVertexArrays(const std::vector<float>& data)
	{
		OGLRenderer::vertexBuffer = data;

		glGenVertexArrays(1, &OGLRenderer::vao);
		glBindVertexArray(OGLRenderer::vao);
		glGenBuffers(1, &OGLRenderer::vbo);
		glBindBuffer(GL_ARRAY_BUFFER, OGLRenderer::vbo);
		glBufferData(GL_ARRAY_BUFFER, OGLRenderer::vertexBuffer.size() * sizeof(float), OGLRenderer::vertexBuffer.data(), GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
		glEnableVertexAttribArray(0);
	}

	void OGLRenderer::initCamera(const glm::vec3& cameraPosition)
	{
		if (OGLRenderer::camera)
			delete OGLRenderer::camera;
		OGLRenderer::camera = new OGLCamera(cameraPosition);
	}

	void OGLRenderer::initShader(const char *vertexPath, const char *fragmentPath)
	{
		if (OGLRenderer::shaderProgram)
			delete OGLRenderer::shaderProgram;
		OGLRenderer::shaderProgram = new OGLShader(vertexPath, fragmentPath);
	}

	void OGLRenderer::processInput(GLFWwindow *wnd)
	{
		if (glfwGetKey(wnd, GLFW_KEY_ESCAPE) == GLFW_PRESS)
			glfwSetWindowShouldClose(wnd, true);

		if (glfwGetKey(wnd, GLFW_KEY_W) == GLFW_PRESS)
			OGLRenderer::camera->move(FORWARD, OGLRenderer::deltaTime);
		if (glfwGetKey(wnd, GLFW_KEY_S) == GLFW_PRESS)
			OGLRenderer::camera->move(BACKWARDS, OGLRenderer::deltaTime);
		if (glfwGetKey(wnd, GLFW_KEY_A) == GLFW_PRESS)
			OGLRenderer::camera->move(LEFT, OGLRenderer::deltaTime);
		if (glfwGetKey(wnd, GLFW_KEY_D) == GLFW_PRESS)
			OGLRenderer::camera->move(RIGHT, OGLRenderer::deltaTime);
	}

	void OGLRenderer::onWindowResize(GLFWwindow *wnd, int w, int h)
	{
		OGLRenderer::width = w;
		OGLRenderer::height = h;

		glViewport(0, 0, w, h);
	}

	void OGLRenderer::onMouseMove(GLFWwindow *wnd, double xPos, double yPos)
	{
		if (!OGLRenderer::mouseMoved)
		{
			OGLRenderer::lastXPos = xPos;
			OGLRenderer::lastYPos = yPos;
			OGLRenderer::mouseMoved = true;
		}

		float xOff = xPos - OGLRenderer::lastXPos;
		float yOff = OGLRenderer::lastYPos - yPos;

		OGLRenderer::lastXPos = xPos;
		OGLRenderer::lastYPos = yPos;

		OGLRenderer::camera->look(xOff, yOff);
	}

	void OGLRenderer::onMouseScroll(GLFWwindow *wnd, double xOff, double yOff)
	{
		OGLRenderer::camera->zoom(yOff);
	}
	
	void OGLRenderer::renderScene(const std::vector<float>& vBuf, const std::vector<OGLTexture *>& texData,
		unsigned w, unsigned h, const glm::vec3& cPos, const char *vSh, const char *fSh, const char *cap)
	{
		OGLRenderer::textures = texData;
		OGLRenderer::width = w;
		OGLRenderer::height = h;
		OGLRenderer::initGLWindow(cap);
		OGLRenderer::initVertexArrays(vBuf);
		OGLRenderer::initCamera(cPos);
		OGLRenderer::initShader(vSh, fSh);

		glEnable(GL_DEPTH_TEST);

		glBindVertexArray(OGLRenderer::vao);
		OGLRenderer::shaderProgram->use();

		glm::mat4 projection = glm::perspective(glm::radians(OGLRenderer::camera->getFOV()),
			(float)OGLRenderer::width / OGLRenderer::height, 0.1f, 100.0f);
		glm::mat4 view = OGLRenderer::camera->getViewMatrix();

		OGLRenderer::shaderProgram->setFloatMx4("proj", projection);
		OGLRenderer::shaderProgram->setFloatMx4("view", view);

		while (!glfwWindowShouldClose(OGLRenderer::glWindow))
		{
			processInput(OGLRenderer::glWindow);

			glClearColor(0.8f, 0.8f, 0.8f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			projection = glm::perspective(glm::radians(OGLRenderer::camera->getFOV()),
				(float)OGLRenderer::width / OGLRenderer::height, 0.1f, 100.0f);
			view = OGLRenderer::camera->getViewMatrix();

			OGLRenderer::shaderProgram->setFloatMx4("proj", projection);
			OGLRenderer::shaderProgram->setFloatMx4("view", view);

			float currentFrame = (float)glfwGetTime();
			OGLRenderer::deltaTime = currentFrame - OGLRenderer::lastFrame;
			OGLRenderer::lastFrame = currentFrame;
			
			glm::mat4 model = glm::mat4(1.0f);
			model = glm::translate(model, glm::vec3(0.0f, 0.0f, -5.0f));
			shaderProgram->setFloatMx4("model", model);

			glDrawArrays(GL_TRIANGLES, 0, OGLRenderer::vertexBuffer.size() / 3);

			glfwSwapBuffers(OGLRenderer::glWindow);
			glfwPollEvents();
		}

		OGLRenderer::destroyGLWindow();
	}

}
