
#include "OGLArrayTexture.h"
#include "..\..\include\glad\glad.h"
#include "stb_image.h"
#include <iostream>

namespace lrend
{

	void OGLArrayTexture::initArrayTexture()
	{
		glGenTextures(1, &arrayTextureId);
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D_ARRAY, arrayTextureId);

		glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
		glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glTexStorage3D(GL_TEXTURE_2D_ARRAY, 4, GL_RGBA8, width, height, static_cast<GLsizei>(layers));
	}

	OGLArrayTexture::OGLArrayTexture(const std::vector<const char *>& paths, int w, int h)
		:layers(paths.size()), width(w), height(h)
	{
		initArrayTexture();

		int channels, width, height, layer = 0;
		stbi_set_flip_vertically_on_load(true);

		for (const char *path : paths)
		{
			unsigned char *image = stbi_load(path, &width, &height, &channels, 0);
			unsigned short format = (channels == 3) ? GL_RGB : GL_RGBA;

			if (image)
				glTexSubImage3D(GL_TEXTURE_2D_ARRAY, 0, 0, 0, layer++, width, height, 1, format, GL_UNSIGNED_BYTE, image);
			else
				std::cout << "An error ocurred while loading the texture image: " << path << std::endl;

			stbi_image_free(image);
		}

		glGenerateMipmap(GL_TEXTURE_2D_ARRAY);
	}

	OGLArrayTexture::OGLArrayTexture(const std::vector<unsigned char *>& data, int w, int h)
		:layers(data.size()), width(w), height(h)
	{
		initArrayTexture();

		int layer = 0;

		for (unsigned char *image : data)
		{
			if (image)
				glTexSubImage3D(GL_TEXTURE_2D_ARRAY, 0, 0, 0, layer++, width, height, 1, GL_RGBA, GL_UNSIGNED_BYTE, image);
			else
				std::cout << "An error ocurred while loading the texture image." << std::endl;
			
			delete[] image;
		}

		glGenerateMipmap(GL_TEXTURE_2D_ARRAY);
	}

	OGLArrayTexture::~OGLArrayTexture()
	{
		glDeleteTextures(1, &arrayTextureId);
	}

}
