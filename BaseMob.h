#pragma once
#include <iostream>
#include <string>
#include <cstdio>	
#include <ctime>
#include <Windows.h>
using std::cout;
using std::cin;
using std::string;

class BaseMob
{
protected:
	string Name;
	int Health;
	int Damage;
	int DamageDecrease;

public:
	bool isBoss;
	bool HalfBoss;
	int firetick;
	int poisontick;
    BaseMob(int health,int damage,string name,int damagedecrease, bool isBos, bool halfboss)
	{
		Health = health;
		Damage = damage;
		Name = name;
		DamageDecrease = damagedecrease;
		isBoss = isBos;
		HalfBoss = halfboss;
	}
	void setHealth(int health) {
		Health = health;
	}
	int getHealth()
	{
		return Health;
	}
	void setDamage(int damage)
	{
		Damage = damage;
	}
	int getDamage()
	{
		return Damage;
	}
	void setName(string name) {
		Name = name;
	}
	string getName()
	{
		return Name;
	}
	void setDamageDecrease(int damagedecrease)
	{
		DamageDecrease = damagedecrease;
	}
	int getDamageDecrease()
	{
		return DamageDecrease;;
	}
	
};