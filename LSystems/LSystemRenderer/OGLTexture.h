#ifndef OGLTEXTURE_H
#define OGLTEXTURE_H

#include "..\..\include\glad\glad.h"

namespace lrend
{

	class OGLTexture
	{
	private:
		unsigned int texture_id;
		int width, height;

		void initTexture();

	public:
		static unsigned char texture_pointer;

		OGLTexture() = delete;
		explicit OGLTexture(const char *path);
		OGLTexture(unsigned char *data, int w, int h);
		OGLTexture(const OGLTexture&) = delete;
		OGLTexture(OGLTexture&&) = delete;
		OGLTexture& operator=(const OGLTexture&) = delete;
		inline ~OGLTexture() { glDeleteTextures(1, &texture_id); }
	};

}

#endif
