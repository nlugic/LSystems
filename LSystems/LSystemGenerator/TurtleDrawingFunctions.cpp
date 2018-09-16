
#include "TurtleDrawingFunctions.h"

namespace lsys
{

	void drawBranchSegment(GraphicsTurtle *turtle, LSystemSymbol *sym)
	{
		std::vector<Vertex> vertices;

		float R = sym->getParam('R');
		float r = sym->getParam('r');
		float h = sym->getParam('h');
		int n = static_cast<int>(sym->getParam('n'));
		float t = sym->getParam('t');
		float w = sym->getParam('w');

		float ang = pix2 / n;
		float phi = 0.0f;
		float sf = std::sin(phi), cf = std::cos(phi);
		float p = std::sqrt(h * h + (R - r) * (R - r));
		float s = w, ds = w / (n + 1);

		glm::mat4 mat = turtle->getCurrentTransform();

		glm::vec4 nm(h / p * cf, (R - r) / p, h / p * sf, 1.0f);
		nm = mat * nm;

		glm::vec4 v1(R * cf, 0.0f, R * sf, 1.0f);
		v1 = mat * v1;
		glm::vec4 v2(r * cf, h, r * sf, 1.0f);
		v2 = mat * v2;

		for (unsigned short i = 0U; i <= n; ++i)
		{
			vertices.push_back({ v1.x, v1.y, v1.z, nm.x, nm.y, nm.z, s, 0.0f, t, GraphicsTurtle::transformPointer });
			vertices.push_back({ v2.x, v2.y, v2.z, nm.x, nm.y, nm.z, s, 1.0f, t, GraphicsTurtle::transformPointer });
			
			phi += ang; s -= ds;
			sf = std::sin(phi); cf = std::cos(phi);

			v1.x = R * cf; v1.y = 0.0f; v1.z = R * sf;
			v1 = mat * v1;
			v2.x = r * cf; v2.y = h; v2.z = r * sf;
			v2 = mat * v2;
		}

		glm::vec3 trans = v2 - v1;
		turtle->translateState(trans);

		vertices.push_back({ 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, NAN});

		/*

		float ang = pix2 / n;
		float phi = 0.0f;
		float sf = std::sin(phi), cf = std::cos(phi);
		float p = std::sqrt(h * h + (R - r) * (R - r));
		float sa = (R - r) / p, ca = h / p;
		float nx = ca * cf, nz = ca * sf;
		float s = w, ds = w / (n + 1);

		for (unsigned short i = 0U; i <= n; ++i)
		{
			/*
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
			/

			vertices.push_back({ R * cf, 0.0f, R * sf, nx, sa, nz, s, 0.0f, t });
			vertices.push_back({ r * cf, h, r * sf, nx, sa, nz, s, 1.0f, t });

			phi += ang; s -= ds;
			sf = std::sin(phi); cf = std::cos(phi);
		}
		*/

		turtle->addVertices(vertices);
		++GraphicsTurtle::transformPointer;
	}

	void saveTurtleState(GraphicsTurtle *turtle, LSystemSymbol *sym)
	{
		turtle->pushState();
	}

	void restoreTurtleState(GraphicsTurtle *turtle, LSystemSymbol *sym)
	{
		turtle->popState();
	}

	void turnTurtleLeft(GraphicsTurtle *turtle, LSystemSymbol *sym)
	{
		turtle->rotateStateAroundUp(sym->getParam('y'));
	}

	void turnTurtleRight(GraphicsTurtle *turtle, LSystemSymbol *sym)
	{
		turtle->rotateStateAroundUp(-sym->getParam('y'));
	}

	void pitchTurtleUp(GraphicsTurtle *turtle, LSystemSymbol *sym)
	{
		turtle->rotateStateAroundLeft(-sym->getParam('p'));
	}

	void pitchTurtleDown(GraphicsTurtle *turtle, LSystemSymbol *sym)
	{
		turtle->rotateStateAroundLeft(sym->getParam('p'));
	}

	void rollTurtleLeft(GraphicsTurtle *turtle, LSystemSymbol *sym)
	{
		turtle->rotateStateAroundHeading(-sym->getParam('r'));
	}

	void rollTurtleRight(GraphicsTurtle *turtle, LSystemSymbol *sym)
	{
		turtle->rotateStateAroundHeading(sym->getParam('r'));
	}

	void turnTurtleAround(GraphicsTurtle *turtle, LSystemSymbol *sym)
	{
		turtle->rotateStateAroundUp(180.0f);
	}

	void rotateTurtleToVertical(GraphicsTurtle *turtle, LSystemSymbol *sym)
	{
		turtle->rotateStateToVector(glm::vec3(0.0f, 1.0f, 0.0f));
	}

}
