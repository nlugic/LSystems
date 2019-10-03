#ifndef ROLLRIGHTSYMBOL_H
#define ROLLRIGHTSYMBOL_H

#include "LSystemSymbol.h"

namespace lsys
{

	class RollRightSymbol : public LSystemSymbol
	{
	public:
		explicit inline RollRightSymbol(float roll)
			:LSystemSymbol('/') { setParam('r', roll); }

		inline virtual LSystemSymbol *clone() const override { return new RollRightSymbol(*this); }
	};

}

#endif
