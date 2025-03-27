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
	동적배열 제공하는 표준 템플릿 라이브러리 컨테이너
	배열과 흡사하지만 크기가 자동으로 조절된다.

	장점 : 임의접근 ㅣ 인덱스를 사용해서 O(1) 시간복잡도로
	원소에 접근이 가능하다

	단점 : 배열과 같다. 중간에 원소를 삽입, 삭제할 때 비용이
	시간복잡도 O(n) 가 많이든다.
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
