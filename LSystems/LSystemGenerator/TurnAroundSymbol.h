#ifndef TURNAROUNDSYMBOL_H
#define TURNAROUNDSYMBOL_H

#include "LSystemSymbol.h"

namespace lsys
{

	class TurnAroundSymbol : public LSystemSymbol
	{
	public:
		inline TurnAroundSymbol()
			:LSystemSymbol('|') { }

		inline virtual LSystemSymbol *clone() const override { return new TurnAroundSymbol(*this); }
	};

}

#endif
