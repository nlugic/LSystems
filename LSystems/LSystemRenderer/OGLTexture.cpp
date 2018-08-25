
#include "OGLTexture.h"

#include "..\..\include\glad\glad.h"
#include "stb_image.h"

#include <iostream>

namespace lrend
{

	unsigned OGLTexture::nextTexture = 0;

	void OGLTexture::createTexture()
	{
		glGenTextures(1, &textureId);
		glActiveTexture(GL_TEXTURE0 + OGLTexture::nextTexture);
		glBindTexture(GL_TEXTURE_2D, textureId);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		++OGLTexture::nextTexture;
	}

	OGLTexture::OGLTexture(const char *path)
	{
		createTexture();

		int channels;
		unsigned char *image = stbi_load(path, &width, &height, &channels, 0);

		if (image)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
			glGenerateMipmap(GL_TEXTURE_2D);
		}
		else
			std::cout << "An error ocurred while loading the texture image." << std::endl;
		stbi_image_free(image);
	}

	OGLTexture::OGLTexture(unsigned char *data, unsigned w, unsigned h)
		:width(w), height(h)
	{
		createTexture();

		if (data)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
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
