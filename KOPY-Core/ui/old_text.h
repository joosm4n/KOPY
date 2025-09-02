#pragma once

#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <vector>
#include <string>
#include <KO_Maths/maths.h>
#include "../macros.h"

constexpr unsigned int MAX_LINES = 63;
constexpr const char* FONT_PATH = "assets/fonts/test_font.ttf";

namespace KOPY {

	class Text
	{
	private:
		TTF_Text* m_Text;
		TTF_Font* m_Font; // Make font index
		SDL_Color m_Color;
		float m_PtSize;

		TTF_TextEngine* m_TextEngine;
		bool m_RenderFlag;

		std::vector<std::string> m_Content;
		int m_LineCount;
		Uint8 m_WordsPerLine[MAX_LINES];

		int* m_ContentNum;
		bool m_IsContentNum;
		std::string m_ContentPrefix;

		std::string m_DisplayContent;
		int m_DisplayedLine;
		float m_DispWidth;
		float m_DispHeight;

		float m_Xpos;
		float m_Ypos;

		SDL_Texture* m_TextBoxTexture;
		SDL_FRect m_TextBoxFrect;
		SDL_Color m_TextBoxColor;
		int m_TBoxBorder;
		bool m_HasTextbox;
		bool m_TBHasTexture;

	public:
		Text(SDL_Renderer* renderer = nullptr);
		~Text();

		void HandlerSetup(TTF_Font* font, TTF_TextEngine* engine) {
			m_Font = font;
			m_TextEngine = engine;
		}
		void AddRenderer(SDL_Renderer* renderer);
		void SetContent(const std::string& content);

#if NO_CURRENT_USAGE
		void SetContentNum(int& var, const std::string prefix);
		void SetContentFile(const char* path);

		void SetTextBox(SDL_Renderer*& renderer, const char* texture_file);
		void SetTextBox(const SDL_Color* color);

		void DisplayLine(const int line);
		void NextLine();
#endif NO_CURRENT_USAGE

		void SetPos(float x, float y);
		void SetPos(maths::vec2 position);
		void SetShow(bool show) { m_RenderFlag = show; };
		void SetColor(SDL_Color color);

		void Update();

		SDL_Color* GetColor() { return &m_Color; };
#if NO_CURRENT_USAGE
		SDL_Color* GetTBColor() { return &m_TextBoxColor; };
		SDL_FRect* GetTBFrect() { return &m_TextBoxFrect; };
		bool HasTextbox() const { return m_HasTextbox; };
		int GetLineNum() const { return m_DisplayedLine; };
#endif NO_CURRENT_USAGE
		bool IsShowing() const { return m_RenderFlag; };
		void Render(SDL_Renderer* renderer);

	private:
		void UpdateFrect() {
			m_TextBoxFrect = { m_Xpos - m_TBoxBorder, m_Ypos - m_TBoxBorder,
							  m_DispWidth + 2 * m_TBoxBorder, m_DispHeight + 2 * m_TBoxBorder };
		}
	};

	
}