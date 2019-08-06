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
		Generic3DTreeContext(std::size_t max_l, int slices, float radius, float height, float angle,
			const TurtleState& state = default_turtle_state)
			:LSystemContext(new Generic3DTreeLSystem(slices, radius, height, angle), max_l, state)
		{
			turtle.setAction('F', drawGenericBranchSegment);
			turtle.setAction('A', drawGenericBranchApex);
			turtle.setAction('L', drawGenericLeaf);
		}

		virtual LSystemContext *clone() const override { return new Generic3DTreeContext(*this); }
	};

	class TesselatedGeneric3DTreeContext : public LSystemContext
	{
	public:
		TesselatedGeneric3DTreeContext(std::size_t max_l, float radius, float height, float angle,
			const TurtleState& state = default_turtle_state)
			:LSystemContext(new TesselatedGeneric3DTreeLSystem(radius, height, angle), max_l, state)
		{
			turtle.setAction('F', drawTesselatedGenericBranchSegment);
		}

		virtual LSystemContext *clone() const override { return new TesselatedGeneric3DTreeContext(*this); }
	};

}

#endif
