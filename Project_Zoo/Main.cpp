#include"GeneralConsole.h"
void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Rus");
	GeneralConsole g;
	try {
		g.begin();
	}
	catch (exception&e) {
		cout << e.what();
		system("pause");
	}
	system("pause");
}