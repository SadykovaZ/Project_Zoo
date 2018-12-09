#include"GeneralConsole.h"
#include"ZooConsole.h"
#include"org/OrganizationConsole.h"
void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Rus");
	ZooConsole z;
	OrganizationConsole org;
	int ch;
	cin >> ch;
	if (ch == 1)
	{
		z.loadFromFile();
		z.start();
		z.saveToFile();
	}
	else if (ch == 2)
	{
		//org.loadFromFile();
		org.start();
		
		org.saveToFile();
	}
	
	//GeneralConsole g;
	//try {
	//	g.begin();//
	//}
	//catch (exception&e) {
	//	cout << e.what();
	//	system("pause");
	//}
	system("pause");
}