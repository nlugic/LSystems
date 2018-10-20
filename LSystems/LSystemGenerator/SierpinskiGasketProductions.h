#ifndef SIERPINSKIGASKETPRODUCTIONS_H
#define SIERPINSKIGASKETPRODUCTIONS_H

#include "LSystemProduction.h"
#include "GenericLineSymbol.h"
#include "TurnLeftSymbol.h"
#include "TurnRightSymbol.h"

namespace lsys
{

	class SierpinskiGasketProductionL : public LSystemProduction
	{
	public:
		SierpinskiGasketProductionL()
			:LSystemProduction('L') { }

		virtual void generateSuccessor(const LSystemSymbol *pred, const std::map<char, float>& globalParams,
			std::vector<LSystemSymbol *>& word) const override
		{
			float length = pred->getParam('h');
			float angle = globalParams.at('a');

			word.push_back(new GenericLineSymbol('R', length));
			word.push_back(new TurnLeftSymbol(angle));
			word.push_back(new GenericLineSymbol('L', length));
			word.push_back(new TurnLeftSymbol(angle));
			word.push_back(new GenericLineSymbol('R', length));
		}
	};

	class SierpinskiGasketProductionR : public LSystemProduction
	{
	public:
		SierpinskiGasketProductionR()
			:LSystemProduction('R') { }

		virtual void generateSuccessor(const LSystemSymbol *pred, const std::map<char, float>& globalParams,
			std::vector<LSystemSymbol *>& word) const override
		{
			float length = pred->getParam('h');
			float angle = globalParams.at('a');

			word.push_back(new GenericLineSymbol('L', length));
			word.push_back(new TurnRightSymbol(angle));
			word.push_back(new GenericLineSymbol('R', length));
			word.push_back(new TurnRightSymbol(angle));
			word.push_back(new GenericLineSymbol('L', length));
		}
	};

}

#endif
