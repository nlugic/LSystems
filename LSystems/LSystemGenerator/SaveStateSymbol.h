#ifndef SAVESTATESYMBOL_H
#define SAVESTATESYMBOL_H

#include "LSystemSymbol.h"

namespace lsys
{

	class SaveStateSymbol : public LSystemSymbol
	{
	public:
		SaveStateSymbol() :LSystemSymbol('[') { }
	};

}

#endif
