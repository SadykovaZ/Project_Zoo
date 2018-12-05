#include"ZooConsole.h"
void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Rus");
	ZooConsole z;
	try {
		z.loadFromFile();

	}
	catch (exception&w)
	{
		cout << w.what();
		system("pause");
	}
	z.start();
	system("pause");
}