#ifndef LSYSTEMCONTEXT_H
#define LSYSTEMCONTEXT_H

#include "LSystem.h"
#include "TurtleDrawingFunctions.h"

namespace lsys
{

	class LSystemContext
	{
	protected:
		LSystem *lSystem;
		GraphicsTurtle turtle;

		void initTurtleFunctions();

	public:
		LSystemContext(LSystem *lSys = nullptr, const TurtleState& state = defaultTurtleState);
		LSystemContext(const char *params, const TurtleState& state = defaultTurtleState);
		LSystemContext(const LSystemContext& lCxt);
		LSystemContext& operator=(const LSystemContext& lCxt);
		virtual ~LSystemContext();

		GraphicsTurtle& getTurtle();
		const std::vector<float> getCurrentVertexBuffer() const;
		const std::vector<unsigned>& getCurrentElementBuffer() const;
		const std::vector<glm::mat4>& getCurrentTransformBuffer() const;
		void drawLevel(size_t level);

		std::string toString() const;
		friend std::ostream& operator<<(std::ostream& out, const LSystemContext& lCxt);
	};

}

#endif
