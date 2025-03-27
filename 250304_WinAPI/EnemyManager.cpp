#include "EnemyManager.h"
#include "Enemy.h"


void EnemyManager::Init()
{
	// 1. �迭
	/*enemys = new Enemy[10];
	for (int i = 0; i < 10; i++)
	{
		enemys[i].Init();
	}*/

	// 2. vector
	/*
		push_back() �Լ��� ���� : ���ϰ� �Ǹ� �������� �� ���� (���Ҵ� �ݺ�����)
	*/

	//for (int i = 0; i < 10; i++)
	//{
	//	vecEnemys.push_back(new Enemy);
	//	vecEnemys[i]->Init();
	//}

	//vecEnemys.capacity();		// �����̳� ũ��(�Ҵ�� �޸� ũ��)
	//vecEnemys.reserve(60);	// �޸𸮸� 60����ŭ �̸� �Ҵ�

	//vecEnemys.size();			// 10 : ������ ����
	//vecEnemys.resize(60);		// ���� 60���� ����ȴ�.(�ʱ�ȭ �� �� ���·�, Enemy*�� ������ �� �ִ� ��������, new ����� ��)

	vecEnemys.resize(10);
	for (int i = 0; i < 10; i++)
	{
		vecEnemys[i] = new Enemy();
		vecEnemys[i]->Init(100.0f + 130.0f * (i % 5), 80.0f + 90.0f * (i / 5));
	}
}

void EnemyManager::Release()
{
	for (int i = 0; i < vecEnemys.size(); i++)
	{
		vecEnemys[i]->Release();
		delete vecEnemys[i]; // clear�� ���� �ϸ� delete�� �� ���� ��
	}
	vecEnemys.clear();	// ���Ұ� ��� ���ŵǰ� capacity�� ���� ��.
	EnemyManager::ReleaseInstance();
}

void EnemyManager::Update()
{
	for (int i = 0; i < vecEnemys.size(); i++)
	{
		vecEnemys[i]->Update();
	}
}

void EnemyManager::Render(HDC hdc)
{
	for (int i = 0; i < vecEnemys.size(); i++)
	{
		vecEnemys[i]->Render(hdc);
	}
}

void EnemyManager::AddEnemy(int size)
{
	for (int i = 0; i < size; i++)
	{
		vecEnemys.push_back(new Enemy());
		vecEnemys.back()->Init(0, 0);
	}
}

EnemyManager::EnemyManager()
{
}

EnemyManager::~EnemyManager()
{
}
