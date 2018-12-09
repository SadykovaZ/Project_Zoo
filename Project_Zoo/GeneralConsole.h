#pragma once
#include"ZooConsole.h"
#include"org/OrganizationConsole.h"

class GeneralConsole
{
public:
	ZooConsole z;
	OrganizationConsole o;
	GeneralConsole();
	void begin();
	~GeneralConsole();
	
	void saveToFile1()const;
	void saveToFile2()const;
	void save()const;

private:
	void startMenu();
};
