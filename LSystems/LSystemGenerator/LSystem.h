#ifndef LSYSTEM_H
#define LSYSTEM_H

#include "LSystemProdRule.h"
#include "TurtleDrawingFunctions.h"

namespace lsys
{

	class LSystem
	{
	private:
		void clearSymbols();
		void copySymbols(const LSystem& lSys);
		void produceAxiom();
		void initTurtleFunctions();

	protected:
		std::vector<LSystemSymbol *> axiom;
		std::vector<LSystemProdRule *> rules;
		std::map<char, float> params;
		std::vector<std::vector<LSystemSymbol *>> products;
		GraphicsTurtle turtle;

	public:
		LSystem();
		LSystem(const char *params);
		LSystem(const LSystem& lSys);
		LSystem& operator=(const LSystem& lSys);
		virtual ~LSystem();

		size_t getCurrentLevel() const;
		void addSymbolToAxiom(LSystemSymbol *sym);
		void addRule(LSystemProdRule *rule);
		float getParam(char param);
		void setParam(char param, float value);
		void createParam(char param);
		std::vector<LSystemSymbol *>& operator[](unsigned char level);
		const std::vector<float>& getCurrentVertexBuffer() const;
		const std::vector<unsigned>& getCurrentElementBuffer() const;

		std::vector<LSystemSymbol *>& derive(unsigned char level);
		std::vector<LSystemSymbol *>& derive();
		LSystemProdRule* pickRule(LSystemSymbol *sym) const;
		void drawLevel(unsigned char level);

		virtual std::string toString() const;
		friend std::ostream& operator<<(std::ostream& out, const LSystem& lSys);
	};

}

#endif
