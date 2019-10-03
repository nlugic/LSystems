
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

	void LSystemSymbol::defineParams(const char *param)
	{
		while (*param)
			params[*param++] = NAN;
	}

	std::string LSystemSymbol::toString() const
	{
		std::ostringstream out;
		out << key;

		if (!params.empty())
		{
			out << "(";

			for (std::map<char, float>::const_iterator& it = params.cbegin(); it != params.cend(); ++it)
			{
				out << it->first;
				if (!std::isnan(it->second))
					out << " = " << it->second;
				out << ((std::distance(it, params.cend()) == 1ll) ? ")" : ", ");
			}
		}

		return out.str();
	}

}
