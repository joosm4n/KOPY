#pragma once

#include <vector>
#include <SDL3/SDL.h>
#include <iostream>
#include <string>

#define LOG(x) std::cout << x << std::endl;
#define LOG2(x, y) std::cout << x << y << std::endl;

namespace KOPY {

	class TextureHandler
	{
	private:
		std::vector<SDL_Texture*> m_Textures;
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

		int LoadTexture(std::string& file_path) 
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
			return m_Textures.size() - 1;
		}
	};

}