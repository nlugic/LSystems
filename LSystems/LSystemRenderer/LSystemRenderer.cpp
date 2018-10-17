
#include "LSystemRenderer.h"
#include "..\..\include\glm\gtc\matrix_transform.hpp"
#include <ctime>

#include "..\LSystemGenerator\KochCurveContexts.h"
#include "..\LSystemGenerator\SierpinskiGasketContext.h"
#include "..\LSystemGenerator\Generic2DTreeContexts.h"
#include "..\LSystemGenerator\HilbertCurve3DContext.h"
#include "..\LSystemGenerator\Generic3DTreeContext.h"

#pragma comment (lib, "..\\x64\\Debug\\LSystemGenerator.lib")

namespace lrend
{

	LSystemRenderer::LSystemRenderer(lsys::LSystemContext *lCxt)
		:context(lCxt) { }

	LSystemRenderer::~LSystemRenderer()
	{
		delete context;
	}

	void LSystemRenderer::drawKochCurveA(size_t level, float length, float angle)
	{
		LSystemRenderer rend(new lsys::KochCurveContextA(length, angle));
		rend.context->generateModel(level);

		OGLRenderer::renderScene(rend.context->getVertexBuffer(), rend.context->getElementBuffer(),
			std::vector<const char *> { }, rend.context->getTransformBuffer());
	}

	void LSystemRenderer::drawKochCurveB(size_t level, float length, float angle)
	{
		LSystemRenderer rend(new lsys::KochCurveContextB(length, angle));
		rend.context->generateModel(level);

		OGLRenderer::renderScene(rend.context->getVertexBuffer(), rend.context->getElementBuffer(),
			std::vector<const char *> { }, rend.context->getTransformBuffer());
	}

	void LSystemRenderer::drawKochCurveC(size_t level, float length, float angle)
	{
		LSystemRenderer rend(new lsys::KochCurveContextC(length, angle));
		rend.context->generateModel(level);

		OGLRenderer::renderScene(rend.context->getVertexBuffer(), rend.context->getElementBuffer(),
			std::vector<const char *> { }, rend.context->getTransformBuffer());
	}

	void LSystemRenderer::drawKochCurveD(size_t level, float length, float angle)
	{
		LSystemRenderer rend(new lsys::KochCurveContextD(length, angle));
		rend.context->generateModel(level);

		OGLRenderer::renderScene(rend.context->getVertexBuffer(), rend.context->getElementBuffer(),
			std::vector<const char *> { }, rend.context->getTransformBuffer());
	}

	void LSystemRenderer::drawKochCurveE(size_t level, float length, float angle)
	{
		LSystemRenderer rend(new lsys::KochCurveContextE(length, angle));
		rend.context->generateModel(level);

		OGLRenderer::renderScene(rend.context->getVertexBuffer(), rend.context->getElementBuffer(),
			std::vector<const char *> { }, rend.context->getTransformBuffer());
	}

	void LSystemRenderer::drawKochCurveF(size_t level, float length, float angle)
	{
		LSystemRenderer rend(new lsys::KochCurveContextF(length, angle));
		rend.context->generateModel(level);

		OGLRenderer::renderScene(rend.context->getVertexBuffer(), rend.context->getElementBuffer(),
			std::vector<const char *> { }, rend.context->getTransformBuffer());
	}

	void LSystemRenderer::drawKochCurveG(size_t level, float length, float angle)
	{
		LSystemRenderer rend(new lsys::KochCurveContextG(length, angle));
		rend.context->generateModel(level);

		OGLRenderer::renderScene(rend.context->getVertexBuffer(), rend.context->getElementBuffer(),
			std::vector<const char *> { }, rend.context->getTransformBuffer());
	}

	void LSystemRenderer::drawSierpinskiGasket(size_t level, float length, float angle)
	{
		LSystemRenderer rend(new lsys::SierpinskiGasketContext(length, angle));
		rend.context->generateModel(level);

		OGLRenderer::renderScene(rend.context->getVertexBuffer(), rend.context->getElementBuffer(),
			std::vector<const char *> { }, rend.context->getTransformBuffer());
	}

	void LSystemRenderer::drawGeneric2DTreeA(size_t level, float length, float angle)
	{
		LSystemRenderer rend(new lsys::Generic2DTreContextA(length, angle));
		rend.context->generateModel(level);

		OGLRenderer::renderScene(rend.context->getVertexBuffer(), rend.context->getElementBuffer(),
			std::vector<const char *> { }, rend.context->getTransformBuffer());
	}

	void LSystemRenderer::drawGeneric2DTreeB(size_t level, float length, float angle)
	{
		LSystemRenderer rend(new lsys::Generic2DTreContextB(length, angle));
		rend.context->generateModel(level);

		OGLRenderer::renderScene(rend.context->getVertexBuffer(), rend.context->getElementBuffer(),
			std::vector<const char *> { }, rend.context->getTransformBuffer());
	}

	void LSystemRenderer::drawGeneric2DTreeC(size_t level, float length, float angle)
	{
		LSystemRenderer rend(new lsys::Generic2DTreContextC(length, angle));
		rend.context->generateModel(level);

		OGLRenderer::renderScene(rend.context->getVertexBuffer(), rend.context->getElementBuffer(),
			std::vector<const char *> { }, rend.context->getTransformBuffer());
	}

	void LSystemRenderer::drawGeneric2DTreeD(size_t level, float length, float angle)
	{
		LSystemRenderer rend(new lsys::Generic2DTreContextD(length, angle));
		rend.context->generateModel(level);

		OGLRenderer::renderScene(rend.context->getVertexBuffer(), rend.context->getElementBuffer(),
			std::vector<const char *> { }, rend.context->getTransformBuffer());
	}

	void LSystemRenderer::drawGeneric2DTreeE(size_t level, float length, float angle)
	{
		LSystemRenderer rend(new lsys::Generic2DTreContextE(length, angle));
		rend.context->generateModel(level);

		OGLRenderer::renderScene(rend.context->getVertexBuffer(), rend.context->getElementBuffer(),
			std::vector<const char *> { }, rend.context->getTransformBuffer());
	}

	void LSystemRenderer::drawGeneric2DTreeF(size_t level, float length, float angle)
	{
		LSystemRenderer rend(new lsys::Generic2DTreContextF(length, angle));
		rend.context->generateModel(level);

		OGLRenderer::renderScene(rend.context->getVertexBuffer(), rend.context->getElementBuffer(),
			std::vector<const char *> { }, rend.context->getTransformBuffer());
	}

	void LSystemRenderer::drawGeneric2DTreeS(size_t level, float length, float angle)
	{
		LSystemRenderer rend(new lsys::Generic2DTreContextS(length, angle));
		rend.context->generateModel(level);

		OGLRenderer::renderScene(rend.context->getVertexBuffer(), rend.context->getElementBuffer(),
			std::vector<const char *> { }, rend.context->getTransformBuffer());
	}

	void LSystemRenderer::drawGeneric2DTreeSD(size_t level, float length, float reduction, float angle)
	{
		LSystemRenderer rend(new lsys::Generic2DTreeContextSD(length, reduction, angle));
		rend.context->generateModel(level);

		OGLRenderer::renderScene(rend.context->getVertexBuffer(), rend.context->getElementBuffer(),
			std::vector<const char *> { }, rend.context->getTransformBuffer());
	}

	void LSystemRenderer::drawHilbertCurve3D(size_t level, int slices, float radius, float length, float angle)
	{
		LSystemRenderer rend(new lsys::HilbertCurve3DContext(slices, radius, length, angle));
		rend.context->generateModel(level);

		OGLRenderer::renderScene(rend.context->getVertexBuffer(), rend.context->getElementBuffer(),
			std::vector<const char *> { "..\\LSystemRenderer\\tree.jpg" }, rend.context->getTransformBuffer());
	}

	void LSystemRenderer::drawGeneric3DTree(size_t level, int slices, float radius, float height, float angle)
	{
		LSystemRenderer rend(new lsys::Generic3DTreeContext(slices, radius, height, angle));
		rend.context->generateModel(level);

		OGLRenderer::renderScene(rend.context->getVertexBuffer(), rend.context->getElementBuffer(),
			std::vector<const char *> { "..\\LSystemRenderer\\tree.jpg" }, rend.context->getTransformBuffer());
	}

}
