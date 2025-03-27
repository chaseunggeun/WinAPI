#pragma once
#include "config.h"
class GameObject;

class Collider
{
public:
	void Init(GameObject* owner, int size, FPOINT pos, CollisionType type);
	void Release();
	void Update();
	void Render(HDC hdc);

	GameObject* getOwner() { return owner; }
	void SetPos(float x, float y) { pos.x = x; pos.y = y; }

	FPOINT GetPos() { return pos; }
	int GetSize() { return size; }

private:
	GameObject* owner;
	FPOINT pos;
	int size;
	CollisionType type;
};

