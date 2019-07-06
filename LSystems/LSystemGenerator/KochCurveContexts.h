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
		KochSnowflakeContext(std::size_t maxL, float length, float angle)
			:LSystemContext(new KochCurveLSystem(new KochSnowflakeProduction(), length, angle, 3.0f), maxL)
		{
			turtle.setAction('F', drawLine);
		}
	};

	class KochIslandContextA : public LSystemContext
	{
	public:
		KochIslandContextA(std::size_t maxL, float length, float angle)
			:LSystemContext(new KochCurveLSystem(new KochIslandProductionA(), length, angle), maxL)
		{
			turtle.setAction('F', drawLine);
		}
	};

	class KochIslandContextB : public LSystemContext
	{
	public:
		KochIslandContextB(std::size_t maxL, float length, float angle)
			:LSystemContext(new KochCurveLSystem(new KochIslandProductionB(length, angle), length, angle), maxL)
		{
			turtle.setAction('F', drawLine);
		}
	};

	class KochIslandContextC : public LSystemContext
	{
	public:
		KochIslandContextC(std::size_t maxL, float length, float angle)
			:LSystemContext(new KochCurveLSystem(new KochIslandProductionC(length, angle), length, angle), maxL)
		{
			turtle.setAction('F', drawLine);
		}
	};

	class KochIslandContextD : public LSystemContext
	{
	public:
		KochIslandContextD(std::size_t maxL, float length, float angle)
			:LSystemContext(new KochCurveLSystem(new KochIslandProductionD(length, angle), length, angle), maxL)
		{
			turtle.setAction('F', drawLine);
		}
	};

	class KochIslandContextE : public LSystemContext
	{
	public:
		KochIslandContextE(std::size_t maxL, float length, float angle)
			:LSystemContext(new KochCurveLSystem(new KochIslandProductionE(length, angle), length, angle), maxL)
		{
			turtle.setAction('F', drawLine);
		}
	};

	class KochIslandContextF : public LSystemContext
	{
	public:
		KochIslandContextF(std::size_t maxL, float length, float angle)
			:LSystemContext(new KochCurveLSystem(new KochIslandProductionF(length, angle), length, angle), maxL)
		{
			turtle.setAction('F', drawLine);
		}
	};

	class KochIslandContextG : public LSystemContext
	{
	public:
		KochIslandContextG(std::size_t maxL, float length, float angle)
			:LSystemContext(new KochCurveLSystem(new KochIslandProductionG(length, angle), length, angle), maxL)
		{
			turtle.setAction('F', drawLine);
		}
	};

}

#endif
