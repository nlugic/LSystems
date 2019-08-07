
#include "GraphicsTurtle.h"
#include "ConsoleProgressBar.h"
#include "..\..\include\glm\gtc\matrix_transform.hpp"

namespace lsys
{

	using TurtleAction = std::function<void(GraphicsTurtle *, LSystemSymbol *, LSystem *)>;

	const TurtleAction empty_action = TurtleAction([](GraphicsTurtle *, LSystemSymbol *, LSystem *) { });

	std::vector<float> GraphicsTurtle::vertex_buffer;
	std::vector<glm::mat4> GraphicsTurtle::transform_buffer;
	float GraphicsTurtle::transform_index = 0.0f;

	void swap(GraphicsTurtle& trt_1, GraphicsTurtle& trt_2)
	{
		std::swap(trt_1.owner, trt_2.owner);
		std::swap(trt_1.actions, trt_2.actions);
		std::swap(trt_1.initial_state, trt_2.initial_state);
		std::swap(trt_1.current_state, trt_2.current_state);
		std::swap(trt_1.state_stack, trt_2.state_stack);
		std::swap(trt_1.current_transform, trt_2.current_transform);
	}
	
	const TurtleAction& GraphicsTurtle::getAction(char key) const
	{
		std::map<char, TurtleAction>::const_iterator value = actions.find(key);
		return (value != actions.end()) ? value->second : empty_action;
	}

	void GraphicsTurtle::resetState()
	{
		std::size_t stack_size = state_stack.size();
		for (unsigned int i = 1ULL; i < stack_size; ++i)
			state_stack.pop();
		current_state = state_stack.top();
		current_transform = glm::mat4(1.0f);
	}

	void GraphicsTurtle::updateTransform()
	{
		current_transform = glm::translate(glm::mat4(1.0f), current_state.position);

		glm::vec3 axis(glm::cross(initial_state.heading, current_state.heading));
		float angle = glm::acos(glm::clamp(glm::dot(initial_state.heading, current_state.heading), -1.0f, 1.0f));

		if (std::fabs(angle) > eps)
			current_transform = glm::rotate(current_transform, angle, (glm::length(axis) > eps) ? axis : current_state.up);
		else
		{
			angle = glm::acos(glm::clamp(glm::dot(initial_state.up, current_state.up), -1.0f, 1.0f));

			if (std::fabs(angle) > eps)
				current_transform = glm::rotate(current_transform, angle, current_state.heading);
		}
	}

	void GraphicsTurtle::translateState(const glm::vec3& offset)
	{
		std::memset(&current_transform[3], 0, 3ULL * sizeof(float));
		current_state.position += glm::vec3(current_transform * glm::vec4(offset, 1.0f));
	}

	void GraphicsTurtle::rotateAroundUp(float angle)
	{
		current_state.heading = glm::rotate(glm::mat4(1.0f), glm::radians(angle), current_state.up)
			* glm::vec4(current_state.heading, 1.0f);
		current_state.left = glm::cross(current_state.up, current_state.heading);
	}

	void GraphicsTurtle::rotateAroundLeft(float angle)
	{
		current_state.heading = glm::rotate(glm::mat4(1.0f), glm::radians(angle), current_state.left)
			* glm::vec4(current_state.heading, 1.0f);
		current_state.up = glm::cross(current_state.heading, current_state.left);
	}

	void GraphicsTurtle::rotateAroundHeading(float angle)
	{
		current_state.left = glm::rotate(glm::mat4(1.0f), glm::radians(angle), current_state.heading)
			* glm::vec4(current_state.left, 1.0f);
		current_state.up = glm::cross(current_state.heading, current_state.left);
	}

	void GraphicsTurtle::rotateToVector(const glm::vec3& target)
	{
		glm::vec3 axis = glm::cross(current_state.heading, target);
		float angle = glm::acos(glm::clamp(glm::dot(current_state.heading, target), -1.0f, 1.0f));

		if (std::fabs(angle) > eps)
		{
			glm::mat4 rot(glm::rotate(glm::mat4(1.0f), angle, (glm::length(axis) > eps) ? axis : current_state.up));
			current_state.heading = rot * glm::vec4(current_state.heading, 1.0f);
			current_state.left = rot * glm::vec4(current_state.left, 1.0f);
			current_state.up = glm::cross(current_state.heading, current_state.left);
		}
	}

	void GraphicsTurtle::addVertices(const std::vector<Vertex>& vertices)
	{
		for (const Vertex& vert : vertices)
		{
			GraphicsTurtle::vertex_buffer.insert(GraphicsTurtle::vertex_buffer.end(), &vert.x,
				&vert.x + sizeof(Vertex) / sizeof(float));
			GraphicsTurtle::vertex_buffer.push_back(GraphicsTurtle::transform_index);
		}
		updateTransform();
		GraphicsTurtle::transform_buffer.push_back(current_transform);
		++GraphicsTurtle::transform_index;
	}

	void GraphicsTurtle::interpretSymbols(const std::vector<LSystemSymbol *>& symbols)
	{
#if defined(_DEBUG) || defined(_VERBOSE)
		std::size_t symbol_count = symbols.size();

		std::clog << "Interpreting " << symbol_count << " symbols..." << std::endl;

		lsysh::ConsoleProgressBar symbol_interpretation(symbol_count);
#endif

		for (LSystemSymbol *sym : symbols)
		{
			if (actions.find(sym->getKey()) != actions.end())
				getAction(sym->getKey())(this, sym, owner);

#if defined(_DEBUG) || defined(_VERBOSE)
			symbol_interpretation.step();
		}
		symbol_interpretation.finish(true);
#else
		}
#endif
	}

	std::string GraphicsTurtle::toString() const
	{
		std::string ret("Turtle's symbols = { ");
		for (std::map<char, TurtleAction>::const_iterator& it = actions.begin(); it != actions.end(); ++it)
			ret += it->first + (std::distance(it, actions.end()) > 1) ? ", " : " ";
		ret += '}';
		
		return ret;
	}
	
	void GraphicsTurtle::resetBuffers()
	{
		GraphicsTurtle::vertex_buffer.clear();
		GraphicsTurtle::transform_buffer.clear();
		GraphicsTurtle::transform_index = 0.0f;
	}

}
