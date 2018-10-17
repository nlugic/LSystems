#ifndef GENERIC2DTREEPRODUCTIONS_H
#define GENERIC2DTREEPRODUCTIONS_H

#include "LSystemProduction.h"
#include "SaveStateSymbol.h"
#include "RestoreStateSymbol.h"
#include "TurnLeftSymbol.h"
#include "TurnRightSymbol.h"

namespace lsys
{

	class Generic2DTreeProductionA : public LSystemProduction
	{
	public:
		Generic2DTreeProductionA(float angle)
			:LSystemProduction('F')
		{
			addSymbolToSuccessor(new LSystemSymbol('F'));
			addSymbolToSuccessor(new SaveStateSymbol());
			addSymbolToSuccessor(new TurnLeftSymbol(angle));
			addSymbolToSuccessor(new LSystemSymbol('F'));
			addSymbolToSuccessor(new RestoreStateSymbol());
			addSymbolToSuccessor(new LSystemSymbol('F'));
			addSymbolToSuccessor(new SaveStateSymbol());
			addSymbolToSuccessor(new TurnRightSymbol(angle));
			addSymbolToSuccessor(new LSystemSymbol('F'));
			addSymbolToSuccessor(new RestoreStateSymbol());
			addSymbolToSuccessor(new LSystemSymbol('F'));
		}
	};

	class Generic2DTreeProductionB : public LSystemProduction
	{
	public:
		Generic2DTreeProductionB(float angle)
			:LSystemProduction('F')
		{
			addSymbolToSuccessor(new LSystemSymbol('F'));
			addSymbolToSuccessor(new SaveStateSymbol());
			addSymbolToSuccessor(new TurnLeftSymbol(angle));
			addSymbolToSuccessor(new LSystemSymbol('F'));
			addSymbolToSuccessor(new RestoreStateSymbol());
			addSymbolToSuccessor(new LSystemSymbol('F'));
			addSymbolToSuccessor(new SaveStateSymbol());
			addSymbolToSuccessor(new TurnRightSymbol(angle));
			addSymbolToSuccessor(new LSystemSymbol('F'));
			addSymbolToSuccessor(new RestoreStateSymbol());
			addSymbolToSuccessor(new SaveStateSymbol());
			addSymbolToSuccessor(new LSystemSymbol('F'));
			addSymbolToSuccessor(new RestoreStateSymbol());
		}
	};

	class Generic2DTreeProductionC : public LSystemProduction
	{
	public:
		Generic2DTreeProductionC(float angle)
			:LSystemProduction('F')
		{
			addSymbolToSuccessor(new LSystemSymbol('F'));
			addSymbolToSuccessor(new LSystemSymbol('F'));
			addSymbolToSuccessor(new TurnRightSymbol(angle));
			addSymbolToSuccessor(new SaveStateSymbol());
			addSymbolToSuccessor(new TurnRightSymbol(angle));
			addSymbolToSuccessor(new LSystemSymbol('F'));
			addSymbolToSuccessor(new TurnLeftSymbol(angle));
			addSymbolToSuccessor(new LSystemSymbol('F'));
			addSymbolToSuccessor(new TurnLeftSymbol(angle));
			addSymbolToSuccessor(new LSystemSymbol('F'));
			addSymbolToSuccessor(new RestoreStateSymbol());
			addSymbolToSuccessor(new TurnLeftSymbol(angle));
			addSymbolToSuccessor(new SaveStateSymbol());
			addSymbolToSuccessor(new TurnLeftSymbol(angle));
			addSymbolToSuccessor(new LSystemSymbol('F'));
			addSymbolToSuccessor(new TurnRightSymbol(angle));
			addSymbolToSuccessor(new LSystemSymbol('F'));
			addSymbolToSuccessor(new TurnRightSymbol(angle));
			addSymbolToSuccessor(new LSystemSymbol('F'));
			addSymbolToSuccessor(new RestoreStateSymbol());
		}
	};

	class Generic2DTreeProductionD : public LSystemProduction
	{
	public:
		Generic2DTreeProductionD(float angle)
			:LSystemProduction('X')
		{
			addSymbolToSuccessor(new LSystemSymbol('F'));
			addSymbolToSuccessor(new SaveStateSymbol());
			addSymbolToSuccessor(new TurnLeftSymbol(angle));
			addSymbolToSuccessor(new LSystemSymbol('X'));
			addSymbolToSuccessor(new RestoreStateSymbol());
			addSymbolToSuccessor(new LSystemSymbol('F'));
			addSymbolToSuccessor(new SaveStateSymbol());
			addSymbolToSuccessor(new TurnRightSymbol(angle));
			addSymbolToSuccessor(new LSystemSymbol('X'));
			addSymbolToSuccessor(new RestoreStateSymbol());
			addSymbolToSuccessor(new TurnLeftSymbol(angle));
			addSymbolToSuccessor(new LSystemSymbol('X'));
		}
	};

	class Generic2DTreeProductionE : public LSystemProduction
	{
	public:
		Generic2DTreeProductionE(float angle)
			:LSystemProduction('X')
		{
			addSymbolToSuccessor(new LSystemSymbol('F'));
			addSymbolToSuccessor(new SaveStateSymbol());
			addSymbolToSuccessor(new TurnLeftSymbol(angle));
			addSymbolToSuccessor(new LSystemSymbol('X'));
			addSymbolToSuccessor(new RestoreStateSymbol());
			addSymbolToSuccessor(new SaveStateSymbol());
			addSymbolToSuccessor(new TurnRightSymbol(angle));
			addSymbolToSuccessor(new LSystemSymbol('X'));
			addSymbolToSuccessor(new RestoreStateSymbol());
			addSymbolToSuccessor(new LSystemSymbol('F'));
			addSymbolToSuccessor(new LSystemSymbol('X'));
		}
	};

	class Generic2DTreeProductionF : public LSystemProduction
	{
	public:
		Generic2DTreeProductionF(float angle)
			:LSystemProduction('X')
		{
			addSymbolToSuccessor(new LSystemSymbol('F'));
			addSymbolToSuccessor(new TurnRightSymbol(angle));
			addSymbolToSuccessor(new SaveStateSymbol());
			addSymbolToSuccessor(new SaveStateSymbol());
			addSymbolToSuccessor(new LSystemSymbol('X'));
			addSymbolToSuccessor(new RestoreStateSymbol());
			addSymbolToSuccessor(new TurnLeftSymbol(angle));
			addSymbolToSuccessor(new LSystemSymbol('X'));
			addSymbolToSuccessor(new RestoreStateSymbol());
			addSymbolToSuccessor(new TurnLeftSymbol(angle));
			addSymbolToSuccessor(new LSystemSymbol('F'));
			addSymbolToSuccessor(new SaveStateSymbol());
			addSymbolToSuccessor(new TurnLeftSymbol(angle));
			addSymbolToSuccessor(new LSystemSymbol('F'));
			addSymbolToSuccessor(new LSystemSymbol('X'));
			addSymbolToSuccessor(new RestoreStateSymbol());
			addSymbolToSuccessor(new TurnRightSymbol(angle));
			addSymbolToSuccessor(new LSystemSymbol('X'));
		}
	};

	class Generic2DTreeElongationProduction : public LSystemProduction
	{
	public:
		Generic2DTreeElongationProduction()
			:LSystemProduction('F')
		{
			addSymbolToSuccessor(new LSystemSymbol('F'));
			addSymbolToSuccessor(new LSystemSymbol('F'));
		}
	};

	class Generic2DTreeProductionS1 : public LSystemProduction
	{
	public:
		Generic2DTreeProductionS1(float angle)
			:LSystemProduction('F', 0.34f)
		{
			addSymbolToSuccessor(new LSystemSymbol('F'));
			addSymbolToSuccessor(new SaveStateSymbol());
			addSymbolToSuccessor(new TurnLeftSymbol(angle));
			addSymbolToSuccessor(new LSystemSymbol('F'));
			addSymbolToSuccessor(new RestoreStateSymbol());
			addSymbolToSuccessor(new LSystemSymbol('F'));
			addSymbolToSuccessor(new SaveStateSymbol());
			addSymbolToSuccessor(new TurnRightSymbol(angle));
			addSymbolToSuccessor(new LSystemSymbol('F'));
			addSymbolToSuccessor(new RestoreStateSymbol());
			addSymbolToSuccessor(new LSystemSymbol('F'));
		}
	};

	class Generic2DTreeProductionS2 : public LSystemProduction
	{
	public:
		Generic2DTreeProductionS2(float angle)
			:LSystemProduction('F', 0.33f)
		{
			addSymbolToSuccessor(new LSystemSymbol('F'));
			addSymbolToSuccessor(new SaveStateSymbol());
			addSymbolToSuccessor(new TurnLeftSymbol(angle));
			addSymbolToSuccessor(new LSystemSymbol('F'));
			addSymbolToSuccessor(new RestoreStateSymbol());
			addSymbolToSuccessor(new LSystemSymbol('F'));
		}
	};

	class Generic2DTreeProductionS3 : public LSystemProduction
	{
	public:
		Generic2DTreeProductionS3(float angle)
			:LSystemProduction('F', 0.33f)
		{
			addSymbolToSuccessor(new LSystemSymbol('F'));
			addSymbolToSuccessor(new SaveStateSymbol());
			addSymbolToSuccessor(new TurnRightSymbol(angle));
			addSymbolToSuccessor(new LSystemSymbol('F'));
			addSymbolToSuccessor(new RestoreStateSymbol());
			addSymbolToSuccessor(new LSystemSymbol('F'));
		}
	};

	class Generic2DTreeProductionSD : public LSystemProduction
	{
	public:
		Generic2DTreeProductionSD()
			:LSystemProduction('A') { }

		virtual void generateSuccessor(const LSystemSymbol *pred, const std::map<char, float>& globalParams,
			std::vector<LSystemSymbol *>& word) const override
		{
			float angle = globalParams.at('a');
			LSystemSymbol *branch = new LSystemSymbol('F');
			branch->setParam('s', pred->getParam('s'));

			LSystemSymbol *apex = new LSystemSymbol('A');
			apex->setParam('s', pred->getParam('s') / globalParams.at('R'));

			word.push_back(branch);
			word.push_back(new SaveStateSymbol());
			word.push_back(new TurnLeftSymbol(angle));
			word.push_back(apex);
			word.push_back(new RestoreStateSymbol());
			word.push_back(new SaveStateSymbol());
			word.push_back(new TurnRightSymbol(angle));
			word.push_back(new LSystemSymbol(*apex));
			word.push_back(new RestoreStateSymbol());
		}
	};

}

#endif
