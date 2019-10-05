
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

			std::map<char, float>::const_iterator& par = params.cbegin();
			for (; par != std::prev(params.cend()); ++par)
			{
				out << par->first;
				if (!std::isnan(par->second))
					out << " = " << par->second;
				out << ", ";
			}

			out << par->first;
			if (!std::isnan(par->second))
				out << " = " << par->second;
			out << ")";
		}

		return out.str();
	}

}
