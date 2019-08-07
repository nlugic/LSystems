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
		LSystemSymbol() = delete;
		inline LSystemSymbol(char k)
			:key(k) { }
		inline LSystemSymbol(const LSystemSymbol&) = default;
		inline virtual LSystemSymbol *clone() const { return new LSystemSymbol(*this); }
		friend void swap(LSystemSymbol& sym_1, LSystemSymbol& sym_2);
		inline LSystemSymbol(LSystemSymbol&& sym) noexcept { swap(*this, sym); }
		inline LSystemSymbol& operator=(LSystemSymbol sym) noexcept { swap(*this, sym); return *this; }
		inline virtual ~LSystemSymbol() = default;

		inline char getKey() const { return key; }
		float getParam(char param) const;
		inline void setParam(char param, float value) { params[param] = value; }
		inline void setParams(const LSystemSymbol *sym) { params = sym->params; }
		inline virtual bool operator==(const LSystemSymbol& sym) const { return key == sym.key; }
		inline virtual bool operator!=(const LSystemSymbol& sym) const { return !(*this == sym); }

		virtual std::string toString() const;
		inline friend std::ostream& operator<<(std::ostream& out, const LSystemSymbol& sym)
			{ out << sym.toString(); return out; }
	};

}

#endif
