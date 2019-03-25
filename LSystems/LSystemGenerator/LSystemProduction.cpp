
#include "LSystemProduction.h"

namespace lsys
{

	void LSystemProduction::clearSymbols(std::vector<LSystemSymbol *>& syms)
	{
		for (LSystemSymbol *sym : syms)
			delete sym;
		syms.clear();
	}

	LSystemProduction::LSystemProduction(LSystemSymbol *pred, float prob)
		:predecessor(pred), probability((prob < 0.0f || prob > 1.0f) ? 1.0f : prob) { }

	LSystemProduction::LSystemProduction(char pred, float prob)
		:predecessor(new LSystemSymbol(pred)), probability((prob < 0.0f || prob > 1.0f) ? 1.0f : prob) { }

	void swap(LSystemProduction& lProd1, LSystemProduction& lProd2)
	{
		std::swap(lProd1.predecessor, lProd2.predecessor);
		std::swap(lProd1.leftContext, lProd2.leftContext);
		std::swap(lProd1.rightContext, lProd2.rightContext);
		std::swap(lProd1.successor, lProd2.successor);
	}

	LSystemProduction::LSystemProduction(const LSystemProduction& lProd)
		:predecessor(new LSystemSymbol(*lProd.predecessor)), probability(lProd.probability)
	{
		for (const LSystemSymbol *sym : lProd.leftContext)
			leftContext.push_back(new LSystemSymbol(*sym));
		for (const LSystemSymbol *sym : lProd.rightContext)
			rightContext.push_back(new LSystemSymbol(*sym));
		for (const LSystemSymbol *sym : lProd.successor)
			successor.push_back(new LSystemSymbol(*sym));
	}

	LSystemProduction::LSystemProduction(LSystemProduction&& lProd) noexcept
	{
		swap(*this, lProd);
	}

	LSystemProduction& LSystemProduction::operator=(LSystemProduction lProd) noexcept
	{
		swap(*this, lProd);
		return *this;
	}

	LSystemProduction::~LSystemProduction()
	{
		delete predecessor;
		clearSymbols(leftContext);
		clearSymbols(rightContext);
		clearSymbols(successor);
	}

	const LSystemSymbol* LSystemProduction::getPredecessor() const
	{
		return predecessor;
	}

	const std::vector<LSystemSymbol *>& LSystemProduction::getLeftContext() const
	{
		return leftContext;
	}

	const std::vector<LSystemSymbol *>& LSystemProduction::getRightContext() const
	{
		return rightContext;
	}

	const std::vector<LSystemSymbol *>& LSystemProduction::getSuccessor() const
	{
		return successor;
	}

	void LSystemProduction::addSymbolToLeftContext(LSystemSymbol *lSym)
	{
		if (lSym)
			leftContext.push_back(lSym);
	}

	void LSystemProduction::setLeftContext(const std::vector<LSystemSymbol *>& lCxt)
	{
		clearSymbols(leftContext);
	}

	void LSystemProduction::addSymbolToRightContext(LSystemSymbol *lSym)
	{
		if (lSym)
			rightContext.push_back(lSym);
	}

	void LSystemProduction::setRightContext(const std::vector<LSystemSymbol *>& rCxt)
	{
		clearSymbols(rightContext);
	}

	void LSystemProduction::addSymbolToSuccessor(LSystemSymbol *lSym)
	{
		if (lSym)
			successor.push_back(lSym);
	}

	void LSystemProduction::setSuccessor(const std::vector<LSystemSymbol *>& succ)
	{
		clearSymbols(successor);
		successor = succ;
	}

	float LSystemProduction::getProbability() const
	{
		return probability;
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
		std::string ret;

		for (const LSystemSymbol *sym : leftContext)
			ret += sym->toString();
		if (!leftContext.empty())
			ret += " < ";

		ret += predecessor->toString();

		if (!rightContext.empty())
			ret += " > ";
		for (const LSystemSymbol *sym : rightContext)
			ret += sym->toString();

		ret += " -";
		if (probability < 1.0f)
		{
			ret += '[';
			ret += std::to_string(probability * 100.0f);
			ret += "%]";
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
