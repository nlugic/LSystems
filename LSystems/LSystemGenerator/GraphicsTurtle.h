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
		float x, y, z, nx, ny, nz, s, t, d;

		bool operator==(const Vertex& v) { return !std::memcmp(this, &v, sizeof(Vertex)); }
	};
	
	struct TurtleState { glm::vec3 position, heading, left, up; };

	const TurtleState default_turtle_state =
	{
		glm::vec3(0.0f), glm::vec3(0.0f, 1.0f, 0.0f),
		glm::vec3(-1.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f)
	};

	class GraphicsTurtle
	{
	private:
		LSystem *owner;
		std::map<char, std::function<void(GraphicsTurtle *, LSystemSymbol *, LSystem *)>> actions;

		TurtleState initial_state, current_state;
		std::stack<TurtleState> state_stack;
		glm::mat4 current_transform;

		static std::vector<float> vertex_buffer;
		static std::vector<glm::mat4> transform_buffer;
		static float transform_index;

	public:
		GraphicsTurtle(LSystem *owner = nullptr, const TurtleState& state = default_turtle_state);
		GraphicsTurtle(const GraphicsTurtle&) = default;
		friend void swap(GraphicsTurtle& trt_1, GraphicsTurtle& trt_2);
		GraphicsTurtle(GraphicsTurtle&& trt) noexcept;
		GraphicsTurtle& operator=(GraphicsTurtle trt) noexcept;

		void setOwner(LSystem *sys);
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
		friend std::ostream& operator<<(std::ostream& out, const GraphicsTurtle& trt);

		static std::vector<float>& getVertexBuffer();
		static std::vector<glm::mat4>& getTransformBuffer();
		static void resetBuffers();
	};

}

#endif
