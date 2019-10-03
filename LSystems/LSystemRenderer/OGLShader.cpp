
#include "OGLShader.h"
#include <iostream>
#include <sstream>
#include <fstream>

namespace lrend
{

	unsigned int OGLShader::createShader(const char *path, unsigned short type)
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

		std::string code_string = code_stream.str();
		const char *code = code_string.c_str();
		unsigned int id = glCreateShader(type);
		glShaderSource(id, 1, &code, nullptr);
		glCompileShader(id);

		int success;
		glGetShaderiv(id, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			char error_msg[msg_buf_size];
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

	OGLShader::OGLShader(const char *vert_path, const char *frag_path, const char *geom_path,
		const char *tesc_path, const char *tese_path)
		:program_id(glCreateProgram())
	{
		if (vert_path)
		{
			unsigned int vertex_id = createShader(vert_path, GL_VERTEX_SHADER);
			glAttachShader(program_id, vertex_id);
			glDeleteShader(vertex_id);
		}

		if (frag_path)
		{
			unsigned int fragment_id = createShader(frag_path, GL_FRAGMENT_SHADER);
			glAttachShader(program_id, fragment_id);
			glDeleteShader(fragment_id);
		}

		if (geom_path)
		{
			unsigned int geometry_id = createShader(geom_path, GL_GEOMETRY_SHADER);
			glAttachShader(program_id, geometry_id);
			glDeleteShader(geometry_id);
		}

		if (tesc_path)
		{
			unsigned int tess_ctrl_id = createShader(tesc_path, GL_TESS_CONTROL_SHADER);
			glAttachShader(program_id, tess_ctrl_id);
			glDeleteShader(tess_ctrl_id);
		}

		if (tese_path)
		{
			unsigned int tess_eval_id = createShader(tese_path, GL_TESS_EVALUATION_SHADER);
			glAttachShader(program_id, tess_eval_id);
			glDeleteShader(tess_eval_id);
		}

		int success;
		glLinkProgram(program_id);
		glGetProgramiv(program_id, GL_LINK_STATUS, &success);
		if (!success)
		{
			char error_msg[msg_buf_size];
			glGetProgramInfoLog(program_id, msg_buf_size, nullptr, error_msg);
			std::cerr << "An error ocurred while linking the shader program." << std::endl
				<< error_msg << std::endl;
		}
	}

}
