#ifndef LSYSTEMRENDERER_H
#define LSYSTEMRENDERER_H

#include "..\LSystemGenerator\LSystemContext.h"
#include "OGLRenderer.h"

#ifdef LSYSTEMRENDERER_EXPORTS
#define LSYSTEMRENDERER_API __declspec(dllexport)
#else
#define LSYSTEMRENDERER_API __declspec(dllimport)
#endif

namespace lrend
{

	class LSystemRenderer
	{
	private:
		size_t maxLevel;

		lsys::LSystemContext *context;

		LSystemRenderer(size_t maxL, lsys::LSystemContext *lCxt);
		LSystemRenderer(const LSystemRenderer&) = delete;
		LSystemRenderer& operator=(const LSystemRenderer&) = delete;
		~LSystemRenderer();

	public:
		void levelUp();
		void levelDown();

		static LSYSTEMRENDERER_API void drawKochSnowflake(size_t level, float length, float angle = 60.0f);
		static LSYSTEMRENDERER_API void drawKochIslandA(size_t level, float length, float angle = 90.0f);
		static LSYSTEMRENDERER_API void drawKochIslandB(size_t level, float length, float angle = 90.0f);
		static LSYSTEMRENDERER_API void drawKochIslandC(size_t level, float length, float angle = 90.0f);
		static LSYSTEMRENDERER_API void drawKochIslandD(size_t level, float length, float angle = 90.0f);
		static LSYSTEMRENDERER_API void drawKochIslandE(size_t level, float length, float angle = 90.0f);
		static LSYSTEMRENDERER_API void drawKochIslandF(size_t level, float length, float angle = 90.0f);
		static LSYSTEMRENDERER_API void drawKochIslandG(size_t level, float length, float angle = 90.0f);
		static LSYSTEMRENDERER_API void drawDragonCurve(size_t level, float length, float angle = 90.0f);
		static LSYSTEMRENDERER_API void drawSierpinskiGasket(size_t level, float length, float angle = 60.0f);
		static LSYSTEMRENDERER_API void drawGeneric2DTreeA(size_t level, float length, float angle = 25.7f);
		static LSYSTEMRENDERER_API void drawGeneric2DTreeB(size_t level, float length, float angle = 20.0f);
		static LSYSTEMRENDERER_API void drawGeneric2DTreeC(size_t level, float length, float angle = 22.5f);
		static LSYSTEMRENDERER_API void drawGeneric2DTreeD(size_t level, float length, float angle = 20.0f);
		static LSYSTEMRENDERER_API void drawGeneric2DTreeE(size_t level, float length, float angle = 25.7f);
		static LSYSTEMRENDERER_API void drawGeneric2DTreeF(size_t level, float length, float angle = 22.5f);
		static LSYSTEMRENDERER_API void drawGeneric2DTreeS(size_t level, float length, float angle = 22.5f);
		static LSYSTEMRENDERER_API void drawGeneric2DTreeSD(size_t level, float length,
			float reduction = 1.456f, float angle = 85.0f);
		static LSYSTEMRENDERER_API void drawHilbertCurve3D(size_t level, float width, float length,
			float red = 0.0f, float green = 0.0f, float blue = 0.0f, float angle = 90.0f);
		static LSYSTEMRENDERER_API void drawGeneric3DTree(size_t level, int slices, float radius,
			float height, float angle = 22.5f);
	};

}

#endif
