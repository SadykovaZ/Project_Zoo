#pragma once
#include "Animal.h"
class Cat :
	public Animal
{
	string breed;
	int cntLives;
public:
	Cat(string name, string color, int age, string breed, int cntLives);
	Cat() = default;
	void setBreed(string breed);
	void setCntLives(int cntLives);

	string getBreed() const { return breed; }
	int getCntLives() const { return cntLives; }

	void getInfo()const override;
	string voice() const override;	

	string getStringFileInfo()const override;
	void readStringInfo(string &res)override;
};

