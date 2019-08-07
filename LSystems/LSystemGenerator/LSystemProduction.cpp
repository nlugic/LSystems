
#include "LSystemProduction.h"

namespace lsys
{

	void LSystemProduction::clearSymbols(std::vector<LSystemSymbol *>& syms)
	{
		for (LSystemSymbol *sym : syms)
			delete sym;
		syms.clear();
	}

	LSystemProduction::LSystemProduction(const LSystemProduction& prod)
		:predecessor(prod.predecessor->clone()), probability(prod.probability)
	{
		for (const LSystemSymbol *sym : prod.left_context)
			left_context.push_back(sym->clone());
		for (const LSystemSymbol *sym : prod.right_context)
			right_context.push_back(sym->clone());
		for (const LSystemSymbol *sym : prod.successor)
			successor.push_back(sym->clone());
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
		clearSymbols(left_context);
		clearSymbols(right_context);
		clearSymbols(successor);
	}

	void LSystemProduction::generateSuccessor(const LSystemSymbol *pred, const std::map<char, float>& global_params,
		std::vector<LSystemSymbol *>& word) const
	{
		for (LSystemSymbol *sym : successor)
			word.push_back(sym->clone());
	}

	std::string LSystemProduction::toString() const
	{
		std::string ret;

		for (const LSystemSymbol *sym : left_context)
		{
			ret += sym->toString();
			if (!left_context.empty())
				ret += " < ";
		}

		ret += predecessor->toString();

		if (!right_context.empty())
		{
			ret += " > ";
			for (const LSystemSymbol *sym : right_context)
				ret += sym->toString();
		}

		ret += " -";
		if (probability < 1.0f)
		{
			ret += '[';
			ret += std::to_string(probability * 100.0f);
			ret += "%]";
		}
		ret += "-> ";
		for (const LSystemSymbol *sym : successor)
			ret += sym->toString();
		ret += '\n';

		return ret;
	}

}
