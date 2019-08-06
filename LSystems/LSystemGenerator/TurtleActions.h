#ifndef TURTLEACTIONS_H
#define TURTLEACTIONS_H

#include "GlobalDefinitions.h"
#include "LSystem.h"
#include "GraphicsTurtle.h"

namespace lsys
{

	void saveTurtleState(GraphicsTurtle *turtle, LSystemSymbol *sym, LSystem *sys);
	void restoreTurtleState(GraphicsTurtle *turtle, LSystemSymbol *sym, LSystem *sys);
	void turnTurtleLeft(GraphicsTurtle *turtle, LSystemSymbol *sym, LSystem *sys);
	void turnTurtleRight(GraphicsTurtle *turtle, LSystemSymbol *sym, LSystem *sys);
	void pitchTurtleUp(GraphicsTurtle *turtle, LSystemSymbol *sym, LSystem *sys);
	void pitchTurtleDown(GraphicsTurtle *turtle, LSystemSymbol *sym, LSystem *sys);
	void rollTurtleLeft(GraphicsTurtle *turtle, LSystemSymbol *sym, LSystem *sys);
	void rollTurtleRight(GraphicsTurtle *turtle, LSystemSymbol *sym, LSystem *sys);
	void turnTurtleAround(GraphicsTurtle *turtle, LSystemSymbol *sym, LSystem *sys);
	void rotateTurtleToVertical(GraphicsTurtle *turtle, LSystemSymbol *sym, LSystem *sys);

	void drawLine(GraphicsTurtle *turtle, LSystemSymbol *sym, LSystem *sys);
	void drawBox(GraphicsTurtle *turtle, LSystemSymbol *sym, LSystem *sys);
	void drawGenericBranchSegment(GraphicsTurtle *turtle, LSystemSymbol *sym, LSystem *sys);
	void drawGenericBranchApex(GraphicsTurtle *turtle, LSystemSymbol *sym, LSystem *sys);
	void drawGenericLeaf(GraphicsTurtle *turtle, LSystemSymbol *sym, LSystem *sys);
	void drawTesselatedGenericBranchSegment(GraphicsTurtle *turtle, LSystemSymbol *sym, LSystem *sys);

}

#endif
