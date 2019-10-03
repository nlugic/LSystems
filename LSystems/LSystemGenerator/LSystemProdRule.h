#ifndef LSYSTEMPRODRULE_H
#define LSYSTEMPRODRULE_H

#include "LSystemSymbol.h"
#include <vector>

class LSystemProdRule
{
protected:
	LSystemSymbol *word;
	std::vector<LSystemSymbol *> possibleResult;
	float probability;

public:

	LSystemProdRule(LSystemSymbol *w, std::vector<LSystemSymbol *> pRes, float p = 1.0f);
	virtual ~LSystemProdRule();
	void addSymbolToResult(LSystemSymbol *sym);
	float getProbability() const;
	void setProbability(float prob);
	virtual bool condition();
	virtual void rewriteSymbol(const LSystemSymbol* lSym, std::vector<LSystemSymbol *>& res);
	
	bool matchSymbol(LSystemSymbol *sym);

	virtual std::string toString() const;
	friend std::ostream& operator<<(std::ostream& out, const LSystemProdRule& rule);
};

#endif
