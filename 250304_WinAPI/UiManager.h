#pragma once
#include "Singleton.h"
#include "config.h"

class BackGround;
class UiManager : public Singleton<UiManager>
{
public:
	void Init();
	void Release();
	void Update();
	void Render(HDC hdc);

	UiManager() {};
	~UiManager() {};

private:
	BackGround* backGround;
};

