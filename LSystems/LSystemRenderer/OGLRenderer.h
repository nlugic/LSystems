#ifndef OGLRENDERER_H
#define OGLRENDERER_H

#include "OGLCamera.h"
#include "OGLShader.h"
#include "OGLArrayTexture.h"
#include "..\..\include\glad\glad.h"
#include "..\..\include\GLFW\glfw3.h"
#include <string>
#include <vector>

namespace lrend
{
	
	const unsigned defaultWidth = 1024;
	const unsigned defaultHeight = 768;
	const int defaultTexWidth = 256;
	const int defaultTexHeight = 256;
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

		static unsigned vao, vbo, ebo, ssbo;
		static size_t vertexBufSize, elementBufSize, shaderStorageBufSize;
		static OGLShader *shaderProgram;
		static OGLArrayTexture *textures;

		OGLRenderer() = default;
		OGLRenderer(const OGLRenderer&) = delete;
		OGLRenderer& operator=(const OGLRenderer&) = delete;

		static void initGLWindow(const char *caption);
		static void destroyGLWindow();
		static void initBuffers(const std::vector<float>& vertData, const std::vector<unsigned>& elemData,
			const std::vector<glm::mat4>& transformData);
		static void initCamera(const glm::vec3& cameraPosition);
		static void initShader(const char *vertexPath, const char *fragmentPath);
		static void initTextures(const std::vector<const char *>& texturePaths, int w, int h);

		static void processInput(GLFWwindow *wnd);
		static void onWindowResize(GLFWwindow *wnd, int w, int h);
		static void onMouseMove(GLFWwindow *wnd, double xPos, double yPos);
		static void onMouseScroll(GLFWwindow *wnd, double xOff, double yOff);

	public:
		~OGLRenderer() = default;

		static void renderScene(const std::vector<float>& vBuf, const std::vector<unsigned>& eBuf,
			const std::vector<const char *>& texPaths, const std::vector<glm::mat4>& transMats,
			unsigned w = defaultWidth, unsigned h = defaultHeight, int texW = defaultTexWidth, int texH = defaultTexHeight,
			const glm::vec3& cPos = defaultCamPos, const char *vSh = "../LSystemRenderer/shader.vert",
			const char *fSh = "../LSystemRenderer/shader.frag", const char *cap = "L-System Renderer");
	};

}

#endif
