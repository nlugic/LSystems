#ifndef STOCHASTICHELPERS_H
#define STOCHASTICHELPERS_H

#include <random>

namespace lsys
{

	float randomVariation(float totalAmount = 1.0f)
	{
		return totalAmount * (static_cast<float>(std::rand()) / static_cast<float>(RAND_MAX) - 0.5f);
	}

}

#endif
