#include "ZooConsole.h"

ZooConsole::ZooConsole()
	:z("", "")
{
	startMenu();
}

void ZooConsole::start()
{
	mainMenu();
}

void ZooConsole::saveToFile() const
{
	ofstream file("zoo.txt");
	file << z.getZooName() << ";"
		<< z.getCity() << "\n";
	for (size_t i = 0; i < z.getCountOfAnimals(); i++)
	{
		file << z[i].getStringFileInfo();
		if (i != z.getCountOfAnimals() - 1) file << endl;
	}
	file.close();
}

void ZooConsole::loadFromFile()
{
	ifstream file("zoo.txt");
	if (!file)
		throw exception("Cannot open file!");
	string s;
	getline(file, s);
	z.setZooName(s.substr(0, s.find(';')));
	s = s.substr(s.find(';') + 1);
	if (s[s.size() - 1] == ';')	s.pop_back();
	z.setCity(s.substr(0, s.find(';')));
	s = s.substr(s.find(';') + 1);
	if (s[s.size() - 1] == ';')	s.pop_back();
	while (!file.eof())
	{
		getline(file, s);
		string type = s.substr(0, s.find(';'));
		Animal*anim = nullptr;
		if (type == "Bear") {
			anim = new Bear;
		}
		else if (type == "Cat") {
			anim = new Cat;
		}
		else if (type == "Elephant") {
			anim = new Elephant;
		}
		else if (type == "Giraffe") {
			anim = new Giraffe;
		}
		else if (type == "Kangaroo") {
			anim = new Kangaroo;
		}
		else if (type == "Monkey") {
			anim = new Monkey;
		}

		s = s.substr(s.find(';') + 1);
		anim->readStringInfo(s);
		z.addAnimal(anim);
	}
	file.close();
}

ZooConsole::~ZooConsole()
{
	saveToFile();
}

void ZooConsole::startMenu()
{
	clearScreen();
	cout << "����� ����������!";
	Sleep(2000);
	/*this->setZooNameMenu();
	this->setCityNameMenu();*/
}

void ZooConsole::mainMenu()
{
	int choise = 0;

	while (choise != 4) {
		clearScreen();
		cout << "��� ��������: " << z.getZooName();
		cout << "\n�����: " << z.getCity();
		cout << "\n���������� ��������: " << z.getCountOfAnimals();
		cout << "\n\n-------------\n\n";
		cout << "\
		1. �������� ����� ��������\n\
		2. �������� ���������\n\
		3. �������� ���������� � ��������\n\
		4. �����\n"
			;
		cin >> choise;
		switch (choise)
		{
		case 1:
			addAnimalMenu();
			break;
		case 2:
			removeAnimalMenu();
			break;
		case 3:
			showInfo();
			pause();
			break;
		case 4:
			break;
		default:
			cout << "������������ �������\n������ ����� ������ ����� ����������\n";
			pause();
			clearScreen();
			break;
		}
	}
	cout << "�� ��������!\n";
}

void ZooConsole::addAnimalMenu()
{
	size_t ch;
	while (1) {
		clearScreen();
		cout << "�������� ��������\n";
		cout << "1. �������\n2. �����\n3. ����\n4. �����\n5. �������\n6. ��������\n7. ����� � �������� ����\n";
		cin >> ch;
		if (ch > 7) {
			cout << "�������� �������\n";
			system("pause");
		}
		else
			break;

	}
	if (ch == 7)
		return;
	string name;
	string color;
	int age;
	clearScreen();
	cout << "������� ��� ���������\n";
	cin >> name;
	cout << "������� ���� ���������\n";
	cin >> color;
	cout << "������� ������� ���������\n";
	cin >> age;

	Animal*anim = nullptr;
	switch (ch)
	{
	case 1:
	{

		string type;
		cout << "������� ��� �������\n";
		cin >> type;
		anim = new Bear(name, color, age, type);
		break;
	}
	case 2:
	{
		string breed;
		int cntLives;

		cout << "������� ������\n";
		cin >> breed;
		cout << "������� ���������� ������\n";
		cin >> cntLives;
		anim = new Cat(name, color, age, breed, cntLives);
		break;
	}
	case 3:
	{
		int trunkLength;
		bool hasTusk;
		cout << "������� ����� ������\n";
		cin >> trunkLength;
		cout << "���� �� � ����� �����\n";
		cin >> hasTusk;
		anim = new Elephant(name, color, age, trunkLength, hasTusk);
		break;
	}
	case 4:
	{
		int neckLength;
		cout << "������� ����� ���\n";
		cin >> neckLength;		
		anim = new Giraffe(name, color, age, neckLength);
		break;
	}
	case 5:
	{
		int bagSize;
		cout << "������� ������ �����\n";
		cin >> bagSize;
		anim = new Kangaroo(name, color, age, bagSize);
		break;
	}
	case 6:
	{
		string type;
		cout << "������� ��� ��������\n";
		cin >> type;
		anim = new Monkey(name, color, age, type);
		break;
	}
	}
	clearScreen();
	z.addAnimal(anim);
	cout << "�������� ���������!\n";
	system("pause");
}

void ZooConsole::removeAnimalMenu()
{
	while (1) {
		clearScreen();
		cout << "�������� ID ��������� ��� ��������" << endl;
		showShortInfo();
		int ch;
		cin >> ch;
		if (!z.removeAnimalById(ch)) {
			cout << "�������� ID!\n";
			pause();
			continue;
		}
		cout << "�������� ���������!\n";
		pause();
		return;
	}
}

void ZooConsole::showInfo() const
{
	clearScreen();
	z.info();
	
}

void ZooConsole::setZooNameMenu()
{
	clearScreen();
	cout << "������� �������� ��������\n";
	string name;
	cin >> name;
	z.setZooName(name);
}

void ZooConsole::setCityNameMenu()
{
	clearScreen();
	cout << "������� �������� ������\n";
	string name;
	cin >> name;
	z.setCity(name);
}

void ZooConsole::setAnimalInfoMenu()
{
	while (1)
	{
		clearScreen();
		showShortInfo();
		cout << "0- ��������� �����";
		cout << "\n������� ID ���������: ";
		int ch;
		cin >> ch;
		if (ch == 0) break;
		Animal *anim = z.getAnimalById(ch);

		if (anim == nullptr)
		{
			cout << "�������� ID\n";
			pause();
			continue;
		}
		editAnimalMenu(anim);
	}
}


void ZooConsole::showShortInfo() const
{
	for (int i = 0; i < z.getCountOfAnimals(); i++)
	{
		cout << setw(3) << left << z[i].getId()
			<< setw(10) << left << string(typeid(z[i]).name()).substr(6)
			<< setw(10) << left << z[i].getName() << endl;
	}
}

void ZooConsole::editAnimalMenu(Animal * animal)
{
	while (1)
	{
		clearScreen();
		cout << string(typeid(*animal).name()).substr(6) << endl;
		animal->getInfo();
		cout << "1. �������� ���������� � ��������\n";
		cout << "2. ��������� ��������\n";
		cout << "0. Back\n";
		int ch;
		cin >> ch;
		switch (ch)
		{
		case 0:
			return;
		case 1:
			editAnimalInfo(animal);
			break;
		case 2:
			z.removeAnimalById(animal->getId());
			cout << "�������� ���������!" << endl;
			pause();
			return;
			break;		
		default:
			cout << "����������� �������";
			break;
		}
	}
}

void ZooConsole::editAnimalInfo(Animal * animal)
{
	while (1)
	{
		clearScreen();
		animal->getInfo();
		int index = 0;
		cout << "\n�������� ����� ���������� ��������\n";
		cout << ++index << ". ���\n";
		cout << ++index << ". ����\n";
		cout << ++index << ". �������\n";
		
		int pos;
		if (typeid(*animal) == typeid(Bear))
		{
			pos = 1;
			cout << ++index << ". ��� �������\n";			
		}
		else if (typeid(*animal) == typeid(Cat))
		{
			pos = 2;
			cout << ++index << ". ������ \n";
			cout << ++index << ". ���������� ������ \n";

		}
		else if (typeid(*animal) == typeid(Elephant))
		{
			pos = 3;
			cout << ++index << ". ����� ������ \n";
			cout << ++index << ". ���� �� ����� \n";

		}
		else if (typeid(*animal) == typeid(Giraffe))
		{
			pos = 4;
			cout << ++index << ". ����� ��� \n";
		}
		else if (typeid(*animal) == typeid(Kangaroo))
		{
			pos = 5;
			cout << ++index << ". ������ ����� \n";
		}
		else if (typeid(*animal) == typeid(Monkey))
		{
			pos = 6;
			cout << ++index << ". ��� �������� \n";
		}

		cout << "0. ��������� �����\n";
		int ch;
		cin >> ch;
		if (ch < 0 || ch > index)
		{
			cout << "����������� �������!\n";
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
			cout << "\n ������� ����� ���: ";
			cin >> name;
			animal->setName(name);
			break;
		}
		case 2:
		{
			string color;
			cout << "\n ������� ����� �������: ";
			cin >> color;
			animal->setColor(color);
			break;
		}
		case 3:
		{
			int age;
			cout << "\n ������� ����� �������: ";
			cin >> age;
			animal->setAge(age);
			break;
		}		
		default:
		{
			switch (pos)
			{
			case 1:
				if (ch == 4)
				{
					cout << "������� ��� �������\n";
					string type;
					cin >> type;
					((Bear*)animal)->setType(type);
				}				
				break;
			case 2:
				if (ch == 4)
				{
					cout << "������� ������\n";
					string breed;
					cin >> breed;
					((Cat*)animal)->setBreed(breed);
				}
				else
				{
					cout << "������� ���������� ������\n";
					int cntLives;
					cin >> cntLives;					
					((Cat*)animal)->setCntLives(cntLives);
				}
				break;
			case 3:
				if (ch == 4)
				{
					cout << "������� ����� ������\n";
					int trunkLength;
					cin >> trunkLength;
					((Elephant*)animal)->setTrunkLength(trunkLength);
				}
				else
				{
					cout << "���� �� �����\n";
					bool hasTusk;
					cin >> hasTusk;
					((Elephant*)animal)->setHasTusk(hasTusk);
				}
				break;
			case 4:
				if (ch == 4)
				{
					cout << "������ ���\n";
					int neckLength;
					cin >> neckLength;
					((Giraffe*)animal)->setNeckLength(neckLength);
				}
				break;
			case 5:
				if (ch == 4)
				{
					cout << "������ �����\n";
					int bagSize;
					cin >> bagSize;
					((Kangaroo*)animal)->setBagSize(bagSize);
				}
				break;
			case 6:
				if (ch == 4)
				{
					cout << "��� ��������\n";
					string type;
					cin >> type;
					((Monkey*)animal)->setType(type);
				}
				break;

			}
		}
		break;
		}
	}
	pause();
}
