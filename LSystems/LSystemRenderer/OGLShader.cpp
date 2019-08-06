
#include "OGLShader.h"
#include "..\..\include\glad\glad.h"
#include "..\..\include\glm\gtc\type_ptr.hpp"
#include <iostream>
#include <sstream>
#include <fstream>

namespace lrend
{

	unsigned OGLShader::createShader(const char *path, unsigned short type) const
	{
		std::ifstream in;
		in.exceptions(std::ifstream::badbit | std::ifstream::failbit);

		std::stringstream code_stream;

		try
		{
			in.open(path);
			code_stream << in.rdbuf();
			in.close();
		}
		catch (const std::ifstream::failure& e)
		{
			std::cerr << "An error ocurred while reading shader code." << std::endl
				<< e.what() << std::endl;
		}

		unsigned id;
		int success;
		char error_msg[msg_buf_size];

		std::string code_string = code_stream.str();
		const char *code = code_string.c_str();
		id = glCreateShader(type);
		glShaderSource(id, 1, &code, nullptr);
		glCompileShader(id);

		glGetShaderiv(id, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(id, msg_buf_size, nullptr, error_msg);
			std::cerr << "An error ocurred while compiling the ";
			switch (type)
			{
				case GL_VERTEX_SHADER: std::cerr << "vertex"; break;
				case GL_TESS_CONTROL_SHADER: std::cerr << "tesselation control"; break;
				case GL_TESS_EVALUATION_SHADER: std::cerr << "tesselation evaluation"; break;
				case GL_GEOMETRY_SHADER: std::cerr << "geometry"; break;
				case GL_FRAGMENT_SHADER: std::cerr << "fragment"; break;
			}
			std::cerr << " shader." << std::endl << error_msg << std::endl;
		}

		return id;
	}

	OGLShader::OGLShader(const char *vert_path, const char *tesc_path, const char *tese_path,
		const char *geom_path, const char *frag_path)
		:program_id(glCreateProgram())
	{
		if (vert_path)
		{
			unsigned vertex_id = createShader(vert_path, GL_VERTEX_SHADER);
			glAttachShader(program_id, vertex_id);
			glDeleteShader(vertex_id);
		}

		if (tesc_path)
		{
			unsigned tess_ctrl_id = createShader(tesc_path, GL_TESS_CONTROL_SHADER);
			glAttachShader(program_id, tess_ctrl_id);
			glDeleteShader(tess_ctrl_id);
		}

		if (tese_path)
		{
			unsigned tess_eval_id = createShader(tese_path, GL_TESS_EVALUATION_SHADER);
			glAttachShader(program_id, tess_eval_id);
			glDeleteShader(tess_eval_id);
		}

		if (geom_path)
		{
			unsigned geometry_id = createShader(geom_path, GL_GEOMETRY_SHADER);
			glAttachShader(program_id, geometry_id);
			glDeleteShader(geometry_id);
		}

		if (frag_path)
		{
			unsigned fragment_id = createShader(frag_path, GL_FRAGMENT_SHADER);
			glAttachShader(program_id, fragment_id);
			glDeleteShader(fragment_id);
		}

		int success;
		char error_msg[msg_buf_size];

		glLinkProgram(program_id);
		glGetProgramiv(program_id, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(program_id, msg_buf_size, nullptr, error_msg);
			std::cerr << "An error ocurred while linking the shader program." << std::endl
				<< error_msg << std::endl;
		}
	}

	OGLShader::~OGLShader() { glDeleteProgram(program_id); }

	void OGLShader::use() const { glUseProgram(program_id); }

	void OGLShader::setBool(const char *name, bool value) const
		{ glUniform1i(glGetUniformLocation(program_id, name), value); }

	void OGLShader::setInt(const char *name, int value) const
		{ glUniform1i(glGetUniformLocation(program_id, name), value); }

	void OGLShader::setFloat(const char *name, float value) const
		{ glUniform1f(glGetUniformLocation(program_id, name), value); }

	void OGLShader::setFloatVx3(const char *name, const glm::vec3& value) const
		{ glUniform3fv(glGetUniformLocation(program_id, name), 1, glm::value_ptr(value)); }

	void OGLShader::setFloatVx4(const char *name, const glm::vec4& value) const
		{ glUniform4fv(glGetUniformLocation(program_id, name), 1, glm::value_ptr(value)); }

	void OGLShader::setFloatMx3(const char *name, const glm::mat3& value) const
		{ glUniformMatrix3fv(glGetUniformLocation(program_id, name), 1, GL_FALSE, glm::value_ptr(value)); }

	void OGLShader::setFloatMx4(const char *name, const glm::mat4& value) const
		{ glUniformMatrix4fv(glGetUniformLocation(program_id, name), 1, GL_FALSE, glm::value_ptr(value)); }

}
