#ifndef OGLARRAYTEXTURE_H
#define OGLARRAYTEXTURE_H

#include "..\..\include\glad\glad.h"
#include <vector>

namespace lrend
{

	class OGLArrayTexture
	{
	private:
		unsigned int array_texture_id;
		std::size_t layers;
		int width, height;

		void initArrayTexture();

	public:
		OGLArrayTexture() = delete;
		OGLArrayTexture(const std::vector<const char *>& paths, int w, int h);
		OGLArrayTexture(const std::vector<unsigned char *>& data, int w, int h);
		OGLArrayTexture(const OGLArrayTexture&) = delete;
		OGLArrayTexture(OGLArrayTexture&&) = delete;
		OGLArrayTexture& operator=(const OGLArrayTexture&) = delete;
		inline ~OGLArrayTexture() { glDeleteTextures(1, &array_texture_id); }
	};

}

#endif
