
#include "OGLShader.h"

#include "..\..\include\glad\glad.h"
#include "..\..\include\glm\gtc\type_ptr.hpp"

#include <iostream>
#include <sstream>
#include <fstream>

namespace lrend
{

	OGLShader::OGLShader(const char *vertexPath, const char *fragmentPath)
		:shaderId(glCreateProgram())
	{
		std::ifstream vertexIn, fragmentIn;
		vertexIn.exceptions(std::ifstream::badbit | std::ifstream::failbit);
		fragmentIn.exceptions(std::ifstream::badbit | std::ifstream::failbit);

		std::stringstream vertexCode;
		std::stringstream fragmentCode;

		try
		{
			vertexIn.open(vertexPath);
			fragmentIn.open(fragmentPath);

			vertexCode << vertexIn.rdbuf();
			fragmentCode << fragmentIn.rdbuf();

			vertexIn.close();
			fragmentIn.close();
		}
		catch (std::ifstream::failure& e)
		{
			std::cout << "An error ocurred while reading shader code." << std::endl
				<< e.what() << std::endl;
		}

		unsigned vertexId, fragmentId;
		int success;
		char errorMsg[MSG_BUF_SIZE];

		const char *vCode = vertexCode.str().c_str();
		vertexId = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertexId, 1, &vCode, nullptr);
		glCompileShader(vertexId);

		glGetShaderiv(vertexId, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(vertexId, MSG_BUF_SIZE, nullptr, errorMsg);
			std::cout << "An error ocurred while compiling the vertex shader." << std::endl
				<< errorMsg << std::endl;
		}

		const char *fCode = fragmentCode.str().c_str();
		fragmentId = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragmentId, 1, &fCode, nullptr);
		glCompileShader(fragmentId);

		glGetShaderiv(fragmentId, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(fragmentId, MSG_BUF_SIZE, nullptr, errorMsg);
			std::cout << "An error ocurred while compiling the fragment shader." << std::endl << errorMsg << std::endl;
		}

		glAttachShader(shaderId, vertexId);
		glAttachShader(shaderId, fragmentId);
		glLinkProgram(shaderId);

		glGetProgramiv(shaderId, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(shaderId, MSG_BUF_SIZE, nullptr, errorMsg);
			std::cout << "An error ocurred while linking the shader program." << std::endl
				<< errorMsg << std::endl;
		}

		glDeleteShader(vertexId);
		glDeleteShader(fragmentId);
	}

	OGLShader::~OGLShader()
	{
		glDeleteProgram(shaderId);
	}

	void OGLShader::use() const
	{
		glUseProgram(shaderId);
	}

	void OGLShader::setInt(const char *name, int value) const
	{
		glUniform1i(glGetUniformLocation(shaderId, name), value);
	}

	void OGLShader::setFloatMX4(const char *name, const glm::mat4& value) const
	{
		glUniformMatrix4fv(glGetUniformLocation(shaderId, name), 1, GL_FALSE, glm::value_ptr(value));
	}

}
