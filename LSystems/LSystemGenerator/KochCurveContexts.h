#ifndef KOCHCURVECONTEXTS_H
#define KOCHCURVECONTEXTS_H

#include "LSystemContext.h"
#include "KochCurveLSystem.h"
#include "TurtleActions.h"

namespace lsys
{

	class KochCurveContextA : public LSystemContext
	{
	public:
		KochCurveContextA(float length, float angle)
			:LSystemContext(new KochCurveLSystem(new KochCurveProductionA(angle), length, angle))
		{
			turtle.setAction('F', drawLine);
		}
	};

	class KochCurveContextB : public LSystemContext
	{
	public:
		KochCurveContextB(float length, float angle)
			:LSystemContext(new KochCurveLSystem(new KochCurveProductionB(angle), length, angle))
		{
			turtle.setAction('F', drawLine);
		}
	};

	class KochCurveContextC : public LSystemContext
	{
	public:
		KochCurveContextC(float length, float angle)
			:LSystemContext(new KochCurveLSystem(new KochCurveProductionC(angle), length, angle))
		{
			turtle.setAction('F', drawLine);
		}
	};

	class KochCurveContextD : public LSystemContext
	{
	public:
		KochCurveContextD(float length, float angle)
			:LSystemContext(new KochCurveLSystem(new KochCurveProductionD(angle), length, angle))
		{
			turtle.setAction('F', drawLine);
		}
	};

	class KochCurveContextE : public LSystemContext
	{
	public:
		KochCurveContextE(float length, float angle)
			:LSystemContext(new KochCurveLSystem(new KochCurveProductionE(angle), length, angle))
		{
			turtle.setAction('F', drawLine);
		}
	};

	class KochCurveContextF : public LSystemContext
	{
	public:
		KochCurveContextF(float length, float angle)
			:LSystemContext(new KochCurveLSystem(new KochCurveProductionF(angle), length, angle))
		{
			turtle.setAction('F', drawLine);
		}
	};

	class KochCurveContextG : public LSystemContext
	{
	public:
		KochCurveContextG(float length, float angle)
			:LSystemContext(new KochCurveLSystem(new KochCurveProductionG(angle), length, angle))
		{
			turtle.setAction('F', drawLine);
		}
	};

}

#endif
