
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

	LSystemContext::LSystemContext(std::size_t maxL, const TurtleState& state)
		:currentLevel(0U), maxLevel(maxL), lSystem(new LSystem), turtle(lSystem, state)
	{
		initTurtleActions();
	}

	LSystemContext::LSystemContext(LSystem *lSys, std::size_t maxL, const TurtleState& state)
		:currentLevel(0U), maxLevel(maxL), lSystem(lSys), turtle(lSystem, state)
	{
		initTurtleActions();
	}

	void swap(LSystemContext& lCxt1, LSystemContext& lCxt2)
	{
		std::swap(lCxt1.currentLevel, lCxt2.currentLevel);
		std::swap(lCxt1.maxLevel, lCxt2.maxLevel);
		std::swap(lCxt1.lSystem, lCxt2.lSystem);
		std::swap(lCxt1.turtle, lCxt2.turtle);
	}

	LSystemContext::LSystemContext(const LSystemContext& lCxt)
		:currentLevel(lCxt.currentLevel), lSystem(new LSystem(*lCxt.lSystem)), turtle(lCxt.turtle)
	{
		turtle.setOwner(lSystem);
	}

	LSystemContext::LSystemContext(LSystemContext&& lCxt) noexcept
	{
		swap(*this, lCxt);
	}

	LSystemContext& LSystemContext::operator=(LSystemContext lCxt) noexcept
	{
		swap(*this, lCxt);
		return *this;
	}

	LSystemContext::~LSystemContext()
	{
		delete lSystem;
	}

	std::size_t LSystemContext::getCurrentLevel() const
	{
		return currentLevel;
	}

	std::size_t LSystemContext::getMaxLevel() const
	{
		return maxLevel;
	}

	void LSystemContext::generateModel(std::size_t level)
	{
		turtle.resetState();

		std::size_t curr = lSystem->getCurrentLevel();

		if (level > curr)
#if defined(_DEBUG) || defined(_VERBOSE)
		{
			std::clog << "Deriving the L-system to level " << level << "..." << std::endl;
			lSystem->derive(level - curr);
			std::clog << "L-system derivation finished!" << std::endl;
		}
#else
			lSystem->derive(level - curr);
#endif

		turtle.interpretSymbols((*lSystem)[level]);
		currentLevel = level;
	}

	std::string LSystemContext::toString() const
	{
		std::string ret(lSystem->toString());
		ret += "Maximum derivation level: ";
		ret += std::to_string(maxLevel);
		ret += '\n';
		ret += turtle.toString();

		return ret;
	}

	std::ostream& operator<<(std::ostream& out, const LSystemContext& lCxt)
	{
		out << lCxt.toString();
		return out;
	}

}
