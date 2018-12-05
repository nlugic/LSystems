#ifndef LSYSTEM_H
#define LSYSTEM_H

#include "LSystemProduction.h"

namespace lsys
{

	const float epsilon = 1e-5f;

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
		friend void swap(LSystem& lSys1, LSystem& lSys2);
		LSystem(const LSystem& lSys);
		LSystem(LSystem&& lSys) noexcept;
		LSystem& operator=(LSystem lSys) noexcept;
		virtual ~LSystem();

		std::size_t getCurrentLevel() const;
		float getParam(char param) const;
		void setParam(char param, float value);
		const std::vector<LSystemSymbol *>& getAxiom() const;
		void addSymbolToAxiom(LSystemSymbol *lSym);
		void setAxiom(const std::vector<LSystemSymbol *>& ax);
		const std::vector<LSystemProduction *>& getProductions() const;
		void addProduction(LSystemProduction *prod);
		void setProductions(const std::vector<LSystemProduction *>& prods);
		const std::vector<LSystemSymbol *>& operator[](std::size_t level);

		virtual const std::vector<LSystemSymbol *>& derive();
		const std::vector<LSystemSymbol *>& derive(std::size_t level);
		LSystemProduction* matchProduction(LSystemSymbol *pred);

		virtual std::string toString() const;
		friend std::ostream& operator<<(std::ostream& out, const LSystem& lSys);
	};

}

#endif
