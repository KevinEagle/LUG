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
	int i, j, n;

public:
	Lu();
	~Lu();
	void decomposition(float a[10][10], float l[10][10], float u[10][10], int n);
	void lu_results();
	void lu_input(int, int, int);

};

