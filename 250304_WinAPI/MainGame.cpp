#include "MainGame.h"
#include "CommonFunction.h"
#include "Image.h"
#include "EnemyManager.h"
#include "UiManager.h"
#include "CollisionManager.h"
#include "Player.h"
#include "MissileManager.h"
#include "ImageManager.h"

void MainGame::Init()
{
	KeyManager::GetInstance()->Init();
	ImageManager::GetInstance()->Init();

	UiManager::GetInstance()->Init();
	CollisionManager::GetInstance()->Init();
	EnemyManager::GetInstance()->Init();
	MissileManager::GetInstance()->Init();
	player = new Player();
	player->Init();

	hdc = GetDC(g_hWnd);
	backBuffer = new Image();
	if (FAILED(backBuffer->Init(WINSIZE_X, WINSIZE_Y)))
	{
		MessageBox(g_hWnd, 
			TEXT("����� ���� ����"), TEXT("���"), MB_OK);
	}
}

void MainGame::Release()
{

	if (backBuffer)
	{
		backBuffer->Release();
		delete backBuffer;
		backBuffer = nullptr;
	}

	if (player)
	{
		player->Release();
		delete player;
		player = nullptr;
	}

	ReleaseDC(g_hWnd, hdc);

	UiManager::GetInstance()->Release();
	CollisionManager::GetInstance()->Release();
	MissileManager::GetInstance()->Release();
	EnemyManager::GetInstance()->Release();

	KeyManager::GetInstance()->Release();
	ImageManager::GetInstance()->Release();
}

void MainGame::Update()
{
	EnemyManager::GetInstance()->Update();
	UiManager::GetInstance()->Update();
	CollisionManager::GetInstance()->Update();
	MissileManager::GetInstance()->Update();
	player->Update();
	InvalidateRect(g_hWnd, NULL, false);
}

void MainGame::Render()
{
	// ����ۿ� ���� ����
	HDC hBackBufferDC = backBuffer->GetMemDC();

	UiManager::GetInstance()->Render(hBackBufferDC);
	CollisionManager::GetInstance()->Render(hBackBufferDC);
	EnemyManager::GetInstance()->Render(hBackBufferDC);
	MissileManager::GetInstance()->Render(hBackBufferDC);
	player->Render(hBackBufferDC);
	wsprintf(szText, TEXT("Mouse X : %d, Y : %d"), mousePosX, mousePosY);
	TextOut(hBackBufferDC, 20, 60, szText, wcslen(szText));

	TimerManager::GetInstance()->Render(hBackBufferDC);
	// ����ۿ� �ִ� ������ ���� hdc�� ����
	backBuffer->Render(hdc);
}

LRESULT MainGame::MainProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	switch (iMessage)
	{
	case WM_KEYDOWN:
		switch (wParam)
		{
		case 'a': case 'A':
			break;
		case 'd': case 'D':
			break;
		}
		break;
	case WM_LBUTTONDOWN:
		mousePosX = LOWORD(lParam);
		mousePosY = HIWORD(lParam);

		break;
	case WM_LBUTTONUP:
		break;
	case WM_MOUSEMOVE:
		mousePosX = LOWORD(lParam);
		mousePosY = HIWORD(lParam);

		mousePos.x = LOWORD(lParam);
		mousePos.y = HIWORD(lParam);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}

	return DefWindowProc(hWnd, iMessage, wParam, lParam);
}

MainGame::MainGame()
{
}

MainGame::~MainGame()
{
}
