#ifndef PITCHUPSYMBOL_H
#define PITCHUPSYMBOL_H

#include "LSystemSymbol.h"

namespace lsys
{

	class PitchUpSymbol : public LSystemSymbol
	{
	public:
		PitchUpSymbol(float pitch) :LSystemSymbol('^') { setParam('p', pitch); }

		virtual LSystemSymbol *clone() const override { return new PitchUpSymbol(*this); }
	};

}

#endif
