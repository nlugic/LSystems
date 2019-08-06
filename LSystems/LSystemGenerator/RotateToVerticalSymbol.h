#ifndef ROTATETOVERTICALSYMBOL_H
#define ROTATETOVERTICALSYMBOL_H

#include "LSystemSymbol.h"

namespace lsys
{

	class RotateToVerticalSymbol : public LSystemSymbol
	{
	public:
		RotateToVerticalSymbol() :LSystemSymbol('$') { }

		virtual LSystemSymbol *clone() const override { return new RotateToVerticalSymbol(*this); }
	};

}

#endif
