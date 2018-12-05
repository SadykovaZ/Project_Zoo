#include "Elephant.h"
Elephant::Elephant(string name, string color, int age, int trunkLength, bool hasTusk)
	:Animal(name, color, age)
{
	this->trunkLength = trunkLength;
	this->hasTusk = hasTusk;
}
void Elephant::setTrunkLength(int trunkLength)
{
	this->trunkLength = trunkLength;
}
void Elephant::setHasTusk(bool hasTusk)
{
	this->hasTusk = hasTusk;
}
void Elephant::getInfo() const
{
	Animal::getInfo();
	cout << "\n����� ������: " << trunkLength << endl;
	cout << "\n������� ������: " << hasTusk << endl;
	
}
string Elephant::voice() const
{
	return string("������");
}

string Elephant::getStringFileInfo() const
{
	string res = Animal::getStringFileInfo();
	res += to_string(trunkLength);
	res += ';';
	res += to_string(hasTusk);
	res += ';';
	return res;
}

void Elephant::readStringInfo(string & res)
{
	Animal::readStringInfo(res);
	trunkLength = stoi(res.substr(0, res.find(';')));
	hasTusk = res[res.size() - 2];
}
