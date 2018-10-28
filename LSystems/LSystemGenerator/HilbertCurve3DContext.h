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
		HilbertCurve3DContext(float width, float length, float angle, float red, float green, float blue)
			:LSystemContext(new HilbertCurve3DLSystem(width, length, angle, glm::vec3(red, green, blue)))
		{
			turtle.setAction('F', drawBox);
		}
	};

}

#endif
