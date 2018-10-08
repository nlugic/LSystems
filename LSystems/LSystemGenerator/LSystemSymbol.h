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
		LSystemSymbol(const LSystemSymbol&) = default;
		LSystemSymbol& operator=(const LSystemSymbol&) = default;
		virtual ~LSystemSymbol() = default;

		char getKey() const;
		float getParam(char param);
		void setParam(char param, float value);
		virtual bool operator==(const LSystemSymbol& lSym) const;
		virtual bool operator!=(const LSystemSymbol& lSym) const;

		virtual std::string toString() const;
		friend std::ostream& operator<<(std::ostream& out, const LSystemSymbol& lSym);
	};

}

#endif
