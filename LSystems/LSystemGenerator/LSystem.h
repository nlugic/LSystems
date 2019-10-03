#ifndef LSYSTEM_H
#define LSYSTEM_H

#include "LSystemProduction.h"

namespace lhelp
{

	void clearProductions(std::vector<lsys::LSystemProduction *>& prods);
	void clearProductionsAndFreeMemory(std::vector<lsys::LSystemProduction *>& prods);

}

namespace lsys
{

	class LSystem
	{
	private:
		void produceAxiom();

	protected:
		std::map<char, float> params;
		std::vector<LSystemSymbol *> axiom;
		std::vector<LSystemProduction *> productions;
		std::vector<std::vector<LSystemSymbol *>> products;

	public:
		inline LSystem() = default;
		LSystem(const LSystem& sys);
		friend void swap(LSystem& sys_1, LSystem& sys_2);
		inline LSystem(LSystem&& sys) noexcept { swap(*this, sys); }
		inline LSystem& operator=(LSystem sys) noexcept { swap(*this, sys); return *this; }
		inline virtual LSystem *clone() const { return new LSystem(*this); }
		virtual ~LSystem();

		std::size_t getCurrentLevel() const;
		float getParam(char param) const;
		inline void setParam(char param, float value) { params[param] = value; }
		inline const std::vector<LSystemSymbol *>& getAxiom() const { return axiom; }
		inline void addSymbolToAxiom(LSystemSymbol *sym) { if (sym) axiom.push_back(sym); }
		inline void setAxiom(const std::vector<LSystemSymbol *>& ax) { lhelp::clearSymbols(axiom); axiom = ax; }
		inline const std::vector<LSystemProduction *>& getProductions() const { return productions; }
		inline void addProduction(LSystemProduction *prod) { if (prod) productions.push_back(prod); }
		inline void setProductions(const std::vector<LSystemProduction *>& prods)
			{ lhelp::clearProductions(productions); productions = prods; }
		const std::vector<LSystemSymbol *>& operator[](std::size_t level);

		virtual const std::vector<LSystemSymbol *>& derive();
		const std::vector<LSystemSymbol *>& derive(std::size_t level);
		LSystemProduction* matchProduction(const std::vector<LSystemSymbol *>& curr_level,
			const std::vector<LSystemSymbol *>::const_iterator& pred);

		virtual std::string toString() const;
		inline friend std::ostream& operator<<(std::ostream& out, const LSystem& sys)
			{ out << sys.toString(); return out; }
	};

}

#endif
