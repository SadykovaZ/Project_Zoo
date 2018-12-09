#include "Manager.h"


Manager::Manager(string name, int age, string sex, int workYears, bool communicationSkills, bool hasEdu)
	:Employee(name, age, sex, workYears)
{
	setCommunicationSkills(communicationSkills);
	setHasEdu(hasEdu);
}

void Manager::setCommunicationSkills(bool communicationSkills)
{
	this->communicationSkills = communicationSkills;
}

void Manager::setHasEdu(bool hasEdu)
{
	this->hasEdu = hasEdu;
}

void Manager::info() const
{
	Employee::info();
	cout << "��������������� ������: " << boolalpha << communicationSkills << endl;
	cout << "������ �����������: " << boolalpha << hasEdu << endl;
}

double Manager::getSalary() const
{
	double coef = communicationSkills * 0.05;
	coef = hasEdu * 0.03;
	coef += getWorkYears()*0.05;

	return coef;
}

string Manager::getStringFileInfo() const
{
	string res = Employee::getStringFileInfo();
	res += to_string(getCommunicationSkills()) + ";";
	res += to_string(getHasEdu());
	res += ';';
	return res;
}

void Manager::readStringInfo(string & res)
{
	Employee::readStringInfo(res);
	communicationSkills = res[res.size() - 2];
	hasEdu = res[res.size() - 2];
}
