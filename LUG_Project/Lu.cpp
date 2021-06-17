#include "pch.h"
#include "Lu.h"



Lu::Lu()
{
}

Lu::~Lu() //destruktor
{
	for (int i = 0; i < n; i++) {
		delete[] tab_lu[i];
	}
	delete[] tab_lu;
}
void Lu::decomposition()
{
	float ** l;
	float ** u;

	l = new float*[n];
	u = new float*[n];
	for (int i = 0; i < n; i++)
	{
		l[i] = new float[n];
		u[i] = new float[n];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j < i)
				l[j][i] = 0;
			else
			{
				l[j][i] = tab_lu[j][i];
				for (int k = 0; k < i; k++)
				{
					l[j][i] = l[j][i] - l[j][k] * u[k][i];
				}
			}
		}
		for (int j = 0; j < n; j++)
		{
			if (j < i)
				u[i][j] = 0;
			else if (j == i)
				u[i][j] = 1;
			else {
				u[i][j] = tab_lu[i][j] / l[i][i];
				for (int k = 0; k < i; k++)
				{
					u[i][j] = u[i][j] - ((l[i][k] * u[k][j]) / l[i][i]);
				}
			}
		}
	}

	cout << "Wyglad macierzy po dekompozycji czesci L: " << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
		{
			cout << l[i][j] << " ";
		}
		cout << endl;
	}
	cout << "Wyglad macierzy po dekompozycji czesci U: " << endl;
	for (int i = 0; i < n; i++)
	{


		for (int j = 0; j < n; j++)
		{
			cout << u[i][j] << " ";
		}
		cout << endl;
	}


	for (int i = 0; i < n; i++)
	{
		delete[] l[i];
		delete[] u[i];
	}
	delete[] l;
	delete[] u;

}

void Lu::initMatrix() //jest
{
	cout << "Wpisz wielkosc macierzy" << endl;
	cin >> n;
	tab_lu = new float*[n];
	for (int i = 0; i < n; i++) {
		tab_lu[i] = new float[n];
	}
}

void Lu::fillMatrix() //jest
{
	cout << "Wpisz wartosci macierzy: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "Kolumna " << i << endl;
		for (int j = 0; j < n; j++)
		{
			cout << "Wiersz" << j;
			cin >> tab_lu[i][j];
		}
	}
}

void Lu::printMatrix() //jest
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << tab_lu[i][j] << " ";
		cout << endl;
	}
}

void Lu::loadFromFile(string name)
{
	ifstream file;
	name += ".txt";
	file.open(name);

	if (!file.good())
	{
		cout << "Nie ma takiego pliku." << endl;
	}

	file >> n;

	tab_lu = new float*[n];
	for (int i = 0; i < n; i++)
	{
		tab_lu[i] = new float[n];
	}


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			file >> tab_lu[i][j];

		}
	}

	file.close();
}