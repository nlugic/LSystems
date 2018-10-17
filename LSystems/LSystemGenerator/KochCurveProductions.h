#ifndef KOCHCURVEPRODUCTIONS_H
#define KOCHCURVEPRODUCTIONS_H

#include "LSystemProduction.h"
#include "TurnLeftSymbol.h"
#include "TurnRightSymbol.h"

namespace lsys
{

	class KochCurveProductionA : public LSystemProduction
	{
	public:
		KochCurveProductionA(float angle)
			:LSystemProduction('F')
		{
			addSymbolToSuccessor(new LSystemSymbol('F'));
			addSymbolToSuccessor(new TurnRightSymbol(angle));
			addSymbolToSuccessor(new LSystemSymbol('F'));
			addSymbolToSuccessor(new TurnLeftSymbol(angle));
			addSymbolToSuccessor(new LSystemSymbol('F'));
			addSymbolToSuccessor(new TurnLeftSymbol(angle));
			addSymbolToSuccessor(new LSystemSymbol('F'));
			addSymbolToSuccessor(new LSystemSymbol('F'));
			addSymbolToSuccessor(new TurnRightSymbol(angle));
			addSymbolToSuccessor(new LSystemSymbol('F'));
			addSymbolToSuccessor(new TurnRightSymbol(angle));
			addSymbolToSuccessor(new LSystemSymbol('F'));
			addSymbolToSuccessor(new TurnLeftSymbol(angle));
			addSymbolToSuccessor(new LSystemSymbol('F'));
		}
	};

	class KochCurveProductionB : public LSystemProduction
	{
	public:
		KochCurveProductionB(float angle)
			:LSystemProduction('F')
		{
			addSymbolToSuccessor(new LSystemSymbol('F'));
			addSymbolToSuccessor(new LSystemSymbol('F'));
			addSymbolToSuccessor(new TurnRightSymbol(angle));
			addSymbolToSuccessor(new LSystemSymbol('F'));
			addSymbolToSuccessor(new TurnRightSymbol(angle));
			addSymbolToSuccessor(new LSystemSymbol('F'));
			addSymbolToSuccessor(new TurnRightSymbol(angle));
			addSymbolToSuccessor(new LSystemSymbol('F'));
			addSymbolToSuccessor(new TurnRightSymbol(angle));
			addSymbolToSuccessor(new LSystemSymbol('F'));
			addSymbolToSuccessor(new TurnRightSymbol(angle));
			addSymbolToSuccessor(new LSystemSymbol('F'));
			addSymbolToSuccessor(new TurnLeftSymbol(angle));
			addSymbolToSuccessor(new LSystemSymbol('F'));
		}
	};

	class KochCurveProductionC : public LSystemProduction
	{
	public:
		KochCurveProductionC(float angle)
			:LSystemProduction('F')
		{
			addSymbolToSuccessor(new LSystemSymbol('F'));
			addSymbolToSuccessor(new LSystemSymbol('F'));
			addSymbolToSuccessor(new TurnRightSymbol(angle));
			addSymbolToSuccessor(new LSystemSymbol('F'));
			addSymbolToSuccessor(new TurnRightSymbol(angle));
			addSymbolToSuccessor(new LSystemSymbol('F'));
			addSymbolToSuccessor(new TurnRightSymbol(angle));
			addSymbolToSuccessor(new LSystemSymbol('F'));
			addSymbolToSuccessor(new TurnRightSymbol(angle));
			addSymbolToSuccessor(new LSystemSymbol('F'));
			addSymbolToSuccessor(new LSystemSymbol('F'));
		}
	};

	class KochCurveProductionD : public LSystemProduction
	{
	public:
		KochCurveProductionD(float angle)
			:LSystemProduction('F')
		{
			addSymbolToSuccessor(new LSystemSymbol('F'));
			addSymbolToSuccessor(new LSystemSymbol('F'));
			addSymbolToSuccessor(new TurnRightSymbol(angle));
			addSymbolToSuccessor(new LSystemSymbol('F'));
			addSymbolToSuccessor(new TurnLeftSymbol(angle));
			addSymbolToSuccessor(new LSystemSymbol('F'));
			addSymbolToSuccessor(new TurnRightSymbol(angle));
			addSymbolToSuccessor(new LSystemSymbol('F'));
			addSymbolToSuccessor(new TurnRightSymbol(angle));
			addSymbolToSuccessor(new LSystemSymbol('F'));
			addSymbolToSuccessor(new LSystemSymbol('F'));
		}
	};

	class KochCurveProductionE : public LSystemProduction
	{
	public:
		KochCurveProductionE(float angle)
			:LSystemProduction('F')
		{
			addSymbolToSuccessor(new LSystemSymbol('F'));
			addSymbolToSuccessor(new LSystemSymbol('F'));
			addSymbolToSuccessor(new TurnRightSymbol(angle));
			addSymbolToSuccessor(new LSystemSymbol('F'));
			addSymbolToSuccessor(new TurnRightSymbol(angle));
			addSymbolToSuccessor(new TurnRightSymbol(angle));
			addSymbolToSuccessor(new LSystemSymbol('F'));
			addSymbolToSuccessor(new TurnRightSymbol(angle));
			addSymbolToSuccessor(new LSystemSymbol('F'));
		}
	};

	class KochCurveProductionF : public LSystemProduction
	{
	public:
		KochCurveProductionF(float angle)
			:LSystemProduction('F')
		{
			addSymbolToSuccessor(new LSystemSymbol('F'));
			addSymbolToSuccessor(new TurnRightSymbol(angle));
			addSymbolToSuccessor(new LSystemSymbol('F'));
			addSymbolToSuccessor(new LSystemSymbol('F'));
			addSymbolToSuccessor(new TurnRightSymbol(angle));
			addSymbolToSuccessor(new TurnRightSymbol(angle));
			addSymbolToSuccessor(new LSystemSymbol('F'));
			addSymbolToSuccessor(new TurnRightSymbol(angle));
			addSymbolToSuccessor(new LSystemSymbol('F'));
		}
	};

	class KochCurveProductionG : public LSystemProduction
	{
	public:
		KochCurveProductionG(float angle)
			:LSystemProduction('F')
		{
			addSymbolToSuccessor(new LSystemSymbol('F'));
			addSymbolToSuccessor(new TurnRightSymbol(angle));
			addSymbolToSuccessor(new LSystemSymbol('F'));
			addSymbolToSuccessor(new TurnLeftSymbol(angle));
			addSymbolToSuccessor(new LSystemSymbol('F'));
			addSymbolToSuccessor(new TurnRightSymbol(angle));
			addSymbolToSuccessor(new LSystemSymbol('F'));
			addSymbolToSuccessor(new TurnRightSymbol(angle));
			addSymbolToSuccessor(new LSystemSymbol('F'));
		}
	};

}

#endif
