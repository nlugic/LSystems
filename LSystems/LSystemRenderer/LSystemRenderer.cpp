
#include "LSystemRenderer.h"
#include "..\LSystemGenerator\TurtleDrawingFunctions.h"
#include "..\..\include\glm\gtc\matrix_transform.hpp"

#pragma comment (lib, "..\\x64\\Debug\\LSystemGenerator.lib")

namespace lrend
{

	LSystemRenderer::LSystemRenderer(lsys::LSystemContext *lCxt)
		:current(lCxt) { }

	LSystemRenderer::~LSystemRenderer()
	{
		delete current;
	}

	void LSystemRenderer::testOGLRender()
	{
		std::vector<float> vert {
			// back
			-0.5f, -0.5f, -0.5f, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f, 1.0f, 0.0f,
			-0.5f, 0.5f, -0.5f, 0.0f, 0.0f, -1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
			0.5f, 0.5f, -0.5f, 0.0f, 0.0f, -1.0f, 0.0f, 1.0f, 1.0f, 0.0f,
			0.5f, -0.5f, -0.5f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
			// front
			-0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
			0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f,
			0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
			-0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f, 0.0f,
			// left
			-0.5f, 0.5f, 0.5f, -1.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 0.0f,
			-0.5f, 0.5f, -0.5f, -1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f,
			-0.5f, -0.5f, -0.5f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f,
			-0.5f, -0.5f, 0.5f, -1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,
			// right
			0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,
			0.5f, 0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 0.0f,
			0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f,
			0.5f, -0.5f, 0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f,
			// bottom
			-0.5f, -0.5f, -0.5f, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f,
			0.5f, -0.5f, -0.5f, 0.0f, -1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
			0.5f, -0.5f, 0.5f, 0.0f, -1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f,
			-0.5f, -0.5f, 0.5f, 0.0f, -1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f,
			// top
			0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
			0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f,
			-0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f,
			-0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f
		};

		std::vector<unsigned> ind {
			0, 1, 2, 2, 3, 0, 4, 5, 6, 6, 7, 4, 8, 9, 10, 10, 11, 8,
			12, 13, 14, 14, 15, 12, 16, 17, 18, 18, 19, 16, 20, 21, 22, 22, 23, 20
		};

		std::vector<const char *> texs { "../LSystemRenderer/test.png", "../LSystemRenderer/tree.jpg" };

		std::vector<glm::mat4> transs;

		glm::mat4 tr1(1.0f);
		transs.push_back(glm::translate(tr1, glm::vec3(2.0f, 0.0f, 0.0f)));
		transs.push_back(glm::scale(tr1, glm::vec3(1.0f, 2.0f, 1.0f)));

		OGLRenderer::renderScene(vert, ind, texs, transs);
	}

	LSYSTEMRENDERER_API void LSystemRenderer::testTurtleRender()
	{
		lsys::GraphicsTurtle turtle(nullptr);

		turtle.setAction('[', lsys::saveTurtleState);
		turtle.setAction(']', lsys::restoreTurtleState);
		turtle.setAction('+', lsys::turnTurtleLeft);
		turtle.setAction('-', lsys::turnTurtleRight);
		turtle.setAction('^', lsys::pitchTurtleUp);
		turtle.setAction('&', lsys::pitchTurtleDown);
		turtle.setAction('\\', lsys::rollTurtleLeft);
		turtle.setAction('/', lsys::rollTurtleRight);
		turtle.setAction('|', lsys::turnTurtleAround);

		turtle.setAction('F', lsys::drawGenericBranchSegment);
		turtle.setAction('A', lsys::drawGenericBranchApex);
		turtle.setAction('L', lsys::drawGenericLeaf);

		/*
		lsys::LSystemSymbol *lsym = new lsys::LSystemSymbol('F');
		lsym->setParam('n', 16.0f);
		lsym->setParam('R', 1.0f);
		lsym->setParam('r', 0.5f);
		lsym->setParam('h', 4.0f);
		lsym->setParam('t', 0.0f);
		lsym->setParam('w', 4.0f);
		*/

		/*
		lsys::LSystemSymbol *lsym = new lsys::LSystemSymbol('A');
		lsym->setParam('n', 16.0f);
		lsym->setParam('r', 1.0f);
		lsym->setParam('h', 4.0f);
		lsym->setParam('t', 0.0f);
		lsym->setParam('w', 4.0f);
		*/

		/*
		lsys::LSystemSymbol *lsym = new lsys::LSystemSymbol('L');
		lsym->setParam('l', 0.1f);
		lsym->setParam('w', 0.04f);
		lsym->setParam('p', 0.05f);
		lsym->setParam('c', 0.25f);
		lsym->setParam('C', 0.5f);
		lsym->setParam('t', 1.0f);
		*/

		//std::vector<lsys::LSystemSymbol *> syms { lsym };

		lsys::LSystemSymbol *lsym1 = new lsys::LSystemSymbol('F');
		lsym1->setParam('n', 16.0f);
		lsym1->setParam('R', 1.0f);
		lsym1->setParam('r', 0.5f);
		lsym1->setParam('h', 4.0f);
		lsym1->setParam('t', 0.0f);
		lsym1->setParam('w', 4.0f);

		lsys::LSystemSymbol *lsym2 = new lsys::LSystemSymbol('F');
		lsym2->setParam('n', 16.0f);
		lsym2->setParam('R', 0.5f);
		lsym2->setParam('r', 0.25f);
		lsym2->setParam('h', 4.0f);
		lsym2->setParam('t', 0.0f);
		lsym2->setParam('w', 2.0f);

		lsys::LSystemSymbol *lsym3 = new lsys::LSystemSymbol('F');
		lsym3->setParam('n', 16.0f);
		lsym3->setParam('R', 0.25f);
		lsym3->setParam('r', 0.125f);
		lsym3->setParam('h', 2.0f);
		lsym3->setParam('t', 0.0f);
		lsym3->setParam('w', 1.0f);

		std::vector<lsys::LSystemSymbol *> syms { lsym1, lsym2, lsym3 };
		turtle.interpretSymbols(syms);
		// delete lsym;
		delete lsym1; delete lsym2; delete lsym3;

		std::vector<const char *> texs { "../LSystemRenderer/test.png", "../LSystemRenderer/tree.jpg" };

		OGLRenderer::renderScene(turtle.getVertices(), turtle.getElements(), texs, turtle.getTransforms());
	}

}
