
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

		std::array<bool, NUM_MOUSE_BUTTONS> m_MouseButtons;
		Vec2 m_MousePos;

	public:
		
		EventHandler() {
			m_Intialized = true;
			m_CheckResults.fill(false);
		}

		bool IsKeyPressed(KOPY_KEY key) const {
			ERR_HANDLE(!m_Intialized, "EventHandler not intialized", return false);
			return m_CheckResults.at(key);
		}

		bool MouseButtonPressed(KOPY_MOUSE_BUTTON button) const {
			ERR_HANDLE(!m_Intialized, "EventHandler not intialized", return false);
			return m_MouseButtons.at(button);
		}

		inline float GetMouseX() const {
			return m_MousePos.x;
		}

		inline float GetMouseY() const {
			return m_MousePos.y;
		}

		inline Vec2 GetMousePos() const {
			return m_MousePos;
		}



		bool EventPoll() {
			ERR_HANDLE(!m_Intialized, "EventHandler not intialized", return false);
			m_CheckResults.fill(false);
			m_MouseButtons.fill(false);

			SDL_MouseButtonFlags state = SDL_GetMouseState(&m_MousePos.x, &m_MousePos.y);
			bool nonePressed = true;
			for (uint8_t i = 1; i < NUM_MOUSE_BUTTONS; i++) {
				if (state & SDL_BUTTON_MASK(i)) {
					m_MouseButtons.at(i) = true;
					nonePressed = false;
				}
			}
			if (nonePressed) {
				m_MouseButtons.at(0) = true;
			}

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
