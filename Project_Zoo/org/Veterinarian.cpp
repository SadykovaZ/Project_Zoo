#include "Veterinarian.h"


Veterinarian::Veterinarian(string name, int age, string sex, int workYears, bool anesthesiologySkill, bool surgerySkill, bool ophthalmologySkill)
	:Employee(name, age, sex, workYears)
{
	setAnesthesiologySkill(anesthesiologySkill);
	setSurgerySkill(surgerySkill);
	setOphthalmologySkill(ophthalmologySkill);
}

void Veterinarian::setAnesthesiologySkill(bool anesthesiologySkill)
{
	this->anesthesiologySkill = anesthesiologySkill;
}

void Veterinarian::setSurgerySkill(bool surgerySkill)
{
	this->surgerySkill = surgerySkill;
}

void Veterinarian::setOphthalmologySkill(bool ophthalmologySkill)
{
	this->ophthalmologySkill = ophthalmologySkill;
}

void Veterinarian::info() const
{
	Employee::info();
	cout << "������ ���������: " << boolalpha << anesthesiologySkill << endl;
	cout << "������ ���������: " << boolalpha << surgerySkill << endl;
	cout << "������ �������������: " << boolalpha << ophthalmologySkill << endl;
}

double Veterinarian::getSalary() const
{
	double coef = anesthesiologySkill * 0.01;
	coef = surgerySkill * 0.05;
	coef = ophthalmologySkill * 0.03;

	coef += getWorkYears()*0.05;

	return coef;
}

string Veterinarian::getStringFileInfo() const
{
	string res = Employee::getStringFileInfo();
	res += to_string(getAnesthesiologySkill()) + ";";
	res += to_string(getSurgerySkill())+";";
	res += to_string(getOphthalmologySkill());
	res += ';';
	return res;
}

void Veterinarian::readStringInfo(string & res)
{
	Employee::readStringInfo(res);
	anesthesiologySkill = res[res.size() - 2];
	surgerySkill = res[res.size() - 2];
	ophthalmologySkill = res[res.size() - 2];

}
