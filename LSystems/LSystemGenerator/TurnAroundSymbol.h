#ifndef TURNAROUNDSYMBOL_H
#define TURNAROUNDSYMBOL_H

#include "LSystemSymbol.h"

namespace lsys
{

	class TurnAroundSymbol : public LSystemSymbol
	{
	public:
		TurnAroundSymbol() :LSystemSymbol('|') { }
	};

}

#endif
