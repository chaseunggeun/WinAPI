#pragma once
#include "GameObject.h"
#include "config.h"

class Image;
class Collider;

class Player : public GameObject
{
public:
	void Init() override;		// 멤버 변수의 초기화, 메모리 할당
	void Release() override;		// 메모리 해제
	void Update() override;		// 프레임 단위로 게임 로직 실행(데이터 계산)
	void Render(HDC hdc) override;	// 프레임 단위로 출력(이미지, 텍스트 등)

	void PlayerDamaged(int damage) { HP -= damage; }
	int GetHp() { return HP; }
	FPOINT GetPos() { return pos; }

	CollisionType GetType() override { return type; }
private:
	float moveSpeed;
	FPOINT pos;
	int size;
	int HP;

	Image* image;
	Collider* collider;
	CollisionType type;
};

