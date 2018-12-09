#pragma once
#include"Zoo.h"
#include"Cat.h"
#include"Elephant.h"
#include"Kangaroo.h"
#include"Bear.h"
#include"Giraffe.h"
#include"Monkey.h"
#include<iostream>
#include<conio.h>
#include<Windows.h>
#include<iomanip>
using namespace std;

class ZooConsole
{
public:
	Zoo z;
	ZooConsole();
	void start();
	void saveToFile()const;
	void loadFromFile();
	~ZooConsole();
private:
	void startMenu();
	void mainMenu();
	void addAnimalMenu();
	void removeAnimalMenu();
	void showInfo()const;

	void setZooNameMenu();
	void setCityNameMenu();
	void setAnimalInfoMenu();
	void showShortInfo() const;
	void showRollCall()const;
	void clearScreen()const { system("cls"); }
	void pause()const { system("pause"); }
	void editAnimalMenu(Animal* animal);
	void editAnimalInfo(Animal* animal);
	
};

