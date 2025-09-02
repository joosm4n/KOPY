#pragma once

namespace KOPY {

	constexpr unsigned int NUM_KEYS = 256;
	constexpr unsigned int NUM_MOUSE_BUTTONS = 6;

	enum KOPY_MOUSE_BUTTON {
		MOUSE_NONE	   = 0,
		MOUSE_LEFT     = 1,
		MOUSE_MIDDLE   = 2,
		MOUSE_RIGHT    = 3,
		MOUSE_X1       = 4,
		MOUSE_X2       = 5
	};

	enum KOPY_KEY {
		 UNKNOWN           
		,RETURN                
		,ESCAPE                
		,BACKSPACE             
		,TAB                   
		,SPACE                 
		,EXCLAIM               
		,DBLAPOSTROPHE         
		,HASH                  
		,DOLLAR                
		,PERCENT               
		,AMPERSAND             
		,APOSTROPHE            
		,LEFTPAREN             
		,RIGHTPAREN            
		,ASTERISK              
		,PLUS                  
		,COMMA                 
		,MINUS                 
		,PERIOD                
		,SLASH                 
		,NUM_0                 
		,NUM_1                 
		,NUM_2                 
		,NUM_3                 
		,NUM_4                 
		,NUM_5                 
		,NUM_6                 
		,NUM_7                 
		,NUM_8                 
		,NUM_9                 
		,COLON                 
		,SEMICOLON             
		,LESS                  
		,EQUALS                
		,GREATER               
		,QUESTION              
		,AT                    
		,LEFTBRACKET           
		,BACKSLASH             
		,RIGHTBRACKET          
		,CARET                 
		,UNDERSCORE            
		,GRAVE                 
		,A                     
		,B                     
		,C                     
		,D                     
		,E                     
		,F                     
		,G                     
		,H                     
		,I                     
		,J                     
		,K                     
		,L                     
		,M                     
		,N                     
		,O                     
		,P                     
		,Q                     
		,R                     
		,S                     
		,T                     
		,U                     
		,V                     
		,W                     
		,X                     
		,Y                     
		,Z                     
		,LEFTBRACE             
		,PIPE                  
		,RIGHTBRACE            
		,TILDE                 
		,DELETE_KEY            
		,PLUSMINUS
		,CAPSLOCK
		,F1
		,F2
		,F3
		,F4
		,F5
		,F6
		,F7
		,F8
		,F9
		,F10
		,F11
		,F12
		,PRINTSCREEN
		,SCROLLLOCK
		,PAUSE
		,INSERT
		,HOME
		,PAGEUP
		,END
		,PAGEDOWN
		,RIGHT
		,LEFT
		,DOWN
		,UP
		,NUMLOCKCLEAR
		,KP_DIVIDE
		,KP_MULTIPLY
		,KP_MINUS
		,KP_PLUS
		,KP_ENTER
		,KP_1
		,KP_2
		,KP_3
		,KP_4
		,KP_5
		,KP_6
		,KP_7
		,KP_8
		,KP_9
		,KP_0
		,KP_PERIOD
		,APPLICATION
		,POWER
		,KP_EQUALS
		,F13
		,F14
		,F15
		,F16
		,F17
		,F18
		,F19
		,F20
		,F21
		,F22
		,F23
		,F24
		,EXECUTE
		,HELP
		,MENU
		,SELECT
		,STOP
		,AGAIN
		,UNDO
		,CUT
		,COPY
		,PASTE
		,FIND
		,MUTE
		,VOLUMEUP
		,VOLUMEDOWN
		,KP_COMMA
		,KP_EQUALSAS400
		,ALTERASE
		,SYSREQ
		,CANCEL
		,CLEAR
		,PRIOR
		,RETURN2
		,SEPARATOR
		,OUT_KEY
		,OPER
		,CLEARAGAIN
		,CRSEL
		,EXSEL
		,KP_00
		,KP_000
		,THOUSANDSSEPARATOR
		,DECIMALSEPARATOR
		,CURRENCYUNIT
		,CURRENCYSUBUNIT
		,KP_LEFTPAREN
		,KP_RIGHTPAREN
		,KP_LEFTBRACE
		,KP_RIGHTBRACE
		,KP_TAB
		,KP_BACKSPACE
		,KP_A
		,KP_B
		,KP_C
		,KP_D
		,KP_E
		,KP_F
		,KP_XOR
		,KP_POWER
		,KP_PERCENT
		,KP_LESS
		,KP_GREATER
		,KP_AMPERSAND
		,KP_DBLAMPERSAND
		,KP_VERTICALBAR
		,KP_DBLVERTICALBAR
		,KP_COLON
		,KP_HASH
		,KP_SPACE
		,KP_AT
		,KP_EXCLAM
		,KP_MEMSTORE
		,KP_MEMRECALL
		,KP_MEMCLEAR
		,KP_MEMADD
		,KP_MEMSUBTRACT
		,KP_MEMMULTIPLY
		,KP_MEMDIVIDE
		,KP_PLUSMINUS
		,KP_CLEAR
		,KP_CLEARENTRY
		,KP_BINARY
		,KP_OCTAL
		,KP_DECIMAL
		,KP_HEXADECIMAL
		,LCTRL
		,LSHIFT
		,LALT
		,LGUI
		,RCTRL
		,RSHIFT
		,RALT
		,RGUI
		,MODE
		,SLEEP
		,WAKE
		,CHANNEL_INCREMENT
		,CHANNEL_DECREMENT
		,MEDIA_PLAY
		,MEDIA_PAUSE
		,MEDIA_RECORD
		,MEDIA_FAST_FORWARD
		,MEDIA_REWIND
		,MEDIA_NEXT_TRACK
		,MEDIA_PREVIOUS_TRACK
		,MEDIA_STOP
		,MEDIA_EJECT
		,MEDIA_PLAY_PAUSE
		,MEDIA_SELECT
		,AC_NEW
		,AC_OPEN
		,AC_CLOSE
		,AC_EXIT
		,AC_SAVE
		,AC_PRINT
		,AC_PROPERTIES
		,AC_SEARCH
		,AC_HOME
		,AC_BACK
		,AC_FORWARD
		,AC_STOP
		,AC_REFRESH
		,AC_BOOKMARKS
		,SOFTLEFT
		,SOFTRIGHT
		,CALL
		,ENDCALL
		,LEFT_TAB
		,LEVEL5_SHIFT
		,MULTI_KEY_COMPOSE
		,LMETA
		,RMETA
		,LHYPER
		,RHYPER
	};

	enum SDLK {
		SDL_UNKNOWN                = 0x00000000u,/**< 0 */
		SDL_RETURN                 = 0x0000000du,/**< '\r' */
		SDL_ESCAPE                 = 0x0000001bu,/**< '\x1B' */
		SDL_BACKSPACE              = 0x00000008u,/**< '\b' */
		SDL_TAB                    = 0x00000009u,/**< '\t' */
		SDL_SPACE                  = 0x00000020u,/**< ' ' */
		SDL_EXCLAIM                = 0x00000021u,/**< '!' */
		SDL_DBLAPOSTROPHE          = 0x00000022u,/**< '"' */
		SDL_HASH                   = 0x00000023u,/**< '#' */
		SDL_DOLLAR                 = 0x00000024u,/**< '$' */
		SDL_PERCENT                = 0x00000025u,/**< '%' */
		SDL_AMPERSAND              = 0x00000026u,/**< '&' */
		SDL_APOSTROPHE             = 0x00000027u,/**< '\'' */
		SDL_LEFTPAREN              = 0x00000028u,/**< '(' */
		SDL_RIGHTPAREN             = 0x00000029u,/**< ')' */
		SDL_ASTERISK               = 0x0000002au,/**< '*' */
		SDL_PLUS                   = 0x0000002bu,/**< '+' */
		SDL_COMMA                  = 0x0000002cu,/**< ',' */
		SDL_MINUS                  = 0x0000002du,/**< '-' */
		SDL_PERIOD                 = 0x0000002eu,/**< '.' */
		SDL_SLASH                  = 0x0000002fu,/**< '/' */
		SDL_NUM_0                  = 0x00000030u,/**< '0' */
		SDL_NUM_1                  = 0x00000031u,/**< '1' */
		SDL_NUM_2                  = 0x00000032u,/**< '2' */
		SDL_NUM_3                  = 0x00000033u,/**< '3' */
		SDL_NUM_4                  = 0x00000034u,/**< '4' */
		SDL_NUM_5                  = 0x00000035u,/**< '5' */
		SDL_NUM_6                  = 0x00000036u,/**< '6' */
		SDL_NUM_7                  = 0x00000037u,/**< '7' */
		SDL_NUM_8                  = 0x00000038u,/**< '8' */
		SDL_NUM_9                  = 0x00000039u,/**< '9' */
		SDL_COLON                  = 0x0000003au,/**< ':' */
		SDL_SEMICOLON              = 0x0000003bu,/**< ';' */
		SDL_LESS                   = 0x0000003cu,/**< '<' */
		SDL_EQUALS                 = 0x0000003du,/**< '=' */
		SDL_GREATER                = 0x0000003eu,/**< '>' */
		SDL_QUESTION               = 0x0000003fu,/**< '?' */
		SDL_AT                     = 0x00000040u,/**< '@' */
		SDL_LEFTBRACKET            = 0x0000005bu,/**< '[' */
		SDL_BACKSLASH              = 0x0000005cu,/**< '\\' */
		SDL_RIGHTBRACKET           = 0x0000005du,/**< ']' */
		SDL_CARET                  = 0x0000005eu,/**< '^' */
		SDL_UNDERSCORE             = 0x0000005fu,/**< '_' */
		SDL_GRAVE                  = 0x00000060u,/**< '`' */
		SDL_A                      = 0x00000061u,/**< 'a' */
		SDL_B                      = 0x00000062u,/**< 'b' */
		SDL_C                      = 0x00000063u,/**< 'c' */
		SDL_D                      = 0x00000064u,/**< 'd' */
		SDL_E                      = 0x00000065u,/**< 'e' */
		SDL_F                      = 0x00000066u,/**< 'f' */
		SDL_G                      = 0x00000067u,/**< 'g' */
		SDL_H                      = 0x00000068u,/**< 'h' */
		SDL_I                      = 0x00000069u,/**< 'i' */
		SDL_J                      = 0x0000006au,/**< 'j' */
		SDL_K                      = 0x0000006bu,/**< 'k' */
		SDL_L                      = 0x0000006cu,/**< 'l' */
		SDL_M                      = 0x0000006du,/**< 'm' */
		SDL_N                      = 0x0000006eu,/**< 'n' */
		SDL_O                      = 0x0000006fu,/**< 'o' */
		SDL_P                      = 0x00000070u,/**< 'p' */
		SDL_Q                      = 0x00000071u,/**< 'q' */
		SDL_R                      = 0x00000072u,/**< 'r' */
		SDL_S                      = 0x00000073u,/**< 's' */
		SDL_T                      = 0x00000074u,/**< 't' */
		SDL_U                      = 0x00000075u,/**< 'u' */
		SDL_V                      = 0x00000076u,/**< 'v' */
		SDL_W                      = 0x00000077u,/**< 'w' */
		SDL_X                      = 0x00000078u,/**< 'x' */
		SDL_Y                      = 0x00000079u,/**< 'y' */
		SDL_Z                      = 0x0000007au,/**< 'z' */
		SDL_LEFTBRACE              = 0x0000007bu,/**< '{' */
		SDL_PIPE                   = 0x0000007cu,/**< '|' */
		SDL_RIGHTBRACE             = 0x0000007du,/**< '}' */
		SDL_TILDE                  = 0x0000007eu,/**< '~' */
		SDL_DELETE_KEY             = 0x0000007fu, /**< '\x7F' */
		SDL_PLUSMINUS              = 0x000000b1u, /**< '\xB1' */
		SDL_CAPSLOCK               = 0x40000039u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CAPSLOCK) */
		SDL_F1                     = 0x4000003au, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F1) */
		SDL_F2                     = 0x4000003bu, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F2) */
		SDL_F3                     = 0x4000003cu, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F3) */
		SDL_F4                     = 0x4000003du, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F4) */
		SDL_F5                     = 0x4000003eu, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F5) */
		SDL_F6                     = 0x4000003fu, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F6) */
		SDL_F7                     = 0x40000040u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F7) */
		SDL_F8                     = 0x40000041u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F8) */
		SDL_F9                     = 0x40000042u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F9) */
		SDL_F10                    = 0x40000043u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F10) */
		SDL_F11                    = 0x40000044u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F11) */
		SDL_F12                    = 0x40000045u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F12) */
		SDL_PRINTSCREEN            = 0x40000046u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_PRINTSCREEN) */
		SDL_SCROLLLOCK             = 0x40000047u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_SCROLLLOCK) */
		SDL_PAUSE                  = 0x40000048u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_PAUSE) */
		SDL_INSERT                 = 0x40000049u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_INSERT) */
		SDL_HOME                   = 0x4000004au, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_HOME) */
		SDL_PAGEUP                 = 0x4000004bu, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_PAGEUP) */
		SDL_END                    = 0x4000004du, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_END) */
		SDL_PAGEDOWN               = 0x4000004eu, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_PAGEDOWN) */
		SDL_RIGHT                  = 0x4000004fu, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_RIGHT) */
		SDL_LEFT                   = 0x40000050u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_LEFT) */
		SDL_DOWN                   = 0x40000051u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_DOWN) */
		SDL_UP                     = 0x40000052u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_UP) */
		SDL_NUMLOCKCLEAR           = 0x40000053u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_NUMLOCKCLEAR) */
		SDL_KP_DIVIDE              = 0x40000054u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_DIVIDE) */
		SDL_KP_MULTIPLY            = 0x40000055u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MULTIPLY) */
		SDL_KP_MINUS               = 0x40000056u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MINUS) */
		SDL_KP_PLUS                = 0x40000057u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_PLUS) */
		SDL_KP_ENTER               = 0x40000058u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_ENTER) */
		SDL_KP_1                   = 0x40000059u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_1) */
		SDL_KP_2                   = 0x4000005au, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_2) */
		SDL_KP_3                   = 0x4000005bu, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_3) */
		SDL_KP_4                   = 0x4000005cu, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_4) */
		SDL_KP_5                   = 0x4000005du, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_5) */
		SDL_KP_6                   = 0x4000005eu, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_6) */
		SDL_KP_7                   = 0x4000005fu, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_7) */
		SDL_KP_8                   = 0x40000060u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_8) */
		SDL_KP_9                   = 0x40000061u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_9) */
		SDL_KP_0                   = 0x40000062u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_0) */
		SDL_KP_PERIOD              = 0x40000063u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_PERIOD) */
		SDL_APPLICATION            = 0x40000065u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_APPLICATION) */
		SDL_POWER                  = 0x40000066u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_POWER) */
		SDL_KP_EQUALS              = 0x40000067u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_EQUALS) */
		SDL_F13                    = 0x40000068u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F13) */
		SDL_F14                    = 0x40000069u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F14) */
		SDL_F15                    = 0x4000006au, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F15) */
		SDL_F16                    = 0x4000006bu, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F16) */
		SDL_F17                    = 0x4000006cu, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F17) */
		SDL_F18                    = 0x4000006du, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F18) */
		SDL_F19                    = 0x4000006eu, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F19) */
		SDL_F20                    = 0x4000006fu, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F20) */
		SDL_F21                    = 0x40000070u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F21) */
		SDL_F22                    = 0x40000071u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F22) */
		SDL_F23                    = 0x40000072u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F23) */
		SDL_F24                    = 0x40000073u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F24) */
		SDL_EXECUTE                = 0x40000074u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_EXECUTE) */
		SDL_HELP                   = 0x40000075u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_HELP) */
		SDL_MENU                   = 0x40000076u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_MENU) */
		SDL_SELECT                 = 0x40000077u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_SELECT) */
		SDL_STOP                   = 0x40000078u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_STOP) */
		SDL_AGAIN                  = 0x40000079u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AGAIN) */
		SDL_UNDO                   = 0x4000007au, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_UNDO) */
		SDL_CUT                    = 0x4000007bu, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CUT) */
		SDL_COPY                   = 0x4000007cu, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_COPY) */
		SDL_PASTE                  = 0x4000007du, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_PASTE) */
		SDL_FIND                   = 0x4000007eu, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_FIND) */
		SDL_MUTE                   = 0x4000007fu, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_MUTE) */
		SDL_VOLUMEUP               = 0x40000080u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_VOLUMEUP) */
		SDL_VOLUMEDOWN             = 0x40000081u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_VOLUMEDOWN) */
		SDL_KP_COMMA               = 0x40000085u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_COMMA) */
		SDL_KP_EQUALSAS400         = 0x40000086u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_EQUALSAS400) */
		SDL_ALTERASE               = 0x40000099u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_ALTERASE) */
		SDL_SYSREQ                 = 0x4000009au, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_SYSREQ) */
		SDL_CANCEL                 = 0x4000009bu, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CANCEL) */
		SDL_CLEAR                  = 0x4000009cu, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CLEAR) */
		SDL_PRIOR                  = 0x4000009du, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_PRIOR) */
		SDL_RETURN2                = 0x4000009eu, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_RETURN2) */
		SDL_SEPARATOR              = 0x4000009fu, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_SEPARATOR) */
		SDL_OUT_KEY                = 0x400000a0u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_OUT) */
		SDL_OPER                   = 0x400000a1u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_OPER) */
		SDL_CLEARAGAIN             = 0x400000a2u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CLEARAGAIN) */
		SDL_CRSEL                  = 0x400000a3u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CRSEL) */
		SDL_EXSEL                  = 0x400000a4u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_EXSEL) */
		SDL_KP_00                  = 0x400000b0u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_00) */
		SDL_KP_000                 = 0x400000b1u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_000) */
		SDL_THOUSANDSSEPARATOR     = 0x400000b2u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_THOUSANDSSEPARATOR) */
		SDL_DECIMALSEPARATOR       = 0x400000b3u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_DECIMALSEPARATOR) */
		SDL_CURRENCYUNIT           = 0x400000b4u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CURRENCYUNIT) */
		SDL_CURRENCYSUBUNIT        = 0x400000b5u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CURRENCYSUBUNIT) */
		SDL_KP_LEFTPAREN           = 0x400000b6u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_LEFTPAREN) */
		SDL_KP_RIGHTPAREN          = 0x400000b7u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_RIGHTPAREN) */
		SDL_KP_LEFTBRACE           = 0x400000b8u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_LEFTBRACE) */
		SDL_KP_RIGHTBRACE          = 0x400000b9u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_RIGHTBRACE) */
		SDL_KP_TAB                 = 0x400000bau, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_TAB) */
		SDL_KP_BACKSPACE           = 0x400000bbu, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_BACKSPACE) */
		SDL_KP_A                   = 0x400000bcu, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_A) */
		SDL_KP_B                   = 0x400000bdu, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_B) */
		SDL_KP_C                   = 0x400000beu, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_C) */
		SDL_KP_D                   = 0x400000bfu, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_D) */
		SDL_KP_E                   = 0x400000c0u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_E) */
		SDL_KP_F                   = 0x400000c1u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_F) */
		SDL_KP_XOR                 = 0x400000c2u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_XOR) */
		SDL_KP_POWER               = 0x400000c3u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_POWER) */
		SDL_KP_PERCENT             = 0x400000c4u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_PERCENT) */
		SDL_KP_LESS                = 0x400000c5u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_LESS) */
		SDL_KP_GREATER             = 0x400000c6u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_GREATER) */
		SDL_KP_AMPERSAND           = 0x400000c7u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_AMPERSAND) */
		SDL_KP_DBLAMPERSAND        = 0x400000c8u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_DBLAMPERSAND) */
		SDL_KP_VERTICALBAR         = 0x400000c9u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_VERTICALBAR) */
		SDL_KP_DBLVERTICALBAR      = 0x400000cau, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_DBLVERTICALBAR) */
		SDL_KP_COLON               = 0x400000cbu, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_COLON) */
		SDL_KP_HASH                = 0x400000ccu, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_HASH) */
		SDL_KP_SPACE               = 0x400000cdu, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_SPACE) */
		SDL_KP_AT                  = 0x400000ceu, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_AT) */
		SDL_KP_EXCLAM              = 0x400000cfu, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_EXCLAM) */
		SDL_KP_MEMSTORE            = 0x400000d0u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MEMSTORE) */
		SDL_KP_MEMRECALL           = 0x400000d1u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MEMRECALL) */
		SDL_KP_MEMCLEAR            = 0x400000d2u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MEMCLEAR) */
		SDL_KP_MEMADD              = 0x400000d3u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MEMADD) */
		SDL_KP_MEMSUBTRACT         = 0x400000d4u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MEMSUBTRACT) */
		SDL_KP_MEMMULTIPLY         = 0x400000d5u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MEMMULTIPLY) */
		SDL_KP_MEMDIVIDE           = 0x400000d6u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MEMDIVIDE) */
		SDL_KP_PLUSMINUS           = 0x400000d7u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_PLUSMINUS) */
		SDL_KP_CLEAR               = 0x400000d8u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_CLEAR) */
		SDL_KP_CLEARENTRY          = 0x400000d9u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_CLEARENTRY) */
		SDL_KP_BINARY              = 0x400000dau, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_BINARY) */
		SDL_KP_OCTAL               = 0x400000dbu, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_OCTAL) */
		SDL_KP_DECIMAL             = 0x400000dcu, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_DECIMAL) */
		SDL_KP_HEXADECIMAL         = 0x400000ddu, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_HEXADECIMAL) */
		SDL_LCTRL                  = 0x400000e0u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_LCTRL) */
		SDL_LSHIFT                 = 0x400000e1u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_LSHIFT) */
		SDL_LALT                   = 0x400000e2u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_LALT) */
		SDL_LGUI                   = 0x400000e3u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_LGUI) */
		SDL_RCTRL                  = 0x400000e4u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_RCTRL) */
		SDL_RSHIFT                 = 0x400000e5u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_RSHIFT) */
		SDL_RALT                   = 0x400000e6u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_RALT) */
		SDL_RGUI                   = 0x400000e7u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_RGUI) */
		SDL_MODE                   = 0x40000101u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_MODE) */
		SDL_SLEEP                  = 0x40000102u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_SLEEP) */
		SDL_WAKE                   = 0x40000103u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_WAKE) */
		SDL_CHANNEL_INCREMENT      = 0x40000104u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CHANNEL_INCREMENT) */
		SDL_CHANNEL_DECREMENT      = 0x40000105u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CHANNEL_DECREMENT) */
		SDL_MEDIA_PLAY             = 0x40000106u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_MEDIA_PLAY) */
		SDL_MEDIA_PAUSE            = 0x40000107u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_MEDIA_PAUSE) */
		SDL_MEDIA_RECORD           = 0x40000108u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_MEDIA_RECORD) */
		SDL_MEDIA_FAST_FORWARD     = 0x40000109u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_MEDIA_FAST_FORWARD) */
		SDL_MEDIA_REWIND           = 0x4000010au, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_MEDIA_REWIND) */
		SDL_MEDIA_NEXT_TRACK       = 0x4000010bu, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_MEDIA_NEXT_TRACK) */
		SDL_MEDIA_PREVIOUS_TRACK   = 0x4000010cu, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_MEDIA_PREVIOUS_TRACK) */
		SDL_MEDIA_STOP             = 0x4000010du, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_MEDIA_STOP) */
		SDL_MEDIA_EJECT            = 0x4000010eu, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_MEDIA_EJECT) */
		SDL_MEDIA_PLAY_PAUSE       = 0x4000010fu, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_MEDIA_PLAY_PAUSE) */
		SDL_MEDIA_SELECT           = 0x40000110u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_MEDIA_SELECT) */
		SDL_AC_NEW                 = 0x40000111u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_NEW) */
		SDL_AC_OPEN                = 0x40000112u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_OPEN) */
		SDL_AC_CLOSE               = 0x40000113u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_CLOSE) */
		SDL_AC_EXIT                = 0x40000114u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_EXIT) */
		SDL_AC_SAVE                = 0x40000115u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_SAVE) */
		SDL_AC_PRINT               = 0x40000116u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_PRINT) */
		SDL_AC_PROPERTIES          = 0x40000117u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_PROPERTIES) */
		SDL_AC_SEARCH              = 0x40000118u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_SEARCH) */
		SDL_AC_HOME                = 0x40000119u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_HOME) */
		SDL_AC_BACK                = 0x4000011au, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_BACK) */
		SDL_AC_FORWARD             = 0x4000011bu, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_FORWARD) */
		SDL_AC_STOP                = 0x4000011cu, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_STOP) */
		SDL_AC_REFRESH             = 0x4000011du, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_REFRESH) */
		SDL_AC_BOOKMARKS           = 0x4000011eu, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_BOOKMARKS) */
		SDL_SOFTLEFT               = 0x4000011fu, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_SOFTLEFT) */
		SDL_SOFTRIGHT              = 0x40000120u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_SOFTRIGHT) */
		SDL_CALL                   = 0x40000121u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CALL) */
		SDL_ENDCALL                = 0x40000122u, /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_ENDCALL) */
		SDL_LEFT_TAB               = 0x20000001u, /**< Extended key Left Tab */
		SDL_LEVEL5_SHIFT           = 0x20000002u, /**< Extended key Level 5 Shift */
		SDL_MULTI_KEY_COMPOSE      = 0x20000003u, /**< Extended key Multi-key Compose */
		SDL_LMETA                  = 0x20000004u, /**< Extended key Left Meta */
		SDL_RMETA                  = 0x20000005u, /**< Extended key Right Meta */
		SDL_LHYPER                 = 0x20000006u, /**< Extended key Left Hyper */
		SDL_RHYPER                 = 0x20000007u, /**< Extended key Right Hyper */
	};

	static KOPY_KEY GetIndex(SDLK sdlKey)
	{
		switch (sdlKey) 
		{
		case SDLK::SDL_UNKNOWN				   : return KOPY_KEY::UNKNOWN		   ;
		case SDLK::SDL_RETURN                  : return KOPY_KEY::RETURN         ;
		case SDLK::SDL_ESCAPE                  : return KOPY_KEY::ESCAPE         ;
		case SDLK::SDL_BACKSPACE               : return KOPY_KEY::BACKSPACE      ;
		case SDLK::SDL_TAB                     : return KOPY_KEY::TAB            ;
		case SDLK::SDL_SPACE                   : return KOPY_KEY::SPACE          ;
		case SDLK::SDL_EXCLAIM                 : return KOPY_KEY::EXCLAIM        ;
		case SDLK::SDL_DBLAPOSTROPHE           : return KOPY_KEY::DBLAPOSTROPHE  ;
		case SDLK::SDL_HASH                    : return KOPY_KEY::HASH           ;
		case SDLK::SDL_DOLLAR                  : return KOPY_KEY::DOLLAR         ;
		case SDLK::SDL_PERCENT                 : return KOPY_KEY::PERCENT        ;
		case SDLK::SDL_AMPERSAND               : return KOPY_KEY::AMPERSAND      ;
		case SDLK::SDL_APOSTROPHE              : return KOPY_KEY::APOSTROPHE     ;
		case SDLK::SDL_LEFTPAREN               : return KOPY_KEY::LEFTPAREN      ;
		case SDLK::SDL_RIGHTPAREN              : return KOPY_KEY::RIGHTPAREN     ;
		case SDLK::SDL_ASTERISK                : return KOPY_KEY::ASTERISK       ;
		case SDLK::SDL_PLUS                    : return KOPY_KEY::PLUS           ;
		case SDLK::SDL_COMMA                   : return KOPY_KEY::COMMA          ;
		case SDLK::SDL_MINUS                   : return KOPY_KEY::MINUS          ;
		case SDLK::SDL_PERIOD                  : return KOPY_KEY::PERIOD         ;
		case SDLK::SDL_SLASH                   : return KOPY_KEY::SLASH          ;
		case SDLK::SDL_NUM_0                   : return KOPY_KEY::NUM_0          ;
		case SDLK::SDL_NUM_1                   : return KOPY_KEY::NUM_1          ;
		case SDLK::SDL_NUM_2                   : return KOPY_KEY::NUM_2          ;
		case SDLK::SDL_NUM_3                   : return KOPY_KEY::NUM_3          ;
		case SDLK::SDL_NUM_4                   : return KOPY_KEY::NUM_4          ;
		case SDLK::SDL_NUM_5                   : return KOPY_KEY::NUM_5          ;
		case SDLK::SDL_NUM_6                   : return KOPY_KEY::NUM_6          ;
		case SDLK::SDL_NUM_7                   : return KOPY_KEY::NUM_7          ;
		case SDLK::SDL_NUM_8                   : return KOPY_KEY::NUM_8          ;
		case SDLK::SDL_NUM_9				   : return KOPY_KEY::NUM_9          ;
		case SDLK::SDL_COLON				   : return KOPY_KEY::COLON          ;
		case SDLK::SDL_SEMICOLON			   : return KOPY_KEY::SEMICOLON      ;
		case SDLK::SDL_LESS                    : return KOPY_KEY::LESS           ;
		case SDLK::SDL_EQUALS                  : return KOPY_KEY::EQUALS         ;
		case SDLK::SDL_GREATER                 : return KOPY_KEY::GREATER        ;
		case SDLK::SDL_QUESTION                : return KOPY_KEY::QUESTION       ;
		case SDLK::SDL_AT                      : return KOPY_KEY::AT             ;
		case SDLK::SDL_LEFTBRACKET             : return KOPY_KEY::LEFTBRACKET    ;
		case SDLK::SDL_BACKSLASH               : return KOPY_KEY::BACKSLASH      ;
		case SDLK::SDL_RIGHTBRACKET            : return KOPY_KEY::RIGHTBRACKET   ;
		case SDLK::SDL_CARET                   : return KOPY_KEY::CARET          ;
		case SDLK::SDL_UNDERSCORE              : return KOPY_KEY::UNDERSCORE     ;
		case SDLK::SDL_GRAVE                   : return KOPY_KEY::GRAVE          ;
		case SDLK::SDL_A                       : return KOPY_KEY::A              ;
		case SDLK::SDL_B                       : return KOPY_KEY::B              ;
		case SDLK::SDL_C                       : return KOPY_KEY::C              ;
		case SDLK::SDL_D                       : return KOPY_KEY::D              ;
		case SDLK::SDL_E                       : return KOPY_KEY::E              ;
		case SDLK::SDL_F                       : return KOPY_KEY::F              ;
		case SDLK::SDL_G                       : return KOPY_KEY::G              ;
		case SDLK::SDL_H                       : return KOPY_KEY::H              ;
		case SDLK::SDL_I                       : return KOPY_KEY::I              ;
		case SDLK::SDL_J                       : return KOPY_KEY::J              ;
		case SDLK::SDL_K                       : return KOPY_KEY::K              ;
		case SDLK::SDL_L                       : return KOPY_KEY::L              ;
		case SDLK::SDL_M                       : return KOPY_KEY::M              ;
		case SDLK::SDL_N                       : return KOPY_KEY::N              ;
		case SDLK::SDL_O                       : return KOPY_KEY::O              ;
		case SDLK::SDL_P                       : return KOPY_KEY::P              ;
		case SDLK::SDL_Q                       : return KOPY_KEY::Q              ;
		case SDLK::SDL_R                       : return KOPY_KEY::R              ;
		case SDLK::SDL_S                       : return KOPY_KEY::S              ;
		case SDLK::SDL_T                       : return KOPY_KEY::T              ;
		case SDLK::SDL_U                       : return KOPY_KEY::U              ;
		case SDLK::SDL_V                       : return KOPY_KEY::V              ;
		case SDLK::SDL_W                       : return KOPY_KEY::W              ;
		case SDLK::SDL_X                       : return KOPY_KEY::X              ;
		case SDLK::SDL_Y                       : return KOPY_KEY::Y              ;
		case SDLK::SDL_Z                       : return KOPY_KEY::Z              ;
		case SDLK::SDL_LEFTBRACE               : return KOPY_KEY::LEFTBRACE      ;
		case SDLK::SDL_PIPE                    : return KOPY_KEY::PIPE           ;
		case SDLK::SDL_RIGHTBRACE              : return KOPY_KEY::RIGHTBRACE     ;
		case SDLK::SDL_TILDE                   : return KOPY_KEY::TILDE          ;
		case SDLK::SDL_DELETE_KEY              : return KOPY_KEY::DELETE_KEY     ;
		case SDLK::SDL_PLUSMINUS               : return KOPY_KEY::PLUSMINUS      ;
		case SDLK::SDL_CAPSLOCK                : return KOPY_KEY::CAPSLOCK;
		case SDLK::SDL_F1                      : return KOPY_KEY::F1;
		case SDLK::SDL_F2                      : return KOPY_KEY::F2;
		case SDLK::SDL_F3                      : return KOPY_KEY::F3;
		case SDLK::SDL_F4                      : return KOPY_KEY::F4;
		case SDLK::SDL_F5                      : return KOPY_KEY::F5;
		case SDLK::SDL_F6                      : return KOPY_KEY::F6;
		case SDLK::SDL_F7                      : return KOPY_KEY::F7;
		case SDLK::SDL_F8                      : return KOPY_KEY::F8;
		case SDLK::SDL_F9                      : return KOPY_KEY::F9;
		case SDLK::SDL_F10                     : return KOPY_KEY::F10;
		case SDLK::SDL_F11                     : return KOPY_KEY::F11;
		case SDLK::SDL_F12                     : return KOPY_KEY::F12;
		case SDLK::SDL_PRINTSCREEN             : return KOPY_KEY::PRINTSCREEN;
		case SDLK::SDL_SCROLLLOCK              : return KOPY_KEY::SCROLLLOCK;
		case SDLK::SDL_PAUSE                   : return KOPY_KEY::PAUSE;
		case SDLK::SDL_INSERT                  : return KOPY_KEY::INSERT;
		case SDLK::SDL_HOME                    : return KOPY_KEY::HOME;
		case SDLK::SDL_PAGEUP                  : return KOPY_KEY::PAGEUP;
		case SDLK::SDL_END                     : return KOPY_KEY::END;
		case SDLK::SDL_PAGEDOWN                : return KOPY_KEY::PAGEDOWN;
		case SDLK::SDL_RIGHT                   : return KOPY_KEY::RIGHT;
		case SDLK::SDL_LEFT                    : return KOPY_KEY::LEFT;
		case SDLK::SDL_DOWN                    : return KOPY_KEY::DOWN;
		case SDLK::SDL_UP                      : return KOPY_KEY::UP;
		case SDLK::SDL_NUMLOCKCLEAR            : return KOPY_KEY::NUMLOCKCLEAR;
		case SDLK::SDL_KP_DIVIDE               : return KOPY_KEY::KP_DIVIDE;
		case SDLK::SDL_KP_MULTIPLY             : return KOPY_KEY::KP_MULTIPLY;
		case SDLK::SDL_KP_MINUS                : return KOPY_KEY::KP_MINUS;
		case SDLK::SDL_KP_PLUS                 : return KOPY_KEY::KP_PLUS;
		case SDLK::SDL_KP_ENTER                : return KOPY_KEY::KP_ENTER;
		case SDLK::SDL_KP_1                    : return KOPY_KEY::KP_1;
		case SDLK::SDL_KP_2                    : return KOPY_KEY::KP_2;
		case SDLK::SDL_KP_3                    : return KOPY_KEY::KP_3;
		case SDLK::SDL_KP_4                    : return KOPY_KEY::KP_4;
		case SDLK::SDL_KP_5                    : return KOPY_KEY::KP_5;
		case SDLK::SDL_KP_6                    : return KOPY_KEY::KP_6;
		case SDLK::SDL_KP_7                    : return KOPY_KEY::KP_7;
		case SDLK::SDL_KP_8                    : return KOPY_KEY::KP_8;
		case SDLK::SDL_KP_9                    : return KOPY_KEY::KP_9;
		case SDLK::SDL_KP_0                    : return KOPY_KEY::KP_0;
		case SDLK::SDL_KP_PERIOD               : return KOPY_KEY::KP_PERIOD;
		case SDLK::SDL_APPLICATION             : return KOPY_KEY::APPLICATION;
		case SDLK::SDL_POWER                   : return KOPY_KEY::POWER;
		case SDLK::SDL_KP_EQUALS               : return KOPY_KEY::KP_EQUALS;
		case SDLK::SDL_F13                     : return KOPY_KEY::F13;
		case SDLK::SDL_F14                     : return KOPY_KEY::F14;
		case SDLK::SDL_F15                     : return KOPY_KEY::F15;
		case SDLK::SDL_F16                     : return KOPY_KEY::F16;
		case SDLK::SDL_F17                     : return KOPY_KEY::F17;
		case SDLK::SDL_F18                     : return KOPY_KEY::F18;
		case SDLK::SDL_F19                     : return KOPY_KEY::F19;
		case SDLK::SDL_F20                     : return KOPY_KEY::F20;
		case SDLK::SDL_F21                     : return KOPY_KEY::F21;
		case SDLK::SDL_F22                     : return KOPY_KEY::F22;
		case SDLK::SDL_F23                     : return KOPY_KEY::F23;
		case SDLK::SDL_F24                     : return KOPY_KEY::F24;
		case SDLK::SDL_EXECUTE                 : return KOPY_KEY::EXECUTE;
		case SDLK::SDL_HELP                    : return KOPY_KEY::HELP;
		case SDLK::SDL_MENU                    : return KOPY_KEY::MENU;
		case SDLK::SDL_SELECT                  : return KOPY_KEY::SELECT;
		case SDLK::SDL_STOP                    : return KOPY_KEY::STOP;
		case SDLK::SDL_AGAIN                   : return KOPY_KEY::AGAIN;
		case SDLK::SDL_UNDO                    : return KOPY_KEY::UNDO;
		case SDLK::SDL_CUT                     : return KOPY_KEY::CUT;
		case SDLK::SDL_COPY                    : return KOPY_KEY::COPY;
		case SDLK::SDL_PASTE                   : return KOPY_KEY::PASTE;
		case SDLK::SDL_FIND                    : return KOPY_KEY::FIND;
		case SDLK::SDL_MUTE                    : return KOPY_KEY::MUTE;
		case SDLK::SDL_VOLUMEUP                : return KOPY_KEY::VOLUMEUP;
		case SDLK::SDL_VOLUMEDOWN              : return KOPY_KEY::VOLUMEDOWN;
		case SDLK::SDL_KP_COMMA                : return KOPY_KEY::KP_COMMA;
		case SDLK::SDL_KP_EQUALSAS400          : return KOPY_KEY::KP_EQUALSAS400;
		case SDLK::SDL_ALTERASE                : return KOPY_KEY::ALTERASE;
		case SDLK::SDL_SYSREQ                  : return KOPY_KEY::SYSREQ;
		case SDLK::SDL_CANCEL                  : return KOPY_KEY::CANCEL;
		case SDLK::SDL_CLEAR                   : return KOPY_KEY::CLEAR;
		case SDLK::SDL_PRIOR                   : return KOPY_KEY::PRIOR;
		case SDLK::SDL_RETURN2                 : return KOPY_KEY::RETURN2;
		case SDLK::SDL_SEPARATOR               : return KOPY_KEY::SEPARATOR;
		case SDLK::SDL_OUT_KEY                 : return KOPY_KEY::OUT_KEY;
		case SDLK::SDL_OPER                    : return KOPY_KEY::OPER;
		case SDLK::SDL_CLEARAGAIN              : return KOPY_KEY::CLEARAGAIN;
		case SDLK::SDL_CRSEL                   : return KOPY_KEY::CRSEL;
		case SDLK::SDL_EXSEL                   : return KOPY_KEY::EXSEL;
		case SDLK::SDL_KP_00                   : return KOPY_KEY::KP_00;
		case SDLK::SDL_KP_000                  : return KOPY_KEY::KP_000;
		case SDLK::SDL_THOUSANDSSEPARATOR      : return KOPY_KEY::THOUSANDSSEPARATOR;
		case SDLK::SDL_DECIMALSEPARATOR        : return KOPY_KEY::DECIMALSEPARATOR;
		case SDLK::SDL_CURRENCYUNIT            : return KOPY_KEY::CURRENCYUNIT;
		case SDLK::SDL_CURRENCYSUBUNIT         : return KOPY_KEY::CURRENCYSUBUNIT;
		case SDLK::SDL_KP_LEFTPAREN            : return KOPY_KEY::KP_LEFTPAREN;
		case SDLK::SDL_KP_RIGHTPAREN           : return KOPY_KEY::KP_RIGHTPAREN;
		case SDLK::SDL_KP_LEFTBRACE            : return KOPY_KEY::KP_LEFTBRACE;
		case SDLK::SDL_KP_RIGHTBRACE           : return KOPY_KEY::KP_RIGHTBRACE;
		case SDLK::SDL_KP_TAB                  : return KOPY_KEY::KP_TAB;
		case SDLK::SDL_KP_BACKSPACE            : return KOPY_KEY::KP_BACKSPACE;
		case SDLK::SDL_KP_A                    : return KOPY_KEY::KP_A;
		case SDLK::SDL_KP_B                    : return KOPY_KEY::KP_B;
		case SDLK::SDL_KP_C                    : return KOPY_KEY::KP_C;
		case SDLK::SDL_KP_D                    : return KOPY_KEY::KP_D;
		case SDLK::SDL_KP_E                    : return KOPY_KEY::KP_E;
		case SDLK::SDL_KP_F                    : return KOPY_KEY::KP_F;
		case SDLK::SDL_KP_XOR                  : return KOPY_KEY::KP_XOR;
		case SDLK::SDL_KP_POWER                : return KOPY_KEY::KP_POWER;
		case SDLK::SDL_KP_PERCENT              : return KOPY_KEY::KP_PERCENT;
		case SDLK::SDL_KP_LESS                 : return KOPY_KEY::KP_LESS;
		case SDLK::SDL_KP_GREATER              : return KOPY_KEY::KP_GREATER;
		case SDLK::SDL_KP_AMPERSAND            : return KOPY_KEY::KP_AMPERSAND;
		case SDLK::SDL_KP_DBLAMPERSAND         : return KOPY_KEY::KP_DBLAMPERSAND;
		case SDLK::SDL_KP_VERTICALBAR          : return KOPY_KEY::KP_VERTICALBAR;
		case SDLK::SDL_KP_DBLVERTICALBAR       : return KOPY_KEY::KP_DBLVERTICALBAR;
		case SDLK::SDL_KP_COLON                : return KOPY_KEY::KP_COLON;
		case SDLK::SDL_KP_HASH                 : return KOPY_KEY::KP_HASH;
		case SDLK::SDL_KP_SPACE                : return KOPY_KEY::KP_SPACE;
		case SDLK::SDL_KP_AT                   : return KOPY_KEY::KP_AT;
		case SDLK::SDL_KP_EXCLAM               : return KOPY_KEY::KP_EXCLAM;
		case SDLK::SDL_KP_MEMSTORE             : return KOPY_KEY::KP_MEMSTORE;
		case SDLK::SDL_KP_MEMRECALL            : return KOPY_KEY::KP_MEMRECALL;
		case SDLK::SDL_KP_MEMCLEAR             : return KOPY_KEY::KP_MEMCLEAR;
		case SDLK::SDL_KP_MEMADD               : return KOPY_KEY::KP_MEMADD;
		case SDLK::SDL_KP_MEMSUBTRACT          : return KOPY_KEY::KP_MEMSUBTRACT;
		case SDLK::SDL_KP_MEMMULTIPLY          : return KOPY_KEY::KP_MEMMULTIPLY;
		case SDLK::SDL_KP_MEMDIVIDE            : return KOPY_KEY::KP_MEMDIVIDE;
		case SDLK::SDL_KP_PLUSMINUS            : return KOPY_KEY::KP_PLUSMINUS;
		case SDLK::SDL_KP_CLEAR                : return KOPY_KEY::KP_CLEAR;
		case SDLK::SDL_KP_CLEARENTRY           : return KOPY_KEY::KP_CLEARENTRY;
		case SDLK::SDL_KP_BINARY               : return KOPY_KEY::KP_BINARY;
		case SDLK::SDL_KP_OCTAL                : return KOPY_KEY::KP_OCTAL;
		case SDLK::SDL_KP_DECIMAL              : return KOPY_KEY::KP_DECIMAL;
		case SDLK::SDL_KP_HEXADECIMAL          : return KOPY_KEY::KP_HEXADECIMAL;
		case SDLK::SDL_LCTRL                   : return KOPY_KEY::LCTRL;
		case SDLK::SDL_LSHIFT                  : return KOPY_KEY::LSHIFT;
		case SDLK::SDL_LALT                    : return KOPY_KEY::LALT;
		case SDLK::SDL_LGUI                    : return KOPY_KEY::LGUI;
		case SDLK::SDL_RCTRL                   : return KOPY_KEY::RCTRL;
		case SDLK::SDL_RSHIFT                  : return KOPY_KEY::RSHIFT;
		case SDLK::SDL_RALT                    : return KOPY_KEY::RALT;
		case SDLK::SDL_RGUI                    : return KOPY_KEY::RGUI;
		case SDLK::SDL_MODE                    : return KOPY_KEY::MODE;
		case SDLK::SDL_SLEEP                   : return KOPY_KEY::SLEEP;
		case SDLK::SDL_WAKE                    : return KOPY_KEY::WAKE;
		case SDLK::SDL_CHANNEL_INCREMENT       : return KOPY_KEY::CHANNEL_INCREMENT;
		case SDLK::SDL_CHANNEL_DECREMENT       : return KOPY_KEY::CHANNEL_DECREMENT;
		case SDLK::SDL_MEDIA_PLAY              : return KOPY_KEY::MEDIA_PLAY;
		case SDLK::SDL_MEDIA_PAUSE             : return KOPY_KEY::MEDIA_PAUSE;
		case SDLK::SDL_MEDIA_RECORD            : return KOPY_KEY::MEDIA_RECORD;
		case SDLK::SDL_MEDIA_FAST_FORWARD      : return KOPY_KEY::MEDIA_FAST_FORWARD;
		case SDLK::SDL_MEDIA_REWIND            : return KOPY_KEY::MEDIA_REWIND;
		case SDLK::SDL_MEDIA_NEXT_TRACK        : return KOPY_KEY::MEDIA_NEXT_TRACK;
		case SDLK::SDL_MEDIA_PREVIOUS_TRACK    : return KOPY_KEY::MEDIA_PREVIOUS_TRACK;
		case SDLK::SDL_MEDIA_STOP              : return KOPY_KEY::MEDIA_STOP;
		case SDLK::SDL_MEDIA_EJECT             : return KOPY_KEY::MEDIA_EJECT;
		case SDLK::SDL_MEDIA_PLAY_PAUSE        : return KOPY_KEY::MEDIA_PLAY_PAUSE;
		case SDLK::SDL_MEDIA_SELECT            : return KOPY_KEY::MEDIA_SELECT;
		case SDLK::SDL_AC_NEW                  : return KOPY_KEY::AC_NEW;
		case SDLK::SDL_AC_OPEN                 : return KOPY_KEY::AC_OPEN;
		case SDLK::SDL_AC_CLOSE                : return KOPY_KEY::AC_CLOSE;
		case SDLK::SDL_AC_EXIT                 : return KOPY_KEY::AC_EXIT;
		case SDLK::SDL_AC_SAVE                 : return KOPY_KEY::AC_SAVE;
		case SDLK::SDL_AC_PRINT                : return KOPY_KEY::AC_PRINT;
		case SDLK::SDL_AC_PROPERTIES           : return KOPY_KEY::AC_PROPERTIES;
		case SDLK::SDL_AC_SEARCH               : return KOPY_KEY::AC_SEARCH;
		case SDLK::SDL_AC_HOME                 : return KOPY_KEY::AC_HOME;
		case SDLK::SDL_AC_BACK                 : return KOPY_KEY::AC_BACK;
		case SDLK::SDL_AC_FORWARD              : return KOPY_KEY::AC_FORWARD;
		case SDLK::SDL_AC_STOP                 : return KOPY_KEY::AC_STOP;
		case SDLK::SDL_AC_REFRESH              : return KOPY_KEY::AC_REFRESH;
		case SDLK::SDL_AC_BOOKMARKS            : return KOPY_KEY::AC_BOOKMARKS;
		case SDLK::SDL_SOFTLEFT                : return KOPY_KEY::SOFTLEFT;
		case SDLK::SDL_SOFTRIGHT               : return KOPY_KEY::SOFTRIGHT;
		case SDLK::SDL_CALL                    : return KOPY_KEY::CALL;
		case SDLK::SDL_ENDCALL                 : return KOPY_KEY::ENDCALL;
		case SDLK::SDL_LEFT_TAB                : return KOPY_KEY::LEFT_TAB;
		case SDLK::SDL_LEVEL5_SHIFT            : return KOPY_KEY::LEVEL5_SHIFT;
		case SDLK::SDL_MULTI_KEY_COMPOSE       : return KOPY_KEY::MULTI_KEY_COMPOSE;
		case SDLK::SDL_LMETA                   : return KOPY_KEY::LMETA;
		case SDLK::SDL_RMETA                   : return KOPY_KEY::RMETA;
		case SDLK::SDL_LHYPER                  : return KOPY_KEY::LHYPER;
		case SDLK::SDL_RHYPER                  : return KOPY_KEY::RHYPER;
		}
	};
	static SDLK GetSDLK(KOPY_KEY koKey)
	{
		switch (koKey) 
		{
		case KOPY_KEY::UNKNOWN					: return SDLK::SDL_UNKNOWN;
		case KOPY_KEY::RETURN						: return SDLK::SDL_RETURN;
		case KOPY_KEY::ESCAPE						: return SDLK::SDL_ESCAPE;
		case KOPY_KEY::BACKSPACE					: return SDLK::SDL_BACKSPACE;
		case KOPY_KEY::TAB						: return SDLK::SDL_TAB;
		case KOPY_KEY::SPACE						: return SDLK::SDL_SPACE;
		case KOPY_KEY::EXCLAIM					: return SDLK::SDL_EXCLAIM;
		case KOPY_KEY::DBLAPOSTROPHE				: return SDLK::SDL_DBLAPOSTROPHE;
		case KOPY_KEY::HASH						: return SDLK::SDL_HASH;
		case KOPY_KEY::DOLLAR						: return SDLK::SDL_DOLLAR;
		case KOPY_KEY::PERCENT					: return SDLK::SDL_PERCENT;
		case KOPY_KEY::AMPERSAND					: return SDLK::SDL_AMPERSAND;
		case KOPY_KEY::APOSTROPHE					: return SDLK::SDL_APOSTROPHE;
		case KOPY_KEY::LEFTPAREN					: return SDLK::SDL_LEFTPAREN;
		case KOPY_KEY::RIGHTPAREN					: return SDLK::SDL_RIGHTPAREN;
		case KOPY_KEY::ASTERISK					: return SDLK::SDL_ASTERISK;
		case KOPY_KEY::PLUS						: return SDLK::SDL_PLUS;
		case KOPY_KEY::COMMA						: return SDLK::SDL_COMMA;
		case KOPY_KEY::MINUS						: return SDLK::SDL_MINUS;
		case KOPY_KEY::PERIOD						: return SDLK::SDL_PERIOD;
		case KOPY_KEY::SLASH						: return SDLK::SDL_SLASH;
		case KOPY_KEY::NUM_0						: return SDLK::SDL_NUM_0;
		case KOPY_KEY::NUM_1						: return SDLK::SDL_NUM_1;
		case KOPY_KEY::NUM_2						: return SDLK::SDL_NUM_2;
		case KOPY_KEY::NUM_3						: return SDLK::SDL_NUM_3;
		case KOPY_KEY::NUM_4						: return SDLK::SDL_NUM_4;
		case KOPY_KEY::NUM_5						: return SDLK::SDL_NUM_5;
		case KOPY_KEY::NUM_6						: return SDLK::SDL_NUM_6;
		case KOPY_KEY::NUM_7						: return SDLK::SDL_NUM_7;
		case KOPY_KEY::NUM_8						: return SDLK::SDL_NUM_8;
		case KOPY_KEY::NUM_9						: return SDLK::SDL_NUM_9;
		case KOPY_KEY::COLON						: return SDLK::SDL_COLON;
		case KOPY_KEY::SEMICOLON					: return SDLK::SDL_SEMICOLON;
		case KOPY_KEY::LESS						: return SDLK::SDL_LESS;
		case KOPY_KEY::EQUALS						: return SDLK::SDL_EQUALS;
		case KOPY_KEY::GREATER					: return SDLK::SDL_GREATER;
		case KOPY_KEY::QUESTION					: return SDLK::SDL_QUESTION;
		case KOPY_KEY::AT							: return SDLK::SDL_AT;
		case KOPY_KEY::LEFTBRACKET				: return SDLK::SDL_LEFTBRACKET;
		case KOPY_KEY::BACKSLASH					: return SDLK::SDL_BACKSLASH;
		case KOPY_KEY::RIGHTBRACKET				: return SDLK::SDL_RIGHTBRACKET;
		case KOPY_KEY::CARET						: return SDLK::SDL_CARET;
		case KOPY_KEY::UNDERSCORE					: return SDLK::SDL_UNDERSCORE;
		case KOPY_KEY::GRAVE						: return SDLK::SDL_GRAVE;
		case KOPY_KEY::A							: return SDLK::SDL_A;
		case KOPY_KEY::B							: return SDLK::SDL_B;
		case KOPY_KEY::C							: return SDLK::SDL_C;
		case KOPY_KEY::D							: return SDLK::SDL_D;
		case KOPY_KEY::E							: return SDLK::SDL_E;
		case KOPY_KEY::F							: return SDLK::SDL_F;
		case KOPY_KEY::G							: return SDLK::SDL_G;
		case KOPY_KEY::H							: return SDLK::SDL_H;
		case KOPY_KEY::I							: return SDLK::SDL_I;
		case KOPY_KEY::J							: return SDLK::SDL_J;
		case KOPY_KEY::K							: return SDLK::SDL_K;
		case KOPY_KEY::L							: return SDLK::SDL_L;
		case KOPY_KEY::M							: return SDLK::SDL_M;
		case KOPY_KEY::N							: return SDLK::SDL_N;
		case KOPY_KEY::O							: return SDLK::SDL_O;
		case KOPY_KEY::P							: return SDLK::SDL_P;
		case KOPY_KEY::Q							: return SDLK::SDL_Q;
		case KOPY_KEY::R							: return SDLK::SDL_R;
		case KOPY_KEY::S							: return SDLK::SDL_S;
		case KOPY_KEY::T							: return SDLK::SDL_T;
		case KOPY_KEY::U							: return SDLK::SDL_U;
		case KOPY_KEY::V							: return SDLK::SDL_V;
		case KOPY_KEY::W							: return SDLK::SDL_W;
		case KOPY_KEY::X							: return SDLK::SDL_X;
		case KOPY_KEY::Y							: return SDLK::SDL_Y;
		case KOPY_KEY::Z							: return SDLK::SDL_Z;
		case KOPY_KEY::LEFTBRACE					: return SDLK::SDL_LEFTBRACE;
		case KOPY_KEY::PIPE						: return SDLK::SDL_PIPE;
		case KOPY_KEY::RIGHTBRACE					: return SDLK::SDL_RIGHTBRACE;
		case KOPY_KEY::TILDE						: return SDLK::SDL_TILDE;
		case KOPY_KEY::DELETE_KEY					: return SDLK::SDL_DELETE_KEY;
		case KOPY_KEY::PLUSMINUS					: return SDLK::SDL_PLUSMINUS;
		case KOPY_KEY::CAPSLOCK					: return SDLK::SDL_CAPSLOCK;
		case KOPY_KEY::F1							: return SDLK::SDL_F1;
		case KOPY_KEY::F2							: return SDLK::SDL_F2;
		case KOPY_KEY::F3							: return SDLK::SDL_F3;
		case KOPY_KEY::F4							: return SDLK::SDL_F4;
		case KOPY_KEY::F5							: return SDLK::SDL_F5;
		case KOPY_KEY::F6							: return SDLK::SDL_F6;
		case KOPY_KEY::F7							: return SDLK::SDL_F7;
		case KOPY_KEY::F8							: return SDLK::SDL_F8;
		case KOPY_KEY::F9							: return SDLK::SDL_F9;
		case KOPY_KEY::F10						: return SDLK::SDL_F10;
		case KOPY_KEY::F11						: return SDLK::SDL_F11;
		case KOPY_KEY::F12						: return SDLK::SDL_F12;
		case KOPY_KEY::PRINTSCREEN				: return SDLK::SDL_PRINTSCREEN;
		case KOPY_KEY::SCROLLLOCK					: return SDLK::SDL_SCROLLLOCK;
		case KOPY_KEY::PAUSE						: return SDLK::SDL_PAUSE;
		case KOPY_KEY::INSERT						: return SDLK::SDL_INSERT;
		case KOPY_KEY::HOME						: return SDLK::SDL_HOME;
		case KOPY_KEY::PAGEUP						: return SDLK::SDL_PAGEUP;
		case KOPY_KEY::END						: return SDLK::SDL_END;
		case KOPY_KEY::PAGEDOWN					: return SDLK::SDL_PAGEDOWN;
		case KOPY_KEY::RIGHT						: return SDLK::SDL_RIGHT;
		case KOPY_KEY::LEFT						: return SDLK::SDL_LEFT;
		case KOPY_KEY::DOWN						: return SDLK::SDL_DOWN;
		case KOPY_KEY::UP							: return SDLK::SDL_UP;
		case KOPY_KEY::NUMLOCKCLEAR				: return SDLK::SDL_NUMLOCKCLEAR;
		case KOPY_KEY::KP_DIVIDE					: return SDLK::SDL_KP_DIVIDE;
		case KOPY_KEY::KP_MULTIPLY				: return SDLK::SDL_KP_MULTIPLY;
		case KOPY_KEY::KP_MINUS					: return SDLK::SDL_KP_MINUS;
		case KOPY_KEY::KP_PLUS					: return SDLK::SDL_KP_PLUS;
		case KOPY_KEY::KP_ENTER					: return SDLK::SDL_KP_ENTER;
		case KOPY_KEY::KP_1						: return SDLK::SDL_KP_1;
		case KOPY_KEY::KP_2						: return SDLK::SDL_KP_2;
		case KOPY_KEY::KP_3						: return SDLK::SDL_KP_3;
		case KOPY_KEY::KP_4						: return SDLK::SDL_KP_4;
		case KOPY_KEY::KP_5						: return SDLK::SDL_KP_5;
		case KOPY_KEY::KP_6						: return SDLK::SDL_KP_6;
		case KOPY_KEY::KP_7						: return SDLK::SDL_KP_7;
		case KOPY_KEY::KP_8						: return SDLK::SDL_KP_8;
		case KOPY_KEY::KP_9						: return SDLK::SDL_KP_9;
		case KOPY_KEY::KP_0						: return SDLK::SDL_KP_0;
		case KOPY_KEY::KP_PERIOD					: return SDLK::SDL_KP_PERIOD;
		case KOPY_KEY::APPLICATION				: return SDLK::SDL_APPLICATION;
		case KOPY_KEY::POWER						: return SDLK::SDL_POWER;
		case KOPY_KEY::KP_EQUALS					: return SDLK::SDL_KP_EQUALS;
		case KOPY_KEY::F13						: return SDLK::SDL_F13;
		case KOPY_KEY::F14						: return SDLK::SDL_F14;
		case KOPY_KEY::F15						: return SDLK::SDL_F15;
		case KOPY_KEY::F16						: return SDLK::SDL_F16;
		case KOPY_KEY::F17						: return SDLK::SDL_F17;
		case KOPY_KEY::F18						: return SDLK::SDL_F18;
		case KOPY_KEY::F19						: return SDLK::SDL_F19;
		case KOPY_KEY::F20						: return SDLK::SDL_F20;
		case KOPY_KEY::F21						: return SDLK::SDL_F21;
		case KOPY_KEY::F22						: return SDLK::SDL_F22;
		case KOPY_KEY::F23						: return SDLK::SDL_F23;
		case KOPY_KEY::F24						: return SDLK::SDL_F24;
		case KOPY_KEY::EXECUTE					: return SDLK::SDL_EXECUTE;
		case KOPY_KEY::HELP						: return SDLK::SDL_HELP;
		case KOPY_KEY::MENU						: return SDLK::SDL_MENU;
		case KOPY_KEY::SELECT						: return SDLK::SDL_SELECT;
		case KOPY_KEY::STOP						: return SDLK::SDL_STOP;
		case KOPY_KEY::AGAIN						: return SDLK::SDL_AGAIN;
		case KOPY_KEY::UNDO						: return SDLK::SDL_UNDO;
		case KOPY_KEY::CUT						: return SDLK::SDL_CUT;
		case KOPY_KEY::COPY						: return SDLK::SDL_COPY;
		case KOPY_KEY::PASTE						: return SDLK::SDL_PASTE;
		case KOPY_KEY::FIND						: return SDLK::SDL_FIND;
		case KOPY_KEY::MUTE						: return SDLK::SDL_MUTE;
		case KOPY_KEY::VOLUMEUP					: return SDLK::SDL_VOLUMEUP;
		case KOPY_KEY::VOLUMEDOWN					: return SDLK::SDL_VOLUMEDOWN;
		case KOPY_KEY::KP_COMMA					: return SDLK::SDL_KP_COMMA;
		case KOPY_KEY::KP_EQUALSAS400				: return SDLK::SDL_KP_EQUALSAS400;
		case KOPY_KEY::ALTERASE					: return SDLK::SDL_ALTERASE;
		case KOPY_KEY::SYSREQ						: return SDLK::SDL_SYSREQ;
		case KOPY_KEY::CANCEL						: return SDLK::SDL_CANCEL;
		case KOPY_KEY::CLEAR						: return SDLK::SDL_CLEAR;
		case KOPY_KEY::PRIOR						: return SDLK::SDL_PRIOR;
		case KOPY_KEY::RETURN2					: return SDLK::SDL_RETURN2;
		case KOPY_KEY::SEPARATOR					: return SDLK::SDL_SEPARATOR;
		case KOPY_KEY::OUT_KEY					: return SDLK::SDL_OUT_KEY;
		case KOPY_KEY::OPER						: return SDLK::SDL_OPER;
		case KOPY_KEY::CLEARAGAIN					: return SDLK::SDL_CLEARAGAIN;
		case KOPY_KEY::CRSEL						: return SDLK::SDL_CRSEL;
		case KOPY_KEY::EXSEL						: return SDLK::SDL_EXSEL;
		case KOPY_KEY::KP_00						: return SDLK::SDL_KP_00;
		case KOPY_KEY::KP_000						: return SDLK::SDL_KP_000;
		case KOPY_KEY::THOUSANDSSEPARATOR			: return SDLK::SDL_THOUSANDSSEPARATOR;
		case KOPY_KEY::DECIMALSEPARATOR			: return SDLK::SDL_DECIMALSEPARATOR;
		case KOPY_KEY::CURRENCYUNIT				: return SDLK::SDL_CURRENCYUNIT;
		case KOPY_KEY::CURRENCYSUBUNIT			: return SDLK::SDL_CURRENCYSUBUNIT;
		case KOPY_KEY::KP_LEFTPAREN				: return SDLK::SDL_KP_LEFTPAREN;
		case KOPY_KEY::KP_RIGHTPAREN				: return SDLK::SDL_KP_RIGHTPAREN;
		case KOPY_KEY::KP_LEFTBRACE				: return SDLK::SDL_KP_LEFTBRACE;
		case KOPY_KEY::KP_RIGHTBRACE				: return SDLK::SDL_KP_RIGHTBRACE;
		case KOPY_KEY::KP_TAB						: return SDLK::SDL_KP_TAB;
		case KOPY_KEY::KP_BACKSPACE				: return SDLK::SDL_KP_BACKSPACE;
		case KOPY_KEY::KP_A						: return SDLK::SDL_KP_A;
		case KOPY_KEY::KP_B						: return SDLK::SDL_KP_B;
		case KOPY_KEY::KP_C						: return SDLK::SDL_KP_C;
		case KOPY_KEY::KP_D						: return SDLK::SDL_KP_D;
		case KOPY_KEY::KP_E						: return SDLK::SDL_KP_E;
		case KOPY_KEY::KP_F						: return SDLK::SDL_KP_F;
		case KOPY_KEY::KP_XOR						: return SDLK::SDL_KP_XOR;
		case KOPY_KEY::KP_POWER					: return SDLK::SDL_KP_POWER;
		case KOPY_KEY::KP_PERCENT					: return SDLK::SDL_KP_PERCENT;
		case KOPY_KEY::KP_LESS					: return SDLK::SDL_KP_LESS;
		case KOPY_KEY::KP_GREATER					: return SDLK::SDL_KP_GREATER;
		case KOPY_KEY::KP_AMPERSAND				: return SDLK::SDL_KP_AMPERSAND;
		case KOPY_KEY::KP_DBLAMPERSAND			: return SDLK::SDL_KP_DBLAMPERSAND;
		case KOPY_KEY::KP_VERTICALBAR				: return SDLK::SDL_KP_VERTICALBAR;
		case KOPY_KEY::KP_DBLVERTICALBAR			: return SDLK::SDL_KP_DBLVERTICALBAR;
		case KOPY_KEY::KP_COLON					: return SDLK::SDL_KP_COLON;
		case KOPY_KEY::KP_HASH					: return SDLK::SDL_KP_HASH;
		case KOPY_KEY::KP_SPACE					: return SDLK::SDL_KP_SPACE;
		case KOPY_KEY::KP_AT						: return SDLK::SDL_KP_AT;
		case KOPY_KEY::KP_EXCLAM					: return SDLK::SDL_KP_EXCLAM;
		case KOPY_KEY::KP_MEMSTORE				: return SDLK::SDL_KP_MEMSTORE;
		case KOPY_KEY::KP_MEMRECALL				: return SDLK::SDL_KP_MEMRECALL;
		case KOPY_KEY::KP_MEMCLEAR				: return SDLK::SDL_KP_MEMCLEAR;
		case KOPY_KEY::KP_MEMADD					: return SDLK::SDL_KP_MEMADD;
		case KOPY_KEY::KP_MEMSUBTRACT				: return SDLK::SDL_KP_MEMSUBTRACT;
		case KOPY_KEY::KP_MEMMULTIPLY				: return SDLK::SDL_KP_MEMMULTIPLY;
		case KOPY_KEY::KP_MEMDIVIDE				: return SDLK::SDL_KP_MEMDIVIDE;
		case KOPY_KEY::KP_PLUSMINUS				: return SDLK::SDL_KP_PLUSMINUS;
		case KOPY_KEY::KP_CLEAR					: return SDLK::SDL_KP_CLEAR;
		case KOPY_KEY::KP_CLEARENTRY				: return SDLK::SDL_KP_CLEARENTRY;
		case KOPY_KEY::KP_BINARY					: return SDLK::SDL_KP_BINARY;
		case KOPY_KEY::KP_OCTAL					: return SDLK::SDL_KP_OCTAL;
		case KOPY_KEY::KP_DECIMAL					: return SDLK::SDL_KP_DECIMAL;
		case KOPY_KEY::KP_HEXADECIMAL				: return SDLK::SDL_KP_HEXADECIMAL;
		case KOPY_KEY::LCTRL						: return SDLK::SDL_LCTRL;
		case KOPY_KEY::LSHIFT						: return SDLK::SDL_LSHIFT;
		case KOPY_KEY::LALT						: return SDLK::SDL_LALT;
		case KOPY_KEY::LGUI						: return SDLK::SDL_LGUI;
		case KOPY_KEY::RCTRL						: return SDLK::SDL_RCTRL;
		case KOPY_KEY::RSHIFT						: return SDLK::SDL_RSHIFT;
		case KOPY_KEY::RALT						: return SDLK::SDL_RALT;
		case KOPY_KEY::RGUI						: return SDLK::SDL_RGUI;
		case KOPY_KEY::MODE						: return SDLK::SDL_MODE;
		case KOPY_KEY::SLEEP						: return SDLK::SDL_SLEEP;
		case KOPY_KEY::WAKE						: return SDLK::SDL_WAKE;
		case KOPY_KEY::CHANNEL_INCREMENT			: return SDLK::SDL_CHANNEL_INCREMENT;
		case KOPY_KEY::CHANNEL_DECREMENT			: return SDLK::SDL_CHANNEL_DECREMENT;
		case KOPY_KEY::MEDIA_PLAY					: return SDLK::SDL_MEDIA_PLAY;
		case KOPY_KEY::MEDIA_PAUSE				: return SDLK::SDL_MEDIA_PAUSE;
		case KOPY_KEY::MEDIA_RECORD				: return SDLK::SDL_MEDIA_RECORD;
		case KOPY_KEY::MEDIA_FAST_FORWARD			: return SDLK::SDL_MEDIA_FAST_FORWARD;
		case KOPY_KEY::MEDIA_REWIND				: return SDLK::SDL_MEDIA_REWIND;
		case KOPY_KEY::MEDIA_NEXT_TRACK			: return SDLK::SDL_MEDIA_NEXT_TRACK;
		case KOPY_KEY::MEDIA_PREVIOUS_TRACK		: return SDLK::SDL_MEDIA_PREVIOUS_TRACK;
		case KOPY_KEY::MEDIA_STOP					: return SDLK::SDL_MEDIA_STOP;
		case KOPY_KEY::MEDIA_EJECT				: return SDLK::SDL_MEDIA_EJECT;
		case KOPY_KEY::MEDIA_PLAY_PAUSE			: return SDLK::SDL_MEDIA_PLAY_PAUSE;
		case KOPY_KEY::MEDIA_SELECT				: return SDLK::SDL_MEDIA_SELECT;
		case KOPY_KEY::AC_NEW						: return SDLK::SDL_AC_NEW;
		case KOPY_KEY::AC_OPEN					: return SDLK::SDL_AC_OPEN;
		case KOPY_KEY::AC_CLOSE					: return SDLK::SDL_AC_CLOSE;
		case KOPY_KEY::AC_EXIT					: return SDLK::SDL_AC_EXIT;
		case KOPY_KEY::AC_SAVE					: return SDLK::SDL_AC_SAVE;
		case KOPY_KEY::AC_PRINT					: return SDLK::SDL_AC_PRINT;
		case KOPY_KEY::AC_PROPERTIES				: return SDLK::SDL_AC_PROPERTIES;
		case KOPY_KEY::AC_SEARCH					: return SDLK::SDL_AC_SEARCH;
		case KOPY_KEY::AC_HOME					: return SDLK::SDL_AC_HOME;
		case KOPY_KEY::AC_BACK					: return SDLK::SDL_AC_BACK;
		case KOPY_KEY::AC_FORWARD					: return SDLK::SDL_AC_FORWARD;
		case KOPY_KEY::AC_STOP					: return SDLK::SDL_AC_STOP;
		case KOPY_KEY::AC_REFRESH					: return SDLK::SDL_AC_REFRESH;
		case KOPY_KEY::AC_BOOKMARKS				: return SDLK::SDL_AC_BOOKMARKS;
		case KOPY_KEY::SOFTLEFT					: return SDLK::SDL_SOFTLEFT;
		case KOPY_KEY::SOFTRIGHT					: return SDLK::SDL_SOFTRIGHT;
		case KOPY_KEY::CALL						: return SDLK::SDL_CALL;
		case KOPY_KEY::ENDCALL					: return SDLK::SDL_ENDCALL;
		case KOPY_KEY::LEFT_TAB					: return SDLK::SDL_LEFT_TAB;
		case KOPY_KEY::LEVEL5_SHIFT				: return SDLK::SDL_LEVEL5_SHIFT;
		case KOPY_KEY::MULTI_KEY_COMPOSE			: return SDLK::SDL_MULTI_KEY_COMPOSE;
		case KOPY_KEY::LMETA						: return SDLK::SDL_LMETA;
		case KOPY_KEY::RMETA						: return SDLK::SDL_RMETA;
		case KOPY_KEY::LHYPER						: return SDLK::SDL_LHYPER;
		case KOPY_KEY::RHYPER						: return SDLK::SDL_RHYPER;
		
		}
	};

}