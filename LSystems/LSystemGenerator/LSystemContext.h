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

		void initTurtleActions();

	public:
		LSystemContext() = delete;
		explicit inline LSystemContext(std::size_t max_l, const TurtleState& state = default_turtle_state)
			:current_level(0u), max_level(max_l), system(new LSystem), turtle(system, state) { initTurtleActions(); }
		inline LSystemContext(LSystem *sys, std::size_t max_l, const TurtleState& state = default_turtle_state)
			:current_level(0u), max_level(max_l), system(sys), turtle(system, state) { initTurtleActions(); }
		inline LSystemContext(const LSystemContext& cxt)
			:current_level(cxt.current_level), system(cxt.system->clone()), turtle(cxt.turtle) { turtle.setOwner(system); }
		friend void swap(LSystemContext& cxt_1, LSystemContext& cxt_2);
		inline LSystemContext(LSystemContext&& cxt) noexcept { swap(*this, cxt); }
		inline LSystemContext& operator=(LSystemContext cxt) noexcept { swap(*this, cxt); return *this; }
		inline virtual LSystemContext *clone() const { return new LSystemContext(*this); }
		inline virtual ~LSystemContext() { delete system; }

		inline std::size_t getCurrentLevel() const { return current_level; }
		inline std::size_t getMaxLevel() const { return max_level; }
		inline TurtleState& getTurtleState() { return turtle.getCurrentState(); }
		void generateModel(std::size_t level);

		virtual std::string toString() const;
		inline friend std::ostream& operator<<(std::ostream& out, const LSystemContext& cxt)
			{ return out << cxt.toString(); }
	};

}

#endif
