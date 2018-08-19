#ifndef OGLRENDERER_H
#define OGLRENDERER_H

#include "OGLShader.h"
#include "OGLTexture.h"
#include "OGLCamera.h"

#include "..\..\include\GLFW\glfw3.h"

#include <vector>

namespace lrend
{

	class OGLRenderer
	{
	protected:
		unsigned width, height;
		GLFWwindow *glWindow;
		unsigned vao, vbo;
		OGLShader *shaderProgram;
		std::vector<OGLTexture *> textures;
		OGLCamera camera;

		GLFWwindow* initGLWindow(const char *caption);

	public:
		OGLRenderer(unsigned w = 800, unsigned h = 600, const char *caption = "L-System Renderer");
		OGLRenderer(const OGLRenderer& oglr) = delete;
		OGLRenderer& operator=(const OGLRenderer& oglr) = delete;
		virtual ~OGLRenderer();

		void createShader(const char *vertexPath, const char *fragmentPath);

		void initArrays(float *data, size_t size);
		void writeVBO(float *data, size_t size);
		void render();
	};

}

#endif
