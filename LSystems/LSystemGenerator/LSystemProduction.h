#ifndef LSYSTEMPRODUCTION_H
#define LSYSTEMPRODUCTION_H

#include "LSystemSymbol.h"
#include <vector>

namespace lsys
{

	class LSystemProduction
	{
	private:
		void clearSymbols(std::vector<LSystemSymbol *>& syms);

	protected:
		LSystemSymbol *predecessor;
		std::vector<LSystemSymbol *> leftContext, rightContext;
		std::vector<LSystemSymbol *> successor;
		float probability;

	public:
		LSystemProduction(LSystemSymbol *pred, float prob = 1.0f);
		LSystemProduction(char pred, float prob = 1.0f);
		friend void swap(LSystemProduction& lProd1, LSystemProduction& lProd2);
		LSystemProduction(const LSystemProduction& lProd);
		LSystemProduction(LSystemProduction&& lProd) noexcept;
		LSystemProduction& operator=(LSystemProduction lProd) noexcept;
		virtual ~LSystemProduction();

		const LSystemSymbol* getPredecessor() const;
		const std::vector<LSystemSymbol *>& getLeftContext() const;
		const std::vector<LSystemSymbol *>& getRightContext() const;
		const std::vector<LSystemSymbol *>& getSuccessor() const;
		void addSymbolToLeftContext(LSystemSymbol *lSym);
		void setLeftContext(const std::vector<LSystemSymbol *>& lCxt);
		void addSymbolToRightContext(LSystemSymbol *lSym);
		void setRightContext(const std::vector<LSystemSymbol *>& rCxt);
		void addSymbolToSuccessor(LSystemSymbol *lSym);
		void setSuccessor(const std::vector<LSystemSymbol *>& succ);
		float getProbability() const;

		virtual bool condition(const LSystemSymbol *pred, const std::map<char, float>& globalParams) const;
		virtual void generateSuccessor(const LSystemSymbol *pred, const std::map<char, float>& globalParams,
			std::vector<LSystemSymbol *>& word) const;

		virtual std::string toString() const;
		friend std::ostream& operator<<(std::ostream& out, const LSystemProduction& lProd);
	};

}

#endif
