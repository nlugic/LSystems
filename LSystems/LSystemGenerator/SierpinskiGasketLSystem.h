#ifndef SIERPINSKIGASKETLSYSTEM_H
#define SIERPINSKIGASKETLSYSTEM_H

#include "LSystem.h"
#include "SierpinskiGasketProductions.h"

namespace lsys
{

	class SierpinskiGasketLSystem : public LSystem
	{
	public:
		SierpinskiGasketLSystem(float length, float angle)
		{
			addSymbolToAxiom(new GenericLineSymbol('R', length));

			addProduction(new SierpinskiGasketProductionL(length, angle));
			addProduction(new SierpinskiGasketProductionR(length, angle));
		}

		inline virtual LSystem *clone() const override { return new SierpinskiGasketLSystem(*this); }
	};

}

#endif
