#include "pch.h"
#include "Lu.h"



Lu::Lu()
{
}

Lu::~Lu() //destruktor
{
	for (int i = 0; i < numberOfRows; i++) {
		delete[] tab_lu[i];
	}
	delete[] tab_lu;
}
void Lu::decomposition(float a[10][10], float l[10][10], float u[10][10], int n)
{
	{
		int i = 0, j = 0, k = 0;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				if (j < i)
					l[j][i] = 0;
				else
				{
					l[j][i] = a[j][i];
					for (k = 0; k < i; k++)
					{
						l[j][i] = l[j][i] - l[j][k] * u[k][i];
					}
				}
			}
			for (j = 0; j < n; j++)
			{
				if (j < i)
					u[i][j] = 0;
				else if (j == i)
					u[i][j] = 1;
				else {
					u[i][j] = a[i][j] / l[i][i];
					for (k = 0; k < i; k++) {
						u[i][j] = u[i][j] - ((l[i][k] * u[k][j]) / l[i][i]);
					}
				}
			}
		}
	}
	cout << "Wyglad macierzy po dekompozycji czesci L: " << endl;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			cout << l[i][j] << " ";
		}
		cout << endl;
	}
	cout << "Wyglad macierzy po dekompozycji czesci U: " << endl;
	for (i = 0; i < n; i++) {


		for (j = 0; j < n; j++) {
			cout << u[i][j] << " ";
		}
		cout << endl;
	}
	return;

}

//void Lu::lu_results() {
	//float a[10][10], l[10][10], u[10][10];
	//int n = 0, i = 0, j = 0;

	///*decomposition(a, l, u, n);
	//cout << "Wyglad macierzy po dekompozycji czesci L: " << endl;
	//for (i = 0; i < n; i++) {
	//	for (j = 0; j < n; j++) {
	//		cout << l[i][j] << " ";
	//	}
	//	cout << endl;
	//}
	//cout << "Wyglad macierzy po dekompozycji czesci U: " << endl;
	//for (i = 0; i < n; i++) {


	//	for (j = 0; j < n; j++) {
	//		cout << u[i][j] << " ";
	//	}
	//	cout << endl;
	//}
	//return;*/
//}


//void Lu::lu_input()
//{
//
//	int * tab_1 = new int*[i];
//	//int n = 0, i = 0, j = 0;
//
//	cout << "Prosze wpisac wielkosc macierzy : " << endl;
//	cin >> n;
//
//	cout << "Prosze wpisac wartosci macierzy kolumnami: " << endl;
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < n; j++)
//		{
//			cin >> a[i][j];
//		}
//
//	}
//
//
//	return;
//}

void Lu::initMatrix() //jest
{
	cout << "Wpisz ilosc wierszy" << endl;
	cin >> numberOfRows;
	cout << "Wpis ilosc kolumn" << endl;
	cin >> numberOfColumns;
	tab_lu = new float* [numberOfRows];
	for (int i = 0; i < numberOfRows; i++) {
		tab_lu[i] = new float[numberOfColumns];
	}
}

void Lu::fillMatrix() //jest
{
	cout << "Wpisz wartosci macierzy: " << endl;
	for (int i = 0; i < numberOfRows; i++)
	{
		cout << "Kolumna " << i << endl;
		for (int j = 0; j < numberOfColumns; j++)
		{
			cout << "Wiersz" << j;
			cin >> tab_lu[i][j];
		}
	}
}

void Lu::printMatrix() //jest
{
	for (int i = 0; i < numberOfRows; i++) {
		for (int j = 0; j <= numberOfColumns; j++)
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

	file >> numberOfRows;
	file >> numberOfColumns;

	tab_lu = new float* [numberOfRows];
	for (int i = 0; i < numberOfRows; i++)
	{
		tab_lu[i] = new float[numberOfColumns];
	}


	for (int i = 0; i < numberOfRows; i++)
	{
		for (int j = 0; j < numberOfColumns; j++)
		{
			file >> tab_lu[i][j];

		}
	}

	file.close();
}