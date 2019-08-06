#ifndef PITCHDOWNSYMBOL_H
#define PITCHDOWNSYMBOL_H

#include "LSystemSymbol.h"

namespace lsys
{

	class PitchDownSymbol : public LSystemSymbol
	{
	public:
		PitchDownSymbol(float pitch) :LSystemSymbol('&') { setParam('p', pitch); }

		virtual LSystemSymbol *clone() const override { return new PitchDownSymbol(*this); }
	};

}

#endif
