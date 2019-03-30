#ifndef TURTLEACTIONS_H
#define TURTLEACTIONS_H

#include "LSystem.h"
#include "GraphicsTurtle.h"

namespace lsys
{

	const float pix2 = 6.28318530717958647692f;
	const float pi = 3.14159265358979323846f;
	const float pi_2 = 1.57079632679489661923f;
	const float pi_4 = 0.785398163397448309616f;

	void saveTurtleState(GraphicsTurtle *turtle, LSystemSymbol *lSym, LSystem *lSys);
	void restoreTurtleState(GraphicsTurtle *turtle, LSystemSymbol *lSym, LSystem *lSys);
	void turnTurtleLeft(GraphicsTurtle *turtle, LSystemSymbol *lSym, LSystem *lSys);
	void turnTurtleRight(GraphicsTurtle *turtle, LSystemSymbol *lSym, LSystem *lSys);
	void pitchTurtleUp(GraphicsTurtle *turtle, LSystemSymbol *lSym, LSystem *lSys);
	void pitchTurtleDown(GraphicsTurtle *turtle, LSystemSymbol *lSym, LSystem *lSys);
	void rollTurtleLeft(GraphicsTurtle *turtle, LSystemSymbol *lSym, LSystem *lSys);
	void rollTurtleRight(GraphicsTurtle *turtle, LSystemSymbol *lSym, LSystem *lSys);
	void turnTurtleAround(GraphicsTurtle *turtle, LSystemSymbol *lSym, LSystem *lSys);
	void rotateTurtleToVertical(GraphicsTurtle *turtle, LSystemSymbol *lSym, LSystem *lSys);

	void drawLine(GraphicsTurtle *turtle, LSystemSymbol *lSym, LSystem *lSys);
	void drawBox(GraphicsTurtle *turtle, LSystemSymbol *lSym, LSystem *lSys);
	void drawGenericBranchSegment(GraphicsTurtle *turtle, LSystemSymbol *lSym, LSystem *lSys);
	void drawGenericBranchApex(GraphicsTurtle *turtle, LSystemSymbol *lSym, LSystem *lSys);
	void drawGenericLeaf(GraphicsTurtle *turtle, LSystemSymbol *lSym, LSystem *lSys);
	void drawTesselatedGenericBranchSegment(GraphicsTurtle *turtle, LSystemSymbol *lSym, LSystem *lSys);

}

#endif
