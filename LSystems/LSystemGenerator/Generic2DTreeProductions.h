#ifndef GENERIC2DTREEPRODUCTIONS_H
#define GENERIC2DTREEPRODUCTIONS_H

#include "LSystemProduction.h"
#include "SaveStateSymbol.h"
#include "RestoreStateSymbol.h"
#include "TurnLeftSymbol.h"
#include "TurnRightSymbol.h"
#include "GenericLineSymbol.h"

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

		inline virtual LSystemProduction *clone() const override { return new Generic2DTreeProductionA(*this); }
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

		inline virtual LSystemProduction *clone() const override { return new Generic2DTreeProductionB(*this); }
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

		inline virtual LSystemProduction *clone() const override { return new Generic2DTreeProductionC(*this); }
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

		inline virtual LSystemProduction *clone() const override { return new Generic2DTreeProductionD(*this); }
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

		inline virtual LSystemProduction *clone() const override { return new Generic2DTreeProductionE(*this); }
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

		inline virtual LSystemProduction *clone() const override { return new Generic2DTreeProductionF(*this); }
	};

	class Generic2DTreeElongationProduction : public LSystemProduction
	{
	public:
		explicit Generic2DTreeElongationProduction(float length)
			:LSystemProduction('F')
		{
			addSymbolToSuccessor(new GenericLineSymbol('F', length));
			addSymbolToSuccessor(new GenericLineSymbol('F', length));
		}

		inline virtual LSystemProduction *clone() const override { return new Generic2DTreeElongationProduction(*this); }
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

		inline virtual LSystemProduction *clone() const override { return new Generic2DTreeProductionS1(*this); }
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

		inline virtual LSystemProduction *clone() const override { return new Generic2DTreeProductionS2(*this); }
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

		inline virtual LSystemProduction *clone() const override { return new Generic2DTreeProductionS3(*this); }
	};

	class Generic2DTreeProductionSD : public LSystemProduction
	{
	public:
		explicit Generic2DTreeProductionSD(float angle)
			:LSystemProduction('A')
		{
			LSystemSymbol *apex = new LSystemSymbol('A');
			apex->defineParam('s');

			addSymbolToSuccessor(new GenericLineSymbol('F', NAN, NAN));
			addSymbolToSuccessor(new SaveStateSymbol());
			addSymbolToSuccessor(new TurnLeftSymbol(angle));
			addSymbolToSuccessor(apex);
			addSymbolToSuccessor(new RestoreStateSymbol());
			addSymbolToSuccessor(new SaveStateSymbol());
			addSymbolToSuccessor(new TurnRightSymbol(angle));
			addSymbolToSuccessor(apex->clone());
			addSymbolToSuccessor(new RestoreStateSymbol());
		}

		virtual void generateSuccessor(const LSystemSymbol *pred, const std::map<char, float>& global_params,
			std::vector<LSystemSymbol *>& word) const override
		{
			float angle = global_params.at('a');
			float scale = pred->getParam('s');

			LSystemSymbol *apex = new LSystemSymbol('A');
			apex->setParam('s', scale / global_params.at('R'));

			word.push_back(new GenericLineSymbol('F', scale));
			word.push_back(new SaveStateSymbol());
			word.push_back(new TurnLeftSymbol(angle));
			word.push_back(apex);
			word.push_back(new RestoreStateSymbol());
			word.push_back(new SaveStateSymbol());
			word.push_back(new TurnRightSymbol(angle));
			word.push_back(apex->clone());
			word.push_back(new RestoreStateSymbol());
		}

		inline virtual LSystemProduction *clone() const override { return new Generic2DTreeProductionSD(*this); }
	};

}

#endif
