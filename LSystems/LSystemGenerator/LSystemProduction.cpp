
#include "LSystemProduction.h"
#include <iterator>
#include <numeric>
#include <algorithm>

namespace lhelp
{

	void clearSymbols(std::vector<lsys::LSystemSymbol *>& syms)
	{
		for (lsys::LSystemSymbol *sym : syms)
			delete sym;
		syms.clear();
	}

	void clearSymbolsAndFreeMemory(std::vector<lsys::LSystemSymbol *>& syms)
	{
		for (lsys::LSystemSymbol *sym : syms)
			delete sym;
		std::swap(syms, std::vector<lsys::LSystemSymbol *> { });
	}

}

namespace lsys
{

	LSystemProduction::LSystemProduction(const LSystemProduction& prod)
		:predecessor(prod.predecessor->clone()), probability(prod.probability)
	{
		std::transform(prod.left_context.cbegin(), prod.left_context.cend(), std::back_inserter(left_context),
			[](LSystemSymbol *sym) { return sym->clone(); });
		std::transform(prod.right_context.cbegin(), prod.right_context.cend(), std::back_inserter(right_context),
			[](LSystemSymbol *sym) { return sym->clone(); });
		std::transform(prod.successor.cbegin(), prod.successor.cend(), std::back_inserter(successor),
			[](LSystemSymbol *sym) { return sym->clone(); });
	}

	void swap(LSystemProduction& prod_1, LSystemProduction& prod_2)
	{
		std::swap(prod_1.predecessor, prod_2.predecessor);
		std::swap(prod_1.left_context, prod_2.left_context);
		std::swap(prod_1.right_context, prod_2.right_context);
		std::swap(prod_1.successor, prod_2.successor);
	}

	LSystemProduction::~LSystemProduction()
	{
		delete predecessor;
		lhelp::clearSymbolsAndFreeMemory(left_context);
		lhelp::clearSymbolsAndFreeMemory(right_context);
		lhelp::clearSymbolsAndFreeMemory(successor);
	}

	void LSystemProduction::generateSuccessor(const LSystemSymbol *pred, const std::map<char, float>& global_params,
		std::vector<LSystemSymbol *>& word) const
	{
		std::transform(successor.cbegin(), successor.cend(), std::back_inserter(word),
			[](LSystemSymbol *sym) { return sym->clone(); });
	}

	std::string LSystemProduction::toString() const
	{
		std::string ret;

		if (!left_context.empty())
		{
			ret += std::accumulate(left_context.cbegin(), left_context.cend(), std::string(),
				[](const std::string& res, LSystemSymbol *sym) { return res + sym->toString(); });
			ret += " < ";
		}

		ret += predecessor->toString();

		if (!right_context.empty())
		{
			ret += " > ";
			ret += std::accumulate(right_context.cbegin(), right_context.cend(), std::string(),
				[](const std::string& res, LSystemSymbol *sym) { return res + sym->toString(); });
		}

		ret += " -";
		if (probability < 1.0f)
		{
			ret += '{';
			ret += std::to_string(probability * 100.0f);
			ret += "%}";
		}
		ret += "-> ";
		
		if (!successor.empty())
			ret += std::accumulate(successor.cbegin(), successor.cend(), std::string(),
				[](const std::string& res, LSystemSymbol *sym) { return res + sym->toString(); });
		else
			ret += "{dynamically_derived_successor}";
		ret += '\n';

		return ret;
	}

}
