#ifndef GENERIC3DTREESYMBOLS_H
#define GENERIC3DTREESYMBOLS_H

#include "LSystemSymbol.h"

namespace lsys
{

	class Generic3DTreeBranchSegmentSymbol : public LSystemSymbol
	{
	public:
		Generic3DTreeBranchSegmentSymbol(float slices, float radiusStart, float radiusEnd, float height, float textureWrap = 1.0f)
			:LSystemSymbol('F')
		{
			setParam('n', slices);
			setParam('R', radiusStart);
			setParam('r', radiusEnd);
			setParam('h', height);
			setParam('t', 0.0f);
			setParam('w', textureWrap);
		}
	};

	class Generic3DTreeBranchApexSymbol : public LSystemSymbol
	{
	public:
		Generic3DTreeBranchApexSymbol(float slices, float radius, float height, float textureWrap = 1.0f)
			:LSystemSymbol('A')
		{
			setParam('n', slices);
			setParam('r', radius);
			setParam('h', height);
			setParam('t', 0.0f);
			setParam('w', textureWrap);
		}
	};

	class Generic3DTreeLeafSymbol : public LSystemSymbol
	{
	public:
		Generic3DTreeLeafSymbol(float length, float width, float petiole, float firstCurve, float secondCurve)
			:LSystemSymbol('L')
		{
			setParam('l', length);
			setParam('w', width);
			setParam('p', petiole);
			setParam('c', firstCurve * length);
			setParam('C', secondCurve * length);
			setParam('t', -0.4f);
		}
	};

}

#endif
