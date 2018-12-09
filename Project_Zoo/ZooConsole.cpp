#include "ZooConsole.h"

ZooConsole::ZooConsole()
	:z("", "")
{
	try
	{
		startMenu();
	}
	catch (exception&e)
	{
		cout << e.what();
	}
}

void ZooConsole::start()
{
	mainMenu();
}

void ZooConsole::saveToFile() const
{
	cout << "1";
	ofstream file("zoo.txt");
	file << z.getZooName() << ";"
		<< z.getCity() << "\n";
	for (size_t i = 0; i < z.getCountOfAnimals(); i++)
	{
		file << z[i].getStringFileInfo();
		if (i != z.getCountOfAnimals() - 1) file << endl;
	}
	file.close();
	cout << "2";
}

void ZooConsole::loadFromFile()
{
	ifstream file("zoo.txt");
	if (!file)
		throw exception("Невозможно открыть файл!");
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
	/*cout << "Добро пожаловать!";
	Sleep(2000);
	system("cls");
	cout << "Подождите информация загружается";
	for (size_t i = 0; i < 5; i++)
	{
		cout << ".";
		Sleep(1000);
	}*/
	//this->setZooNameMenu();
	//this->setCityNameMenu();
}

void ZooConsole::mainMenu()
{
	int choise = 0;

	while (choise != 5) {
		clearScreen();
		cout << "Имя зоопарка: " << z.getZooName();
		cout << "\nГород: " << z.getCity();
		cout << "\nКоличество животных: " << z.getCountOfAnimals();
		cout << "\n\n----------------------------------------------------------\n\n";
		cout << "\
		1. Добавить новое животное\n\
		2. Животное переехало\n\
		3. Показать информацию о животных\n\
                4. Изменить информацию о животных\n\
		5. Выход на начальный экран выбора\n"
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
			setAnimalInfoMenu();
			break;
		case 5:
			break;
		default:
			cout << "Неправильная команда\nнажмите любую кнопку чтобы продолжить\n";
			pause();
			clearScreen();
			break;
		}
	}
	cout << "Спасибо!\n";
	pause();
	clearScreen();
}

void ZooConsole::addAnimalMenu()
{
	size_t ch;
	while (1) {
		clearScreen();
		cout << "Выберите животное\n";
		cout << "1. Медведь\n2. Кошка\n3. Слон\n4. Жираф\n5. Кенгуру\n6. Обезьяна\n7. Выход в основное меню\n";
		cin >> ch;
		if (ch > 7) {
			cout << "Неверная позиция\n";
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
	cout << "Введите имя животного\n";
	cin >> name;
	cout << "Введите цвет животного\n";
	cin >> color;
	cout << "Введите возраст животного\n";
	cin >> age;

	Animal*anim = nullptr;
	switch (ch)
	{
	case 1:
	{

		string type;
		cout << "Введите вид медведя\n";
		cin >> type;
		anim = new Bear(name, color, age, type);
		break;
	}
	case 2:
	{
		string breed;

		cout << "Введите породу\n";
		cin >> breed;
		anim = new Cat(name, color, age, breed);
		break;
	}
	case 3:
	{
		int trunkLength;
		bool hasTusk;
		cout << "Введите длину хобота\n";
		cin >> trunkLength;
		cout << "Есть ли у слона бивни\n";
		cin >> hasTusk;
		anim = new Elephant(name, color, age, trunkLength, hasTusk);
		break;
	}
	case 4:
	{
		int neckLength;
		cout << "Введите длину шеи\n";
		cin >> neckLength;
		anim = new Giraffe(name, color, age, neckLength);
		break;
	}
	case 5:
	{
		int bagSize;
		cout << "Введите размер сумки\n";
		cin >> bagSize;
		anim = new Kangaroo(name, color, age, bagSize);
		break;
	}
	case 6:
	{
		string type;
		cout << "Введите вид обезьяны\n";
		cin >> type;
		anim = new Monkey(name, color, age, type);
		break;
	}
	}
	clearScreen();
	z.addAnimal(anim);
	cout << "Животное добавлено!\n";
	system("pause");

}

void ZooConsole::removeAnimalMenu()
{
	while (1) {
		clearScreen();
		cout << "Выберите ID животного для отгрузки" << endl;
		showShortInfo();
		int ch;
		cin >> ch;
		if (!z.removeAnimalById(ch)) {
			cout << "Неверный ID!\n";
			pause();
			continue;
		}
		cout << "Животное отгружено!\n";
		pause();
		return;
	}
}

void ZooConsole::showInfo() const
{
	clearScreen();
	z.info();
	while (1)
	{
		cout << "Хотите посмотреть что говорит каждое животное (1 - да, 0 - выход в главное меню)\n";

		int ch;
		cin >> ch;
		if (ch == 0) break;
		if (ch == 1)
		{
			showRollCall();
		}
	}
}

void ZooConsole::setZooNameMenu()
{
	clearScreen();
	cout << "Введите название зоопарка\n";
	string name;
	cin >> name;
	z.setZooName(name);
}

void ZooConsole::setCityNameMenu()
{
	clearScreen();
	cout << "Введите название города\n";
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
		cout << "0- Вернуться назад";
		cout << "\nВыбрать ID животного: ";
		int ch;
		cin >> ch;
		if (ch == 0) break;
		Animal *anim = z.getAnimalById(ch);

		if (anim == nullptr)
		{
			cout << "Неверный ID\n";
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

void ZooConsole::showRollCall() const
{
	cout << z.rollCall();
}

void ZooConsole::editAnimalMenu(Animal * animal)
{
	while (1)
	{
		clearScreen();
		cout << string(typeid(*animal).name()).substr(6) << endl;
		animal->getInfo();
		cout << "1. Изменить информацию о животном\n";
		cout << "2. Отгрузить животное\n";
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
			cout << "Животное отгружено!" << endl;
			pause();
			return;
			break;
		default:
			cout << "Неизвестная команда";
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
		cout << "\nВыберите какую информацию изменить\n";
		cout << ++index << ". Имя\n";
		cout << ++index << ". Цвет\n";
		cout << ++index << ". Возраст\n";

		int pos;
		if (typeid(*animal) == typeid(Bear))
		{
			pos = 1;
			cout << ++index << ". Вид медведя\n";
		}
		else if (typeid(*animal) == typeid(Cat))
		{
			pos = 2;
			cout << ++index << ". Порода \n";


		}
		else if (typeid(*animal) == typeid(Elephant))
		{
			pos = 3;
			cout << ++index << ". Длина хобота \n";
			cout << ++index << ". Есть ли бивни \n";

		}
		else if (typeid(*animal) == typeid(Giraffe))
		{
			pos = 4;
			cout << ++index << ". Длина шеи \n";
		}
		else if (typeid(*animal) == typeid(Kangaroo))
		{
			pos = 5;
			cout << ++index << ". Размер сумки \n";
		}
		else if (typeid(*animal) == typeid(Monkey))
		{
			pos = 6;
			cout << ++index << ". Вид обезьяны \n";
		}

		cout << "0. Вернуться назад\n";
		int ch;
		cin >> ch;
		if (ch < 0 || ch > index)
		{
			cout << "Неизвестная команда!\n";
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
			cout << "\n Введите новое имя: ";
			cin >> name;
			animal->setName(name);
			break;
		}
		case 2:
		{
			string color;
			cout << "\n Введите новый возраст: ";
			cin >> color;
			animal->setColor(color);
			break;
		}
		case 3:
		{
			int age;
			cout << "\n Введите новый возраст: ";
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
					cout << "Введите вид медведя\n";
					string type;
					cin >> type;
					((Bear*)animal)->setType(type);
				}
				break;
			case 2:
				if (ch == 4)
				{
					cout << "Введите породу\n";
					string breed;
					cin >> breed;
					((Cat*)animal)->setBreed(breed);
				}
				break;
			case 3:
				if (ch == 4)
				{
					cout << "Введите длину хобота\n";
					int trunkLength;
					cin >> trunkLength;
					((Elephant*)animal)->setTrunkLength(trunkLength);
				}
				else
				{
					cout << "Есть ли бивни\n";
					bool hasTusk;
					cin >> hasTusk;
					((Elephant*)animal)->setHasTusk(hasTusk);
				}
				break;
			case 4:
				if (ch == 4)
				{
					cout << "Размер шеи\n";
					int neckLength;
					cin >> neckLength;
					((Giraffe*)animal)->setNeckLength(neckLength);
				}
				break;
			case 5:
				if (ch == 4)
				{
					cout << "Размер сумки\n";
					int bagSize;
					cin >> bagSize;
					((Kangaroo*)animal)->setBagSize(bagSize);
				}
				break;
			case 6:
				if (ch == 4)
				{
					cout << "Вид обезьяны\n";
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
