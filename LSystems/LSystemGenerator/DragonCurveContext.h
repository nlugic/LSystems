#ifndef DRAGONCURVECONTEXT_H
#define DRAGONCURVECONTEXT_H

#include "LSystemContext.h"
#include "DragonCurveLSystem.h"
#include "TurtleActions.h"

namespace lsys
{

	class DragonCurveContext : public LSystemContext
	{
	public:
		DragonCurveContext(float length, float angle)
			:LSystemContext(new DragonCurveLSystem(length, angle))
		{
			turtle.setAction('L', drawLine);
			turtle.setAction('R', drawLine);
		}
	};

}

#endif
