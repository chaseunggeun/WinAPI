#pragma once
#include "GameObject.h"

class Image;
class Player;

class MainGame : public GameObject
{
private:
	HDC hdc;
	PAINTSTRUCT ps;
	int mousePosX = 0, mousePosY = 0;
	FPOINT mousePos;
	wchar_t szText[128];

	Image* backBuffer;
	Player* player;

	Timer* timer;
public:
	void Init() override;	// override (�θ�Ŭ������ ���� �Լ��̸�, ������ �ٸ��� �����ϰ� ���� ��)
					// <-> overload (���� �Լ� �̸�, �Ű����� Ÿ�԰� ������ �ٸ��� �ٸ� �Լ��� ó��)
	void Release() override;	
	void Update() override;	
	void Render();

	LRESULT MainProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);

	MainGame();
	~MainGame();
	CollisionType GetType() override { return CollisionType::NONE; }
};

