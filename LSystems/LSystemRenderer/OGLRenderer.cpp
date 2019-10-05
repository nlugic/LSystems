
#include "LSystemRenderer.h"
#include "..\..\include\glm\gtc\matrix_transform.hpp"
#include "..\..\include\stb_image_write.h"
#include <iostream>

#ifdef _DEBUG
#pragma comment (lib, "..\\..\\lib\\glfw3d.lib")
#else
#pragma comment (lib, "..\\..\\lib\\glfw3r.lib")
#endif

namespace lrend
{

	using OGLR = OGLRenderer;

	void *OGLR::owner = nullptr;
	int OGLR::width = default_ogl_renderer_config.window_width;
	int OGLR::height = default_ogl_renderer_config.window_height;
	GLFWwindow *OGLR::gl_window = nullptr;
	//bool OGLR::enable_wireframe = false;
	bool OGLR::mouse_moved = false;
	double OGLR::last_x_pos = OGLR::width / 2.0;
	double OGLR::last_y_pos = OGLR::height / 2.0;
	float OGLR::delta_time = 0.0f;
	float OGLR::last_frame = 0.0f;
	OGLCamera *OGLR::camera = nullptr;
	unsigned int OGLR::vao = 0u;
	unsigned int OGLR::vbo = 0u;
	unsigned int OGLR::ssbo = 0u;
	std::size_t OGLR::vertex_buf_size = 0ull;
	std::size_t OGLR::shader_storage_buf_size = 0ull;
	OGLShader *OGLR::shader_program = nullptr;
	OGLArrayTexture *OGLR::textures = nullptr;

#ifdef _DEBUG
	unsigned int OGLR::tqo = 0u;
#endif

	void OGLRenderer::initGLWindow(const char *caption)
	{
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
		glfwWindowHint(GLFW_SAMPLES, 8);

#ifdef _DEBUG
		glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);
#endif

		GLFWwindow *temp_wnd = glfwCreateWindow(OGLR::width, OGLR::height, caption, nullptr, nullptr);
		if (!temp_wnd)
		{
			std::cerr << "An error ocurred while creating the GLFW window." << std::endl;
			glfwTerminate();
			return;
		}

		glfwMakeContextCurrent(temp_wnd);

		if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress)))
		{
			std::cerr << "An error ocurred while loading functions with GLAD." << std::endl;
			glfwTerminate();
			return;
		}

		glViewport(0, 0, OGLR::width, OGLR::height);

		glfwSwapInterval(1);
		glfwSetInputMode(temp_wnd, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

		glfwSetKeyCallback(temp_wnd, OGLR::onKeyPress);
		glfwSetWindowSizeCallback(temp_wnd, OGLR::onWindowResize);
		glfwSetCursorPosCallback(temp_wnd, OGLR::onMouseMove);
		glfwSetScrollCallback(temp_wnd, OGLR::onMouseScroll);

#ifdef _DEBUG
		glGenQueries(1, &OGLR::tqo);
		glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
		glDebugMessageCallback(OGLR::processDebugMessage, nullptr);
#endif

		OGLR::gl_window = temp_wnd;
	}

	void OGLRenderer::destroyGLWindow()
	{
		if (OGLR::camera)
			delete OGLR::camera;
		if (OGLR::shader_program)
			delete OGLR::shader_program;
		if (OGLR::textures)
			delete OGLR::textures;

		glDeleteBuffers(1, &OGLR::ssbo);
		glDeleteBuffers(1, &OGLR::vbo);
		glDeleteVertexArrays(1, &OGLR::vao);
		glfwTerminate();

		OGLR::owner = nullptr;
		OGLR::width = default_ogl_renderer_config.window_width;
		OGLR::height = default_ogl_renderer_config.window_height;
		OGLR::gl_window = nullptr;
		//OGLR::enable_wireframe = false;
		OGLR::mouse_moved = false;
		OGLR::last_x_pos = OGLR::width / 2.0;
		OGLR::last_y_pos = OGLR::height / 2.0;
		OGLR::delta_time = OGLR::last_frame = 0.0f;
		OGLR::camera = nullptr;
		OGLR::vao = OGLR::vbo = OGLR::ssbo = 0u;
		OGLR::vertex_buf_size = OGLR::shader_storage_buf_size = 0ull;
		OGLR::shader_program = nullptr;
		OGLR::textures = nullptr;

#ifdef _DEBUG
		glDeleteQueries(1, &OGLR::tqo);
		OGLR::tqo = 0u;
#endif
	}

	void OGLRenderer::initBuffers(const std::vector<float>& vert_data, const std::vector<glm::mat4>& transform_data)
	{
		OGLR::vertex_buf_size = vert_data.size();
		OGLR::shader_storage_buf_size = transform_data.size();

#ifdef _DEBUG
		glBeginQuery(GL_TIME_ELAPSED, OGLR::tqo);
#endif

		glGenVertexArrays(1, &OGLR::vao);
		glBindVertexArray(OGLR::vao);

		glGenBuffers(1, &OGLR::vbo);
		glBindBuffer(GL_ARRAY_BUFFER, OGLR::vbo);
		glBufferData(GL_ARRAY_BUFFER, OGLR::vertex_buf_size * sizeof(float), vert_data.data(), GL_STATIC_DRAW);

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(lsys::Vertex) + sizeof(float), nullptr);
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(lsys::Vertex) + sizeof(float),
			reinterpret_cast<const void *>(3 * sizeof(float)));
		glEnableVertexAttribArray(2);
		glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(lsys::Vertex) + sizeof(float),
			reinterpret_cast<const void *>(6 * sizeof(float)));
		glEnableVertexAttribArray(3);
		glVertexAttribPointer(3, 1, GL_FLOAT, GL_FALSE, sizeof(lsys::Vertex) + sizeof(float),
			reinterpret_cast<const void *>(9 * sizeof(float)));

		glGenBuffers(1, &OGLR::ssbo);
		glBindBuffer(GL_SHADER_STORAGE_BUFFER, OGLR::ssbo);
		glBufferData(GL_SHADER_STORAGE_BUFFER, OGLR::shader_storage_buf_size * sizeof(glm::mat4),
			transform_data.data(), GL_STATIC_DRAW);
		glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 0, OGLR::ssbo);

#ifdef _DEBUG
		glEndQuery(GL_TIME_ELAPSED);

		GLuint64 elapsed_time = 0ull;
		glGetQueryObjectui64v(OGLR::tqo, GL_QUERY_RESULT, &elapsed_time);

		std::clog << "Initializing the buffers took " << elapsed_time << " nanoseconds." << std::endl;

		glObjectLabel(GL_VERTEX_ARRAY, OGLR::vao, 9, "Main VAO");
		glObjectLabel(GL_BUFFER, OGLR::vbo, 9, "Mesh VBO");
		glObjectLabel(GL_BUFFER, OGLR::ssbo, 22, "Transform matrix SSBO");
#endif

		glBindVertexArray(0u);
		glBindBuffer(GL_ARRAY_BUFFER, 0u);
		glBindBuffer(GL_SHADER_STORAGE_BUFFER, 0u);
	}

	void OGLRenderer::initCamera(const OGLCameraConfig& config)
	{
		if (OGLR::camera)
			delete OGLR::camera;

		OGLR::camera = new OGLCamera(config);
	}

	void OGLRenderer::initShader(const char *vert_path, const char *frag_path, const char *geom_path,
		const char *tesc_path, const char *tese_path)
	{
		if (OGLR::shader_program)
			delete OGLR::shader_program;

		OGLR::shader_program = new OGLShader(vert_path, frag_path, geom_path, tesc_path, tese_path);
	}

	void OGLRenderer::initTextures(const std::vector<const char *>& texture_paths, int w, int h)
	{
		if (OGLR::textures)
			delete OGLR::textures;

		OGLR::textures = new OGLArrayTexture(texture_paths, w, h);
	}

	void OGLRenderer::initLighting(const glm::vec4& position, const glm::vec3& attenuation, 
		const glm::vec3& ambient, const glm::vec3& diffuse, const glm::vec3& specular, float shininess)
	{
		OGLR::shader_program->setFloatVx4("light.position", position);
		OGLR::shader_program->setFloatVx3("light.attenuation", attenuation);
		OGLR::shader_program->setFloatVx3("light.ambient", ambient);
		OGLR::shader_program->setFloatVx3("light.diffuse", diffuse);
		OGLR::shader_program->setFloatVx3("light.specular", specular);
		OGLR::shader_program->setFloat("light.shininess", shininess);
	}
	
#ifdef _DEBUG
	void APIENTRY OGLRenderer::processDebugMessage(GLenum source, GLenum type, GLenum id, GLenum severity,
		GLsizei length, const GLchar *message, const void *param)
	{
		std::cerr << std::hex << ((type == GL_DEBUG_TYPE_ERROR) ? "Error [" : "Message [")
			<< "src = " << source << ", type = " << type << ", severity = " << severity << "]:"
			<< std::dec << std::endl << message << std::endl;
	}
#endif

	void OGLRenderer::takeScreenshot()
	{
		unsigned char *data = new unsigned char[OGLR::width * OGLR::height * 3];

		glReadPixels(0, 0, OGLR::width, OGLR::height, GL_RGB, GL_UNSIGNED_BYTE, data);

		std::string time(std::to_string(glfwGetTime()));
		time += ".jpg";

		stbi_flip_vertically_on_write(true);
		stbi_write_jpg(time.c_str(), OGLR::width, OGLR::height, 3, data, 0);

		delete[] data;
	}

	void OGLRenderer::processMoveKeys(GLFWwindow *wnd)
	{
		if (glfwGetKey(wnd, GLFW_KEY_W) == GLFW_PRESS)
			OGLR::camera->move(FORWARD, OGLR::delta_time);
		if (glfwGetKey(wnd, GLFW_KEY_S) == GLFW_PRESS)
			OGLR::camera->move(BACKWARDS, OGLR::delta_time);
		if (glfwGetKey(wnd, GLFW_KEY_A) == GLFW_PRESS)
			OGLR::camera->move(LEFT, OGLR::delta_time);
		if (glfwGetKey(wnd, GLFW_KEY_D) == GLFW_PRESS)
			OGLR::camera->move(RIGHT, OGLR::delta_time);
	}
	
	void OGLRenderer::onKeyPress(GLFWwindow *wnd, int key, int scancode, int action, int mode)
	{
		if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
			glfwSetWindowShouldClose(wnd, true);

		if (key == GLFW_KEY_PRINT_SCREEN && action == GLFW_PRESS)
			takeScreenshot();

		/*
		if (key == GLFW_KEY_F && action == GLFW_PRESS)
		{
			OGLR::enable_wireframe = !OGLR::enable_wireframe;
			OGLR::shader_program->setBool("enable_wireframe", OGLR::enable_wireframe);
		}
		*/

		if (key == GLFW_KEY_KP_ADD && action == GLFW_PRESS)
			static_cast<LSystemRenderer *>(OGLR::owner)->levelUp();
		if (key == GLFW_KEY_KP_SUBTRACT && action == GLFW_PRESS)
			static_cast<LSystemRenderer *>(OGLR::owner)->levelDown();
	}

	void OGLRenderer::onWindowResize(GLFWwindow *wnd, int w, int h)
	{
		OGLR::width = w;
		OGLR::height = h;

		glViewport(0, 0, w, h);
	}

	void OGLRenderer::onMouseMove(GLFWwindow *wnd, double x_pos, double y_pos)
	{
		if (!OGLR::mouse_moved)
		{
			OGLR::last_x_pos = x_pos;
			OGLR::last_y_pos = y_pos;
			OGLR::mouse_moved = true;
		}

		double x_off = x_pos - OGLR::last_x_pos;
		double y_off = OGLR::last_y_pos - y_pos;
		
		OGLR::last_x_pos = x_pos;
		OGLR::last_y_pos = y_pos;

		OGLR::camera->look(static_cast<float>(x_off), static_cast<float>(y_off));
	}

	void OGLRenderer::updateVertexData(std::vector<float>& vert_data, std::vector<glm::mat4>& transform_data)
	{
		OGLR::vertex_buf_size = vert_data.size();
		OGLR::shader_storage_buf_size = transform_data.size();

#ifdef _DEBUG
		glBeginQuery(GL_TIME_ELAPSED, OGLR::tqo);
#endif

		glBindVertexArray(OGLR::vao);
		glBindBuffer(GL_ARRAY_BUFFER, OGLR::vbo);
		glBindBuffer(GL_SHADER_STORAGE_BUFFER, OGLR::ssbo);

		glBufferSubData(GL_ARRAY_BUFFER, 0, OGLR::vertex_buf_size * sizeof(float), vert_data.data());
		glBufferSubData(GL_SHADER_STORAGE_BUFFER, 0, OGLR::shader_storage_buf_size * sizeof(glm::mat4), transform_data.data());

#ifdef _DEBUG
		glEndQuery(GL_TIME_ELAPSED);

		GLuint64 elapsed_time = 0ull;
		glGetQueryObjectui64v(OGLR::tqo, GL_QUERY_RESULT, &elapsed_time);

		std::clog << "Updating the buffers took " << elapsed_time << " nanoseconds." << std::endl;
#endif

		std::swap(vert_data, std::vector<float> { });
		std::swap(transform_data, std::vector<glm::mat4> { });

		glBindVertexArray(0u);
		glBindBuffer(GL_ARRAY_BUFFER, 0u);
		glBindBuffer(GL_SHADER_STORAGE_BUFFER, 0u);
	}

	void OGLRenderer::renderScene(void *owner, std::vector<float>& v_buf, std::vector<glm::mat4>& trans_mats,
		const std::vector<const char *>& tex_paths, const OGLRendererConfig& config)
	{
		OGLR::owner = owner;
		OGLR::width = config.window_width;
		OGLR::height = config.window_height;
		OGLR::last_x_pos = OGLR::width / 2.0;
		OGLR::last_y_pos = OGLR::height / 2.0;

		OGLR::initGLWindow(config.window_caption);
		OGLR::initBuffers(v_buf, trans_mats);
		std::swap(v_buf, std::vector<float> { });
		std::swap(trans_mats, std::vector<glm::mat4> { });

		OGLR::initCamera(config.camera_config);
		OGLR::initShader(config.vert_path, config.frag_path, config.geom_path,
			config.tesc_path, config.tese_path);
		OGLR::shader_program->use();
		OGLR::initLighting(config.light_position, config.light_attenuation, config.light_ambient,
			config.light_diffuse, config.light_specular, config.specular_shininess);
		if (!tex_paths.empty())
			OGLR::initTextures(tex_paths, config.texture_width, config.texture_height);

		glEnable(GL_DEPTH_TEST);
		glEnable(GL_MULTISAMPLE);
		glFrontFace(GL_CCW);
		glEnable(GL_CULL_FACE);
		glCullFace(GL_BACK);

		//glPatchParameteri(GL_PATCH_VERTICES, 4);

		glm::mat4 projection(glm::perspective(glm::radians(OGLR::camera->getFOV()),
			static_cast<float>(OGLR::width) / OGLR::height, 0.1f, 100.0f));
		glm::mat4 view(OGLR::camera->getViewMatrix());

		OGLR::shader_program->setFloatMx4("proj", projection);
		OGLR::shader_program->setFloatMx4("view", view);
		OGLR::shader_program->setFloatMx4("model", glm::mat4(1.0f));

		/*
		OGLR::shader_program->setFloat("outer_x", 8.0f);
		OGLR::shader_program->setFloat("outer_y", 6.0f);
		OGLR::shader_program->setFloat("inner_x", 4.0f);
		OGLR::shader_program->setFloat("inner_y", 3.0f);

		OGLR::shader_program->setBool("enable_wireframe", OGLR::enable_wireframe);
		OGLR::shader_program->setFloatVx3("viewport", glm::vec3(config.window_width, config.window_height, 1.0f));
		*/

		while (!glfwWindowShouldClose(OGLR::gl_window))
		{
			processMoveKeys(OGLR::gl_window);

			glClearColor(config.background_color.x, config.background_color.y, config.background_color.z, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			glBindVertexArray(OGLR::vao);

			projection = glm::perspective(glm::radians(OGLR::camera->getFOV()),
				static_cast<float>(OGLR::width) / OGLR::height, 0.1f, 100.0f);
			view = OGLR::camera->getViewMatrix();

			OGLR::shader_program->setFloatMx4("proj", projection);
			OGLR::shader_program->setFloatMx4("view", view);

			OGLR::shader_program->setFloatVx3("viewPosition", OGLR::camera->getPosition());

			float current_frame = static_cast<float>(glfwGetTime());
			OGLR::delta_time = current_frame - OGLR::last_frame;
			OGLR::last_frame = current_frame;

			glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(OGLR::vertex_buf_size
				/ (sizeof(lsys::Vertex) / sizeof(float) + 1u)));

			//glDrawArrays(GL_PATCHES, 0, static_cast<GLsizei>(OGLR::vertex_buf_size
			//	/ (sizeof(lsys::Vertex) / sizeof(float) + 1u)));

			glfwSwapBuffers(OGLR::gl_window);
			glfwPollEvents();
		}

		OGLR::destroyGLWindow();
	}

}
