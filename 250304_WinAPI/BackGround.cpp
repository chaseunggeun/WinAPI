#include "BackGround.h"
#include "Image.h"
void BackGround::Init()
{
	image = new Image();
	image->Init(TEXT("Image/background2.bmp"), 600, 800, false, RGB(255, 0, 255));
}

void BackGround::Release()
{
	image->Release();
	delete image;
	image = nullptr;
	
}

void BackGround::Update()
{
}

void BackGround::Render(HDC hdc)
{
	image->Render(hdc, 0, 0);
}
