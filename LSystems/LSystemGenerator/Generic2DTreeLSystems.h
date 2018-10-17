#ifndef GENERIC2DTREELSYSTEMS_H
#define GENERIC2DTREELSYSTEMS_H

#include "LSystem.h"
#include "Generic2DTreeProductions.h"

namespace lsys
{

	class Generic2DTreeLSystem : public LSystem
	{
	public:
		Generic2DTreeLSystem(char axiom, LSystemProduction *prod, float length, bool elongation = false)
		{
			setParam('d', length);

			addSymbolToAxiom(new LSystemSymbol(axiom));
			
			addProduction(prod);
			if (elongation)
				addProduction(new Generic2DTreeElongationProduction());
		}
	};

	class Generic2DTreeLSystemSD : public LSystem
	{
	public:
		Generic2DTreeLSystemSD(float length, float reduction, float angle)
		{
			setParam('R', reduction);
			setParam('a', angle);

			addSymbolToAxiom(new LSystemSymbol('A'));
			axiom.at(0)->setParam('s', length);

			addProduction(new Generic2DTreeProductionSD());
		}
	};

}

#endif