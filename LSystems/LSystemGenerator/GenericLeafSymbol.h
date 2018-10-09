#ifndef GENERICLEAFSYMBOL_H
#define GENERICLEAFSYMBOL_H

#include "LSystemSymbol.h"

namespace lsys
{

	class GenericLeafSymbol : public LSystemSymbol
	{
	public:
		GenericLeafSymbol(float length, float width, float petiole,
				float firstCurve, float secondCurve, int textureId)
			:LSystemSymbol('L')
		{
			setParam('l', length);
			setParam('w', width);
			setParam('p', petiole);
			setParam('c', firstCurve * length);
			setParam('C', secondCurve * length);
			setParam('t', textureId);
		}
	};

}

#endif
