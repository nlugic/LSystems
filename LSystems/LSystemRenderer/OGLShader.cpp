
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

		std::stringstream codeStream;

		try
		{
			in.open(path);
			codeStream << in.rdbuf();
			in.close();
		}
		catch (const std::ifstream::failure& e)
		{
			std::cerr << "An error ocurred while reading shader code." << std::endl
				<< e.what() << std::endl;
		}

		unsigned id;
		int success;
		char errorMsg[msg_buf_size];

		std::string codeStr = codeStream.str();
		const char *code = codeStr.c_str();
		id = glCreateShader(type);
		glShaderSource(id, 1, &code, nullptr);
		glCompileShader(id);

		glGetShaderiv(id, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(id, msg_buf_size, nullptr, errorMsg);
			std::cerr << "An error ocurred while compiling the " << ((type == GL_VERTEX_SHADER) ? "vertex" : "fragment")
				<< " shader." << std::endl << errorMsg << std::endl;
		}

		return id;
	}

	OGLShader::OGLShader(const char *vertexPath, const char *tessCtrlPath, const char *tessEvalPath,
		const char *geometryPath, const char *fragmentPath)
		:programId(glCreateProgram())
	{
		if (vertexPath)
		{
			unsigned vertexId = createShader(vertexPath, GL_VERTEX_SHADER);
			glAttachShader(programId, vertexId);
			glDeleteShader(vertexId);
		}

		if (tessCtrlPath)
		{
			unsigned tessCtrlId = createShader(tessCtrlPath, GL_TESS_CONTROL_SHADER);
			glAttachShader(programId, tessCtrlId);
			glDeleteShader(tessCtrlId);
		}

		if (tessEvalPath)
		{
			unsigned tessEvalId = createShader(tessEvalPath, GL_TESS_EVALUATION_SHADER);
			glAttachShader(programId, tessEvalId);
			glDeleteShader(tessEvalId);
		}

		if (geometryPath)
		{
			unsigned geometryId = createShader(geometryPath, GL_GEOMETRY_SHADER);
			glAttachShader(programId, geometryId);
			glDeleteShader(geometryId);
		}

		if (fragmentPath)
		{
			unsigned fragmentId = createShader(fragmentPath, GL_FRAGMENT_SHADER);
			glAttachShader(programId, fragmentId);
			glDeleteShader(fragmentId);
		}

		int success;
		char errorMsg[msg_buf_size];

		glLinkProgram(programId);
		glGetProgramiv(programId, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(programId, msg_buf_size, nullptr, errorMsg);
			std::cerr << "An error ocurred while linking the shader program." << std::endl
				<< errorMsg << std::endl;
		}
	}

	OGLShader::~OGLShader()
	{
		glDeleteProgram(programId);
	}

	void OGLShader::use() const
	{
		glUseProgram(programId);
	}

	void OGLShader::setInt(const char *name, int value) const
	{
		glUniform1i(glGetUniformLocation(programId, name), value);
	}

	void OGLShader::setFloat(const char *name, float value) const
	{
		glUniform1f(glGetUniformLocation(programId, name), value);
	}

	void OGLShader::setFloatVx3(const char *name, const glm::vec3& value) const
	{
		glUniform3fv(glGetUniformLocation(programId, name), 1, glm::value_ptr(value));
	}

	void OGLShader::setFloatVx4(const char *name, const glm::vec4& value) const
	{
		glUniform4fv(glGetUniformLocation(programId, name), 1, glm::value_ptr(value));
	}

	void OGLShader::setFloatMx3(const char *name, const glm::mat3& value) const
	{
		glUniformMatrix3fv(glGetUniformLocation(programId, name), 1, GL_FALSE, glm::value_ptr(value));
	}

	void OGLShader::setFloatMx4(const char *name, const glm::mat4& value) const
	{
		glUniformMatrix4fv(glGetUniformLocation(programId, name), 1, GL_FALSE, glm::value_ptr(value));
	}

}
