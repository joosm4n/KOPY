#pragma once

#include "macros.h"
#include <vector>
#include <SDL3/SDL.h>
#include <iostream>
#include <string>

namespace KOPY {

	class TextureHandler
	{
	private:
		std::vector<SDL_Texture*> m_Textures;
		std::vector<SDL_FRect> m_FRects;
		SDL_Renderer* m_Renderer;

	public:
		TextureHandler()
			: m_Renderer(nullptr)
		{ }

		TextureHandler(SDL_Renderer* renderer)
			: m_Renderer(renderer)
		{ }

		~TextureHandler()
		{ 
			for (int i = 0; i < m_Textures.size(); i++) {
				SDL_DestroyTexture(m_Textures.at(i));
			}
		}

		bool SetRenderer(SDL_Renderer* renderer)
		{
			if (m_Renderer != nullptr) {
				LOG("Renderer already assigned");
				return false;
			}
			else {
				m_Renderer = renderer;
				return true;
			}
		}

		int LoadTexture(const std::string& file_path) 
		{
			if (m_Renderer == nullptr) {
				LOG("Renderer not loaded to TextureHandler");
				return -1;
			}

			SDL_Surface* _surface = SDL_LoadBMP(file_path.data());
			//SDL_Surface* _surface = SDL_LoadBMP("assets/test_bmp.bmp");
			if (!_surface) {
				LOG2("SDL_LoadBMP error : ", SDL_GetError());
				return -1;
			}
			SDL_Texture* _texture = SDL_CreateTextureFromSurface(m_Renderer, _surface);
			if (!_texture) {
				LOG2("SDL_Texture load error : ", SDL_GetError());
				SDL_DestroySurface(_surface);
				return -1;
			}
			m_Textures.emplace_back(_texture);
			SDL_DestroySurface(_surface);

			SDL_FRect frect = { 0, 0, 0, 0 };
			m_FRects.emplace_back(frect);

			LOG2("Texture Loaded from ", file_path);
			return (int)(m_Textures.size()) - 1;
		}

		bool ResizeTexture(int index, float width, float height)
		{
			if (index > m_Textures.size() - 1) {
				LOG2("Invalid texture index, must be <= ", m_Textures.size() - 1);
				return false;
			}

			m_FRects.at(index).w = width;
			m_FRects.at(index).h = height;
			return true;
		}

		bool PlaceTexture(int index, float pointx, float pointy)
		{
			if (index > m_Textures.size() - 1) {
				LOG2("Invalid texture index, must be <= ", m_Textures.size() - 1);
				return false;
			}

			m_FRects.at(index).x = pointx;
			m_FRects.at(index).y = pointy;
			LOG2("x : ", m_FRects.at(index).x);
			LOG2("y : ", m_FRects.at(index).y);
			return true;
		}

		void RenderAll()
		{
			for (int i = 0; i < m_Textures.size(); i++) {
				SDL_RenderTexture(m_Renderer, m_Textures.at(i), NULL, &m_FRects.at(i));
			}
		}
	};

}