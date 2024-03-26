#pragma once
#include <iostream>
#include <string>
#include <cstdio>	
#include <ctime>
#include <Windows.h>

class Room
{
private:
	bool right;
	bool left;
	bool front;
	bool back;

public:
	bool getRight()
	{
		return right;
	}
	bool getleft()
	{
		return left;
	}
	bool getFront()
	{
		return front;
	}
	bool getBack()
	{
		return back;
	}
	void setLeft(string i)
	{
		if (i == "0")
		{
			left = false;
		}
		if (i == "1")
		{
			left = true;
		}
	}
	void setRight(string i)
	{
		if (i == "0")
		{
			right = false;
		}
		if (i == "1")
		{
			right = true;
		}
	}
	void setFront(string i)
	{
		if (i == "0")
		{
			front = false;
		}
		if (i == "1")
		{
			front = true;
		}
	}
	void setBack(string i)
	{
		if (i == "0")
		{
			back = false;
		}
		if (i == "1")
		{
			back = true;
		}
	}
	
	void newRoom()
	{
		system("cls");
		
		int randomexitright = rand() % 2;
		int randomexitleft = rand() % 2;
		int randomexitfront = rand() % 2;
		int randomexitback = rand() % 2;

		if (randomexitright == 1) {
			right = true;
		}
		if (randomexitright == 0) {
			right = false;
		}
		if (randomexitleft == 1) {
			left = true;
		}
		if (randomexitleft == 0) {
			left = false;
		}
		if (randomexitfront == 1) {
			front = true;
		}
		if (randomexitfront == 0) {
			front = false;
		}
		if (randomexitback == 1) {
			back = true;
		}
		if (randomexitback == 0) {
			back = false;
		}


		if (right == true && left == true && front == true && back == true)
		{
			cout << "Du befindest dich an einer Kreuzung. In alle Richtungen f�hrt ein Weg.\n";

		}
		if (right == true && left == true && front == false && back == true)
		{
			cout << "Du befindest dich an einer Weggabelung. Du kannst nach hinten, nach rechts oder nach links gehen.\n";
		}
		if (right == true && left == true && front == true && back == false)
		{
			cout << "Hinter die bricht die Wand ein...\nDu befindest dich an einer Weggabelung. Du kannst nach vorne, nach rechts oder nach links gehen.\n";
		}
		if (right == true && left == true && front == false && back == false)
		{
			cout << "Hinter die bricht die Wand ein...\nDu befindest dich in einem Gang. Du kannst nach rechts oder nach links gehen.\n";
		}
		if (right == true && left == false && front == true && back == false)
		{
			cout << "Hinter die bricht die Wand ein...\nDu befindest dich an einer Abzweigung. Du kannst nach rechts oder nach vorne gehen.\n";
		}
		if (right == false && left == true && front == true && back == false)
		{
			cout << "Hinter die bricht die Wand ein...\nDu befindest dich an einer Abzweigung. Du kannst nach links oder nach vorne gehen.\n";
		}

		if (right == false && left == false && front == false && back == true)
		{
			cout << "Du befindest dich in einer Sackgasse, du kannst nur zur�ck nach hinten gehen.\n";
		}
		if (right == false && left == false && front == true && back == false)
		{
			cout << "Hinter die bricht die Wand ein...\nDu befindest dich in einer Sackgasse, du kannst nur nach vorne gehen.\n";
		}
		if (right == false && left == true && front == false && back == false)
		{
			cout << "Hinter die bricht die Wand ein...\nDu befindest dich in einer Sackgasse, du kannst nur  nach links gehen.\n";
		}
		if (right == true && left == false && front == false && back == false)
		{
			cout << "Hinter die bricht die Wand ein...\nDu befindest dich in einer Sackgasse, du kannst nur  nach rechts gehen.\n";
		}

		if (right == true && left == false && front == false && back == true)
		{
			cout << "Du befindest dich an einer Abzweigung. Du kannst nach rechts oder nach hinten gehen.\n";
		}
		if (right == false && left == false && front == true && back == true)
		{
			cout << "Du befindest dich in einem Gang. Du kannst nach vorne oder nach hinten gehen.\n";
		}

		if (right == false && left == false && front == false && back == false)
		{
			front = true;
			cout << "Hinter die bricht die Wand ein...\nDu steckst in einer Sackgasse und kannst nur nach vorne gehen\n";
		}

		if (right == false && left == true && front == true && back == true)
		{
			cout << "Du befindest dich an einer Weggabelung. Du kannst nach links, nach vorne oder nach hinten gehen\n";
		}
		if (right == false && left == true && front == false && back == true)
		{
			cout << "Du befindest dich an einer Weggabelung. Du kannst nach hinten oder nach links gehen.\n";
		}
		
		

		int randdesc = rand() % 10;
		if (randdesc == 0)
		{
			cout << "Die W�nde sind mit Moos und Schimmel bedeckt und der Boden ist mit herabgefallenen Steinen und Schutt �bers�t.\n";
		}
		if (randdesc == 1)
		{
			cout << "Deine Augen gew�hnen sich langsam an das schwache Licht und du siehst, dass du dich in einem gro�en, verfallenen Saal befindest.\n";
		}
		if (randdesc == 2)
		{
			cout << "Du betrittst eine riesige Halle, die von S�ulen und Statuen aus Stein umgeben ist.\n";
		}
		if (randdesc == 3)
		{
			cout << "Der Raum ist voller Spinnweben und du siehst einen riesigen, von Schatten verh�llten Thron in der Ecke..\n";
		}
		if (randdesc == 4)
		{
			cout << "Ein kalter Luftzug schl�gt dir entgegen, als du den Raum betrittst. Du siehst, dass sich die W�nde mit Eis �berzogen haben und der Boden unter deinen F��en glatt und rutschig ist.\n";
		}
		if (randdesc == 5)
		{
			cout << "Du betrittst einen d�steren, feuchten Raum. Die W�nde sind aus rauem Stein gemauert und es riecht nach Moder und Schimmel.\n";
		}
		if (randdesc == 6)
		{
			cout << "Du betrittst einen weitl�ufigen Raum, dessen Decke von hohen, gew�lbten B�gen gest�tzt wird. Der Boden ist aus gl�nzendem, poliertem Marmor und es gibt Dutzende von Statuen und Kunstwerken, die das gesamte Zimmer schm�cken.\n";
		}
		if (randdesc == 7)
		{
			cout << "Der Raum, den du betrittst, ist klein und eng. Die Luft ist stickig und es riecht nach Schimmel und Feuchtigkeit. Die W�nde sind schmutzig und es gibt keinerlei Fenster, um Licht hereinkommen zu lassen.\n";
		}
		if (randdesc == 8)
		{
			cout << "Der Raum ist von zersplittertem Marmor und zerbrochenen Statuen �bers�t.\n";
		}
		if (randdesc == 9)
		{
			cout << "Der Raum ist von gr�nen Pflanzen und Blumen �berwuchert. Du siehst einen Springbrunnen in der Mitte des Raumes.\n";
		}

		system("pause");
	}
};
