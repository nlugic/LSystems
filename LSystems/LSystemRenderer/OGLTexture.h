#ifndef OGLTEXTURE_H
#define OGLTEXTURE_H

namespace lrend
{

	class OGLTexture
	{
	private:
		unsigned textureId;
		int width, height;

		void createTexture();

	public:
		static unsigned nextTexture;

		OGLTexture(const char *path);
		OGLTexture(unsigned char *data, unsigned w, unsigned h);
		OGLTexture(const OGLTexture&) = delete;
		OGLTexture& operator=(const OGLTexture&) = delete;
		~OGLTexture();

	};

}

#endif
