#ifndef SIERPINSKIGASKETPRODUCTIONS_H
#define SIERPINSKIGASKETPRODUCTIONS_H

#include "LSystemProduction.h"
#include "TurnLeftSymbol.h"
#include "TurnRightSymbol.h"

namespace lsys
{

	class SierpinskiGasketProductionL : public LSystemProduction
	{
	public:
		SierpinskiGasketProductionL(float angle)
			:LSystemProduction('L')
		{
			addSymbolToSuccessor(new LSystemSymbol('R'));
			addSymbolToSuccessor(new TurnLeftSymbol(angle));
			addSymbolToSuccessor(new LSystemSymbol('L'));
			addSymbolToSuccessor(new TurnLeftSymbol(angle));
			addSymbolToSuccessor(new LSystemSymbol('R'));
		}
	};

	class SierpinskiGasketProductionR : public LSystemProduction
	{
	public:
		SierpinskiGasketProductionR(float angle)
			:LSystemProduction('R')
		{
			addSymbolToSuccessor(new LSystemSymbol('L'));
			addSymbolToSuccessor(new TurnRightSymbol(angle));
			addSymbolToSuccessor(new LSystemSymbol('R'));
			addSymbolToSuccessor(new TurnRightSymbol(angle));
			addSymbolToSuccessor(new LSystemSymbol('L'));
		}
	};

}

#endif
