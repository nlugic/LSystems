#ifndef GRAPHICSTURTLE_H
#define GRAPHICSTURTLE_H

#include "LSystemSymbol.h"
#include "..\..\include\glm\glm.hpp"
#include <stack>
#include <functional>

namespace lsys
{

	struct TurtleState
	{
	public:
		glm::vec3 position;
		glm::vec3 heading, left, up;
	};

	const TurtleState defaultTurtleState =
	{
		glm::vec3(0.0f), glm::vec3(0.0f, 1.0f, 0.0f),
		glm::vec3(-1.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f)
	};

	class GraphicsTurtle
	{
	private:
		std::map<char, std::function<void(GraphicsTurtle *, LSystemSymbol *)>> drawingFuncs;
		std::stack<TurtleState> statesStack;
		const TurtleState initialState;
		TurtleState currentState;

	public:
		GraphicsTurtle(const TurtleState& state = defaultTurtleState);
		GraphicsTurtle(const GraphicsTurtle&) = default;
		GraphicsTurtle& operator=(const GraphicsTurtle&) = default;
		~GraphicsTurtle() = default;

		TurtleState& getCurrentState();
		std::function<void(GraphicsTurtle *, LSystemSymbol *)> getFunction(char key);
		void setFunction(char key, const std::function<void(GraphicsTurtle *, LSystemSymbol *)>& func);
		void drawSymbol(LSystemSymbol *sym);
		void pushState();
		void popState();
	};

}

#endif
