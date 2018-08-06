#ifndef LSYSTEM_H
#define LSYSTEM_H

#include "LSystemProdRule.h"
#include <functional>

class LSystem
{
protected:
	std::vector<LSystemSymbol *> axiom;
	std::vector<LSystemProdRule *> rules;
	std::map<char, float> params;
	std::map<LSystemSymbol *, std::function<void(float)>> actions;
	std::vector<std::vector<LSystemSymbol *>> produced;

public:
	LSystem();
	virtual ~LSystem();
	int getCurrentLevel() const;
	void addSymbolToAxiom(LSystemSymbol *sym);
	void addRule(LSystemProdRule *rule);
	float getParam(char param);
	void setParam(char param, float value);
	void derive(unsigned char level);
	std::vector<LSystemSymbol *> derive();
	LSystemProdRule* pickRule(LSystemSymbol *sym);

	std::vector<LSystemSymbol *>& operator[](size_t level);

	virtual std::string toString() const;
	friend std::ostream& operator<<(std::ostream& out, const LSystem& lSys);
};

#endif
