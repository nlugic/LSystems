#ifndef OGLSHADER_H
#define OGLSHADER_H

#include "..\..\include\glm\glm.hpp"
#include "..\..\include\glm\gtc\type_ptr.hpp"
#include "..\..\include\glad\glad.h"

namespace lrend
{

	const std::size_t msg_buf_size = 512ull;

	class OGLShader
	{
	private:
		unsigned int program_id;

		static unsigned int createShader(const char *path, unsigned short type);
		
	public:
		OGLShader(const char *vert_path = nullptr, const char *frag_path = nullptr, const char *geom_path = nullptr,
			const char *tesc_path = nullptr, const char *tese_path = nullptr);
		OGLShader(const OGLShader&) = delete;
		OGLShader(OGLShader&&) = delete;
		OGLShader& operator=(const OGLShader&) = delete;
		inline ~OGLShader() { glDeleteProgram(program_id); }

		inline void use() const { glUseProgram(program_id); }
		inline void setBool(const char *name, bool value) const
			{ glUniform1i(glGetUniformLocation(program_id, name), value); }
		inline void setInt(const char *name, int value) const
			{ glUniform1i(glGetUniformLocation(program_id, name), value); }
		inline void setFloat(const char *name, float value) const
			{ glUniform1f(glGetUniformLocation(program_id, name), value); }
		inline void setFloatVx3(const char *name, const glm::vec3& value) const
			{ glUniform3fv(glGetUniformLocation(program_id, name), 1, glm::value_ptr(value)); }
		inline void setFloatVx4(const char *name, const glm::vec4& value) const
			{ glUniform4fv(glGetUniformLocation(program_id, name), 1, glm::value_ptr(value)); }
		inline void setFloatMx3(const char *name, const glm::mat3& value) const
			{ glUniformMatrix3fv(glGetUniformLocation(program_id, name), 1, GL_FALSE, glm::value_ptr(value)); }
		inline void setFloatMx4(const char *name, const glm::mat4& value) const
			{ glUniformMatrix4fv(glGetUniformLocation(program_id, name), 1, GL_FALSE, glm::value_ptr(value)); }
	};

}

#endif
