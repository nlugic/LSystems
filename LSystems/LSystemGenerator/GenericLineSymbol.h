#ifndef GENERICLINESYMBOL_H
#define GENERICLINESYMBOL_H

#include "LSystemSymbol.h"

namespace lsys
{

	class GenericLineSymbol : public LSystemSymbol
	{
	public:
		GenericLineSymbol(char axiom, float length, float width_factor = 0.1f)
			:LSystemSymbol(axiom)
		{
			setParam('h', length);
			setParam('w', width_factor * length);
		}

		virtual LSystemSymbol *clone() const override { return new GenericLineSymbol(*this); }
	};

}

#endif
