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
		throw exception("Невозможно открыть файл!");
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
	/*cout << "Добро пожаловать!";
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
		cout << "Название организации: " << org.getName();
		cout << "\nЗарплата: " << org.getBaseSalary();
		cout << "\nКоличество сотрудников: " << org.getCountOfEmployee();
		cout << "\n\n----------------------------\n\n";
		cout << "\
		1. Добавить нового сотрудника\n\
		2. Удалить сотрудника\n\
		3. Информация по организации\n\
                4. Информация по сотрудникам\n\
		5. Выход на начальный экран выбора\n"
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
			cout << "Неизвестная команда\nНажмити любую клавишу для продолжения\n";
			pause();
			system("cls");
			break;
		}
	}
	cout << "Спасибо!\n";
	pause();
	clearScreen();	
}
void OrganizationConsole::addEmpMenu()
{
	size_t ch;
	while (1) {
		system("cls");
		cout << "Выберити должность\n";
		cout << "1. Садовод\n2. Смотритель\n3. Директор\n4. Менеджер\n5. Ветеринар\n6.Основное меню\n";
		cin >> ch;
		if (ch > 6) {
			cout << "Неизвестная должность\n";
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
	cout << "Введите имя сотрудника\n";
	cin >> name;
	cout << "Введите возвраст сотрудника\n";
	cin >> age;
	cout << "Введите пол сотрудника\n";
	cin >> sex;
	cout << "Введите опыт сотрудника\n";
	cin >> exp;
	Employee*emp = nullptr;
	switch (ch)
	{
	case 1:
		bool creativeSkills;
		cout << "Имеется ли творческий стиль? (1 - да, 0 - нет)\n";
		cin >> creativeSkills;
		emp = new Gardener(name, age, sex, exp, creativeSkills);
		break;
	case 2:
		bool attentiveness;
		cout << "Внимательность? (1 - да, 0 - нет)\n";
		cin >> attentiveness;
		
		emp = new Keeper(name, age, sex, exp, attentiveness);
		break;
	case 3:
		emp = new Director(name, age, sex, exp);
		break;
	case 4:
		bool edu1;
		bool communication;
		cout << "Наличие высшего образования? (1 - да, 0 - нет)\n" << endl;
		cin >> edu1;
		cout << "Коммуникативность? (1 - да, 0 - нет)\n" << endl;
		cin >> communication;
		emp = new Manager(name, age, sex, exp, edu1, communication);
		break;
	case 5:
		bool anesthesiology;
		bool surgery;
		bool ophthalmology;
		cout << "Обладает ли сотрудник следующими навыками: \n";
		cout << "анестезиологии? (1 - да, 0 - нет)\n" << endl;
		cin >> anesthesiology;
		cout << "хирургия? (1 - да, 0 - нет)\n" << endl;
		cin >> surgery;
		cout << "офтальмология? (1 - да, 0 - нет)\n" << endl;
		cin >> ophthalmology;

		emp = new Veterinarian(name, age, sex, exp, anesthesiology, surgery, ophthalmology);
		break;
	}
	system("cls");
	org.addEmployee(emp);
	cout << "Сотрудник добавлен!\n";
	pause();
}
void OrganizationConsole::removeEmpMenu()
{
	while (1) {
		system("cls");
		cout << "Выберите ID работника для увольнения:" << endl;
		showShortInfo();
		int ch;
		cin >> ch;
		if (!org.removeEmployeeById(ch)) {
			cout << "Неверный ID!\n";
			system("pause");
			continue;
		}
		cout << "Работник уволен!\n";
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
	cout << "Введите имя организации: \n";
	string name;
	cin >> name;
	org.setName(name);
}
void OrganizationConsole::setSalaryMenu()
{
	system("cls");
	cout << "Введите зарплату: \n";
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
		cout << "0- Вернуться назад";
		cout << "\nВыберите ID работника: ";
		int ch;
		cin >> ch;
		if (ch == 0) break;
		Employee *e = org.getEmpById(ch);

		if (e == nullptr)
		{
			cout << "Неверный ID!\n";
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
		cout << "1. Изменить информацию о сотруднике\n";
		cout << "2. Уволить сотрудника\n";
		cout << "3. Поменять позицию сотрудника\n";
		cout << "0. Назад\n";
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
			cout << "Работник уволен!" << endl;
			pause();
			return;
			break;
		case 3:
			changePosition(emp);
			return;
		default:
			cout << "Неизвестная команда";
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
		cout << "\nВыберите информацию для изменения: \n";
		cout << ++index << ". Имя\n";
		cout << ++index << ". Возраст\n";
		cout << ++index << ". Пол\n";
		cout << ++index << ". Опыт работы\n";
		int pos;
		if (typeid(*emp) == typeid(Gardener))
		{
			pos = 1;
			cout << ++index << ". Творческие навыки\n";			
		}
		else if (typeid(*emp) == typeid(Keeper))
		{
			pos = 2;
			cout << ++index << ". Внимательность\n";
		}
		else if (typeid(*emp) == typeid(Manager))
		{
			pos = 3;
			cout << ++index << ". Коммуникативные навыки\n";
			cout << ++index << ". Высшее образование\n";

		}
		else if (typeid(*emp) == typeid(Veterinarian))
		{
			pos = 4;
			cout << ++index << ". Навыки анастезии\n";
			cout << ++index << ". Навыки хирургии\n";
			cout << ++index << ". Навыки офтальмологии\n";

		}
		cout << "0. Вернуться назад\n";
		int ch;
		cin >> ch;
		if (ch < 0 || ch > index)
		{
			cout << "Неизвестная комманда!\n";
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
			cout << "\nВведите новое имя: ";
			cin >> name;
			emp->setName(name);
			break;
		}
		case 2:
		{
			int age;
			cout << "\nВведите возрас: ";
			cin >> age;
			emp->setAge(age);
			break;
		}
		case 3:
		{
			string sex;
			cout << "\nВведите пол: ";
			cin >> sex;
			emp->setSex(sex);
			break;
		}
		case 4:
		{
			int exp;
			cout << "\nВведите опыт работы: ";
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
					cout << "Введите имеются ли творческие навыки\n";
					bool creativeSkills;
					cin >> creativeSkills;
					((Gardener*)emp)->setCreativeSkills(creativeSkills);
				}				
				break;
			case 2:
				if (ch == 5)
				{
					cout << "Внимательный сотрудник?\n";
					bool attentiveness;
					cin >> attentiveness;
					((Keeper*)emp)->setAttentiveness(attentiveness);
				}
				break;
			case 3:
				if (ch == 5)
				{
					cout << "Имеются ли коммуникативные навыки\n";
					bool commSkills;
					cin >> commSkills;
					((Manager*)emp)->setCommunicationSkills(commSkills);
				}
				else
				{
					cout << "Есть ли высшее образование\n";
					bool hasEdu;
					cin >> hasEdu;
					((Manager*)emp)->setHasEdu(hasEdu);
				}
				break;
			case 4:
				if (ch == 5)
				{
					cout << "Есть ли следующие навыки:\n";					
					bool anastSkills;
					bool surgSkills;
					bool ophSkills;
					cout << "Анастезии: ";
					cin >> anastSkills;
					cout << "Хирургии: ";
					cin >> surgSkills;
					cout << "Офтальмологии: ";
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
		cout << "Выберите новую позицию для работника " << emp->getPosition() << " " << emp->getName() << endl;
		cout << "1. Директор\n";
		cout << "2. Садовник\n";
		cout << "3. Смотритель\n";
		cout << "4. Менеджер\n";
		cout << "5. Ветеринар\n";
		cout << "0. Вернуться назад\n";
		int ch;
		cin >> ch;
		if (ch < 0 || ch>5)
		{
			cout << "Неизвестная команда\n";
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