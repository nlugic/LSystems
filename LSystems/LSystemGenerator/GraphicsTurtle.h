#ifndef GRAPHICSTURTLE_H
#define GRAPHICSTURTLE_H

#include "LSystem.h"
#include "..\..\include\glm\glm.hpp"
#include <stack>
#include <functional>

namespace lsys
{

	struct Vertex
	{
		float x, y, z;
		float nx, ny, nz;
		float s, t, d, tr;

		bool operator==(const Vertex& v)
		{
			return x == v.x && y == v.y && z == v.z
				&& nx == v.nx && ny == v.ny && nz == v.nz
				&& s == v.s && t == v.t && d == v.d && tr == v.tr;
		}
	};

	struct TurtleState
	{
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
		LSystem *owner;
		std::map<char, std::function<void(GraphicsTurtle *, LSystemSymbol *, LSystem *)>> actions;

		TurtleState initialState, currentState;
		glm::mat4 currentTransform;
		std::stack<TurtleState> stateStack;

		std::vector<Vertex> vertexBuffer;
		unsigned elementPointer;
		std::vector<unsigned> elementBuffer;
		std::vector<glm::mat4> transformBuffer;
		
	public:
		static float transformPointer;

		GraphicsTurtle(LSystem *owner, const TurtleState& state = defaultTurtleState);
		GraphicsTurtle(const GraphicsTurtle&) = default;
		GraphicsTurtle& operator=(const GraphicsTurtle&) = default;
		~GraphicsTurtle() = default;

		void setOwner(LSystem *lSys);
		TurtleState& getCurrentState();
		glm::mat4& getCurrentTransform();
		const std::function<void(GraphicsTurtle *, LSystemSymbol *, LSystem *)>& getAction(char key) const;
		void setAction(char key, const std::function<void(GraphicsTurtle *, LSystemSymbol *, LSystem *)>& func);
		std::vector<float> getVertices() const;
		const std::vector<unsigned>& getElements() const;
		const std::vector<glm::mat4>& getTransforms() const;

		void pushState();
		void popState();
		void updateTransform();
		void translateState(const glm::vec3& offset);
		void rotateAroundUp(float angle);
		void rotateAroundLeft(float angle);
		void rotateAroundHeading(float angle);
		void rotateToVector(const glm::vec3& target);
		void interpretSymbols(const std::vector<LSystemSymbol *>& symbols);
		void addVertices(const std::vector<Vertex>& vertices);

		std::string toString() const;
		friend std::ostream& operator<<(std::ostream& out, const GraphicsTurtle& gTrt);
	};

}

#endif
