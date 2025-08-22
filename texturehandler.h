#pragma once

#include "macros.h"
#include <vector>
#include <SDL3/SDL.h>
#include <iostream>
#include <string>
#include "transform.h"

namespace KOPY {

	class TextureHandler
	{
	private:
		std::vector<SDL_Texture*> m_Textures;
		std::vector<Transform> m_Transforms;
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
			SDL_FRect frect = { 0, 0, _texture->w, _texture->h };
			m_Transforms.emplace_back(Transform(frect));

			LOG2("Texture Loaded from ", file_path);
			return (int)(m_Textures.size()) - 1;
		}

		bool ResizeTexture(int index, float width, float height)
		{
			if (index > m_Textures.size() - 1) {
				LOG2("Invalid texture index, must be <= ", m_Textures.size() - 1);
				return false;
			}
			m_Transforms.at(index).SetSize(width, height);
			return true;
		}

		bool MoveTexture(int index, float pointx, float pointy)
		{
			if (index > m_Textures.size() - 1) {
				LOG2("Invalid texture index, must be <= ", m_Textures.size() - 1);
				return false;
			}

			m_Transforms.at(index).SetPos(pointx, pointy);
			return true;
		}

		bool RotateTexture(int index, float degrees)
		{
			if (index > m_Textures.size() - 1) {
				LOG2("Invalid texture index, must be <= ", m_Textures.size() - 1);
				return false;
			}

			m_Transforms.at(index).Rotation += degrees;
		}

		void RenderAll()
		{
			for (int i = 0; i < m_Textures.size(); i++) {
				SDL_RenderTextureRotated(m_Renderer, m_Textures.at(i), NULL,
											&m_Transforms.at(i).FRect,
											m_Transforms.at(i).Rotation,
											NULL, SDL_FLIP_NONE);
			}
		}
	};

}