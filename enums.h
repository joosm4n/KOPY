#pragma once

constexpr unsigned int NUM_KEYS = 76;

enum KO_KEY {
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
 SDL_PLUSMINUS              = 0x000000b1u /**< '\xB1' */
};

