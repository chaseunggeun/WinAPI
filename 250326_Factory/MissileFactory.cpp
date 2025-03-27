#include "MissileFactory.h"
#include "Missile.h"

void MissileFactory::AddMissile()
{
	Missile* missile = CreateMissile();
	vecMissile.push_back(missile);
	missile->Notice();
}

MissileFactory::~MissileFactory()
{
	std::cout << "미사일 팩토리가 메모리 해제된다.\n";
}

Missile* NormalMissileFactory::CreateMissile() // 부모클래스 포인터로 리턴
{
	return new NormalMissile();
}

NormalMissileFactory::~NormalMissileFactory()
{
	std::cout << "일반 미사일 팩토리가 메모리 해제된다.\n";
}

Missile* SignMissileFactory::CreateMissile()
{
	return new SignMissile();
}

SignMissileFactory::~SignMissileFactory()
{
	std::cout << "사인 미사일 팩토리가 메모리 해제된다.\n";
}

Missile* LazerMissileFactory::CreateMissile()
{
	return new LazerMissile();
}

LazerMissileFactory::~LazerMissileFactory()
{
	std::cout << "레이저 미사일 팩토리가 메모리 해제된다.\n";
}
