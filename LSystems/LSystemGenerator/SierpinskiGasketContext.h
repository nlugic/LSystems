#ifndef SIERPINSKIGASKETCONTEXT_H
#define SIERPINSKIGASKETCONTEXT_H

#include "LSystemContext.h"
#include "SierpinskiGasketLSystem.h"
#include "TurtleActions.h"

namespace lsys
{

	class SierpinskiGasketContext : public LSystemContext
	{
	public:
		SierpinskiGasketContext(std::size_t max_l, float length, float angle,
			const TurtleState& state = default_turtle_state)
			:LSystemContext(new SierpinskiGasketLSystem(length, angle), max_l, state)
		{
			turtle.setAction('L', drawLine);
			turtle.setAction('R', drawLine);
		}

		inline virtual LSystemContext *clone() const override { return new SierpinskiGasketContext(*this); }
	};

}

#endif
