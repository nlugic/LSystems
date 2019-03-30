
#include "LSystemRenderer.h"
#include "..\..\include\glm\gtc\matrix_transform.hpp"

#include "..\LSystemGenerator\KochCurveContexts.h"
#include "..\LSystemGenerator\SierpinskiGasketContext.h"
#include "..\LSystemGenerator\DragonCurveContext.h"
#include "..\LSystemGenerator\Generic2DTreeContexts.h"
#include "..\LSystemGenerator\HilbertCurve3DContext.h"
#include "..\LSystemGenerator\Generic3DTreeContexts.h"

#ifdef _DEBUG
#pragma comment (lib, "..\\x64\\Debug\\LSystemGenerator.lib")
#else
#pragma comment (lib, "..\\x64\\Release\\LSystemGenerator.lib")
#endif

namespace lrend
{

	static bool testMode = false;

	LSystemRenderer::LSystemRenderer(std::size_t maxL, lsys::LSystemContext *lCxt)
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
		OGLRenderer::updateVertexData(context->getVertexBuffer(), context->getTransformBuffer());
	}

	void LSystemRenderer::levelDown()
	{
		if (context->getCurrentLevel() == 0ULL)
			return;

		context->generateModel(context->getCurrentLevel() - 1ULL);
		OGLRenderer::updateVertexData(context->getVertexBuffer(), context->getTransformBuffer());
	}

	void LSystemRenderer::setTestMode(bool test)
	{
		lrend::testMode = test;
	}

	void LSystemRenderer::drawKochSnowflake(std::size_t level, float length, float angle)
	{
		LSystemRenderer rend(level, new lsys::KochSnowflakeContext(length, angle));
		rend.context->generateModel(level);

		if (!lrend::testMode)
			OGLRenderer::renderScene(&rend, rend.context->getVertexBuffer(), std::vector<const char *> { },
				rend.context->getTransformBuffer());
	}

	void LSystemRenderer::drawKochIslandA(std::size_t level, float length, float angle)
	{
		LSystemRenderer rend(level, new lsys::KochIslandContextA(length, angle));
		rend.context->generateModel(level);

		if (!lrend::testMode)
			OGLRenderer::renderScene(&rend, rend.context->getVertexBuffer(), std::vector<const char *> { },
				rend.context->getTransformBuffer());
	}

	void LSystemRenderer::drawKochIslandB(std::size_t level, float length, float angle)
	{
		LSystemRenderer rend(level, new lsys::KochIslandContextB(length, angle));
		rend.context->generateModel(level);

		if (!lrend::testMode)
			OGLRenderer::renderScene(&rend, rend.context->getVertexBuffer(), std::vector<const char *> { },
				rend.context->getTransformBuffer());
	}

	void LSystemRenderer::drawKochIslandC(std::size_t level, float length, float angle)
	{
		LSystemRenderer rend(level, new lsys::KochIslandContextC(length, angle));
		rend.context->generateModel(level);

		if (!lrend::testMode)
			OGLRenderer::renderScene(&rend, rend.context->getVertexBuffer(), std::vector<const char *> { },
				rend.context->getTransformBuffer());
	}

	void LSystemRenderer::drawKochIslandD(std::size_t level, float length, float angle)
	{
		LSystemRenderer rend(level, new lsys::KochIslandContextD(length, angle));
		rend.context->generateModel(level);

		if (!lrend::testMode)
			OGLRenderer::renderScene(&rend, rend.context->getVertexBuffer(), std::vector<const char *> { },
				rend.context->getTransformBuffer());
	}

	void LSystemRenderer::drawKochIslandE(std::size_t level, float length, float angle)
	{
		LSystemRenderer rend(level, new lsys::KochIslandContextE(length, angle));
		rend.context->generateModel(level);

		if (!lrend::testMode)
			OGLRenderer::renderScene(&rend, rend.context->getVertexBuffer(), std::vector<const char *> { },
				rend.context->getTransformBuffer());
	}

	void LSystemRenderer::drawKochIslandF(std::size_t level, float length, float angle)
	{
		LSystemRenderer rend(level, new lsys::KochIslandContextF(length, angle));
		rend.context->generateModel(level);

		if (!lrend::testMode)
			OGLRenderer::renderScene(&rend, rend.context->getVertexBuffer(), std::vector<const char *> { },
				rend.context->getTransformBuffer());
	}

	void LSystemRenderer::drawKochIslandG(std::size_t level, float length, float angle)
	{
		LSystemRenderer rend(level, new lsys::KochIslandContextG(length, angle));
		rend.context->generateModel(level);

		if (!lrend::testMode)
			OGLRenderer::renderScene(&rend, rend.context->getVertexBuffer(), std::vector<const char *> { },
				rend.context->getTransformBuffer());
	}

	void LSystemRenderer::drawDragonCurve(std::size_t level, float length, float angle)
	{
		LSystemRenderer rend(level, new lsys::DragonCurveContext(length, angle));
		rend.context->generateModel(level);

		if (!lrend::testMode)
			OGLRenderer::renderScene(&rend, rend.context->getVertexBuffer(), std::vector<const char *> { },
				rend.context->getTransformBuffer());
	}

	void LSystemRenderer::drawSierpinskiGasket(std::size_t level, float length, float angle)
	{
		LSystemRenderer rend(level, new lsys::SierpinskiGasketContext(length, angle));
		rend.context->generateModel(level);

		if (!lrend::testMode)
			OGLRenderer::renderScene(&rend, rend.context->getVertexBuffer(), std::vector<const char *> { },
				rend.context->getTransformBuffer());
	}

	void LSystemRenderer::drawGeneric2DTreeA(std::size_t level, float length, float angle)
	{
		LSystemRenderer rend(level, new lsys::Generic2DTreContextA(length, angle));
		rend.context->generateModel(level);

		if (!lrend::testMode)
			OGLRenderer::renderScene(&rend, rend.context->getVertexBuffer(), std::vector<const char *> { },
				rend.context->getTransformBuffer());
	}

	void LSystemRenderer::drawGeneric2DTreeB(std::size_t level, float length, float angle)
	{
		LSystemRenderer rend(level, new lsys::Generic2DTreContextB(length, angle));
		rend.context->generateModel(level);

		if (!lrend::testMode)
			OGLRenderer::renderScene(&rend, rend.context->getVertexBuffer(), std::vector<const char *> { },
				rend.context->getTransformBuffer());
	}

	void LSystemRenderer::drawGeneric2DTreeC(std::size_t level, float length, float angle)
	{
		LSystemRenderer rend(level, new lsys::Generic2DTreContextC(length, angle));
		rend.context->generateModel(level);

		if (!lrend::testMode)
			OGLRenderer::renderScene(&rend, rend.context->getVertexBuffer(), std::vector<const char *> { },
				rend.context->getTransformBuffer());
	}

	void LSystemRenderer::drawGeneric2DTreeD(std::size_t level, float length, float angle)
	{
		LSystemRenderer rend(level, new lsys::Generic2DTreContextD(length, angle));
		rend.context->generateModel(level);

		if (!lrend::testMode)
			OGLRenderer::renderScene(&rend, rend.context->getVertexBuffer(), std::vector<const char *> { },
				rend.context->getTransformBuffer());
	}

	void LSystemRenderer::drawGeneric2DTreeE(std::size_t level, float length, float angle)
	{
		LSystemRenderer rend(level, new lsys::Generic2DTreContextE(length, angle));
		rend.context->generateModel(level);

		if (!lrend::testMode)
			OGLRenderer::renderScene(&rend, rend.context->getVertexBuffer(), std::vector<const char *> { },
				rend.context->getTransformBuffer());
	}

	void LSystemRenderer::drawGeneric2DTreeF(std::size_t level, float length, float angle)
	{
		LSystemRenderer rend(level, new lsys::Generic2DTreContextF(length, angle));
		rend.context->generateModel(level);

		if (!lrend::testMode)
			OGLRenderer::renderScene(&rend, rend.context->getVertexBuffer(), std::vector<const char *> { },
				rend.context->getTransformBuffer());
	}

	void LSystemRenderer::drawGeneric2DTreeS(std::size_t level, float length, float angle)
	{
		LSystemRenderer rend(level, new lsys::Generic2DTreContextS(length, angle));
		rend.context->generateModel(level);

		if (!lrend::testMode)
			OGLRenderer::renderScene(&rend, rend.context->getVertexBuffer(), std::vector<const char *> { },
				rend.context->getTransformBuffer());
	}

	void LSystemRenderer::drawGeneric2DTreeSD(std::size_t level, float length, float reduction, float angle)
	{
		LSystemRenderer rend(level, new lsys::Generic2DTreeContextSD(length, reduction, angle));
		rend.context->generateModel(level);

		if (!lrend::testMode)
			OGLRenderer::renderScene(&rend, rend.context->getVertexBuffer(), std::vector<const char *> { },
				rend.context->getTransformBuffer());
	}

	void LSystemRenderer::drawHilbertCurve3D(std::size_t level, float width, float length, float red, float green, float blue, float angle)
	{
		LSystemRenderer rend(level, new lsys::HilbertCurve3DContext(width, length, angle, red, green, blue));
		rend.context->generateModel(level);

		if (!lrend::testMode)
			OGLRenderer::renderScene(&rend, rend.context->getVertexBuffer(), std::vector<const char *> { },
				rend.context->getTransformBuffer());
	}

	void LSystemRenderer::drawGeneric3DTree(std::size_t level, int slices, float radius, float height, float angle)
	{
		LSystemRenderer rend(level, new lsys::Generic3DTreeContext(slices, radius, height, angle));
		rend.context->generateModel(level);

		if (!lrend::testMode)
			OGLRenderer::renderScene(&rend, rend.context->getVertexBuffer(),
				std::vector<const char *> { "..\\LSystemRenderer\\tree.jpg" }, rend.context->getTransformBuffer());
	}

	void LSystemRenderer::drawTesselatedGeneric3DTree(std::size_t level, float radius, float height, float angle)
	{
		LSystemRenderer rend(level, new lsys::TesselatedGeneric3DTreeContext(radius, height, angle));
		rend.context->generateModel(level);

		if (!lrend::testMode)
		{
			OGLRendererConfig config = defaultOGLRendererConfig;

			config.vertShaderPath = "..\\LSystemRenderer\\default_tess.vert";
			config.tessCtrlPath = "..\\LSystemRenderer\\default_tess.tesc";
			config.tessEvalPath = "..\\LSystemRenderer\\default_tess.tese";
			config.geometryPath = "..\\LSystemRenderer\\wireframe.geom";
			config.fragShaderPath = "..\\LSystemRenderer\\default_tess.frag";

			OGLRenderer::renderScene(&rend, rend.context->getVertexBuffer(),
				std::vector<const char *> { "..\\LSystemRenderer\\tree.jpg" },
				rend.context->getTransformBuffer(), config);
		}
	}

}
