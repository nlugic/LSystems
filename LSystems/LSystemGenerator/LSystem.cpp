
#include "LSystem.h"

LSystem::LSystem() { }

LSystem::~LSystem() { }

int LSystem::getCurrentLevel() const
{
	return produced.size();
}

void LSystem::addSymbolToAxiom(LSystemSymbol *sym)
{
	axiom.push_back(sym);
}

void LSystem::addRule(LSystemProdRule *rule)
{
	rules.push_back(rule);
}

float LSystem::getParam(char param)
{
	return params[param];
}

void LSystem::setParam(char param, float value)
{
	params[param] = value;
}

void LSystem::derive(unsigned char level)
{
	while (level-- > 0)
		derive();
}

std::vector<LSystemSymbol *> LSystem::derive()
{
	if (!produced.size())
		produced.push_back(axiom);

	std::vector<LSystemSymbol *>& currentLevel = produced[produced.size() - 1];
	std::vector<LSystemSymbol *> newLevel;

	for (LSystemSymbol *sym : currentLevel)
	{
		LSystemProdRule *rule = pickRule(sym);

		if (rule == nullptr)
		{
			newLevel.push_back(sym);
			continue;
		}
		else
			rule->rewriteSymbol(sym, newLevel);
	}

	produced.push_back(newLevel);
	return newLevel;
}

LSystemProdRule* LSystem::pickRule(LSystemSymbol *sym)
{
	std::vector<LSystemProdRule *> candidates;

	for (LSystemProdRule *rule : rules)
	{
		if (rule->matchSymbol(sym) && rule->condition())
			candidates.push_back(rule);
	}

	if (candidates.size() == 1)
		return candidates[0];
	else
	{
		float prob = (float)rand() / RAND_MAX;
		for (LSystemProdRule *rule : candidates)
			if (prob <= rule->getProbability())
				return rule;
	}

	return nullptr;
}

std::vector<LSystemSymbol *>& LSystem::operator[](size_t level)
{
	try	{ return produced.at(level); }
	catch (std::range_error& err) {	return produced[0];	}
}

std::string LSystem::toString() const
{
	std::string ret = "A: ";
	for (LSystemSymbol *s : axiom)
		ret += s->toString();
	ret += '\n';
	unsigned short no = 1;
	for (LSystemProdRule *pr : rules)
	{
		ret += 'P';	ret += no; ret += ": ";
		ret += pr->toString();
	}
	return ret;
}

std::ostream& operator<<(std::ostream& out, const LSystem& lSys)
{
	out << lSys.toString();
	return out;
}
