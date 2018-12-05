#include "Monkey.h"
Monkey::Monkey(string name, string color, int age, string type)
	:Animal(name, color, age)
{
	this->type = type;
}

void Monkey::setType(string type)
{
	this->type = type;
}

void Monkey::getInfo() const
{
	Animal::getInfo();
	cout << "\n��� �������: " << type << endl;
	
}

string Monkey::voice() const
{
	return string("�����");
}

string Monkey::getStringFileInfo() const
{
	string res = Animal::getStringFileInfo();
	res += type;
	res += ';';
	return res;
}

void Monkey::readStringInfo(string & res)
{
	Animal::readStringInfo(res);
	type = res;
}
