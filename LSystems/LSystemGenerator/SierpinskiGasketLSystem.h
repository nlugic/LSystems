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
			setParam('a', angle);

			addSymbolToAxiom(new GenericLineSymbol('R', length));

			addProduction(new SierpinskiGasketProductionL());
			addProduction(new SierpinskiGasketProductionR());
		}
	};

}

#endif
