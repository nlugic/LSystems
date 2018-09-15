#ifndef OGLTEXTURE_H
#define OGLTEXTURE_H

namespace lrend
{

	class OGLTexture
	{
	private:
		unsigned textureId;
		int width, height;

		void initTexture();

	public:
		static unsigned char texPointer;

		OGLTexture(const char *path);
		OGLTexture(unsigned char *data, int w, int h);
		OGLTexture(const OGLTexture&) = delete;
		OGLTexture& operator=(const OGLTexture&) = delete;
		~OGLTexture();
	};

}

#endif
