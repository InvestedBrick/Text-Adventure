#pragma once
#include <iostream>
#include <string>
#include <cstdio>	
#include <ctime>
#include <Windows.h>
#include <vector>
using std::cout;
using std::cin;
using std::string;
using std::vector;

class Player {
private:
	string Name;
	int Energy;
	int Health;
	int Damage;
	int DamageDecrease;
	int level;
	int XP;
	
	
	int healthpotnum;
	int slates;
	int energyPotNum;
	int chestcount;
	int mobcount;

	int Vasecount;
	int Levercount;
	int Secretroomcount;
	int trapcount;
	int Echsenschuppen;
public:
	int firetick;
	int poisontick;
	string slot[5];
	vector<string> Items;
	vector <string> ::iterator Pass;
	Player(int energy, int health, int damage, int damagedecrease, int lvl, int xp, string name) {
		Energy = energy;
		Health = health;
		Damage = damage;
		DamageDecrease = damagedecrease;
		level = lvl;
		XP = xp;
		Name = name;
	}
	string thing;
	
	void setEchsenschuppen(int echsens)
	{
		Echsenschuppen = echsens;
	}
	int getEchsenShuppen()
	{
		return Echsenschuppen;
	}
	void setTrapCount(int tcount)
	{
		trapcount = tcount;
	}
	int getTrapCount()
	{
		return trapcount;
	}
	void setVaseCount(int count)
	{
		Vasecount = count;
	}
	int getVaseCount()
	{
		return Vasecount;
	}
	void setLevercount(int countl)
	{
		Levercount = countl;
	}
	int getLeverCount()
	{
		return Levercount;
	}
	void setSecretRoomCount(int counts)
	{
		Secretroomcount = counts;
	}
	int getSecretroomCount()
	{
		return Secretroomcount;
	}
	void setchestcount(int count)
	{
		chestcount = count;
	}
	int getChestCount()
	{
		return chestcount;
	}
	void setMobCount(int countmob)
	{
		mobcount = countmob;
	}
	int getMobCount()
	{
		return mobcount;
	}
	void setName(string name)
	{
		Name = name;
	}
	string getName()
	{
		return Name;
	}
	void setEnergy(int energy) {
		Energy = energy;
	}
	int getEnergy()
	{
		return Energy;
	}
	void setHealth(int health) {
		Health = health;
	}
	int getHealth()
	{
		return Health;
	}
	void setDamage(int damage) {
		Damage = damage;
	}
	int getDamage()
	{
		return Damage;
	}
	void setDamageDecrease(int damagedecrease) {
		DamageDecrease = damagedecrease;
	}
	int getDamageDecrease() {
		return DamageDecrease;
	}
	void setlevel(int lvl) {
		level = lvl;
	}
	int getlevel() {
		return level;
	}
	void setXP(int xp) {
		XP = xp;
	}
	int getXP() {
		return XP;
	}
	void setHealthPotNum(int healthpotNum)
	{
		healthpotnum = healthpotNum;
	}
	int gethealthPotNum()
	{
		return healthpotnum;
	}
	void setSlates(int Slates)
	{
		slates = Slates;
	}
	int getslates()
	{
		return slates;
	}
	void setEnergyPotNum(int pots)
	{
		energyPotNum = pots;
	}
	int getEnergyPotNum()
	{
		return energyPotNum;
	}


	void UseItem(string inputitem)
	{
		if (slot[0] == "Leer" && inputitem == "Holzschwert")
		{
			slot[0] = "Holzschwert";
			Damage = Damage + 5;
		}
		else if (slot[0] == "Leer" && inputitem == "Eisenschwert")
		{
			slot[0] = "Eisenschwert";
			Damage = Damage + 9;
		}
		else if (slot[1] == "Leer" && inputitem == "Eisenhelm")
		{
			slot[1] = "Eisenhelm";
			DamageDecrease = DamageDecrease + 3;
		}
		else if (slot[2] == "Leer" && inputitem == "Eisenbrustplatte")
		{
			slot[2] = "Eisenbrustplatte";
			DamageDecrease = DamageDecrease + 5;
		}
		else if (slot[3] == "Leer" && inputitem == "Eisenhose")
		{
			slot[3] = "Eisenhose";
			DamageDecrease = DamageDecrease + 4;
		}
		else if (slot[4] == "Leer" && inputitem == "Eisenschuhe")
		{
			slot[4] = "Eisenschuhe";
			DamageDecrease = DamageDecrease + 2;
		}
		else if (slot[0] == "Leer" && inputitem == "Dolch")
		{
			slot[0] = "Dolch";
			Damage = Damage + 7;
		}
		else if (slot[0] == "Leer" && inputitem == "Axt")
		{
			slot[0] = "Axt";
			Damage = Damage + 10;
		}
		else if (slot[1] == "Leer" && inputitem == "Schuppenhelm")
		{
			slot[1] = "Schuppenhelm";
			DamageDecrease = DamageDecrease + 4;
		}
		else if (slot[2] == "Leer" && inputitem == "Schuppenbrustplatte")
		{
			slot[2] = "Schuppenbrustplatte";
			DamageDecrease = DamageDecrease + 6;
		}
		else if (slot[3] == "Leer" && inputitem == "Schuppenhose")
		{
			slot[3] = "Schuppenhose";
			DamageDecrease = DamageDecrease + 5;
		}
		else if (slot[4] == "Leer" && inputitem == "Schuppenschuhe")
		{
			slot[4] = "Schuppenschuhe";
			DamageDecrease = DamageDecrease + 3;
		}
		else cout << "\nSlot ist belegt\n";

	}
	void UnUseItem(string inputitem1)
	{
		if (inputitem1 == "Holzschwert")
		{
			slot[0] = "Leer";
			Damage = Damage - 5;
		}
		else if (inputitem1 == "Eisenschwert")
		{
			slot[0] = "Leer";
			Damage = Damage - 9;
		}
		else if (inputitem1 == "Eisenhelm")
		{
			slot[1] = "Leer";
			DamageDecrease = DamageDecrease - 3;
		}
		else if (inputitem1 == "Eisenbrustplatte")
		{
			slot[2] = "Leer";
			DamageDecrease = DamageDecrease - 5;
		}
		else if (inputitem1 == "Eisenhose")
		{
			slot[3] = "Leer";
			DamageDecrease = DamageDecrease - 4;
		}
		else if (inputitem1 == "Eisenschuhe")
		{
			slot[4] = "Leer";
			DamageDecrease = DamageDecrease - 2;
		}
		else if (inputitem1 == "Dolch")
		{
			slot[0] = "Leer";
			Damage = Damage - 7;
		}
		else if (inputitem1 == "Axt")
		{
			slot[0] = "Leer";
			Damage = Damage - 10;
		}
		else if (inputitem1 == "Schuppenhelm")
		{
			slot[1] = "Leer";
			DamageDecrease = DamageDecrease - 4;
		}
		else if (inputitem1 == "Schuppenbrustplatte")
		{
			slot[2] = "Leer";
			DamageDecrease = DamageDecrease - 6;
		}
		else if (inputitem1 == "Schuppenhose")
		{
			slot[3] = "Leer";
			DamageDecrease = DamageDecrease - 5;
		}
		else if (inputitem1 == "Schuppenschuhe")
		{
			slot[4] = "Leer";
			DamageDecrease = DamageDecrease - 3;
		}

	}
	
	void OpenInv()
	{

		while (true) {
			cin.clear(); cin.ignore(cin.rdbuf()->in_avail());
			string choice1;
			string Item;
			system("cls");
			cout << "Du besitzt folgende Items:\n";
			for (auto& thing : Items)
			{
				cout << thing << " ";
			}
			if (Echsenschuppen > 0)
			{
				cout << "\nDu hast " << Echsenschuppen << " Echsenschuppen\n\n";
			}
			cout << "\n\nDu benutzt gerade folgende Items:\n";
			cout << "Waffe: " << slot[0] << std::endl << "Helm: " << slot[1] << std::endl << "Brustplatte: "<<  slot[2] << std::endl << "Hose: " <<  slot[3] << std::endl << "Schuhe: " <<  slot[4] << std::endl;

			
			cout << "\nWas willst du tun?\n'b'um ein spezielles Item zu benutzen\n'a'um ein Item abzulegen\n'h'um Rüstung herzustellen\n'z'um zurück zu gehen\n>";
			cin >> choice1;
			if (choice1 == "h")
			{
				while (true) {
					system("cls");
					cout << "Du kannst folgendes herstellen:\n";
					if (Echsenschuppen >= 2)
					{
						cout << "Schuppenhelm(2)\n";
					}
					if (Echsenschuppen >= 4)
					{
						cout << "Schuppenbrustplatte(4)\n";
					}
					if (Echsenschuppen >= 3)
					{
						cout << "Schuppenhose(3)\n";
					}
					if (Echsenschuppen >= 1)
					{
						cout << "Schuppenschuhe(1)\n";
					}
					cout << "Was willst du herstellen?(oder 'z'um zurück zu gehen)\n>";
					string echsenInput;
					cin >> echsenInput;
					if (echsenInput == "Schuppenhelm" && Echsenschuppen >= 2)
					{
						Pass = Items.begin();
						Items.insert(Pass, "Schuppenhelm");
						Echsenschuppen = Echsenschuppen - 2;
					}
					if (echsenInput == "Schuppenbrustplatte" && Echsenschuppen >= 4)
					{
						Pass = Items.begin();
						Items.insert(Pass, "Schuppenbrustplatte");
						Echsenschuppen = Echsenschuppen - 4;
					}
					if (echsenInput == "Schuppenhose" && Echsenschuppen >= 3)
					{
						Pass = Items.begin();
						Items.insert(Pass, "Schuppenhose");
						Echsenschuppen = Echsenschuppen - 3;
					}
					if (echsenInput == "Schuppenschuhe" && Echsenschuppen >= 1)
					{
						Pass = Items.begin();
						Items.insert(Pass, "Schuppenschuhe");
						Echsenschuppen = Echsenschuppen - 1;
					}
					if (echsenInput == "z")
					{
						break;
					}
				}
			}
			if (choice1 == "z") { break; }
			if (choice1 == "b")
			{
				cout << "Welches Item?\n>";
				cin >> Item;
				for (auto& thing : Items)
				{
					if (thing == Item)
					{
						UseItem(Item);
					}
					
					
				}
			}
			if (choice1 == "a")
			{
				cout << "Welches Item?\n>";
				cin >> Item;
				for (int i = 0; i < 5; i++)
				{
					if (slot[i] == Item)
					{
						UnUseItem(Item);
					}
					
				}
				
			}
		}
	}
	
	void waitandregen(int Healthcap, int EnergyCap)
	{
		cout << "\nWarte und regeneriere...";
		Sleep(5000);
		for (int i = 0; i < 25; i++)
		{
			
			if (Health < Healthcap) { Health++; }
			if (Energy < EnergyCap) { Energy++; }
		}
		for (int i = 0; i < level * 4; i++)
		{
			if (Health < Healthcap) { Health++; }
			if (Energy < EnergyCap) { Energy++; }
		}
	}
	void potinv(int HealthCap,int EnergyCap)
	{
		string input;
		system("cls");
		cout << "           Trankinventar\n\nDu hast:\nRegenerationstränke - " << healthpotnum << "\nEnergietränke - " << energyPotNum << "\n";
		cout << "'r'um Regenerationstrank einzusetzen\n'e'um Energietrank zu benutzen\n'z'um zurück zu gehen\n>";
		cin >> input;
		if (input == "r") {
			if (healthpotnum >= 1) {
				cin.clear(); cin.ignore(cin.rdbuf()->in_avail());
				cout << "Du benutzt einen Regenerationstrank...\n";
				for (int i = 0; i < 35; i++)
				{
					if (Health < HealthCap) {
						Health++;
					}
				}
				healthpotnum--;
				system("pause");
			}
			if (healthpotnum < 1) {
				cout << "Du hat keine Regenerationstränke mehr...\n";
				system("pause");
			}
		}
		if (input == "e")
		{
			cin.clear(); cin.ignore(cin.rdbuf()->in_avail());
			if (energyPotNum >= 1)
			{
				cout << "Du benutzt einen Energietrank...\n";
				for (int i = 0; i < 30; i++)
				{
					if (Energy < EnergyCap)
					{
						Energy++;
					}
					energyPotNum--;
					
				}
				system("pause");
			}
			if (energyPotNum < 1)
			{
				cout << "Du hast keine Energietränke mehr\n";
				system("pause");
			}
		}

	}
};