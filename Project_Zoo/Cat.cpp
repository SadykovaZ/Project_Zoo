#include "Cat.h"

Cat::Cat(string name, string color, int age, string breed, int cntLives)
	:Animal(name,  color,  age)
{
	this->breed = breed;
	this->cntLives = cntLives;
}
void Cat::setBreed(string breed)
{
	this->breed = breed;
}
void Cat::setCntLives(int cntLives)
{
	this->cntLives = cntLives;
}
void Cat::getInfo() const
{
	Animal::getInfo();
	cout << "\nПорода семейста кошачих: " << breed << endl;
	cout << "\nКоличество жизней: " << cntLives << endl;	
}
string Cat::voice() const
{
	return string("Мяу");
}

string Cat::getStringFileInfo() const
{
	string res = Animal::getStringFileInfo();
	res += breed;
	res += to_string(cntLives);
	res += ';';
	return res;
}

void Cat::readStringInfo(string & res)
{
	Animal::readStringInfo(res);
	breed = res;
	cntLives = stoi(res.substr(0, res.find(';')));
}
