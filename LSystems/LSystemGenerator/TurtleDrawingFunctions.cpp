
#include "TurtleDrawingFunctions.h"
#include "..\..\include\glm\gtc\matrix_transform.hpp"

namespace lsys
{

	void drawBranchSegment(GraphicsTurtle *turtle, LSystemSymbol *sym)
	{

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
		glm::rotate(mat, glm::radians(sym->getParam('y')), state.up);
		state.heading = mat * glm::vec4(state.heading, 1.0f);
		state.left = mat * glm::vec4(state.left, 1.0f);
	}

	void turnTurtleRight(GraphicsTurtle *turtle, LSystemSymbol *sym)
	{
		TurtleState& state = turtle->getCurrentState();
		glm::mat4 mat(1.0f);
		glm::rotate(mat, glm::radians(-sym->getParam('y')), state.up);
		state.heading = mat * glm::vec4(state.heading, 1.0f);
		state.left = mat * glm::vec4(state.left, 1.0f);
	}

	void pitchTurtleUp(GraphicsTurtle *turtle, LSystemSymbol *sym)
	{
		TurtleState& state = turtle->getCurrentState();
		glm::mat4 mat(1.0f);
		glm::rotate(mat, glm::radians(-sym->getParam('p')), state.left);
		state.heading = mat * glm::vec4(state.heading, 1.0f);
		state.up = mat * glm::vec4(state.up, 1.0f);
	}

	void pitchTurtleDown(GraphicsTurtle *turtle, LSystemSymbol *sym)
	{
		TurtleState& state = turtle->getCurrentState();
		glm::mat4 mat(1.0f);
		glm::rotate(mat, glm::radians(sym->getParam('p')), state.left);
		state.heading = mat * glm::vec4(state.heading, 1.0f);
		state.up = mat * glm::vec4(state.up, 1.0f);
	}

	void rollTurtleLeft(GraphicsTurtle *turtle, LSystemSymbol *sym)
	{
		TurtleState& state = turtle->getCurrentState();
		glm::mat4 mat(1.0f);
		glm::rotate(mat, glm::radians(-sym->getParam('r')), state.heading);
		state.left = mat * glm::vec4(state.left, 1.0f);
		state.up = mat * glm::vec4(state.up, 1.0f);
	}

	void rollTurtleRight(GraphicsTurtle *turtle, LSystemSymbol *sym)
	{
		TurtleState& state = turtle->getCurrentState();
		glm::mat4 mat(1.0f);
		glm::rotate(mat, glm::radians(sym->getParam('r')), state.heading);
		state.left = mat * glm::vec4(state.left, 1.0f);
		state.up = mat * glm::vec4(state.up, 1.0f);
	}

	void turnTurtleAround(GraphicsTurtle *turtle, LSystemSymbol *sym)
	{
		TurtleState& state = turtle->getCurrentState();
		glm::mat4 mat(1.0f);
		glm::rotate(mat, glm::radians(180.0f), state.up);
		state.heading = mat * glm::vec4(state.heading, 1.0f);
		state.left = mat * glm::vec4(state.left, 1.0f);
	}

	void rotateTurtleToVertical(GraphicsTurtle *turtle, LSystemSymbol *sym)
	{

	}

}
