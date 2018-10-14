
#include "LSystemProduction.h"

namespace lsys
{

	void LSystemProduction::clearSuccessor()
	{
		for (LSystemSymbol *sym : successor)
			delete sym;
		successor.clear();
	}

	LSystemProduction::LSystemProduction(LSystemSymbol *pred, float prob)
		:predecessor(pred), probability((prob < 0.0f || prob > 1.0f) ? 1.0f : prob) { }

	LSystemProduction::LSystemProduction(char pred, float prob)
		: predecessor(new LSystemSymbol(pred)), probability((prob < 0.0f || prob > 1.0f) ? 1.0f : prob) { }

	LSystemProduction::LSystemProduction(const LSystemProduction& lProd)
		: predecessor(new LSystemSymbol(*lProd.predecessor)), probability(lProd.probability)
	{
		for (const LSystemSymbol *sym : lProd.successor)
			successor.push_back(new LSystemSymbol(*sym));
	}

	LSystemProduction& LSystemProduction::operator=(const LSystemProduction& lProd)
	{
		if (this != &lProd)
		{
			delete predecessor;
			clearSuccessor();

			predecessor = new LSystemSymbol(*lProd.predecessor);
			for (const LSystemSymbol* sym : lProd.successor)
				successor.push_back(new LSystemSymbol(*sym));
			probability = lProd.probability;
		}
		return *this;
	}

	LSystemProduction::~LSystemProduction()
	{
		delete predecessor;
		clearSuccessor();
	}

	const LSystemSymbol* LSystemProduction::getPredecessor() const
	{
		return predecessor;
	}

	const std::vector<LSystemSymbol *>& LSystemProduction::getSuccessor() const
	{
		return successor;
	}

	void LSystemProduction::addSymbolToSuccessor(LSystemSymbol *lSym)
	{
		if (lSym)
			successor.push_back(lSym);
	}

	void LSystemProduction::setSuccessor(const std::vector<LSystemSymbol *>& succ)
	{
		clearSuccessor();
		successor = succ;
	}

	float LSystemProduction::getProbability() const
	{
		return probability;
	}

	void LSystemProduction::setProbability(float prob)
	{
		if (prob > 0.0f && prob <= 1.0f)
			probability = prob;
	}

	bool LSystemProduction::condition(const LSystemSymbol *pred, const std::map<char, float>& globalParams) const
	{
		return true;
	}

	void LSystemProduction::generateSuccessor(const LSystemSymbol *pred, const std::map<char, float>& globalParams,
		std::vector<LSystemSymbol *>& word) const
	{
		for (LSystemSymbol *sym : successor)
			word.push_back(new LSystemSymbol(*sym));
	}

	std::string LSystemProduction::toString() const
	{
		std::string ret(predecessor->toString());
		ret += " -";
		if (probability < 1.0f)
		{
			ret += '[';
			ret += std::to_string(std::round(probability * 100));
			ret += ']';
		}
		ret += "-> ";
		for (const LSystemSymbol *sym : successor)
			ret += sym->toString();
		ret += '\n';

		return ret;
	}

	std::ostream& operator<<(std::ostream& out, const LSystemProduction& lProd)
	{
		out << lProd.toString();
		return out;
	}

}
