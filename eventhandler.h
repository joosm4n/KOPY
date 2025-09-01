
#include <SDL3/SDL.h>
#include "event_enums.h"
#include "macros.h"
#include <array>

namespace KOPY {

	class EventHandler
	{
	private:
		std::array<bool, NUM_KEYS> m_CheckResults;
		bool m_Intialized = false;

	public:
		
		EventHandler() {
			m_Intialized = true;
			m_CheckResults.fill(false);
		}

		bool IsKeyPressed(KOPY_KEY key) {
			ERR_HANDLE(!m_Intialized, "EventHandler not intialized", return false);
			return m_CheckResults.at(key);
		}

		bool EventPoll() {
			ERR_HANDLE(!m_Intialized, "EventHandler not intialized", return false);
			m_CheckResults.fill(false);

			SDL_Event event;
			while (SDL_PollEvent(&event)) {
				switch (event.type)
				{
				case SDL_EVENT_QUIT:
					return false;

				case SDL_EVENT_KEY_DOWN:
					CheckQueue(event.key.key);
				}
			}
			return true;
		}

	private:

		void CheckQueue(SDL_Keycode event_key) {
			KOPY_KEY index = GetIndex((SDLK)event_key);
			m_CheckResults.at(index) = true;
			return;
		}
	};

}
