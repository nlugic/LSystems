#ifndef GENERIC2DTREECONTEXTS_H
#define GENERIC2DTREECONTEXTS_H

#include "LSystemContext.h"
#include "Generic2DTreeLSystems.h"
#include "TurtleActions.h"

namespace lsys
{

	class Generic2DTreContextA : public LSystemContext
	{
	public:
		Generic2DTreContextA(std::size_t max_l, float length, float angle = 25.7f,
			const TurtleState& state = default_turtle_state)
			:LSystemContext(new Generic2DTreeLSystem('F', new Generic2DTreeProductionA(length, angle), length), max_l, state)
		{
			turtle.setAction('F', drawLine);
		}

		virtual LSystemContext *clone() const override { return new Generic2DTreContextA(*this); }
	};

	class Generic2DTreContextB : public LSystemContext
	{
	public:
		Generic2DTreContextB(std::size_t max_l, float length, float angle = 20.0f,
			const TurtleState& state = default_turtle_state)
			:LSystemContext(new Generic2DTreeLSystem('F', new Generic2DTreeProductionB(length, angle), length), max_l, state)
		{
			turtle.setAction('F', drawLine);
		}

		virtual LSystemContext *clone() const override { return new Generic2DTreContextB(*this); }
	};

	class Generic2DTreContextC : public LSystemContext
	{
	public:
		Generic2DTreContextC(std::size_t max_l, float length, float angle = 22.5f,
			const TurtleState& state = default_turtle_state)
			:LSystemContext(new Generic2DTreeLSystem('F', new Generic2DTreeProductionC(length, angle), length), max_l, state)
		{
			turtle.setAction('F', drawLine);
		}

		virtual LSystemContext *clone() const override { return new Generic2DTreContextC(*this); }
	};

	class Generic2DTreContextD : public LSystemContext
	{
	public:
		Generic2DTreContextD(std::size_t max_l, float length, float angle = 20.0f,
			const TurtleState& state = default_turtle_state)
			:LSystemContext(new Generic2DTreeLSystem('X', new Generic2DTreeProductionD(length, angle), length, true), max_l, state)
		{
			turtle.setAction('F', drawLine);
			turtle.setAction('X', drawLine);
		}

		virtual LSystemContext *clone() const override { return new Generic2DTreContextD(*this); }
	};

	class Generic2DTreContextE : public LSystemContext
	{
	public:
		Generic2DTreContextE(std::size_t max_l, float length, float angle = 25.7f,
			const TurtleState& state = default_turtle_state)
			:LSystemContext(new Generic2DTreeLSystem('X', new Generic2DTreeProductionE(length, angle), length, true), max_l, state)
		{
			turtle.setAction('F', drawLine);
			turtle.setAction('X', drawLine);
		}

		virtual LSystemContext *clone() const override { return new Generic2DTreContextE(*this); }
	};

	class Generic2DTreContextF : public LSystemContext
	{
	public:
		Generic2DTreContextF(std::size_t max_l, float length, float angle = 22.5f,
			const TurtleState& state = default_turtle_state)
			:LSystemContext(new Generic2DTreeLSystem('X', new Generic2DTreeProductionF(length, angle), length, true), max_l, state)
		{
			turtle.setAction('F', drawLine);
			turtle.setAction('X', drawLine);
		}

		virtual LSystemContext *clone() const override { return new Generic2DTreContextF(*this); }
	};

	class Generic2DTreContextS : public LSystemContext
	{
	public:
		Generic2DTreContextS(std::size_t max_l, float length, float angle = 22.5f,
			const TurtleState& state = default_turtle_state)
			:LSystemContext(new Generic2DTreeLSystem('F', new Generic2DTreeProductionS1(length, angle), length), max_l, state)
		{
			system->addProduction(new Generic2DTreeProductionS2(length, angle));
			system->addProduction(new Generic2DTreeProductionS3(length, angle));

			turtle.setAction('F', drawLine);
		}

		virtual LSystemContext *clone() const override { return new Generic2DTreContextS(*this); }
	};

	class Generic2DTreeContextSD : public LSystemContext
	{
	public:
		Generic2DTreeContextSD(std::size_t max_l, float length, float reduction, float angle = 85.0f,
			const TurtleState& state = default_turtle_state)
			:LSystemContext(new Generic2DTreeLSystemSD(length, reduction, angle), max_l, state)
		{
			turtle.setAction('F', drawLine);
		}

		virtual LSystemContext *clone() const override { return new Generic2DTreeContextSD(*this); }
	};

}

#endif
