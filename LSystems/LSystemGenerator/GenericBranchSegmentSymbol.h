#ifndef GENERICBRANCHSEGMENTSYMBOL_H
#define GENERICBRANCHSEGMENTSYMBOL_H

#include "LSystemSymbol.h"

namespace lsys
{

	class GenericBranchSegmentSymbol : public LSystemSymbol
	{
	public:
		GenericBranchSegmentSymbol(int slices, float radiusStart, float radiusEnd,
				float height, int textureId, float textureWrap = 1.0f)
			:LSystemSymbol('F')
		{
			setParam('n', slices);
			setParam('R', radiusStart);
			setParam('r', radiusEnd);
			setParam('h', height);
			setParam('t', textureId);
			setParam('w', textureWrap);
		}
	};

}

#endif
