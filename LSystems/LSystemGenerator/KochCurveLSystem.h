#ifndef KOCHCURVELSYSTEM_H
#define KOCHCURVELSYSTEM_H

#include "LSystem.h"
#include "KochCurveProductions.h"

namespace lsys
{

	class KochCurveLSystem : public LSystem
	{
	public:
		KochCurveLSystem(LSystemProduction *prod, float length, float angle)
		{
			setParam('d', length);

			addSymbolToAxiom(new LSystemSymbol('F'));
			addSymbolToAxiom(new TurnRightSymbol(angle));
			addSymbolToAxiom(new LSystemSymbol('F'));
			addSymbolToAxiom(new TurnRightSymbol(angle));
			addSymbolToAxiom(new LSystemSymbol('F'));
			addSymbolToAxiom(new TurnRightSymbol(angle));
			addSymbolToAxiom(new LSystemSymbol('F'));

			addProduction(prod);
		}

		virtual const std::vector<LSystemSymbol *>& derive() override
		{
			const std::vector<LSystemSymbol *>& ret = LSystem::derive();
			setParam('d', getParam('d') / 4.0f);
			return ret;
		}
	};

}

#endif
