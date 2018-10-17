#ifndef GENERIC3DTREECONTEXT_H
#define GENERIC3DTREECONTEXT_H

#include "LSystemContext.h"
#include "Generic3DTreeLSystem.h"
#include "TurtleActions.h"

namespace lsys
{

	class Generic3DTreeContext : public LSystemContext
	{
	public:
		Generic3DTreeContext(int slices, float radius, float height, float angle)
			:LSystemContext(new Generic3DTreeLSystem(slices, radius, height, angle))
		{
			turtle.setAction('F', drawGenericBranchSegment);
			turtle.setAction('A', drawGenericBranchApex);
			turtle.setAction('L', drawGenericLeaf);
		}
	};

}

#endif
