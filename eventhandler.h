
#include <SDL3/SDL.h>
#include "enums.h"
#include "macros.h"
#include <array>

namespace KOPY {

	static KO_KEY GetIndex(SDLK sdlKey)
	{
		switch (sdlKey) 
		{
		case SDLK::SDL_UNKNOWN				   : return KO_KEY::UNKNOWN		   ;
		case SDLK::SDL_RETURN                  : return KO_KEY::RETURN         ;
		case SDLK::SDL_ESCAPE                  : return KO_KEY::ESCAPE         ;
		case SDLK::SDL_BACKSPACE               : return KO_KEY::BACKSPACE      ;
		case SDLK::SDL_TAB                     : return KO_KEY::TAB            ;
		case SDLK::SDL_SPACE                   : return KO_KEY::SPACE          ;
		case SDLK::SDL_EXCLAIM                 : return KO_KEY::EXCLAIM        ;
		case SDLK::SDL_DBLAPOSTROPHE           : return KO_KEY::DBLAPOSTROPHE  ;
		case SDLK::SDL_HASH                    : return KO_KEY::HASH           ;
		case SDLK::SDL_DOLLAR                  : return KO_KEY::DOLLAR         ;
		case SDLK::SDL_PERCENT                 : return KO_KEY::PERCENT        ;
		case SDLK::SDL_AMPERSAND               : return KO_KEY::AMPERSAND      ;
		case SDLK::SDL_APOSTROPHE              : return KO_KEY::APOSTROPHE     ;
		case SDLK::SDL_LEFTPAREN               : return KO_KEY::LEFTPAREN      ;
		case SDLK::SDL_RIGHTPAREN              : return KO_KEY::RIGHTPAREN     ;
		case SDLK::SDL_ASTERISK                : return KO_KEY::ASTERISK       ;
		case SDLK::SDL_PLUS                    : return KO_KEY::PLUS           ;
		case SDLK::SDL_COMMA                   : return KO_KEY::COMMA          ;
		case SDLK::SDL_MINUS                   : return KO_KEY::MINUS          ;
		case SDLK::SDL_PERIOD                  : return KO_KEY::PERIOD         ;
		case SDLK::SDL_SLASH                   : return KO_KEY::SLASH          ;
		case SDLK::SDL_NUM_0                   : return KO_KEY::NUM_0          ;
		case SDLK::SDL_NUM_1                   : return KO_KEY::NUM_1          ;
		case SDLK::SDL_NUM_2                   : return KO_KEY::NUM_2          ;
		case SDLK::SDL_NUM_3                   : return KO_KEY::NUM_3          ;
		case SDLK::SDL_NUM_4                   : return KO_KEY::NUM_4          ;
		case SDLK::SDL_NUM_5                   : return KO_KEY::NUM_5          ;
		case SDLK::SDL_NUM_6                   : return KO_KEY::NUM_6          ;
		case SDLK::SDL_NUM_7                   : return KO_KEY::NUM_7          ;
		case SDLK::SDL_NUM_8                   : return KO_KEY::NUM_8          ;
		case SDLK::SDL_NUM_9				   : return KO_KEY::NUM_9          ;
		case SDLK::SDL_COLON				   : return KO_KEY::COLON          ;
		case SDLK::SDL_SEMICOLON			   : return KO_KEY::SEMICOLON      ;
		case SDLK::SDL_LESS                    : return KO_KEY::LESS           ;
		case SDLK::SDL_EQUALS                  : return KO_KEY::EQUALS         ;
		case SDLK::SDL_GREATER                 : return KO_KEY::GREATER        ;
		case SDLK::SDL_QUESTION                : return KO_KEY::QUESTION       ;
		case SDLK::SDL_AT                      : return KO_KEY::AT             ;
		case SDLK::SDL_LEFTBRACKET             : return KO_KEY::LEFTBRACKET    ;
		case SDLK::SDL_BACKSLASH               : return KO_KEY::BACKSLASH      ;
		case SDLK::SDL_RIGHTBRACKET            : return KO_KEY::RIGHTBRACKET   ;
		case SDLK::SDL_CARET                   : return KO_KEY::CARET          ;
		case SDLK::SDL_UNDERSCORE              : return KO_KEY::UNDERSCORE     ;
		case SDLK::SDL_GRAVE                   : return KO_KEY::GRAVE          ;
		case SDLK::SDL_A                       : return KO_KEY::A              ;
		case SDLK::SDL_B                       : return KO_KEY::B              ;
		case SDLK::SDL_C                       : return KO_KEY::C              ;
		case SDLK::SDL_D                       : return KO_KEY::D              ;
		case SDLK::SDL_E                       : return KO_KEY::E              ;
		case SDLK::SDL_F                       : return KO_KEY::F              ;
		case SDLK::SDL_G                       : return KO_KEY::G              ;
		case SDLK::SDL_H                       : return KO_KEY::H              ;
		case SDLK::SDL_I                       : return KO_KEY::I              ;
		case SDLK::SDL_J                       : return KO_KEY::J              ;
		case SDLK::SDL_K                       : return KO_KEY::K              ;
		case SDLK::SDL_L                       : return KO_KEY::L              ;
		case SDLK::SDL_M                       : return KO_KEY::M              ;
		case SDLK::SDL_N                       : return KO_KEY::N              ;
		case SDLK::SDL_O                       : return KO_KEY::O              ;
		case SDLK::SDL_P                       : return KO_KEY::P              ;
		case SDLK::SDL_Q                       : return KO_KEY::Q              ;
		case SDLK::SDL_R                       : return KO_KEY::R              ;
		case SDLK::SDL_S                       : return KO_KEY::S              ;
		case SDLK::SDL_T                       : return KO_KEY::T              ;
		case SDLK::SDL_U                       : return KO_KEY::U              ;
		case SDLK::SDL_V                       : return KO_KEY::V              ;
		case SDLK::SDL_W                       : return KO_KEY::W              ;
		case SDLK::SDL_X                       : return KO_KEY::X              ;
		case SDLK::SDL_Y                       : return KO_KEY::Y              ;
		case SDLK::SDL_Z                       : return KO_KEY::Z              ;
		case SDLK::SDL_LEFTBRACE               : return KO_KEY::LEFTBRACE      ;
		case SDLK::SDL_PIPE                    : return KO_KEY::PIPE           ;
		case SDLK::SDL_RIGHTBRACE              : return KO_KEY::RIGHTBRACE     ;
		case SDLK::SDL_TILDE                   : return KO_KEY::TILDE          ;
		case SDLK::SDL_DELETE_KEY              : return KO_KEY::DELETE_KEY     ;
		case SDLK::SDL_PLUSMINUS               : return KO_KEY::PLUSMINUS      ;
		}
	};
	static SDLK GetSDLK(KO_KEY koKey)
	{
		switch (koKey) 
		{
		case KO_KEY::UNKNOWN        : return SDLK::SDL_UNKNOWN;
		case KO_KEY::RETURN         : return SDLK::SDL_RETURN;
		case KO_KEY::ESCAPE         : return SDLK::SDL_ESCAPE;
		case KO_KEY::BACKSPACE      : return SDLK::SDL_BACKSPACE;
		case KO_KEY::TAB            : return SDLK::SDL_TAB;
		case KO_KEY::SPACE          : return SDLK::SDL_SPACE;
		case KO_KEY::EXCLAIM        : return SDLK::SDL_EXCLAIM;
		case KO_KEY::DBLAPOSTROPHE  : return SDLK::SDL_DBLAPOSTROPHE;
		case KO_KEY::HASH           : return SDLK::SDL_HASH;
		case KO_KEY::DOLLAR         : return SDLK::SDL_DOLLAR;
		case KO_KEY::PERCENT        : return SDLK::SDL_PERCENT;
		case KO_KEY::AMPERSAND      : return SDLK::SDL_AMPERSAND;
		case KO_KEY::APOSTROPHE     : return SDLK::SDL_APOSTROPHE;
		case KO_KEY::LEFTPAREN      : return SDLK::SDL_LEFTPAREN;
		case KO_KEY::RIGHTPAREN     : return SDLK::SDL_RIGHTPAREN;
		case KO_KEY::ASTERISK       : return SDLK::SDL_ASTERISK;
		case KO_KEY::PLUS           : return SDLK::SDL_PLUS;
		case KO_KEY::COMMA          : return SDLK::SDL_COMMA;
		case KO_KEY::MINUS          : return SDLK::SDL_MINUS;
		case KO_KEY::PERIOD         : return SDLK::SDL_PERIOD;
		case KO_KEY::SLASH          : return SDLK::SDL_SLASH;
		case KO_KEY::NUM_0          : return SDLK::SDL_NUM_0;
		case KO_KEY::NUM_1          : return SDLK::SDL_NUM_1;
		case KO_KEY::NUM_2          : return SDLK::SDL_NUM_2;
		case KO_KEY::NUM_3          : return SDLK::SDL_NUM_3;
		case KO_KEY::NUM_4          : return SDLK::SDL_NUM_4;
		case KO_KEY::NUM_5          : return SDLK::SDL_NUM_5;
		case KO_KEY::NUM_6          : return SDLK::SDL_NUM_6;
		case KO_KEY::NUM_7          : return SDLK::SDL_NUM_7;
		case KO_KEY::NUM_8          : return SDLK::SDL_NUM_8;
		case KO_KEY::NUM_9          : return SDLK::SDL_NUM_9;
		case KO_KEY::COLON          : return SDLK::SDL_COLON;
		case KO_KEY::SEMICOLON      : return SDLK::SDL_SEMICOLON;
		case KO_KEY::LESS           : return SDLK::SDL_LESS;
		case KO_KEY::EQUALS         : return SDLK::SDL_EQUALS;
		case KO_KEY::GREATER        : return SDLK::SDL_GREATER;
		case KO_KEY::QUESTION       : return SDLK::SDL_QUESTION;
		case KO_KEY::AT             : return SDLK::SDL_AT;
		case KO_KEY::LEFTBRACKET    : return SDLK::SDL_LEFTBRACKET;
		case KO_KEY::BACKSLASH      : return SDLK::SDL_BACKSLASH;
		case KO_KEY::RIGHTBRACKET   : return SDLK::SDL_RIGHTBRACKET;
		case KO_KEY::CARET          : return SDLK::SDL_CARET;
		case KO_KEY::UNDERSCORE     : return SDLK::SDL_UNDERSCORE;
		case KO_KEY::GRAVE          : return SDLK::SDL_GRAVE;
		case KO_KEY::A              : return SDLK::SDL_A;
		case KO_KEY::B              : return SDLK::SDL_B;
		case KO_KEY::C              : return SDLK::SDL_C;
		case KO_KEY::D              : return SDLK::SDL_D;
		case KO_KEY::E              : return SDLK::SDL_E;
		case KO_KEY::F              : return SDLK::SDL_F;
		case KO_KEY::G              : return SDLK::SDL_G;
		case KO_KEY::H              : return SDLK::SDL_H;
		case KO_KEY::I              : return SDLK::SDL_I;
		case KO_KEY::J              : return SDLK::SDL_J;
		case KO_KEY::K              : return SDLK::SDL_K;
		case KO_KEY::L              : return SDLK::SDL_L;
		case KO_KEY::M              : return SDLK::SDL_M;
		case KO_KEY::N              : return SDLK::SDL_N;
		case KO_KEY::O              : return SDLK::SDL_O;
		case KO_KEY::P              : return SDLK::SDL_P;
		case KO_KEY::Q              : return SDLK::SDL_Q;
		case KO_KEY::R              : return SDLK::SDL_R;
		case KO_KEY::S              : return SDLK::SDL_S;
		case KO_KEY::T              : return SDLK::SDL_T;
		case KO_KEY::U              : return SDLK::SDL_U;
		case KO_KEY::V              : return SDLK::SDL_V;
		case KO_KEY::W              : return SDLK::SDL_W;
		case KO_KEY::X              : return SDLK::SDL_X;
		case KO_KEY::Y              : return SDLK::SDL_Y;
		case KO_KEY::Z              : return SDLK::SDL_Z;
		case KO_KEY::LEFTBRACE      : return SDLK::SDL_LEFTBRACE;
		case KO_KEY::PIPE           : return SDLK::SDL_PIPE;
		case KO_KEY::RIGHTBRACE     : return SDLK::SDL_RIGHTBRACE;
		case KO_KEY::TILDE          : return SDLK::SDL_TILDE;
		case KO_KEY::DELETE_KEY     : return SDLK::SDL_DELETE_KEY;
		case KO_KEY::PLUSMINUS      : return SDLK::SDL_PLUSMINUS;
		}
	};

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

		bool IsKeyPressed(KO_KEY key) {
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
			KO_KEY index = GetIndex((SDLK)event_key);
			m_CheckResults.at(index) = true;
			return;
		}
	};

}
