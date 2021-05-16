#include "pch.h"
#include "Lu.h"



Lu::Lu()
{
}

Lu::~Lu()
{
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
}

void Lu::lu_results() {
	float a[10][10], l[10][10], u[10][10];
	int n = 0, i = 0, j = 0;

	cout << "Proszê wpisaæ wielkosc macierzy : " << endl;
	cin >> n;

	cout << "Proszê wpisaæ wartosci macierzy: " << endl;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			cin >> a[i][j];
	decomposition(a, l, u, n);
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
