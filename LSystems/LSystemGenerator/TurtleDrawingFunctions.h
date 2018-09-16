#ifndef TURTLEDRAWINGFUNCTIONS_H
#define TURTLEDRAWINGFUNCTIONS_H

#include "LSystemSymbol.h"
#include "GraphicsTurtle.h"

namespace lsys
{

	const float pix2 = 6.28318530717958647692f;
	const float pi = 3.14159265358979323846f;
	const float pi_2 = 1.57079632679489661923f;
	const float pi_4 = 0.785398163397448309616f;

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
