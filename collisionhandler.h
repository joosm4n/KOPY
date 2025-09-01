#pragma once

#include <KO_Maths/maths.h>
#include <vector>
#include "objecthandler.h"

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
		std::vector<unsigned int> m_TformIndices;
		std::vector<Collision> m_Collisions;

	private:
		bool CircleCircle(Transform& a, Transform& b, Collision& col) {

			maths::vec2 diff = a.Centre() - b.Centre();
			float dist = length(diff);
			float sumRadii = a.Radius() + b.Radius();
			static const float epsilon = 1;

			if (dist < sumRadii + epsilon) {
				col.depth = abs(sumRadii - dist);
				col.normal = normalize(diff);
				return true;
			}
			else 
				return false;
		}

		bool BoundingBoxCheck(const Transform& a, const Transform& b) {

			// Area
			bool horiMiss = (a.Centre().x + a.Radius() < b.Centre().x - b.Radius()) && (a.Centre().x - a.Radius() > b.Centre().x + b.Radius());
			bool vertMiss = (a.Centre().y + a.Radius() < b.Centre().y - b.Radius()) && (a.Centre().y - a.Radius() > b.Centre().y + b.Radius());
			if (horiMiss && vertMiss) {
				return false;
			}
			else {
				return true;
			}
		}

	public:

		CollisionHandler() { }

		bool AddCollider(unsigned int tformIndex) {
			m_TformIndices.emplace_back(tformIndex);
			return true;
		}
		
		bool RemoveColldier(unsigned int tformIndex) {
			for (unsigned int i = 0; i < m_TformIndices.size(); i++) {
				if (tformIndex == m_TformIndices.at(i)) {
					m_TformIndices.erase(m_TformIndices.begin() + (i + 1));
					return true;
				}
			}
			return false;
		}

		bool Detect(ObjectHandler& objHandler) {

			m_Collisions.clear();
			Uint32 loop = 0;
			Collision col;
			for (size_t i = 0; i < m_TformIndices.size(); i++) {
				if (!objHandler.ValidIndex(i)) continue;
				Transform& ObjA = *objHandler.GetTransform(m_TformIndices.at(i));

				for (size_t j = i + 1; j < m_TformIndices.size(); j++) {
					loop++;
					if (!objHandler.ValidIndex(j)) continue;
					Transform& ObjB = *objHandler.GetTransform(m_TformIndices.at(j));

					if (BoundingBoxCheck(ObjA, ObjB) == false) continue;

					if (CircleCircle(ObjA, ObjB, col)) {
						col.objA = objHandler.GetTransform(m_TformIndices.at(i));
						col.objB = objHandler.GetTransform(m_TformIndices.at(j));
						m_Collisions.emplace_back(col);
						continue;
					}
				}
			}
			//LOG2("Num col checks : ", loop);
			//LOG2("Num collisions : ", m_Collisions.size());
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

				float rotA = objA.RotVel * massA / massB;
				float rotB = objB.RotVel * massB / massA;

				objA.RotVel += -rotB;
				objB.RotVel += -rotA;
			}
			return true;
		}
	};

}