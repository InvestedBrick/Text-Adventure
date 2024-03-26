#pragma once
#include <iostream>
#include <string>
#include <cstdio>	
#include <ctime>
#include <Windows.h>
#include "BaseMob.h"

class Boss : public BaseMob
{
private:
	
public:
	Boss(int health, int damage, string name, int damagedecrease) : BaseMob(health,damage,name,damagedecrease,isBoss,HalfBoss)
	{
		Health = health;
		Damage = damage;
		Name = name;
		DamageDecrease = damagedecrease;
	}
};
