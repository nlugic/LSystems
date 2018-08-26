#ifndef TURTLEDRAWINGFUNCTIONS_H
#define TURTLEDRAWINGFUNCTIONS_H

#include "LSystemSymbol.h"
#include "GraphicsTurtle.h"

namespace lsys
{

	void drawBranchSegment(GraphicsTurtle *turtle, LSystemSymbol *sym);
	void saveTurtleState(GraphicsTurtle *turtle, LSystemSymbol *sym);
	void restoreTurtleState(GraphicsTurtle *turtle, LSystemSymbol *sym);
	void turnTurtleLeft(GraphicsTurtle *turtle, LSystemSymbol *sym);
	void turnTurtleRight(GraphicsTurtle *turtle, LSystemSymbol *sym);
	void pitchTurtleUp(GraphicsTurtle *turtle, LSystemSymbol *sym);
	void pitchTurtleDown(GraphicsTurtle *turtle, LSystemSymbol *sym);
	void rollTurtleLeft(GraphicsTurtle *turtle, LSystemSymbol *sym);
	void rollTurtleRight(GraphicsTurtle *turtle, LSystemSymbol *sym);
	void turnTurtleAround(GraphicsTurtle *turtle, LSystemSymbol *sym);
	void rotateTurtleToVertical(GraphicsTurtle *turtle, LSystemSymbol *sym);

}

#endif
