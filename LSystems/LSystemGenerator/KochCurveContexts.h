#ifndef KOCHCURVECONTEXTS_H
#define KOCHCURVECONTEXTS_H

#include "LSystemContext.h"
#include "KochCurveLSystem.h"
#include "TurtleActions.h"

namespace lsys
{

	class KochSnowflakeContext : public LSystemContext
	{
	public:
		KochSnowflakeContext(float length, float angle)
			:LSystemContext(new KochCurveLSystem(new KochSnowflakeProduction(), length, angle, 3.0f))
		{
			turtle.setAction('F', drawLine);
		}
	};

	class KochIslandContextA : public LSystemContext
	{
	public:
		KochIslandContextA(float length, float angle)
			:LSystemContext(new KochCurveLSystem(new KochIslandProductionA(), length, angle))
		{
			turtle.setAction('F', drawLine);
		}
	};

	class KochIslandContextB : public LSystemContext
	{
	public:
		KochIslandContextB(float length, float angle)
			:LSystemContext(new KochCurveLSystem(new KochIslandProductionB(), length, angle))
		{
			turtle.setAction('F', drawLine);
		}
	};

	class KochIslandContextC : public LSystemContext
	{
	public:
		KochIslandContextC(float length, float angle)
			:LSystemContext(new KochCurveLSystem(new KochIslandProductionC(), length, angle))
		{
			turtle.setAction('F', drawLine);
		}
	};

	class KochIslandContextD : public LSystemContext
	{
	public:
		KochIslandContextD(float length, float angle)
			:LSystemContext(new KochCurveLSystem(new KochIslandProductionD(), length, angle))
		{
			turtle.setAction('F', drawLine);
		}
	};

	class KochIslandContextE : public LSystemContext
	{
	public:
		KochIslandContextE(float length, float angle)
			:LSystemContext(new KochCurveLSystem(new KochIslandProductionE(), length, angle))
		{
			turtle.setAction('F', drawLine);
		}
	};

	class KochIslandContextF : public LSystemContext
	{
	public:
		KochIslandContextF(float length, float angle)
			:LSystemContext(new KochCurveLSystem(new KochIslandProductionF(), length, angle))
		{
			turtle.setAction('F', drawLine);
		}
	};

	class KochIslandContextG : public LSystemContext
	{
	public:
		KochIslandContextG(float length, float angle)
			:LSystemContext(new KochCurveLSystem(new KochIslandProductionG(), length, angle))
		{
			turtle.setAction('F', drawLine);
		}
	};

}

#endif
