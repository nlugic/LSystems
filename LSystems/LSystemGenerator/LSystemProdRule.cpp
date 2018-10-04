
#include "LSystemProdRule.h"

namespace lsys
{

	void LSystemProdRule::clearProduct()
	{
		for (LSystemSymbol *sym : product)
			delete sym;
		product.clear();
	}

	LSystemProdRule::LSystemProdRule(LSystemSymbol *lSym, std::vector<LSystemSymbol *> prod, float p)
		:symbol(lSym), product(prod), probability(p) { }

	LSystemProdRule::LSystemProdRule(LSystemSymbol *lSym, float p)
		:symbol(lSym), probability(p) { }

	LSystemProdRule::LSystemProdRule(char sym, std::vector<LSystemSymbol *> prod, float p)
		:symbol(new LSystemSymbol(sym)), product(prod), probability(p) { }

	LSystemProdRule::LSystemProdRule(char sym, float p)
		:symbol(new LSystemSymbol(sym)), probability(p) { }

	LSystemProdRule::LSystemProdRule(const LSystemProdRule& lRul)
		:symbol(new LSystemSymbol(*lRul.symbol)), probability(lRul.probability)
	{
		for (const LSystemSymbol *sym : lRul.product)
			product.push_back(new LSystemSymbol(*sym));
	}

	LSystemProdRule& LSystemProdRule::operator=(const LSystemProdRule& lRul)
	{
		if (this != &lRul)
		{
			delete symbol;
			clearProduct();

			symbol = new LSystemSymbol(*lRul.symbol);
			for (const LSystemSymbol* sym : lRul.product)
				product.push_back(new LSystemSymbol(*sym));
			probability = lRul.probability;
		}
		return *this;
	}

	LSystemProdRule::~LSystemProdRule()
	{
		delete symbol;
		clearProduct();
	}

	const LSystemSymbol* LSystemProdRule::getSymbol() const
	{
		return symbol;
	}

	const std::vector<LSystemSymbol *>& LSystemProdRule::getProduct() const
	{
		return product;
	}

	void LSystemProdRule::addSymbolToProduct(LSystemSymbol *lSym)
	{
		product.push_back(lSym);
	}

	void LSystemProdRule::setProduct(const std::vector<LSystemSymbol *>& prod)
	{
		clearProduct();

		for (LSystemSymbol *sym : prod)
			product.push_back(new LSystemSymbol(*sym));
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

	std::string LSystemProdRule::toString() const
	{
		std::string ret(symbol->toString());
		ret += " -";
		if (probability < 1.0f)
		{
			ret += '[';
			ret += std::to_string(std::round(probability * 100));
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
