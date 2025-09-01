#pragma once

#include "text.h"
#include <array>

constexpr Uint8 MAX_TEXT_OBJS = 63;

namespace KOPY {

	class TextHandler
	{
	private:
		std::array<Text, MAX_TEXT_OBJS> m_TextObjs;
		unsigned int m_ObjCount;

		TTF_Font* m_Font = nullptr;
		TTF_TextEngine* m_TextEngine = nullptr;
		SDL_Renderer* m_Renderer = nullptr;
		
	public:
		bool m_Initalized = false;

		TextHandler() {
			m_ObjCount = 0;
		}

		~TextHandler() {
			//if (m_Font != nullptr) {
			//	TTF_CloseFont(m_Font);
			//}
			if (m_TextEngine != nullptr) {
				TTF_DestroyRendererTextEngine(m_TextEngine);
			}
		}

		void UseFont(const char* path) {
			LOG2("Font filepath : ", path);
			m_Font = TTF_OpenFont(path, 24);
			ERR_HANDLE(!m_Font, "Font failed to initalize", m_Font = nullptr);
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
				text.m_Text = TTF_CreateText(m_TextEngine, m_Font, text.m_Content.c_str(), text.m_Content.size());
				text.SetContent(content);
				text.SetPos(pos);
				text.SetColor({ 255, 0, 0, 255 });
				text.Print();

				m_ObjCount++;
			}
			else {
				LOG("Too many text objects");
			}
			int index = m_ObjCount;
			LOG2("Added text obj : ", m_ObjCount);
			return index;
		}

		TTF_TextEngine* GetTextEngine() { return m_TextEngine; }

		bool SetPos(int index, maths::vec2 pos) {
			ERR_HANDLE(index > m_ObjCount - 1, "Invalid text index in SetPos()", return false);
			m_TextObjs.at(index).SetPos(pos);
			return true;
		}

		void RenderAll() {
			ERR_HANDLE(m_Font == nullptr, "Font == nullptr", NULL);
			for (unsigned int i = 0; i < m_ObjCount; i++) {
				m_TextObjs.at(i).Render();
			}
		}
	};


}