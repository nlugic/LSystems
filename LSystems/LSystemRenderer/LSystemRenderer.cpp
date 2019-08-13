
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

	bool LSystemRenderer::test_mode = false;

	LSystemRenderer::~LSystemRenderer()
	{
		for (lsys::LSystemContext *cxt : contexts)
			delete cxt;
	}

	void LSystemRenderer::levelUp()
	{
		bool buffer_changed = false;
		lsys::GraphicsTurtle::resetBuffers();

		for (lsys::LSystemContext *cxt : contexts)
		{
			if (cxt->getCurrentLevel() >= cxt->getMaxLevel())
				cxt->generateModel(cxt->getCurrentLevel());
			else
			{
				cxt->generateModel(cxt->getCurrentLevel() + 1ull);
				buffer_changed = true;
			}
		}

		if (buffer_changed)
			OGLRenderer::updateVertexData(lsys::GraphicsTurtle::getVertexBuffer(),
				lsys::GraphicsTurtle::getTransformBuffer());
	}

	void LSystemRenderer::levelDown()
	{
		bool buffer_changed = false;
		lsys::GraphicsTurtle::resetBuffers();

		for (lsys::LSystemContext *cxt : contexts)
		{
			if (cxt->getCurrentLevel() == 0ull)
				cxt->generateModel(cxt->getCurrentLevel());
			else
			{
				cxt->generateModel(cxt->getCurrentLevel() - 1ull);
				buffer_changed = true;
			}
		}

		if (buffer_changed)
			OGLRenderer::updateVertexData(lsys::GraphicsTurtle::getVertexBuffer(),
				lsys::GraphicsTurtle::getTransformBuffer());
	}

	void LSystemRenderer::drawKochSnowflake(std::size_t level, float length, float angle)
	{
		lsys::GraphicsTurtle::resetBuffers();

		LSystemRenderer rend(new lsys::KochSnowflakeContext(level, length, angle));
		rend.contexts[0]->generateModel(level);

		if (!LSystemRenderer::test_mode)
			OGLRenderer::renderScene(&rend, lsys::GraphicsTurtle::getVertexBuffer(),
				lsys::GraphicsTurtle::getTransformBuffer(), std::vector<const char *> { });
	}

	void LSystemRenderer::drawKochIslandA(std::size_t level, float length, float angle)
	{
		lsys::GraphicsTurtle::resetBuffers();

		LSystemRenderer rend(new lsys::KochIslandContextA(level, length, angle));
		rend.contexts[0]->generateModel(level);

		if (!LSystemRenderer::test_mode)
			OGLRenderer::renderScene(&rend, lsys::GraphicsTurtle::getVertexBuffer(),
				lsys::GraphicsTurtle::getTransformBuffer(), std::vector<const char *> { });
	}

	void LSystemRenderer::drawKochIslandB(std::size_t level, float length, float angle)
	{
		lsys::GraphicsTurtle::resetBuffers();

		LSystemRenderer rend(new lsys::KochIslandContextB(level, length, angle));
		rend.contexts[0]->generateModel(level);

		if (!LSystemRenderer::test_mode)
			OGLRenderer::renderScene(&rend, lsys::GraphicsTurtle::getVertexBuffer(),
				lsys::GraphicsTurtle::getTransformBuffer(), std::vector<const char *> { });
	}

	void LSystemRenderer::drawKochIslandC(std::size_t level, float length, float angle)
	{
		lsys::GraphicsTurtle::resetBuffers();

		LSystemRenderer rend(new lsys::KochIslandContextC(level, length, angle));
		rend.contexts[0]->generateModel(level);

		if (!LSystemRenderer::test_mode)
			OGLRenderer::renderScene(&rend, lsys::GraphicsTurtle::getVertexBuffer(),
				lsys::GraphicsTurtle::getTransformBuffer(), std::vector<const char *> { });
	}

	void LSystemRenderer::drawKochIslandD(std::size_t level, float length, float angle)
	{
		lsys::GraphicsTurtle::resetBuffers();

		LSystemRenderer rend(new lsys::KochIslandContextD(level, length, angle));
		rend.contexts[0]->generateModel(level);

		if (!LSystemRenderer::test_mode)
			OGLRenderer::renderScene(&rend, lsys::GraphicsTurtle::getVertexBuffer(),
				lsys::GraphicsTurtle::getTransformBuffer(), std::vector<const char *> { });
	}

	void LSystemRenderer::drawKochIslandE(std::size_t level, float length, float angle)
	{
		lsys::GraphicsTurtle::resetBuffers();

		LSystemRenderer rend(new lsys::KochIslandContextE(level, length, angle));
		rend.contexts[0]->generateModel(level);

		if (!LSystemRenderer::test_mode)
			OGLRenderer::renderScene(&rend, lsys::GraphicsTurtle::getVertexBuffer(),
				lsys::GraphicsTurtle::getTransformBuffer(), std::vector<const char *> { });
	}

	void LSystemRenderer::drawKochIslandF(std::size_t level, float length, float angle)
	{
		lsys::GraphicsTurtle::resetBuffers();

		LSystemRenderer rend(new lsys::KochIslandContextF(level, length, angle));
		rend.contexts[0]->generateModel(level);

		if (!LSystemRenderer::test_mode)
			OGLRenderer::renderScene(&rend, lsys::GraphicsTurtle::getVertexBuffer(),
				lsys::GraphicsTurtle::getTransformBuffer(), std::vector<const char *> { });
	}

	void LSystemRenderer::drawKochIslandG(std::size_t level, float length, float angle)
	{
		lsys::GraphicsTurtle::resetBuffers();

		LSystemRenderer rend(new lsys::KochIslandContextG(level, length, angle));
		rend.contexts[0]->generateModel(level);

		if (!LSystemRenderer::test_mode)
			OGLRenderer::renderScene(&rend, lsys::GraphicsTurtle::getVertexBuffer(),
				lsys::GraphicsTurtle::getTransformBuffer(), std::vector<const char *> { });
	}

	void LSystemRenderer::drawDragonCurve(std::size_t level, float length, float angle)
	{
		lsys::GraphicsTurtle::resetBuffers();

		LSystemRenderer rend(new lsys::DragonCurveContext(level, length, angle));
		rend.contexts[0]->generateModel(level);

		if (!LSystemRenderer::test_mode)
			OGLRenderer::renderScene(&rend, lsys::GraphicsTurtle::getVertexBuffer(),
				lsys::GraphicsTurtle::getTransformBuffer(), std::vector<const char *> { });
	}

	void LSystemRenderer::drawSierpinskiGasket(std::size_t level, float length, float angle)
	{
		lsys::GraphicsTurtle::resetBuffers();

		LSystemRenderer rend(new lsys::SierpinskiGasketContext(level, length, angle));
		rend.contexts[0]->generateModel(level);

		if (!LSystemRenderer::test_mode)
			OGLRenderer::renderScene(&rend, lsys::GraphicsTurtle::getVertexBuffer(),
				lsys::GraphicsTurtle::getTransformBuffer(), std::vector<const char *> { });
	}

	void LSystemRenderer::drawGeneric2DTreeA(std::size_t level, float length, float angle)
	{
		lsys::GraphicsTurtle::resetBuffers();

		LSystemRenderer rend(new lsys::Generic2DTreContextA(level, length, angle));
		rend.contexts[0]->generateModel(level);

		if (!LSystemRenderer::test_mode)
			OGLRenderer::renderScene(&rend, lsys::GraphicsTurtle::getVertexBuffer(),
				lsys::GraphicsTurtle::getTransformBuffer(), std::vector<const char *> { });
	}

	void LSystemRenderer::drawGeneric2DTreeB(std::size_t level, float length, float angle)
	{
		lsys::GraphicsTurtle::resetBuffers();

		LSystemRenderer rend(new lsys::Generic2DTreContextB(level, length, angle));
		rend.contexts[0]->generateModel(level);

		if (!LSystemRenderer::test_mode)
			OGLRenderer::renderScene(&rend, lsys::GraphicsTurtle::getVertexBuffer(),
				lsys::GraphicsTurtle::getTransformBuffer(), std::vector<const char *> { });
	}

	void LSystemRenderer::drawGeneric2DTreeC(std::size_t level, float length, float angle)
	{
		lsys::GraphicsTurtle::resetBuffers();

		LSystemRenderer rend(new lsys::Generic2DTreContextC(level, length, angle));
		rend.contexts[0]->generateModel(level);

		if (!LSystemRenderer::test_mode)
			OGLRenderer::renderScene(&rend, lsys::GraphicsTurtle::getVertexBuffer(),
				lsys::GraphicsTurtle::getTransformBuffer(), std::vector<const char *> { });
	}

	void LSystemRenderer::drawGeneric2DTreeD(std::size_t level, float length, float angle)
	{
		lsys::GraphicsTurtle::resetBuffers();

		LSystemRenderer rend(new lsys::Generic2DTreContextD(level, length, angle));
		rend.contexts[0]->generateModel(level);

		if (!LSystemRenderer::test_mode)
			OGLRenderer::renderScene(&rend, lsys::GraphicsTurtle::getVertexBuffer(),
				lsys::GraphicsTurtle::getTransformBuffer(), std::vector<const char *> { });
	}

	void LSystemRenderer::drawGeneric2DTreeE(std::size_t level, float length, float angle)
	{
		lsys::GraphicsTurtle::resetBuffers();

		LSystemRenderer rend(new lsys::Generic2DTreContextE(level, length, angle));
		rend.contexts[0]->generateModel(level);

		if (!LSystemRenderer::test_mode)
			OGLRenderer::renderScene(&rend, lsys::GraphicsTurtle::getVertexBuffer(),
				lsys::GraphicsTurtle::getTransformBuffer(), std::vector<const char *> { });
	}

	void LSystemRenderer::drawGeneric2DTreeF(std::size_t level, float length, float angle)
	{
		lsys::GraphicsTurtle::resetBuffers();

		LSystemRenderer rend(new lsys::Generic2DTreContextF(level, length, angle));
		rend.contexts[0]->generateModel(level);

		if (!LSystemRenderer::test_mode)
			OGLRenderer::renderScene(&rend, lsys::GraphicsTurtle::getVertexBuffer(),
				lsys::GraphicsTurtle::getTransformBuffer(), std::vector<const char *> { });
	}

	void LSystemRenderer::drawGeneric2DTreeS(std::size_t level, float length, float angle)
	{
		lsys::GraphicsTurtle::resetBuffers();

		LSystemRenderer rend(new lsys::Generic2DTreContextS(level, length, angle));
		rend.contexts[0]->generateModel(level);

		if (!LSystemRenderer::test_mode)
			OGLRenderer::renderScene(&rend, lsys::GraphicsTurtle::getVertexBuffer(),
				lsys::GraphicsTurtle::getTransformBuffer(), std::vector<const char *> { });
	}

	void LSystemRenderer::drawGeneric2DTreeSD(std::size_t level, float length, float reduction, float angle)
	{
		lsys::GraphicsTurtle::resetBuffers();

		LSystemRenderer rend(new lsys::Generic2DTreeContextSD(level, length, reduction, angle));
		rend.contexts[0]->generateModel(level);

		if (!LSystemRenderer::test_mode)
			OGLRenderer::renderScene(&rend, lsys::GraphicsTurtle::getVertexBuffer(),
				lsys::GraphicsTurtle::getTransformBuffer(), std::vector<const char *> { });
	}

	void LSystemRenderer::drawHilbertCurve3D(std::size_t level, float width, float length,
		float red, float green, float blue, float angle)
	{
		lsys::GraphicsTurtle::resetBuffers();

		LSystemRenderer rend(new lsys::HilbertCurve3DContext(level, width, length, angle, red, green, blue));
		rend.contexts[0]->generateModel(level);

		if (!LSystemRenderer::test_mode)
			OGLRenderer::renderScene(&rend, lsys::GraphicsTurtle::getVertexBuffer(),
				lsys::GraphicsTurtle::getTransformBuffer(), std::vector<const char *> { });
	}

	void LSystemRenderer::drawGeneric3DTree(std::size_t level, int slices, float radius, float height, float angle)
	{
		lsys::GraphicsTurtle::resetBuffers();

		LSystemRenderer rend(new lsys::Generic3DTreeContext(level, slices, radius, height, angle));
		rend.contexts[0]->generateModel(level);

		if (!LSystemRenderer::test_mode)
			OGLRenderer::renderScene(&rend, lsys::GraphicsTurtle::getVertexBuffer(),
				lsys::GraphicsTurtle::getTransformBuffer(), std::vector<const char *> { "..\\LSystemRenderer\\tree.jpg" });
	}

	void LSystemRenderer::drawTesselatedGeneric3DTree(std::size_t level, float radius, float height, float angle)
	{
		lsys::GraphicsTurtle::resetBuffers();

		LSystemRenderer rend(new lsys::TesselatedGeneric3DTreeContext(level, radius, height, angle));
		rend.contexts[0]->generateModel(level);

		if (!LSystemRenderer::test_mode)
		{
			OGLRendererConfig config = default_ogl_renderer_config;

			config.vert_path = "..\\LSystemRenderer\\default_tess.vert";
			config.frag_path = "..\\LSystemRenderer\\default_tess.frag";
			config.geom_path = "..\\LSystemRenderer\\wireframe.geom";
			config.tesc_path = "..\\LSystemRenderer\\default_tess.tesc";
			config.tese_path = "..\\LSystemRenderer\\default_tess.tese";

			OGLRenderer::renderScene(&rend, lsys::GraphicsTurtle::getVertexBuffer(),
				lsys::GraphicsTurtle::getTransformBuffer(), std::vector<const char *> { "..\\LSystemRenderer\\tree.jpg" }, config);
		}
	}

	void LSystemRenderer::drawMultipleKochSnowflakes(std::size_t level, const std::vector<glm::vec3>& positions,
		const std::vector<float>& lengths, float angle)
	{
		lsys::GraphicsTurtle::resetBuffers();

		LSystemRenderer rend;

		std::size_t snowflakes = positions.size();
		lsys::TurtleState state = lsys::default_turtle_state;
		for (std::size_t i = 0ull; i < snowflakes; ++i)
		{
			state.position = positions[i];
			rend.addContext(new lsys::KochSnowflakeContext(level, lengths[i], angle, state));
			rend.contexts[i]->generateModel(level);
		}

		if (!LSystemRenderer::test_mode)
			OGLRenderer::renderScene(&rend, lsys::GraphicsTurtle::getVertexBuffer(),
				lsys::GraphicsTurtle::getTransformBuffer(), std::vector<const char *> { });
	}

	void LSystemRenderer::drawGeneric3DForest(std::size_t level, int slices, const std::vector<glm::vec3>& positions,
		const std::vector<float>& radii, const std::vector<float>& heights, float angle)
	{
		lsys::GraphicsTurtle::resetBuffers();

		LSystemRenderer rend;

		std::size_t trees = positions.size();
		lsys::TurtleState state = lsys::default_turtle_state;
		for (std::size_t i = 0ull; i < trees; ++i)
		{
			state.position = positions[i];
			rend.addContext(new lsys::Generic3DTreeContext(level, slices, radii[i], heights[i], angle, state));
			rend.contexts[i]->generateModel(level);
		}

		if (!LSystemRenderer::test_mode)
			OGLRenderer::renderScene(&rend, lsys::GraphicsTurtle::getVertexBuffer(),
				lsys::GraphicsTurtle::getTransformBuffer(), std::vector<const char *> { "..\\LSystemRenderer\\tree.jpg" });
	}

}
