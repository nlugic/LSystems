
#include "LSystemSymbol.h"
#include <sstream>

namespace lsys
{

	LSystemSymbol::LSystemSymbol(char key)
		:key(key) { }

	LSystemSymbol *LSystemSymbol::clone() const { return new LSystemSymbol(*this); }

	char LSystemSymbol::getKey() const { return key; }

	float LSystemSymbol::getParam(char param) const
	{
		std::map<char, float>::const_iterator value = params.find(param);
		return (value != params.end()) ? value->second : NAN;
	}

	void LSystemSymbol::setParam(char param, float value) { params[param] = value; }

	void LSystemSymbol::setParams(const LSystemSymbol *sym) { params = sym->params; }

	bool LSystemSymbol::operator==(const LSystemSymbol& sym) const { return key == sym.key; }

	bool LSystemSymbol::operator!=(const LSystemSymbol& sym) const { return !(*this == sym); }

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

	std::ostream& operator<<(std::ostream& out, const LSystemSymbol& sym) { out << sym.toString(); return out; }

}
