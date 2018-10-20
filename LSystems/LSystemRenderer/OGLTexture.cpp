
#include "OGLTexture.h"
#include "..\..\include\glad\glad.h"
#include "..\..\include\stb_image.h"
#include <iostream>

namespace lrend
{

	unsigned char OGLTexture::texPointer = 0U;

	void OGLTexture::initTexture()
	{
		glGenTextures(1, &textureId);
		glActiveTexture(GL_TEXTURE0 + OGLTexture::texPointer);
		glBindTexture(GL_TEXTURE_2D, textureId);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		++OGLTexture::texPointer;
	}

	OGLTexture::OGLTexture(const char *path)
	{
		initTexture();

		int channels;
		stbi_set_flip_vertically_on_load(true);
		unsigned char *image = stbi_load(path, &width, &height, &channels, 0);
		unsigned short format = (channels == 3) ? GL_RGB : GL_RGBA;

		if (image)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, image);
			glGenerateMipmap(GL_TEXTURE_2D);
		}
		else
			std::cout << "An error ocurred while loading the texture image." << std::endl;
		stbi_image_free(image);
	}

	OGLTexture::OGLTexture(unsigned char *data, int w, int h)
		:width(w), height(h)
	{
		initTexture();

		if (data)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
		}
		else
			std::cout << "An error ocurred while loading the texture image." << std::endl;

		delete[] data;
	}

	OGLTexture::~OGLTexture()
	{
		glDeleteTextures(1, &textureId);
	}

}
