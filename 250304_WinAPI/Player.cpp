#include "Player.h"
#include "Image.h"
#include "Collider.h"
#include "CollisionManager.h"
#include "MissileManager.h"

void Player::Init()
{
	HP = 100;
	moveSpeed = 300.0f;
	pos = { WINSIZE_X / 2, WINSIZE_Y - 50 };
	int size = 30;

	image = new Image();
	image->Init(TEXT("Image/rocket.bmp"), 52, 64, 1, 1, true, RGB(255, 0, 255));

	type = CollisionType::Player;
	
	collider = new Collider();
	collider->Init(this, size, pos, type);
	CollisionManager::GetInstance()->AddCollider(collider);
}

void Player::Release()
{
	if (image)
	{
		image->Release();
		delete image;
		image = nullptr;
	}

	//if (collider) {
	//	collider->Release();
	//	delete collider;
	//	collider = nullptr;
	//}
}

void Player::Update()
{
	if (KeyManager::GetInstance()->IsStayKeyDown(VK_UP))
	{
		pos.y -= moveSpeed * TimerManager::GetInstance()->GetDeltaTime();;
		if (pos.y < 0)pos.y = 0;
	}
	if (KeyManager::GetInstance()->IsStayKeyDown(VK_DOWN))
	{
		pos.y += moveSpeed * TimerManager::GetInstance()->GetDeltaTime();
		if (pos.y > WINSIZE_Y)pos.y = WINSIZE_Y;
	}
	if (KeyManager::GetInstance()->IsStayKeyDown(VK_LEFT))
	{
		pos.x -= moveSpeed * TimerManager::GetInstance()->GetDeltaTime();
		if (pos.x < 0)pos.x = 0;
	}
	if (KeyManager::GetInstance()->IsStayKeyDown(VK_RIGHT))
	{
		pos.x += moveSpeed * TimerManager::GetInstance()->GetDeltaTime();
		if (pos.x > WINSIZE_X)pos.x = WINSIZE_X;
	}
	if (KeyManager::GetInstance()->IsOnceKeyDown(VK_SPACE))
	{
		MissileManager::GetInstance()->AddMissile({ pos.x, pos.y }, true, CollisionType::PlayerMissile);
	}

	collider->SetPos(pos.x, pos.y);
}

void Player::Render(HDC hdc)
{
	image->FrameRender(hdc, pos.x, pos.y, 0, 0, false);
}
