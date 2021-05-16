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
	cout << "2. Metoda LU" << endl;
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
		gaus->performOperation();
		gaus->checkConsistency();
		gausOptions();


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
	cout << "==== METODA LU ===" << endl;
	cout << "1. Wpisz wartosci macierzy" << endl;
	cout << "2.	Wyswietl wyniki" << endl;

	cin >> operation;
	switch (operation)
	{
	case 1:
	{
		system("CLS");
		lu->lu_results();
		luOptions();

	}
	break;
	case 2:
	{
		system("CLS");
		lu->decomposition();
		luOptions();
	}
	break;
	case 3:
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
void Menu::menu()
{
	options();
	cin >> operation;
	switch (operation)
	{
	case 1:
	{
		system("CLS");
		gausOptions();
	}
	break;
	case 2:
	{
		system("CLS");
		luOptions();
	}
	break;
	case 3:
	{
		exit(0);
	}
	break;
	default:
	{
		cout << endl << "Brak takiej operacji" << endl;
		system("CLS");
		menu();

	}
	break;
	}

}