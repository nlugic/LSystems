#ifndef HILBERTCURVE3DPRODUCTIONS_H
#define HILBERTCURVE3DPRODUCTIONS_H

#include "LSystemProduction.h"
#include "TurnLeftSymbol.h"
#include "TurnRightSymbol.h"
#include "PitchUpSymbol.h"
#include "PitchDownSymbol.h"
#include "RollRightSymbol.h"
#include "TurnAroundSymbol.h"
#include "HilbertCurve3DSymbols.h"

namespace lsys
{

	class HilbertCurve3DProductionA : public LSystemProduction
	{
	public:
		HilbertCurve3DProductionA(float width, float length, float angle, const glm::vec3& color)
			:LSystemProduction('A')
		{
			addSymbolToSuccessor(new LSystemSymbol('B'));
			addSymbolToSuccessor(new TurnRightSymbol(angle));
			addSymbolToSuccessor(new HilbertCurve3DPipeSymbol(width, length, color));
			addSymbolToSuccessor(new TurnLeftSymbol(angle));
			addSymbolToSuccessor(new LSystemSymbol('C'));
			addSymbolToSuccessor(new HilbertCurve3DPipeSymbol(width, length, color));
			addSymbolToSuccessor(new LSystemSymbol('C'));
			addSymbolToSuccessor(new TurnLeftSymbol(angle));
			addSymbolToSuccessor(new HilbertCurve3DPipeSymbol(width, length, color));
			addSymbolToSuccessor(new TurnRightSymbol(angle));
			addSymbolToSuccessor(new LSystemSymbol('D'));
			addSymbolToSuccessor(new PitchDownSymbol(angle));
			addSymbolToSuccessor(new HilbertCurve3DPipeSymbol(width, length, color));
			addSymbolToSuccessor(new PitchUpSymbol(angle));
			addSymbolToSuccessor(new LSystemSymbol('D'));
			addSymbolToSuccessor(new TurnRightSymbol(angle));
			addSymbolToSuccessor(new HilbertCurve3DPipeSymbol(width, length, color));
			addSymbolToSuccessor(new TurnLeftSymbol(angle));
			addSymbolToSuccessor(new PitchDownSymbol(angle));
			addSymbolToSuccessor(new PitchDownSymbol(angle));
			addSymbolToSuccessor(new LSystemSymbol('C'));
			addSymbolToSuccessor(new HilbertCurve3DPipeSymbol(width, length, color));
			addSymbolToSuccessor(new LSystemSymbol('C'));
			addSymbolToSuccessor(new TurnLeftSymbol(angle));
			addSymbolToSuccessor(new HilbertCurve3DPipeSymbol(width, length, color));
			addSymbolToSuccessor(new TurnLeftSymbol(angle));
			addSymbolToSuccessor(new LSystemSymbol('B'));
			addSymbolToSuccessor(new RollRightSymbol(angle));
			addSymbolToSuccessor(new RollRightSymbol(angle));
		}

		inline virtual LSystemProduction *clone() const override { return new HilbertCurve3DProductionA(*this); }
	};

	class HilbertCurve3DProductionB : public LSystemProduction
	{
	public:
		HilbertCurve3DProductionB(float width, float length, float angle, const glm::vec3& color)
			:LSystemProduction('B')
		{
			addSymbolToSuccessor(new LSystemSymbol('A'));
			addSymbolToSuccessor(new PitchDownSymbol(angle));
			addSymbolToSuccessor(new HilbertCurve3DPipeSymbol(width, length, color));
			addSymbolToSuccessor(new PitchUpSymbol(angle));
			addSymbolToSuccessor(new LSystemSymbol('C'));
			addSymbolToSuccessor(new HilbertCurve3DPipeSymbol(width, length, color));
			addSymbolToSuccessor(new LSystemSymbol('B'));
			addSymbolToSuccessor(new PitchUpSymbol(angle));
			addSymbolToSuccessor(new HilbertCurve3DPipeSymbol(width, length, color));
			addSymbolToSuccessor(new PitchUpSymbol(angle));
			addSymbolToSuccessor(new LSystemSymbol('D'));
			addSymbolToSuccessor(new PitchUpSymbol(angle));
			addSymbolToSuccessor(new PitchUpSymbol(angle));
			addSymbolToSuccessor(new TurnRightSymbol(angle));
			addSymbolToSuccessor(new HilbertCurve3DPipeSymbol(width, length, color));
			addSymbolToSuccessor(new TurnRightSymbol(angle));
			addSymbolToSuccessor(new LSystemSymbol('D'));
			addSymbolToSuccessor(new PitchUpSymbol(angle));
			addSymbolToSuccessor(new TurnAroundSymbol());
			addSymbolToSuccessor(new HilbertCurve3DPipeSymbol(width, length, color));
			addSymbolToSuccessor(new PitchUpSymbol(angle));
			addSymbolToSuccessor(new LSystemSymbol('B'));
			addSymbolToSuccessor(new TurnAroundSymbol());
			addSymbolToSuccessor(new HilbertCurve3DPipeSymbol(width, length, color));
			addSymbolToSuccessor(new LSystemSymbol('C'));
			addSymbolToSuccessor(new PitchUpSymbol(angle));
			addSymbolToSuccessor(new HilbertCurve3DPipeSymbol(width, length, color));
			addSymbolToSuccessor(new PitchUpSymbol(angle));
			addSymbolToSuccessor(new LSystemSymbol('A'));
			addSymbolToSuccessor(new RollRightSymbol(angle));
			addSymbolToSuccessor(new RollRightSymbol(angle));
		}

		inline virtual LSystemProduction *clone() const override { return new HilbertCurve3DProductionB(*this); }
	};

	class HilbertCurve3DProductionC : public LSystemProduction
	{
	public:
		HilbertCurve3DProductionC(float width, float length, float angle, const glm::vec3& color)
			:LSystemProduction('C')
		{
			addSymbolToSuccessor(new TurnAroundSymbol());
			addSymbolToSuccessor(new LSystemSymbol('D'));
			addSymbolToSuccessor(new PitchUpSymbol(angle));
			addSymbolToSuccessor(new TurnAroundSymbol());
			addSymbolToSuccessor(new HilbertCurve3DPipeSymbol(width, length, color));
			addSymbolToSuccessor(new PitchUpSymbol(angle));
			addSymbolToSuccessor(new LSystemSymbol('B'));
			addSymbolToSuccessor(new TurnRightSymbol(angle));
			addSymbolToSuccessor(new HilbertCurve3DPipeSymbol(width, length, color));
			addSymbolToSuccessor(new TurnLeftSymbol(angle));
			addSymbolToSuccessor(new LSystemSymbol('C'));
			addSymbolToSuccessor(new PitchUpSymbol(angle));
			addSymbolToSuccessor(new HilbertCurve3DPipeSymbol(width, length, color));
			addSymbolToSuccessor(new PitchUpSymbol(angle));
			addSymbolToSuccessor(new LSystemSymbol('A'));
			addSymbolToSuccessor(new PitchDownSymbol(angle));
			addSymbolToSuccessor(new PitchDownSymbol(angle));
			addSymbolToSuccessor(new HilbertCurve3DPipeSymbol(width, length, color));
			addSymbolToSuccessor(new LSystemSymbol('A'));
			addSymbolToSuccessor(new PitchDownSymbol(angle));
			addSymbolToSuccessor(new HilbertCurve3DPipeSymbol(width, length, color));
			addSymbolToSuccessor(new PitchUpSymbol(angle));
			addSymbolToSuccessor(new LSystemSymbol('C'));
			addSymbolToSuccessor(new TurnLeftSymbol(angle));
			addSymbolToSuccessor(new HilbertCurve3DPipeSymbol(width, length, color));
			addSymbolToSuccessor(new TurnLeftSymbol(angle));
			addSymbolToSuccessor(new LSystemSymbol('B'));
			addSymbolToSuccessor(new PitchUpSymbol(angle));
			addSymbolToSuccessor(new HilbertCurve3DPipeSymbol(width, length, color));
			addSymbolToSuccessor(new PitchUpSymbol(angle));
			addSymbolToSuccessor(new LSystemSymbol('D'));
			addSymbolToSuccessor(new RollRightSymbol(angle));
			addSymbolToSuccessor(new RollRightSymbol(angle));
		}

		inline virtual LSystemProduction *clone() const override { return new HilbertCurve3DProductionC(*this); }
	};

	class HilbertCurve3DProductionD : public LSystemProduction
	{
	public:
		HilbertCurve3DProductionD(float width, float length, float angle, const glm::vec3& color)
			:LSystemProduction('D')
		{
			addSymbolToSuccessor(new TurnAroundSymbol());
			addSymbolToSuccessor(new LSystemSymbol('C'));
			addSymbolToSuccessor(new HilbertCurve3DPipeSymbol(width, length, color));
			addSymbolToSuccessor(new LSystemSymbol('B'));
			addSymbolToSuccessor(new TurnRightSymbol(angle));
			addSymbolToSuccessor(new HilbertCurve3DPipeSymbol(width, length, color));
			addSymbolToSuccessor(new TurnLeftSymbol(angle));
			addSymbolToSuccessor(new LSystemSymbol('B'));
			addSymbolToSuccessor(new TurnAroundSymbol());
			addSymbolToSuccessor(new HilbertCurve3DPipeSymbol(width, length, color));
			addSymbolToSuccessor(new LSystemSymbol('A'));
			addSymbolToSuccessor(new PitchDownSymbol(angle));
			addSymbolToSuccessor(new HilbertCurve3DPipeSymbol(width, length, color));
			addSymbolToSuccessor(new PitchUpSymbol(angle));
			addSymbolToSuccessor(new LSystemSymbol('A'));
			addSymbolToSuccessor(new PitchDownSymbol(angle));
			addSymbolToSuccessor(new PitchDownSymbol(angle));
			addSymbolToSuccessor(new HilbertCurve3DPipeSymbol(width, length, color));
			addSymbolToSuccessor(new LSystemSymbol('B'));
			addSymbolToSuccessor(new TurnRightSymbol(angle));
			addSymbolToSuccessor(new HilbertCurve3DPipeSymbol(width, length, color));
			addSymbolToSuccessor(new TurnLeftSymbol(angle));
			addSymbolToSuccessor(new LSystemSymbol('B'));
			addSymbolToSuccessor(new TurnAroundSymbol());
			addSymbolToSuccessor(new HilbertCurve3DPipeSymbol(width, length, color));
			addSymbolToSuccessor(new LSystemSymbol('C'));
			addSymbolToSuccessor(new RollRightSymbol(angle));
			addSymbolToSuccessor(new RollRightSymbol(angle));
		}

		inline virtual LSystemProduction *clone() const override { return new HilbertCurve3DProductionD(*this); }
	};
}

#endif
