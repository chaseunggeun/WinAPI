#pragma once
#include "GameObject.h"
#include "config.h"

class Collider;
class Image;

class Missile : public GameObject
{
private:
	FPOINT pos;
	bool isActived;
	COLORREF color;
	float playerMoveSpeed;
	float enemyMoveSpeed;
	FPOINT destination;
	int size;
	CollisionType type;
	Collider* collider;
	Image* image;

public:
	void Init() override;
	void Release() override;
	void Update() override;
	void Render(HDC hdc) override;

	void Move();
	bool IsOutofScreen();

	// getter, setter
	inline bool GetIsActived() { return isActived; }
	inline void SetIsActived(bool isActived) { this->isActived = isActived;	}

	inline void SetPos(FPOINT pos) { this->pos = pos; }
	inline FPOINT GetPos() { return pos; }

	inline void SetType(CollisionType type) { this->type = type; }
	CollisionType GetType() override { return type; }

	Missile();
	~Missile();

};

