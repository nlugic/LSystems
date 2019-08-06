
#include "LSystemProduction.h"
#include "..\..\include\glm\glm.hpp"

namespace lsys
{

	void LSystemProduction::clearSymbols(std::vector<LSystemSymbol *>& syms)
	{
		for (LSystemSymbol *sym : syms)
			delete sym;
		syms.clear();
	}

	LSystemProduction::LSystemProduction(LSystemSymbol *pred, float prob)
		:predecessor(pred), probability(glm::clamp(prob, 0.0f, 1.0f)) { }

	LSystemProduction::LSystemProduction(char pred, float prob)
		:predecessor(new LSystemSymbol(pred)), probability(glm::clamp(prob, 0.0f, 1.0f)) { }

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

	LSystemProduction::LSystemProduction(LSystemProduction&& prod) noexcept { swap(*this, prod); }

	LSystemProduction& LSystemProduction::operator=(LSystemProduction prod) noexcept { swap(*this, prod); return *this; }

	LSystemProduction *LSystemProduction::clone() const { return new LSystemProduction(*this); }

	LSystemProduction::~LSystemProduction()
	{
		delete predecessor;
		clearSymbols(left_context);
		clearSymbols(right_context);
		clearSymbols(successor);
	}

	const LSystemSymbol* LSystemProduction::getPredecessor() const { return predecessor; }

	const std::vector<LSystemSymbol *>& LSystemProduction::getLeftContext() const { return left_context; }

	const std::vector<LSystemSymbol *>& LSystemProduction::getRightContext() const { return right_context; }

	const std::vector<LSystemSymbol *>& LSystemProduction::getSuccessor() const { return successor; }

	void LSystemProduction::addSymbolToLeftContext(LSystemSymbol *sym) { if (sym) left_context.push_back(sym); }

	void LSystemProduction::setLeftContext(const std::vector<LSystemSymbol *>& l_cxt)
		{ clearSymbols(left_context); left_context = l_cxt; }

	void LSystemProduction::addSymbolToRightContext(LSystemSymbol *sym) { if (sym) right_context.push_back(sym); }

	void LSystemProduction::setRightContext(const std::vector<LSystemSymbol *>& r_cxt)
		{ clearSymbols(right_context); right_context = r_cxt; }

	void LSystemProduction::addSymbolToSuccessor(LSystemSymbol *sym) { if (sym) successor.push_back(sym); }

	void LSystemProduction::setSuccessor(const std::vector<LSystemSymbol *>& succ)
		{ clearSymbols(successor); successor = succ; }

	float LSystemProduction::getProbability() const { return probability; }

	bool LSystemProduction::condition(const LSystemSymbol *pred, const std::map<char, float>& global_params) const
		{ return true; }

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

	std::ostream& operator<<(std::ostream& out, const LSystemProduction& prod) { out << prod.toString(); return out; }

}
