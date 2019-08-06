#ifndef TURNLEFTSYMBOL_H
#define TURNLEFTSYMBOL_H

#include "LSystemSymbol.h"

namespace lsys
{

	class TurnLeftSymbol : public LSystemSymbol
	{
	public:
		TurnLeftSymbol(float yaw) :LSystemSymbol('+') { setParam('y', yaw); }

		virtual LSystemSymbol *clone() const override { return new TurnLeftSymbol(*this); }
	};

}

#endif
