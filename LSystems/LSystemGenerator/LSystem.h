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
		void produceAxiom();

	protected:
		std::map<char, float> params;
		std::vector<LSystemSymbol *> axiom;
		std::vector<LSystemProduction *> productions;
		std::vector<std::vector<LSystemSymbol *>> products;

	public:
		LSystem() = default;
		LSystem(const LSystem& sys);
		friend void swap(LSystem& sys_1, LSystem& sys_2);
		LSystem(LSystem&& sys) noexcept;
		LSystem& operator=(LSystem sys) noexcept;
		virtual LSystem *clone() const;
		virtual ~LSystem();

		std::size_t getCurrentLevel() const;
		float getParam(char param) const;
		void setParam(char param, float value);
		const std::vector<LSystemSymbol *>& getAxiom() const;
		void addSymbolToAxiom(LSystemSymbol *sym);
		void setAxiom(const std::vector<LSystemSymbol *>& ax);
		const std::vector<LSystemProduction *>& getProductions() const;
		void addProduction(LSystemProduction *prod);
		void setProductions(const std::vector<LSystemProduction *>& prods);
		const std::vector<LSystemSymbol *>& operator[](std::size_t level);

		virtual const std::vector<LSystemSymbol *>& derive();
		const std::vector<LSystemSymbol *>& derive(std::size_t level);
		LSystemProduction* matchProduction(const std::vector<LSystemSymbol *>& currLevel,
			std::vector<LSystemSymbol *>::const_iterator& pred);

		virtual std::string toString() const;
		friend std::ostream& operator<<(std::ostream& out, const LSystem& sys);
	};

}

#endif
