
#include "TurtleDrawingFunctions.h"
#include "..\..\include\glm\gtc\matrix_transform.hpp"

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
			*/

			vertices.push_back({ R * cf, 0.0f, R * sf, nx, sa, nz, s, 0.0f, t });
			vertices.push_back({ r * cf, h, r * sf, nx, sa, nz, s, 1.0f, t });

			phi += ang; s -= ds;
			sf = std::sin(phi); cf = std::cos(phi);
		}

		turtle->addVertices(vertices);
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
		TurtleState& state = turtle->getCurrentState();
		glm::mat4 mat(1.0f);
		mat = glm::rotate(mat, glm::radians(sym->getParam('y')), state.up);
		state.heading = mat * glm::vec4(state.heading, 1.0f);
		state.left = mat * glm::vec4(state.left, 1.0f);
	}

	void turnTurtleRight(GraphicsTurtle *turtle, LSystemSymbol *sym)
	{
		TurtleState& state = turtle->getCurrentState();
		glm::mat4 mat(1.0f);
		mat = glm::rotate(mat, glm::radians(-sym->getParam('y')), state.up);
		state.heading = mat * glm::vec4(state.heading, 1.0f);
		state.left = mat * glm::vec4(state.left, 1.0f);
	}

	void pitchTurtleUp(GraphicsTurtle *turtle, LSystemSymbol *sym)
	{
		TurtleState& state = turtle->getCurrentState();
		glm::mat4 mat(1.0f);
		mat = glm::rotate(mat, glm::radians(-sym->getParam('p')), state.left);
		state.heading = mat * glm::vec4(state.heading, 1.0f);
		state.up = mat * glm::vec4(state.up, 1.0f);
	}

	void pitchTurtleDown(GraphicsTurtle *turtle, LSystemSymbol *sym)
	{
		TurtleState& state = turtle->getCurrentState();
		glm::mat4 mat(1.0f);
		mat = glm::rotate(mat, glm::radians(sym->getParam('p')), state.left);
		state.heading = mat * glm::vec4(state.heading, 1.0f);
		state.up = mat * glm::vec4(state.up, 1.0f);
	}

	void rollTurtleLeft(GraphicsTurtle *turtle, LSystemSymbol *sym)
	{
		TurtleState& state = turtle->getCurrentState();
		glm::mat4 mat(1.0f);
		mat = glm::rotate(mat, glm::radians(-sym->getParam('r')), state.heading);
		state.left = mat * glm::vec4(state.left, 1.0f);
		state.up = mat * glm::vec4(state.up, 1.0f);
	}

	void rollTurtleRight(GraphicsTurtle *turtle, LSystemSymbol *sym)
	{
		TurtleState& state = turtle->getCurrentState();
		glm::mat4 mat(1.0f);
		mat = glm::rotate(mat, glm::radians(sym->getParam('r')), state.heading);
		state.left = mat * glm::vec4(state.left, 1.0f);
		state.up = mat * glm::vec4(state.up, 1.0f);
	}

	void turnTurtleAround(GraphicsTurtle *turtle, LSystemSymbol *sym)
	{
		TurtleState& state = turtle->getCurrentState();
		glm::mat4 mat(1.0f);
		mat = glm::rotate(mat, glm::radians(180.0f), state.up);
		state.heading = mat * glm::vec4(state.heading, 1.0f);
		state.left = mat * glm::vec4(state.left, 1.0f);
	}

	void rotateTurtleToVertical(GraphicsTurtle *turtle, LSystemSymbol *sym)
	{
		TurtleState& state = turtle->getCurrentState();
		glm::vec3 axis = glm::cross(state.heading, glm::vec3(0.0f, 1.0f, 0.0f));
		float sine = glm::length(axis);
		glm::mat4 mat(1.0f);
		mat = glm::rotate(mat, glm::asin(sine), axis);
		state.heading = mat * glm::vec4(state.heading, 1.0f);
		state.left = mat * glm::vec4(state.left, 1.0f);
		state.up = mat * glm::vec4(state.up, 1.0f);
	}

}
