
#include "GraphicsTurtle.h"
#include "..\..\include\glm\gtc\matrix_transform.hpp"

namespace lsys
{

	unsigned GraphicsTurtle::transformPointer = 0U;

	GraphicsTurtle::GraphicsTurtle(const TurtleState& state)
		:initialState(state), currentState(initialState), elemPointer(0U)
	{
		updateTransform();
	}

	TurtleState& GraphicsTurtle::getCurrentState()
	{
		return currentState;
	}

	glm::mat4& GraphicsTurtle::getCurrentTransform()
	{
		return currentTransform;
	}

	std::function<void(GraphicsTurtle *, LSystemSymbol *)> GraphicsTurtle::getFunction(char key)
	{
		return drawingFuncs[key];
	}

	void GraphicsTurtle::setFunction(char key, const std::function<void(GraphicsTurtle *, LSystemSymbol *)>& func)
	{
		drawingFuncs[key] = func;
	}

	std::vector<float> GraphicsTurtle::getVertices() const
	{
		std::vector<float> buffer;

		for (Vertex vert : vertexBuffer)
		{
			buffer.push_back(vert.x);
			buffer.push_back(vert.y);
			buffer.push_back(vert.z);
			buffer.push_back(vert.nx);
			buffer.push_back(vert.ny);
			buffer.push_back(vert.nz);
			buffer.push_back(vert.s);
			buffer.push_back(vert.t);
			buffer.push_back(vert.d);
			buffer.push_back(vert.tr);
		}

		return buffer;
	}

	const std::vector<unsigned>& GraphicsTurtle::getElements() const
	{
		return elementBuffer;
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
		currentState.position += offset;
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

	void GraphicsTurtle::rotateStateToVector(glm::vec3& target)
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
			if (vert.tr == NAN)
				elementBuffer.push_back(UINT_MAX);
			else
			{
				ptrdiff_t pos = std::distance(vertexBuffer.begin(), std::find(vertexBuffer.begin(), vertexBuffer.end(), vert));
				if (pos >= vertexBuffer.size())
				{
					vertexBuffer.push_back(vert);
					elementBuffer.push_back(elemPointer++);
				}
				else
					elementBuffer.push_back(pos);
			}
		}
	}

	void GraphicsTurtle::interpretSymbols(const std::vector<LSystemSymbol *>& symbols)
	{
		for (LSystemSymbol *sym : symbols)
			drawingFuncs[sym->getKey()](this, sym);
	}

	void GraphicsTurtle::updateTransform()
	{
		glm::vec3 axis = glm::cross(glm::vec3(0.0f, 1.0f, 0.0f), currentState.heading);
		float sine = glm::length(axis);
		glm::mat4 mat(1.0f);
		mat = glm::translate(mat, currentState.position);
		currentTransform = glm::rotate(mat, glm::asin(sine), axis);
	}

}
