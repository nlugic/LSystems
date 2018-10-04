
#include "LSystemSymbol.h"

namespace lsys
{

	LSystemSymbol::LSystemSymbol(char key)
		:key(key) { }


	LSystemSymbol::LSystemSymbol(char key, const char *params)
		:key(key)
	{
		for (const char *c = params; *c; ++c)
			createParam(*c);
	}
		
	LSystemSymbol::LSystemSymbol(const LSystemSymbol& lSym)
		:key(lSym.key), params(lSym.params) { }

	LSystemSymbol& LSystemSymbol::operator=(const LSystemSymbol& lSym)
	{
		if (this != &lSym)
		{
			key = lSym.key;
			params = lSym.params;
		}
		return *this;
	}

	char LSystemSymbol::getKey() const
	{
		return key;
	}

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
		if (!params.empty())
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
