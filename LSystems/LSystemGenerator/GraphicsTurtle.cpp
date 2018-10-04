
#include "GraphicsTurtle.h"
#include "..\..\include\glm\gtc\matrix_transform.hpp"

namespace lsys
{

	unsigned GraphicsTurtle::transformPointer = 0U;

	GraphicsTurtle::GraphicsTurtle(LSystem *owner, const TurtleState& state)
		:owner(owner), initialState(state), currentState(initialState), elemPointer(0U)
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

	std::function<void(GraphicsTurtle *, LSystemSymbol *, LSystem *)> GraphicsTurtle::getFunction(char key)
	{
		return drawingFuncs[key];
	}

	void GraphicsTurtle::setFunction(char key, const std::function<void(GraphicsTurtle *, LSystemSymbol *, LSystem *)>& func)
	{
		drawingFuncs[key] = func;
	}

	std::vector<float> GraphicsTurtle::getVertices() const
	{
		std::vector<float> buffer;

		for (Vertex vert : vertexBuffer)
			buffer.insert(buffer.end(), &vert.x, &vert.x + sizeof(Vertex) / sizeof(float) - 1);

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
		updateTransform();
	}

	void GraphicsTurtle::translateState(const glm::vec3& offset)
	{
		currentState.position += glm::vec3(currentTransform * glm::vec4(offset, 1.0f));
		updateTransform();
	}

	void GraphicsTurtle::rotateStateAroundUp(float angle)
	{
		glm::mat4 mat(1.0f);
		mat = glm::rotate(mat, glm::radians(angle), currentState.up);
		currentState.heading = mat * glm::vec4(currentState.heading, 1.0f);
		currentState.left = mat * glm::vec4(currentState.left, 1.0f);
	}

	void GraphicsTurtle::rotateStateAroundLeft(float angle)
	{
		glm::mat4 mat(1.0f);
		mat = glm::rotate(mat, glm::radians(angle), currentState.left);
		currentState.heading = mat * glm::vec4(currentState.heading, 1.0f);
		currentState.up = mat * glm::vec4(currentState.up, 1.0f);
	}

	void GraphicsTurtle::rotateStateAroundHeading(float angle)
	{
		glm::mat4 mat(1.0f);
		mat = glm::rotate(mat, glm::radians(angle), currentState.heading);
		currentState.left = mat * glm::vec4(currentState.left, 1.0f);
		currentState.up = mat * glm::vec4(currentState.up, 1.0f);
	}

	void GraphicsTurtle::rotateStateToVector(const glm::vec3& target)
	{
		glm::vec3 axis = glm::cross(currentState.heading, target);
		float sine = glm::length(axis);
		glm::mat4 mat(1.0f);
		mat = glm::rotate(mat, glm::asin(sine), axis);
		currentState.heading = mat * glm::vec4(currentState.heading, 1.0f);
		currentState.left = mat * glm::vec4(currentState.left, 1.0f);
		currentState.up = mat * glm::vec4(currentState.up, 1.0f);
	}

	void GraphicsTurtle::addVertices(const std::vector<Vertex>& vertices)
	{
		for (Vertex vert : vertices)
		{
			ptrdiff_t pos = std::distance(vertexBuffer.begin(), std::find(vertexBuffer.begin(), vertexBuffer.end(), vert));
			if (pos >= static_cast<ptrdiff_t>(vertexBuffer.size()))
			{
				vertexBuffer.push_back(vert);
				elementBuffer.push_back(elemPointer++);
			}
			else
				elementBuffer.push_back(static_cast<unsigned>(pos));

			transformBuffer.push_back(currentTransform);
		}
	}

	void GraphicsTurtle::interpretSymbols(const std::vector<LSystemSymbol *>& symbols)
	{
		for (LSystemSymbol *sym : symbols)
			drawingFuncs[sym->getKey()](this, sym, owner);
	}

	void GraphicsTurtle::updateTransform()
	{
		glm::vec3 axis = glm::cross(glm::vec3(0.0f, 1.0f, 0.0f), currentState.heading);
		float sine = glm::length(axis);
		glm::mat4 mat(1.0f);
		mat = glm::translate(mat, currentState.position);
		currentTransform = glm::rotate(mat, glm::asin(sine), axis);
	}

	std::string GraphicsTurtle::toString() const
	{
		std::string ret("Turtle's symbols = { ");
		for (std::map<char, std::function<void(GraphicsTurtle *, LSystemSymbol *, LSystem *)>>::const_iterator& iter = drawingFuncs.begin();
				iter != drawingFuncs.end(); ++iter)
			ret += iter->first + (std::distance(iter, drawingFuncs.end()) > 1) ? ", " : " ";
		ret += '}';

		return ret;
	}
	
	std::ostream& operator<<(std::ostream& out, const GraphicsTurtle& gTrt)
	{
		out << gTrt.toString();
		return out;
	}

}
