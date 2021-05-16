#include "pch.h"
#include "Gaus.h"



Gaus::Gaus()
{
}

Gaus::~Gaus()
{
	for (int i = 0; i < numberOfRows; i++) {
		delete[] tab[i];
	}
	delete[] tab;
}

void Gaus::initMatrix() //jest
{
	cout << "Wpisz ilosc wierszy" << endl;
	cin >> numberOfRows;
	cout << "Wpis ilosc kolumn" << endl;
	cin >> numberOfColumns;
	tab = new float *[numberOfRows];
	for (int i = 0; i < numberOfRows; i++) {
		tab[i] = new float[numberOfColumns];
	}
}

void Gaus::fillMatrix() //jest
{
	cout << "Wpisz wartosci macierzy: " << endl;
	for (int i = 0; i < numberOfRows; i++)
	{
		cout << "Kolumna " << i << endl;
		for (int j = 0; j < numberOfColumns; j++)
		{
			cout << "Wiersz" << j;
			cin >> tab[i][j];
		}
	}
}

void Gaus::printMatrix() //jest
{
	for (int i = 0; i < numberOfRows; i++) {
		for (int j = 0; j <= numberOfColumns; j++)
			cout << tab[i][j] << " ";
		cout << endl;
	}
}

int Gaus::performOperation(int n)
{
	int i, j, k = 0, c, flag = 0, m = 0;
	float pro = 0;

	// Performing elementary operations
	for (i = 0; i < n; i++)
	{
		if (tab[i][i] == 0)
		{
			c = 1;
			while ((i + c) < n && tab[i + c][i] == 0)
				c++;
			if ((i + c) == n) {
				flag = 1;
				break;
			}
			for (j = i, k = 0; k <= n; k++)
				swap(tab[j][k], tab[j + c][k]);
		}

		for (j = 0; j < n; j++) {

			// Excluding all i == j
			if (i != j) {

				// Converting Matrix to reduced row
				// echelon form(diagonal matrix)
				float pro = tab[j][i] / tab[i][i];

				for (k = 0; k <= n; k++)
					tab[j][k] = tab[j][k] - (tab[i][k]) * pro;
			}
		}
	}
	return flag;
}

int Gaus::checkConsistency(int n, int flag)
{
	int i, j;
	float sum;

	// flag == 2 for infinite solution
	// flag == 3 for No solution
	flag = 3;
	for (i = 0; i < n; i++)
	{
		sum = 0;
		for (j = 0; j < n; j++)
			sum = sum + tab[i][j];
		if (sum == tab[i][j])
			flag = 2;
	}
	return flag;
}


void Gaus::printResult(int n, int flag)
{
	cout << "Wynik:";

	if (flag == 2)
		cout << "Uklad jest rozwiazywalny" << endl;
	else if (flag == 3)
		cout << "Uklad jest nierozwiazywalny" << endl;


	// Printing the solution by dividing constants by
	// their respective diagonal elements
	else {
		for (int i = 0; i < n; i++)
			cout << tab[i][n] / tab[i][i] << " ";
	}
}

void Gaus::loadFromFile(string name)
{
	ifstream file;
	name += ".txt";
	file.open(name);

	if (!file.good())
	{
		cout << "Nie ma takiego pliku." << endl;
	}

	file >> numberOfRows;
	file >> numberOfColumns;

	tab = new float *[numberOfRows];
	for (int i = 0; i < numberOfRows; i++)
	{
		tab[i] = new float[numberOfColumns];
	}


	for (int i = 0; i < numberOfRows; i++)
	{
		for (int j = 0; j < numberOfColumns; j++)
		{
			file >> tab[i][j];

		}
	}

	file.close();
}
