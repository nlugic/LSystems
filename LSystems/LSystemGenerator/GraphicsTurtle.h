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
		float s, t, d;

		bool operator==(const Vertex& v)
		{
			return !std::memcmp(this, &v, sizeof(Vertex));
		}
	};

	struct VertexInstance
	{
		unsigned v;
		float tr;
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

		static std::vector<VertexInstance> vertexInstances;
		static std::vector<Vertex> vertexBuffer;
		static std::vector<glm::mat4> transformBuffer;
		static float transformPointer;

	public:
		GraphicsTurtle(LSystem *owner = nullptr, const TurtleState& state = defaultTurtleState);

		void setOwner(LSystem *lSys);
		const TurtleState& getInitialState() const;
		TurtleState& getCurrentState();
		glm::mat4& getCurrentTransform();
		const std::function<void(GraphicsTurtle *, LSystemSymbol *, LSystem *)>& getAction(char key) const;
		void setAction(char key, const std::function<void(GraphicsTurtle *, LSystemSymbol *, LSystem *)>& func);

		void pushState();
		void popState();
		void resetState();
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

		static std::vector<float> getVertexBuffer();
		static const std::vector<glm::mat4>& getTransformBuffer();
		static void resetBuffers();
	};

}

#endif
