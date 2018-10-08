#ifndef LSYSTEMPRODUCTION_H
#define LSYSTEMPRODUCTION_H

#include "LSystemSymbol.h"
#include <vector>

namespace lsys
{

	class LSystemProduction
	{
	private:
		void clearSuccessor();

	protected:
		LSystemSymbol *predecessor;
		std::vector<LSystemSymbol *> successor;
		float probability;

	public:
		LSystemProduction(LSystemSymbol *pred, float prob = 1.0f);
		LSystemProduction(char pred, float prob = 1.0f);
		LSystemProduction(const LSystemProduction& lProd);
		LSystemProduction& operator=(const LSystemProduction& lProd);
		virtual ~LSystemProduction();

		const LSystemSymbol* getPredecessor() const;
		virtual const std::vector<LSystemSymbol *>& getSuccessor(const LSystemSymbol *lSym = nullptr);
		void addSymbolToSuccessor(LSystemSymbol *lSym);
		void setSuccessor(const std::vector<LSystemSymbol *>& succ);
		float getProbability() const;
		void setProbability(float prob);
		virtual bool condition() const;

		virtual std::string toString() const;
		friend std::ostream& operator<<(std::ostream& out, const LSystemProduction& lProd);
	};

}

#endif
