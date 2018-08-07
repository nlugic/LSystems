
#include "LSystemProdRule.h"

namespace lsys
{

	LSystemProdRule::LSystemProdRule(LSystemSymbol *sym, std::vector<LSystemSymbol *> pRes, float p = 1.0f)
		:symbol(sym), product(pRes), probability(p) { }

	LSystemProdRule::~LSystemProdRule() { }

	void LSystemProdRule::addSymbolToProduct(LSystemSymbol *sym)
	{
		product.push_back(sym);
	}

	const LSystemSymbol* LSystemProdRule::getSymbol() const
	{
		return symbol;
	}

	float LSystemProdRule::getProbability() const
	{
		return probability;
	}

	void LSystemProdRule::setProbability(float prob)
	{
		if (prob >= 0.0f && prob <= 1.0f)
			probability = prob;
	}

	bool LSystemProdRule::condition() const
	{
		return true;
	}

	void LSystemProdRule::rewriteSymbol(const LSystemSymbol* sym, std::vector<LSystemSymbol *>& res) const
	{
		if (!condition() || *symbol != *sym)
			return;
		else
			for (LSystemSymbol *sym : product)
				res.push_back(sym);
	}

	std::string LSystemProdRule::toString() const
	{
		std::string ret = symbol->toString();
		ret += " --";
		if (probability < 1.0f)
		{
			ret += '[';
			ret += std::round(probability * 100);
			ret += ']';
		}
		ret += "-> ";
		for (LSystemSymbol *sym : product)
			ret += sym->toString();
		ret += '\n';

		return ret;
	}

	std::ostream& operator<<(std::ostream& out, const LSystemProdRule& lRul)
	{
		out << lRul.toString();
		return out;
	}

}
