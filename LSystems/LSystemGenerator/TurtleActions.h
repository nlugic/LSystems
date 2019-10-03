#ifndef TURTLEACTIONS_H
#define TURTLEACTIONS_H

#include "GlobalDefinitions.h"
#include "LSystem.h"
#include "GraphicsTurtle.h"

namespace lsys
{

	inline void saveTurtleState(GraphicsTurtle *turtle, LSystemSymbol *sym, LSystem *sys) { turtle->pushState(); }

	inline void restoreTurtleState(GraphicsTurtle *turtle, LSystemSymbol *sym, LSystem *sys) { turtle->popState(); }

	inline void turnTurtleLeft(GraphicsTurtle *turtle, LSystemSymbol *sym, LSystem *sys)
		{ turtle->rotateAroundUp(sym->getParam('y')); }

	inline void turnTurtleRight(GraphicsTurtle *turtle, LSystemSymbol *sym, LSystem *sys)
		{ turtle->rotateAroundUp(-sym->getParam('y')); }

	inline void pitchTurtleUp(GraphicsTurtle *turtle, LSystemSymbol *sym, LSystem *sys)
		{ turtle->rotateAroundLeft(-sym->getParam('p')); }

	inline void pitchTurtleDown(GraphicsTurtle *turtle, LSystemSymbol *sym, LSystem *sys)
		{ turtle->rotateAroundLeft(sym->getParam('p')); }

	inline void rollTurtleLeft(GraphicsTurtle *turtle, LSystemSymbol *sym, LSystem *sys)
		{ turtle->rotateAroundHeading(-sym->getParam('r')); }

	inline void rollTurtleRight(GraphicsTurtle *turtle, LSystemSymbol *sym, LSystem *sys)
		{ turtle->rotateAroundHeading(sym->getParam('r')); }

	inline void turnTurtleAround(GraphicsTurtle *turtle, LSystemSymbol *sym, LSystem *sys)
		{ turtle->rotateAroundUp(180.0f); }

	inline void rotateTurtleToVertical(GraphicsTurtle *turtle, LSystemSymbol *sym, LSystem *sys)
	{ //turtle->rotateToVector(turtle->getInitialState().up); }
	}
	void drawLine(GraphicsTurtle *turtle, LSystemSymbol *sym, LSystem *sys);
	void drawBox(GraphicsTurtle *turtle, LSystemSymbol *sym, LSystem *sys);
	void drawGenericBranchSegment(GraphicsTurtle *turtle, LSystemSymbol *sym, LSystem *sys);
	void drawGenericBranchApex(GraphicsTurtle *turtle, LSystemSymbol *sym, LSystem *sys);
	void drawGenericLeaf(GraphicsTurtle *turtle, LSystemSymbol *sym, LSystem *sys);
	void drawTesselatedGenericBranchSegment(GraphicsTurtle *turtle, LSystemSymbol *sym, LSystem *sys);

}

#endif
