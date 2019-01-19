
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

	LSystemContext::LSystemContext(const TurtleState& state)
		:currentLevel(0U), lSystem(new LSystem), turtle(lSystem, state)
	{
		initTurtleActions();
	}

	LSystemContext::LSystemContext(LSystem *lSys, const TurtleState& state)
		: currentLevel(0U), lSystem(lSys), turtle(lSystem, state)
	{
		initTurtleActions();
	}

	void swap(LSystemContext& lCxt1, LSystemContext& lCxt2)
	{
		std::swap(lCxt1.currentLevel, lCxt2.currentLevel);
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
		return lSystem->getCurrentLevel();
	}

	const std::vector<float> LSystemContext::getVertexBuffer() const
	{
		return turtle.getVertices();
	}

	const std::vector<glm::mat4>& LSystemContext::getTransformBuffer() const
	{
		return turtle.getTransforms();
	}

	void LSystemContext::generateModel(std::size_t level)
	{
		currentLevel = level;

		std::size_t curr = lSystem->getCurrentLevel();
		if (level > curr)
		{
			std::cout << "Deriving the L-system to level " << level << "..." << std::endl;
			lSystem->derive(level - curr);
			std::cout << "L-system derivation finished!" << std::endl;
		}

		turtle.resetState();
		turtle.interpretSymbols((*lSystem)[level]);

		GraphicsTurtle::transformPointer = 0U;
	}

	std::string LSystemContext::toString() const
	{
		std::string ret(lSystem->toString());
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
