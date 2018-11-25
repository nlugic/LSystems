
#include "LSystemSymbol.h"
#include <sstream>

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
		params[param] = value;
	}

	void LSystemSymbol::setParams(const LSystemSymbol *lSym)
	{
		params = lSym->params;
	}

	bool LSystemSymbol::operator==(const LSystemSymbol& lSym) const
	{
		return key == lSym.key;
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
		{
			std::ostringstream out;
			out.precision(4LL);
			out << "(";

			for (std::map<char, float>::const_iterator& iter = params.begin(); iter != params.end(); ++iter)
			{
				out << iter->second;
				out << ((std::distance(iter, params.end()) == 1LL) ? ")" : ", ");
			}
			ret += out.str();
		}

		return ret;
	}

	std::ostream& operator<<(std::ostream& out, const LSystemSymbol& lSym)
	{
		out << lSym.toString();
		return out;
	}

}
