#ifndef OGLSHADER_H
#define OGLSHADER_H

#include "..\..\include\glm\glm.hpp"

namespace lrend
{

	const size_t msg_buf_size = 512;

	class OGLShader
	{
	private:
		unsigned shaderId;

	public:
		OGLShader(const char *vertexPath, const char *fragmentPath);
		~OGLShader();

		void use() const;
		void setInt(const char *name, int value) const;
		void setFloatMX4(const char *name, const glm::mat4& value) const;
	};

}

#endif
