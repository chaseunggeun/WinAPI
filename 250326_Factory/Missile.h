#pragma once
#include "iostream"
class Missile
{
public:
	virtual void Move() = 0;	// 순수가상함수
	virtual void Notice() = 0;	//

	Missile() {}
	virtual ~Missile() {}
};

class NormalMissile : public Missile
{
private:
	virtual void Move() override;
	virtual void Notice() override;
public:
	NormalMissile() {}
	virtual ~NormalMissile() {}

};

class SignMissile : public Missile
{
private:
	virtual void Move() override;
	virtual void Notice() override;
public:
	SignMissile() {}
	virtual ~SignMissile() {}

};

class LazerMissile : public Missile
{
private:
	virtual void Move() override;
	virtual void Notice() override;
public:
	LazerMissile() {}
	virtual ~LazerMissile() {}

};
void NormalMissile::Move()
{
	std::cout << "발사 시점 각도로 직선으로 날아간다\n";
}

void NormalMissile::Notice()
{
	std::cout << "일반 미사일이 생산되었다.\n";
}

void SignMissile::Move()
{
	std::cout << "사인 곡선을 그리면서 이동한다.\n";
}

void SignMissile::Notice()
{
	std::cout << "사인 미사일이 생산되었다.\n";
}

void LazerMissile::Move()
{
	std::cout << "발사 위치부터 화면 끝까지 일직선 2초동안 유지된다.\n";
}

void LazerMissile::Notice()
{
	std::cout << "레이저 미사일이 생산되었다.\n";
}
