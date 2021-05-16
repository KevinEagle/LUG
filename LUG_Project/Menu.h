#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include "Gaus.h"
#include "Lu.h"


using namespace std;
class Menu
{
private:
	int operation;
	string file;
	Gaus *gaus;
	Lu *lu;

public:
	Menu();
	~Menu();
	void options();
	void gausOptions();
	void luOptions();
	void menu();
};

