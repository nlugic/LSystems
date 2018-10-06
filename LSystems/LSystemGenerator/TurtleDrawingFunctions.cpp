
#include "TurtleDrawingFunctions.h"

namespace lsys
{

	void drawGenericBranchSegment(GraphicsTurtle *turtle, LSystemSymbol *lSym, LSystem *lSys)
	{
		int n = static_cast<int>(lSym->getParam('n'));
		float R = lSym->getParam('R');
		float r = lSym->getParam('r');
		float h = lSym->getParam('h');
		float t = lSym->getParam('t');
		float w = lSym->getParam('w');

		float ang = pix2 / n;
		float phi = 0.0f;
		float sf = std::sin(phi), cf = std::cos(phi);
		float sfu = std::sin(phi + ang), cfu = std::cos(phi + ang);
		float p = std::sqrt(h * h + (R - r) * (R - r));
		float s = w, ds = w / (n + 1);

		glm::vec3 nm(h / p * cf, (R - r) / p, h / p * sf);
		glm::vec3 nmu(h / p * cfu, (R - r) / p, h / p * sfu);

		glm::vec3 v1(R * cf, 0.0f, R * sf);
		glm::vec3 v1u(R * cfu, 0.0f, R * sfu);
		glm::vec3 v2(r * cf, h, r * sf);
		glm::vec3 v2u(r * cfu, h, r * sfu);

		std::vector<Vertex> vertices;

		for (unsigned short i = 0U; i <= n; ++i)
		{
			vertices.push_back({ v1.x, v1.y, v1.z,
				nm.x, nm.y, nm.z, s, 0.0f, t,
				static_cast<float>(GraphicsTurtle::transformPointer) });

			vertices.push_back({ v2u.x, v2u.y, v2u.z,
				nmu.x, nmu.y, nmu.z, s, 1.0f, t,
				static_cast<float>(GraphicsTurtle::transformPointer) });

			vertices.push_back({ v2.x, v2.y, v2.z,
				nm.x, nm.y, nm.z, s, 1.0f, t,
				static_cast<float>(GraphicsTurtle::transformPointer) });
			
			vertices.push_back({ v1.x, v1.y, v1.z,
				nm.x, nm.y, nm.z, s, 0.0f, t,
				static_cast<float>(GraphicsTurtle::transformPointer) });

			vertices.push_back({ v1u.x, v1u.y, v1u.z,
				nmu.x, nmu.y, nmu.z, s, 0.0f, t,
				static_cast<float>(GraphicsTurtle::transformPointer) });

			vertices.push_back({ v2u.x, v2u.y, v2u.z,
				nmu.x, nmu.y, nmu.z, s, 1.0f, t,
				static_cast<float>(GraphicsTurtle::transformPointer) });

			phi += ang; s -= ds;
			sf = sfu; cf = cfu;
			sfu = std::sin(phi + ang); cfu = std::cos(phi + ang);
			v1 = v1u; v2 = v2u; nm = nmu;
			nmu.x = h / p * cfu; nmu.y = (R - r) / p; nmu.z = h / p * sfu;
			v1u.x = R * cfu; v1u.y = 0.0f; v1u.z = R * sfu;
			v2u.x = r * cfu; v2u.y = h; v2u.z = r * sfu;
		}

		turtle->addVertices(vertices);
		++GraphicsTurtle::transformPointer;
		glm::vec3 trans = v2 - v1;
		turtle->translateState(trans);
	}

	void drawGenericBranchApex(GraphicsTurtle *turtle, LSystemSymbol *lSym, LSystem *lSys)
	{
		int n = static_cast<int>(lSym->getParam('n'));
		float r = lSym->getParam('r');
		float h = lSym->getParam('h');
		float t = lSym->getParam('t');
		float w = lSym->getParam('w');

		float ang = pix2 / n;
		float phi = 0.0f;
		float sf = std::sin(phi), cf = std::cos(phi);
		float sfu = std::sin(phi + ang), cfu = std::cos(phi + ang);
		float p = std::sqrt(h * h + r * r);
		float s = w, ds = w / (n + 1);

		glm::vec3 nm(h / p * cf, r / p, h / p * sf);
		glm::vec3 nmu(h / p * cfu, r / p, h / p * sfu);

		glm::vec3 v1(0.0f, h, 0.0f);
		glm::vec3 v2(r * cf, 0.0f, r * sf);
		glm::vec3 v2u(r * cfu, 0.0f, r * sfu);

		std::vector<Vertex> vertices;

		for (unsigned short i = 0U; i <= n; ++i)
		{
			vertices.push_back({ v1.x, v1.y, v1.z,
				(nm.x + nmu.x) / 2.0f, (nm.y + nmu.y) / 2.0f, (nm.z + nmu.z) / 2.0f,
				s, 1.0f, t,
				static_cast<float>(GraphicsTurtle::transformPointer) });

			vertices.push_back({ v2.x, v2.y, v2.z,
				nm.x, nm.y, nm.z, s, 0.0f, t,
				static_cast<float>(GraphicsTurtle::transformPointer) });

			vertices.push_back({ v2u.x, v2u.y, v2u.z,
				nmu.x, nmu.y, nmu.z, s, 0.0f, t,
				static_cast<float>(GraphicsTurtle::transformPointer) });

			phi += ang; s -= ds;
			sf = sfu; cf = cfu;
			sfu = std::sin(phi + ang); cfu = std::cos(phi + ang);
			v2 = v2u; nm = nmu;
			nmu.x = h / p * cfu; nmu.y = r / p; nmu.z = h / p * sfu;
			v2u.x = r * cfu; v2u.y = h; v2u.z = r * sfu;
		}

		turtle->addVertices(vertices);
		++GraphicsTurtle::transformPointer;
		glm::vec3 trans = v2 - v1;
		turtle->translateState(trans);
	}

	void drawGenericLeaf(GraphicsTurtle *turtle, LSystemSymbol *lSym, LSystem *lSys)
	{
		float l = lSym->getParam('l');
		float w = lSym->getParam('w');
		float c = lSym->getParam('c');
		float C = lSym->getParam('C');
		float t = lSym->getParam('t');

		glm::vec3 vl(l * c, 0.0f, w / 2);
		glm::vec3 vh(l * (1.0f - C), 0.0f, w / 2);

		std::vector<Vertex> vertices;

		vertices.push_back({ 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, t, GraphicsTurtle::transformPointer });
		vertices.push_back({ vl.x, vl.y, vl.z, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, t, GraphicsTurtle::transformPointer });
		vertices.push_back({ vl.x, vl.y, -vl.z, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, t, GraphicsTurtle::transformPointer });

		vertices.push_back({ vl.x, vl.y, vl.z, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, t, GraphicsTurtle::transformPointer });
		vertices.push_back({ vh.x, vh.y, -vh.z, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, t, GraphicsTurtle::transformPointer });
		vertices.push_back({ vl.x, vl.y, -vl.z, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, t, GraphicsTurtle::transformPointer });

		vertices.push_back({ vl.x, vl.y, vl.z, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, t, GraphicsTurtle::transformPointer });
		vertices.push_back({ vh.x, vh.y, vh.z, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, t, GraphicsTurtle::transformPointer });
		vertices.push_back({ vh.x, vh.y, -vh.z, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, t, GraphicsTurtle::transformPointer });

		vertices.push_back({ vh.x, vh.y, vh.z, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, t, GraphicsTurtle::transformPointer });
		vertices.push_back({ l, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, t, GraphicsTurtle::transformPointer });
		vertices.push_back({ vh.x, vh.y, -vh.z, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, t, GraphicsTurtle::transformPointer });

		vertices.push_back({ 0.0f, 0.0f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f, t, GraphicsTurtle::transformPointer });
		vertices.push_back({ vl.x, vl.y, -vl.z, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f, t, GraphicsTurtle::transformPointer });
		vertices.push_back({ vl.x, vl.y, vl.z, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f, t, GraphicsTurtle::transformPointer });

		vertices.push_back({ vl.x, vl.y, vl.z, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f, t, GraphicsTurtle::transformPointer });
		vertices.push_back({ vl.x, vl.y, -vl.z, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f, t, GraphicsTurtle::transformPointer });
		vertices.push_back({ vh.x, vh.y, -vh.z, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f, t, GraphicsTurtle::transformPointer });

		vertices.push_back({ vl.x, vl.y, vl.z, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f, t, GraphicsTurtle::transformPointer });
		vertices.push_back({ vh.x, vh.y, -vh.z, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f, t, GraphicsTurtle::transformPointer });
		vertices.push_back({ vh.x, vh.y, vh.z, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f, t, GraphicsTurtle::transformPointer });

		vertices.push_back({ vh.x, vh.y, vh.z, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f, t, GraphicsTurtle::transformPointer });
		vertices.push_back({ vh.x, vh.y, -vh.z, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f, t, GraphicsTurtle::transformPointer });
		vertices.push_back({ l, 0.0f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f, t, GraphicsTurtle::transformPointer });

		turtle->addVertices(vertices);
		++GraphicsTurtle::transformPointer;
		turtle->translateState(glm::vec3(l, 0.0f, 0.0f));
	}

	void saveTurtleState(GraphicsTurtle *turtle, LSystemSymbol *lSym, LSystem *lSys)
	{
		turtle->pushState();
	}

	void restoreTurtleState(GraphicsTurtle *turtle, LSystemSymbol *lSym, LSystem *lSys)
	{
		turtle->popState();
	}

	void turnTurtleLeft(GraphicsTurtle *turtle, LSystemSymbol *lSym, LSystem *lSys)
	{
		turtle->rotateStateAroundUp(lSym->getParam('y'));
	}

	void turnTurtleRight(GraphicsTurtle *turtle, LSystemSymbol *lSym, LSystem *lSys)
	{
		turtle->rotateStateAroundUp(-lSym->getParam('y'));
	}

	void pitchTurtleUp(GraphicsTurtle *turtle, LSystemSymbol *lSym, LSystem *lSys)
	{
		turtle->rotateStateAroundLeft(-lSym->getParam('p'));
	}

	void pitchTurtleDown(GraphicsTurtle *turtle, LSystemSymbol *lSym, LSystem *lSys)
	{
		turtle->rotateStateAroundLeft(lSym->getParam('p'));
	}

	void rollTurtleLeft(GraphicsTurtle *turtle, LSystemSymbol *lSym, LSystem *lSys)
	{
		turtle->rotateStateAroundHeading(-lSym->getParam('r'));
	}

	void rollTurtleRight(GraphicsTurtle *turtle, LSystemSymbol *lSym, LSystem *lSys)
	{
		turtle->rotateStateAroundHeading(lSym->getParam('r'));
	}

	void turnTurtleAround(GraphicsTurtle *turtle, LSystemSymbol *lSym, LSystem *lSys)
	{
		turtle->rotateStateAroundUp(180.0f);
	}

	void rotateTurtleToVertical(GraphicsTurtle *turtle, LSystemSymbol *lSym, LSystem *lSys)
	{
		turtle->rotateStateToVector(glm::vec3(0.0f, 1.0f, 0.0f));
	}

}
