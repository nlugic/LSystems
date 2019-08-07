#ifndef SAVESTATESYMBOL_H
#define SAVESTATESYMBOL_H

#include "LSystemSymbol.h"

namespace lsys
{

	class SaveStateSymbol : public LSystemSymbol
	{
	public:
		inline SaveStateSymbol()
			:LSystemSymbol('[') { }

		inline virtual LSystemSymbol *clone() const override { return new SaveStateSymbol(*this); }
	};

}

#endif
