#include "OrganizationConsole.h"
#include<iomanip>
OrganizationConsole::OrganizationConsole()
	:org("", 0)
{
	startMenu();
}
void OrganizationConsole::start()
{
	mainMenu();
}
OrganizationConsole::~OrganizationConsole()
{
	saveToFile();
}
void OrganizationConsole::saveToFile() const
{
	ofstream file("org.txt");
	file << org.getName() << ";"
		<< to_string(org.getBaseSalary()) << "\n";
	for (size_t i = 0; i < org.getCountOfEmployee(); i++)
	{
		file << org[i].getStringFileInfo();
		if (i != org.getCountOfEmployee() - 1) file << endl;
	}
	file.close();
}
void OrganizationConsole::loadFromFile()
{
	ifstream file("org.txt");
	if (!file)
		throw exception("���������� ������� ����!");
	string s;
	getline(file, s);
	org.setName(s.substr(0, s.find(';')));
	s = s.substr(s.find(';') + 1);
	if (s[s.size() - 1] == ';')	s.pop_back();
	org.setBaseSalary(stoi(s));
	while (!file.eof())
	{
		getline(file, s);
		string type = s.substr(0, s.find(';'));
		Employee*emp = nullptr;
		if (type == "Director") {
			emp = new Director;
		}
		else if (type == "Gardener") {
			emp = new Gardener;
		}
		else if (type == "Keeper") {
			emp = new Keeper;
		}
		else if (type == "Manager")
		{
			emp = new Manager;
		}
		else if (type == "Veterinarian")
		{
			emp = new Veterinarian;
		}
		s = s.substr(s.find(';') + 1);
		emp->readStringInfo(s);
		org.addEmployee(emp);
	}
	file.close();
}
void OrganizationConsole::startMenu()
{
	system("cls");
	/*cout << "����� ����������!";
	Sleep(2000);*/
	/*this->setOrgNameMenu();
	this->setSalaryMenu();*/
}
void OrganizationConsole::mainMenu()
{
	int choise = 0;
	while (choise != 5)
	{
		system("cls");
		cout << "�������� �����������: " << org.getName();
		cout << "\n��������: " << org.getBaseSalary();
		cout << "\n���������� �����������: " << org.getCountOfEmployee();
		cout << "\n\n----------------------------\n\n";
		cout << "\
		1. �������� ������ ����������\n\
		2. ������� ����������\n\
		3. ���������� �� �����������\n\
                4. ���������� �� �����������\n\
		5. ����� �� ��������� ����� ������\n"
			;
		cin >> choise;
		switch (choise)
		{

		case 1:
			addEmpMenu();
			break;
		case 2:
			removeEmpMenu();
			break;
		case 3:
			showInfo();
			pause();
			break;
		case 4:
			setEmpInfoMenu();
			pause();
			break;
		case 5:
			break;
		default:
			cout << "����������� �������\n������� ����� ������� ��� �����������\n";
			pause();
			system("cls");
			break;
		}
	}
	cout << "�������!\n";
	pause();
	clearScreen();	
}
void OrganizationConsole::addEmpMenu()
{
	size_t ch;
	while (1) {
		system("cls");
		cout << "�������� ���������\n";
		cout << "1. �������\n2. ����������\n3. ��������\n4. ��������\n5. ���������\n6.�������� ����\n";
		cin >> ch;
		if (ch > 6) {
			cout << "����������� ���������\n";
			pause();
		}
		else
			break;
	}
	if (ch == 6)
		return;
	string name;
	int age;
	string sex;
	int exp;
	system("cls");
	cout << "������� ��� ����������\n";
	cin >> name;
	cout << "������� �������� ����������\n";
	cin >> age;
	cout << "������� ��� ����������\n";
	cin >> sex;
	cout << "������� ���� ����������\n";
	cin >> exp;
	Employee*emp = nullptr;
	switch (ch)
	{
	case 1:
		bool creativeSkills;
		cout << "������� �� ���������� �����? (1 - ��, 0 - ���)\n";
		cin >> creativeSkills;
		emp = new Gardener(name, age, sex, exp, creativeSkills);
		break;
	case 2:
		bool attentiveness;
		cout << "��������������? (1 - ��, 0 - ���)\n";
		cin >> attentiveness;
		
		emp = new Keeper(name, age, sex, exp, attentiveness);
		break;
	case 3:
		emp = new Director(name, age, sex, exp);
		break;
	case 4:
		bool edu1;
		bool communication;
		cout << "������� ������� �����������? (1 - ��, 0 - ���)\n" << endl;
		cin >> edu1;
		cout << "�����������������? (1 - ��, 0 - ���)\n" << endl;
		cin >> communication;
		emp = new Manager(name, age, sex, exp, edu1, communication);
		break;
	case 5:
		bool anesthesiology;
		bool surgery;
		bool ophthalmology;
		cout << "�������� �� ��������� ���������� ��������: \n";
		cout << "��������������? (1 - ��, 0 - ���)\n" << endl;
		cin >> anesthesiology;
		cout << "��������? (1 - ��, 0 - ���)\n" << endl;
		cin >> surgery;
		cout << "�������������? (1 - ��, 0 - ���)\n" << endl;
		cin >> ophthalmology;

		emp = new Veterinarian(name, age, sex, exp, anesthesiology, surgery, ophthalmology);
		break;
	}
	system("cls");
	org.addEmployee(emp);
	cout << "��������� ��������!\n";
	pause();
}
void OrganizationConsole::removeEmpMenu()
{
	while (1) {
		system("cls");
		cout << "�������� ID ��������� ��� ����������:" << endl;
		showShortInfo();
		int ch;
		cin >> ch;
		if (!org.removeEmployeeById(ch)) {
			cout << "�������� ID!\n";
			system("pause");
			continue;
		}
		cout << "�������� ������!\n";
		system("pause");
		return;
	}
}
void OrganizationConsole::showInfo() const
{
	system("cls");
	org.getInfo();
}
void OrganizationConsole::setOrgNameMenu()
{
	system("cls");
	cout << "������� ��� �����������: \n";
	string name;
	cin >> name;
	org.setName(name);
}
void OrganizationConsole::setSalaryMenu()
{
	system("cls");
	cout << "������� ��������: \n";
	int sal;
	cin >> sal;
	org.setBaseSalary(sal);
}
void OrganizationConsole::setEmpInfoMenu()
{
	while (1)
	{
		clearScreen();
		showShortInfo();
		cout << "0- ��������� �����";
		cout << "\n�������� ID ���������: ";
		int ch;
		cin >> ch;
		if (ch == 0) break;
		Employee *e = org.getEmpById(ch);

		if (e == nullptr)
		{
			cout << "�������� ID!\n";
			pause();
			continue;
		}
		editEmpMenu(e);
	}
}
void OrganizationConsole::showShortInfo() const
{
	for (int i = 0; i < org.getCountOfEmployee(); i++)
	{
		cout << setw(3) << left << org[i].getId()
			<< setw(10) << left << string(typeid(org[i]).name()).substr(6)
			<< setw(10) << left << org[i].getName() << endl;
	}
}
void OrganizationConsole::editEmpMenu(Employee * emp)
{
	while (1)
	{
		clearScreen();
		cout << string(typeid(*emp).name()).substr(6) << endl;
		emp->info();
		cout << "1. �������� ���������� � ����������\n";
		cout << "2. ������� ����������\n";
		cout << "3. �������� ������� ����������\n";
		cout << "0. �����\n";
		int ch;
		cin >> ch;
		switch (ch)
		{
		case 0:
			return;
		case 1:
			editEmpInfo(emp);
			break;
		case 2:
			org.removeEmployeeById(emp->getId());
			cout << "�������� ������!" << endl;
			pause();
			return;
			break;
		case 3:
			changePosition(emp);
			return;
		default:
			cout << "����������� �������";
			break;
		}
	}
}
void OrganizationConsole::editEmpInfo(Employee * emp)
{
	while (1)
	{
		clearScreen();
		emp->info();
		int index = 0;
		cout << "\n�������� ���������� ��� ���������: \n";
		cout << ++index << ". ���\n";
		cout << ++index << ". �������\n";
		cout << ++index << ". ���\n";
		cout << ++index << ". ���� ������\n";
		int pos;
		if (typeid(*emp) == typeid(Gardener))
		{
			pos = 1;
			cout << ++index << ". ���������� ������\n";			
		}
		else if (typeid(*emp) == typeid(Keeper))
		{
			pos = 2;
			cout << ++index << ". ��������������\n";
		}
		else if (typeid(*emp) == typeid(Manager))
		{
			pos = 3;
			cout << ++index << ". ��������������� ������\n";
			cout << ++index << ". ������ �����������\n";

		}
		else if (typeid(*emp) == typeid(Veterinarian))
		{
			pos = 4;
			cout << ++index << ". ������ ���������\n";
			cout << ++index << ". ������ ��������\n";
			cout << ++index << ". ������ �������������\n";

		}
		cout << "0. ��������� �����\n";
		int ch;
		cin >> ch;
		if (ch < 0 || ch > index)
		{
			cout << "����������� ��������!\n";
			pause();
			continue;
		}
		switch (ch)
		{
		case 0: return;
			break;
		case 1:
		{
			string name;
			cout << "\n������� ����� ���: ";
			cin >> name;
			emp->setName(name);
			break;
		}
		case 2:
		{
			int age;
			cout << "\n������� ������: ";
			cin >> age;
			emp->setAge(age);
			break;
		}
		case 3:
		{
			string sex;
			cout << "\n������� ���: ";
			cin >> sex;
			emp->setSex(sex);
			break;
		}
		case 4:
		{
			int exp;
			cout << "\n������� ���� ������: ";
			cin >> exp;
			emp->setWorkYears(exp);
			break;
		}
		default:
		{
			switch (pos)
			{
			case 1:
				if (ch == 5)
				{
					cout << "������� ������� �� ���������� ������\n";
					bool creativeSkills;
					cin >> creativeSkills;
					((Gardener*)emp)->setCreativeSkills(creativeSkills);
				}				
				break;
			case 2:
				if (ch == 5)
				{
					cout << "������������ ���������?\n";
					bool attentiveness;
					cin >> attentiveness;
					((Keeper*)emp)->setAttentiveness(attentiveness);
				}
				break;
			case 3:
				if (ch == 5)
				{
					cout << "������� �� ��������������� ������\n";
					bool commSkills;
					cin >> commSkills;
					((Manager*)emp)->setCommunicationSkills(commSkills);
				}
				else
				{
					cout << "���� �� ������ �����������\n";
					bool hasEdu;
					cin >> hasEdu;
					((Manager*)emp)->setHasEdu(hasEdu);
				}
				break;
			case 4:
				if (ch == 5)
				{
					cout << "���� �� ��������� ������:\n";					
					bool anastSkills;
					bool surgSkills;
					bool ophSkills;
					cout << "���������: ";
					cin >> anastSkills;
					cout << "��������: ";
					cin >> surgSkills;
					cout << "�������������: ";
					cin >> ophSkills;
					((Veterinarian*)emp)->setAnesthesiologySkill(anastSkills);
					((Veterinarian*)emp)->setSurgerySkill(surgSkills);
					((Veterinarian*)emp)->setOphthalmologySkill(ophSkills);
				}				
				break;
			}
		}
		break;
		}
	}
	pause();
}
void OrganizationConsole::changePosition(Employee * emp)
{
	while (1)
	{
		clearScreen();
		cout << "�������� ����� ������� ��� ��������� " << emp->getPosition() << " " << emp->getName() << endl;
		cout << "1. ��������\n";
		cout << "2. ��������\n";
		cout << "3. ����������\n";
		cout << "4. ��������\n";
		cout << "5. ���������\n";
		cout << "0. ��������� �����\n";
		int ch;
		cin >> ch;
		if (ch < 0 || ch>5)
		{
			cout << "����������� �������\n";
			pause();
			continue;
		}
		Employee *e = nullptr;
		switch (ch)
		{
		case 1:
			e = new Director(emp->getName(), emp->getAge(), emp->getSex(), emp->getWorkYears());
			
			break;
		case 2:
			e = new Gardener(emp->getName(), emp->getAge(), emp->getSex(), emp->getWorkYears(), 0);
			
			break;
		case 3:
			e = new Keeper(emp->getName(), emp->getAge(), emp->getSex(), emp->getWorkYears(), 0);
			
			break;
		case 4:
			e = new Manager(emp->getName(), emp->getAge(), emp->getSex(), emp->getWorkYears(), 0, 0);
			break;
		case 5:
			e = new Veterinarian(emp->getName(), emp->getAge(), emp->getSex(), emp->getWorkYears(), 0, 0, 0);
			break;
		}
		org.addEmployee(e);
		org.removeEmployeeById(emp->getId());
		return;
	}
}