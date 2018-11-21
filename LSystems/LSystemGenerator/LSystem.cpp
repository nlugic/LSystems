
#include "LSystem.h"
#include "ConsoleProgressBar.h"

namespace lsys
{

	void LSystem::clearAxiom()
	{
		for (LSystemSymbol *sym : axiom)
			delete sym;
		axiom.clear();
	}

	void LSystem::clearProductions()
	{
		for (LSystemProduction *prod : productions)
			delete prod;
		productions.clear();
	}

	void LSystem::clearSymbols()
	{
		clearAxiom();
		clearProductions();
		for (std::vector<LSystemSymbol *>& product : products)
			for (LSystemSymbol *sym : product)
				delete sym;
		products.clear();
	}

	void LSystem::copySymbols(const LSystem& lSys)
	{
		for (const LSystemSymbol *sym : lSys.axiom)
			axiom.push_back(new LSystemSymbol(*sym));
		for (const LSystemProduction *prod : lSys.productions)
			productions.push_back(new LSystemProduction(*prod));
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

	std::size_t LSystem::getCurrentLevel() const
	{
		std::size_t level = products.size();
		return (level > 0) ? level - 1 : level;
	}

	float LSystem::getParam(char param) const
	{
		if (params.count(param))
			return params.at(param);
		return NAN;
	}

	void LSystem::setParam(char param, float value)
	{
		params[param] = value;
	}

	const std::vector<LSystemSymbol *>& LSystem::getAxiom() const
	{
		return axiom;
	}

	void LSystem::addSymbolToAxiom(LSystemSymbol *lSym)
	{
		if (lSym)
			axiom.push_back(lSym);
	}

	void LSystem::setAxiom(const std::vector<LSystemSymbol *>& ax)
	{
		clearAxiom();
		axiom = ax;
	}

	const std::vector<LSystemProduction *>& LSystem::getProductions() const
	{
		return productions;
	}

	void LSystem::addProduction(LSystemProduction *prod)
	{
		if (prod)
			productions.push_back(prod);
	}

	void LSystem::setProductions(const std::vector<LSystemProduction *>& prods)
	{
		clearProductions();
		productions = prods;
	}

	const std::vector<LSystemSymbol *>& LSystem::operator[](std::size_t level)
	{
		try { return products.at(level); }
		catch (const std::out_of_range&)
		{
			if (products.empty())
				produceAxiom();

			return products[products.size() - 1];
		}
	}

	const std::vector<LSystemSymbol *>& LSystem::derive()
	{
		if (products.empty())
			produceAxiom();

		const std::vector<LSystemSymbol *>& currentLevel = products[products.size() - 1ULL];
		std::vector<LSystemSymbol *> newLevel;

		lsysh::ConsoleProgressBar symbolDerivation(currentLevel.size());

		for (LSystemSymbol *sym : currentLevel)
		{
			LSystemProduction *matchedProd = matchProduction(sym);

			if (!matchedProd)
				newLevel.push_back(new LSystemSymbol(*sym));
			else
				matchedProd->generateSuccessor(sym, params, newLevel);

			symbolDerivation.step();
		}
		symbolDerivation.finish();

		products.push_back(newLevel);
		return products[products.size() - 1ULL];
	}

	const std::vector<LSystemSymbol *>& LSystem::derive(std::size_t level)
	{
		std::size_t curr = getCurrentLevel() + 1ULL;

		while (--level)
		{
			std::cout << "Deriving level " << curr++ << "..." << std::endl;
			derive();
		}

		std::cout << "Deriving level " << curr << "..." << std::endl;
		return derive();
	}

	LSystemProduction* LSystem::matchProduction(LSystemSymbol *pred)
	{
		std::vector<LSystemProduction *> candidates;

		for (LSystemProduction *prod : productions)
			if (*prod->getPredecessor() == *pred && prod->condition(pred, params))
				candidates.push_back(prod);

		if (candidates.size() == 1)
			return candidates[0];
		else
		{
			float prob = (float)std::rand() / RAND_MAX, totalProb = 0.0f;

			for (LSystemProduction *prod : candidates)
				if (prob <= (totalProb += prod->getProbability()))
					return prod;
		}

		return nullptr;
	}

	std::string LSystem::toString() const
	{
		std::string ret("A:\t");
		for (LSystemSymbol *sym : axiom)
			ret += sym->toString();
		ret += '\n';
		unsigned short no = 1;
		for (LSystemProduction *prod : productions)
		{
			ret += 'P';	ret += std::to_string(no++); ret += ":\t";
			ret += prod->toString();
		}
		return ret;
	}

	std::ostream& operator<<(std::ostream& out, const LSystem& lSys)
	{
		out << lSys.toString();
		return out;
	}

}
