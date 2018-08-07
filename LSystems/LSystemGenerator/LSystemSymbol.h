#ifndef LSYSTEMSYMBOL_H
#define LSYSTEMSYMBOL_H

#include <iostream>
#include <string>
#include <map>

// difoltni konstruktor?
// konstruktor sa const char * koji automatski radi createParam()?
// konstruktor koji od pointera pravi novi objekat
// destruktor, copy, move?

namespace lsys
{

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
		void createParam(char param);
		virtual bool operator==(const LSystemSymbol& lSym) const;
		virtual bool operator!=(const LSystemSymbol& lSym) const;

		virtual std::string toString() const;
		friend std::ostream& operator<<(std::ostream& out, const LSystemSymbol& lSym);
	};

}

#endif
