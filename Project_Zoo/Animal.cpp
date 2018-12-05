#include "Animal.h"
int Animal::idSeq = 0;

Animal::Animal(string name, string color, int age)
{
	this->id = ++idSeq;
	this->name = name;
	this->age = age;
	this->color = color;
}
Animal::Animal() { id = ++idSeq; }
void Animal::setName(string name)
{
	this->name = name;
}

void Animal::setColor(string color)
{
	this->color = color;
}

void Animal::setAge(int age)
{
	this->age = age;
}

void Animal::getInfo() const
{
	cout << "Название: " << (string(typeid(*this).name()).substr(6)) << endl;
	cout << "Имя: " << name << "\nЦвет: " << color << "\nВозраст: " << age << endl;
}

string Animal::getStringFileInfo() const
{
	char d = ';';
	string res = typeid(*this).name();
	res = res.substr(6) + d;
	res += getName() += d;
	res += getColor() += d;
	res += to_string(getAge()) += d;
	return res;
}

void Animal::readStringInfo(string & str)
{
	string info[6];
	for (size_t i = 0; i < 6; i++)
	{
		info[i] = str.substr(0, str.find(';'));
		str = str.substr(str.find(';') + 1);
	}
	this->setName(info[0]);
	this->setColor(info[1]);
	this->setAge(stoi(info[2]));
	
}
