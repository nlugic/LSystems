
#include "LSystemContext.h"
#include "TurtleActions.h"

namespace lsys
{

	void LSystemContext::initTurtleActions()
	{
		turtle.setAction('[', saveTurtleState);
		turtle.setAction(']', restoreTurtleState);
		turtle.setAction('+', turnTurtleLeft);
		turtle.setAction('-', turnTurtleRight);
		turtle.setAction('^', pitchTurtleUp);
		turtle.setAction('&', pitchTurtleDown);
		turtle.setAction('\\', rollTurtleLeft);
		turtle.setAction('/', rollTurtleRight);
		turtle.setAction('|', turnTurtleAround);
		turtle.setAction('$', rotateTurtleToVertical);
	}

	LSystemContext::LSystemContext(std::size_t max_l, const TurtleState& state)
		:current_level(0U), max_level(max_l), system(new LSystem), turtle(system, state) { initTurtleActions(); }

	LSystemContext::LSystemContext(LSystem *sys, std::size_t max_l, const TurtleState& state)
		:current_level(0U), max_level(max_l), system(sys), turtle(system, state) { initTurtleActions(); }

	LSystemContext::LSystemContext(const LSystemContext& cxt)
		:current_level(cxt.current_level), system(cxt.system->clone()), turtle(cxt.turtle) { turtle.setOwner(system); }

	void swap(LSystemContext& cxt_1, LSystemContext& cxt_2)
	{
		std::swap(cxt_1.current_level, cxt_2.current_level);
		std::swap(cxt_1.max_level, cxt_2.max_level);
		std::swap(cxt_1.system, cxt_2.system);
		std::swap(cxt_1.turtle, cxt_2.turtle);
	}

	LSystemContext::LSystemContext(LSystemContext&& cxt) noexcept { swap(*this, cxt); }

	LSystemContext& LSystemContext::operator=(LSystemContext cxt) noexcept { swap(*this, cxt); return *this; }

	LSystemContext *LSystemContext::clone() const { return new LSystemContext(*this); }

	LSystemContext::~LSystemContext() { delete system; }

	std::size_t LSystemContext::getCurrentLevel() const { return current_level; }

	std::size_t LSystemContext::getMaxLevel() const { return max_level; }

	TurtleState& LSystemContext::getTurtleState() { return turtle.getCurrentState(); }

	void LSystemContext::generateModel(std::size_t level)
	{
		std::size_t curr_level = system->getCurrentLevel();

		if (level > curr_level)
#if defined(_DEBUG) || defined(_VERBOSE)
		{
			std::clog << "Deriving the L-system to level " << level << "..." << std::endl;
			system->derive(level - curr_level);
			std::clog << "L-system derivation finished!" << std::endl;
		}
#else
			system->derive(level - curr_level);
#endif

		turtle.interpretSymbols((*system)[level]);
		turtle.resetState();

		current_level = level;
	}

	std::string LSystemContext::toString() const
	{
		std::string ret(system->toString());
		ret += "Maximum derivation level: ";
		ret += std::to_string(max_level);
		ret += '\n';
		ret += turtle.toString();

		return ret;
	}

	std::ostream& operator<<(std::ostream& out, const LSystemContext& cxt) { out << cxt.toString(); return out; }

}
