#ifndef RESTORESTATESYMBOL_H
#define RESTORESTATESYMBOL_H

#include "LSystemSymbol.h"

namespace lsys
{

	class RestoreStateSymbol : public LSystemSymbol
	{
	public:
		inline RestoreStateSymbol()
			:LSystemSymbol(']') { }

		inline virtual LSystemSymbol *clone() const override { return new RestoreStateSymbol(*this); }
	};

}

#endif
