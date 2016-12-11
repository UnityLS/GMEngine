#pragma once

#include "GMStdC.h"
#include <memory>
#include <array>

namespace game
{
	class GM_DLL GraphicsEngine
	{
		friend class Director;
	public:
		struct GM_DLL Parameters
		{
			Parameters() :
				Width(1.0f),
				Height(1.0f),
				ClearDepth(1.0f),
				ClearStencil(0)
			{
				ClearColor.fill(0.0f);
				ClearColor[3] = 1.0f;
			}
			Parameters(float w, float h, std::array<float, 4> const& clearColor, float clearDepth, float clearStencil) :
				Width(w),
				Height(h),
				ClearDepth(clearDepth),
				ClearStencil(clearStencil),
				ClearColor(clearColor)
			{}

			float Width, Height;
			float ClearDepth;
			unsigned int ClearStencil;
			std::array<float, 4> ClearColor;
		};
	public:
		virtual ~GraphicsEngine(){};

		virtual bool initialize() = 0;
		virtual void terminate() = 0;

		virtual void setViewport(int x, int y, int w, int h) = 0;
		virtual void getViewport(int& x, int& y, int& w, int& h) const = 0;
		virtual void setDepthRange(float zMin, float zMax) = 0;
		virtual void getDepthRange(float& zMin, float& zMax) const = 0;

		virtual bool resize(unsigned int w, unsigned int h) = 0;

		inline void setClearColor(std::array<float, 4> const& clearColor) { mClearColor = clearColor; }
		inline void setClearDepth(float clearDepth) { mClearDepth = clearDepth; }
		inline void setClearStencil(unsigned int clearStencil) { mClearStencil = clearStencil; }
		inline std::array<float, 4> const& getClearColor() const { return mClearColor; }
		inline float getClearDepth() const { return mClearDepth; }
		inline unsigned int getClearStencil() const { return mClearStencil; }
		virtual void displayColorBuffer(unsigned int syncInterval) = 0;

		virtual void clearColorBuffer() = 0;

		virtual void clearDepthBuffer() = 0;

		virtual void clearStencilBuffer() = 0;

		virtual void clearBuffers() = 0;

//		virtual void clearColorBuffer(int x, int y, int w, int h) = 0;

//		virtual void clearDepthBuffer(int x, int y, int w, int h) = 0;

//		virtual void clearStencilBuffer(int x, int y, int w, int h) = 0;

//		virtual void clearBuffers(int x, int y, int w, int h) = 0;

		virtual void flush() = 0;
	protected:
		GraphicsEngine(Parameters& param) :
			mViewWidth(param.Width),
			mViewHeight(param.Height),
			mClearDepth(param.ClearDepth),
			mClearStencil(param.ClearStencil),
			mClearColor(param.ClearColor)
		{}
		GraphicsEngine(const GraphicsEngine&) = delete;

		static GraphicsEngine* create(GraphicsEngine::Parameters& param);

	protected:
		unsigned int mViewWidth, mViewHeight;

		// Clear values.
		std::array<float, 4> mClearColor;
		float mClearDepth;
		unsigned int mClearStencil;
	};
}