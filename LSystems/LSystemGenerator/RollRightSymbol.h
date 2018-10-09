#ifndef ROLLRIGHTSYMBOL_H
#define ROLLRIGHTSYMBOL_H

#include "LSystemSymbol.h"

namespace lsys
{

	class RollRightSymbol : public LSystemSymbol
	{
	public:
		RollRightSymbol(float roll) :LSystemSymbol('/') { setParam('r', roll); }
	};

}

#endif
