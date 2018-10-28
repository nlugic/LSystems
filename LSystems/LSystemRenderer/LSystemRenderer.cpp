
#include "LSystemRenderer.h"
#include "..\..\include\glm\gtc\matrix_transform.hpp"

#include "..\LSystemGenerator\KochCurveContexts.h"
#include "..\LSystemGenerator\SierpinskiGasketContext.h"
#include "..\LSystemGenerator\DragonCurveContext.h"
#include "..\LSystemGenerator\Generic2DTreeContexts.h"
#include "..\LSystemGenerator\HilbertCurve3DContext.h"
#include "..\LSystemGenerator\Generic3DTreeContext.h"

#pragma comment (lib, "..\\x64\\Debug\\LSystemGenerator.lib")

namespace lrend
{

	LSystemRenderer::LSystemRenderer(size_t maxL, lsys::LSystemContext *lCxt)
		:maxLevel(maxL), context(lCxt) { }

	LSystemRenderer::~LSystemRenderer()
	{
		delete context;
	}

	void LSystemRenderer::levelUp()
	{
		if (context->getCurrentLevel() >= maxLevel)
			return;

		context->generateModel(context->getCurrentLevel() + 1ULL);
		OGLRenderer::updateVertexData(context->getVertexBuffer(), context->getElementBuffer(),
			context->getTransformBuffer());
	}

	void LSystemRenderer::levelDown()
	{
		if (context->getCurrentLevel() == 0ULL)
			return;

		context->generateModel(context->getCurrentLevel() - 1ULL);
		OGLRenderer::updateVertexData(context->getVertexBuffer(), context->getElementBuffer(),
			context->getTransformBuffer());
	}

	void LSystemRenderer::drawKochSnowflake(size_t level, float length, float angle)
	{
		LSystemRenderer rend(level, new lsys::KochSnowflakeContext(length, angle));
		rend.context->generateModel(level);

		OGLRenderer::renderScene(&rend, rend.context->getVertexBuffer(), rend.context->getElementBuffer(),
			std::vector<const char *> { }, rend.context->getTransformBuffer());
	}

	void LSystemRenderer::drawKochIslandA(size_t level, float length, float angle)
	{
		LSystemRenderer rend(level, new lsys::KochIslandContextA(length, angle));
		rend.context->generateModel(level);

		OGLRenderer::renderScene(&rend, rend.context->getVertexBuffer(), rend.context->getElementBuffer(),
			std::vector<const char *> { }, rend.context->getTransformBuffer());
	}

	void LSystemRenderer::drawKochIslandB(size_t level, float length, float angle)
	{
		LSystemRenderer rend(level, new lsys::KochIslandContextB(length, angle));
		rend.context->generateModel(level);

		OGLRenderer::renderScene(&rend, rend.context->getVertexBuffer(), rend.context->getElementBuffer(),
			std::vector<const char *> { }, rend.context->getTransformBuffer());
	}

	void LSystemRenderer::drawKochIslandC(size_t level, float length, float angle)
	{
		LSystemRenderer rend(level, new lsys::KochIslandContextC(length, angle));
		rend.context->generateModel(level);

		OGLRenderer::renderScene(&rend, rend.context->getVertexBuffer(), rend.context->getElementBuffer(),
			std::vector<const char *> { }, rend.context->getTransformBuffer());
	}

	void LSystemRenderer::drawKochIslandD(size_t level, float length, float angle)
	{
		LSystemRenderer rend(level, new lsys::KochIslandContextD(length, angle));
		rend.context->generateModel(level);

		OGLRenderer::renderScene(&rend, rend.context->getVertexBuffer(), rend.context->getElementBuffer(),
			std::vector<const char *> { }, rend.context->getTransformBuffer());
	}

	void LSystemRenderer::drawKochIslandE(size_t level, float length, float angle)
	{
		LSystemRenderer rend(level, new lsys::KochIslandContextE(length, angle));
		rend.context->generateModel(level);

		OGLRenderer::renderScene(&rend, rend.context->getVertexBuffer(), rend.context->getElementBuffer(),
			std::vector<const char *> { }, rend.context->getTransformBuffer());
	}

	void LSystemRenderer::drawKochIslandF(size_t level, float length, float angle)
	{
		LSystemRenderer rend(level, new lsys::KochIslandContextF(length, angle));
		rend.context->generateModel(level);

		OGLRenderer::renderScene(&rend, rend.context->getVertexBuffer(), rend.context->getElementBuffer(),
			std::vector<const char *> { }, rend.context->getTransformBuffer());
	}

	void LSystemRenderer::drawKochIslandG(size_t level, float length, float angle)
	{
		LSystemRenderer rend(level, new lsys::KochIslandContextG(length, angle));
		rend.context->generateModel(level);

		OGLRenderer::renderScene(&rend, rend.context->getVertexBuffer(), rend.context->getElementBuffer(),
			std::vector<const char *> { }, rend.context->getTransformBuffer());
	}

	void LSystemRenderer::drawDragonCurve(size_t level, float length, float angle)
	{
		LSystemRenderer rend(level, new lsys::DragonCurveContext(length, angle));
		rend.context->generateModel(level);

		OGLRenderer::renderScene(&rend, rend.context->getVertexBuffer(), rend.context->getElementBuffer(),
			std::vector<const char *> { }, rend.context->getTransformBuffer());
	}

	void LSystemRenderer::drawSierpinskiGasket(size_t level, float length, float angle)
	{
		LSystemRenderer rend(level, new lsys::SierpinskiGasketContext(length, angle));
		rend.context->generateModel(level);

		OGLRenderer::renderScene(&rend, rend.context->getVertexBuffer(), rend.context->getElementBuffer(),
			std::vector<const char *> { }, rend.context->getTransformBuffer());
	}

	void LSystemRenderer::drawGeneric2DTreeA(size_t level, float length, float angle)
	{
		LSystemRenderer rend(level, new lsys::Generic2DTreContextA(length, angle));
		rend.context->generateModel(level);

		OGLRenderer::renderScene(&rend, rend.context->getVertexBuffer(), rend.context->getElementBuffer(),
			std::vector<const char *> { }, rend.context->getTransformBuffer());
	}

	void LSystemRenderer::drawGeneric2DTreeB(size_t level, float length, float angle)
	{
		LSystemRenderer rend(level, new lsys::Generic2DTreContextB(length, angle));
		rend.context->generateModel(level);

		OGLRenderer::renderScene(&rend, rend.context->getVertexBuffer(), rend.context->getElementBuffer(),
			std::vector<const char *> { }, rend.context->getTransformBuffer());
	}

	void LSystemRenderer::drawGeneric2DTreeC(size_t level, float length, float angle)
	{
		LSystemRenderer rend(level, new lsys::Generic2DTreContextC(length, angle));
		rend.context->generateModel(level);

		OGLRenderer::renderScene(&rend, rend.context->getVertexBuffer(), rend.context->getElementBuffer(),
			std::vector<const char *> { }, rend.context->getTransformBuffer());
	}

	void LSystemRenderer::drawGeneric2DTreeD(size_t level, float length, float angle)
	{
		LSystemRenderer rend(level, new lsys::Generic2DTreContextD(length, angle));
		rend.context->generateModel(level);

		OGLRenderer::renderScene(&rend, rend.context->getVertexBuffer(), rend.context->getElementBuffer(),
			std::vector<const char *> { }, rend.context->getTransformBuffer());
	}

	void LSystemRenderer::drawGeneric2DTreeE(size_t level, float length, float angle)
	{
		LSystemRenderer rend(level, new lsys::Generic2DTreContextE(length, angle));
		rend.context->generateModel(level);

		OGLRenderer::renderScene(&rend, rend.context->getVertexBuffer(), rend.context->getElementBuffer(),
			std::vector<const char *> { }, rend.context->getTransformBuffer());
	}

	void LSystemRenderer::drawGeneric2DTreeF(size_t level, float length, float angle)
	{
		LSystemRenderer rend(level, new lsys::Generic2DTreContextF(length, angle));
		rend.context->generateModel(level);

		OGLRenderer::renderScene(&rend, rend.context->getVertexBuffer(), rend.context->getElementBuffer(),
			std::vector<const char *> { }, rend.context->getTransformBuffer());
	}

	void LSystemRenderer::drawGeneric2DTreeS(size_t level, float length, float angle)
	{
		LSystemRenderer rend(level, new lsys::Generic2DTreContextS(length, angle));
		rend.context->generateModel(level);

		OGLRenderer::renderScene(&rend, rend.context->getVertexBuffer(), rend.context->getElementBuffer(),
			std::vector<const char *> { }, rend.context->getTransformBuffer());
	}

	void LSystemRenderer::drawGeneric2DTreeSD(size_t level, float length, float reduction, float angle)
	{
		LSystemRenderer rend(level, new lsys::Generic2DTreeContextSD(length, reduction, angle));
		rend.context->generateModel(level);

		OGLRenderer::renderScene(&rend, rend.context->getVertexBuffer(), rend.context->getElementBuffer(),
			std::vector<const char *> { }, rend.context->getTransformBuffer());
	}

	void LSystemRenderer::drawHilbertCurve3D(size_t level, float width, float length, float red, float green, float blue, float angle)
	{
		LSystemRenderer rend(level, new lsys::HilbertCurve3DContext(width, length, angle, red, green, blue));
		rend.context->generateModel(level);

		OGLRenderer::renderScene(&rend, rend.context->getVertexBuffer(), rend.context->getElementBuffer(),
			std::vector<const char *> { }, rend.context->getTransformBuffer());
	}

	void LSystemRenderer::drawGeneric3DTree(size_t level, int slices, float radius, float height, float angle)
	{
		LSystemRenderer rend(level, new lsys::Generic3DTreeContext(slices, radius, height, angle));
		rend.context->generateModel(level);

		OGLRenderer::renderScene(&rend, rend.context->getVertexBuffer(), rend.context->getElementBuffer(),
			std::vector<const char *> { "..\\LSystemRenderer\\tree.jpg" }, rend.context->getTransformBuffer());
	}

}
