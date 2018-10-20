#ifndef DRAGONCURVEPRODUCTIONS_H
#define DRAGONCURVEPRODUCTIONS_H

#include "LSystemProduction.h"
#include "GenericLineSymbol.h"
#include "TurnLeftSymbol.h"
#include "TurnRightSymbol.h"

namespace lsys
{

	class DragonCurveProductionL : public LSystemProduction
	{
	public:
		DragonCurveProductionL(float length, float angle)
			:LSystemProduction('L')
		{
			addSymbolToSuccessor(new GenericLineSymbol('L', length));
			addSymbolToSuccessor(new TurnLeftSymbol(angle));
			addSymbolToSuccessor(new GenericLineSymbol('R', length));
			addSymbolToSuccessor(new TurnLeftSymbol(angle));
		}
	};

	class DragonCurveProductionR : public LSystemProduction
	{
	public:
		DragonCurveProductionR(float length, float angle)
			:LSystemProduction('R')
		{
			addSymbolToSuccessor(new TurnRightSymbol(angle));
			addSymbolToSuccessor(new GenericLineSymbol('L', length));
			addSymbolToSuccessor(new TurnRightSymbol(angle));
			addSymbolToSuccessor(new GenericLineSymbol('R', length));
		}
	};

}

#endif
