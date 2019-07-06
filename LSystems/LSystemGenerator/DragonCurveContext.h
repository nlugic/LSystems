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
		DragonCurveContext(std::size_t maxL, float length, float angle)
			:LSystemContext(new DragonCurveLSystem(length, angle), maxL)
		{
			turtle.setAction('L', drawLine);
			turtle.setAction('R', drawLine);
		}
	};

}

#endif
