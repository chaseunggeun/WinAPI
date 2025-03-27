#include "Enemy.h"
#include "CommonFunction.h"
#include "Tank.h"
#include "Image.h"
#include "Collider.h"
#include "CollisionManager.h"
#include "MissileManager.h"
#include "ImageManager.h"

/*
	STL (Standard Template Library) : Vector
	�����迭 �����ϴ� ǥ�� ���ø� ���̺귯�� �����̳�
	�迭�� ��������� ũ�Ⱑ �ڵ����� �����ȴ�.

	���� : �������� �� �ε����� ����ؼ� O(1) �ð����⵵��
	���ҿ� ������ �����ϴ�

	���� : �迭�� ����. �߰��� ���Ҹ� ����, ������ �� �����
	�ð����⵵ O(n) �� ���̵��.
*/
void Enemy::Init(float posX, float posY)
{
	pos = { posX , posY };
	moveSpeed = 20.0f;
	angle = -90.0f;
	isAlive = true;
	size = 30;
	animationFrame = 0;
	elapseFrame = 0;
	elapsedTime = 0.0f;
	image = ImageManager::GetInstance()->AddImage("Normal_Enemy",
		TEXT("Image/ufo.bmp"), 530, 32, 10, 1, true, RGB(255, 0, 255));

	type = CollisionType::Enemy;
	maxFireCycle = 3000;
	curFireCycle = 0;

	collider = new Collider();
	collider->Init(this, size, pos, type);
	CollisionManager::GetInstance()->AddCollider(collider);
}

void Enemy::Release()
{
	isAlive = false;
}

void Enemy::Update()
{
	if (isAlive)
	{
		Move();
		elapseFrame++;
		
		elapsedTime += TimerManager::GetInstance()->GetDeltaTime();
		if (elapsedTime > 0.1f)
		{
			animationFrame++;
			if (animationFrame > image->GetMaxFrameX()-1)
			{
				animationFrame = 0;
			}
			elapsedTime = 0.0f;
		}
		collider->SetPos(pos.x, pos.y);

		curFireCycle++;
		if (curFireCycle > maxFireCycle)
		{
			MissileManager::GetInstance()->AddMissile(pos, true, CollisionType::EnemyMissile);
			curFireCycle = 0;
		}
	}
}

void Enemy::Render(HDC hdc)
{
	if (isAlive)
	{
		image->FrameRender(hdc, pos.x, pos.y, animationFrame,0);
		// RenderRectAtCenter(hdc, pos.x, pos.y, size, size);
	}
}

void Enemy::Move()
{
	pos.x+= moveSpeed * TimerManager::GetInstance()->GetDeltaTime();
	if (pos.x > WINSIZE_X) pos.x = 0;
}

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}
