#ifndef GENERICLINESYMBOL_H
#define GENERICLINESYMBOL_H

#include "LSystemSymbol.h"

namespace lsys
{

	class GenericLineSymbol : public LSystemSymbol
	{
	public:
		GenericLineSymbol(char axiom, float length, float widthFactor = 0.1f)
			:LSystemSymbol(axiom)
		{
			setParam('h', length);
			setParam('w', widthFactor * length);
		}
	};

}

#endif
