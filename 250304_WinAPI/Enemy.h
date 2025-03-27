#pragma once
#include "GameObject.h"

class Tank;
class Image;
class Collider;

enum class State
{
	None,
	Dash
};
class Enemy : public GameObject	// is-a
{
private:
	FPOINT pos;
	float moveSpeed;
	float angle;
	bool isAlive;
	int size;
	int animationFrame;
	int elapseFrame;
	float elapsedTime;

	Image* image;
	Collider* collider;
	CollisionType type;
	int maxFireCycle;
	int curFireCycle;
	
public:
	void Init(float posX = 0.0f, float posY = 0.0f);
	void Init() override {};
	void Release() override;
	void Update() override;
	void Render(HDC hdc) override;

	void Move();

	inline void SetIsAlive(bool isAlive) { this->isAlive = isAlive; }
	inline bool GetIsAlive() { return isAlive;}
	inline FPOINT GetPos() { return pos; }
	inline int GetSize() { return size; }
	CollisionType GetType() override { return type; }
	Enemy();
	~Enemy();

};

