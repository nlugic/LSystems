
#include "LSystemSymbol.h"
#include <sstream>

namespace lsys
{

	void swap(LSystemSymbol& sym_1, LSystemSymbol& sym_2)
	{
		std::swap(sym_1.key, sym_2.key);
		std::swap(sym_1.params, sym_2.params);
	}

	float LSystemSymbol::getParam(char param) const
	{
		std::map<char, float>::const_iterator value = params.find(param);
		return (value != params.end()) ? value->second : NAN;
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

			for (std::map<char, float>::const_iterator& it = params.begin(); it != params.end(); ++it)
			{
				out << it->second;
				out << ((std::distance(it, params.end()) == 1LL) ? ")" : ", ");
			}
			ret += out.str();
		}

		return ret;
	}

}
