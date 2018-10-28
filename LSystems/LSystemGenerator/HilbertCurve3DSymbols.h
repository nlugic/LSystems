#ifndef HILBERTCURVE3DSYMBOLS_H
#define HILBERTCURVE3DSYMBOLS_H

#include "LSystemSymbol.h"

namespace lsys
{

	class HilbertCurve3DPipeSymbol : public LSystemSymbol
	{
	public:
		HilbertCurve3DPipeSymbol(float width, float length, const glm::vec3& color)
			:LSystemSymbol('F')
		{
			setParam('a', width);
			setParam('h', length);
			setParam('r', color.r);
			setParam('g', color.g);
			setParam('b', color.b);
		}
	};

}

#endif
