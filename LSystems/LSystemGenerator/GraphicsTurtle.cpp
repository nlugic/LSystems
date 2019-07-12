
#include "GraphicsTurtle.h"
#include "ConsoleProgressBar.h"
#include "..\..\include\glm\gtc\matrix_transform.hpp"

namespace lsys
{

	const std::function<void(GraphicsTurtle *, LSystemSymbol *, LSystem *)> emptyAction =
		std::function<void(GraphicsTurtle *, LSystemSymbol *, LSystem *)>([](GraphicsTurtle *, LSystemSymbol *, LSystem *) {});

	std::vector<float> GraphicsTurtle::vertexBuffer;
	std::vector<glm::mat4> GraphicsTurtle::transformBuffer;
	float GraphicsTurtle::transformIndex = 0.0f;

	GraphicsTurtle::GraphicsTurtle(LSystem *owner, const TurtleState& state)
		:owner(owner), initialState(state), currentState(state), currentTransform(glm::mat4(1.0f))
	{
		stateStack.push(currentState);
	}

	void GraphicsTurtle::setOwner(LSystem *lSys)
	{
		owner = lSys;
	}

	const TurtleState& GraphicsTurtle::getInitialState() const
	{
		return initialState;
	}

	TurtleState& GraphicsTurtle::getCurrentState()
	{
		return currentState;
	}

	glm::mat4& GraphicsTurtle::getCurrentTransform()
	{
		return currentTransform;
	}

	const std::function<void(GraphicsTurtle *, LSystemSymbol *, LSystem *)>& GraphicsTurtle::getAction(char key) const
	{
		if (actions.find(key) != actions.end())
			return actions.at(key);
		return emptyAction;
	}

	void GraphicsTurtle::setAction(char key, const std::function<void(GraphicsTurtle *, LSystemSymbol *, LSystem *)>& func)
	{
		actions[key] = func;
	}

	void GraphicsTurtle::pushState()
	{
		stateStack.push(currentState);
	}

	void GraphicsTurtle::popState()
	{
		currentState = stateStack.top();
		if (stateStack.size() > 1ULL)
			stateStack.pop();
	}

	void GraphicsTurtle::resetState()
	{
		std::size_t stackSize = stateStack.size();
		for (unsigned i = 1U; i < stackSize; ++i)
			stateStack.pop();
		currentState = stateStack.top();
		currentTransform = glm::mat4(1.0f);
	}

	void GraphicsTurtle::updateTransform()
	{
		currentTransform = glm::translate(glm::mat4(1.0f), currentState.position);

		glm::vec3 axis(glm::cross(initialState.heading, currentState.heading));
		float angle = glm::acos(glm::clamp(glm::dot(initialState.heading, currentState.heading), -1.0f, 1.0f));

		if (std::fabs(angle) > epsilon)
			currentTransform = glm::rotate(currentTransform, angle, (glm::length(axis) > epsilon) ? axis : currentState.up);
		else
		{
			angle = glm::acos(glm::clamp(glm::dot(initialState.up, currentState.up), -1.0f, 1.0f));

			if (std::fabs(angle) > epsilon)
				currentTransform = glm::rotate(currentTransform, angle, currentState.heading);
		}
	}

	void GraphicsTurtle::translateState(const glm::vec3& offset)
	{
		std::memset(&currentTransform[3], 0, 3ULL * sizeof(float));
		currentState.position += glm::vec3(currentTransform * glm::vec4(offset, 1.0f));
	}

	void GraphicsTurtle::rotateAroundUp(float angle)
	{
		currentState.heading = glm::rotate(glm::mat4(1.0f), glm::radians(angle), currentState.up)
			* glm::vec4(currentState.heading, 1.0f);
		currentState.left = glm::cross(currentState.up, currentState.heading);
	}

	void GraphicsTurtle::rotateAroundLeft(float angle)
	{
		currentState.heading = glm::rotate(glm::mat4(1.0f), glm::radians(angle), currentState.left)
			* glm::vec4(currentState.heading, 1.0f);
		currentState.up = glm::cross(currentState.heading, currentState.left);
	}

	void GraphicsTurtle::rotateAroundHeading(float angle)
	{
		currentState.left = glm::rotate(glm::mat4(1.0f), glm::radians(angle), currentState.heading)
			* glm::vec4(currentState.left, 1.0f);
		currentState.up = glm::cross(currentState.heading, currentState.left);
	}

	void GraphicsTurtle::rotateToVector(const glm::vec3& target)
	{
		glm::vec3 axis = glm::cross(currentState.heading, target);
		float angle = glm::acos(glm::clamp(glm::dot(currentState.heading, target), -1.0f, 1.0f));

		if (std::fabs(angle) > epsilon)
		{
			glm::mat4 rot(glm::rotate(glm::mat4(1.0f), angle, (glm::length(axis) > epsilon) ? axis : currentState.up));
			currentState.heading = rot * glm::vec4(currentState.heading, 1.0f);
			currentState.left = rot * glm::vec4(currentState.left, 1.0f);
			currentState.up = glm::cross(currentState.heading, currentState.left);
		}
	}

	void GraphicsTurtle::addVertices(const std::vector<Vertex>& vertices)
	{
		for (const Vertex& vert : vertices)
		{
			GraphicsTurtle::vertexBuffer.insert(GraphicsTurtle::vertexBuffer.end(), &vert.x,
				&vert.x + sizeof(Vertex) / sizeof(float));
			GraphicsTurtle::vertexBuffer.push_back(GraphicsTurtle::transformIndex);
		}
		updateTransform();
		GraphicsTurtle::transformBuffer.push_back(currentTransform);
		++GraphicsTurtle::transformIndex;
	}

	void GraphicsTurtle::interpretSymbols(const std::vector<LSystemSymbol *>& symbols)
	{
#if defined(_DEBUG) || defined(_VERBOSE)
		std::size_t symbolCount = symbols.size();

		std::clog << "Interpreting " << symbolCount << " symbols..." << std::endl;

		lsysh::ConsoleProgressBar symbolInterpretation(symbolCount);
#endif

		for (LSystemSymbol *sym : symbols)
		{
			if (actions.find(sym->getKey()) != actions.end())
				getAction(sym->getKey())(this, sym, owner);

#if defined(_DEBUG) || defined(_VERBOSE)
			symbolInterpretation.step();
		}
		symbolInterpretation.finish(true);
#else
		}
#endif
	}

	std::string GraphicsTurtle::toString() const
	{
		std::string ret("Turtle's symbols = { ");
		for (std::map<char, std::function<void(GraphicsTurtle *, LSystemSymbol *, LSystem *)>>::const_iterator& iter = actions.begin();
			iter != actions.end(); ++iter)
			ret += iter->first + (std::distance(iter, actions.end()) > 1) ? ", " : " ";
		ret += '}';
		
		return ret;
	}
	
	std::ostream& operator<<(std::ostream& out, const GraphicsTurtle& gTrt)
	{
		out << gTrt.toString();
		return out;
	}

	std::vector<float>& GraphicsTurtle::getVertexBuffer()
	{
		return GraphicsTurtle::vertexBuffer;
	}

	std::vector<glm::mat4>& GraphicsTurtle::getTransformBuffer()
	{
		return GraphicsTurtle::transformBuffer;
	}

	void GraphicsTurtle::resetBuffers()
	{
		GraphicsTurtle::vertexBuffer.clear();
		GraphicsTurtle::transformBuffer.clear();
		GraphicsTurtle::transformIndex = 0.0f;
	}

}
