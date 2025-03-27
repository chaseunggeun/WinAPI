#include <iostream>
#include "MissileFactory.h"

int main()
{
	MissileFactory* missileFactorys[3];
	missileFactorys[0] = new NormalMissileFactory();
	missileFactorys[1] = new SignMissileFactory();
	missileFactorys[2] = new LazerMissileFactory();

	for (int i = 0; i < 3; i++)
	{
		missileFactorys[i]->AddMissile();

	}

	for (int i = 0; i < 3; i++)
	{
		delete missileFactorys[i];
	}
}
