#pragma once

#include "KO_Maths/maths.h"
#include <vector>
#include "texturehandler.h"

namespace KOPY {

	struct Collision {
		std::shared_ptr<Transform> objA;
		std::shared_ptr<Transform> objB;
		float depth = 0.0f;
		maths::vec2 normal = { 0, 0 };

		Collision()
			: objA(nullptr), objB(nullptr), depth(0.0f), normal(0, 0)
		{}
	};

	class CollisionHandler
	{
	private:
		std::vector<unsigned int> m_Indices;
		std::vector<Collision> m_Collisions;

	private:
		bool CircleCircle(Transform& a, Transform& b, Collision& col) {

			maths::vec2 diff = { b.FRect.x - a.FRect.x, b.FRect.y - a.FRect.y };
			float len = length(diff);
			float sumRadii = a.Radius() + b.Radius();
			static const float epsilon = 1;

			if (len < sumRadii + epsilon) {
				col.depth = len - sumRadii;
				col.normal = normalize(diff);
				return true;
			}
			else
				return false;
		}

	public:

		CollisionHandler() { }

		bool AddCollider(unsigned int index) {
			m_Indices.emplace_back(index);
			return true;
		}
		
		bool RemoveColldier(unsigned int index) {
			for (unsigned int i = 0; i < m_Indices.size(); i++) {
				if (index == m_Indices.at(i)) {
					m_Indices.erase(m_Indices.begin() + (i + 1));
					return true;
				}
			}
			return false;
		}

		bool Detect(TextureHandler& tHandler) {

			m_Collisions.clear();

			Collision col;
			for (size_t i = 0; i < m_Indices.size(); i++) {
				//LOG2("i : ", i);
				if (!tHandler.GoodIndex(i)) continue;
				Transform& ObjA = *tHandler.GetTransform(m_Indices.at(i));

				for (size_t j = i + 1; j < m_Indices.size(); j++) {
					//LOG2("j : ", j);
					if (!tHandler.GoodIndex(j)) continue;
					Transform& ObjB = *tHandler.GetTransform(m_Indices.at(j));

					if (CircleCircle(ObjA, ObjB, col)) {
						//LOG("Colliding");
						col.objA = tHandler.GetTransform(m_Indices.at(i));
						col.objB = tHandler.GetTransform(m_Indices.at(j));
						m_Collisions.emplace_back(col);
						continue;
					}
				}
			}
			return true;
		}

		bool Solve(float deltaTime) {

			for (Collision& collision : m_Collisions) {

				Transform& objA = *collision.objA;
				Transform& objB = *collision.objB;

				float massA = objA.Mass();
				float massB = objB.Mass();
				float totalMass = massB + massB;
				float moveA = (massB / totalMass) * collision.depth;
				float moveB = (massA / totalMass) * collision.depth;

				objA.Push( collision.normal *  moveA * deltaTime);
				objB.Push( collision.normal * -moveB * deltaTime);

				maths::vec2 relativeVel = objB.Velocity - objA.Velocity;
				float velAlongNormal = dot(relativeVel, collision.normal);

				float j = -(2) * velAlongNormal;
				j /= (1 / massA) + (1 / massB);

				maths::vec2 impulse = collision.normal * j;
				objA.Velocity -= impulse / massA;
				objB.Velocity += impulse / massB;

				float rotA = objA.RotVel;
				float rotB = objB.RotVel;

				objA.RotVel += -rotB / massA;
				objB.RotVel += -rotA / massB;
			}
			return true;
		}
	};

}