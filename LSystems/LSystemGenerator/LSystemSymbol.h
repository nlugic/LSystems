#ifndef LSYSTEMSYMBOL_H
#define LSYSTEMSYMBOL_H

#include <iostream>
#include <string>
#include <map>

namespace lsys
{

	class LSystemSymbol
	{
	protected:
		char key;
		std::map<char, float> params;

	public:
		LSystemSymbol(char key);

		char getKey() const;
		float getParam(char param) const;
		void setParam(char param, float value);
		void setParams(const LSystemSymbol *lSym);
		virtual bool operator==(const LSystemSymbol& lSym) const;
		virtual bool operator!=(const LSystemSymbol& lSym) const;

		virtual std::string toString() const;
		friend std::ostream& operator<<(std::ostream& out, const LSystemSymbol& lSym);
	};

}

#endif
