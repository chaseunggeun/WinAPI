#pragma once
#include <vector>

class Missile;
class MissileFactory
{
private:
	std::vector<Missile*> vecMissile;
	virtual Missile* CreateMissile() = 0; // 순수 가상 함수는 반드시 오버라이드 되어야 해서 private여도 상속됨

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

