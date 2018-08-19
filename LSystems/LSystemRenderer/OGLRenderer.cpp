
#include "OGLRenderer.h"

#include "..\..\include\glad\glad.h"

namespace lrend
{

	GLFWwindow* OGLRenderer::initGLWindow(const char *caption)
	{
		glfwInit();
		glfwWindowHint(GLFW_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_VERSION_MINOR, 5);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		GLFWwindow *tWnd = glfwCreateWindow(width, height, caption, nullptr, nullptr);
		glfwMakeContextCurrent(tWnd);

		gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

		glfwSetInputMode(tWnd, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

		glViewport(0, 0, width, height);

		return tWnd;
	}

	OGLRenderer::OGLRenderer(unsigned w, unsigned h, const char *caption)
		:width(w), height(h), glWindow(initGLWindow(caption)), camera(glm::vec3(0.0f, 0.0f, 0.0f)) { }

	OGLRenderer::~OGLRenderer()
	{
		glDeleteBuffers(1, &vao);
		glDeleteBuffers(1, &vbo);

		delete shaderProgram;
		glfwTerminate();
	}

	void OGLRenderer::createShader(const char *vertexPath, const char *fragmentPath)
	{
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

}
