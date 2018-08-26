#ifndef LSYSTEMSYMBOL_H
#define LSYSTEMSYMBOL_H

#include <iostream>
#include <string>
#include <map>

// move?

namespace lsys
{

	class LSystemSymbol
	{
	protected:
		char key;
		std::map<char, float> params;

	public:
		LSystemSymbol(char k);
		LSystemSymbol(char k, const char *params);
		LSystemSymbol(const LSystemSymbol& sym);
		LSystemSymbol& operator=(const LSystemSymbol& sym);
		virtual ~LSystemSymbol() = default;

		char getKey() const;
		float getParam(char param);
		void setParam(char param, float value);
		void createParam(char param);
		virtual bool operator==(const LSystemSymbol& lSym) const;
		virtual bool operator!=(const LSystemSymbol& lSym) const;

		virtual std::string toString() const;
		friend std::ostream& operator<<(std::ostream& out, const LSystemSymbol& lSym);
	};

}

#endif
