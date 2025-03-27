#include "CollisionManager.h"
#include "Collider.h"
#include "GameObject.h"
#include "CommonFunction.h"
#include "player.h"

void CollisionManager::Init()
{
	colliders.resize(256);
}

void CollisionManager::Release()
{
	for (auto iter = colliders.begin(); iter != colliders.end(); iter++)
	{
		if (*iter)
		{
			(*iter)->Release();
			(*iter) = nullptr;
		}
	}
	ReleaseInstance();
}

void CollisionManager::Update()
{
	for (auto iter = colliders.begin(); iter != colliders.end(); iter++)
	{
		if (*iter) {
			(*iter)->Update();
		}
		
	}

	for (auto iter1 = colliders.begin(); iter1 != colliders.end(); iter1++)
	{
		if (*iter1) {
			for (auto iter2 = next(iter1); iter2 != colliders.end(); iter2++)
			{
				if (*iter2) {
					CheckCollision((*iter1), (*iter2));
				}
			}
		}
	}
	for (auto iter = colliders.begin(); iter != colliders.end(); iter++)
	{
		if (*iter) {
			float right = (*iter)->GetPos().x + (*iter)->GetSize() / 2;
			float left = (*iter)->GetPos().x - (*iter)->GetSize() / 2;
			float top = (*iter)->GetPos().y - (*iter)->GetSize() / 2;
			float bottom = (*iter)->GetPos().y + (*iter)->GetSize() / 2;

			if (right < 0 || left > WINSIZE_X
				|| bottom < 0 || top > WINSIZE_Y) {
				(*iter)->Release();
				delete (*iter);
				(*iter) = nullptr;
			}
		}
	}

}

void CollisionManager::Render(HDC hdc)
{
	for (auto iter = colliders.begin(); iter != colliders.end(); iter++)
	{
		if((*iter))
			(*iter)->Render(hdc);
	}
}

CollisionManager::CollisionManager()
{
}

CollisionManager::~CollisionManager()
{
}

void CollisionManager::AddCollider(Collider* col)
{
	colliders.push_back(col);
}

void CollisionManager::CheckCollision(Collider* col1, Collider* col2)
{
	CollisionType t1 = CollisionType::NONE;
	CollisionType t2 = CollisionType::NONE;
	if (col1 && col1->getOwner() && col2 && col2->getOwner())
	{
		t1 = col1->getOwner()->GetType();
		t2 = col2->getOwner()->GetType();
	}

	RECT rc1 = RectByCenter(col1->GetPos(), col1->GetSize());
	RECT rc2 = RectByCenter(col2->GetPos(), col2->GetSize());

	if (RectInRect(rc1, rc2) || RectInRect(rc2, rc1)) // 둘 중 하나라도 포함되면 충돌로 간주
	{
		// 플레이어 총알 - 적
		if ((t1 == CollisionType::PlayerMissile && t2 == CollisionType::Enemy)
			|| (t1 == CollisionType::Enemy && t2 == CollisionType::PlayerMissile))
		{
			// 적 죽음, 총알 삭제
			col1->SetPos(-100, -100);
			col2->SetPos(-100, -100);
			col1->getOwner()->Release();
			col2->getOwner()->Release();
		}

		// 적 총알 - 플레이어
		if ((t1 == CollisionType::EnemyMissile && t2 == CollisionType::Player))
		{
			// 플레이어 데미지, 총알 삭제
			col1->SetPos(-100, -100);
			col1->getOwner()->Release();
			// TODO. 플레이어 데미지
		}

		// 플레이어 - 적 총알
		if ((t1 == CollisionType::Player && t2 == CollisionType::EnemyMissile))
		{
			// 플레이어 데미지, 총알 삭제
			// TODO. 플레이어 데미지
			col2->SetPos(-100, -100);
			col2->getOwner()->Release();
		}

		// 플레이어 - 적
		if ((t1 == CollisionType::Player && t2 == CollisionType::Enemy))
		{
			// 적 죽음, 플레이어 데미지
			// TODO. 플레이어 데미지
			col2->SetPos(-100, -100);
			col2->getOwner()->Release();
		}

		// 적 - 플레이어
		if ((t1 == CollisionType::Enemy && t2 == CollisionType::Player))
		{
			// 적 죽음, 플레이어 데미지
			// TODO. 플레이어 데미지
			col1->SetPos(-100, -100);
			col1->getOwner()->Release();
		}
	}
}
