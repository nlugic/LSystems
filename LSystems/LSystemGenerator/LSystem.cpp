
#include "LSystem.h"

namespace lsys
{

	void LSystem::clearSymbols()
	{
		for (LSystemSymbol *sym : axiom)
			delete sym;
		for (LSystemProdRule *rule : rules)
			delete rule;
		for (std::vector<LSystemSymbol *>& product : products)
			for (LSystemSymbol *sym : product)
				delete sym;
		axiom.clear();
		rules.clear();
		products.clear();
	}

	void LSystem::copySymbols(const LSystem& lSys)
	{
		for (const LSystemSymbol *sym : lSys.axiom)
			axiom.push_back(new LSystemSymbol(*sym));
		for (const LSystemProdRule *rule : lSys.rules)
			rules.push_back(new LSystemProdRule(*rule));
		for (const std::vector<LSystemSymbol *>& product : lSys.products)
		{
			std::vector<LSystemSymbol *> prod;
			for (LSystemSymbol *sym : product)
				prod.push_back(new LSystemSymbol(*sym));
			products.push_back(prod);
		}
	}

	void LSystem::produceAxiom()
	{
		std::vector<LSystemSymbol *> prod;
		for (LSystemSymbol *sym : axiom)
			prod.push_back(new LSystemSymbol(*sym));
		products.push_back(prod);
	}

	LSystem::LSystem() { }

	LSystem::LSystem(const char *params)
	{
		for (const char *c = params; *c != '\0'; ++c)
			createParam(*c);
	}

	LSystem::LSystem(const LSystem& lSys)
		:params(lSys.params)
	{
		copySymbols(lSys);
	}

	LSystem& LSystem::operator=(const LSystem& lSys)
	{
		if (this != &lSys)
		{
			clearSymbols();
			copySymbols(lSys);

			params = lSys.params;
		}
		return *this;
	}

	LSystem::~LSystem()
	{
		clearSymbols();
	}

	int LSystem::getCurrentLevel() const
	{
		return products.size();
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
		if (params.find(param) != params.end())
			return params[param];
		return NAN;
	}

	void LSystem::setParam(char param, float value)
	{
		params[param] = value;
	}

	void LSystem::createParam(char param)
	{
		params[param] = NAN;
	}

	std::vector<LSystemSymbol *>& LSystem::derive(unsigned char level)
	{
		while (level-- > 1)
			derive();
		return derive();
	}

	std::vector<LSystemSymbol *>& LSystem::derive()
	{
		if (!products.size())
			produceAxiom();
		
		std::vector<LSystemSymbol *>& currentLevel = products[products.size() - 1];
		std::vector<LSystemSymbol *> newLevel;

		for (LSystemSymbol *sym : currentLevel)
		{
			LSystemProdRule *rule = pickRule(sym);

			if (rule == nullptr)
			{
				newLevel.push_back(new LSystemSymbol(*sym));
				continue;
			}
			else
				rule->rewriteSymbol(sym, newLevel);
		}

		products.push_back(newLevel);
		return newLevel;
	}

	LSystemProdRule* LSystem::pickRule(LSystemSymbol *sym) const
	{
		std::vector<LSystemProdRule *> candidates;

		for (LSystemProdRule *rule : rules)
		{
			if (*rule->getSymbol() == *sym && rule->condition())
				candidates.push_back(rule);
		}

		if (candidates.size() == 1)
			return candidates[0];
		else
		{
			float prob = (float)std::rand() / RAND_MAX, totalProb = 0.0f;

			for (LSystemProdRule *rule : candidates)
				if (prob <= (totalProb += rule->getProbability()))
					return rule;
		}

		return nullptr;
	}

	std::vector<LSystemSymbol *>& LSystem::operator[](unsigned char level)
	{
		try { return products.at(level); }
		catch (std::out_of_range& err)
		{
			std::cerr << err.what() << std::endl;
			if (!products.size())
				produceAxiom();

			return products[0];
		}
	}

	std::string LSystem::toString() const
	{
		std::string ret = "A:\t";
		for (LSystemSymbol *s : axiom)
			ret += s->toString();
		ret += '\n';
		unsigned short no = 1;
		for (LSystemProdRule *pr : rules)
		{
			ret += 'P';	ret += std::to_string(no++); ret += ":\t";
			ret += pr->toString();
		}
		return ret;
	}

	std::ostream& operator<<(std::ostream& out, const LSystem& lSys)
	{
		out << lSys.toString();
		return out;
	}

}
