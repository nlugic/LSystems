#ifndef OGLTEXTURE_H
#define OGLTEXTURE_H

namespace lrend
{

	class OGLTexture
	{
	private:
		unsigned texture_id;
		int width, height;

		void initTexture();

	public:
		static unsigned char texture_pointer;

		OGLTexture(const char *path);
		OGLTexture(unsigned char *data, int w, int h);
		OGLTexture(const OGLTexture&) = delete;
		OGLTexture& operator=(const OGLTexture&) = delete;
		~OGLTexture();
	};

}

#endif
