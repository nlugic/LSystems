#ifndef LSYSTEMRENDERER_H
#define LSYSTEMRENDERER_H

#include "..\LSystemGenerator\LSystemContext.h"
#include "OGLRenderer.h"

namespace lrend
{

	class LSystemRenderer
	{
	private:
		std::size_t maxLevel;
		lsys::LSystemContext *context;

		LSystemRenderer(std::size_t maxL, lsys::LSystemContext *lCxt);
		LSystemRenderer(const LSystemRenderer&) = delete;
		LSystemRenderer& operator=(const LSystemRenderer&) = delete;
		~LSystemRenderer();

	public:
		void levelUp();
		void levelDown();

		static void setTestMode(bool test);

		static void drawKochSnowflake(std::size_t level, float length, float angle = 60.0f);
		static void drawKochIslandA(std::size_t level, float length, float angle = 90.0f);
		static void drawKochIslandB(std::size_t level, float length, float angle = 90.0f);
		static void drawKochIslandC(std::size_t level, float length, float angle = 90.0f);
		static void drawKochIslandD(std::size_t level, float length, float angle = 90.0f);
		static void drawKochIslandE(std::size_t level, float length, float angle = 90.0f);
		static void drawKochIslandF(std::size_t level, float length, float angle = 90.0f);
		static void drawKochIslandG(std::size_t level, float length, float angle = 90.0f);
		static void drawDragonCurve(std::size_t level, float length, float angle = 90.0f);
		static void drawSierpinskiGasket(std::size_t level, float length, float angle = 60.0f);
		static void drawGeneric2DTreeA(std::size_t level, float length, float angle = 25.7f);
		static void drawGeneric2DTreeB(std::size_t level, float length, float angle = 20.0f);
		static void drawGeneric2DTreeC(std::size_t level, float length, float angle = 22.5f);
		static void drawGeneric2DTreeD(std::size_t level, float length, float angle = 20.0f);
		static void drawGeneric2DTreeE(std::size_t level, float length, float angle = 25.7f);
		static void drawGeneric2DTreeF(std::size_t level, float length, float angle = 22.5f);
		static void drawGeneric2DTreeS(std::size_t level, float length, float angle = 22.5f);
		static void drawGeneric2DTreeSD(std::size_t level, float length,
			float reduction = 1.456f, float angle = 85.0f);
		static void drawHilbertCurve3D(std::size_t level, float width, float length,
			float red = 0.0f, float green = 0.0f, float blue = 0.0f, float angle = 90.0f);
		static void drawGeneric3DTree(std::size_t level, int slices, float radius,
			float height, float angle = 22.5f);
	};

}

#endif
