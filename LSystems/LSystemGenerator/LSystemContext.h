#ifndef LSYSTEMCONTEXT_H
#define LSYSTEMCONTEXT_H

#include "LSystem.h"
#include "GraphicsTurtle.h"

namespace lsys
{

	class LSystemContext
	{
	protected:
		size_t currentLevel;

		LSystem *lSystem;
		GraphicsTurtle turtle;

		virtual void initTurtleActions();

	public:
		LSystemContext(const TurtleState& state = defaultTurtleState);
		LSystemContext(LSystem *lSys, const TurtleState& state = defaultTurtleState);
		LSystemContext(const LSystemContext& lCxt);
		LSystemContext& operator=(const LSystemContext& lCxt);
		virtual ~LSystemContext();

		size_t getCurrentLevel() const;
		size_t getMaxLevel() const;
		const std::vector<float> getVertexBuffer() const;
		const std::vector<unsigned>& getElementBuffer() const;
		const std::vector<glm::mat4>& getTransformBuffer() const;
		void generateModel(size_t level);

		virtual std::string toString() const;
		friend std::ostream& operator<<(std::ostream& out, const LSystemContext& lCxt);
	};

}

#endif
