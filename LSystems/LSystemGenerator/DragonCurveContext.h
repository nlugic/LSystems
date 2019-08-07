#ifndef DRAGONCURVECONTEXT_H
#define DRAGONCURVECONTEXT_H

#include "LSystemContext.h"
#include "DragonCurveLSystem.h"
#include "TurtleActions.h"

namespace lsys
{

	class DragonCurveContext : public LSystemContext
	{
	public:
		inline DragonCurveContext(std::size_t max_l, float length, float angle,
			const TurtleState& state = default_turtle_state)
			:LSystemContext(new DragonCurveLSystem(length, angle),
				max_l, state) { turtle.setAction('L', drawLine); turtle.setAction('R', drawLine); }

		inline virtual LSystemContext *clone() const override { return new DragonCurveContext(*this); }
	};

}

#endif
