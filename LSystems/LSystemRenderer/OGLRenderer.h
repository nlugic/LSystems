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
	
	struct OGLRendererConfig
	{
		unsigned windowWidth, windowHeight;
		unsigned textureWidth, textureHeight;
		glm::vec3 backgroundColor;
		glm::vec3 cameraPosition, lightPosition, lightAttenuation;
		glm::vec3 lightAmbient, lightDiffuse, lightSpecular;
		float specularShininess;
		const char *vertShaderPath, *fragShaderPath;
		const char *windowCaption;
	};

	const OGLRendererConfig defaultOGLRendererConfig =
	{
		1024U, 768U, 256U, 256U,
		glm::vec3(0.9f, 0.9f, 0.9f),
		glm::vec3(0.0f, 1.0f, 3.0f),
		glm::vec3(0.0f, 5.0f, 3.0f),
		glm::vec3(1.0f, 0.05f, 0.015f),
		glm::vec3(0.3f, 0.3f, 0.3f),
		glm::vec3(0.9f, 0.9f, 0.9f),
		glm::vec3(0.2f, 0.2f, 0.2f), 32.0f,
		"../LSystemRenderer/shader.vert",
		"../LSystemRenderer/shader.frag",
		"L-System Renderer"
	};

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
		static void initLighting(const glm::vec3& lightPosition, const glm::vec3& lightAttenuation,
			const glm::vec3& lightAmbient, const glm::vec3& lightDiffuse, const glm::vec3& lightSpecular, float shininess);
		static void initTextures(const std::vector<const char *>& texturePaths, int w, int h);

		static void processInput(GLFWwindow *wnd);
		static void onWindowResize(GLFWwindow *wnd, int w, int h);
		static void onMouseMove(GLFWwindow *wnd, double xPos, double yPos);
		static void onMouseScroll(GLFWwindow *wnd, double xOff, double yOff);

	public:
		~OGLRenderer() = default;

		static void renderScene(const std::vector<float>& vBuf, const std::vector<unsigned>& eBuf,
			const std::vector<const char *>& texPaths, const std::vector<glm::mat4>& transMats,
			const OGLRendererConfig& config = defaultOGLRendererConfig);
	};

}

#endif
