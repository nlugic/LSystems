
#include "TurtleActions.h"

namespace lsys
{

	void drawLine(GraphicsTurtle *turtle, LSystemSymbol *sym, LSystem *sys)
	{
		float h = sym->getParam('h');
		float w_2 = sym->getParam('w') / 2.0f;
		float d = h - w_2;

		turtle->addVertices({
			{ -w_2, -w_2, 0.0f, 0.0f, 0.0f, 1.0f, 0.3f, 0.7f, -0.4f },
			{ w_2, d, 0.0f, 0.0f, 0.0f, 1.0f, 0.3f, 0.7f, -0.4f },
			{ -w_2, d, 0.0f, 0.0f, 0.0f, 1.0f, 0.3f, 0.7f, -0.4f },
			{ -w_2, -w_2, 0.0f, 0.0f, 0.0f, 1.0f, 0.3f, 0.7f, -0.4f },
			{ w_2, -w_2, 0.0f, 0.0f, 0.0f, 1.0f, 0.3f, 0.7f, -0.4f },
			{ w_2, d, 0.0f, 0.0f, 0.0f, 1.0f, 0.3f, 0.7f, -0.4f },
			{ -w_2, -w_2, 0.0f, 0.0f, 0.0f, 1.0f, 0.3f, 0.7f, -0.4f },
			{ -w_2, d, 0.0f, 0.0f, 0.0f, 1.0f, 0.3f, 0.7f, -0.4f },
			{ w_2, d, 0.0f, 0.0f, 0.0f, 1.0f, 0.3f, 0.7f, -0.4f },
			{ -w_2, -w_2, 0.0f, 0.0f, 0.0f, 1.0f, 0.3f, 0.7f, -0.4f },
			{ w_2, d, 0.0f, 0.0f, 0.0f, 1.0f, 0.3f, 0.7f, -0.4f },
			{ w_2, -w_2, 0.0f, 0.0f, 0.0f, 1.0f, 0.3f, 0.7f, -0.4f }
		});

		turtle->translateState(glm::vec3(0.0f, h, 0.0f));
	}

	void drawBox(GraphicsTurtle *turtle, LSystemSymbol *sym, LSystem *sys)
	{
		float a_2 = sym->getParam('a') / 2.0f;
		float h = sym->getParam('h');
		float r = sym->getParam('r');
		float g = sym->getParam('g');
		float b = sym->getParam('b');

		turtle->addVertices({
			{ -a_2, -a_2, a_2, 0.0f, 0.0f, 1.0f, r, g, -b },
			{ a_2, h - a_2, a_2, 0.0f, 0.0f, 1.0f, r, g, -b },
			{ -a_2, h - a_2, a_2, 0.0f, 0.0f, 1.0f, r, g, -b },
			{ -a_2, -a_2, a_2, 0.0f, 0.0f, 1.0f, r, g, -b },
			{ a_2, -a_2, a_2, 0.0f, 0.0f, 1.0f, r, g, -b },
			{ a_2, h - a_2, a_2, 0.0f, 0.0f, 1.0f, r, g, -b },

			{ a_2, -a_2, -a_2, 0.0f, 0.0f, -1.0f, r, g, -b },
			{ -a_2, h - a_2, -a_2, 0.0f, 0.0f, -1.0f, r, g, -b },
			{ a_2, h - a_2, -a_2, 0.0f, 0.0f, -1.0f, r, g, -b },
			{ a_2, -a_2, -a_2, 0.0f, 0.0f, -1.0f, r, g, -b },
			{ -a_2, -a_2, -a_2, 0.0f, 0.0f, -1.0f, r, g, -b },
			{ -a_2, h - a_2, -a_2, 0.0f, 0.0f, -1.0f, r, g, -b },

			{ -a_2, -a_2, -a_2, -1.0f, 0.0f, 0.0f, r, g, -b },
			{ -a_2, h - a_2, a_2, -1.0f, 0.0f, 0.0f, r, g, -b },
			{ -a_2, h - a_2, -a_2, -1.0f, 0.0f, 0.0f, r, g, -b },
			{ -a_2, -a_2, -a_2, -1.0f, 0.0f, 0.0f, r, g, -b },
			{ -a_2, -a_2, a_2, -1.0f, 0.0f, 0.0f, r, g, -b },
			{ -a_2, h - a_2, a_2, -1.0f, 0.0f, 0.0f, r, g, -b },

			{ a_2, -a_2, a_2, 1.0f, 0.0f, 0.0f, r, g, -b },
			{ a_2, h - a_2, -a_2, 1.0f, 0.0f, 0.0f, r, g, -b },
			{ a_2, h - a_2, a_2, 1.0f, 0.0f, 0.0f, r, g, -b },
			{ a_2, -a_2, a_2, 1.0f, 0.0f, 0.0f, r, g, -b },
			{ a_2, -a_2, -a_2, 1.0f, 0.0f, 0.0f, r, g, -b },
			{ a_2, h - a_2, -a_2, 1.0f, 0.0f, 0.0f, r, g, -b },

			{ -a_2, h - a_2, a_2, 0.0f, 1.0f, 0.0f, r, g, -b },
			{ a_2, h - a_2, -a_2, 0.0f, 1.0f, 0.0f, r, g, -b },
			{ -a_2, h - a_2, -a_2, 0.0f, 1.0f, 0.0f, r, g, -b },
			{ -a_2, h - a_2, a_2, 0.0f, 1.0f, 0.0f, r, g, -b },
			{ a_2, h - a_2, a_2, 0.0f, 1.0f, 0.0f, r, g, -b },
			{ a_2, h - a_2, -a_2, 0.0f, 1.0f, 0.0f, r, g, -b },

			{ -a_2, -a_2, -a_2, 0.0f, -1.0f, 0.0f, r, g, -b },
			{ a_2, -a_2, a_2, 0.0f, -1.0f, 0.0f, r, g, -b },
			{ -a_2, -a_2, a_2, 0.0f, -1.0f, 0.0f, r, g, -b },
			{ -a_2, -a_2, -a_2, 0.0f, -1.0f, 0.0f, r, g, -b },
			{ a_2, -a_2, -a_2, 0.0f, -1.0f, 0.0f, r, g, -b },
			{ a_2, -a_2, a_2, 0.0f, -1.0f, 0.0f, r, g, -b }
		});

		turtle->translateState(glm::vec3(0.0f, h, 0.0f));
	}

	void drawGenericBranchSegment(GraphicsTurtle *turtle, LSystemSymbol *sym, LSystem *sys)
	{
		unsigned short n = static_cast<unsigned short>(sym->getParam('n'));
		float R = sym->getParam('R');
		float r = sym->getParam('r');
		float h = sym->getParam('h');
		float t = sym->getParam('t');
		float w = sym->getParam('w');

		float ang = pix2 / n;
		float phi = 0.0f;
		float sf = std::sin(phi), cf = std::cos(phi);
		float sfu = std::sin(phi + ang), cfu = std::cos(phi + ang);
		float p = std::sqrt(h * h + (R - r) * (R - r));
		float s = w, ds = w / n;

		glm::vec3 nm(h / p * cf, (R - r) / p, h / p * sf);
		glm::vec3 nmu(h / p * cfu, (R - r) / p, h / p * sfu);

		Vertex vx[4] {
			{ R * cf, 0.0f, R * sf, nm.x, nm.y, nm.z, s, 0.0f, t },
			{ R * cfu, 0.0f, R * sfu, nmu.x, nmu.y, nmu.z, s - ds, 0.0f, t },
			{ r * cf, h, r * sf, nm.x, nm.y, nm.z, s, 1.0f, t },
			{ r * cfu, h, r * sfu, nmu.x, nmu.y, nmu.z, s - ds, 1.0f, t }
		};

		std::vector<Vertex> vertices;

		for (unsigned short i = 0u; i < n; ++i)
		{
			vertices.push_back(vx[0]);
			vertices.push_back(vx[2]);
			vertices.push_back(vx[3]);
			vertices.push_back(vx[0]);
			vertices.push_back(vx[3]);
			vertices.push_back(vx[1]);

			phi += ang; s -= ds;
			sf = sfu; cf = cfu;
			sfu = std::sin(phi + ang); cfu = std::cos(phi + ang);

			vx[0] = vx[1]; vx[2] = vx[3];
			nmu.x = h / p * cfu; nmu.z = h / p * sfu;
			vx[1].x = R * cfu; vx[1].z = R * sfu;
			vx[1].nx = nmu.x; vx[1].nz = nmu.z;
			vx[3].x = r * cfu; vx[3].z = r * sfu;
			vx[3].nx = nmu.x; vx[3].nz = nmu.z;
			vx[0].s = s; vx[1].s = s - ds; vx[2].s = s; vx[3].s = s - ds;
		}

		turtle->addVertices(vertices);
		turtle->translateState(glm::vec3(0.0f, h, 0.0f));
	}

	void drawGenericBranchApex(GraphicsTurtle *turtle, LSystemSymbol *sym, LSystem *sys)
	{
		unsigned short n = static_cast<unsigned short>(sym->getParam('n'));
		float r = sym->getParam('r');
		float h = sym->getParam('h');
		float t = sym->getParam('t');
		float w = sym->getParam('w');

		float ang = pix2 / n;
		float phi = 0.0f;
		float sf = std::sin(phi), cf = std::cos(phi);
		float sfu = std::sin(phi + ang), cfu = std::cos(phi + ang);
		float p = std::sqrt(h * h + r * r);
		float s = 0.0f, ds = w / n;

		glm::vec3 nm(h / p * cf, r / p, h / p * sf);
		glm::vec3 nmu(h / p * cfu, r / p, h / p * sfu);

		Vertex vx[3] {
			{ 0.0f, h, 0.0f, (nm.x + nmu.x) / 2.0f, (nm.y + nmu.y) / 2.0f, (nm.z + nmu.z) / 2.0f, s, 1.0f, t },
			{ r * cf, 0.0f, r * sf, nmu.x, nmu.y, nmu.z, s - ds, 0.0f, t },
			{ r * cfu, 0.0f, r * sfu, nm.x, nm.y, nm.z, s, 0.0f, t }
		};

		std::vector<Vertex> vertices;

		for (unsigned short i = 0u; i < n; ++i)
		{
			vertices.push_back(vx[0]);
			vertices.push_back(vx[2]);
			vertices.push_back(vx[1]);

			phi += ang; s -= ds; sf = sfu; cf = cfu;
			sfu = std::sin(phi + ang); cfu = std::cos(phi + ang);
			
			vx[1] = vx[2]; nm = nmu;
			nmu.x = h / p * cfu; nmu.z = h / p * sfu;
			vx[2].x = r * cfu; vx[2].y = 0.0f; vx[2].z = r * sfu;
			vx[0].nx = (nm.x + nmu.x) / 2.0f; vx[0].nz = (nm.z + nmu.z) / 2.0f;
			vx[2].nx = nmu.x; vx[2].nz = nmu.z;
			vx[0].s = s; vx[1].s = s - ds; vx[2].s = s;
		}

		turtle->addVertices(vertices);
		turtle->translateState(glm::vec3(0.0f, h, 0.0f));
	}

	void drawGenericLeaf(GraphicsTurtle *turtle, LSystemSymbol *sym, LSystem *sys)
	{
		float l = sym->getParam('l');
		float w = sym->getParam('w');
		float p = sym->getParam('p');
		float c = sym->getParam('c');
		float C = sym->getParam('C');
		float t = sym->getParam('t');

		glm::vec3 vl(w / 2.0f, p + c, 0.0f);
		glm::vec3 vh(w / 2.0f, p + l - C, 0.0f);

		turtle->addVertices({
			{ -0.025f * w, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.3f, 0.85f, t },
			{ 0.025f * w, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.3f, 0.85f, t },
			{ 0.0f, p, 0.0f, 0.0f, 0.0f, 1.0f, 0.3f, 0.85f, t },

			{ 0.0f, p, 0.0f, 0.0f, 0.0f, 1.0f, 0.3f, 0.85f, t },
			{ vl.x, vl.y, vl.z, 0.0f, 0.0f, 1.0f, 0.3f, 0.85f, t },
			{ -vl.x, vl.y, vl.z, 0.0f, 0.0f, 1.0f, 0.3f, 0.85f, t },

			{ vl.x, vl.y, vl.z, 0.0f, 0.0f, 1.0f, 0.3f, 0.85f, t },
			{ -vh.x, vh.y, vh.z, 0.0f, 0.0f, 1.0f, 0.3f, 0.85f, t },
			{ -vl.x, vl.y, vl.z, 0.0f, 0.0f, 1.0f, 0.3f, 0.85f, t },

			{ vl.x, vl.y, vl.z, 0.0f, 0.0f, 1.0f, 0.3f, 0.85f, t },
			{ vh.x, vh.y, vh.z, 0.0f, 0.0f, 1.0f, 0.3f, 0.85f, t },
			{ -vh.x, vh.y, vh.z, 0.0f, 0.0f, 1.0f, 0.3f, 0.85f, t },

			{ vh.x, vh.y, vh.z, 0.0f, 0.0f, 1.0f, 0.3f, 0.85f, t },
			{ 0.0f, p + l, 0.0f, 0.0f, 0.0f, 1.0f, 0.3f, 0.85f, t },
			{ -vh.x, vh.y, vh.z, 0.0f, 0.0f, 1.0f, 0.3f, 0.85f, t },

			{ 0.025f * w, 0.0f, 0.0f, 0.0f, 0.0f, -1.0f, 0.3f, 0.85f, t },
			{ -0.025f * w, 0.0f, 0.0f, 0.0f, 0.0f, -1.0f, 0.3f, 0.85f, t },
			{ 0.0f, p, 0.0f, 0.0f, 0.0f, -1.0f, 0.3f, 0.85f, t },

			{ 0.0f, p, 0.0f, 0.0f, 0.0f, -1.0f, 0.3f, 0.85f, t },
			{ -vl.x, vl.y, vl.z, 0.0f, 0.0f, -1.0f, 0.3f, 0.85f, t },
			{ vl.x, vl.y, vl.z, 0.0f, 0.0f, -1.0f, 0.3f, 0.85f, t },

			{ vl.x, vl.y, vl.z, 0.0f, 0.0f, -1.0f, 0.3f, 0.85f, t },
			{ -vl.x, vl.y, vl.z, 0.0f, 0.0f, -1.0f, 0.3f, 0.85f, t },
			{ -vh.x, vh.y, vh.z, 0.0f, 0.0f, -1.0f, 0.3f, 0.85f, t },

			{ vl.x, vl.y, vl.z, 0.0f, 0.0f, -1.0f, 0.3f, 0.85f, t },
			{ -vh.x, vh.y, vh.z, 0.0f, 0.0f, -1.0f, 0.3f, 0.85f, t },
			{ vh.x, vh.y, vh.z, 0.0f, 0.0f, -1.0f, 0.3f, 0.85f, t },

			{ vh.x, vh.y, vh.z, 0.0f, 0.0f, -1.0f, 0.3f, 0.85f, t },
			{ -vh.x, vh.y, vh.z, 0.0f, 0.0f, -1.0f, 0.3f, 0.85f, t },
			{ 0.0f, p + l, 0.0f, 0.0f, 0.0f, -1.0f, 0.3f, 0.85f, t }
		});

		turtle->translateState(glm::vec3(0.0f, l, 0.0f));
	}

	void drawTesselatedGenericBranchSegment(GraphicsTurtle *turtle, LSystemSymbol *sym, LSystem *sys)
	{
		float R = sym->getParam('R');
		float r = sym->getParam('r');
		float h = sym->getParam('h');
		float t = sym->getParam('t');
		float w = sym->getParam('w');

		float phi = 0.0f;
		float sf = std::sin(phi), cf = std::cos(phi);
		float sfu = std::sin(phi + pi_2), cfu = std::cos(phi + pi_2);
		float p = std::sqrt(h * h + (R - r) * (R - r));
		float s = w, ds = w / 4.0f;

		glm::vec3 nm(h / p * cf, (R - r) / p, h / p * sf);
		glm::vec3 nmu(h / p * cfu, (R - r) / p, h / p * sfu);

		Vertex vx[4] {
			{ R * cf, 0.0f, R * sf, nm.x, nm.y, nm.z, s, 0.0f, t },
			{ R * cfu, 0.0f, R * sfu, nmu.x, nmu.y, nmu.z, s - ds, 0.0f, t },
			{ r * cf, h, r * sf, nm.x, nm.y, nm.z, s, 1.0f, t },
			{ r * cfu, h, r * sfu, nmu.x, nmu.y, nmu.z, s - ds, 1.0f, t }
		};

		std::vector<Vertex> vertices;

		for (unsigned char i = 0u; i < 4u; ++i)
		{
			vertices.push_back(vx[0]);
			vertices.push_back(vx[1]);
			vertices.push_back(vx[2]);
			vertices.push_back(vx[3]);

			phi += pi_2; s -= ds;
			sf = sfu; cf = cfu;
			sfu = std::sin(phi + pi_2); cfu = std::cos(phi + pi_2);

			vx[0] = vx[1]; vx[2] = vx[3];
			nmu.x = h / p * cfu; nmu.z = h / p * sfu;
			vx[1].x = R * cfu; vx[1].z = R * sfu;
			vx[1].nx = nmu.x; vx[1].nz = nmu.z;
			vx[3].x = r * cfu; vx[3].z = r * sfu;
			vx[3].nx = nmu.x; vx[3].nz = nmu.z;
			vx[0].s = s; vx[1].s = s - ds; vx[2].s = s; vx[3].s = s - ds;
		}

		turtle->addVertices(vertices);
		turtle->translateState(glm::vec3(0.0f, h, 0.0f));
	}

}
