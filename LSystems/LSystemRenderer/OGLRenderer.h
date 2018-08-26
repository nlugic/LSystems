#ifndef OGLRENDERER_H
#define OGLRENDERER_H

#include "OGLCamera.h"
#include "OGLShader.h"
#include "OGLTexture.h"
#include "..\..\include\glad\glad.h"
#include "..\..\include\GLFW\glfw3.h"
#include <string>
#include <vector>

namespace lrend
{
	
	const unsigned defaultWidth = 1024;
	const unsigned defaultHeight = 768;
	const glm::vec3 defaultCamPos = glm::vec3(0.0f, 0.0f, 3.0f);

	class OGLRenderer
	{
	private:
		static int width, height;
		static GLFWwindow *glWindow;

		static bool mouseMoved;
		static double lastXPos, lastYPos;
		static float deltaTime, lastFrame;
		static OGLCamera *camera;

		static unsigned vao, vbo;
		static std::vector<float> vertexBuffer;
		static OGLShader *shaderProgram;
		static std::vector<OGLTexture *> textures;

		OGLRenderer() = default;
		OGLRenderer(const OGLRenderer&) = delete;
		OGLRenderer& operator=(const OGLRenderer&) = delete;

		static void initGLWindow(const char *caption);
		static void destroyGLWindow();
		static void initVertexArrays(const std::vector<float>& data);
		static void initCamera(const glm::vec3& cameraPosition);
		static void initShader(const char *vertexPath, const char *fragmentPath);
		static void initTextures(const std::vector<const char *>& texturePaths);

		static void processInput(GLFWwindow *wnd);
		static void onWindowResize(GLFWwindow *wnd, int w, int h);
		static void onMouseMove(GLFWwindow *wnd, double xPos, double yPos);
		static void onMouseScroll(GLFWwindow *wnd, double xOff, double yOff);

	public:
		~OGLRenderer() = default;

		static void renderScene(const std::vector<float>& vBuf, const std::vector<const char *>& texPaths,
			unsigned w = defaultWidth, unsigned h = defaultHeight, const glm::vec3& cPos = defaultCamPos,
			const char *vSh = "../LSystemRenderer/shader.vert", const char *fSh = "../LSystemRenderer/shader.frag", const char *cap = "L-Systems Renderer");
	};
	
}

#endif
