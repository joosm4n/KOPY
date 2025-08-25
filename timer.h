#pragma once

#include <SDL3/SDL.h>

namespace KOPY {

	class Timer
	{
	private:
		Uint32 m_StartTime;

		Uint32 m_StartFrame;
		Uint32 m_EndFrame;
		Uint32 m_TimeElapsed;

		Uint32 m_CurrUpdate;
		Uint32 m_LastUpdate;
		Uint32 m_CurrFPS;

		int m_FrameRate;
		float m_FrameDelay;

	public:
		Timer();
		Timer(const int frame_rate);
		~Timer();

		inline float deltaTime() const { return (m_CurrUpdate - m_LastUpdate) / 1000.0f;}

		void SetFPS(const int fps);
		void SetStart();
		void SetEnd();

		float GetFrameDelay() const { return m_FrameDelay; }
		int GetFPS() const { return 1 / deltaTime(); }
		float GetElapsedMS() const { return m_TimeElapsed; }
		float GetElapsedSecs() const { return (float)(m_TimeElapsed) / 1000.0f; }

		void FrameDelay();
	};


}