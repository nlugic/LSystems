
#include "..\LSystemRenderer\LSystemRenderer.h"

#ifdef _DEBUG
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

#pragma comment (lib, "..\\x64\\Debug\\LSystemGenerator.lib")
#else
#pragma comment (lib, "..\\x64\\Release\\LSystemGenerator.lib")
#endif

void benchmark(unsigned char repeat = 3U)
{
	lrend::LSystemRenderer::setTestMode(true);

	for (unsigned char i = 1U; i <= 5U; ++i)
		for (unsigned char j = 0U; j < repeat; ++j)
			lrend::LSystemRenderer::drawKochSnowflake(i, 2.0f);
	for (unsigned char i = 1U; i <= 4U; ++i)
		for (unsigned char j = 0U; j < repeat; ++j)
			lrend::LSystemRenderer::drawKochIslandA(i, 2.0f);
	for (unsigned char i = 1U; i <= 4U; ++i)
		for (unsigned char j = 0U; j < repeat; ++j)
			lrend::LSystemRenderer::drawKochIslandB(i, 0.1f);
	for (unsigned char i = 1U; i <= 4U; ++i)
		for (unsigned char j = 0U; j < repeat; ++j)
			lrend::LSystemRenderer::drawKochIslandC(i, 0.1f);
	for (unsigned char i = 1U; i <= 4U; ++i)
		for (unsigned char j = 0U; j < repeat; ++j)
			lrend::LSystemRenderer::drawKochIslandD(i, 0.1f);
	for (unsigned char i = 1U; i <= 5U; ++i)
		for (unsigned char j = 0U; j < repeat; ++j)
			lrend::LSystemRenderer::drawKochIslandE(i, 0.1f);
	for (unsigned char i = 1U; i <= 5U; ++i)
		for (unsigned char j = 0U; j < repeat; ++j)
			lrend::LSystemRenderer::drawKochIslandF(i, 0.1f);
	for (unsigned char i = 1U; i <= 5U; ++i)
		for (unsigned char j = 0U; j < repeat; ++j)
			lrend::LSystemRenderer::drawKochIslandG(i, 0.1f);
	for (unsigned char i = 1U; i <= 14U; ++i)
		for (unsigned char j = 0U; j < repeat; ++j)
			lrend::LSystemRenderer::drawDragonCurve(i, 0.1f);
	for (unsigned char i = 1U; i <= 8U; ++i)
		for (unsigned char j = 0U; j < repeat; ++j)
			lrend::LSystemRenderer::drawSierpinskiGasket(i, 0.1f);
	for (unsigned char i = 1U; i <= 6U; ++i)
		for (unsigned char j = 0U; j < repeat; ++j)
			lrend::LSystemRenderer::drawGeneric2DTreeA(i, 0.05f);
	for (unsigned char i = 1U; i <= 6U; ++i)
		for (unsigned char j = 0U; j < repeat; ++j)
			lrend::LSystemRenderer::drawGeneric2DTreeB(i, 0.05f);
	for (unsigned char i = 1U; i <= 5U; ++i)
		for (unsigned char j = 0U; j < repeat; ++j)
			lrend::LSystemRenderer::drawGeneric2DTreeC(i, 0.05f);
	for (unsigned char i = 1U; i <= 7U; ++i)
		for (unsigned char j = 0U; j < repeat; ++j)
			lrend::LSystemRenderer::drawGeneric2DTreeD(i, 0.05f);
	for (unsigned char i = 1U; i <= 7U; ++i)
		for (unsigned char j = 0U; j < repeat; ++j)
			lrend::LSystemRenderer::drawGeneric2DTreeE(i, 0.05f);
	for (unsigned char i = 1U; i <= 5U; ++i)
		for (unsigned char j = 0U; j < repeat; ++j)
			lrend::LSystemRenderer::drawGeneric2DTreeF(i, 0.05f);
	for (unsigned char i = 1U; i <= 15U; ++i)
		for (unsigned char j = 0U; j < repeat; ++j)
			lrend::LSystemRenderer::drawGeneric2DTreeSD(i, 0.5f);
	for (unsigned char i = 1U; i <= 4U; ++i)
		for (unsigned char j = 0U; j < repeat; ++j)
			lrend::LSystemRenderer::drawHilbertCurve3D(i, 0.025f, 0.25f, 0.3f, 0.6f, 0.4f);
	for (unsigned char i = 4U; i <= 32U; i += 4U)
		for (unsigned char j = 1U; j <= 7U; ++j)
			for (unsigned char k = 0U; k < repeat; ++k)
				lrend::LSystemRenderer::drawGeneric3DTree(j, i, 0.05f, 0.2f);
}

int main(int argc, char **argv)
{
	//lrend::LSystemRenderer::drawKochSnowflake(5, 2.0f);
	//lrend::LSystemRenderer::drawKochIslandA(4, 2.0f);
	//lrend::LSystemRenderer::drawKochIslandB(4, 0.1f);
	//lrend::LSystemRenderer::drawKochIslandC(4, 0.1f);
	//lrend::LSystemRenderer::drawKochIslandD(4, 0.1f);
	//lrend::LSystemRenderer::drawKochIslandE(5, 0.1f);
	//lrend::LSystemRenderer::drawKochIslandF(5, 0.1f);
	//lrend::LSystemRenderer::drawKochIslandG(5, 0.1f);
	//lrend::LSystemRenderer::drawDragonCurve(14, 0.1f);
	//lrend::LSystemRenderer::drawSierpinskiGasket(8, 0.1f);
	//lrend::LSystemRenderer::drawGeneric2DTreeA(6, 0.05f);
	//lrend::LSystemRenderer::drawGeneric2DTreeB(6, 0.05f);
	//lrend::LSystemRenderer::drawGeneric2DTreeC(5, 0.05f);
	//lrend::LSystemRenderer::drawGeneric2DTreeD(7, 0.05f);
	//lrend::LSystemRenderer::drawGeneric2DTreeE(7, 0.05f);
	//lrend::LSystemRenderer::drawGeneric2DTreeF(5, 0.05f);
	//lrend::LSystemRenderer::drawGeneric2DTreeS(5, 0.05f);
	//lrend::LSystemRenderer::drawGeneric2DTreeS(5, 0.05f);
	//lrend::LSystemRenderer::drawGeneric2DTreeS(5, 0.05f);
	//lrend::LSystemRenderer::drawGeneric2DTreeS(5, 0.05f);
	//lrend::LSystemRenderer::drawGeneric2DTreeS(5, 0.05f);
	//lrend::LSystemRenderer::drawGeneric2DTreeSD(15, 0.5f);
	lrend::LSystemRenderer::drawHilbertCurve3D(6, 0.025f, 0.4f, 0.3f, 0.6f, 0.4f);
	//lrend::LSystemRenderer::drawGeneric3DTree(7, 8, 0.1f, 0.15f);
	
	//lrend::LSystemRenderer::drawTesselatedGeneric3DTree(7, 0.1f, 0.2f);
	
	//std::vector<glm::vec3> positions { glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(5.0f, 0.0f, 5.0f), glm::vec3(-4.0f, 0.0f, 5.0f),
	//	glm::vec3(4.0f, 0.0f, -5.0f), glm::vec3(-5.0f, 0.0f, -4.0f), glm::vec3(-6.0f, 0.0f, 2.0f), glm::vec3(2.0f, 0.0f, -6.0f) };
	//lrend::LSystemRenderer::drawMultipleKochSnowflakes(5, positions, std::vector<float> { 1.0f, 1.1f, 0.9f, 1.3f, 1.2f, 0.95f, 1.05f });
	//lrend::LSystemRenderer::drawGeneric3DForest(7, 8, positions, std::vector<float> { 0.1f, 0.08f, 0.12f, 0.05f, 0.09f, 0.11f, 0.14f },
	//	std::vector<float> { 0.15f, 0.14f, 0.2f, 0.13f, 0.16f, 0.14f, 0.22f });

	//benchmark();

#ifdef _DEBUG
	_CrtDumpMemoryLeaks();
#endif
	
	return 0;
}
