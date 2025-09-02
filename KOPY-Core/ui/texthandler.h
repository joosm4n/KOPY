#pragma once

#include "text.h"
#include <array>

constexpr Uint8 MAX_TEXT_OBJS = 63;

namespace KOPY {

	class TextHandler
	{
	private:
		std::array<Text, MAX_TEXT_OBJS> m_TextObjs;
		std::array<TTF_Font*, MAX_TEXT_OBJS> m_Fonts;
		unsigned int m_ObjCount;

		SDL_Renderer* m_Renderer = nullptr;
		TTF_TextEngine* m_TextEngine = nullptr;

		TTF_Font* m_Font = nullptr;
		std::string m_FontPath = "";
		
	public:
		bool m_Initalized = false;

		TextHandler() {
			m_ObjCount = 0;
			m_Fonts.fill(nullptr);
		}

		~TextHandler() {
			for (unsigned int i = 0; i < m_ObjCount; i++) {
				if (m_Fonts.at(i) != nullptr) {
					TTF_CloseFont(m_Font);
				}
			}
			if (m_TextEngine != nullptr) {
				TTF_DestroyRendererTextEngine(m_TextEngine);
			}
		}

		void UseFont(const char* path) {
			LOG2("Font filepath : ", path);
			m_FontPath = path;
			for (unsigned int i = 0; i < MAX_TEXT_OBJS; i++) {
				m_Fonts.at(i) = TTF_OpenFont(path, 24);
				ERR_HANDLE(!m_Fonts.at(i), "Font failed to initalize", m_Fonts.at(i) = nullptr);
			}
		}

		bool Resize(const unsigned int textIndex, const unsigned int size) {
			ERR_HANDLE(textIndex >= m_ObjCount, "Invalid text index ", return false);
			if (!TTF_SetFontSize(m_Fonts.at(textIndex), size)) {
				LOG2("TTF_SetFontSize() error : ", SDL_GetError());
				return false;
			}
			Text& text = m_TextObjs.at(textIndex);
			TTF_SetTextFont(text.m_Text, m_Fonts.at(textIndex));
		}

		void CreateTextEngine(SDL_Renderer* renderer) {
			m_Renderer = renderer;
			m_TextEngine = TTF_CreateRendererTextEngine(renderer);
			LOG("Text Engine Created");
		}

		int AddText(const std::string content, const maths::vec2& pos = { 0, 0 }) {
			ERR_HANDLE(!m_Initalized, "Cannot render text as TTF is not initalized", return -1);
			if (m_ObjCount < MAX_TEXT_OBJS) {
				m_TextObjs.at(m_ObjCount) = Text();
				Text& text = m_TextObjs.at(m_ObjCount);
				text.m_Text = TTF_CreateText(m_TextEngine, m_Fonts.at(m_ObjCount), text.m_Content.c_str(), text.m_Content.size());
				text.SetContent(content);
				text.SetPos(pos);
				m_ObjCount++;
			}
			else {
				LOG("Too many text objects");
			}
			LOG2("Added text obj : ", m_ObjCount);

			unsigned int index = m_ObjCount - 1;
			return index;
		}

		TTF_TextEngine* GetTextEngine() { return m_TextEngine; }

		bool SetPos(int index, maths::vec2 pos) {
			ERR_HANDLE(index > m_ObjCount - 1, "Invalid text index in SetPos()", return false);
			m_TextObjs.at(index).SetPos(pos);
			return true;
		}

		bool SetColor(unsigned int index, uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255) {
			ERR_HANDLE(index > m_ObjCount - 1, "Invalid text index in SetColor()", return false);
			m_TextObjs.at(index).SetColor({ r, g, b, a });
		}

		bool SetContent(unsigned int index, const char* content) {
			ERR_HANDLE(index > m_ObjCount - 1, "Invalid text index in SetColor()", return false);
			m_TextObjs.at(index).SetContent(content);
		}	

		void RenderAll() {
			for (unsigned int i = 0; i < m_ObjCount; i++) {
				m_TextObjs.at(i).Render();
			}
		}
	};


}