
#include "GraphicsTurtle.h"
#include "..\..\include\glm\gtc\matrix_transform.hpp"

namespace lsys
{

	GraphicsTurtle::GraphicsTurtle(const TurtleState& state)
		:initialState(state), currentState(initialState), elemPointer(0U)
	{
		updateTransform;
	}

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

	void GraphicsTurtle::interpretSymbol(LSystemSymbol *sym)
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
		updateTransform();
	}

	void GraphicsTurtle::addVertices(const std::vector<Vertex>& vertices)
	{
		for (Vertex vert : vertices)
		{
			glm::vec4 vertVec(vert.x, vert.y, vert.z, 1.0f);
			vertVec = currentTransform * vertVec;
			glm::vec4 normVec(vert.nx, vert.ny, vert.nz, 1.0f);
			normVec = currentTransform * normVec;
			vert.x = vertVec.x; vert.y = vertVec.y; vert.z = vertVec.z;
			vert.nx = normVec.x; vert.ny = normVec.y; vert.nz = normVec.z;

			ptrdiff_t pos = std::distance(vertexBuffer.begin(), std::find(vertexBuffer.begin(), vertexBuffer.end(), vert));
			if (pos >= vertexBuffer.size())
			{
				vertexBuffer.push_back(vert);
				elementBuffer.push_back(elemPointer++);
			}
			else
				elementBuffer.push_back(pos);
		}
		elementBuffer.push_back(UINT_MAX);
	}

	void GraphicsTurtle::updateTransform()
	{
		glm::vec3 axis = glm::cross(glm::vec3(0.0f, 1.0f, 0.0f), currentState.heading);
		float sine = glm::length(axis);
		glm::mat4 mat(1.0f);
		mat = glm::translate(mat, currentState.position);
		currentTransform = glm::rotate(mat, glm::asin(sine), axis);
	}

	std::vector<float> GraphicsTurtle::getVertexBuffer() const
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
			buffer.push_back(vert.id);
		}
		
		return buffer;
	}

	const std::vector<unsigned>& GraphicsTurtle::getElementBuffer() const
	{
		return elementBuffer;
	}

}
