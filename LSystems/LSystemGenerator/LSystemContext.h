#ifndef LSYSTEMCONTEXT_H
#define LSYSTEMCONTEXT_H

#include "LSystem.h"
#include "GraphicsTurtle.h"

namespace lsys
{

	class LSystemContext
	{
	protected:
		std::size_t current_level, max_level;

		LSystem *system;
		GraphicsTurtle turtle;

		virtual void initTurtleActions();

	public:
		LSystemContext() = delete;
		LSystemContext(std::size_t max_l, const TurtleState& state = default_turtle_state);
		LSystemContext(LSystem *sys, std::size_t max_l, const TurtleState& state = default_turtle_state);
		LSystemContext(const LSystemContext& cxt);
		friend void swap(LSystemContext& cxt_1, LSystemContext& cxt_2);
		LSystemContext(LSystemContext&& cxt) noexcept;
		LSystemContext& operator=(LSystemContext cxt) noexcept;
		virtual LSystemContext *clone() const;
		virtual ~LSystemContext();

		std::size_t getCurrentLevel() const;
		std::size_t getMaxLevel() const;
		TurtleState& getTurtleState();
		void generateModel(std::size_t level);

		virtual std::string toString() const;
		friend std::ostream& operator<<(std::ostream& out, const LSystemContext& cxt);
	};

}

#endif
