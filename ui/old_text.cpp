
#include "text.h"
#include <fstream>
#include <SDL3_image/SDL_image.h>

namespace KOPY {

	Text::Text(SDL_Renderer* renderer)
	{
		m_Xpos = 0;
		m_Ypos = 0;

		m_LineCount = 0;
		for (int i = 0; i < MAX_LINES; i++)
		{
			m_WordsPerLine[i] = 0;
		}

		m_PtSize = 24;
		//m_Font = TTF_OpenFont(FONT_PATH, m_PtSize);
		m_Text = nullptr;
		m_Color = { 0, 0, 0, 255 };
		m_RenderFlag = false;
		m_IsContentNum = false;

		m_TextBoxTexture = nullptr;
		m_TBHasTexture = false;
		m_TBoxBorder = 10;
		m_DispHeight = 0;
		m_DispWidth = 0;
		UpdateFrect();
		m_HasTextbox = true;
		m_TextBoxColor = { 255, 255, 255, 255 };
	}

	Text::~Text()
	{
		if (m_TextBoxTexture != nullptr) {
			SDL_DestroyTexture(m_TextBoxTexture);
		}
		//TTF_CloseFont(m_Font);
		TTF_DestroyText(m_Text);
		//TTF_DestroyRendererTextEngine(m_TextEngine);
	}

	void Text::AddRenderer(SDL_Renderer* renderer) 
	{
		m_TextEngine = TTF_CreateRendererTextEngine(renderer);
	}

	void Text::SetContent(const std::string& content)
	{
		m_IsContentNum = false;
		m_DisplayContent = content;
		if (m_Text != nullptr) {
			TTF_SetTextString(m_Text, m_DisplayContent.c_str(), m_DisplayContent.size());
		}
		else {
			LOG("Content Set");
			m_Text = TTF_CreateText(m_TextEngine, m_Font, m_DisplayContent.c_str(), m_DisplayContent.size());
		}
	}

	void Text::SetPos(float x, float y)
	{
		m_Xpos = x;
		m_Ypos = y;
		UpdateFrect();
	}
	void Text::SetPos(maths::vec2 position)
	{
		m_Xpos = position.x;
		m_Ypos = position.y;
		UpdateFrect();
	}

	void Text::SetColor(SDL_Color color)
	{
		m_Color = color;
		TTF_SetTextColor(m_Text, m_Color.r, m_Color.g, m_Color.b, m_Color.a);
	}

#if NO_CURRENT_USAGE

	void Text::SetContentNum(int& var, const std::string prefix)
	{
		m_IsContentNum = true;
		m_DisplayedLine = 0;
		m_ContentNum = &var;
		m_ContentPrefix = prefix;

		if (m_Content.size() < 1)
			m_Content.push_back(" ");

		m_Content.at(0) = m_ContentPrefix + std::to_string(*m_ContentNum);
		m_WordsPerLine[m_LineCount] = m_Content.at(0).size();
		m_LineCount++;

		m_DisplayContent = m_Content[m_DisplayedLine];
		m_Text = TTF_CreateText(m_TextEngine, m_Font, m_DisplayContent.c_str(), m_DisplayContent.size());
		Update();
	}



	void Text::SetContentFile(const char* path)
	{
		std::ifstream text_file(path);
		bool run = true;
		while (run)
		{
			std::string line;
			std::getline(text_file, line);

			if (line == "\\end")
			{
				run = false;
			}
			else
			{
				m_WordsPerLine[m_LineCount] = line.size();
				m_Content.push_back(line);
				m_LineCount++;
			}
		}
		text_file.close();

		m_DisplayedLine = 0;
		m_DisplayContent = m_Content[m_DisplayedLine];
		m_Text = TTF_CreateText(m_TextEngine, m_Font, m_DisplayContent.data(), strlen(m_DisplayContent.data()));

		DisplayLine(0);
	}

	void Text::SetTextBox(SDL_Renderer*& renderer, const char* texture_path)
	{
		SDL_Surface* surface = IMG_Load(texture_path);
		m_TextBoxTexture = SDL_CreateTextureFromSurface(renderer, surface);
		if (m_TextBoxTexture == nullptr)
		{
			std::cerr << "TextBox Load Error: " << SDL_GetError << " for path: " << texture_path << std::endl;
			return;
		}
		else
			m_TBHasTexture = true;
	}
	void Text::SetTextBox(const SDL_Color* color)
	{
		m_TextBoxColor = *color;
	}

	void Text::DisplayLine(const int line)
	{
		if (line <= m_LineCount)
		{
			m_DisplayedLine = line;
			m_DisplayContent = m_ContentPrefix + m_Content[m_DisplayedLine];
			TTF_SetTextString(m_Text, m_DisplayContent.data(), strlen(m_DisplayContent.data()));
			TTF_SetTextColor(m_Text, m_Color.r, m_Color.g, m_Color.b, m_Color.a);

			int width, height;
			TTF_GetTextSize(m_Text, &width, &height);
			m_DispWidth = width;
			m_DispHeight = height;
			UpdateFrect();
		}
	}

	void Text::NextLine()
	{
		int next_line = m_DisplayedLine + 1;
		DisplayLine(next_line);
	}

#endif /* NO_CURRENT_USAGE */

	void Text::Update()
	{
		if (m_IsContentNum)
		{
			m_Content.at(0) = m_ContentPrefix + std::to_string(*m_ContentNum);
			m_DisplayContent = m_Content[0];
			TTF_SetTextString(m_Text, m_DisplayContent.data(), strlen(m_DisplayContent.data()));
			TTF_SetTextColor(m_Text, m_Color.r, m_Color.g, m_Color.b, m_Color.a);

			int width, height;
			TTF_GetTextSize(m_Text, &width, &height);	
			m_DispWidth = width;
			m_DispHeight = height;
			UpdateFrect();
		}

	}

	void Text::Render(SDL_Renderer* renderer)
	{
		if (m_RenderFlag)
		{
			Update();
			/*
			if (m_HasTextbox)
			{
				if (m_TBHasTexture)
				{
					SDL_RenderTexture(renderer, m_TextBoxTexture, NULL, &m_TextBoxFrect);
				}
				else
				{
					SDL_SetRenderDrawColor(renderer, m_TextBoxColor.r, m_TextBoxColor.g, m_TextBoxColor.b, m_TextBoxColor.a);
					SDL_RenderFillRect(renderer, &m_TextBoxFrect);
				}
			}
			*/
			SDL_SetRenderDrawColor(renderer, m_Color.r, m_Color.g, m_Color.b, m_Color.a );
			TTF_DrawRendererText(m_Text, (int)m_Xpos, (int)m_Ypos);
		}

	}

}