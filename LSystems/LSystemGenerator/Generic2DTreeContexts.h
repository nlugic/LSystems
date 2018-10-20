#ifndef GENERIC2DTREECONTEXTS_H
#define GENERIC2DTREECONTEXTS_H

#include "LSystemContext.h"
#include "Generic2DTreeLSystems.h"
#include "TurtleActions.h"

namespace lsys
{

	class Generic2DTreContextA : public LSystemContext
	{
	public:
		Generic2DTreContextA(float length, float angle = 25.7f)
			:LSystemContext(new Generic2DTreeLSystem('F', new Generic2DTreeProductionA(length, angle), length))
		{
			turtle.setAction('F', drawLine);
		}
	};

	class Generic2DTreContextB : public LSystemContext
	{
	public:
		Generic2DTreContextB(float length, float angle = 20.0f)
			:LSystemContext(new Generic2DTreeLSystem('F', new Generic2DTreeProductionB(length, angle), length))
		{
			turtle.setAction('F', drawLine);
		}
	};

	class Generic2DTreContextC : public LSystemContext
	{
	public:
		Generic2DTreContextC(float length, float angle = 22.5f)
			:LSystemContext(new Generic2DTreeLSystem('F', new Generic2DTreeProductionC(length, angle), length))
		{
			turtle.setAction('F', drawLine);
		}
	};

	class Generic2DTreContextD : public LSystemContext
	{
	public:
		Generic2DTreContextD(float length, float angle = 20.0f)
			:LSystemContext(new Generic2DTreeLSystem('X', new Generic2DTreeProductionD(length, angle), length, true))
		{
			turtle.setAction('F', drawLine);
			turtle.setAction('X', drawLine);
		}
	};

	class Generic2DTreContextE : public LSystemContext
	{
	public:
		Generic2DTreContextE(float length, float angle = 25.7f)
			:LSystemContext(new Generic2DTreeLSystem('X', new Generic2DTreeProductionE(length, angle), length, true))
		{
			turtle.setAction('F', drawLine);
			turtle.setAction('X', drawLine);
		}
	};

	class Generic2DTreContextF : public LSystemContext
	{
	public:
		Generic2DTreContextF(float length, float angle = 22.5f)
			:LSystemContext(new Generic2DTreeLSystem('X', new Generic2DTreeProductionF(length, angle), length, true))
		{
			turtle.setAction('F', drawLine);
			turtle.setAction('X', drawLine);
		}
	};

	class Generic2DTreContextS : public LSystemContext
	{
	public:
		Generic2DTreContextS(float length, float angle = 22.5f)
			:LSystemContext(new Generic2DTreeLSystem('F', new Generic2DTreeProductionS1(length, angle), length))
		{
			lSystem->addProduction(new Generic2DTreeProductionS2(length, angle));
			lSystem->addProduction(new Generic2DTreeProductionS3(length, angle));

			turtle.setAction('F', drawLine);
		}
	};

	class Generic2DTreeContextSD : public LSystemContext
	{
	public:
		Generic2DTreeContextSD(float length, float reduction, float angle = 85.0f)
			:LSystemContext(new Generic2DTreeLSystemSD(length, reduction, angle))
		{
			turtle.setAction('F', drawLine);
		}
	};

}

#endif
