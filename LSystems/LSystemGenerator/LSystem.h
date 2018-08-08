#ifndef LSYSTEM_H
#define LSYSTEM_H

#include "LSystemProdRule.h"
#include <functional>

// move?
// akcije i njihovo mesto?
// random seed i odredjivanje pravila?

namespace lsys
{

	class LSystem
	{
	protected:
		std::vector<LSystemSymbol *> axiom;
		std::vector<LSystemProdRule *> rules;
		std::map<char, float> params;
		std::map<char, std::function<void(float)>> actions;
		std::vector<std::vector<LSystemSymbol *>> products;

	public:
		LSystem();
		LSystem(const char *params);
		LSystem(const LSystem& lSys);
		LSystem& operator=(const LSystem& lSys);
		virtual ~LSystem();

		int getCurrentLevel() const;
		void addSymbolToAxiom(LSystemSymbol *sym);
		void addRule(LSystemProdRule *rule);
		float getParam(char param);
		void setParam(char param, float value);
		void createParam(char param);
		std::vector<LSystemSymbol *>& operator[](unsigned char level);

		void derive(unsigned char level);
		std::vector<LSystemSymbol *>& derive();
		LSystemProdRule* pickRule(LSystemSymbol *sym) const;

		virtual std::string toString() const;
		friend std::ostream& operator<<(std::ostream& out, const LSystem& lSys);
	};

}

#endif
