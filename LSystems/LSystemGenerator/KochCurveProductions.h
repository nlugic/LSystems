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
		explicit KochSnowflakeProduction(float angle)
			:LSystemProduction('F')
		{
			addSymbolToSuccessor(new GenericLineSymbol('F', NAN));
			addSymbolToSuccessor(new TurnLeftSymbol(angle));
			addSymbolToSuccessor(new GenericLineSymbol('F', NAN));
			addSymbolToSuccessor(new TurnRightSymbol(angle));
			addSymbolToSuccessor(new TurnRightSymbol(angle));
			addSymbolToSuccessor(new GenericLineSymbol('F', NAN));
			addSymbolToSuccessor(new TurnLeftSymbol(angle));
			addSymbolToSuccessor(new GenericLineSymbol('F', NAN));
		}

		virtual void generateSuccessor(const LSystemSymbol *pred, const std::map<char, float>& global_params,
			std::vector<LSystemSymbol *>& word) const override
		{
			float length = pred->getParam('h') / global_params.at('s');
			float angle = global_params.at('a');

			word.push_back(new GenericLineSymbol('F', length));
			word.push_back(new TurnLeftSymbol(angle));
			word.push_back(new GenericLineSymbol('F', length));
			word.push_back(new TurnRightSymbol(angle));
			word.push_back(new TurnRightSymbol(angle));
			word.push_back(new GenericLineSymbol('F', length));
			word.push_back(new TurnLeftSymbol(angle));
			word.push_back(new GenericLineSymbol('F', length));
		}

		inline virtual LSystemProduction *clone() const override { return new KochSnowflakeProduction(*this); }
	};

	class KochIslandProductionA : public LSystemProduction
	{
	public:
		explicit KochIslandProductionA(float angle)
			:LSystemProduction('F')
		{
			addSymbolToSuccessor(new GenericLineSymbol('F', NAN));
			addSymbolToSuccessor(new TurnRightSymbol(angle));
			addSymbolToSuccessor(new GenericLineSymbol('F', NAN));
			addSymbolToSuccessor(new TurnLeftSymbol(angle));
			addSymbolToSuccessor(new GenericLineSymbol('F', NAN));
			addSymbolToSuccessor(new TurnLeftSymbol(angle));
			addSymbolToSuccessor(new GenericLineSymbol('F', NAN));
			addSymbolToSuccessor(new GenericLineSymbol('F', NAN));
			addSymbolToSuccessor(new TurnRightSymbol(angle));
			addSymbolToSuccessor(new GenericLineSymbol('F', NAN));
			addSymbolToSuccessor(new TurnRightSymbol(angle));
			addSymbolToSuccessor(new GenericLineSymbol('F', NAN));
			addSymbolToSuccessor(new TurnLeftSymbol(angle));
			addSymbolToSuccessor(new GenericLineSymbol('F', NAN));
		}
		
		virtual void generateSuccessor(const LSystemSymbol *pred, const std::map<char, float>& global_params,
			std::vector<LSystemSymbol *>& word) const override
		{
			float length = pred->getParam('h') / global_params.at('s');
			float angle = global_params.at('a');

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

		inline virtual LSystemProduction *clone() const override { return new KochIslandProductionA(*this); }
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

		inline virtual LSystemProduction *clone() const override { return new KochIslandProductionB(*this); }
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

		inline virtual LSystemProduction *clone() const override { return new KochIslandProductionC(*this); }
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

		inline virtual LSystemProduction *clone() const override { return new KochIslandProductionD(*this); }
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

		inline virtual LSystemProduction *clone() const override { return new KochIslandProductionE(*this); }
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

		inline virtual LSystemProduction *clone() const override { return new KochIslandProductionF(*this); }
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

		inline virtual LSystemProduction *clone() const override { return new KochIslandProductionG(*this); }
	};

}

#endif
