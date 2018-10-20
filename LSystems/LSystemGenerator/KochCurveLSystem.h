#ifndef KOCHCURVELSYSTEM_H
#define KOCHCURVELSYSTEM_H

#include "LSystem.h"
#include "KochCurveProductions.h"

namespace lsys
{

	class KochCurveLSystem : public LSystem
	{
	public:
		KochCurveLSystem(LSystemProduction *prod, float length, float angle, float segments = 4.0f)
		{
			setParam('a', angle);
			setParam('s', segments);

			unsigned char segs = static_cast<unsigned char>(segments);
			for (unsigned char i = 0U; i < segs; ++i)
			{
				addSymbolToAxiom(new GenericLineSymbol('F', length));
				addSymbolToAxiom(new TurnRightSymbol((segs == 4U) ? angle : 2.0f * angle));
			}

			addProduction(prod);
		}
	};

}

#endif
