#ifndef OGLARRAYTEXTURE_H
#define OGLARRAYTEXTURE_H

#include <vector>

namespace lrend
{

	class OGLArrayTexture
	{
	private:
		unsigned arrayTextureId;

		size_t layers;
		int width, height;

		void initArrayTexture();

	public:
		OGLArrayTexture(const std::vector<const char *>& paths, int w, int h);
		OGLArrayTexture(const std::vector<unsigned char *>& data, int w, int h);
		OGLArrayTexture(const OGLArrayTexture&) = delete;
		OGLArrayTexture& operator=(const OGLArrayTexture&) = delete;
		~OGLArrayTexture();
	};

}

#endif
