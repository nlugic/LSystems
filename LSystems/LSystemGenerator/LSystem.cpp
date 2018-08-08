
#include "LSystem.h"

namespace lsys
{

	LSystem::LSystem() { }

	LSystem::LSystem(const char *params)
	{
		for (const char *c = params; *c != '\0'; ++c)
			createParam(*c);
	}

	LSystem::LSystem(const LSystem& lSys)
		:params(lSys.params), actions(lSys.actions)
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

	LSystem& LSystem::operator=(const LSystem& lSys)
	{
		if (this != &lSys)
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

			for (const LSystemSymbol *sym : lSys.axiom)
				axiom.push_back(new LSystemSymbol(*sym));
			for (const LSystemProdRule *rule : lSys.rules)
				rules.push_back(new LSystemProdRule(*rule));
			params = lSys.params;
			actions = lSys.actions;
			for (const std::vector<LSystemSymbol *>& product : lSys.products)
			{
				std::vector<LSystemSymbol *> prod;
				for (LSystemSymbol *sym : product)
					prod.push_back(new LSystemSymbol(*sym));
				products.push_back(prod);
			}
		}
		return *this;
	}

	LSystem::~LSystem()
	{
		for (LSystemSymbol *sym : axiom)
			delete sym;
		for (LSystemProdRule *rule : rules)
			delete rule;
		for (std::vector<LSystemSymbol *>& product : products)
			for (LSystemSymbol *sym : product)
				delete sym;
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

	void LSystem::derive(unsigned char level)
	{
		while (level-- > 0)
			derive();
	}

	std::vector<LSystemSymbol *>& LSystem::derive()
	{
		if (!products.size())
			products.push_back(axiom);

		std::vector<LSystemSymbol *>& currentLevel = products[products.size() - 1];
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
		catch (std::range_error& err)
		{
			std::cerr << err.what() << std::endl;
			return products[0];
		}
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

}
