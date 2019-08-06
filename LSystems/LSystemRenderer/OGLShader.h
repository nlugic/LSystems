#ifndef OGLSHADER_H
#define OGLSHADER_H

#include "..\..\include\glm\glm.hpp"

namespace lrend
{

	const std::size_t msg_buf_size = 512;

	class OGLShader
	{
	private:
		unsigned int program_id;

		unsigned int createShader(const char *path, unsigned short type) const;
		
	public:
		OGLShader(const char *vert_path = nullptr, const char *tesc_path = nullptr, const char *tese_path = nullptr,
			const char *geom_path = nullptr, const char *frag_path = nullptr);
		OGLShader(const OGLShader&) = delete;
		OGLShader(OGLShader&&) = delete;
		OGLShader& operator=(const OGLShader&) = delete;
		~OGLShader();

		void use() const;
		void setBool(const char *name, bool value) const;
		void setInt(const char *name, int value) const;
		void setFloat(const char *name, float value) const;
		void setFloatVx3(const char *name, const glm::vec3& value) const;
		void setFloatVx4(const char *name, const glm::vec4& value) const;
		void setFloatMx3(const char *name, const glm::mat3& value) const;
		void setFloatMx4(const char *name, const glm::mat4& value) const;
	};

}

#endif
