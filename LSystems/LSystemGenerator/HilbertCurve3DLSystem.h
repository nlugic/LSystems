#ifndef HILBERTCURVE3DLSYSTEM_H
#define HILBERTCURVE3DLSYSTEM_H

#include "LSystem.h"
#include "HilbertCurve3DProductions.h"

namespace lsys
{

	class HilbertCurve3DLSystem : public LSystem
	{
	public:
		HilbertCurve3DLSystem(float width, float length, float angle, const glm::vec3& color)
		{
			addSymbolToAxiom(new LSystemSymbol('A'));

			addProduction(new HilbertCurve3DProductionA(width, length, angle, color));
			addProduction(new HilbertCurve3DProductionB(width, length, angle, color));
			addProduction(new HilbertCurve3DProductionC(width, length, angle, color));
			addProduction(new HilbertCurve3DProductionD(width, length, angle, color));
		}

		inline virtual LSystem *clone() const override { return new HilbertCurve3DLSystem(*this); }
	};

}

#endif
