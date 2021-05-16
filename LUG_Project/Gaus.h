#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <vector>

using namespace std;
class Gaus
{
private:
	float **tab;
	int numberOfRows;
	int numberOfColumns;

public:
	Gaus();
	~Gaus();
	void initMatrix();
	void fillMatrix();
	void printMatrix();
	int performOperation(int);
	int checkConsistency(int, int);
	void printResult(int, int);
	void loadFromFile(string);
};

