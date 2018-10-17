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
		HilbertCurve3DContext(int slices, float radius, float length, float angle)
			:LSystemContext(new HilbertCurve3DLSystem(slices, radius, length, angle))
		{
			turtle.setAction('F', drawGenericBranchSegment);
		}
	};

}

#endif
