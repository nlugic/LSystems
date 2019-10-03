
#include "LSystemProdRule.h"

LSystemProdRule::LSystemProdRule(LSystemSymbol *w, std::vector<LSystemSymbol *> pRes, float p = 1.0f)
	:word(w), possibleResult(pRes), probability(p) { }

LSystemProdRule::~LSystemProdRule() { }

void LSystemProdRule::addSymbolToResult(LSystemSymbol *sym)
{
	possibleResult.push_back(sym);
}

float LSystemProdRule::getProbability() const
{
	return probability
}

void LSystemProdRule::setProbability(float prob)
{
	probability = prob;
}

bool LSystemProdRule::condition()
{
	return true;
}

void LSystemProdRule::rewriteSymbol(const LSystemSymbol* lSym, std::vector<LSystemSymbol *>& res)
{
	if (!condition() || (*word != *lSym))
		return;
	else
		for (LSystemSymbol *sym : possibleResult)
			res.push_back(sym);
}

bool LSystemProdRule::matchSymbol(LSystemSymbol *sym)
{
	return *word == *sym;
}

std::string LSystemProdRule::toString() const
{
	std::string ret = word->toString();
	ret += " --";
	if (probability < 1.0f)
	{
		ret += "[p = ";
		ret += probability;
		ret += ']';
	}
	ret += "-> ";
	for (LSystemSymbol *sym : possibleResult)
		ret += sym->toString();
	ret += '\n';
	return ret;
}

std::ostream& operator<<(std::ostream& out, const LSystemProdRule& lRul)
{
	out << lRul.toString();
	return out;
}
