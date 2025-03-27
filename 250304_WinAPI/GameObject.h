#pragma once
#include "config.h"

class Collider;
class GameObject
{
public:
	virtual void Init() = 0;		// 멤버 변수의 초기화, 메모리 할당
	virtual void Release() = 0;		// 메모리 해제
	virtual void Update() = 0;		// 프레임 단위로 게임 로직 실행(데이터 계산)
	virtual void Render(HDC hdc);	// 프레임 단위로 출력(이미지, 텍스트 등)

	GameObject();
	virtual ~GameObject();

	virtual CollisionType GetType() = 0;
private:
};

