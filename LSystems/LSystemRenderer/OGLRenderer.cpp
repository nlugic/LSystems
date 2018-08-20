
#include "OGLRenderer.h"

#include "..\..\include\glad\glad.h"

namespace lrend
{
	
	unsigned OGLRenderer::width = 800;
	unsigned OGLRenderer::height = 600;
	bool OGLRenderer::mouseMoved = false;
	unsigned OGLRenderer::lastXPos = 400;
	unsigned OGLRenderer::lastYPos = 300;
	float OGLRenderer::deltaTime = 0.0f;
	float OGLRenderer::lastFrame = 0.0f;
	OGLCamera OGLRenderer::camera = OGLCamera(glm::vec3(0.0f, 0.0f, 0.0f));

	GLFWwindow* OGLRenderer::initGLWindow(const char *caption)
	{
		glfwInit();
		glfwWindowHint(GLFW_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_VERSION_MINOR, 5);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		GLFWwindow *tWnd = glfwCreateWindow(width, height, caption, nullptr, nullptr);
		glfwMakeContextCurrent(tWnd);

		gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

		glViewport(0, 0, width, height);

		glfwSetInputMode(tWnd, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
		glfwSetWindowSizeCallback(tWnd, (GLFWwindowsizefun)onWindowResize);
		glfwSetCursorPosCallback(tWnd, (GLFWcursorposfun)onMouseMove);
		glfwSetScrollCallback(tWnd, (GLFWscrollfun)onMouseScroll);

		return tWnd;
	}

	OGLRenderer::OGLRenderer(unsigned w, unsigned h, const char *caption)
		:glWindow(OGLRenderer::initGLWindow(caption)), shaderProgram(nullptr)
	{
		OGLRenderer::width = w;
		OGLRenderer::height = h;
		OGLRenderer::lastXPos = w / 2;
		OGLRenderer::lastYPos = h / 2;
	}

	OGLRenderer::~OGLRenderer()
	{
		glDeleteBuffers(1, &vao);
		glDeleteBuffers(1, &vbo);

		delete shaderProgram;
		glfwTerminate();
	}

	void OGLRenderer::createShader(const char *vertexPath, const char *fragmentPath)
	{
		if (shaderProgram != nullptr)
			delete shaderProgram;
		shaderProgram = new OGLShader(vertexPath, fragmentPath);
	}

	void OGLRenderer::initArrays(float *data, size_t size)
	{
		glGenVertexArrays(1, &vao);
		glBindVertexArray(vao);
		glGenBuffers(1, &vbo);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);

		// izmeniti kasnije
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), nullptr);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), nullptr);
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), nullptr);
		glEnableVertexAttribArray(2);
	}

	void OGLRenderer::writeVBO(float *data, size_t size)
	{
		glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
	}

	void OGLRenderer::render()
	{
		glBindVertexArray(vao);

		while (!glfwWindowShouldClose(glWindow))
		{
			glClearColor(0.4f, 0.4f, 0.4f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			glDrawArrays(GL_TRIANGLE_STRIP, 0, 0); // count?

			glfwSwapBuffers(glWindow);
			glfwPollEvents();
		}
	}

	void OGLRenderer::processInput(GLFWwindow *wnd)
	{
		if (glfwGetKey(wnd, GLFW_KEY_ESCAPE) == GLFW_PRESS)
			glfwSetWindowShouldClose(wnd, true);

		if (glfwGetKey(wnd, GLFW_KEY_W) == GLFW_PRESS)
			OGLRenderer::camera.move(FORWARD, deltaTime);
		if (glfwGetKey(wnd, GLFW_KEY_S) == GLFW_PRESS)
			OGLRenderer::camera.move(BACKWARDS, deltaTime);
		if (glfwGetKey(wnd, GLFW_KEY_A) == GLFW_PRESS)
			OGLRenderer::camera.move(LEFT, deltaTime);
		if (glfwGetKey(wnd, GLFW_KEY_D) == GLFW_PRESS)
			OGLRenderer::camera.move(RIGHT, deltaTime);
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

		OGLRenderer::camera.look(xPos - lastXPos, lastYPos - yPos);

		OGLRenderer::lastXPos = xPos;
		OGLRenderer::lastYPos = yPos;
	}

	void OGLRenderer::onMouseScroll(GLFWwindow *wnd, double xOff, double yOff)
	{
		OGLRenderer::camera.zoom(yOff);
	}

}
