#ifndef LSYSTEMPRODRULE_H
#define LSYSTEMPRODRULE_H

#include "LSystemSymbol.h"
#include <vector>

namespace lsys
{

	class LSystemProdRule
	{
	private:
		void clearProduct();

	protected:
		LSystemSymbol *symbol;
		std::vector<LSystemSymbol *> product;
		float probability;

	public:
		LSystemProdRule(LSystemSymbol *lSym, std::vector<LSystemSymbol *> prod, float p = 1.0f);
		LSystemProdRule(LSystemSymbol *lSym, float p = 1.0f);
		LSystemProdRule(char sym, std::vector<LSystemSymbol *> prod, float p = 1.0f);
		LSystemProdRule(char sym, float p = 1.0f);
		LSystemProdRule(const LSystemProdRule& lRul);
		LSystemProdRule& operator=(const LSystemProdRule& lRul);
		virtual ~LSystemProdRule();

		const LSystemSymbol* getSymbol() const;
		const std::vector<LSystemSymbol *>& getProduct() const;
		void addSymbolToProduct(LSystemSymbol *lSym);
		void setProduct(const std::vector<LSystemSymbol *>& prod);
		float getProbability() const;
		void setProbability(float prob);
		virtual bool condition() const;

		virtual std::string toString() const;
		friend std::ostream& operator<<(std::ostream& out, const LSystemProdRule& lRul);
	};

}

#endif
