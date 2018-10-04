
#include "TurtleDrawingFunctions.h"

namespace lsys
{

	void drawGenericBranchSegment(GraphicsTurtle *turtle, LSystemSymbol *lSym, LSystem *lSys)
	{
		float R = lSym->getParam('R');
		float r = lSym->getParam('r');
		float h = lSym->getParam('h');
		int n = static_cast<int>(lSym->getParam('n'));
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
		glm::vec3 v2(r * cf, h, r * sf);
		glm::vec3 v3(R * cfu, 0.0f, R * sfu);
		glm::vec3 v4(r * cfu, h, r * sfu);

		std::vector<Vertex> vertices;

		for (unsigned short i = 0U; i <= n; ++i)
		{
			vertices.push_back({ v1.x, v1.y, v1.z,
				nm.x, nm.y, nm.z, s, 0.0f, t,
				static_cast<float>(GraphicsTurtle::transformPointer) });

			vertices.push_back({ v4.x, v4.y, v4.z,
				nmu.x, nmu.y, nmu.z, s, 1.0f, t,
				static_cast<float>(GraphicsTurtle::transformPointer) });

			vertices.push_back({ v2.x, v2.y, v2.z,
				nm.x, nm.y, nm.z, s, 1.0f, t,
				static_cast<float>(GraphicsTurtle::transformPointer) });
			
			vertices.push_back({ v1.x, v1.y, v1.z,
				nm.x, nm.y, nm.z, s, 0.0f, t,
				static_cast<float>(GraphicsTurtle::transformPointer) });

			vertices.push_back({ v3.x, v3.y, v3.z,
				nmu.x, nmu.y, nmu.z, s, 0.0f, t,
				static_cast<float>(GraphicsTurtle::transformPointer) });

			vertices.push_back({ v4.x, v4.y, v4.z,
				nmu.x, nmu.y, nmu.z, s, 1.0f, t,
				static_cast<float>(GraphicsTurtle::transformPointer) });

			phi += ang; s -= ds;
			sf = sfu; cf = cfu;
			sfu = std::sin(phi + ang); cfu = std::cos(phi + ang);
			v1 = v3; v2 = v4; nm = nmu;
			v3.x = R * cfu; v3.y = 0.0f; v3.z = R * sfu;
			v3.x = r * cfu; v3.y = h; v3.z = r * sfu;
			nmu.x = h / p * cfu; nmu.y = (R - r) / p; nmu.z = h / p * sfu;
		}

		turtle->addVertices(vertices);
		++GraphicsTurtle::transformPointer;
		glm::vec3 trans = v2 - v1;
		turtle->translateState(trans);
	}

	void drawGenericBranchApex(GraphicsTurtle *turtle, LSystemSymbol *lSym, LSystem *lSys)
	{

	}

	void drawGenericLeaf(GraphicsTurtle *turtle, LSystemSymbol *lSym, LSystem *lSys)
	{

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
