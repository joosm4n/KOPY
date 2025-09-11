#pragma once

#include "objparam.h"
#include <vector>
#include <memory>
#include <map>
#include <string>
#include "transform.h"
#include "macros.h"

namespace KOPY {

	class ObjectHandler
	{
	private:
		std::vector<std::shared_ptr<Transform>> m_Transforms;
		std::vector<ObjParam> m_ObjParams;

		std::vector<unsigned int> m_TextureIndex;
		std::map<std::string, unsigned int> m_TypeMap; // type name >> texture index

	public:

		ObjectHandler() {}

		unsigned int NewType(const std::string& typeName, const unsigned int textureIndex) {
			m_TypeMap.insert({ typeName , textureIndex	});
			return textureIndex;
		}

		unsigned int AddObj(const std::string& typeName, const Transform& tform) {
			auto itr = m_TypeMap.find(typeName);
			if (itr != m_TypeMap.end()) {
				m_TextureIndex.emplace_back(itr->second);
			}
			else {
				LOG2("Cannot add Obj, Invalid TypeName : ", typeName);
				return -1;
			}

			m_Transforms.emplace_back(std::make_shared<Transform>(tform));
			m_ObjParams.emplace_back(ObjParam());
			return m_Transforms.size() - 1;
		}

		unsigned int AddObj(const unsigned int textureIndex, const Transform& tform) {
			auto itr = m_TypeMap.begin();
			for (auto itr = m_TypeMap.begin(); itr != m_TypeMap.end(); ++itr) {
				if (itr->second == textureIndex) {
					m_TextureIndex.emplace_back(textureIndex);
					m_Transforms.emplace_back(std::make_shared<Transform>(tform));
					m_ObjParams.emplace_back(ObjParam());
					break;
				}
			}

			if (itr == m_TypeMap.end()) {
				LOG2("Cannot add Obj as TextureIndex does not match a initalized type. Index : ", textureIndex);
				return -1;
			}
			else
				return m_Transforms.size() - 1;
		}

		inline bool ValidIndex(unsigned int tformIndex) const {
			return (tformIndex < m_Transforms.size());
		}

		inline unsigned int NumTransforms() const {
			return m_Transforms.size();
		}

		void UpdatePhys(float deltaTime) {
			for (int i = 0; i < m_Transforms.size(); i++) {
				m_Transforms.at(i)->UpdatePhys(deltaTime);
			}
		}

		std::shared_ptr<Transform> GetTransform(unsigned int tformIndex) const {
			if (tformIndex > m_Transforms.size() - 1) {
				LOG2("Invalid GetTransform() Transform Index ", tformIndex);
				return nullptr;
			}
			return m_Transforms.at(tformIndex);
		}

		unsigned int GetTextureIndex(unsigned int tformIndex) const {
			if (tformIndex > m_Transforms.size() - 1) {
				LOG2("Invalid GetTextrureIndex() Transform Index ", tformIndex);
				return -1;
			}
			return m_TextureIndex.at(tformIndex);
		}

		unsigned int GetTextureIndex(const std::string& typeName) const {
			auto itr = m_TypeMap.find(typeName);
			if (itr != m_TypeMap.end()) {
				return itr->second;
			}
			else {
				LOG2("Cannot GetTextureIndex() , Invalid TypeName : ", typeName);
				return -1;
			}
		}

		bool ResizeTexture(unsigned int index, float width, float height) {
			m_Transforms.at(index)->SetSize(width, height);
			return true;
		}

		bool ShowTexture(unsigned int tformIndex) {
			ERR_HANDLE(!ValidIndex(tformIndex), "Invalid ShowTexture() transform index", return false;)
			m_Transforms.at(tformIndex)->RenderFlag = true;
			return true;
		}

		bool HideTexture(unsigned int tformIndex) {
			ERR_HANDLE(!ValidIndex(tformIndex), "Invalid HideTexture() transform index", return false;)
			m_Transforms.at(tformIndex)->RenderFlag = false;
			return true;
		}

		bool MoveTexture(unsigned int tformIndex, float pointx, float pointy) {
			ERR_HANDLE(!ValidIndex(tformIndex), "Invalid MoveTexture() transform index", return false;)
			m_Transforms.at(tformIndex)->SetPos(pointx, pointy);
			return true;
		}

		bool PushTexture(unsigned int tformIndex, float push_x, float push_y) {
			ERR_HANDLE(!ValidIndex(tformIndex), "Invalid PushTexture() transform index", return false;)
			m_Transforms.at(tformIndex)->FRect.x += push_x;
			m_Transforms.at(tformIndex)->FRect.y += push_y;
		}

		bool RotateTexture(unsigned int tformIndex, float degrees) {
			ERR_HANDLE(!ValidIndex(tformIndex), "Invalid RotateTexture() transform index", return false;)
			m_Transforms.at(tformIndex)->Rotation += degrees;
			return true;
		}

		bool SetVel(unsigned int tformIndex, KOPY::Vec2 vel) {
			ERR_HANDLE(!ValidIndex(tformIndex), "Invalid SetVel() transform index", return false;)

			maths::vec2& objVel = m_Transforms.at(tformIndex)->Velocity;
			float& maxVel = m_ObjParams.at(tformIndex).max_vel;

			abs(vel.x) > maxVel ? objVel.x = maxVel : objVel.x = vel.x;
			abs(vel.y) > maxVel ? objVel.y = maxVel : objVel.y = vel.y;
			return true;
		}

		bool AddVel(unsigned int tformIndex, KOPY::Vec2 vel) {
			ERR_HANDLE(!ValidIndex(tformIndex), "Invalid AddVel() transform index", return false;)
			m_Transforms.at(tformIndex)->Velocity += KopyToMaths(vel);
			return true;
		}

		bool SetRotVel(unsigned int tformIndex, float rotVel) {
			ERR_HANDLE(!ValidIndex(tformIndex), "Invalid SetRotVel() transform index", return false;)
			m_Transforms.at(tformIndex)->RotVel = rotVel;
			return true;
		}

		bool SetMaxVel(unsigned int tformIndex, float maxVel) {
			ERR_HANDLE(!ValidIndex(tformIndex), "Invalid SetMaxVel() transform index", return false;)
			m_ObjParams.at(tformIndex).max_vel = maxVel;
			return true;
		}

		bool SetMaxAcel(unsigned int tformIndex, float maxAcel) {
			ERR_HANDLE(!ValidIndex(tformIndex), "Invalid SetMaxAcel() transform index", return false;)
			m_ObjParams.at(tformIndex).max_acel = maxAcel;
			return true;
		}

		maths::vec2 GetCentre(unsigned int tformIndex) const {
			ERR_HANDLE(!ValidIndex(tformIndex), "Invalid GetCentre() transform index", return maths::vec2(0, 0))
			return m_Transforms.at(tformIndex)->Centre();
		}

		float GetRadius(unsigned int tformIndex) const {
			ERR_HANDLE(!ValidIndex(tformIndex), "Invalid GetCentre() transform index", return -1);
			return m_Transforms.at(tformIndex)->Radius();
		}

	};

}