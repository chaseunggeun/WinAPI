#include "Missile.h"
#include "CommonFunction.h"
#include "Collider.h"
#include "CollisionManager.h"
#include "Image.h"
#include "ImageManager.h"
void Missile::Init()
{
	pos = { 0, 0 };
	isActived = false;
	color = RGB(255, 255, 255);
	playerMoveSpeed = 500.0f;
	enemyMoveSpeed = 400.0f;
	size = 20;
	type = CollisionType::NONE;
	//destination;
	collider = new Collider();
	collider->Init(this, size, pos, type);
	CollisionManager::GetInstance()->AddCollider(collider);

	//image = new Image();
	//image->Init(TEXT("Image/bullet.bmp"), 21, 21, 1, 1, true, RGB(255, 0, 255));
	image = ImageManager::GetInstance()->AddImage("NormalMissile", TEXT("Image/bullet.bmp"), 21, 21, 1, 1, true, RGB(255, 0, 255));

}

void Missile::Release()
{
	/*if (collider) {
		CollisionManager::GetInstance()->RemoveCollider(collider);
		collider->Release();
		delete collider;
		collider = nullptr;
	}*/
	isActived = false;
	/*if (image)
	{
		image->Release();
		delete image;
		image = nullptr;
	}*/
}

void Missile::Update()
{
	if (isActived)
	{
		 Move();
		 collider->SetPos(pos.x, pos.y);
	}
	if (isActived && IsOutofScreen())
	{
		isActived = false;
		collider = nullptr;
	}
}

void Missile::Render(HDC hdc)
{
	if (isActived)
	{
		// RenderEllipseAtCenter(hdc, pos.x, pos.y, size, size);
		image->FrameRender(hdc, pos.x, pos.y, 0, 0, false);
	}

}

void Missile::Move()
{
	if (isActived)
	{
		if (type == CollisionType::PlayerMissile)
			pos.y -= playerMoveSpeed * TimerManager::GetInstance()->GetDeltaTime();
		else if (type == CollisionType::EnemyMissile)
			pos.y += enemyMoveSpeed * TimerManager::GetInstance()->GetDeltaTime();
	}
	else
	{
		pos.x = -100;
		pos.y = -100;
	}
}

bool Missile::IsOutofScreen()
{
	float right = pos.x + size / 2;
	float left = pos.x - size / 2;
	float top = pos.y - size / 2;
	float bottom = pos.y + size / 2;

	if (right < 0 || left > WINSIZE_X 
		|| bottom < 0 || top > WINSIZE_Y)
		return true;

	return false;
}

Missile::Missile()
{
}

Missile::~Missile()
{
}
