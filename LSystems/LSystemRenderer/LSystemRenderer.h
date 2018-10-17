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
		lsys::LSystemContext *context;

		LSystemRenderer(lsys::LSystemContext *lCxt);
		LSystemRenderer(const LSystemRenderer&) = delete;
		LSystemRenderer& operator=(const LSystemRenderer&) = delete;
		~LSystemRenderer();

	public:
		static LSYSTEMRENDERER_API void drawKochCurveA(size_t level, float length, float angle = 90.0f);
		static LSYSTEMRENDERER_API void drawKochCurveB(size_t level, float length, float angle = 90.0f);
		static LSYSTEMRENDERER_API void drawKochCurveC(size_t level, float length, float angle = 90.0f);
		static LSYSTEMRENDERER_API void drawKochCurveD(size_t level, float length, float angle = 90.0f);
		static LSYSTEMRENDERER_API void drawKochCurveE(size_t level, float length, float angle = 90.0f);
		static LSYSTEMRENDERER_API void drawKochCurveF(size_t level, float length, float angle = 90.0f);
		static LSYSTEMRENDERER_API void drawKochCurveG(size_t level, float length, float angle = 90.0f);
		static LSYSTEMRENDERER_API void drawSierpinskiGasket(size_t level, float length, float angle = 60.0f);
		static LSYSTEMRENDERER_API void drawGeneric2DTreeA(size_t level, float length, float angle = 25.7f);
		static LSYSTEMRENDERER_API void drawGeneric2DTreeB(size_t level, float length, float angle = 20.0f);
		static LSYSTEMRENDERER_API void drawGeneric2DTreeC(size_t level, float length, float angle = 22.5f);
		static LSYSTEMRENDERER_API void drawGeneric2DTreeD(size_t level, float length, float angle = 20.0f);
		static LSYSTEMRENDERER_API void drawGeneric2DTreeE(size_t level, float length, float angle = 25.7f);
		static LSYSTEMRENDERER_API void drawGeneric2DTreeF(size_t level, float length, float angle = 22.5f);
		static LSYSTEMRENDERER_API void drawGeneric2DTreeS(size_t level, float length, float angle = 22.5f);
		static LSYSTEMRENDERER_API void drawGeneric2DTreeSD(size_t level, float length, float reduction = 1.456f, float angle = 85.0f);
		static LSYSTEMRENDERER_API void drawHilbertCurve3D(size_t level, int slices, float radius, float length, float angle = 90.0f);
		static LSYSTEMRENDERER_API void drawGeneric3DTree(size_t level, int slices, float radius, float height, float angle = 22.5f);
	};

}

#endif
