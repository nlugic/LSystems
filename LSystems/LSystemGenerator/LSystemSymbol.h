#ifndef LSYSTEMSYMBOL_H
#define LSYSTEMSYMBOL_H

#include "GlobalDefinitions.h"
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
		virtual LSystemSymbol *clone() const;
		virtual ~LSystemSymbol() = default;

		char getKey() const;
		float getParam(char param) const;
		void setParam(char param, float value);
		void setParams(const LSystemSymbol *sym);
		virtual bool operator==(const LSystemSymbol& sym) const;
		virtual bool operator!=(const LSystemSymbol& sym) const;

		virtual std::string toString() const;
		friend std::ostream& operator<<(std::ostream& out, const LSystemSymbol& sym);
	};

}

#endif
