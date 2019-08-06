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
		std::vector<LSystemSymbol *> left_context, right_context, successor;
		float probability;

	public:
		LSystemProduction(LSystemSymbol *pred, float prob = 1.0f);
		LSystemProduction(char pred, float prob = 1.0f);
		LSystemProduction(const LSystemProduction& prod);
		friend void swap(LSystemProduction& prod_1, LSystemProduction& prod_2);
		LSystemProduction(LSystemProduction&& prod) noexcept;
		LSystemProduction& operator=(LSystemProduction prod) noexcept;
		virtual LSystemProduction *clone() const;
		virtual ~LSystemProduction();

		const LSystemSymbol* getPredecessor() const;
		const std::vector<LSystemSymbol *>& getLeftContext() const;
		const std::vector<LSystemSymbol *>& getRightContext() const;
		const std::vector<LSystemSymbol *>& getSuccessor() const;
		void addSymbolToLeftContext(LSystemSymbol *sym);
		void setLeftContext(const std::vector<LSystemSymbol *>& l_cxt);
		void addSymbolToRightContext(LSystemSymbol *sym);
		void setRightContext(const std::vector<LSystemSymbol *>& r_cxt);
		void addSymbolToSuccessor(LSystemSymbol *sym);
		void setSuccessor(const std::vector<LSystemSymbol *>& succ);
		float getProbability() const;

		virtual bool condition(const LSystemSymbol *pred, const std::map<char, float>& global_params) const;
		virtual void generateSuccessor(const LSystemSymbol *pred, const std::map<char, float>& global_params,
			std::vector<LSystemSymbol *>& word) const;

		virtual std::string toString() const;
		friend std::ostream& operator<<(std::ostream& out, const LSystemProduction& prod);
	};

}

#endif
