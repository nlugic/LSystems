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
	private:
		float slices, radius, length, angle;

	public:
		HilbertCurve3DProductionA(float slic, float rad, float len, float ang)
			:LSystemProduction('A'), slices(slic), radius(rad), length(len), angle(ang) { }

		virtual void generateSuccessor(const LSystemSymbol *pred, const std::map<char, float>& globalParams,
			std::vector<LSystemSymbol *>& word) const override
		{
			word.push_back(new LSystemSymbol('B'));
			word.push_back(new TurnRightSymbol(angle));
			word.push_back(new HilbertCurve3DPipeSymbol(slices, radius, length, angle));
			word.push_back(new TurnLeftSymbol(angle));
			word.push_back(new LSystemSymbol('C'));
			word.push_back(new HilbertCurve3DPipeSymbol(slices, radius, length, angle));
			word.push_back(new LSystemSymbol('C'));
			word.push_back(new TurnLeftSymbol(angle));
			word.push_back(new HilbertCurve3DPipeSymbol(slices, radius, length, angle));
			word.push_back(new TurnRightSymbol(angle));
			word.push_back(new LSystemSymbol('D'));
			word.push_back(new PitchDownSymbol(angle));
			word.push_back(new HilbertCurve3DPipeSymbol(slices, radius, length, angle));
			word.push_back(new PitchUpSymbol(angle));
			word.push_back(new LSystemSymbol('D'));
			word.push_back(new TurnRightSymbol(angle));
			word.push_back(new HilbertCurve3DPipeSymbol(slices, radius, length, angle));
			word.push_back(new TurnLeftSymbol(angle));
			word.push_back(new PitchDownSymbol(angle));
			word.push_back(new PitchDownSymbol(angle));
			word.push_back(new LSystemSymbol('C'));
			word.push_back(new HilbertCurve3DPipeSymbol(slices, radius, length, angle));
			word.push_back(new LSystemSymbol('C'));
			word.push_back(new TurnLeftSymbol(angle));
			word.push_back(new HilbertCurve3DPipeSymbol(slices, radius, length, angle));
			word.push_back(new TurnLeftSymbol(angle));
			word.push_back(new LSystemSymbol('B'));
			word.push_back(new RollRightSymbol(angle));
			word.push_back(new RollRightSymbol(angle));
		}
	};

	class HilbertCurve3DProductionB : public LSystemProduction
	{
	private:
		float slices, radius, length, angle;

	public:
		HilbertCurve3DProductionB(float slic, float rad, float len, float ang)
			:LSystemProduction('B'), slices(slic), radius(rad), length(len), angle(ang) { }

		virtual void generateSuccessor(const LSystemSymbol *pred, const std::map<char, float>& globalParams,
			std::vector<LSystemSymbol *>& word) const override
		{
			word.push_back(new LSystemSymbol('A'));
			word.push_back(new PitchDownSymbol(angle));
			word.push_back(new HilbertCurve3DPipeSymbol(slices, radius, length, angle));
			word.push_back(new PitchUpSymbol(angle));
			word.push_back(new LSystemSymbol('C'));
			word.push_back(new HilbertCurve3DPipeSymbol(slices, radius, length, angle));
			word.push_back(new LSystemSymbol('B'));
			word.push_back(new PitchUpSymbol(angle));
			word.push_back(new HilbertCurve3DPipeSymbol(slices, radius, length, angle));
			word.push_back(new PitchUpSymbol(angle));
			word.push_back(new LSystemSymbol('D'));
			word.push_back(new PitchUpSymbol(angle));
			word.push_back(new PitchUpSymbol(angle));
			word.push_back(new TurnRightSymbol(angle));
			word.push_back(new HilbertCurve3DPipeSymbol(slices, radius, length, angle));
			word.push_back(new TurnRightSymbol(angle));
			word.push_back(new LSystemSymbol('D'));
			word.push_back(new PitchUpSymbol(angle));
			word.push_back(new TurnAroundSymbol());
			word.push_back(new HilbertCurve3DPipeSymbol(slices, radius, length, angle));
			word.push_back(new PitchUpSymbol(angle));
			word.push_back(new LSystemSymbol('B'));
			word.push_back(new TurnAroundSymbol());
			word.push_back(new HilbertCurve3DPipeSymbol(slices, radius, length, angle));
			word.push_back(new LSystemSymbol('C'));
			word.push_back(new PitchUpSymbol(angle));
			word.push_back(new HilbertCurve3DPipeSymbol(slices, radius, length, angle));
			word.push_back(new PitchUpSymbol(angle));
			word.push_back(new LSystemSymbol('A'));
			word.push_back(new RollRightSymbol(angle));
			word.push_back(new RollRightSymbol(angle));
		}
	};

	class HilbertCurve3DProductionC : public LSystemProduction
	{
	private:
		float slices, radius, length, angle;

	public:
		HilbertCurve3DProductionC(float slic, float rad, float len, float ang)
			:LSystemProduction('C'), slices(slic), radius(rad), length(len), angle(ang) { }

		virtual void generateSuccessor(const LSystemSymbol *pred, const std::map<char, float>& globalParams,
			std::vector<LSystemSymbol *>& word) const override
		{
			word.push_back(new TurnAroundSymbol());
			word.push_back(new LSystemSymbol('D'));
			word.push_back(new PitchUpSymbol(angle));
			word.push_back(new TurnAroundSymbol());
			word.push_back(new HilbertCurve3DPipeSymbol(slices, radius, length, angle));
			word.push_back(new PitchUpSymbol(angle));
			word.push_back(new LSystemSymbol('B'));
			word.push_back(new TurnRightSymbol(angle));
			word.push_back(new HilbertCurve3DPipeSymbol(slices, radius, length, angle));
			word.push_back(new TurnLeftSymbol(angle));
			word.push_back(new LSystemSymbol('C'));
			word.push_back(new PitchUpSymbol(angle));
			word.push_back(new HilbertCurve3DPipeSymbol(slices, radius, length, angle));
			word.push_back(new PitchUpSymbol(angle));
			word.push_back(new LSystemSymbol('A'));
			word.push_back(new PitchDownSymbol(angle));
			word.push_back(new PitchDownSymbol(angle));
			word.push_back(new HilbertCurve3DPipeSymbol(slices, radius, length, angle));
			word.push_back(new LSystemSymbol('A'));
			word.push_back(new PitchDownSymbol(angle));
			word.push_back(new HilbertCurve3DPipeSymbol(slices, radius, length, angle));
			word.push_back(new PitchUpSymbol(angle));
			word.push_back(new LSystemSymbol('C'));
			word.push_back(new TurnLeftSymbol(angle));
			word.push_back(new HilbertCurve3DPipeSymbol(slices, radius, length, angle));
			word.push_back(new TurnLeftSymbol(angle));
			word.push_back(new LSystemSymbol('B'));
			word.push_back(new PitchUpSymbol(angle));
			word.push_back(new HilbertCurve3DPipeSymbol(slices, radius, length, angle));
			word.push_back(new PitchUpSymbol(angle));
			word.push_back(new LSystemSymbol('D'));
			word.push_back(new RollRightSymbol(angle));
			word.push_back(new RollRightSymbol(angle));
		}
	};

	class HilbertCurve3DProductionD : public LSystemProduction
	{
	private:
		float slices, radius, length, angle;

	public:
		HilbertCurve3DProductionD(float slic, float rad, float len, float ang)
			:LSystemProduction('D'), slices(slic), radius(rad), length(len), angle(ang) { }

		virtual void generateSuccessor(const LSystemSymbol *pred, const std::map<char, float>& globalParams,
			std::vector<LSystemSymbol *>& word) const override
		{
			word.push_back(new TurnAroundSymbol());
			word.push_back(new LSystemSymbol('C'));
			word.push_back(new HilbertCurve3DPipeSymbol(slices, radius, length, angle));
			word.push_back(new LSystemSymbol('B'));
			word.push_back(new TurnRightSymbol(angle));
			word.push_back(new HilbertCurve3DPipeSymbol(slices, radius, length, angle));
			word.push_back(new TurnLeftSymbol(angle));
			word.push_back(new LSystemSymbol('B'));
			word.push_back(new TurnAroundSymbol());
			word.push_back(new HilbertCurve3DPipeSymbol(slices, radius, length, angle));
			word.push_back(new LSystemSymbol('A'));
			word.push_back(new PitchDownSymbol(angle));
			word.push_back(new HilbertCurve3DPipeSymbol(slices, radius, length, angle));
			word.push_back(new PitchUpSymbol(angle));
			word.push_back(new LSystemSymbol('A'));
			word.push_back(new PitchDownSymbol(angle));
			word.push_back(new PitchDownSymbol(angle));
			word.push_back(new HilbertCurve3DPipeSymbol(slices, radius, length, angle));
			word.push_back(new LSystemSymbol('B'));
			word.push_back(new TurnRightSymbol(angle));
			word.push_back(new HilbertCurve3DPipeSymbol(slices, radius, length, angle));
			word.push_back(new TurnLeftSymbol(angle));
			word.push_back(new LSystemSymbol('B'));
			word.push_back(new TurnAroundSymbol());
			word.push_back(new HilbertCurve3DPipeSymbol(slices, radius, length, angle));
			word.push_back(new LSystemSymbol('C'));
			word.push_back(new RollRightSymbol(angle));
			word.push_back(new RollRightSymbol(angle));
		}
	};
}

#endif
