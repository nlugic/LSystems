
#include "GraphicsTurtle.h"

namespace lsys
{

	GraphicsTurtle::GraphicsTurtle(const TurtleState& state)
		:initialState(state), currentState(initialState) { }

	TurtleState& GraphicsTurtle::getCurrentState()
	{
		return currentState;
	}

	std::function<void(GraphicsTurtle *, LSystemSymbol *)> GraphicsTurtle::getFunction(char key)
	{
		return drawingFuncs[key];
	}

	void GraphicsTurtle::setFunction(char key, const std::function<void(GraphicsTurtle *, LSystemSymbol *)>& func)
	{
		drawingFuncs[key] = func;
	}

	void GraphicsTurtle::drawSymbol(LSystemSymbol *sym)
	{
		drawingFuncs[sym->getKey()](this, sym);
	}

	void GraphicsTurtle::pushState()
	{
		statesStack.push(currentState);
	}

	void GraphicsTurtle::popState()
	{
		if (statesStack.empty())
			currentState = initialState;
		else
		{
			currentState = statesStack.top();
			statesStack.pop();
		}
	}

}
