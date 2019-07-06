#ifndef SIERPINSKIGASKETCONTEXT_H
#define SIERPINSKIGASKETCONTEXT_H

#include "LSystemContext.h"
#include "SierpinskiGasketLSystem.h"
#include "TurtleActions.h"

namespace lsys
{

	class SierpinskiGasketContext : public LSystemContext
	{
	public:
		SierpinskiGasketContext(std::size_t maxL, float length, float angle)
			:LSystemContext(new SierpinskiGasketLSystem(length, angle), maxL)
		{
			turtle.setAction('L', drawLine);
			turtle.setAction('R', drawLine);
		}
	};

}

#endif
