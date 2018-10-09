#ifndef TURNRIGHTSYMBOL_H
#define TURNRIGHTSYMBOL_H

#include "LSystemSymbol.h"

namespace lsys
{

	class TurnRightSymbol : public LSystemSymbol
	{
	public:
		TurnRightSymbol(float yaw) :LSystemSymbol('-') { setParam('y', yaw); }
	};

}

#endif
