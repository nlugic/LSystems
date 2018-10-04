#ifndef LSYSTEM_H
#define LSYSTEM_H

#include "LSystemProdRule.h"

namespace lsys
{

	class LSystem
	{
	private:
		void clearSymbols();
		void copySymbols(const LSystem& lSys);
		void produceAxiom();

	protected:
		std::vector<LSystemSymbol *> axiom;
		std::vector<LSystemProdRule *> rules;
		std::map<char, float> params;
		std::vector<std::vector<LSystemSymbol *>> products;

	public:
		LSystem();
		LSystem(const char *params);
		LSystem(const LSystem& lSys);
		LSystem& operator=(const LSystem& lSys);
		virtual ~LSystem();

		size_t getCurrentLevel() const;
		void addSymbolToAxiom(LSystemSymbol *lSym);
		void addRule(LSystemProdRule *lRul);
		float getParam(char param);
		void setParam(char param, float value);
		void createParam(char param);
		std::vector<LSystemSymbol *>& operator[](unsigned char level);
		
		std::vector<LSystemSymbol *>& derive(size_t level);
		std::vector<LSystemSymbol *>& derive();
		LSystemProdRule* pickRule(LSystemSymbol *lSym) const;

		virtual std::string toString() const;
		friend std::ostream& operator<<(std::ostream& out, const LSystem& lSys);
	};

}

#endif
