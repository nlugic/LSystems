#ifndef PITCHDOWNSYMBOL_H
#define PITCHDOWNSYMBOL_H

#include "LSystemSymbol.h"

namespace lsys
{

	class PitchDownSymbol : public LSystemSymbol
	{
	public:
		PitchDownSymbol(float pitch) :LSystemSymbol('&') { setParam('p', pitch); }
	};

}

#endif
