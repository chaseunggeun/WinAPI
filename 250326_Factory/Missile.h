#pragma once
#include "iostream"
class Missile
{
public:
	virtual void Move() = 0;	// ���������Լ�
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
	std::cout << "�߻� ���� ������ �������� ���ư���\n";
}

void NormalMissile::Notice()
{
	std::cout << "�Ϲ� �̻����� ����Ǿ���.\n";
}

void SignMissile::Move()
{
	std::cout << "���� ��� �׸��鼭 �̵��Ѵ�.\n";
}

void SignMissile::Notice()
{
	std::cout << "���� �̻����� ����Ǿ���.\n";
}

void LazerMissile::Move()
{
	std::cout << "�߻� ��ġ���� ȭ�� ������ ������ 2�ʵ��� �����ȴ�.\n";
}

void LazerMissile::Notice()
{
	std::cout << "������ �̻����� ����Ǿ���.\n";
}
