#pragma once
#include "GameObject.h"
#include "config.h"

class Image;
class Collider;

class Player : public GameObject
{
public:
	void Init() override;		// ��� ������ �ʱ�ȭ, �޸� �Ҵ�
	void Release() override;		// �޸� ����
	void Update() override;		// ������ ������ ���� ���� ����(������ ���)
	void Render(HDC hdc) override;	// ������ ������ ���(�̹���, �ؽ�Ʈ ��)

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

