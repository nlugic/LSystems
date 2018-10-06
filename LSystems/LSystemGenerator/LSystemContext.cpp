
#include "LSystemContext.h"

namespace lsys
{

	LSystemContext::LSystemContext(LSystem *lSys, const TurtleState& state)
		:lSystem(lSys), turtle(lSystem, state) { }

	LSystemContext::LSystemContext(const char *params, const TurtleState& state)
		:lSystem(new LSystem(params)), turtle(lSystem, state) { }

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

	void LSystemContext::initTurtleFunctions()
	{
		turtle.setFunction('[', saveTurtleState);
		turtle.setFunction(']', restoreTurtleState);
		turtle.setFunction('+', turnTurtleLeft);
		turtle.setFunction('-', turnTurtleRight);
		turtle.setFunction('^', pitchTurtleUp);
		turtle.setFunction('&', pitchTurtleDown);
		turtle.setFunction('\\', rollTurtleLeft);
		turtle.setFunction('/', rollTurtleRight);
		turtle.setFunction('|', turnTurtleAround);
	}

	GraphicsTurtle& LSystemContext::getTurtle()
	{
		return turtle;
	}

	const std::vector<float> LSystemContext::getCurrentVertexBuffer() const
	{
		return turtle.getVertices();
	}

	const std::vector<unsigned>& LSystemContext::getCurrentElementBuffer() const
	{
		return turtle.getElements();
	}

	const std::vector<glm::mat4>& LSystemContext::getCurrentTransformBuffer() const
	{
		return turtle.getTransforms();
	}

	void LSystemContext::drawLevel(size_t level)
	{
		size_t curr = lSystem->getCurrentLevel();
		if (level > curr)
			lSystem->derive(level - curr);

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
