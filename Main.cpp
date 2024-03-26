#include <iostream>
#include <cstdio>	
#include <ctime>
#include <string>
#include <fstream>
#include "Player.h"
#include "BaseMob.h"
#include <locale>
#include <vector>
#include "Room.h"
#include "Boss.h"
#include <Windows.h>

std::fstream file;
std::fstream itemfile;
using std::cout;
using std::cin;
using std::string;
using std::vector;

int main();
string PlayerName;
Room room;
Player player = Player(100, 100, 5, 2, 0, 0, PlayerName);
BaseMob mob = BaseMob(0, 0, " ",0, false,false);

int EnergyCap = 100;
int HealthCap = 100;
int xpReq = 100;
void DisplayStats();
int energyIncrease = player.getDamageDecrease() / 2;

int roomexpl = 0;
bool showPassiveRegen = true;
bool showDodge = true;
void Game();
void fight();
Boss *pBoss = nullptr;
void spawnMob();
void NullMob();
void NullPlayer();
void buffMob()
{
	if (mob.getName() == "Skelett")
	{
		int intskelhpdec = mob.getHealth() - 10;
		int skeldaminc = mob.getDamage() + 15;

		mob.setHealth(intskelhpdec);
		mob.setDamage(skeldaminc);
	}
	if (mob.getName() == "Zombie")
	{
		int intszomhpdec = mob.getHealth() + 10;
		int zomdaminc = mob.getDamage() + 4;

		mob.setHealth(intszomhpdec);
		mob.setDamage(zomdaminc);
	}
	if (mob.getName() == "Geist")
	{
		mob.setHealth(10);
		mob.setDamageDecrease(mob.getDamageDecrease() + 20);
	}
	if (mob.getName() == "Assasine")
	{ 
		int t = player.getHealth() - mob.getDamage() + player.getDamageDecrease();
		if (t < 1)
		{
			t = 0;
		}
		player.setHealth(t);
		cout << "Ein Assasine greift dich aus dem dunkeln an\n";
	}
	if (mob.getName() == "Schleim")
	{
		mob.setHealth(mob.getHealth() - 15 - player.getlevel() * 3);
		mob.setDamage(mob.getDamage() - 7);
	}
	if (mob.getName() == "Riesenspinne")
	{
		player.poisontick = 3;
		mob.setHealth(mob.getHealth() + 20);
		mob.setDamageDecrease(mob.getDamageDecrease() - 4);
	}
	if (mob.getName() == "Gnolem")
	{
		mob.setHealth(mob.getHealth() + 20);
		mob.setDamage(mob.getDamage() - 10);
	}
	if (mob.getName() == "Riesenechse")
	{
		mob.setDamageDecrease(mob.getDamageDecrease() + 5);
		mob.setHealth(mob.getHealth() + 20);
		
	}
}
void save()
{
	file.open("Save.txt", std::ios::out);
	if (file.is_open())
	{
		file << player.getHealth() << "\n" << player.getDamage() << "\n" << player.getDamageDecrease() << "\n" << player.getEnergy() << "\n" << player.gethealthPotNum() << "\n"; //5
		file << player.getlevel() << "\n" << player.getXP() << "\n" << player.getName() << "\n" << player.getslates() << "\n";//9
		file << EnergyCap << "\n" << HealthCap << "\n" << xpReq << "\n" << player.slot[0] << "\n" << player.slot[1] << "\n" << player.slot[2] << "\n" << player.slot[3] << "\n" << player.slot[4] << "\n";//17
		file << room.getBack() << "\n" << room.getFront() << "\n" << room.getleft() << "\n" << room.getRight() << "\n";//21
		file << roomexpl << "\n" << player.getEnergyPotNum() << "\n" << player.getChestCount() << "\n" << player.getMobCount() << "\n" << player.getVaseCount() << "\n" << player.getLeverCount() << "\n";//27
		file << player.getSecretroomCount() << "\n" << player.getTrapCount() << "\n" << player.getEchsenShuppen() << "\n";//30
		file.close();
	}
	itemfile.open("Items.txt", std::ios::out);
	if (itemfile.is_open())
	{
		for (auto& thing : player.Items)
		{
			itemfile << thing << "\n";
		}
		itemfile.close();
	}
	


}
void load()
{
	system("cls");
	
	string line[30];
	file.open("Save.txt", std::ios::in);
	if (file.is_open())
	{
		
		for (int i = 0; i < 30; i++)
		{
			std::getline(file, line[i]);
		}
		player.setHealth(std::stoi(line[0])); player.setDamage(std::stoi(line[1])); player.setDamageDecrease(std::stoi(line[2])); player.setEnergy(std::stoi(line[3]));
		player.setHealthPotNum(std::stoi(line[4])); player.setlevel(std::stoi(line[5])); player.setXP(std::stoi(line[6])); player.setName(line[7]); player.setSlates(std::stoi(line[8]));
		EnergyCap = std::stoi(line[9]); HealthCap = std::stoi(line[10]); xpReq = std::stoi(line[11]); player.slot[0] = line[12]; player.slot[1] = line[13]; player.slot[2] = line[14];
		player.slot[3] = line[15];player.slot[4] = line[16];
		room.setBack(line[17]); room.setFront(line[18]); room.setLeft(line[19]); room.setRight(line[20]); roomexpl = std::stoi(line[21]); player.setEnergyPotNum(std::stoi(line[22]));
		player.setchestcount(std::stoi(line[23])); player.setMobCount(std::stoi(line[24])); player.setVaseCount(std::stoi(line[25])); player.setLevercount(std::stoi(line[26]));
		player.setSecretRoomCount(std::stoi(line[27])); player.setTrapCount(std::stoi(line[28])); player.setEchsenschuppen(std::stoi(line[29]));
		
		file.close();
	}
	itemfile.open("Items.txt", std::ios::in);
	if (itemfile.is_open())
	{
		string itemline[100];
		for (int i = 0; i < 100; i++)
		{
			std::getline(itemfile, itemline[i]);
			if (itemline[i] != " ")
			{
				player.Items.push_back(itemline[i]);
			}
		}
		itemfile.close();
	}
	cout << "Lade Daten...\n";
	Sleep(3000);
	cout << "Daten Laden erfolgreich...\n";
	system("pause");
	Game();
}
void Game();
void Credits()
{
	cout << "\n\nHerzlichen Gl�ckwunsch, du hast das Spiel durchgespielt\n\nCredits gehen an:\n\nDeveloper: Julian Brecht\n\nAlpha Tester: Connor aka The Frog\n\nBeta Tester: Justus aka Schleim\n\nC++ Tutorial Guide: Pilzschaf\n";
	cout << "Hier nochmal deine Spielstatistiken:\n";
	cout << "Du hast " << player.getMobCount() << " Monster get�tet\n";
	cout << "Du hast " << player.getChestCount() << " Kisten ge�ffnet\n";
	cout << "Du hast " << player.getLeverCount() << " Hebel bet�tigt\n";
	cout << "Du hast " << player.getSecretroomCount() << " Geheimr�ume gefunden\n";
	cout << "Du bist in " << player.getTrapCount() << " Fallen gelaufen\n";
	cout << "Du hast " << player.getVaseCount() << " Vasen zerschlagen\n";
	system("pause");
	
	ShellExecute(0, 0, L"https://www.youtube.com/watch?v=dQw4w9WgXcQ", 0, 0, SW_HIDE);
	main();

	
}
void boss1()
{
	cout << "Du befindest dich nun in einem leeren Raum. Nachdem sich der Staub verzogen hat, erkennst du, dass in der Mitte des Raumes jemand steht.\n";

	cout << "Du gehst auf die Person zu, doch pl�tzlich sieht sie dich an und greift dich an";
	mob.setHealth(pBoss->getHealth());
	mob.setDamage(pBoss->getDamage());
	mob.setDamageDecrease(pBoss->getDamageDecrease());
	mob.setName(pBoss->getName());
	mob.isBoss = true;
	mob.HalfBoss = false;
	fight();
	pBoss->setHealth(mob.getHealth());
	pBoss->setDamage(mob.getDamage());
	pBoss->setDamageDecrease(mob.getDamageDecrease());
	NullMob();

	cout << "Die Person tritt zur�ck und auf einmal erscheint ein Monster aus dem Boden\n";
	system("pause");
	spawnMob();
	buffMob();
	fight();
	
	cout << "Die Person hat die Ablenkung genutzt um etwas zu regenerieren...\n";
	system("pause");
	pBoss->setHealth(pBoss->getHealth() + 20);
	mob.setHealth(pBoss->getHealth());
	mob.setDamage(pBoss->getDamage());
	mob.setDamageDecrease(pBoss->getDamageDecrease());
	mob.setName(pBoss->getName());
	mob.isBoss = false;
	mob.HalfBoss = true;
	fight();

	pBoss->setHealth(mob.getHealth());
	pBoss->setDamage(mob.getDamage());
	pBoss->setDamageDecrease(mob.getDamageDecrease());
	NullMob();
	cout << "Die Person tritt erneut zur�ck und auf einmal erscheint ein Monster aus dem Boden\n";
	system("pause");
	spawnMob();
	buffMob();
	fight();
	
	cout << "Die Person hat die Ablenkung genutzt um etwas zu regenerieren...\n";
	system("pause");
	pBoss->setHealth(pBoss->getHealth() + 20);
	mob.setHealth(pBoss->getHealth());
	mob.setDamage(pBoss->getDamage());
	mob.setDamageDecrease(pBoss->getDamageDecrease());
	mob.setName(pBoss->getName());
	mob.isBoss = false;
	mob.HalfBoss = false;
	fight();
	pBoss->setHealth(mob.getHealth());
	pBoss->setDamage(mob.getDamage());
	pBoss->setDamageDecrease(mob.getDamageDecrease());
	NullMob();
	player.setXP(player.getXP() + 90);
	player.setSlates(0);
}
void boss2()
{
	cout << "Du befindest dich in einem Thronsaal, rechts und links stehen riesige Steinstatuen\n";
	cout << "Auf einmal bewegt sich eine Statue und greift dich an!\n";
	mob.setHealth(pBoss->getHealth());
	mob.setDamage(pBoss->getDamage());
	mob.setDamageDecrease(pBoss->getDamageDecrease());
	mob.setName(pBoss->getName());
	mob.isBoss = true;
	mob.HalfBoss = false;
	fight();
	pBoss->setHealth(mob.getHealth());
	pBoss->setDamage(mob.getDamage());
	pBoss->setDamageDecrease(mob.getDamageDecrease()); 
	cout << "Auf einmal brechen Steine aus der Decke und du wirst getroffen\nEs scheint als w�rden ein paar Steine zur Statur schweben und diese regenerieren\n";
	player.setHealth(player.getHealth() - 30);
	pBoss->setHealth(pBoss->getHealth() + 35);
	mob.setHealth(pBoss->getHealth());
	mob.setDamage(pBoss->getDamage());
	mob.setDamageDecrease(pBoss->getDamageDecrease());
	mob.setName(pBoss->getName());
	mob.isBoss = false;
	mob.HalfBoss = true;
	fight();
	pBoss->setHealth(mob.getHealth());
	pBoss->setDamage(mob.getDamage());
	pBoss->setDamageDecrease(mob.getDamageDecrease());
	cout << "Steine aus dem Boden fangen an zu schweben und bilden einen Kreis um die Statur und bilden einen Wall um diese\n";
	cout << "Auf einmal verfl�ssigt sich auch ein Teil des Bodens zu Lava und du f�ngst an zu brennen\n";
	player.firetick = 3;
	pBoss->setDamageDecrease(pBoss->getDamageDecrease() + 10);
	mob.setHealth(pBoss->getHealth());
	mob.setDamage(pBoss->getDamage());
	mob.setDamageDecrease(pBoss->getDamageDecrease());
	mob.setName(pBoss->getName());
	mob.isBoss = false;
	mob.HalfBoss = false;
	fight();
	pBoss->setHealth(mob.getHealth());
	pBoss->setDamage(mob.getDamage());
	pBoss->setDamageDecrease(mob.getDamageDecrease());
	NullMob();
	player.setXP(player.getXP() + 120);
	player.setSlates(0);
	Credits();
}

void bossfight()
{
	cout << "Als du das dritte Fragment aufnimmst, fangen die anderen beiden Fragmente an zu vibrieren und fangen auf einmal an zu schweben.\nDie Fragmente schweben nun im Kreis und drehen sich immer schneller\n";
	cout << "Es erleuchtet ein grelles Licht. Du siehst nichts, doch du h�rst, wie der Boden unter dir zusammenbricht.\n";
	system("pause");
	

	
	if (player.getlevel() < 9)
	{
		pBoss = new Boss(180 + player.getlevel() * 2, 35 + player.getlevel(), "Unbekannt", 10);
		boss1();
	}
	if (player.getlevel() >= 9)
	{
		pBoss = new Boss(300 + player.getlevel() * 5, 70 + player.getlevel() * 3, "Steinstatur", 20 + player.getlevel());
		boss2();
	}

	if (pBoss->getHealth() < 1 && player.getHealth() > 0)
	{
		
		system("cls");
		player.setSlates(0);
		system("pause");
		Game();
		
		delete pBoss;
	}

}

string loottable()
{
	int randloot = rand() % 9;
	string loot[9] = { "Eisenschwert", "Eisenhelm", "Eisenbrustplatte", "Eisenhose", "Eisenschuhe","Regenerationstrank", "Energietrank", "Dolch", "Axt"};
	return loot[randloot];


}

void NullMob()
{
	mob.setDamage(0);
	mob.setHealth(0);
	mob.setDamageDecrease(0);
	mob.setName("");
	mob.isBoss = false;
	mob.HalfBoss = false;
	mob.firetick = 0;
	mob.poisontick = 0;
}
void NullPlayer()
{
	player.setDamage(5);
	player.setHealth(100);
	player.setlevel(0);
	player.setXP(0);
	player.setDamageDecrease(2);
	player.setEnergy(100);
	player.setName(" ");
	EnergyCap = 100;
	HealthCap = 100;
	xpReq = 100;
	player.setHealthPotNum(0);
	player.setSlates(0);
	player.Items.clear();
	
	for (int i = 0; i < 5; i++)
	{
		player.slot[i] = "Leer";
	}
	player.firetick = 0;
	player.poisontick = 0;
	player.setchestcount(0);
	player.setMobCount(0);
	player.setLevercount(0);
	player.setSecretRoomCount(0);
	player.setTrapCount(0);
	player.setVaseCount(0);
}
void spawnMob()
{
	int damage = rand() % 5 + 10;
	damage = damage + player.getlevel() * 5;
	int dmgdec = rand() % 2 + 2;
	dmgdec = dmgdec + player.getlevel() * 2;
	int randhealth = rand() % 25 + 15;
	randhealth = randhealth + player.getlevel() * 9 + player.getDamage();
	const int names = 9;
	mob.isBoss = false;
	string randname[names];
	randname[0] = "Goblin";
	randname[1] = "Skelett";
	randname[2] = "Zombie";
	randname[3] = "Geist";
	randname[4] = "Assasine";
	randname[5] = "Schleim";
	randname[6] = "Riesenspinne";
	randname[7] = "Gnolem";
	randname[8] = "Riesenechse";

	int f = rand() % names;
	mob.setDamage(damage);
	mob.setDamageDecrease(dmgdec);
	mob.setHealth(randhealth);
	mob.setName(randname[f]);

	
}


void Level()
{
	if (player.getXP() >= xpReq)
	{
		player.setXP(player.getXP() - xpReq);
		player.setlevel(player.getlevel() + 1);
		xpReq = xpReq + 25;
		player.setDamage(player.getDamage() + 4);
		player.setDamageDecrease(player.getDamageDecrease() + 1);
		EnergyCap = EnergyCap + 10;
		HealthCap = HealthCap + 15;
		cout << "\nDu hast Level " << player.getlevel() << " erreicht\n";
		if (player.getlevel() == 3 && showPassiveRegen == true)
		{	
			cout << "Du hast passive Regeneration in K�mpfen freigeschaltet\n";
			showPassiveRegen = false;
		}
		if (player.getlevel() == 6 && showDodge == true)
		{
			cout << "Du hast jetzt eine Chance Atacken auszuweichen\n";
			showDodge = false;
		}
		system("pause");
	}
}
void fight()
{
	int Bosstest = 0;
	int isHalfBoss = 0;
	if (mob.isBoss == true)
	{
		Bosstest = 100;
	}
	if (mob.HalfBoss == true)
	{
		isHalfBoss = 50;
	}
	while (mob.getHealth() > Bosstest + isHalfBoss && player.getHealth() > 0) {
		
		
		if (player.firetick > 0)
		{
			player.setHealth(player.getHealth() - 8);
			player.firetick--;
		}
		if (mob.firetick > 0){
			mob.setHealth(mob.getHealth() - 8);
		    mob.firetick--;
		}
		if (player.poisontick > 0)
		{
			player.setHealth(player.getHealth() - 5);
			player.poisontick--;
		}
		if (mob.poisontick > 0)
		{
			mob.setHealth(mob.getHealth() - 5);
			mob.poisontick--;
		}
		DisplayStats();
		if (player.firetick > 0)
		{
			cout << "Du brennts...\n";
		}
		if (mob.firetick > 0)
		{
			cout << mob.getName() << " brennt";
		}
		if (player.poisontick > 0)
		{
			cout << "Du bist vergiftet...\n";
		}
		if (mob.poisontick > 0)
		{
			cout << mob.getName() << " ist vergiftet";
		}
		string action;
		cin.clear(); cin.ignore(cin.rdbuf()->in_avail());
		cout << "\nWas willst du tun?\n'a'um anzugreifen\n'b'um zu blocken\n's'um den Schaden zu nehmen(tu dies nur wenn du keine Energie mehr hast)\n't'um dein Tr�nkeinventar zu �ffnen\n'i'um dein inventar zu �ffnen\n>";
		cin >> action;
		if (action == "i")
		{
			player.OpenInv();
		}
		if (action == "t")
		{
			player.potinv(HealthCap,EnergyCap);
		}
		if (action == "a") {
			if (player.getlevel() >= 3 && player.getHealth() <= HealthCap - 5 - player.getlevel() * 2) {
				player.setHealth(player.getHealth() + 5 + player.getlevel() * 2);
			}
			int randnum = rand() % 11;
			if (randnum == 0 && player.getEnergy() >= 12 + energyIncrease) {
				 int x1 = player.getDamage() * 2 - mob.getDamageDecrease();
				if (x1 < 1)
				{
					x1 = 0;
				}

				cout << "Kritischer Treffer! Du machst " << x1 << " Schaden\n";
				int x = x1;
				if (x < 1)
				{
					x = 0;
				}
				mob.setHealth(mob.getHealth() - x);
				int Energy1 = player.getEnergy() - 12 - energyIncrease;
				player.setEnergy(Energy1);
				system("pause");
			}
			if (randnum == 1 || randnum == 2 || randnum == 3 && player.getEnergy() >= 10 + energyIncrease) {
				 int y1 = player.getDamage() + 4 - mob.getDamageDecrease();
				if (y1 < 1)
				{
					y1 = 0;
				}
				cout << "Du triffst " << mob.getName() << " am Kopf und machst " << y1 << " Schaden\n";
				int y = y1;
				if (y < 1)
				{
					y = 0;
				}
				
				mob.setHealth(mob.getHealth() - y);
				int Energy2 = player.getEnergy() - 10 - energyIncrease;
				player.setEnergy(Energy2);
				system("pause");
			}
			if (randnum == 4 && player.getEnergy() >= 8 + energyIncrease) {
				 int z1 = player.getDamage() - mob.getDamageDecrease();
				if (z1 < 1)
				{
					z1 = 0;
				}
				cout << "Du triffst "<<  mob.getName() << " sauber am rechten Bein und machst " << z1 << " Schaden\n";
				int z = z1;
				if (z < 1)
				{
					z = 0;
				}
				mob.setHealth(mob.getHealth() - z);
				int Energy3 = player.getEnergy() - 8 - energyIncrease;
				player.setEnergy(Energy3);
				system("pause");
			}
			if (randnum == 5 && player.getEnergy() >= 8 + energyIncrease) {
				 int a1 = player.getDamage() - mob.getDamageDecrease();
				if (a1 < 1)
				{
					a1 = 0;
				}
				cout << "Du triffst " << mob.getName() << " sauber am rechten Arm und machst " << a1 << " Schaden\n";
				int a = a1;
				if (a < 1)
				{
					a = 0;
				}
				mob.setHealth(mob.getHealth() - a);
				int Energy4 = player.getEnergy() - 8 - energyIncrease;
				player.setEnergy(Energy4);
				system("pause");
			}
			if (randnum == 6 && player.getEnergy() >= 8 + energyIncrease){
				 int b1 = player.getDamage() - mob.getDamageDecrease();
				if (b1 < 1)
				{
					b1 = 0;
				}
				cout << "Du triffst " << mob.getName() << " sauber am linken Fuss und machst " << b1 << " Schaden\n";
				int b = b1;
				if (b < 1)
				{
					b = 0;
				}
				mob.setHealth(mob.getHealth() - b);
				int Energy5 = player.getEnergy() - 8 - energyIncrease;
				player.setEnergy(Energy5);
				system("pause");
			}
			if (randnum == 7 || randnum == 8 || randnum == 9 && player.getEnergy() >= 6 + energyIncrease)
			{
				int c1 = player.getDamage() - 3 - mob.getDamageDecrease();
				if (c1 < 1)
				{
					c1 = 0;
				}
				cout << "Dein Arm wackelt etwas beim zuschlagen, aber du triffst " << mob.getName() << " und machst " <<c1 << " Schaden\n";
				unsigned int c = c1;
				if (c < 1)
				{
					c = 0;
				}
				mob.setHealth(mob.getHealth() - c);
				int Energy6 = player.getEnergy() - 6 - energyIncrease;
				player.setEnergy(Energy6);
				system("pause");
			}
			if (randnum == 10 && player.getEnergy() >= 4 + energyIncrease)
			{
				int d1 = player.getDamage() - 5 - mob.getDamageDecrease();
				if (d1 < 1)
				{
					d1 = 0;
				}
				cout << "Du streifst " << mob.getName() << " und machst leider nur " << d1 << " Schaden\n";
				int d = d1;
				if (d < 1)
				{
					d = 0;
				}
				mob.setHealth(mob.getHealth() - d);
				int Energy7 = player.getEnergy() - 4 - energyIncrease;
				player.setEnergy(Energy7);
				system("pause");
			}
			int dodge = rand() % 7;
			
			if (dodge == 5 && player.getlevel() >= 6)
			{
				cout << "Du weichst der Atacke des " << mob.getName() << " aus\n";
				system("pause");
				continue;
			}

				if (mob.getHealth() > 0) {
					int randnum1 = rand() % 10;
					if (randnum1 == 0 || randnum1 == 1)
					{
						int e1 = mob.getDamage() * 2 - player.getDamageDecrease();
						if (e1 < 1)
						{
							e1 = 0;
						}
						cout << mob.getName() << " trifft stark und macht " << e1 << " Schaden\n";
						int e = e1;
						if (e < 1)
						{
							e = 0;
						}
						player.setHealth(player.getHealth() - e);
						system("pause");
					}
					if (randnum1 == 2 || randnum1 == 3 || randnum1 == 4 || randnum1 == 5)
					{
						int f1 = mob.getDamage() + 2 - player.getDamageDecrease();
						if (f1 < 1)
						{
							f1 = 0;
						}
						cout << mob.getName() << " trifft dich und macht " << f1 << " Schaden\n";
						int f = f1;
						if (f < 1)
						{
							f = 0;
						}
						player.setHealth(player.getHealth() - f);
						system("pause");
					}
					if (randnum1 == 6 || randnum1 == 7)
					{
						int g1 = mob.getDamage() - 1 - player.getDamageDecrease();
						if (g1 < 1)
						{
							g1 = 0;
						}
						cout << mob.getName() << " trifft einen schwachen Schlag und macht " << g1 << " Schaden\n";
						int g = g1;
						if (g < 1)
						{
							g = 0;
						}
						player.setHealth(player.getHealth() - g);
						system("pause");
					}
					if (randnum1 == 8 || randnum1 == 9)
					{
						int h1 = mob.getDamage() - 4 - player.getDamageDecrease();
						if (h1 < 1)
						{
							h1 = 0;
						}
						cout << mob.getName() << " streift dich und macht " << h1 << " Schaden\n";
						int h = h1;
						if (h < 1)
						{
							h = 0;
						}
						player.setHealth(player.getHealth() - h);
						system("pause");
					}

				
			    }
			
		}
		if (action == "b") {
			if (player.getlevel() >= 3 && player.getHealth() <= HealthCap - 5 - player.getlevel() * 2) {
				player.setHealth(player.getHealth() + 5 + player.getlevel() * 2);
			}

			int randnum2 = rand() % 3;
			if (randnum2 == 0 && player.getEnergy() >= 4 + energyIncrease ) {
				cout << "Du blockst den Angriff des " << mob.getName() << " problemlos und f�gst ihm " << player.getDamage() - 3 << " Schaden zu\n";
				int damageblock = mob.getHealth() - player.getDamage() + 3;
				mob.setHealth(damageblock);
				int Energyb1 = player.getEnergy() - 4 - energyIncrease;
				player.setEnergy(Energyb1);
				system("pause");
			}
			if (randnum2 == 1 && player.getEnergy() >= 3 + energyIncrease)
			{
				int i1 = mob.getDamage() - 5 - player.getDamageDecrease();
				if (i1 < 1)
				{
					i1 = 0;
				}
				cout << "Du verringerst die Einschlagswucht und erh�ltst nur " << i1 << " Schaden\n";
				int i = i1;
				if (i < 1)
				{
					i = 0;
				}
				player.setHealth(player.getHealth() - i);
				int Energyb2 = player.getEnergy() - 3 - energyIncrease;
				player.setEnergy(Energyb2);
				system("pause");
			}
			if (randnum2 == 2 && player.getEnergy() >= 2 + energyIncrease)
			{
				int j1 = mob.getDamage() - 8 - player.getDamageDecrease();
				if (j1 < 1)
				{
					j1 = 0;
				}
				
				cout << "Dein Block war nicht ganz erfolgreich und du erh�ltst  " << j1 << " Schaden\n";
				int j = j1;
				if (j < 1)
				{
					j = 0;
				}
				player.setHealth(player.getHealth() - j);
				int Energyb3 = player.getEnergy() - 2 - energyIncrease;
				player.setEnergy(Energyb3);
				system("pause");
			}
		}
		if (action == "s")
		{
			if (player.getlevel() >= 3 && player.getHealth() < HealthCap - 5 - player.getlevel() * 2) {
				player.setHealth(player.getHealth() + 5 + player.getlevel() * 2);
			}
			cout << "Du beschliesst etwas Ausdauer zu regenerieren und daf�r aber den Schaden zu akzeptieren\n";
			system("pause");
			int l = player.getHealth() - mob.getDamage() + player.getDamageDecrease();
			player.setHealth(l);
			for (int i = 0; i < 10;i ++) {
				if (player.getEnergy() < 100) {
					int Energyl = player.getEnergy() + 1;
					player.setEnergy(Energyl);
				}
			}
		}
	}
	if (mob.getHealth() < 1)
	{
		cout << "Du hast " << mob.getName() << " besiegt\n";
		if (mob.getName() == "Riesenechse")
		{
			player.setEchsenschuppen(player.getEchsenShuppen() + 1);
			cout << "Die Echse hat eine Schuppe fallen gelassen...\n";
			
		}
		int r = rand() % 5;
		if (r == 4)
		{
			cout << mob.getName() << " hat einen Regenerationstrank fallen gelassen\n";
			player.setHealthPotNum(player.gethealthPotNum() + 1);
		}
		NullMob();
		int randxp = rand() % 50 + 15;
		player.setXP(player.getXP() + randxp);
		system("pause");
		player.firetick = 0;
		player.poisontick = 0;
		player.setMobCount(player.getMobCount() + 1);
	}
	if (player.getHealth() < 1)
	{
		cout << "Du bist gestorben!\n";
		NullMob();
		NullPlayer();
		
		main();
	}
	Level();
}
void DisplayStats()
{
	int playerEnergy = player.getEnergy(); int playerHealth = player.getHealth(); int playerDamage = player.getDamage(); int playerDamageDecrease = player.getDamageDecrease();
	int playerLevel = player.getlevel(); int playerXP = player.getXP(); string PlayerName = player.getName();
	int baseMobHealth = mob.getHealth(); int baseMobDamage = mob.getDamage(); string baseMobName = mob.getName();
	int baseMobDamageDecrease = mob.getDamageDecrease();
	
	system("cls");
	cout << "|Name: " << PlayerName << "                                        |Gegner - " << baseMobName << "\n";
	cout << "|Energie - " << playerEnergy << "       |Lebenspunkte - " << playerHealth << "              |Lebenspunkte - " << baseMobHealth << "\n";
	cout << "|Schaden - " << playerDamage << "        |Schadensveringerung - " << playerDamageDecrease << "         |Schaden - " << baseMobDamage << "\n";
	cout << "|Level - " << playerLevel << "           |XP - " << playerXP << "                          |Schadensveringerung - " << baseMobDamageDecrease << "\n";
	cout << "------------------------------------------------------------------------------------------------------------------------\n";
}
void chest()
{

	string chestopen;
	cout << "Du hast eine Kiste gefunden! Willst du sie aufmachen?(j/n)\n>";
	cin.clear(); cin.ignore(cin.rdbuf()->in_avail());
	cin >> chestopen;
	if (chestopen == "n") {
		cout << "Du l�sst die Kiste einfach stehen...\n";
		system("pause");
	}
	if (chestopen == "j")
	{
		int randchestmob = rand() % 5;
		if (randchestmob < 4)
		{


			string takeloot;
			string loot = loottable();
			cout << "Du machst die Kiste auf und findest " << loot << "\nNimmst du " << loot << " auf?(j/n)\n>";
			cin.clear(); cin.ignore(cin.rdbuf()->in_avail());
			cin >> takeloot;
			if (takeloot == "n")
			{
				cout << "Du nimmst " << loot << " nicht auf.\n";
				system("pause");
				loot = " ";
			}
			if (takeloot == "j") {
				cout << "Du nimmst " << loot << " auf.\n";
				int xp1 = rand() % 30 + 10;
				player.setXP(player.getXP() + xp1);
				if (loot != "Regenerationstrank" && loot != "Energietrank")
				{
					player.Pass = player.Items.begin();
					player.Items.insert(player.Pass, loot);
				}
				if (loot == "Regenerationstrank")
				{
					player.setHealthPotNum(player.gethealthPotNum() + 2);
				}
				if (loot == "Energietrank")
				{
					player.setEnergyPotNum(player.getEnergyPotNum() + 2);
				}
				player.setchestcount(player.getChestCount() + 1);
				system("pause");
				loot = " ";
			}
		}
		if (randchestmob == 4)
		{
			cout << "Es stellt sich heraus, dass die Kiste ein Monster ist\n";
			system("pause");
			mob.setName("LebendeKiste");
			mob.setHealth(45);
			mob.setDamage(15);
			mob.setDamageDecrease(5);
			fight();
			randchestmob = 1;
		}
	}
}
void SecretRoom(string entrance)
{
	player.setSecretRoomCount(player.getSecretroomCount() + 1);
	int secretroom = rand() % 2;
	cout << "Du gelangst durch die " << entrance << " in einen geheimen Raum...\n";
	system("pause");
	if (secretroom == 0)
	{
		spawnMob();
		mob.setName("Assasine");
		buffMob();
		fight();
	}
		

	

	if (secretroom == 1)
	{
		chest();
		chest();
	}
}

void Game()
{ 
	while (true)
	{


		if (player.getslates() == 3)
		{
			bossfight();
		}
		if (player.getHealth() < 1)
		{
			cout << "Du bist gestorben!\n";
			NullMob();
			NullPlayer();

			main();
		}
		DisplayStats();

		cout << "\nWas willst du nun tun?\n'p'um ein Pause zu machen und deine Energie und Lebenspunkte zu regenerieren\n'e'um den Raum weiter zu erkunden\n'i'um dein Inventar zu �ffnen\n's'um zu speichern\n'n'um Spielstatistiken zu laden\n\n";
		if (room.getRight() == true) { cout << "'r'um nach rechts abzubiegen\n"; }
		if (room.getleft() == true) { cout << "'l'um nach links abzubiegen\n"; }
		if (room.getFront() == true) { cout << "'v'um nach vorne zu gehen\n"; }
		if (room.getBack() == true) { cout << "'h'um nach hinten zu gehen\n"; }
		cout << ">";
		cin.clear(); cin.ignore(cin.rdbuf()->in_avail());
		string expl;
		cin >> expl;
		if (expl == "n")
		{
			cout << "Du hast " << player.getMobCount() << " Monster get�tet\n";
			cout << "Du hast " << player.getChestCount() << " Kisten ge�ffnet\n";
			cout << "Du hast " << player.getLeverCount() << " Hebel bet�tigt\n";
			cout << "Du hast " << player.getSecretroomCount() << " Geheimr�ume gefunden\n";
			cout << "Du bist in " << player.getTrapCount() << " Fallen gelaufen\n";
			cout << "Du hast " << player.getVaseCount() << " Vasen zerschlagen\n";
			system("pause");
		}
		if (expl == "p") {
			player.waitandregen(HealthCap, EnergyCap);
		}
		if (expl == "r" && room.getRight() == true) { cout << "Du biegst nach rechts ab...\nDu betrittst einen neuen Raum\n"; system("pause"); room.newRoom(); roomexpl = 0; }
		if (expl == "l" && room.getleft() == true) { cout << "Du biegst nach links ab...\nDu betrittst einen neuen Raum\n"; system("pause"); room.newRoom(); roomexpl = 0; }
		if (expl == "v" && room.getFront() == true) { cout << "Du gehst nach vorne...\nDu betrittst einen neuen Raum\n"; system("pause"); room.newRoom(); roomexpl = 0; }
		if (expl == "h" && room.getBack() == true) { cout << "Du gehst nach hinten...\nDu betrittst einen neuen Raum\n"; system("pause"); room.newRoom(); roomexpl = 0; }
		if (expl == "s")
		{
			save();
			cout << "Speichere Daten...\n";
			Sleep(3000);
		}
		if (expl == "i")
		{
			player.OpenInv();
		}
		if (expl == "e")
		{

			roomexpl++;
			if (roomexpl <= 3)
			{
				int randomeventforroom = rand() % 20;
				if (randomeventforroom < 3) {

					spawnMob();
					buffMob();
					cout << "Du findest ein(en) " << mob.getName() << " und er/es greift dich an!\n";
					system("pause");
					fight();
				}
				if (randomeventforroom == 3)
				{
					cin.clear(); cin.ignore(cin.rdbuf()->in_avail());
					string trapdooryn;
					cout << "Du findest eine alte, verstaubte Fallt�r. �ffnest du sie?(j/n)\n>";
					cin >> trapdooryn;
					if (trapdooryn == "n") {
						cout << "\nDu �ffnest sie nicht\n";
						system("pause");

					}
					if (trapdooryn == "j")
					{
						SecretRoom("Fallt�r");
					}
				}
				if (randomeventforroom == 4)
				{
					cout << "Du findest einen Regenerationstrank in einer Ecke\n";
					player.setHealthPotNum(player.gethealthPotNum() + 1);
					system("pause");
				}
				if (randomeventforroom == 5 || randomeventforroom == 6)
				{
					string mobrun;
					cout << "Auf einmal siehst du wie ein Monster auf dich zukommt. Greifst du es and oder rennst du weg?(a/r)\n>";
					cin.clear(); cin.ignore(cin.rdbuf()->in_avail());
					cin >> mobrun;
					if (mobrun == "a")
					{
						cout << "Du greifst es an!\n";
						spawnMob();
						buffMob();
						system("pause");
						fight();
					}
					if (mobrun == "r")
					{
						int randrun = rand() % 3;
						cout << "Du rennst weg!\n";
						if (randrun == 1)
						{
							cout << "Du entkommst schnell genug und bist in Sicherheit\n";
							system("pause");
						}
						if (randrun == 2)
						{
							cout << "Du entkommst zwar, jedoch stolperst du beim rennen und f�llst auf den Kopf\n";
							player.setHealth(player.getHealth() - 25);
							system("pause");
						}
						if (randrun == 0)
						{
							cout << "Du entkommst zwar, jedoch achtest du nicht darauf wohin du rennst und stolperst in ein neues Monster hinein!\n";
							spawnMob();
							buffMob();
							system("pause");
							fight();

						}

					}
				}
				if (randomeventforroom == 7 || randomeventforroom == 8)
				{
					chest();
				}
				if (randomeventforroom == 9 || randomeventforroom == 10)
				{
					cout << "Du bist in eine Falle gelaufen...\n";
					player.setHealth(player.getHealth() - 40);
					player.setTrapCount(player.getTrapCount() + 1);
					system("pause");
				}
				if (randomeventforroom == 11 || randomeventforroom == 12)
				{
					string hitVase;
					cout << "Du findest eine verstaubte Vase\nWillst du sie zerschlagen um zusehen, was in ihr ist?(j/n)\n>";
					cin >> hitVase;
					if (hitVase == "n")
					{
						cout << "Du zerbrichst die Vase nicht\n";
						system("pause");
					}
					if (hitVase == "j")
					{
						int randomeventforVase = rand() % 4;
						cout << "Du zerbrichst die Vase...\n";
						player.setVaseCount(player.getVaseCount() + 1);
						if (randomeventforVase == 0)
						{
							spawnMob();
							buffMob();
							cout << "Die Vase zerbricht mit einem lauten Klirren\nEs ist zwar nichts in der Vase drin, jedoch scheint es, als h�ttest du ein Monster angelockt\n";
							system("pause");
							fight();
						}
						if (randomeventforVase == 1)
						{
							cout << "Die Vase zerbricht, doch es ist nichts in ihr...\n";
							system("pause");
						}
						if (randomeventforVase == 2)
						{
							player.setHealthPotNum(player.gethealthPotNum() + 1);
							cout << "Du zerschl�gst die Vase und findest einen Regenerationstrank\n";

							system("pause");
						}
						if (randomeventforVase == 3)
						{
							player.setEnergyPotNum(player.getEnergyPotNum() + 1);
							cout << "Du zerschl�gst die Vase und findest einen Energietrank\n";
							system("pause");
						}

					}
				}
				if (randomeventforroom == 13 || randomeventforroom == 14)
				{
					char lever;
					cout << "Du findest einen Schalter, bet�tigst du ihn?(j/n)\n>";
					cin >> lever;
					if (lever == 'n')
					{
						cout << "Du bet�tigst den Schalter nicht...\n";
						system("pause");
					}
					if (lever == 'j')
					{
						player.setLevercount(player.getLeverCount() + 1);
						int leverevent = rand() % 2;
						cout << "Du bet�tigst den Schalter...\n";
						if (leverevent == 0)
						{
							int x = rand() % 50 + 20;
							cout << "Du h�rst wie sich ein Seil l�st. Du siehst nach oben und siehst, wie ein grosser Stein auf dich herabf�llt\n";
							cout << "Du versuchst auszuweichen, doch deine Beine werden schwer verletzt\n";
							player.setHealth(player.getHealth() - x);
							system("pause");
						}
						if (leverevent == 1)
						{
							string input;
							
							cout << "Vor dir �ffnet sich ein kleiner Gang in eine Kammer. In dieser Kammer befindet sich ein Fragment einer Scheibe, welches mit Runen versehen ist\nNimmst du sie auf(j/n)\n>";
							cin >> input;
							if (input == "j")
							{
								
								player.setSlates(player.getslates() + 1);
								cout << "Du hast jetzt " << player.getslates() << " Fragmente\n";
							}
							
							system("pause");
						}
						

					}
				}
				if (randomeventforroom > 14) {
					cout << "Du findest nichts\n";
					system("pause");
				}
			}
			if (roomexpl > 3)
			{
				cout << "Du findest nichts mehr in diesem Raum\n";
				system("pause");
			}
		}
	}
}

void startGame()
{
	system("cls");

	cout << "Wie ist dein Name?\n>";
	cin >> PlayerName;
	player.setName(PlayerName);
	system("cls");
	cout << "Du befindest dich in einer Art Dungeon, du weisst nicht wie du hierhergekommen bist oder wie du hier rauskommen sollst.\nDas Letzte and was du dich erinnern kannst ist, dass du auf der Suche nach etwas warst...\n";
	system("pause");
	system("cls");
	cout << "Du stehst auf und schaust dich um. Du siehst die W�nde des Raumes im leichten Fackelschein. Sie bestehen aus alten,    verrotteten Steinen und ein paar Holzbrettern...\n";
	system("pause");
	cout << "Auf dem Boden liegt ein Schwert aus Holz, sammelst du es auf(j/n)\n>";
	char swordjn = ' ';
	cin >> swordjn;

	if (swordjn == 'j') {
		player.Items.push_back("Holzschwert");
		player.UseItem("Holzschwert");
	}
	
	DisplayStats();
	system("pause");
	system("cls");
	cout << "\nAuf einmal kommt ein Wesen auf dich zu, es greift dich an!\n";
	mob.setDamage(8);
	mob.setHealth(45);
	mob.setName("Goblin");
	buffMob();
	system("pause");
	fight();
	
	room.newRoom();
	Game();
}

void Menu()
{
	while (true) 
	{
		
		cin.clear(); cin.ignore(cin.rdbuf()->in_avail());
		int choice = 0;
		cout << "\n    Text Adventure\n\n(1)Spielen\n(2)Hinweise\n(3)Spielstand laden\n(4)Beenden\n>";
		cin >> choice;
		if (choice == 1)startGame();
		else if (choice == 4)exit(0);
		else if (choice == 2)
		{
			system("cls");
			cout << "Hinweise:\n\n1. Dieses Spiel ist NICHT Idiotensicher und ich bitte hiermit zu verstehen, dass es bei unzuverl�ssiger Eingabe zu Fehlern kommen kann\n";
			cout << "2. Es kann zu Fehlern im Kampfsystem kommen, bei denen du oder der Gegner negativen Schaden machen.\n";
			system("pause");
		}
		else if (choice == 3)
		{
			load();
		}
		else {
			system("cls"); cout << "Eingabe falsch, neu versuchen\n";
		}
	}

}
int main()
{
	NullPlayer();
	srand(time(NULL));
	std::locale::global(std::locale("German_germany"));
	
	Menu();

	system("pause");
	return 0;
}