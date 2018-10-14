#ifndef LSYSTEMCONTEXT_H
#define LSYSTEMCONTEXT_H

#include "LSystem.h"
#include "GraphicsTurtle.h"

namespace lsys
{

	class LSystemContext
	{
	protected:
		LSystem *lSystem;
		GraphicsTurtle turtle;

		virtual void initTurtleFunctions();

	public:
		LSystemContext(const TurtleState& state = defaultTurtleState);
		LSystemContext(LSystem *lSys, const TurtleState& state = defaultTurtleState);
		LSystemContext(const LSystemContext& lCxt);
		LSystemContext& operator=(const LSystemContext& lCxt);
		virtual ~LSystemContext();

		const std::vector<float> getVertexBuffer() const;
		const std::vector<unsigned>& getElementBuffer() const;
		const std::vector<glm::mat4>& getTransformBuffer() const;
		void generateModel(size_t level);

		virtual std::string toString() const;
		friend std::ostream& operator<<(std::ostream& out, const LSystemContext& lCxt);
	};

}

#endif
