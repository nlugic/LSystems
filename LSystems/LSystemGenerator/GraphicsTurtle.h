#ifndef GRAPHICSTURTLE_H
#define GRAPHICSTURTLE_H

#include "LSystemSymbol.h"
#include "..\..\include\glm\glm.hpp"
#include <stack>
#include <functional>

namespace lsys
{

	class GraphicsTurtle
	{
	protected:
		std::stack<glm::mat4> matrices;
		std::map<char, std::function<void(LSystemSymbol *)>> actions;

	public:
		GraphicsTurtle();
		GraphicsTurtle(const GraphicsTurtle& trt) = delete;
		GraphicsTurtle& operator=(const GraphicsTurtle& trt) = delete;
		virtual ~GraphicsTurtle();

	};

}

#endif
