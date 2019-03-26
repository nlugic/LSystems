#ifndef GENERIC3DTREELSYSTEM_H
#define GENERIC3DTREELSYSTEM_H

#include "LSystem.h"
#include "Generic3DTreeProductions.h"

namespace lsys
{

	class Generic3DTreeLSystem : public LSystem
	{
	public:
		Generic3DTreeLSystem(int slices, float radius, float height, float angle)
		{
			setParam('a', angle);

			addSymbolToAxiom(new Generic3DTreeBranchApexSymbol(static_cast<float>(slices), radius, height));

			addProduction(new Generic3DTreeProductionP1());
			addProduction(new Generic3DTreeProductionP2());
			addProduction(new Generic3DTreeProductionP3());
		}
	};

	class TesselatedGeneric3DTreeLSystem : public LSystem
	{
	public:
		TesselatedGeneric3DTreeLSystem(float radius, float height, float angle)
		{
			setParam('a', angle);

			addSymbolToAxiom(new Generic3DTreeBranchApexSymbol(0.0f, radius, height));

			addProduction(new Generic3DTreeProductionP1());
			addProduction(new Generic3DTreeProductionP2());
			addProduction(new Generic3DTreeProductionP3());
		}
	};

}

#endif
