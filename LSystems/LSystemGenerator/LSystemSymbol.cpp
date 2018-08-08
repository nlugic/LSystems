
#include "LSystemSymbol.h"

namespace lsys
{

	LSystemSymbol::LSystemSymbol(char k) :key(k) { }


	LSystemSymbol::LSystemSymbol(char k, const char *params)
		:key(k)
	{
		for (const char *c = params; *c != '\0'; ++c)
			createParam(*c);
	}
		
	LSystemSymbol::LSystemSymbol(const LSystemSymbol& sym)
		:key(sym.key), params(sym.params) { }

	LSystemSymbol& LSystemSymbol::operator=(const LSystemSymbol& sym)
	{
		if (this != &sym)
		{
			key = sym.key;
			params = sym.params;
		}
		return *this;
	}

	LSystemSymbol::~LSystemSymbol() { }

	float LSystemSymbol::getParam(char param)
	{
		if (params.find(param) != params.end())
			return params[param];
		return NAN;
	}

	void LSystemSymbol::setParam(char param, float value)
	{
		params[param] = value;
	}

	void LSystemSymbol::createParam(char param)
	{
		params[param] = NAN;
	}

	bool LSystemSymbol::operator==(const LSystemSymbol& lSym) const
	{
		return key == lSym.key && params == lSym.params;
	}

	bool LSystemSymbol::operator!=(const LSystemSymbol& lSym) const
	{
		return !(*this == lSym);
	}

	std::string LSystemSymbol::toString() const
	{
		std::string ret;
		ret += key;

		if (params.size() > 0)
			ret += '(';
		for (std::map<char, float>::const_iterator& iter = params.begin(); iter != params.end(); ++iter)
			ret += (!std::isnan(iter->second) ? iter->second : iter->first) + (std::distance(iter, params.end()) == 1) ? ", " : ")";

		return ret;
	}

	std::ostream& operator<<(std::ostream& out, const LSystemSymbol& lSym)
	{
		out << lSym.toString();
		return out;
	}

}
