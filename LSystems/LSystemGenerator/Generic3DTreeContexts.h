#ifndef GENERIC3DTREECONTEXT_H
#define GENERIC3DTREECONTEXT_H

#include "LSystemContext.h"
#include "Generic3DTreeLSystems.h"
#include "TurtleActions.h"

namespace lsys
{

	class Generic3DTreeContext : public LSystemContext
	{
	public:
		Generic3DTreeContext(std::size_t maxL, int slices, float radius, float height, float angle)
			:LSystemContext(new Generic3DTreeLSystem(slices, radius, height, angle), maxL)
		{
			turtle.setAction('F', drawGenericBranchSegment);
			turtle.setAction('A', drawGenericBranchApex);
			turtle.setAction('L', drawGenericLeaf);
		}
	};

	class TesselatedGeneric3DTreeContext : public LSystemContext
	{
	public:
		TesselatedGeneric3DTreeContext(std::size_t maxL, float radius, float height, float angle)
			:LSystemContext(new TesselatedGeneric3DTreeLSystem(radius, height, angle), maxL)
		{
			turtle.setAction('F', drawTesselatedGenericBranchSegment);
		}
	};

}

#endif
