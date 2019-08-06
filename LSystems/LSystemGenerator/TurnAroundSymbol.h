#ifndef TURNAROUNDSYMBOL_H
#define TURNAROUNDSYMBOL_H

#include "LSystemSymbol.h"

namespace lsys
{

	class TurnAroundSymbol : public LSystemSymbol
	{
	public:
		TurnAroundSymbol() :LSystemSymbol('|') { }

		virtual LSystemSymbol *clone() const override { return new TurnAroundSymbol(*this); }
	};

}

#endif
