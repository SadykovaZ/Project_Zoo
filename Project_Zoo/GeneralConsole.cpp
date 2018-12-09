#include"GeneralConsole.h"

GeneralConsole::GeneralConsole()
{
	startMenu();
}

void GeneralConsole::begin()
{

	while (1)
	{

		cout << "Сегодня как Главный управляющий выберите информацию, которую хотели бы посмотреть и/или изменить: \n";
		cout << "1 - Информаци о сотрудниках\n";
		cout << "2 - Информация о животных\n";
		cout << "0 - Выход из программы\n";
		int choice;
		cin >> choice;
		if (choice < 0 || choice>2)
		{
			cout << "Неизвестная команда\n";
			system("pause");
			continue;
		}
		switch (choice)
		{
		case 0:
			return;
			break;
		case 1:
		{
			try {
				o.loadFromFile();
			}
			catch (exception&e)
			{
				cout << e.what();
				system("pause");
			}
			o.start();			
			break;
		}
		case 2:
		{
			z.loadFromFile();
			z.start();
			break;
		}

		}
	}
}
GeneralConsole::~GeneralConsole()
{
	save();
}
void GeneralConsole::saveToFile2() const
{
	z.saveToFile();
}
void GeneralConsole::save() const
{
	{
		saveToFile1();
	}
	system("pause");
	{
		saveToFile2();
	}
	system("pause");

}
void GeneralConsole::saveToFile1() const
{
	o.saveToFile();
}

void GeneralConsole::startMenu()
{
	cout << "Добро пожаловать в организацию владеющей зоопарком!\n";
	Sleep(2000);
	system("cls");
}
