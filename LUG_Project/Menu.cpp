#include "pch.h"
#include "Menu.h"



Menu::Menu()
{
	gaus = new Gaus();
	lu = new Lu();
}

Menu::~Menu()
{
	delete gaus;
	delete lu;
}


void Menu::options()
{
	cout << "==== MENU GLOWNE ===" << endl;
	cout << "Dostepne opcje:" << endl;
	cout << "1. Metoda Gausa" << endl;
	cout << "2. Dekompozycja LU" << endl;
	cout << "3. Wyjscie z programu" << endl;
}
void Menu::gausOptions()
{
	cout << "==== METODA GAUSA ===" << endl;
	cout << "1. Zaladuj z pliku" << endl;
	cout << "2. Wygeneruj recznie macierz" << endl;
	cout << "3. Wyswietl macierz" << endl;
	cout << "4. Wykonaj metode Gausa" << endl;
	cout << "5. Powrot" << endl;

	cin >> operation;
	switch (operation)
	{
	case 1:
	{
		system("CLS");
		gaus->loadFromFile(file);

		gausOptions();

	}
	break;
	case 2:
	{
		system("CLS");
		gaus->initMatrix();
		gaus->fillMatrix();

		system("CLS");
		gausOptions();
	}
	break;
	case 3:
	{
		gaus->printMatrix();
		gausOptions();
	}
	break;
	case 4:
	{
		system("CLS");
		gaus->checkConsistency(4, gaus->performOperation(4));
		gaus->printResult(4, gaus->performOperation(4));

		//gausOptions();


	}
	break;
	case 5:
	{
		system("CLS");
		menu();

	}
	break;
	default:
	{
		cout << endl << "Brak takiej operacji" << endl;
		gausOptions();
	}
	break;
	}

}
void Menu::luOptions()
{
	cout << "==== DEKOMPOZYCJA LU ===" << endl;
	cout << "1. Zaladuj z pliku" << endl;
	cout << "2. Wygeneruj recznie macierz" << endl;
	cout << "3. Wyswietl macierz" << endl;
	cout << "4. Wykonaj dekompozycje LU" << endl;
	cout << "5. Powrot" << endl;

	cin >> operation;
	switch (operation)
	{
	case 1:
	{
		system("CLS");
		lu->loadFromFile(file);

		luOptions();

	}
	break;
	case 2:
	{
		system("CLS");
		lu->initMatrix();
		lu->fillMatrix();

		system("CLS");
		luOptions();
	}
	break;
	case 3:
	{
		lu->printMatrix();
		luOptions();
	}
	break;
	case 4:
	{
		system("CLS");

		//gausOptions();


	}
	break;
	case 5:
	{
		system("CLS");
		menu();

	}
	break;
	default:
	{
		cout << endl << "Brak takiej operacji" << endl;
		gausOptions();
	}
	break;
	}

}