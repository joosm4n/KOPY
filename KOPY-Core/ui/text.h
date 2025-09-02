#pragma once

#include <SDL3_ttf/SDL_ttf.h>
#include <string>
#include "KO_Maths/maths.h"

namespace KOPY {

	class Text 
	{
	public:
		std::string m_Content;
		maths::vec2 m_Pos;
		SDL_Color m_Color;

		TTF_Text* m_Text;
		bool m_RenderFlag;

		Text() {
			m_Content = "";
			m_Pos = { 0, 0 };
			m_Text = nullptr;
			m_RenderFlag = true;
			m_Color = { 0, 0, 0, 255 };
		}

		~Text() {
			TTF_DestroyText(m_Text);
		}

		void SetContent(const std::string& content) {
			m_Content = content;
			TTF_SetTextString(m_Text, content.c_str(), content.size());
		}
	
		void SetPos(const maths::vec2& pos) {
			m_Pos = pos;
		}

		void SetColor(const SDL_Color& color) {
			m_Color = color;
			TTF_SetTextColor(m_Text, color.r, color.g, color.b, color.a);
		}

		TTF_Text* GetText() const {
			return m_Text;
		}

		void Print() const {
			LOG2("m_Content : ", m_Content);
			LOG2("m_Pos : ", m_Pos);
			LOG2("m_RenderFlag : ", m_RenderFlag);
		}

		void Render() const {
			if (m_Text != nullptr) {
				TTF_DrawRendererText(m_Text, m_Pos.x, m_Pos.y);
			}
			else {
				LOG("Cannot render text as m_Text is uninitalized");
			}
		}
	};
}