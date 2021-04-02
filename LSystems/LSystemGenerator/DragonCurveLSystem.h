#ifndef DRAGONCURVELSYSTEM_H
#define DRAGONCURVELSYSTEM_H

#include "LSystem.h"
#include "DragonCurveProductions.h"

namespace lsys
{

	class DragonCurveLSystem : public LSystem
	{
	public:
		DragonCurveLSystem(float length, float angle)
		{
			addSymbolToAxiom(new GenericLineSymbol('L', length));

			addProduction(new DragonCurveProductionL(length, angle));
			addProduction(new DragonCurveProductionR(length, angle));
		}

		inline virtual LSystem *clone() const override { return new DragonCurveLSystem(*this); }
	};

}

#endif
