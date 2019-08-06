#ifndef GENERIC3DTREESYMBOLS_H
#define GENERIC3DTREESYMBOLS_H

#include "LSystemSymbol.h"

namespace lsys
{

	class Generic3DTreeBranchSegmentSymbol : public LSystemSymbol
	{
	public:
		Generic3DTreeBranchSegmentSymbol(float slices, float radius_start, float radius_end,
			float height, float texture_wrap = 1.0f)
			:LSystemSymbol('F')
		{
			setParam('n', slices);
			setParam('R', radius_start);
			setParam('r', radius_end);
			setParam('h', height);
			setParam('t', 0.0f);
			setParam('w', texture_wrap);
		}

		virtual LSystemSymbol *clone() const override { return new Generic3DTreeBranchSegmentSymbol(*this); }
	};

	class Generic3DTreeBranchApexSymbol : public LSystemSymbol
	{
	public:
		Generic3DTreeBranchApexSymbol(float slices, float radius, float height, float texture_wrap = 1.0f)
			:LSystemSymbol('A')
		{
			setParam('n', slices);
			setParam('r', radius);
			setParam('h', height);
			setParam('t', 0.0f);
			setParam('w', texture_wrap);
		}

		virtual LSystemSymbol *clone() const override { return new Generic3DTreeBranchApexSymbol(*this); }
	};

	class Generic3DTreeLeafSymbol : public LSystemSymbol
	{
	public:
		Generic3DTreeLeafSymbol(float length, float width, float petiole, float first_curve, float second_curve)
			:LSystemSymbol('L')
		{
			setParam('l', length);
			setParam('w', width);
			setParam('p', petiole);
			setParam('c', first_curve * length);
			setParam('C', second_curve * length);
			setParam('t', -0.4f);
		}

		virtual LSystemSymbol *clone() const override { return new Generic3DTreeLeafSymbol(*this); }
	};

}

#endif
