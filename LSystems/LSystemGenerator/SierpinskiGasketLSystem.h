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
			setParam('d', length);

			addSymbolToAxiom(new LSystemSymbol('R'));
			addProduction(new SierpinskiGasketProductionL(angle));
			addProduction(new SierpinskiGasketProductionR(angle));
		}

		virtual const std::vector<LSystemSymbol *>& derive() override
		{
			const std::vector<LSystemSymbol *>& ret = LSystem::derive();
			setParam('d', getParam('d') / 1.5f);
			return ret;
		}
	};

}

#endif
