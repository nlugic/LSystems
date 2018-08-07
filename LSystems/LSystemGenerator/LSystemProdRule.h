#ifndef LSYSTEMPRODRULE_H
#define LSYSTEMPRODRULE_H

#include "LSystemSymbol.h"
#include <vector>

// difoltni konstruktor?
// konstruktor koji od pointera pravi drugi objekat, za rewriteSymbol i slicno
// rewriteSymbol mesto?
// destruktor, copy, move?

namespace lsys
{

	class LSystemProdRule
	{
	protected:
		LSystemSymbol *symbol;
		std::vector<LSystemSymbol *> product;
		float probability;

	public:
		LSystemProdRule(LSystemSymbol *w, std::vector<LSystemSymbol *> pRes, float p = 1.0f);
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
