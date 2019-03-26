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
		glm::vec3 cameraPosition;
		glm::vec4 lightPosition;
		glm::vec3 lightAttenuation;
		glm::vec3 lightAmbient, lightDiffuse, lightSpecular;
		float specularShininess;
		const char *vertShaderPath, *tessCtrlPath, *tessEvalPath, *geometryPath, *fragShaderPath;
		const char *windowCaption;
	};

	const OGLRendererConfig defaultOGLRendererConfig =
	{
		1280U, 720U, 256U, 256U,
		glm::vec3(0.9f, 0.9f, 0.9f),
		glm::vec3(0.0f, 1.0f, 3.0f),
		glm::vec4(0.0f, 10.0f, 5.0f, 0.0f),
		glm::vec3(1.0f, 0.0f, 0.0f),
		glm::vec3(0.3f, 0.3f, 0.3f),
		glm::vec3(0.9f, 0.9f, 0.9f),
		glm::vec3(0.2f, 0.2f, 0.2f), 32.0f,
		"..\\LSystemRenderer\\default.vert",
		"..\\LSystemRenderer\\default.tesc", "..\\LSystemRenderer\\default.tese",
		"..\\LSystemRenderer\\wireframe.geom", "..\\LSystemRenderer\\default.frag",
		"L-System Renderer"
	};

	class OGLRenderer
	{
	private:
		static void *owner;

		static int width, height;
		static GLFWwindow *glWindow;

		static bool enableWireframe;

		static bool mouseMoved;
		static double lastXPos, lastYPos;
		static float deltaTime, lastFrame;
		static OGLCamera *camera;

		static unsigned vao, vbo, ssbo;
		static std::size_t vertexBufSize, shaderStorageBufSize;
		static OGLShader *shaderProgram;
		static OGLArrayTexture *textures;

#ifdef _DEBUG
		static unsigned tqo;
#endif

		OGLRenderer(const OGLRenderer&) = delete;
		OGLRenderer& operator=(const OGLRenderer&) = delete;

		static void initGLWindow(const char *caption);
		static void destroyGLWindow();
		static void initBuffers(const std::vector<float>& vertData, const std::vector<glm::mat4>& transformData);
		static void initCamera(const glm::vec3& position);
		static void initShader(const char *vertexPath, const char *tessCtrlPath, const char *tessEvalPath,
			const char *geometryPath, const char *fragmentPath);
		static void initLighting(const glm::vec4& position, const glm::vec3& attenuation, const glm::vec3& ambient,
			const glm::vec3& diffuse, const glm::vec3& specular, float shininess);
		static void initTextures(const std::vector<const char *>& paths, int w, int h);
		
#ifdef _DEBUG
		static void APIENTRY processDebugMessage(GLenum source, GLenum type, GLenum id, GLenum severity,
			GLsizei length, const GLchar *message, const void *param);
#endif

		static void takeScreenshot();
		static void processMoveKeys(GLFWwindow *wnd);
		static void onKeyPress(GLFWwindow *wnd, int key, int scancode, int action, int mode);
		static void onWindowResize(GLFWwindow *wnd, int w, int h);
		static void onMouseMove(GLFWwindow *wnd, double xPos, double yPos);
		static void onMouseScroll(GLFWwindow *wnd, double xOff, double yOff);

	public:
		static void updateVertexData(const std::vector<float>& vertData, const std::vector<glm::mat4>& transformData);
		static void renderScene(void *owner, std::vector<float>& vBuf, const std::vector<const char *>& texPaths,
			const std::vector<glm::mat4>& transMats, const OGLRendererConfig& config = defaultOGLRendererConfig);
	};

}

#endif
