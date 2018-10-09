
#include "LSystemSymbol.h"

namespace lsys
{

	LSystemSymbol::LSystemSymbol(char key)
		:key(key) { }

	char LSystemSymbol::getKey() const
	{
		return key;
	}

	float LSystemSymbol::getParam(char param) const
	{
		if (params.count(param))
			return params.at(param);
		return NAN;
	}

	void LSystemSymbol::setParam(char param, float value)
	{
		params.emplace(param, value);
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
