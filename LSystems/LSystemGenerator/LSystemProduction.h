#ifndef LSYSTEMPRODUCTION_H
#define LSYSTEMPRODUCTION_H

#include "LSystemSymbol.h"
#include "..\..\include\glm\glm.hpp"
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
		LSystemProduction() = delete;
		inline LSystemProduction(LSystemSymbol *pred, float prob = 1.0f)
			:predecessor(pred), probability(glm::clamp(prob, 0.0f, 1.0f)) { }
		inline LSystemProduction(char pred, float prob = 1.0f)
			:predecessor(new LSystemSymbol(pred)), probability(glm::clamp(prob, 0.0f, 1.0f)) { }
		LSystemProduction(const LSystemProduction& prod);
		friend void swap(LSystemProduction& prod_1, LSystemProduction& prod_2);
		inline LSystemProduction(LSystemProduction&& prod) noexcept { swap(*this, prod); }
		inline LSystemProduction& operator=(LSystemProduction prod) noexcept { swap(*this, prod); return *this; }
		inline virtual LSystemProduction *clone() const { return new LSystemProduction(*this); }
		virtual ~LSystemProduction();

		inline const LSystemSymbol* getPredecessor() const { return predecessor; }
		inline const std::vector<LSystemSymbol *>& getLeftContext() const { return left_context; }
		inline const std::vector<LSystemSymbol *>& getRightContext() const { return right_context; }
		inline const std::vector<LSystemSymbol *>& getSuccessor() const { return successor; }
		inline void addSymbolToLeftContext(LSystemSymbol *sym) { if (sym) left_context.push_back(sym); }
		inline void setLeftContext(const std::vector<LSystemSymbol *>& l_cxt)
			{ clearSymbols(left_context); left_context = l_cxt; }
		inline void addSymbolToRightContext(LSystemSymbol *sym) { if (sym) right_context.push_back(sym); }
		inline void setRightContext(const std::vector<LSystemSymbol *>& r_cxt)
			{ clearSymbols(right_context); right_context = r_cxt; }
		inline void addSymbolToSuccessor(LSystemSymbol *sym) { if (sym) successor.push_back(sym); }
		inline void setSuccessor(const std::vector<LSystemSymbol *>& succ)
			{ clearSymbols(successor); successor = succ; }
		inline float getProbability() const { return probability; }

		inline virtual bool condition(const LSystemSymbol *pred, const std::map<char, float>& global_params) const
			{ return true; }
		virtual void generateSuccessor(const LSystemSymbol *pred, const std::map<char, float>& global_params,
			std::vector<LSystemSymbol *>& word) const;

		virtual std::string toString() const;
		inline friend std::ostream& operator<<(std::ostream& out, const LSystemProduction& prod)
			{ out << prod.toString(); return out; }
	};

}

#endif
