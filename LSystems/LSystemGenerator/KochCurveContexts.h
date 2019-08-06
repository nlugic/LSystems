#ifndef KOCHCURVECONTEXTS_H
#define KOCHCURVECONTEXTS_H

#include "LSystemContext.h"
#include "KochCurveLSystem.h"
#include "TurtleActions.h"

namespace lsys
{

	class KochSnowflakeContext : public LSystemContext
	{
	public:
		KochSnowflakeContext(std::size_t max_l, float length, float angle, const TurtleState& state = default_turtle_state)
			:LSystemContext(new KochCurveLSystem(new KochSnowflakeProduction(), length, angle, 3.0f), max_l, state)
		{
			turtle.setAction('F', drawLine);
		}

		virtual LSystemContext *clone() const override { return new KochSnowflakeContext(*this); }
	};

	class KochIslandContextA : public LSystemContext
	{
	public:
		KochIslandContextA(std::size_t max_l, float length, float angle, const TurtleState& state = default_turtle_state)
			:LSystemContext(new KochCurveLSystem(new KochIslandProductionA(), length, angle), max_l, state)
		{
			turtle.setAction('F', drawLine);
		}

		virtual LSystemContext *clone() const override { return new KochIslandContextA(*this); }
	};

	class KochIslandContextB : public LSystemContext
	{
	public:
		KochIslandContextB(std::size_t max_l, float length, float angle, const TurtleState& state = default_turtle_state)
			:LSystemContext(new KochCurveLSystem(new KochIslandProductionB(length, angle), length, angle), max_l, state)
		{
			turtle.setAction('F', drawLine);
		}

		virtual LSystemContext *clone() const override { return new KochIslandContextB(*this); }
	};

	class KochIslandContextC : public LSystemContext
	{
	public:
		KochIslandContextC(std::size_t max_l, float length, float angle, const TurtleState& state = default_turtle_state)
			:LSystemContext(new KochCurveLSystem(new KochIslandProductionC(length, angle), length, angle), max_l, state)
		{
			turtle.setAction('F', drawLine);
		}

		virtual LSystemContext *clone() const override { return new KochIslandContextC(*this); }
	};

	class KochIslandContextD : public LSystemContext
	{
	public:
		KochIslandContextD(std::size_t max_l, float length, float angle, const TurtleState& state = default_turtle_state)
			:LSystemContext(new KochCurveLSystem(new KochIslandProductionD(length, angle), length, angle), max_l, state)
		{
			turtle.setAction('F', drawLine);
		}

		virtual LSystemContext *clone() const override { return new KochIslandContextD(*this); }
	};

	class KochIslandContextE : public LSystemContext
	{
	public:
		KochIslandContextE(std::size_t max_l, float length, float angle, const TurtleState& state = default_turtle_state)
			:LSystemContext(new KochCurveLSystem(new KochIslandProductionE(length, angle), length, angle), max_l, state)
		{
			turtle.setAction('F', drawLine);
		}

		virtual LSystemContext *clone() const override { return new KochIslandContextE(*this); }
	};

	class KochIslandContextF : public LSystemContext
	{
	public:
		KochIslandContextF(std::size_t max_l, float length, float angle, const TurtleState& state = default_turtle_state)
			:LSystemContext(new KochCurveLSystem(new KochIslandProductionF(length, angle), length, angle), max_l, state)
		{
			turtle.setAction('F', drawLine);
		}

		virtual LSystemContext *clone() const override { return new KochIslandContextF(*this); }
	};

	class KochIslandContextG : public LSystemContext
	{
	public:
		KochIslandContextG(std::size_t max_l, float length, float angle, const TurtleState& state = default_turtle_state)
			:LSystemContext(new KochCurveLSystem(new KochIslandProductionG(length, angle), length, angle), max_l, state)
		{
			turtle.setAction('F', drawLine);
		}

		virtual LSystemContext *clone() const override { return new KochIslandContextG(*this); }
	};

}

#endif
