#ifndef SIERPINSKIGASKETPRODUCTIONS_H
#define SIERPINSKIGASKETPRODUCTIONS_H

#include "LSystemProduction.h"
#include "TurnLeftSymbol.h"
#include "TurnRightSymbol.h"
#include "GenericLineSymbol.h"

namespace lsys
{

	class SierpinskiGasketProductionL : public LSystemProduction
	{
	public:
		SierpinskiGasketProductionL(float length, float angle)
			:LSystemProduction('L')
		{
			addSymbolToSuccessor(new GenericLineSymbol('R', length));
			addSymbolToSuccessor(new TurnLeftSymbol(angle));
			addSymbolToSuccessor(new GenericLineSymbol('L', length));
			addSymbolToSuccessor(new TurnLeftSymbol(angle));
			addSymbolToSuccessor(new GenericLineSymbol('R', length));
		}

		inline virtual LSystemProduction *clone() const override { return new SierpinskiGasketProductionL(*this); }
	};

	class SierpinskiGasketProductionR : public LSystemProduction
	{
	public:
		SierpinskiGasketProductionR(float length, float angle)
			:LSystemProduction('R')
		{
			addSymbolToSuccessor(new GenericLineSymbol('L', length));
			addSymbolToSuccessor(new TurnRightSymbol(angle));
			addSymbolToSuccessor(new GenericLineSymbol('R', length));
			addSymbolToSuccessor(new TurnRightSymbol(angle));
			addSymbolToSuccessor(new GenericLineSymbol('L', length));
		}

		inline virtual LSystemProduction *clone() const override { return new SierpinskiGasketProductionR(*this); }
	};

}

#endif
