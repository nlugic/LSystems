#ifndef GENERICBRANCHAPEXSYMBOL_H
#define GENERICBRANCHAPEXSYMBOL_H

#include "LSystemSymbol.h"

namespace lsys
{

	class GenericBranchApexSymbol : public LSystemSymbol
	{
	public:
		GenericBranchApexSymbol(int slices, float radius, float height,
				int textureId, float textureWrap = 1.0f)
			:LSystemSymbol('A')
		{
			setParam('n', slices);
			setParam('r', radius);
			setParam('h', height);
			setParam('t', textureId);
			setParam('w', textureWrap);
		}
	};

}

#endif
