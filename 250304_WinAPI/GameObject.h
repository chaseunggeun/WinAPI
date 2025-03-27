#pragma once
#include "config.h"

class Collider;
class GameObject
{
public:
	virtual void Init() = 0;		// ��� ������ �ʱ�ȭ, �޸� �Ҵ�
	virtual void Release() = 0;		// �޸� ����
	virtual void Update() = 0;		// ������ ������ ���� ���� ����(������ ���)
	virtual void Render(HDC hdc);	// ������ ������ ���(�̹���, �ؽ�Ʈ ��)

	GameObject();
	virtual ~GameObject();

	virtual CollisionType GetType() = 0;
private:
};

