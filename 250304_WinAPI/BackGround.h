#pragma once
#include "config.h"
class Image;
class BackGround
{
public:
	void Init();
	void Release();
	void Update();
	void Render(HDC hdc);

private:
	Image* image;
};

