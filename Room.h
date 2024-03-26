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
			cout << "Du befindest dich an einer Kreuzung. In alle Richtungen führt ein Weg.\n";

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
			cout << "Du befindest dich in einer Sackgasse, du kannst nur zurück nach hinten gehen.\n";
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
			cout << "Die Wände sind mit Moos und Schimmel bedeckt und der Boden ist mit herabgefallenen Steinen und Schutt übersät.\n";
		}
		if (randdesc == 1)
		{
			cout << "Deine Augen gewöhnen sich langsam an das schwache Licht und du siehst, dass du dich in einem großen, verfallenen Saal befindest.\n";
		}
		if (randdesc == 2)
		{
			cout << "Du betrittst eine riesige Halle, die von Säulen und Statuen aus Stein umgeben ist.\n";
		}
		if (randdesc == 3)
		{
			cout << "Der Raum ist voller Spinnweben und du siehst einen riesigen, von Schatten verhüllten Thron in der Ecke..\n";
		}
		if (randdesc == 4)
		{
			cout << "Ein kalter Luftzug schlägt dir entgegen, als du den Raum betrittst. Du siehst, dass sich die Wände mit Eis überzogen haben und der Boden unter deinen Füßen glatt und rutschig ist.\n";
		}
		if (randdesc == 5)
		{
			cout << "Du betrittst einen düsteren, feuchten Raum. Die Wände sind aus rauem Stein gemauert und es riecht nach Moder und Schimmel.\n";
		}
		if (randdesc == 6)
		{
			cout << "Du betrittst einen weitläufigen Raum, dessen Decke von hohen, gewölbten Bögen gestützt wird. Der Boden ist aus glänzendem, poliertem Marmor und es gibt Dutzende von Statuen und Kunstwerken, die das gesamte Zimmer schmücken.\n";
		}
		if (randdesc == 7)
		{
			cout << "Der Raum, den du betrittst, ist klein und eng. Die Luft ist stickig und es riecht nach Schimmel und Feuchtigkeit. Die Wände sind schmutzig und es gibt keinerlei Fenster, um Licht hereinkommen zu lassen.\n";
		}
		if (randdesc == 8)
		{
			cout << "Der Raum ist von zersplittertem Marmor und zerbrochenen Statuen übersät.\n";
		}
		if (randdesc == 9)
		{
			cout << "Der Raum ist von grünen Pflanzen und Blumen überwuchert. Du siehst einen Springbrunnen in der Mitte des Raumes.\n";
		}

		system("pause");
	}
};
