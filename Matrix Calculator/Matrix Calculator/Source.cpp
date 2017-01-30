#include "Matrix.h"
#include <iostream>

int main()
{
	vector< vector<int> > firstMatrix = 
	{
		{3, 2, 1},
		{3, 2, 1},
		{3, 2, 1}
	};

	vector< vector<int> > secondMatrix =
	{
		{ 3, 2, 1 },
		{ 3, 2, 1 },
		{ 3, 2, 1 }
	};

	Matrix m1(firstMatrix);
	Matrix m2(secondMatrix);
	Matrix result = m1 * m2;

	cout << firstMatrix << " multiplied by \n" << secondMatrix << " equals \n" << result;
	keep_window_open();
}