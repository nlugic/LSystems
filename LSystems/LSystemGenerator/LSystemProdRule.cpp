
#include "LSystemProdRule.h"

namespace lsys
{

	LSystemProdRule::LSystemProdRule(LSystemSymbol *sym, std::vector<LSystemSymbol *> prod, float p)
		:symbol(sym), product(prod), probability(p) { }

	LSystemProdRule::LSystemProdRule(LSystemSymbol *sym, float p)
		:symbol(sym), probability(p) { }

	LSystemProdRule::LSystemProdRule(char sym, std::vector<LSystemSymbol *> prod, float p)
		:symbol(new LSystemSymbol(sym)), product(prod), probability(p) { }

	LSystemProdRule::LSystemProdRule(char sym, float p)
		:symbol(new LSystemSymbol(sym)), probability(p) { }

	LSystemProdRule::LSystemProdRule(const LSystemProdRule& rule)
		:symbol(new LSystemSymbol(*rule.symbol)), probability(rule.probability)
	{
		for (const LSystemSymbol *sym : rule.product)
			product.push_back(new LSystemSymbol(*sym));
	}

	LSystemProdRule& LSystemProdRule::operator=(const LSystemProdRule& rule)
	{
		if (this != &rule)
		{
			delete symbol;
			for (LSystemSymbol *sym : product)
				delete sym;
			product.clear();

			symbol = new LSystemSymbol(*rule.symbol);
			for (const LSystemSymbol* sym : rule.product)
				product.push_back(new LSystemSymbol(*sym));
			probability = rule.probability;
		}
		return *this;
	}

	LSystemProdRule::~LSystemProdRule()
	{
		delete symbol;
		for (LSystemSymbol *sym : product)
			delete sym;
	}

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
		for (const LSystemSymbol *sym : product)
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
