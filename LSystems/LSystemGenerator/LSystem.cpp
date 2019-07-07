
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

	void LSystem::produceAxiom()
	{
		std::vector<LSystemSymbol *> prod;
		for (LSystemSymbol *sym : axiom)
			prod.push_back(new LSystemSymbol(*sym));
		products.push_back(prod);
	}

	void swap(LSystem& lSys1, LSystem& lSys2)
	{
		std::swap(lSys1.params, lSys2.params);
		std::swap(lSys1.axiom, lSys2.axiom);
		std::swap(lSys1.productions, lSys2.productions);
		std::swap(lSys1.products, lSys2.products);
	}

	LSystem::LSystem(const LSystem& lSys)
		:params(lSys.params)
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

	LSystem::LSystem(LSystem&& lSys) noexcept
	{
		swap(*this, lSys);
	}

	LSystem& LSystem::operator=(LSystem lSys) noexcept
	{
		swap(*this, lSys);
		return *this;
	}

	LSystem::~LSystem()
	{
		clearAxiom();
		clearProductions();
		for (std::vector<LSystemSymbol *>& product : products)
			for (LSystemSymbol *sym : product)
				delete sym;
		products.clear();
	}

	std::size_t LSystem::getCurrentLevel() const
	{
		std::size_t level = products.size();
		return (level > 0) ? level - 1 : level;
	}

	float LSystem::getParam(char param) const
	{
		if (params.find(param) != params.end())
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

#if defined(_DEBUG) || defined(_VERBOSE)
		lsysh::ConsoleProgressBar symbolDerivation(currentLevel.size());
#endif

		for (std::vector<LSystemSymbol *>::const_iterator& sym = currentLevel.begin(); sym != currentLevel.end(); ++sym)
		{
			LSystemProduction *matchedProd = matchProduction(currentLevel, sym);

			if (!matchedProd)
				newLevel.push_back(new LSystemSymbol(**sym));
			else
				matchedProd->generateSuccessor(*sym, params, newLevel);

#if defined(_DEBUG) || defined(_VERBOSE)
			symbolDerivation.step();
		}
		symbolDerivation.finish();
#else
		}
#endif

		products.push_back(newLevel);
		return products[products.size() - 1ULL];
	}

	const std::vector<LSystemSymbol *>& LSystem::derive(std::size_t level)
	{
#if defined(_DEBUG) || defined(_VERBOSE)
		std::size_t curr = getCurrentLevel() + 1ULL;

		while (--level)
		{
			std::clog << "Deriving level " << curr++ << "..." << std::endl;
			derive();
		}

		std::clog << "Deriving level " << curr << "..." << std::endl;
#else
		while (--level)
			derive();
#endif

		return derive();
	}

	LSystemProduction* LSystem::matchProduction(const std::vector<LSystemSymbol *>& currLevel, std::vector<LSystemSymbol *>::const_iterator& pred)
	{
		std::vector<LSystemProduction *> candidates;

		for (LSystemProduction *prod : productions)
		{
			if (*prod->getPredecessor() != **pred || !prod->condition(*pred, params))
				continue;

			long long predIndex = pred - currLevel.begin();
			const std::vector<LSystemSymbol *>& leftCxt = prod->getLeftContext();
			if (!leftCxt.empty())
			{
				long long left = predIndex - 1LL;

				while (left >= 0LL
					&& *currLevel[left] == *leftCxt[leftCxt.size() - predIndex + left])
					--left;
				if (predIndex - left != leftCxt.size() + 1ULL)
					continue;
			}

			const std::vector<LSystemSymbol *>& rightCxt = prod->getRightContext();
			if (!rightCxt.empty())
			{
				long long right = predIndex + 1LL;

				while (right < static_cast<long long>(currLevel.size())
					&& *currLevel[right] == *rightCxt[right - predIndex - 1LL])
					++right;
				if (right - predIndex != rightCxt.size() + 1ULL)
					continue;
			}

			candidates.push_back(prod);
		}

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
