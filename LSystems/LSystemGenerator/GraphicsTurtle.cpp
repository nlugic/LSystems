
#include "GraphicsTurtle.h"
#include "..\..\include\glm\gtc\matrix_transform.hpp"

#define GLM_ENABLE_EXPERIMENTAL
#include "..\..\include\glm\gtc\quaternion.hpp"
#include "..\..\include\glm\gtx\quaternion.hpp"

namespace lsys
{

	const std::function<void(GraphicsTurtle *, LSystemSymbol *, LSystem *)> emptyAction =
		std::function<void(GraphicsTurtle *, LSystemSymbol *, LSystem *)>([](GraphicsTurtle *, LSystemSymbol *, LSystem *) {});

	unsigned GraphicsTurtle::elementPointer = 0U;
	float GraphicsTurtle::transformPointer = 0.0f;

	GraphicsTurtle::GraphicsTurtle(LSystem *owner, const TurtleState& state)
		:owner(owner), currentState(state), currentTransform(glm::mat4(1.0f))
	{
		stateStack.push(currentState);
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
		actions[key] = func;
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
		currentState = stateStack.top();
		if (stateStack.size() > 1)
			stateStack.pop();
		updateTransform();
	}

	void GraphicsTurtle::resetState()
	{
		vertexBuffer.clear();
		elementBuffer.clear();
		transformBuffer.clear();
		size_t stackSize = stateStack.size();
		for (unsigned i = 1U; i < stackSize; ++i)
			stateStack.pop();
		currentState = stateStack.top();
		updateTransform();
	}

	void GraphicsTurtle::updateTransform()
	{
		glm::quat rot(glm::vec3(glm::radians(-currentState.pitch), glm::radians(currentState.roll), glm::radians(currentState.yaw)));
		currentTransform = glm::translate(glm::mat4(1.0f), currentState.position) * glm::toMat4(rot);
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
		currentState.yaw += angle;
		updateTransform();
	}

	void GraphicsTurtle::rotateAroundLeft(float angle)
	{
		currentState.pitch += angle;
		updateTransform();
	}

	void GraphicsTurtle::rotateAroundHeading(float angle)
	{
		currentState.roll += angle;
		updateTransform();
	}

	void GraphicsTurtle::rotateToVector(const glm::vec3& target)
	{
		glm::mat4 mat(glm::rotate(glm::mat4(1.0f), glm::radians(currentState.yaw), glm::vec3(0.0f, 0.0f, 1.0f)));
		glm::vec3 heading = glm::vec3(glm::rotate(mat, glm::radians(currentState.pitch), glm::vec3(-1.0f, 0.0f, 0.0f))
			* glm::vec4(0.0f, 1.0f, 0.0f, 1.0f));

		glm::vec3 axis = glm::cross(heading, target);
		float sine = glm::length(axis);
		mat = (glm::rotate(currentTransform, glm::asin(sine), axis));
		currentState.yaw = std::atan2(mat[1][0], mat[0][0]);
		currentState.pitch = std::atan2(mat[2][1], mat[2][2]);
		currentState.roll = std::atan2(-mat[2][0], std::sqrt(mat[2][1] * mat[2][1] + mat[2][2] * mat[2][2]));
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
				elementBuffer.push_back(GraphicsTurtle::elementPointer++);
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
				getAction(sym->getKey())(this, sym, owner);
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
