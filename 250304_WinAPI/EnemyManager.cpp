#include "EnemyManager.h"
#include "Enemy.h"


void EnemyManager::Init()
{
	// 1. 배열
	/*enemys = new Enemy[10];
	for (int i = 0; i < 10; i++)
	{
		enemys[i].Init();
	}*/

	// 2. vector
	/*
		push_back() 함수의 단점 : 막하게 되면 터져버릴 수 있음 (재할당 반복으로)
	*/

	//for (int i = 0; i < 10; i++)
	//{
	//	vecEnemys.push_back(new Enemy);
	//	vecEnemys[i]->Init();
	//}

	//vecEnemys.capacity();		// 컨테이너 크기(할당된 메모리 크기)
	//vecEnemys.reserve(60);	// 메모리를 60개만큼 미리 할당

	//vecEnemys.size();			// 10 : 원소의 개수
	//vecEnemys.resize(60);		// 원소 60개가 저장된다.(초기화 안 된 상태로, Enemy*을 저장할 수 있는 공간으로, new 해줘야 함)

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
		delete vecEnemys[i]; // clear를 먼저 하면 delete할 수 없게 됨
	}
	vecEnemys.clear();	// 원소가 모두 제거되고 capacity는 유지 됨.
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
