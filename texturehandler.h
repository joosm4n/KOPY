#pragma once

#include "macros.h"
#include <vector>
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <iostream>
#include <string>
#include "transform.h"
#include <memory>
#include "objecthandler.h"

namespace KOPY {

#define ERR_INDEX(retCmd) if (index > m_Textures.size() - 1) { LOG2("Invalid texture index, must be <= ", m_Textures.size() - 1); retCmd; }

	class TextureHandler
	{
	private:
		std::vector<SDL_Texture*> m_Textures;
		SDL_Renderer* m_Renderer;

	public:
		bool m_DebugView = true;

		TextureHandler()
			: m_Renderer(nullptr)
		{ }

		TextureHandler(SDL_Renderer* renderer)
			: m_Renderer(renderer)
		{ }

		~TextureHandler() { 
			for (int i = 0; i < m_Textures.size(); i++) {
				SDL_DestroyTexture(m_Textures.at(i));
			}
		}

		bool SetRenderer(SDL_Renderer* renderer) {
			if (m_Renderer != nullptr) {
				LOG("Renderer already assigned");
				return false;
			}
			else {
				m_Renderer = renderer;
				return true;
			}
		}

		int LoadTexture(const std::string& file_path) {
			if (m_Renderer == nullptr) {
				LOG("Renderer not loaded to TextureHandler");
				return -1;
			}

			SDL_Surface* _surface = IMG_Load(file_path.data());
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

			LOG2("Texture Loaded from ", file_path);
			return (int)(m_Textures.size()) - 1;
		}

		inline bool ValidIndex(unsigned int index) const {
			return (index < m_Textures.size());
		}

		void RenderAll(const ObjectHandler& objHandler) {
			for (int tformIndex = 0; tformIndex < objHandler.NumTransforms(); tformIndex++) {
				ERR_HANDLE(m_Textures.size() == 0, "No textures loaded, cannot render.", return);
				Transform& transform = *objHandler.GetTransform(tformIndex);
				unsigned int textureIndex = objHandler.GetTextureIndex(tformIndex);

				if (!transform.RenderFlag) continue;

				SDL_RenderTextureRotated(m_Renderer, m_Textures.at(textureIndex), NULL,
											&transform.FRect,
											transform.Rotation,
											NULL, SDL_FLIP_NONE);
				
				if (m_DebugView) {

					SDL_SetRenderDrawColor(m_Renderer, 255, 255, 255, 255);

					float radius = transform.Radius();
					maths::vec2 centre = transform.Centre();

					int numPts = radius  * maths::KO_PI;
					float inc = maths::KO_PI / numPts;
					int x, y;

					for (float theta = 0; theta < maths::KO_PI; theta += inc) {
						SDL_RenderPoint(m_Renderer, centre.x + (radius * cos(theta)),
							centre.y + (radius * sin(theta)));

						SDL_RenderPoint(m_Renderer, centre.x - (radius * cos(theta)),
							centre.y - (radius * sin(theta)));
					}
				}
					
			}
		}

	};

}