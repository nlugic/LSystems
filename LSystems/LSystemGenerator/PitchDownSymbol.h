#ifndef PITCHDOWNSYMBOL_H
#define PITCHDOWNSYMBOL_H

#include "LSystemSymbol.h"

namespace lsys
{

	class PitchDownSymbol : public LSystemSymbol
	{
	public:
		inline PitchDownSymbol(float pitch)
			:LSystemSymbol('&') { setParam('p', pitch); }

		inline virtual LSystemSymbol *clone() const override { return new PitchDownSymbol(*this); }
	};

}

#endif
