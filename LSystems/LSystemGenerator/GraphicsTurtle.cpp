
#include "GraphicsTurtle.h"
#include "ConsoleProgressBar.h"
#include "..\..\include\glm\gtc\matrix_transform.hpp"

namespace lsys
{

	const std::function<void(GraphicsTurtle *, LSystemSymbol *, LSystem *)> emptyAction =
		std::function<void(GraphicsTurtle *, LSystemSymbol *, LSystem *)>([](GraphicsTurtle *, LSystemSymbol *, LSystem *) {});

	float GraphicsTurtle::transformPointer = 0.0f;

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
		if (actions.count(key))
			return actions.at(key);
		return emptyAction;
	}

	void GraphicsTurtle::setAction(char key, const std::function<void(GraphicsTurtle *, LSystemSymbol *, LSystem *)>& func)
	{
		actions[key] = func;
	}

	std::vector<float> GraphicsTurtle::getVertices() const
	{
		std::vector<float> buffer;
		for (const VertexInstance &vi : vertexInstances)
		{
			buffer.insert(buffer.end(), &vertexBuffer[vi.v].x, &vertexBuffer[vi.v].x + sizeof(Vertex) / sizeof(float));
			buffer.push_back(vi.tr);
		}

		return buffer;
	}

	const std::vector<glm::mat4>& GraphicsTurtle::getTransforms() const
	{
		return transformBuffer;
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
		updateTransform();
	}

	void GraphicsTurtle::resetState()
	{
		vertexInstances.clear();
		vertexBuffer.clear();
		transformBuffer.clear();
		std::size_t stackSize = stateStack.size();
		for (unsigned i = 1U; i < stackSize; ++i)
			stateStack.pop();
		currentState = stateStack.top();
		updateTransform();
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
		std::memset(&currentTransform[3], 0, 3 * sizeof(float));
		currentState.position += glm::vec3(currentTransform * glm::vec4(offset, 1.0f));
		updateTransform();
	}

	void GraphicsTurtle::rotateAroundUp(float angle)
	{
		glm::mat4 rot(glm::rotate(glm::mat4(1.0f), glm::radians(angle), currentState.up));
		currentState.heading = rot * glm::vec4(currentState.heading, 1.0f);
		currentState.left = rot * glm::vec4(currentState.left, 1.0f);
		updateTransform();
	}

	void GraphicsTurtle::rotateAroundLeft(float angle)
	{
		currentState.heading = glm::rotate(glm::mat4(1.0f), glm::radians(angle), currentState.left)
			* glm::vec4(currentState.heading, 1.0f);
		currentState.up = glm::cross(currentState.heading, currentState.left);
		updateTransform();
	}

	void GraphicsTurtle::rotateAroundHeading(float angle)
	{
		currentState.left = glm::rotate(glm::mat4(1.0f), glm::radians(angle), currentState.heading)
			* glm::vec4(currentState.left, 1.0f);
		currentState.up = glm::cross(currentState.heading, currentState.left);
		updateTransform();
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
			updateTransform();
		}
	}

	void GraphicsTurtle::addVertices(const std::vector<Vertex>& vertices)
	{
		for (const Vertex& vert : vertices)
		{
			std::ptrdiff_t pos = std::distance(vertexBuffer.begin(), std::find(vertexBuffer.begin(), vertexBuffer.end(), vert));
			unsigned vIndex = static_cast<unsigned>(pos);
			if (pos >= static_cast<std::ptrdiff_t>(vertexBuffer.size()))
			{
				vertexBuffer.push_back(vert);
				vIndex = static_cast<unsigned>(vertexBuffer.size() - 1U);
			}
			vertexInstances.push_back({ vIndex, GraphicsTurtle::transformPointer });
		}
		transformBuffer.push_back(currentTransform);
		++GraphicsTurtle::transformPointer;
	}

	void GraphicsTurtle::interpretSymbols(const std::vector<LSystemSymbol *>& symbols)
	{
		std::size_t symbolCount = symbols.size();
		
		std::cout << "Interpreting " << symbolCount << " symbols..." << std::endl;
		lsysh::ConsoleProgressBar symbolInterpretation(symbolCount);

		for (LSystemSymbol *sym : symbols)
		{
			if (actions.count(sym->getKey()))
				getAction(sym->getKey())(this, sym, owner);

			symbolInterpretation.step();
		}
		symbolInterpretation.finish(true);
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

}
