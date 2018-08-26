
#include "LSystemRenderer.h"

namespace lrend
{

	LSystemRenderer::LSystemRenderer(lsys::LSystem *lSys)
		:current(lSys) { }

	LSystemRenderer::~LSystemRenderer()
	{
		delete current;
	}

	void LSystemRenderer::test()
	{
		float vertices[] = {
			// back
			-0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f,
			0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
			0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
			-0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f,
			-0.5f, 0.5f, -0.5f, 1.0f, 1.0f, 0.0f,
			0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
			// front
			-0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 0.0f,
			0.5f, -0.5f, 0.5f, 1.0f, 0.0f, 0.0f,
			0.5f, 0.5f, 0.5f, 1.0f, 1.0f, 0.0f,
			0.5f, 0.5f, 0.5f, 1.0f, 1.0f, 0.0f,
			-0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f,
			-0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 0.0f,
			// left
			-0.5f, 0.5f, 0.5f, 1.0f, 1.0f, 0.0f,
			-0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
			-0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
			-0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
			-0.5f, -0.5f, 0.5f, 1.0f, 0.0f, 0.0f,
			-0.5f, 0.5f, 0.5f, 1.0f, 1.0f, 0.0f,
			// right
			0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f,
			0.5f, 0.5f, -0.5f, 1.0f, 1.0f, 0.0f,
			0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f,
			0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f,
			0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 0.0f,
			0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f,
			// bottom
			-0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
			0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f,
			0.5f, -0.5f, 0.5f, 1.0f, 1.0f, 0.0f,
			0.5f, -0.5f, 0.5f, 1.0f, 1.0f, 0.0f,
			-0.5f, -0.5f, 0.5f, 0.0f, 1.0f, 0.0f,
			-0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
			// top
			0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f,
			0.5f, 0.5f, -0.5f, 1.0f, 1.0f, 0.0f,
			-0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
			-0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
			-0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 0.0f,
			0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f
		};

		std::vector<float> vert(vertices, vertices + sizeof(vertices) / sizeof(vertices[0]));
		std::vector<const char *> tex;
		tex.push_back("../LSystemRenderer/test.png");

		OGLRenderer::renderScene(vert, tex);
	}

}
