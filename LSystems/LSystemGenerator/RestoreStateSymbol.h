#ifndef RESTORESTATESYMBOL_H
#define RESTORESTATESYMBOL_H

#include "LSystemSymbol.h"

namespace lsys
{

	class RestoreStateSymbol : public LSystemSymbol
	{
	public:
		RestoreStateSymbol() :LSystemSymbol(']') { }
	};

}

#endif
