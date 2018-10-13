
#include "GraphicsTurtle.h"
#include "..\..\include\glm\gtc\matrix_transform.hpp"

namespace lsys
{

	const std::function<void(GraphicsTurtle *, LSystemSymbol *, LSystem *)> emptyAction =
		std::function<void(GraphicsTurtle *, LSystemSymbol *, LSystem *)>([](GraphicsTurtle *, LSystemSymbol *, LSystem *) {});

	float GraphicsTurtle::transformPointer = 0.0f;

	GraphicsTurtle::GraphicsTurtle(LSystem *owner, const TurtleState& state)
		:owner(owner), initialState(state), currentState(initialState), elementPointer(0U)
	{
		updateTransform();
	}

	void GraphicsTurtle::setOwner(LSystem *lSys)
	{
		owner = lSys;
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
		actions.emplace(key, func);
	}

	std::vector<float> GraphicsTurtle::getVertices() const
	{
		std::vector<float> buffer;
		for (Vertex vert : vertexBuffer)
			buffer.insert(buffer.end(), &vert.x, &vert.x + sizeof(Vertex) / sizeof(float));

		return buffer;
	}

	const std::vector<unsigned>& GraphicsTurtle::getElements() const
	{
		return elementBuffer;
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
		if (stateStack.empty())
			currentState = initialState;
		else
		{
			currentState = stateStack.top();
			stateStack.pop();
		}
		updateTransform();
	}

	void GraphicsTurtle::updateTransform()
	{
		glm::mat4 mat(glm::translate(glm::mat4(1.0f), currentState.position));
		glm::vec3 axis = glm::cross(glm::vec3(0.0f, 1.0f, 0.0f), currentState.heading);
		float sine = glm::length(axis);

		if (sine)
			currentTransform = glm::rotate(mat, glm::asin(sine), (sine) ? axis : currentState.heading);
		else
		{
			axis = glm::cross(glm::vec3(-1.0f, 0.0f, 0.0f), currentState.left);
			sine = glm::length(axis);
			currentTransform = glm::rotate(mat, glm::asin(sine), (sine) ? axis : currentState.left);
		}
	}

	void GraphicsTurtle::translateState(const glm::vec3& offset)
	{
		glm::mat4 currentRotation(currentTransform);
		std::memset(&currentRotation[3], 0, 3 * sizeof(float));
		currentState.position += glm::vec3(currentRotation * glm::vec4(offset, 1.0f));
		updateTransform();
	}

	void GraphicsTurtle::rotateAroundUp(float angle)
	{
		glm::mat4 mat(glm::rotate(glm::mat4(1.0f), glm::radians(angle), currentState.up));
		currentState.heading = mat * glm::vec4(currentState.heading, 1.0f);
		currentState.left = mat * glm::vec4(currentState.left, 1.0f);
		updateTransform();
	}

	void GraphicsTurtle::rotateAroundLeft(float angle)
	{
		glm::mat4 mat(glm::rotate(glm::mat4(1.0f), glm::radians(angle), currentState.left));
		currentState.heading = mat * glm::vec4(currentState.heading, 1.0f);
		currentState.up = mat * glm::vec4(currentState.up, 1.0f);
		updateTransform();
	}

	void GraphicsTurtle::rotateAroundHeading(float angle)
	{
		glm::mat4 mat(glm::rotate(glm::mat4(1.0f), glm::radians(angle), currentState.heading));
		currentState.left = mat * glm::vec4(currentState.left, 1.0f);
		currentState.up = mat * glm::vec4(currentState.up, 1.0f);
		updateTransform();
	}

	void GraphicsTurtle::rotateToVector(const glm::vec3& target)
	{
		glm::vec3 axis = glm::cross(currentState.heading, target);
		float sine = glm::length(axis);
		glm::mat4 mat(glm::rotate(glm::mat4(1.0f), glm::asin(sine), axis));
		currentState.heading = mat * glm::vec4(currentState.heading, 1.0f);
		currentState.left = mat * glm::vec4(currentState.left, 1.0f);
		currentState.up = mat * glm::vec4(currentState.up, 1.0f);
		updateTransform();
	}

	void GraphicsTurtle::addVertices(const std::vector<Vertex>& vertices)
	{
		for (Vertex vert : vertices)
		{
			ptrdiff_t pos = std::distance(vertexBuffer.begin(), std::find(vertexBuffer.begin(), vertexBuffer.end(), vert));
			if (pos >= static_cast<ptrdiff_t>(vertexBuffer.size()))
			{
				vertexBuffer.push_back(vert);
				elementBuffer.push_back(elementPointer++);
			}
			else
				elementBuffer.push_back(static_cast<unsigned>(pos));
		}
		transformBuffer.push_back(currentTransform);
	}

	void GraphicsTurtle::interpretSymbols(const std::vector<LSystemSymbol *>& symbols)
	{
		for (LSystemSymbol *sym : symbols)
			if (actions.count(sym->getKey()))
				actions[sym->getKey()](this, sym, owner);
	}

	std::string GraphicsTurtle::toString() const
	{
		std::string ret("Turtle's symbols = { ");
		for (std::map<char, std::function<void(GraphicsTurtle *, LSystemSymbol *, LSystem *)>>::const_iterator& iter = actions.begin(); iter != actions.end(); ++iter)
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
