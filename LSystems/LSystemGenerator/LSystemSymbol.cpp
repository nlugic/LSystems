
#include "LSystemSymbol.h"

LSystemSymbol::LSystemSymbol(char k) :key(k) { }

LSystemSymbol::~LSystemSymbol() { }

float LSystemSymbol::getParam(char param)
{
	return params[param];
}

void LSystemSymbol::setParam(char param, float value)
{
	params[param] = value;
}

bool LSystemSymbol::operator==(const LSystemSymbol& lSym)
{
	return key == lSym.key;
}

bool LSystemSymbol::operator!=(const LSystemSymbol& lSym)
{
	return !(*this == lSym);
}

std::string LSystemSymbol::toString() const
{
	std::string ret;
	ret += key;
	return ret;
}

std::ostream& operator<<(std::ostream& out, const LSystemSymbol& lSym)
{
	out << lSym.key;
	return out;
}
