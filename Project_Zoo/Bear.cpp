#include "Bear.h"
Bear::Bear(string name, string color, int age, string type)
	:Animal(name, color, age)
{
	this->type = type;
}

void Bear::setType(string type)
{
	this->type = type;
}

void Bear::getInfo() const
{
	Animal::getInfo();
	cout << "\n��� �������: " << type << endl;	
	cout << "-------------------------------------\n";
}

string Bear::voice() const
{
	return string("����");
}

string Bear::getStringFileInfo() const
{
	string res = Animal::getStringFileInfo();
	res += type;
	//res += ';';
	return res;
}

void Bear::readStringInfo(string & res)
{
	Animal::readStringInfo(res);
	type = res;
}
