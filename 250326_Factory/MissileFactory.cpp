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
	std::cout << "�̻��� ���丮�� �޸� �����ȴ�.\n";
}

Missile* NormalMissileFactory::CreateMissile() // �θ�Ŭ���� �����ͷ� ����
{
	return new NormalMissile();
}

NormalMissileFactory::~NormalMissileFactory()
{
	std::cout << "�Ϲ� �̻��� ���丮�� �޸� �����ȴ�.\n";
}

Missile* SignMissileFactory::CreateMissile()
{
	return new SignMissile();
}

SignMissileFactory::~SignMissileFactory()
{
	std::cout << "���� �̻��� ���丮�� �޸� �����ȴ�.\n";
}

Missile* LazerMissileFactory::CreateMissile()
{
	return new LazerMissile();
}

LazerMissileFactory::~LazerMissileFactory()
{
	std::cout << "������ �̻��� ���丮�� �޸� �����ȴ�.\n";
}
