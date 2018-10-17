#ifndef HILBERTCURVE3DSYMBOLS_H
#define HILBERTCURVE3DSYMBOLS_H

#include "LSystemSymbol.h"

namespace lsys
{

	class HilbertCurve3DPipeSymbol : public LSystemSymbol
	{
	public:
		HilbertCurve3DPipeSymbol(float slices, float radius, float length, float angle)
			:LSystemSymbol('F')
		{
			setParam('n', static_cast<float>(slices));
			setParam('R', radius);
			setParam('r', radius);
			setParam('h', length);
			setParam('a', angle);
			setParam('t', 0.0f);
			setParam('w', 1.0f);
		}
	};

}

#endif
