#ifndef HILBERTCURVE3DLSYSTEM_H
#define HILBERTCURVE3DLSYSTEM_H

#include "LSystem.h"
#include "HilbertCurve3DProductions.h"

namespace lsys
{

	class HilbertCurve3DLSystem : public LSystem
	{
	public:
		HilbertCurve3DLSystem(int slices, float radius, float length, float angle)
		{
			addSymbolToAxiom(new LSystemSymbol('A'));

			addProduction(new HilbertCurve3DProductionA(static_cast<float>(slices), radius, length, angle));
			addProduction(new HilbertCurve3DProductionB(static_cast<float>(slices), radius, length, angle));
			addProduction(new HilbertCurve3DProductionC(static_cast<float>(slices), radius, length, angle));
			addProduction(new HilbertCurve3DProductionD(static_cast<float>(slices), radius, length, angle));
		}
	};

}

#endif
