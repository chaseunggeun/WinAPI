#include "MissileManager.h"
#include "Missile.h"

void MissileManager::Init()
{
	vecMissiles.resize(300);
	/*for (auto iter = vecMissiles.begin(); iter != vecMissiles.end(); iter++)
	{
		(*iter) = new Missile();
		(*iter)->Init();
	}*/
}

void MissileManager::Release()
{
	for (auto iter = vecMissiles.begin(); iter != vecMissiles.end(); iter++)
	{
		if (*iter) {
			(*iter)->Release();
			delete (*iter);
		}
	}
	vecMissiles.clear();
	MissileManager::ReleaseInstance();
}

void MissileManager::Update()
{
	for (auto iter = vecMissiles.begin(); iter != vecMissiles.end(); iter++)
	{
		if (*iter)
		{
			(*iter)->Update();
			/*if ((*iter)->GetIsActived() == false)
			{
				(*iter)->Release();
				delete (*iter);
				(*iter) = nullptr;
			}*/
		}
	}
}

void MissileManager::Render(HDC hdc)
{
	for (auto iter = vecMissiles.begin(); iter != vecMissiles.end(); iter++)
	{
		if(*iter) (*iter)->Render(hdc);
	}
}

void MissileManager::AddMissile(FPOINT pos, bool isActived, CollisionType type)
{
	Missile* missile = new Missile();
	missile->Init();
	missile->SetPos(pos);
	missile->SetIsActived(isActived);
	missile->SetType(type);
	vecMissiles.push_back(missile);
}
