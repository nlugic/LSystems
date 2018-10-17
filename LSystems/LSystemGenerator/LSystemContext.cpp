
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
		:lSystem(new LSystem), turtle(lSystem, state)
	{
		initTurtleActions();
	}

	LSystemContext::LSystemContext(LSystem *lSys, const TurtleState& state)
		:lSystem(lSys), turtle(lSystem, state)
	{
		initTurtleActions();
	}

	LSystemContext::LSystemContext(const LSystemContext& lCxt)
		:lSystem(new LSystem(*lCxt.lSystem)), turtle(lCxt.turtle)
	{
		turtle.setOwner(lSystem);
	}

	LSystemContext& LSystemContext::operator=(const LSystemContext& lCxt)
	{
		if (this != &lCxt)
		{
			delete lSystem;
			lSystem = new LSystem(*lCxt.lSystem);
			turtle = lCxt.turtle;
			turtle.setOwner(lSystem);
		}
		return *this;
	}

	LSystemContext::~LSystemContext()
	{
		delete lSystem;
	}

	const std::vector<float> LSystemContext::getVertexBuffer() const
	{
		return turtle.getVertices();
	}

	const std::vector<unsigned>& LSystemContext::getElementBuffer() const
	{
		return turtle.getElements();
	}

	const std::vector<glm::mat4>& LSystemContext::getTransformBuffer() const
	{
		return turtle.getTransforms();
	}

	void LSystemContext::generateModel(size_t level)
	{
		size_t curr = lSystem->getCurrentLevel();
		if (level > curr)
			lSystem->derive(level - curr);

		turtle.resetState();
		turtle.interpretSymbols((*lSystem)[level]);
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
