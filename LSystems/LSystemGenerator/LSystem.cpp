
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
			prod.push_back(sym->clone());
		products.push_back(prod);
	}

	LSystem::LSystem(const LSystem& sys)
		:params(sys.params)
	{
		for (const LSystemSymbol *sym : sys.axiom)
			axiom.push_back(sym->clone());
		for (const LSystemProduction *prod : sys.productions)
			productions.push_back(prod->clone());
		for (const std::vector<LSystemSymbol *>& product : sys.products)
		{
			std::vector<LSystemSymbol *> prod;
			for (LSystemSymbol *sym : product)
				prod.push_back(sym->clone());
			products.push_back(prod);
		}
	}

	void swap(LSystem& sys_1, LSystem& sys_2)
	{
		std::swap(sys_1.params, sys_2.params);
		std::swap(sys_1.axiom, sys_2.axiom);
		std::swap(sys_1.productions, sys_2.productions);
		std::swap(sys_1.products, sys_2.products);
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
		std::size_t curr_level = products.size();
		return (curr_level > 0ull) ? curr_level - 1ull : curr_level;
	}

	float LSystem::getParam(char param) const
	{
		std::map<char, float>::const_iterator value = params.find(param);
		return (value != params.end()) ? value->second : NAN;
	}

	const std::vector<LSystemSymbol *>& LSystem::operator[](std::size_t level)
	{
		try { return products.at(level); }
		catch (const std::out_of_range&)
		{
			if (products.empty())
				produceAxiom();

			return products[products.size() - 1ull];
		}
	}

	const std::vector<LSystemSymbol *>& LSystem::derive()
	{
		if (products.empty())
			produceAxiom();

		const std::vector<LSystemSymbol *>& current_level = products[products.size() - 1ull];
		std::vector<LSystemSymbol *> new_level;

#if defined(_DEBUG) || defined(_VERBOSE)
		lsysh::ConsoleProgressBar symbol_derivation(current_level.size());
#endif

		for (std::vector<LSystemSymbol *>::const_iterator& it = current_level.begin(); it != current_level.end(); ++it)
		{
			LSystemProduction *matched_prod = matchProduction(current_level, it);

			if (!matched_prod)
				new_level.push_back((*it)->clone());
			else
				matched_prod->generateSuccessor(*it, params, new_level);

#if defined(_DEBUG) || defined(_VERBOSE)
			symbol_derivation.step();
		}
		symbol_derivation.finish();
#else
		}
#endif

		products.push_back(new_level);
		return products[products.size() - 1ull];
	}

	const std::vector<LSystemSymbol *>& LSystem::derive(std::size_t level)
	{
#if defined(_DEBUG) || defined(_VERBOSE)
		std::size_t curr_level = getCurrentLevel() + 1ull;

		while (--level)
		{
			std::clog << "Deriving level " << curr_level++ << "..." << std::endl;
			derive();
		}

		std::clog << "Deriving level " << curr_level << "..." << std::endl;
#else
		while (--level)
			derive();
#endif

		return derive();
	}

	LSystemProduction* LSystem::matchProduction(const std::vector<LSystemSymbol *>& curr_level,
		std::vector<LSystemSymbol *>::const_iterator& pred)
	{
		std::vector<LSystemProduction *> candidates;

		for (LSystemProduction *prod : productions)
		{
			if (*prod->getPredecessor() != **pred || !prod->condition(*pred, params))
				continue;

			long long pred_index = pred - curr_level.begin();
			const std::vector<LSystemSymbol *>& left_cxt = prod->getLeftContext();
			if (!left_cxt.empty())
			{
				long long left = pred_index - 1ll;

				while (left >= 0ll
					&& *curr_level[left] == *left_cxt[left_cxt.size() - pred_index + left])
					--left;
				if (pred_index - left != left_cxt.size() + 1ull)
					continue;
			}

			const std::vector<LSystemSymbol *>& right_cxt = prod->getRightContext();
			if (!right_cxt.empty())
			{
				long long right = pred_index + 1ll;

				while (right < static_cast<long long>(curr_level.size())
					&& *curr_level[right] == *right_cxt[right - pred_index - 1ll])
					++right;
				if (right - pred_index != right_cxt.size() + 1ull)
					continue;
			}

			candidates.push_back(prod);
		}

		if (candidates.size() == 1ull)
			return candidates[0];
		else
		{
			float prob = static_cast<float>(std::rand()) / RAND_MAX, total_prob = 0.0f;

			for (LSystemProduction *prod : candidates)
				if (prob <= (total_prob += prod->getProbability()))
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
		unsigned short no = 1u;
		for (LSystemProduction *prod : productions)
		{
			ret += 'P';	ret += std::to_string(no++); ret += ":\t";
			ret += prod->toString();
		}

		return ret;
	}

}
