#include "pch.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <iomanip> 
#include <string>
#include <windows.h> 
#include "Gaus.h"
#include "Menu.h"
#include "Lu.h"

using namespace std;
int main()
{
	Menu *main_menu = new Menu();
	//Lu* LU = new Lu();

	//Gaus *gaus = new Gaus();
	//gaus->initMatrix();
	//gaus->fillMatrix();
	//gaus->printMatrix();
	//// order of matrix(n)
	//int n = 4, flag = 0;
	//flag = gaus->performOperation(n);
	//// performing matrix transformation
	//if (flag == 1)
	//	flag = gaus->checkConsistency(n, flag);

	//// printing final matrix
	//cout << "final augumented matrix is : " << endl;
	//gaus->printMatrix();
	//cout << endl;

	//// printing solutions(if exist)
	//gaus->printResult(n, flag);

	main_menu->menu();

	delete main_menu;
	system("PAUSE");
	return 0;
}