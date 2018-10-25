#ifndef KOCHCURVEPRODUCTIONS_H
#define KOCHCURVEPRODUCTIONS_H

#include "LSystemProduction.h"
#include "TurnLeftSymbol.h"
#include "TurnRightSymbol.h"
#include "GenericLineSymbol.h"

namespace lsys
{

	class KochSnowflakeProduction : public LSystemProduction
	{
	public:
		KochSnowflakeProduction()
			:LSystemProduction('F') { }

		virtual void generateSuccessor(const LSystemSymbol *pred, const std::map<char, float>& globalParams,
			std::vector<LSystemSymbol *>& word) const override
		{
			float length = pred->getParam('h') / globalParams.at('s');
			float angle = globalParams.at('a');

			word.push_back(new GenericLineSymbol('F', length));
			word.push_back(new TurnLeftSymbol(angle));
			word.push_back(new GenericLineSymbol('F', length));
			word.push_back(new TurnRightSymbol(angle));
			word.push_back(new TurnRightSymbol(angle));
			word.push_back(new GenericLineSymbol('F', length));
			word.push_back(new TurnLeftSymbol(angle));
			word.push_back(new GenericLineSymbol('F', length));
		}
	};

	class KochIslandProductionA : public LSystemProduction
	{
	public:
		KochIslandProductionA()
			:LSystemProduction('F') { }
		
		virtual void generateSuccessor(const LSystemSymbol *pred, const std::map<char, float>& globalParams,
			std::vector<LSystemSymbol *>& word) const override
		{
			float length = pred->getParam('h') / globalParams.at('s');
			float angle = globalParams.at('a');

			word.push_back(new GenericLineSymbol('F', length));
			word.push_back(new TurnRightSymbol(angle));
			word.push_back(new GenericLineSymbol('F', length));
			word.push_back(new TurnLeftSymbol(angle));
			word.push_back(new GenericLineSymbol('F', length));
			word.push_back(new TurnLeftSymbol(angle));
			word.push_back(new GenericLineSymbol('F', length));
			word.push_back(new GenericLineSymbol('F', length));
			word.push_back(new TurnRightSymbol(angle));
			word.push_back(new GenericLineSymbol('F', length));
			word.push_back(new TurnRightSymbol(angle));
			word.push_back(new GenericLineSymbol('F', length));
			word.push_back(new TurnLeftSymbol(angle));
			word.push_back(new GenericLineSymbol('F', length));
		}
	};

	class KochIslandProductionB : public LSystemProduction
	{
	public:
		KochIslandProductionB(float length, float angle)
			:LSystemProduction('F')
		{
			addSymbolToSuccessor(new GenericLineSymbol('F', length));
			addSymbolToSuccessor(new GenericLineSymbol('F', length));
			addSymbolToSuccessor(new TurnRightSymbol(angle));
			addSymbolToSuccessor(new GenericLineSymbol('F', length));
			addSymbolToSuccessor(new TurnRightSymbol(angle));
			addSymbolToSuccessor(new GenericLineSymbol('F', length));
			addSymbolToSuccessor(new TurnRightSymbol(angle));
			addSymbolToSuccessor(new GenericLineSymbol('F', length));
			addSymbolToSuccessor(new TurnRightSymbol(angle));
			addSymbolToSuccessor(new GenericLineSymbol('F', length));
			addSymbolToSuccessor(new TurnRightSymbol(angle));
			addSymbolToSuccessor(new GenericLineSymbol('F', length));
			addSymbolToSuccessor(new TurnLeftSymbol(angle));
			addSymbolToSuccessor(new GenericLineSymbol('F', length));
		}
	};

	class KochIslandProductionC : public LSystemProduction
	{
	public:
		KochIslandProductionC(float length, float angle)
			:LSystemProduction('F')
		{
			addSymbolToSuccessor(new GenericLineSymbol('F', length));
			addSymbolToSuccessor(new GenericLineSymbol('F', length));
			addSymbolToSuccessor(new TurnRightSymbol(angle));
			addSymbolToSuccessor(new GenericLineSymbol('F', length));
			addSymbolToSuccessor(new TurnRightSymbol(angle));
			addSymbolToSuccessor(new GenericLineSymbol('F', length));
			addSymbolToSuccessor(new TurnRightSymbol(angle));
			addSymbolToSuccessor(new GenericLineSymbol('F', length));
			addSymbolToSuccessor(new TurnRightSymbol(angle));
			addSymbolToSuccessor(new GenericLineSymbol('F', length));
			addSymbolToSuccessor(new GenericLineSymbol('F', length));
		}
	};

	class KochIslandProductionD : public LSystemProduction
	{
	public:
		KochIslandProductionD(float length, float angle)
			:LSystemProduction('F')
		{
			addSymbolToSuccessor(new GenericLineSymbol('F', length));
			addSymbolToSuccessor(new GenericLineSymbol('F', length));
			addSymbolToSuccessor(new TurnRightSymbol(angle));
			addSymbolToSuccessor(new GenericLineSymbol('F', length));
			addSymbolToSuccessor(new TurnLeftSymbol(angle));
			addSymbolToSuccessor(new GenericLineSymbol('F', length));
			addSymbolToSuccessor(new TurnRightSymbol(angle));
			addSymbolToSuccessor(new GenericLineSymbol('F', length));
			addSymbolToSuccessor(new TurnRightSymbol(angle));
			addSymbolToSuccessor(new GenericLineSymbol('F', length));
			addSymbolToSuccessor(new GenericLineSymbol('F', length));
		}
	};

	class KochIslandProductionE : public LSystemProduction
	{
	public:
		KochIslandProductionE(float length, float angle)
			:LSystemProduction('F')
		{
			addSymbolToSuccessor(new GenericLineSymbol('F', length));
			addSymbolToSuccessor(new GenericLineSymbol('F', length));
			addSymbolToSuccessor(new TurnRightSymbol(angle));
			addSymbolToSuccessor(new GenericLineSymbol('F', length));
			addSymbolToSuccessor(new TurnRightSymbol(angle));
			addSymbolToSuccessor(new TurnRightSymbol(angle));
			addSymbolToSuccessor(new GenericLineSymbol('F', length));
			addSymbolToSuccessor(new TurnRightSymbol(angle));
			addSymbolToSuccessor(new GenericLineSymbol('F', length));
		}
	};

	class KochIslandProductionF : public LSystemProduction
	{
	public:
		KochIslandProductionF(float length, float angle)
			:LSystemProduction('F')
		{
			addSymbolToSuccessor(new GenericLineSymbol('F', length));
			addSymbolToSuccessor(new TurnRightSymbol(angle));
			addSymbolToSuccessor(new GenericLineSymbol('F', length));
			addSymbolToSuccessor(new GenericLineSymbol('F', length));
			addSymbolToSuccessor(new TurnRightSymbol(angle));
			addSymbolToSuccessor(new TurnRightSymbol(angle));
			addSymbolToSuccessor(new GenericLineSymbol('F', length));
			addSymbolToSuccessor(new TurnRightSymbol(angle));
			addSymbolToSuccessor(new GenericLineSymbol('F', length));
		}
	};

	class KochIslandProductionG : public LSystemProduction
	{
	public:
		KochIslandProductionG(float length, float angle)
			:LSystemProduction('F')
		{
			addSymbolToSuccessor(new GenericLineSymbol('F', length));
			addSymbolToSuccessor(new TurnRightSymbol(angle));
			addSymbolToSuccessor(new GenericLineSymbol('F', length));
			addSymbolToSuccessor(new TurnLeftSymbol(angle));
			addSymbolToSuccessor(new GenericLineSymbol('F', length));
			addSymbolToSuccessor(new TurnRightSymbol(angle));
			addSymbolToSuccessor(new GenericLineSymbol('F', length));
			addSymbolToSuccessor(new TurnRightSymbol(angle));
			addSymbolToSuccessor(new GenericLineSymbol('F', length));
		}
	};

}

#endif
