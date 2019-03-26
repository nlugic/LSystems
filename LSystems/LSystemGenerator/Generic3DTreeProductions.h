#ifndef GENERIC3DTREEPRODUCTIONS_H
#define GENERIC3DTREEPRODUCTIONS_H

#include "LSystemProduction.h"
#include "SaveStateSymbol.h"
#include "RestoreStateSymbol.h"
#include "TurnRightSymbol.h"
#include "PitchUpSymbol.h"
#include "PitchDownSymbol.h"
#include "RollRightSymbol.h"
#include "Generic3DTreeSymbols.h"

namespace lsys
{

	class Generic3DTreeProductionP1 : public LSystemProduction
	{
	public:
		Generic3DTreeProductionP1()
			:LSystemProduction('A') { }

		virtual void generateSuccessor(const LSystemSymbol *pred, const std::map<char, float>& globalParams,
			std::vector<LSystemSymbol *>& word) const override
		{
			float angle = globalParams.at('a');
			float slices = pred->getParam('n');
			float rStart = pred->getParam('r');
			float rEnd = 0.8f * rStart;
			float height = 1.1f * pred->getParam('h');
			float wrap = pred->getParam('w');

			word.push_back(new SaveStateSymbol());

			word.push_back(new PitchDownSymbol(angle));
			word.push_back(new Generic3DTreeBranchSegmentSymbol(slices, rStart, rEnd, height, wrap));

			word.push_back(new SaveStateSymbol());
			word.push_back(new PitchUpSymbol(2.0f * angle));
			word.push_back(new Generic3DTreeLeafSymbol(0.25f, 0.1f, 0.075f, 0.2f, 0.6f));
			word.push_back(new RestoreStateSymbol());

			word.push_back(new Generic3DTreeBranchApexSymbol(slices, rEnd, height, wrap));

			word.push_back(new RestoreStateSymbol());

			word.push_back(new RollRightSymbol(5.0f * angle));

			word.push_back(new SaveStateSymbol());

			word.push_back(new PitchDownSymbol(angle));
			word.push_back(new Generic3DTreeBranchSegmentSymbol(slices, rStart, rEnd, height, wrap));

			word.push_back(new SaveStateSymbol());
			word.push_back(new PitchUpSymbol(2.0f * angle));
			word.push_back(new Generic3DTreeLeafSymbol(0.25f, 0.1f, 0.075f, 0.2f, 0.6f));
			word.push_back(new RestoreStateSymbol());

			word.push_back(new Generic3DTreeBranchApexSymbol(slices, rEnd, height, wrap));

			word.push_back(new RestoreStateSymbol());

			word.push_back(new RollRightSymbol(7.0f * angle));

			word.push_back(new SaveStateSymbol());

			word.push_back(new PitchDownSymbol(angle));
			word.push_back(new Generic3DTreeBranchSegmentSymbol(slices, rStart, rEnd, height, wrap));

			word.push_back(new SaveStateSymbol());
			word.push_back(new PitchUpSymbol(2.0f * angle));
			word.push_back(new Generic3DTreeLeafSymbol(0.25f, 0.1f, 0.075f, 0.2f, 0.6f));
			word.push_back(new RestoreStateSymbol());

			word.push_back(new Generic3DTreeBranchApexSymbol(slices, rEnd, height, wrap));

			word.push_back(new RestoreStateSymbol());
		}
	};

	class Generic3DTreeProductionP2 : public LSystemProduction
	{
	public:
		Generic3DTreeProductionP2()
			:LSystemProduction('F') { }

		virtual void generateSuccessor(const LSystemSymbol *pred, const std::map<char, float>& globalParams,
			std::vector<LSystemSymbol *>& word) const override
		{
			LSystemSymbol *expansionSymbol = new LSystemSymbol('S');
			expansionSymbol->setParams(pred);
			word.push_back(expansionSymbol);

			word.push_back(new RollRightSymbol(5.0f * globalParams.at('a')));
			word.push_back(new Generic3DTreeBranchSegmentSymbol(pred->getParam('n'), pred->getParam('R'),
				pred->getParam('R'), pred->getParam('h'), pred->getParam('w')));
		}
	};

	class Generic3DTreeProductionP3 : public LSystemProduction
	{
	public:
		Generic3DTreeProductionP3()
			:LSystemProduction('S') { }

		virtual void generateSuccessor(const LSystemSymbol *pred, const std::map<char, float>& globalParams,
			std::vector<LSystemSymbol *>& word) const override
		{
			word.push_back(new Generic3DTreeBranchSegmentSymbol(pred->getParam('n'), pred->getParam('R'),
				pred->getParam('R'), pred->getParam('h'), pred->getParam('w')));

			word.push_back(new SaveStateSymbol());
			word.push_back(new PitchUpSymbol(2.0f * globalParams.at('a')));
			word.push_back(new Generic3DTreeLeafSymbol(0.25f, 0.1f, 0.075f, 0.2f, 0.6f));
			word.push_back(new RestoreStateSymbol());
		}
	};

}

#endif
