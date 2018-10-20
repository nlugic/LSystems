#ifndef GENERIC2DTREEPRODUCTIONS_H
#define GENERIC2DTREEPRODUCTIONS_H

#include "LSystemProduction.h"
#include "GenericLineSymbol.h"
#include "SaveStateSymbol.h"
#include "RestoreStateSymbol.h"
#include "TurnLeftSymbol.h"
#include "TurnRightSymbol.h"

namespace lsys
{

	class Generic2DTreeProductionA : public LSystemProduction
	{
	public:
		Generic2DTreeProductionA(float length, float angle)
			:LSystemProduction('F')
		{
			addSymbolToSuccessor(new GenericLineSymbol('F', length));
			addSymbolToSuccessor(new SaveStateSymbol());
			addSymbolToSuccessor(new TurnLeftSymbol(angle));
			addSymbolToSuccessor(new GenericLineSymbol('F', length));
			addSymbolToSuccessor(new RestoreStateSymbol());
			addSymbolToSuccessor(new GenericLineSymbol('F', length));
			addSymbolToSuccessor(new SaveStateSymbol());
			addSymbolToSuccessor(new TurnRightSymbol(angle));
			addSymbolToSuccessor(new GenericLineSymbol('F', length));
			addSymbolToSuccessor(new RestoreStateSymbol());
			addSymbolToSuccessor(new GenericLineSymbol('F', length));
		}
	};

	class Generic2DTreeProductionB : public LSystemProduction
	{
	public:
		Generic2DTreeProductionB(float length, float angle)
			:LSystemProduction('F')
		{
			addSymbolToSuccessor(new GenericLineSymbol('F', length));
			addSymbolToSuccessor(new SaveStateSymbol());
			addSymbolToSuccessor(new TurnLeftSymbol(angle));
			addSymbolToSuccessor(new GenericLineSymbol('F', length));
			addSymbolToSuccessor(new RestoreStateSymbol());
			addSymbolToSuccessor(new GenericLineSymbol('F', length));
			addSymbolToSuccessor(new SaveStateSymbol());
			addSymbolToSuccessor(new TurnRightSymbol(angle));
			addSymbolToSuccessor(new GenericLineSymbol('F', length));
			addSymbolToSuccessor(new RestoreStateSymbol());
			addSymbolToSuccessor(new SaveStateSymbol());
			addSymbolToSuccessor(new GenericLineSymbol('F', length));
			addSymbolToSuccessor(new RestoreStateSymbol());
		}
	};

	class Generic2DTreeProductionC : public LSystemProduction
	{
	public:
		Generic2DTreeProductionC(float length, float angle)
			:LSystemProduction('F')
		{
			addSymbolToSuccessor(new GenericLineSymbol('F', length));
			addSymbolToSuccessor(new GenericLineSymbol('F', length));
			addSymbolToSuccessor(new TurnRightSymbol(angle));
			addSymbolToSuccessor(new SaveStateSymbol());
			addSymbolToSuccessor(new TurnRightSymbol(angle));
			addSymbolToSuccessor(new GenericLineSymbol('F', length));
			addSymbolToSuccessor(new TurnLeftSymbol(angle));
			addSymbolToSuccessor(new GenericLineSymbol('F', length));
			addSymbolToSuccessor(new TurnLeftSymbol(angle));
			addSymbolToSuccessor(new GenericLineSymbol('F', length));
			addSymbolToSuccessor(new RestoreStateSymbol());
			addSymbolToSuccessor(new TurnLeftSymbol(angle));
			addSymbolToSuccessor(new SaveStateSymbol());
			addSymbolToSuccessor(new TurnLeftSymbol(angle));
			addSymbolToSuccessor(new GenericLineSymbol('F', length));
			addSymbolToSuccessor(new TurnRightSymbol(angle));
			addSymbolToSuccessor(new GenericLineSymbol('F', length));
			addSymbolToSuccessor(new TurnRightSymbol(angle));
			addSymbolToSuccessor(new GenericLineSymbol('F', length));
			addSymbolToSuccessor(new RestoreStateSymbol());
		}
	};

	class Generic2DTreeProductionD : public LSystemProduction
	{
	public:
		Generic2DTreeProductionD(float length, float angle)
			:LSystemProduction('X')
		{
			addSymbolToSuccessor(new GenericLineSymbol('F', length));
			addSymbolToSuccessor(new SaveStateSymbol());
			addSymbolToSuccessor(new TurnLeftSymbol(angle));
			addSymbolToSuccessor(new GenericLineSymbol('X', length));
			addSymbolToSuccessor(new RestoreStateSymbol());
			addSymbolToSuccessor(new GenericLineSymbol('F', length));
			addSymbolToSuccessor(new SaveStateSymbol());
			addSymbolToSuccessor(new TurnRightSymbol(angle));
			addSymbolToSuccessor(new GenericLineSymbol('X', length));
			addSymbolToSuccessor(new RestoreStateSymbol());
			addSymbolToSuccessor(new TurnLeftSymbol(angle));
			addSymbolToSuccessor(new GenericLineSymbol('X', length));
		}
	};

	class Generic2DTreeProductionE : public LSystemProduction
	{
	public:
		Generic2DTreeProductionE(float length, float angle)
			:LSystemProduction('X')
		{
			addSymbolToSuccessor(new GenericLineSymbol('F', length));
			addSymbolToSuccessor(new SaveStateSymbol());
			addSymbolToSuccessor(new TurnLeftSymbol(angle));
			addSymbolToSuccessor(new GenericLineSymbol('X', length));
			addSymbolToSuccessor(new RestoreStateSymbol());
			addSymbolToSuccessor(new SaveStateSymbol());
			addSymbolToSuccessor(new TurnRightSymbol(angle));
			addSymbolToSuccessor(new GenericLineSymbol('X', length));
			addSymbolToSuccessor(new RestoreStateSymbol());
			addSymbolToSuccessor(new GenericLineSymbol('F', length));
			addSymbolToSuccessor(new GenericLineSymbol('X', length));
		}
	};

	class Generic2DTreeProductionF : public LSystemProduction
	{
	public:
		Generic2DTreeProductionF(float length, float angle)
			:LSystemProduction('X')
		{
			addSymbolToSuccessor(new GenericLineSymbol('F', length));
			addSymbolToSuccessor(new TurnRightSymbol(angle));
			addSymbolToSuccessor(new SaveStateSymbol());
			addSymbolToSuccessor(new SaveStateSymbol());
			addSymbolToSuccessor(new GenericLineSymbol('X', length));
			addSymbolToSuccessor(new RestoreStateSymbol());
			addSymbolToSuccessor(new TurnLeftSymbol(angle));
			addSymbolToSuccessor(new GenericLineSymbol('X', length));
			addSymbolToSuccessor(new RestoreStateSymbol());
			addSymbolToSuccessor(new TurnLeftSymbol(angle));
			addSymbolToSuccessor(new GenericLineSymbol('F', length));
			addSymbolToSuccessor(new SaveStateSymbol());
			addSymbolToSuccessor(new TurnLeftSymbol(angle));
			addSymbolToSuccessor(new GenericLineSymbol('F', length));
			addSymbolToSuccessor(new GenericLineSymbol('X', length));
			addSymbolToSuccessor(new RestoreStateSymbol());
			addSymbolToSuccessor(new TurnRightSymbol(angle));
			addSymbolToSuccessor(new GenericLineSymbol('X', length));
		}
	};

	class Generic2DTreeElongationProduction : public LSystemProduction
	{
	public:
		Generic2DTreeElongationProduction(float length)
			:LSystemProduction('F')
		{
			addSymbolToSuccessor(new GenericLineSymbol('F', length));
			addSymbolToSuccessor(new GenericLineSymbol('F', length));
		}
	};

	class Generic2DTreeProductionS1 : public LSystemProduction
	{
	public:
		Generic2DTreeProductionS1(float length, float angle)
			:LSystemProduction('F', 0.34f)
		{
			addSymbolToSuccessor(new GenericLineSymbol('F', length));
			addSymbolToSuccessor(new SaveStateSymbol());
			addSymbolToSuccessor(new TurnLeftSymbol(angle));
			addSymbolToSuccessor(new GenericLineSymbol('F', length));
			addSymbolToSuccessor(new RestoreStateSymbol());
			addSymbolToSuccessor(new GenericLineSymbol('F', length));
			addSymbolToSuccessor(new SaveStateSymbol());
			addSymbolToSuccessor(new TurnRightSymbol(angle));
			addSymbolToSuccessor(new GenericLineSymbol('F', length));
			addSymbolToSuccessor(new RestoreStateSymbol());
			addSymbolToSuccessor(new GenericLineSymbol('F', length));
		}
	};

	class Generic2DTreeProductionS2 : public LSystemProduction
	{
	public:
		Generic2DTreeProductionS2(float length, float angle)
			:LSystemProduction('F', 0.33f)
		{
			addSymbolToSuccessor(new GenericLineSymbol('F', length));
			addSymbolToSuccessor(new SaveStateSymbol());
			addSymbolToSuccessor(new TurnLeftSymbol(angle));
			addSymbolToSuccessor(new GenericLineSymbol('F', length));
			addSymbolToSuccessor(new RestoreStateSymbol());
			addSymbolToSuccessor(new GenericLineSymbol('F', length));
		}
	};

	class Generic2DTreeProductionS3 : public LSystemProduction
	{
	public:
		Generic2DTreeProductionS3(float length, float angle)
			:LSystemProduction('F', 0.33f)
		{
			addSymbolToSuccessor(new GenericLineSymbol('F', length));
			addSymbolToSuccessor(new SaveStateSymbol());
			addSymbolToSuccessor(new TurnRightSymbol(angle));
			addSymbolToSuccessor(new GenericLineSymbol('F', length));
			addSymbolToSuccessor(new RestoreStateSymbol());
			addSymbolToSuccessor(new GenericLineSymbol('F', length));
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

			LSystemSymbol *apex = new LSystemSymbol('A');
			apex->setParam('s', pred->getParam('s') / globalParams.at('R'));

			word.push_back(new GenericLineSymbol('F', pred->getParam('s')));
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
