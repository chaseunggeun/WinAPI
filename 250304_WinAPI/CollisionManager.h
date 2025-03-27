#pragma once
#include "config.h"
#include "Singleton.h"

class Collider;
class CollisionManager : public Singleton<CollisionManager>
{
public:
	void Init();
	void Release();
	void Update();
	void Render(HDC hdc);

	CollisionManager();
	~CollisionManager();

	void AddCollider(Collider* col);
	void CheckCollision(Collider* col1, Collider* col2);

	void RemoveCollider(Collider* col)
	{
		colliders.erase(std::remove(colliders.begin(), colliders.end(), col), colliders.end());
	}
private:
	vector<Collider*> colliders;
};

