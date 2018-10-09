#ifndef ROLLLEFTSYMBOL_H
#define ROLLLEFTSYMBOL_H

#include "LSystemSymbol.h"

namespace lsys
{

	class RollLeftSymbol : public LSystemSymbol
	{
	public:
		RollLeftSymbol(float roll) :LSystemSymbol('\\') { setParam('r', roll); }
	};

}

#endif
