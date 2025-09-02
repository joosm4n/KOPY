
#include "timer.h"

namespace KOPY {

	// Uint32 ticks = SDL_GetTicks
	// - Gives ticks since SDL initalized
	// - In MILLISECONDS

	Timer::Timer()
	{
		m_StartTime = SDL_GetTicks();
		m_CurrUpdate = m_StartTime;
		SetFPS(30);
		SDL_Delay(100);
		SetStart();
	}
	Timer::Timer(const int frame_rate)
	{
		m_StartTime = SDL_GetTicks();
		m_CurrUpdate = m_StartTime;
		SetFPS(frame_rate);
		SDL_Delay(100);
		SetStart();
	}

	Timer::~Timer()
	{
		return;
	}

	void Timer::SetFPS(const int fps)
	{
		m_FrameRate = fps;
		m_FrameDelay = 1000.0f / m_FrameRate;
	}

	void Timer::SetStart() 
	{
		m_LastUpdate = m_CurrUpdate;
		m_CurrUpdate = SDL_GetTicks();
		m_StartFrame = SDL_GetPerformanceCounter();
	}
	void Timer::SetEnd()
	{ 
		m_EndFrame = SDL_GetPerformanceCounter();
		m_TimeElapsed = (m_EndFrame - m_StartFrame) / (float)SDL_GetPerformanceFrequency() * 1000.0f;
	}

	void Timer::FrameDelay()
	{
		SetEnd();
		if (m_TimeElapsed < m_FrameDelay)
			SDL_Delay(floor(m_FrameDelay - m_TimeElapsed));
		else
			SDL_Delay(1);
	}

}


