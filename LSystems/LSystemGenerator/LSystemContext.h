#ifndef LSYSTEMCONTEXT_H
#define LSYSTEMCONTEXT_H

#include "LSystem.h"
#include "GraphicsTurtle.h"

namespace lsys
{

	class LSystemContext
	{
	protected:
		std::size_t currentLevel;

		LSystem *lSystem;
		GraphicsTurtle turtle;

		virtual void initTurtleActions();

	public:
		LSystemContext(const TurtleState& state = defaultTurtleState);
		LSystemContext(LSystem *lSys, const TurtleState& state = defaultTurtleState);
		friend void swap(LSystemContext& lCxt1, LSystemContext& lCxt2);
		LSystemContext(const LSystemContext& lCxt);
		LSystemContext(LSystemContext&& lCxt) noexcept;
		LSystemContext& operator=(LSystemContext lCxt) noexcept;
		virtual ~LSystemContext();

		std::size_t getCurrentLevel() const;
		std::size_t getMaxLevel() const;
		const std::vector<float> getVertexBuffer() const;
		const std::vector<glm::mat4>& getTransformBuffer() const;
		void generateModel(std::size_t level);

		virtual std::string toString() const;
		friend std::ostream& operator<<(std::ostream& out, const LSystemContext& lCxt);
	};

}

#endif
