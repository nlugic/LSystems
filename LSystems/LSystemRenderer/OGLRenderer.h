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
		unsigned int window_width, window_height, texture_width, texture_height;
		OGLCameraConfig camera_config;
		glm::vec3 background_color;
		glm::vec4 light_position;
		glm::vec3 light_attenuation, light_ambient, light_diffuse, light_specular;
		float specular_shininess;
		const char *vert_path, *frag_path, *geom_path, *tesc_path, *tese_path, *window_caption;
	};

	const OGLRendererConfig default_ogl_renderer_config =
	{
		1280u, 720u, 256u, 256u,
		default_ogl_camera_config,
		glm::vec3(0.9f, 0.9f, 0.9f),
		glm::vec4(0.0f, 10.0f, 5.0f, 0.0f),
		glm::vec3(1.0f, 0.0f, 0.0f),
		glm::vec3(0.3f, 0.3f, 0.3f),
		glm::vec3(0.9f, 0.9f, 0.9f),
		glm::vec3(0.2f, 0.2f, 0.2f), 32.0f,
		"..\\LSystemRenderer\\default.vert", "..\\LSystemRenderer\\default.frag",
		nullptr, nullptr, nullptr, "L-System Renderer"
	};

	class OGLRenderer
	{
	private:
		static void *owner;

		static int width, height;
		static GLFWwindow *gl_window;

		//static bool enable_wireframe;

		static bool mouse_moved;
		static double last_x_pos, last_y_pos;
		static float delta_time, last_frame;
		static OGLCamera *camera;

		static unsigned int vao, vbo, ssbo;
		static std::size_t vertex_buf_size, shader_storage_buf_size;
		static OGLShader *shader_program;
		static OGLArrayTexture *textures;

#ifdef _DEBUG
		static unsigned int tqo;
#endif

		OGLRenderer() = delete;
		OGLRenderer(const OGLRenderer&) = delete;
		OGLRenderer(OGLRenderer&&) = delete;
		OGLRenderer& operator=(const OGLRenderer&) = delete;
		~OGLRenderer() = delete;

		static void initGLWindow(const char *caption);
		static void destroyGLWindow();
		static void initBuffers(const std::vector<float>& vert_data, const std::vector<glm::mat4>& transform_data);
		static void initCamera(const OGLCameraConfig& config);
		static void initShader(const char *vert_path, const char *frag_path, const char *geom_path,
			const char *tesc_path, const char *tese_path);
		static void initLighting(const glm::vec4& position, const glm::vec3& attenuation, const glm::vec3& ambient,
			const glm::vec3& diffuse, const glm::vec3& specular, float shininess);
		static void initTextures(const std::vector<const char *>& texture_paths, int w, int h);
		
#ifdef _DEBUG
		static void APIENTRY processDebugMessage(GLenum source, GLenum type, GLenum id, GLenum severity,
			GLsizei length, const GLchar *message, const void *param);
#endif

		static void takeScreenshot();
		static void processMoveKeys(GLFWwindow *wnd);
		static void onKeyPress(GLFWwindow *wnd, int key, int scancode, int action, int mode);
		static void onWindowResize(GLFWwindow *wnd, int w, int h);
		static void onMouseMove(GLFWwindow *wnd, double x_pos, double y_pos);
		inline static void onMouseScroll(GLFWwindow *wnd, double x_off, double y_off)
			{ OGLRenderer::camera->zoom(static_cast<float>(y_off)); }

	public:
		static void updateVertexData(std::vector<float>& vert_data, std::vector<glm::mat4>& transform_data);
		static void renderScene(void *owner, std::vector<float>& v_buf, std::vector<glm::mat4>& trans_mats,
			const std::vector<const char *>& tex_paths, const OGLRendererConfig& config = default_ogl_renderer_config);
	};

}

#endif
