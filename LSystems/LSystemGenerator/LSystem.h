#ifndef LSYSTEM_H
#define LSYSTEM_H

#include "LSystemProduction.h"

namespace lsys
{

	class LSystem
	{
	private:
		void clearAxiom();
		void clearProductions();
		void clearSymbols();
		void copySymbols(const LSystem& lSys);
		void produceAxiom();

	protected:
		std::vector<LSystemSymbol *> axiom;
		std::vector<LSystemProduction *> productions;
		std::map<char, float> params;
		std::vector<std::vector<LSystemSymbol *>> products;

	public:
		LSystem() = default;
		LSystem(const LSystem& lSys);
		LSystem& operator=(const LSystem& lSys);
		virtual ~LSystem();

		size_t getCurrentLevel() const;
		const std::vector<LSystemSymbol *>& getAxiom() const;
		void addSymbolToAxiom(LSystemSymbol *lSym);
		void setAxiom(const std::vector<LSystemSymbol *>& ax);
		const std::vector<LSystemProduction *>& getProductions() const;
		void addProduction(LSystemProduction *prod);
		void setProductions(const std::vector<LSystemProduction *>& prods);
		float getParam(char param);
		void setParam(char param, float value);
		const std::vector<LSystemSymbol *>& operator[](size_t level);

		std::vector<LSystemSymbol *>& derive();
		std::vector<LSystemSymbol *>& derive(size_t level);
		LSystemProduction* matchProduction(LSystemSymbol *lSym) const;

		virtual std::string toString() const;
		friend std::ostream& operator<<(std::ostream& out, const LSystem& lSys);
	};

}

#endif
