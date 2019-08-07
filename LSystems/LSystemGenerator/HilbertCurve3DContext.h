#ifndef HILBERTCURVE3DCONTEXT_H
#define HILBERTCURVE3DCONTEXT_H

#include "LSystemContext.h"
#include "HilbertCurve3DLSystem.h"
#include "TurtleActions.h"

namespace lsys
{

	class HilbertCurve3DContext : public LSystemContext
	{
	public:
		inline HilbertCurve3DContext(std::size_t max_l, float width, float length, float angle,
			float red, float green, float blue, const TurtleState& state = default_turtle_state)
			:LSystemContext(new HilbertCurve3DLSystem(width, length, angle, glm::vec3(red, green, blue)),
				max_l, state) { turtle.setAction('F', drawBox); }

		inline virtual LSystemContext *clone() const override { return new HilbertCurve3DContext(*this); }
	};

}

#endif
