#ifndef GRAPHICSTURTLE_H
#define GRAPHICSTURTLE_H

#include "LSystem.h"
#include "..\..\include\glm\glm.hpp"
#define GLM_ENABLE_EXPERIMENTAL
#include "..\..\include\glm\gtc\quaternion.hpp"
#include <stack>
#include <functional>

namespace lsys
{

	struct Vertex
	{
		float x, y, z, nx, ny, nz, s, t, d;

		inline bool operator==(const Vertex& v) { return !std::memcmp(this, &v, sizeof(Vertex)); }
	};

	struct TurtleState { glm::vec3 position; glm::quat orientation; };

	const TurtleState default_turtle_state =
	{
		glm::vec3(0.0f), glm::quat(1.0f, 0.0f, 0.0f, 0.0f)
	};

	const glm::vec3 initial_heading(0.0f, 1.0f, 0.0f);
	const glm::vec3 initial_left(-1.0f, 1.0f, 0.0f);
	const glm::vec3 initial_up(0.0f, 0.0f, 1.0f);

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
		inline GraphicsTurtle(LSystem *owner = nullptr, const TurtleState& state = default_turtle_state)
			:owner(owner), initial_state(state), current_state(state),
			current_transform(glm::mat4(1.0f)) { state_stack.push(current_state); }
		inline GraphicsTurtle(const GraphicsTurtle&) = default;
		friend void swap(GraphicsTurtle& trt_1, GraphicsTurtle& trt_2);
		inline GraphicsTurtle(GraphicsTurtle&& trt) noexcept { swap(*this, trt); }
		inline GraphicsTurtle& operator=(GraphicsTurtle trt) noexcept { swap(*this, trt); return *this; }
		inline ~GraphicsTurtle() = default;

		inline void setOwner(LSystem *sys) { owner = sys; }
		inline const TurtleState& getInitialState() const { return initial_state; }
		inline TurtleState& getCurrentState() { return current_state; }
		inline glm::mat4& getCurrentTransform() { return current_transform; }
		const std::function<void(GraphicsTurtle *, LSystemSymbol *, LSystem *)>& getAction(char key) const;
		inline void setAction(char key, const std::function<void(GraphicsTurtle *, LSystemSymbol *, LSystem *)>& func)
			{ actions[key] = func; }

		inline void pushState() { state_stack.push(current_state); }
		inline void popState() { current_state = state_stack.top(); if (state_stack.size() > 1ull) state_stack.pop(); }
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
		inline friend std::ostream& operator<<(std::ostream& out, const GraphicsTurtle& trt)
			{ out << trt.toString(); return out; }

		inline static std::vector<float>& getVertexBuffer() { return GraphicsTurtle::vertex_buffer; }
		inline static std::vector<glm::mat4>& getTransformBuffer() { return GraphicsTurtle::transform_buffer; }
		static void resetBuffers();
	};

}

#endif
