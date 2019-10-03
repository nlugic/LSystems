
#include "LSystemContext.h"
#include "TurtleActions.h"
#include <sstream>

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

	void swap(LSystemContext& cxt_1, LSystemContext& cxt_2)
	{
		std::swap(cxt_1.current_level, cxt_2.current_level);
		std::swap(cxt_1.max_level, cxt_2.max_level);
		std::swap(cxt_1.system, cxt_2.system);
		std::swap(cxt_1.turtle, cxt_2.turtle);
	}

	void LSystemContext::generateModel(std::size_t level)
	{
		std::size_t curr_level = system->getCurrentLevel();

		if (level > curr_level)
#if defined(_DEBUG) || defined(_VERBOSE)
		{
			std::clog << "The L-system to be derived:" << std::endl << *system;
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
		std::ostringstream out;
		out << *system << "Maximum derivation level: " << max_level
			<< std::endl << turtle;

		return out.str();
	}

}
