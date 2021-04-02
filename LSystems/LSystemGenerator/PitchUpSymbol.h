#ifndef PITCHUPSYMBOL_H
#define PITCHUPSYMBOL_H

#include "LSystemSymbol.h"

namespace lsys
{

	class PitchUpSymbol : public LSystemSymbol
	{
	public:
		explicit inline PitchUpSymbol(float pitch)
			:LSystemSymbol('^') { setParam('p', pitch); }

		inline virtual LSystemSymbol *clone() const override { return new PitchUpSymbol(*this); }
	};

}

#endif
