
#include "LSystemSymbol.h"

namespace lsys
{

	LSystemSymbol::LSystemSymbol(char k) :key(k) { }

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
		for (std::map<char, float>::const_iterator iter = params.begin(); iter != params.end(); ++iter)
			ret += (!std::isnan(iter->second) ? iter->second : iter->first) + (std::distance(iter, params.end()) == 1) ? ", " : ")";

		return ret;
	}

	std::ostream& operator<<(std::ostream& out, const LSystemSymbol& lSym)
	{
		out << lSym.toString();
		return out;
	}

}
