#pragma once

#include "macros.h"
#include <vector>
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <iostream>
#include <string>
#include "transform.h"
#include <memory>

namespace KOPY {

#define ERR_INDEX(retCmd) if (index > m_Textures.size() - 1) { LOG2("Invalid texture index, must be <= ", m_Textures.size() - 1); retCmd; }

	class TextureHandler
	{
	private:
		std::vector<SDL_Texture*> m_Textures;
		std::vector<std::shared_ptr<Transform>> m_Transforms;
		std::vector<bool> m_RenderFlags;
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
			Transform tform(0, 0, _texture->w, _texture->h, 0);
			m_Transforms.emplace_back(std::make_shared<Transform>(tform));
			m_RenderFlags.emplace_back(false);

			LOG2("Texture Loaded from ", file_path);
			return (int)(m_Textures.size()) - 1;
		}

		inline bool GoodIndex(unsigned int index) const {
			if (index > m_Textures.size() - 1)
				return false;
			else
				return true;
		}

		bool ResizeTexture(unsigned int index, float width, float height) {
			ERR_INDEX(return false);
			m_Transforms.at(index)->SetSize(width, height);
			return true;
		}

		bool ShowTexture(unsigned int index) {
			ERR_INDEX(return false);
			m_RenderFlags.at(index) = true;
			return true;
		}

		bool HideTexture(unsigned int index) {
			if (index > m_Textures.size() - 1) {
				LOG2("Invalid texture index, must be <= ", m_Textures.size() - 1);
				return false;
			}
			m_RenderFlags.at(index) = false;
			return true;
		}

		bool MoveTexture(unsigned int index, float pointx, float pointy) {
			if (index > m_Textures.size() - 1) {
				LOG2("Invalid texture index, must be <= ", m_Textures.size() - 1);
				return false;
			}

			m_Transforms.at(index)->SetPos(pointx, pointy);
			return true;
		}

		bool PushTexture(unsigned int index, float push_x, float push_y) {
			if (index > m_Textures.size() - 1) {
				LOG2("Invalid texture index, must be <= ", m_Textures.size() - 1);
				return false;
			}
			m_Transforms.at(index)->FRect.x += push_x;
			m_Transforms.at(index)->FRect.y += push_y;
		}

		bool RotateTexture(unsigned int index, float degrees) {
			ERR_INDEX(return false);
			m_Transforms.at(index)->Rotation += degrees;
			return true;
		}

		bool SetVel(unsigned int index, KOPY::Vec2 vel) {
			ERR_INDEX(return false);
			m_Transforms.at(index)->Velocity = KopyToMaths(vel);
			return true;
		}

		bool SetRotVel(unsigned int index, float rotVel) {
			ERR_INDEX(return false);
			m_Transforms.at(index)->RotVel = rotVel;
			return true;
		}

		maths::vec2 GetCentre(unsigned int index) const {
			ERR_INDEX(return maths::vec2(0, 0));
			return m_Transforms.at(index)->Centre();
		}

		float GetRadius(unsigned int index) const {
			ERR_INDEX(return -1);
			return m_Transforms.at(index)->Radius();
		}

		std::shared_ptr<Transform> GetTransform(unsigned int index) {
			return m_Transforms.at(index);
		}

		void RenderAll() {
			for (int i = 0; i < m_Textures.size(); i++) {
				SDL_RenderTextureRotated(m_Renderer, m_Textures.at(i), NULL,
											&m_Transforms.at(i)->FRect,
											m_Transforms.at(i)->Rotation,
											NULL, SDL_FLIP_NONE);
				
				if (m_DebugView) {

					SDL_SetRenderDrawColor(m_Renderer, 255, 255, 255, 255);

					float radius = m_Transforms.at(i)->Radius();
					maths::vec2 centre = m_Transforms.at(i)->Centre();

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

		void UpdatePhys(float deltaTime) {
			for (int i = 0; i < m_Textures.size(); i++) {
				m_Transforms.at(i)->UpdatePhys(deltaTime);
			}
		}
	};

}