
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
		/*
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
		*/

		std::vector<float> vertices;

		float R = 0.15f;
		float r = 0.1f;
		float h = 1.0f;
		int n = 16;
		float w = 2.0f;

		float ang = 6.28318530717958647692f / n;
		float phi = 0.0f;
		float sf = std::sin(phi), cf = std::cos(phi);
		float p = std::sqrt(h * h + (R - r) * (R - r));
		float sa = (R - r) / p, ca = h / p;
		float nx = ca * cf, nz = ca * sf;
		float s = w, ds = w / (n + 1);

		for (unsigned short i = 0U; i <= n; ++i)
		{
			vertices.push_back(R * cf);
			vertices.push_back(0.0f);
			vertices.push_back(R * sf);
			vertices.push_back(nx);
			vertices.push_back(sa);
			vertices.push_back(nz);
			vertices.push_back(s);
			vertices.push_back(0.0f);
			vertices.push_back(0.0f);

			vertices.push_back(r * cf);
			vertices.push_back(h);
			vertices.push_back(r * sf);
			vertices.push_back(nx);
			vertices.push_back(sa);
			vertices.push_back(nz);
			vertices.push_back(s);
			vertices.push_back(1.0f);
			vertices.push_back(0.0f);

			phi += ang; s -= ds;
			sf = std::sin(phi); cf = std::cos(phi);
		}

		std::vector<const char *> tex;
		tex.push_back("../LSystemRenderer/tree.jpg");

		OGLRenderer::renderScene(vertices, tex);
	}

}
