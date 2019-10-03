#ifndef TURNRIGHTSYMBOL_H
#define TURNRIGHTSYMBOL_H

#include "LSystemSymbol.h"

namespace lsys
{

	class TurnRightSymbol : public LSystemSymbol
	{
	public:
		explicit inline TurnRightSymbol(float yaw)
			:LSystemSymbol('-') { setParam('y', yaw); }

		inline virtual LSystemSymbol *clone() const override { return new TurnRightSymbol(*this); }
	};

}

#endif
