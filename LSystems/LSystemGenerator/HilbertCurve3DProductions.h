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
		float width, length, angle;
		glm::vec3 color;

	public:
		HilbertCurve3DProductionA(float wid, float len, float ang, const glm::vec3& col)
			:LSystemProduction('A'), width(wid), length(len), angle(ang), color(col) { }

		virtual void generateSuccessor(const LSystemSymbol *pred, const std::map<char, float>& globalParams,
			std::vector<LSystemSymbol *>& word) const override
		{
			word.push_back(new LSystemSymbol('B'));
			word.push_back(new TurnRightSymbol(angle));
			word.push_back(new HilbertCurve3DPipeSymbol(width, length, color));
			word.push_back(new TurnLeftSymbol(angle));
			word.push_back(new LSystemSymbol('C'));
			word.push_back(new HilbertCurve3DPipeSymbol(width, length, color));
			word.push_back(new LSystemSymbol('C'));
			word.push_back(new TurnLeftSymbol(angle));
			word.push_back(new HilbertCurve3DPipeSymbol(width, length, color));
			word.push_back(new TurnRightSymbol(angle));
			word.push_back(new LSystemSymbol('D'));
			word.push_back(new PitchDownSymbol(angle));
			word.push_back(new HilbertCurve3DPipeSymbol(width, length, color));
			word.push_back(new PitchUpSymbol(angle));
			word.push_back(new LSystemSymbol('D'));
			word.push_back(new TurnRightSymbol(angle));
			word.push_back(new HilbertCurve3DPipeSymbol(width, length, color));
			word.push_back(new TurnLeftSymbol(angle));
			word.push_back(new PitchDownSymbol(angle));
			word.push_back(new PitchDownSymbol(angle));
			word.push_back(new LSystemSymbol('C'));
			word.push_back(new HilbertCurve3DPipeSymbol(width, length, color));
			word.push_back(new LSystemSymbol('C'));
			word.push_back(new TurnLeftSymbol(angle));
			word.push_back(new HilbertCurve3DPipeSymbol(width, length, color));
			word.push_back(new TurnLeftSymbol(angle));
			word.push_back(new LSystemSymbol('B'));
			word.push_back(new RollRightSymbol(angle));
			word.push_back(new RollRightSymbol(angle));
		}
	};

	class HilbertCurve3DProductionB : public LSystemProduction
	{
	private:
		float width, length, angle;
		glm::vec3 color;

	public:
		HilbertCurve3DProductionB(float wid, float len, float ang, const glm::vec3& col)
			:LSystemProduction('B'), width(wid), length(len), angle(ang), color(col) { }

		virtual void generateSuccessor(const LSystemSymbol *pred, const std::map<char, float>& globalParams,
			std::vector<LSystemSymbol *>& word) const override
		{
			word.push_back(new LSystemSymbol('A'));
			word.push_back(new PitchDownSymbol(angle));
			word.push_back(new HilbertCurve3DPipeSymbol(width, length, color));
			word.push_back(new PitchUpSymbol(angle));
			word.push_back(new LSystemSymbol('C'));
			word.push_back(new HilbertCurve3DPipeSymbol(width, length, color));
			word.push_back(new LSystemSymbol('B'));
			word.push_back(new PitchUpSymbol(angle));
			word.push_back(new HilbertCurve3DPipeSymbol(width, length, color));
			word.push_back(new PitchUpSymbol(angle));
			word.push_back(new LSystemSymbol('D'));
			word.push_back(new PitchUpSymbol(angle));
			word.push_back(new PitchUpSymbol(angle));
			word.push_back(new TurnRightSymbol(angle));
			word.push_back(new HilbertCurve3DPipeSymbol(width, length, color));
			word.push_back(new TurnRightSymbol(angle));
			word.push_back(new LSystemSymbol('D'));
			word.push_back(new PitchUpSymbol(angle));
			word.push_back(new TurnAroundSymbol());
			word.push_back(new HilbertCurve3DPipeSymbol(width, length, color));
			word.push_back(new PitchUpSymbol(angle));
			word.push_back(new LSystemSymbol('B'));
			word.push_back(new TurnAroundSymbol());
			word.push_back(new HilbertCurve3DPipeSymbol(width, length, color));
			word.push_back(new LSystemSymbol('C'));
			word.push_back(new PitchUpSymbol(angle));
			word.push_back(new HilbertCurve3DPipeSymbol(width, length, color));
			word.push_back(new PitchUpSymbol(angle));
			word.push_back(new LSystemSymbol('A'));
			word.push_back(new RollRightSymbol(angle));
			word.push_back(new RollRightSymbol(angle));
		}
	};

	class HilbertCurve3DProductionC : public LSystemProduction
	{
	private:
		float width, length, angle;
		glm::vec3 color;

	public:
		HilbertCurve3DProductionC(float wid, float len, float ang, const glm::vec3& col)
			:LSystemProduction('C'), width(wid), length(len), angle(ang), color(col) { }

		virtual void generateSuccessor(const LSystemSymbol *pred, const std::map<char, float>& globalParams,
			std::vector<LSystemSymbol *>& word) const override
		{
			word.push_back(new TurnAroundSymbol());
			word.push_back(new LSystemSymbol('D'));
			word.push_back(new PitchUpSymbol(angle));
			word.push_back(new TurnAroundSymbol());
			word.push_back(new HilbertCurve3DPipeSymbol(width, length, color));
			word.push_back(new PitchUpSymbol(angle));
			word.push_back(new LSystemSymbol('B'));
			word.push_back(new TurnRightSymbol(angle));
			word.push_back(new HilbertCurve3DPipeSymbol(width, length, color));
			word.push_back(new TurnLeftSymbol(angle));
			word.push_back(new LSystemSymbol('C'));
			word.push_back(new PitchUpSymbol(angle));
			word.push_back(new HilbertCurve3DPipeSymbol(width, length, color));
			word.push_back(new PitchUpSymbol(angle));
			word.push_back(new LSystemSymbol('A'));
			word.push_back(new PitchDownSymbol(angle));
			word.push_back(new PitchDownSymbol(angle));
			word.push_back(new HilbertCurve3DPipeSymbol(width, length, color));
			word.push_back(new LSystemSymbol('A'));
			word.push_back(new PitchDownSymbol(angle));
			word.push_back(new HilbertCurve3DPipeSymbol(width, length, color));
			word.push_back(new PitchUpSymbol(angle));
			word.push_back(new LSystemSymbol('C'));
			word.push_back(new TurnLeftSymbol(angle));
			word.push_back(new HilbertCurve3DPipeSymbol(width, length, color));
			word.push_back(new TurnLeftSymbol(angle));
			word.push_back(new LSystemSymbol('B'));
			word.push_back(new PitchUpSymbol(angle));
			word.push_back(new HilbertCurve3DPipeSymbol(width, length, color));
			word.push_back(new PitchUpSymbol(angle));
			word.push_back(new LSystemSymbol('D'));
			word.push_back(new RollRightSymbol(angle));
			word.push_back(new RollRightSymbol(angle));
		}
	};

	class HilbertCurve3DProductionD : public LSystemProduction
	{
	private:
		float width, length, angle;
		glm::vec3 color;

	public:
		HilbertCurve3DProductionD(float wid, float len, float ang, const glm::vec3& col)
			:LSystemProduction('D'), width(wid), length(len), angle(ang), color(col) { }

		virtual void generateSuccessor(const LSystemSymbol *pred, const std::map<char, float>& globalParams,
			std::vector<LSystemSymbol *>& word) const override
		{
			word.push_back(new TurnAroundSymbol());
			word.push_back(new LSystemSymbol('C'));
			word.push_back(new HilbertCurve3DPipeSymbol(width, length, color));
			word.push_back(new LSystemSymbol('B'));
			word.push_back(new TurnRightSymbol(angle));
			word.push_back(new HilbertCurve3DPipeSymbol(width, length, color));
			word.push_back(new TurnLeftSymbol(angle));
			word.push_back(new LSystemSymbol('B'));
			word.push_back(new TurnAroundSymbol());
			word.push_back(new HilbertCurve3DPipeSymbol(width, length, color));
			word.push_back(new LSystemSymbol('A'));
			word.push_back(new PitchDownSymbol(angle));
			word.push_back(new HilbertCurve3DPipeSymbol(width, length, color));
			word.push_back(new PitchUpSymbol(angle));
			word.push_back(new LSystemSymbol('A'));
			word.push_back(new PitchDownSymbol(angle));
			word.push_back(new PitchDownSymbol(angle));
			word.push_back(new HilbertCurve3DPipeSymbol(width, length, color));
			word.push_back(new LSystemSymbol('B'));
			word.push_back(new TurnRightSymbol(angle));
			word.push_back(new HilbertCurve3DPipeSymbol(width, length, color));
			word.push_back(new TurnLeftSymbol(angle));
			word.push_back(new LSystemSymbol('B'));
			word.push_back(new TurnAroundSymbol());
			word.push_back(new HilbertCurve3DPipeSymbol(width, length, color));
			word.push_back(new LSystemSymbol('C'));
			word.push_back(new RollRightSymbol(angle));
			word.push_back(new RollRightSymbol(angle));
		}
	};
}

#endif
