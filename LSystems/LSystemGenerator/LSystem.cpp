
#include "LSystem.h"
#include "ConsoleProgressBar.h"
#include <iterator>
#include <numeric>
#include <algorithm>

namespace lhelp
{

	void clearProductions(std::vector<lsys::LSystemProduction *>& prods)
	{
		for (lsys::LSystemProduction *prod : prods)
			delete prod;
		prods.clear();
	}

	void clearProductionsAndFreeMemory(std::vector<lsys::LSystemProduction *>& prods)
	{
		for (lsys::LSystemProduction *prod : prods)
			delete prod;
		std::swap(prods, std::vector<lsys::LSystemProduction *> { });
	}

}

namespace lsys
{

	void LSystem::produceAxiom()
	{
		std::vector<LSystemSymbol *> prod;
		std::transform(axiom.cbegin(), axiom.cend(), std::back_inserter(prod),
			[](LSystemSymbol *sym) { return sym->clone(); });
		products.push_back(prod);
	}

	LSystem::LSystem(const LSystem& sys)
		:params(sys.params)
	{
		std::transform(sys.axiom.cbegin(), sys.axiom.cend(), std::back_inserter(axiom),
			[](LSystemSymbol *sym) { return sym->clone(); });
		std::transform(sys.productions.cbegin(), sys.productions.cend(), std::back_inserter(productions),
			[](LSystemProduction *prod) { return prod->clone(); });
		std::transform(sys.products.cbegin(), sys.products.cend(), std::back_inserter(products),
			[](const std::vector<LSystemSymbol *>& product)
		{
			std::vector<LSystemSymbol *> prod;
			std::transform(product.cbegin(), product.cend(), std::back_inserter(prod),
				[](LSystemSymbol *sym) { return sym->clone(); });
			return prod;
		});
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
		lhelp::clearSymbolsAndFreeMemory(axiom);
		lhelp::clearProductionsAndFreeMemory(productions);
		for (std::vector<LSystemSymbol *>& product : products)
			lhelp::clearSymbolsAndFreeMemory(product);
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
		lhelp::ConsoleProgressBar symbol_derivation(current_level.size());
#endif

		for (std::vector<LSystemSymbol *>::const_iterator& it = current_level.cbegin(); it != current_level.cend(); ++it)
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
		const std::vector<LSystemSymbol *>::const_iterator& pred)
	{
		std::vector<LSystemProduction *> candidates;

		for (LSystemProduction *prod : productions)
		{
			if (*prod->getPredecessor() != **pred || !prod->condition(*pred, params))
				continue;

			std::size_t pred_index = static_cast<std::size_t>(pred - curr_level.cbegin());
			const std::vector<LSystemSymbol *>& left_cxt = prod->getLeftContext();
			if (!left_cxt.empty() && left_cxt.size() <= pred_index
				&& !std::equal(std::make_reverse_iterator(pred - 1), curr_level.rend(), left_cxt.rbegin(), left_cxt.rend()))
				continue;

			const std::vector<LSystemSymbol *>& right_cxt = prod->getRightContext();
			if (!right_cxt.empty() && right_cxt.size() <= curr_level.size() - pred_index - 1ull
				&& std::equal(pred + 1, curr_level.end(), right_cxt.cbegin(), right_cxt.cend()))
				continue;

			candidates.push_back(prod);
		}

		if (candidates.size() == 1ull)
			return candidates.front();
		else
		{
			float prob = static_cast<float>(std::rand()) / RAND_MAX, total_prob = 0.0f;
			const std::vector<LSystemProduction *>::const_iterator& matched_rule = std::find_if(candidates.cbegin(), candidates.cend(),
				[&prob, &total_prob](LSystemProduction *prod) { return prob <= (total_prob += prod->getProbability()); });

			if (matched_rule != candidates.cend())
				return *matched_rule;
		}

		return nullptr;
	}

	std::string LSystem::toString() const
	{
		std::string ret("A: \t");
		ret += std::accumulate(axiom.cbegin(), axiom.cend(), std::string(),
			[](const std::string& res, LSystemSymbol *sym) { return res + sym->getKey(); });
		ret += '\n';

		unsigned short no = 1u;
		for (LSystemProduction *prod : productions)
		{
			ret += 'P';	ret += std::to_string(no++); ret += ": \t";
			ret += prod->toString();
		}

		return ret;
	}

}
