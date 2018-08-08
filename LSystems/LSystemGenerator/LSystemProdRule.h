#ifndef LSYSTEMPRODRULE_H
#define LSYSTEMPRODRULE_H

#include "LSystemSymbol.h"
#include <vector>

// rewriteSymbol mesto i funkcija?
// move?

namespace lsys
{

	class LSystemProdRule
	{
	protected:
		LSystemSymbol *symbol;
		std::vector<LSystemSymbol *> product;
		float probability;

	public:
		LSystemProdRule(LSystemSymbol *sym, std::vector<LSystemSymbol *> prod, float p = 1.0f);
		LSystemProdRule(LSystemSymbol *sym, float p = 1.0f);
		LSystemProdRule(char sym, std::vector<LSystemSymbol *> prod, float p = 1.0f);
		LSystemProdRule(char sym, float p = 1.0f);
		LSystemProdRule(const LSystemProdRule& rule);
		LSystemProdRule& operator=(const LSystemProdRule& rule);
		virtual ~LSystemProdRule();

		void addSymbolToProduct(LSystemSymbol *sym);
		const LSystemSymbol* getSymbol() const;
		float getProbability() const;
		void setProbability(float prob);
		virtual bool condition() const;
		virtual void rewriteSymbol(const LSystemSymbol* lSym, std::vector<LSystemSymbol *>& res) const;

		virtual std::string toString() const;
		friend std::ostream& operator<<(std::ostream& out, const LSystemProdRule& rule);
	};

}

#endif
