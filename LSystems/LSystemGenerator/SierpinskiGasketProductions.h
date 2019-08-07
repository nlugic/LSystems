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
		inline SierpinskiGasketProductionL()
			:LSystemProduction('L') { }

		virtual void generateSuccessor(const LSystemSymbol *pred, const std::map<char, float>& global_params,
			std::vector<LSystemSymbol *>& word) const override
		{
			float length = pred->getParam('h');
			float angle = global_params.at('a');

			word.push_back(new GenericLineSymbol('R', length));
			word.push_back(new TurnLeftSymbol(angle));
			word.push_back(new GenericLineSymbol('L', length));
			word.push_back(new TurnLeftSymbol(angle));
			word.push_back(new GenericLineSymbol('R', length));
		}

		inline virtual LSystemProduction *clone() const override { return new SierpinskiGasketProductionL(*this); }
	};

	class SierpinskiGasketProductionR : public LSystemProduction
	{
	public:
		inline SierpinskiGasketProductionR()
			:LSystemProduction('R') { }

		virtual void generateSuccessor(const LSystemSymbol *pred, const std::map<char, float>& global_params,
			std::vector<LSystemSymbol *>& word) const override
		{
			float length = pred->getParam('h');
			float angle = global_params.at('a');

			word.push_back(new GenericLineSymbol('L', length));
			word.push_back(new TurnRightSymbol(angle));
			word.push_back(new GenericLineSymbol('R', length));
			word.push_back(new TurnRightSymbol(angle));
			word.push_back(new GenericLineSymbol('L', length));
		}

		inline virtual LSystemProduction *clone() const override { return new SierpinskiGasketProductionR(*this); }
	};

}

#endif
