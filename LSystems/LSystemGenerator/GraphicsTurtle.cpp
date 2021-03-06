
#include "GraphicsTurtle.h"
#include "ConsoleProgressBar.h"
#include "..\..\include\glm\gtx\quaternion.hpp"
#include "..\..\include\glm\gtc\matrix_transform.hpp"
#include <sstream>

namespace lsys
{

	using TurtleAction = std::function<void(GraphicsTurtle *, LSystemSymbol *, LSystem *)>;

	const TurtleAction empty_action([](GraphicsTurtle *, LSystemSymbol *, LSystem *) { });

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
		for (std::size_t i = 1ull; i < stack_size; ++i)
			state_stack.pop();
		current_state = state_stack.top();
		current_transform = glm::mat4(1.0f);
	}

	void GraphicsTurtle::updateTransform()
	{
		current_transform = glm::translate(glm::mat4(1.0f), current_state.position) * glm::toMat4(current_state.orientation);
	}

	void GraphicsTurtle::translateState(const glm::vec3& offset)
	{
		current_state.position += glm::vec3(glm::rotate(current_state.orientation, glm::vec4(offset, 1.0f)));
	}

	void GraphicsTurtle::rotateAroundUp(float angle)
	{
		glm::vec3 current_up = glm::normalize(glm::rotate(current_state.orientation, initial_up));
		current_state.orientation = glm::angleAxis(glm::radians(angle), current_up) * current_state.orientation;
	}

	void GraphicsTurtle::rotateAroundLeft(float angle)
	{
		glm::vec3 current_left = glm::normalize(glm::rotate(current_state.orientation, initial_left));
		current_state.orientation = glm::angleAxis(glm::radians(angle), current_left) * current_state.orientation;
	}

	void GraphicsTurtle::rotateAroundHeading(float angle)
	{
		glm::vec3 current_heading = glm::normalize(glm::rotate(current_state.orientation, initial_heading));
		current_state.orientation = glm::angleAxis(glm::radians(angle), current_heading) * current_state.orientation;
	}

	void GraphicsTurtle::rotateToVector(const glm::vec3& target)
	{
		glm::vec3 current_heading = glm::normalize(glm::rotate(current_state.orientation, initial_heading));
		float angle_cosine = glm::clamp(glm::dot(current_heading, target), -1.0f, 1.0f);

		if (std::fabsf(angle_cosine - 1.0f) < eps)
			return;
		else if (std::fabsf(angle_cosine + 1.0f) < eps)
		{
			glm::vec3 current_left = glm::normalize(glm::rotate(current_state.orientation, initial_left));
			current_state.orientation = glm::angleAxis(glm::radians(180.0f), current_left) * current_state.orientation;
		}
		else
		{
			glm::vec3 axis = glm::normalize(glm::cross(current_heading, target));
			current_state.orientation = glm::angleAxis(glm::radians(glm::acos(angle_cosine)), axis) * current_state.orientation;
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

		lhelp::ConsoleProgressBar symbol_interpretation(symbol_count);
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
		std::ostringstream out;
		out << "Turtle's symbols = { ";

		std::map<char, TurtleAction>::const_iterator& act = actions.cbegin();
		for (; act != std::prev(actions.cend()); ++act)
			out << act->first << ", ";
		out  << act->first << " }" << std::endl;
		
		return out.str();
	}
	
	void GraphicsTurtle::resetBuffers()
	{
		GraphicsTurtle::vertex_buffer.clear();
		GraphicsTurtle::transform_buffer.clear();
		GraphicsTurtle::transform_index = 0.0f;
	}

}
