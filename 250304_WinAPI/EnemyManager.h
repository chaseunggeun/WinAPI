#pragma once
#include "config.h"
#include "Singleton.h"

class Enemy;

class EnemyManager : public Singleton<EnemyManager>
{
private:
	vector<Enemy*> vecEnemys;
public:
	void Init();
	void Release();
	void Update();
	void Render(HDC hdc);

	void AddEnemy(int size);
	EnemyManager();
	~EnemyManager();
};

