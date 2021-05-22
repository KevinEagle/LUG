#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <vector>

using namespace std;
class Lu
{
private:
	int n; // matrix size
	float ** tab_lu;

public:
	Lu();
	~Lu();
	void decomposition();
	void initMatrix();
	void fillMatrix();
	void printMatrix();
	void loadFromFile(string);

};

