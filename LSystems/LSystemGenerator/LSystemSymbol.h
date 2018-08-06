#ifndef LSYSTEMSYMBOL_H
#define LSYSTEMSYMBOL_H

#include <iostream>
#include <string>
#include <map>

class LSystemSymbol
{
protected:
	char key;
	std::map<char, float> params;

public:
	LSystemSymbol(char k);
	virtual ~LSystemSymbol();
	float getParam(char param);
	void setParam(char param, float value);
	virtual bool operator==(const LSystemSymbol& lSym);
	virtual bool operator!=(const LSystemSymbol& lSym);

	virtual std::string toString() const;
	friend std::ostream& operator<<(std::ostream& out, const LSystemSymbol& lSym);
};

#endif
