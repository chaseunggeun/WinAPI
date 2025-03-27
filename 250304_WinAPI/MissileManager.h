#pragma once
#include "config.h"
#include "Singleton.h"

class Missile;
class MissileManager : public Singleton<MissileManager>
{
public:
	void Init();
	void Release();
	void Update();
	void Render(HDC hdc);
	void AddMissile(FPOINT pos, bool isActived, CollisionType type);
private:
	vector<Missile*> vecMissiles;
};

