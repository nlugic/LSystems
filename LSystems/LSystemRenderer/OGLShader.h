#ifndef OGLSHADER_H
#define OGLSHADER_H

#include "..\..\include\glm\glm.hpp"

namespace lrend
{

	const size_t msg_buf_size = 512;

	class OGLShader
	{
	private:
		unsigned programId;

		unsigned createShader(const char *path, unsigned short type) const;
		
	public:
		OGLShader(const char *vertexPath, const char *fragmentPath);
		OGLShader(const OGLShader&) = delete;
		OGLShader& operator=(const OGLShader&) = delete;
		~OGLShader();

		void use() const;
		void setInt(const char *name, int value) const;
		void setFloat(const char *name, float value) const;
		void setFloatVx3(const char *name, const glm::vec3& value) const;
		void setFloatVx4(const char *name, const glm::vec4& value) const;
		void setFloatMx3(const char *name, const glm::mat3& value) const;
		void setFloatMx4(const char *name, const glm::mat4& value) const;
	};

}

#endif
