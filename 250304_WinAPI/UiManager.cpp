#include "UiManager.h"
#include "BackGround.h"
void UiManager::Init()
{
    backGround = new BackGround();
    backGround->Init();
}

void UiManager::Release()
{
    backGround->Release();
    ReleaseInstance();
}

void UiManager::Update()
{
    backGround->Update();
}

void UiManager::Render(HDC hdc)
{
    backGround->Render(hdc);
}
