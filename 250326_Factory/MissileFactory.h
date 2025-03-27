#pragma once
#include <vector>

class Missile;
class MissileFactory
{
private:
	std::vector<Missile*> vecMissile;
	virtual Missile* CreateMissile() = 0; // ���� ���� �Լ��� �ݵ�� �������̵� �Ǿ�� �ؼ� private���� ��ӵ�

public:
	void AddMissile();

	MissileFactory() {}
	virtual ~MissileFactory();
};

class NormalMissileFactory : public MissileFactory
{
private:
	virtual Missile* CreateMissile() override;
public:
	NormalMissileFactory() {}
	virtual ~NormalMissileFactory();
};

class SignMissileFactory : public MissileFactory
{
private:
	virtual Missile* CreateMissile() override;
public:
	SignMissileFactory() {}
	virtual ~SignMissileFactory();
};

class LazerMissileFactory : public MissileFactory
{
private:
	virtual Missile* CreateMissile() override;
public:
	LazerMissileFactory() {}
	virtual ~LazerMissileFactory();
};

