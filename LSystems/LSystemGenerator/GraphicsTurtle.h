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
		GraphicsTurtle(const GraphicsTurtle&) = delete;
		GraphicsTurtle& operator=(const GraphicsTurtle&) = delete;
		virtual ~GraphicsTurtle();

	};

}

#endif
