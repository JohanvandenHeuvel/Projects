#pragma once

#include "../../std_lib_facilities.h"

class Matrix //class that consist of a vector< vector<int> > and standard operations with it
{
	vector< vector<int> > matrix;
public:
	
	const int sizeRow() const { return matrix.size(); }
	const int sizeCol(int row) const { return matrix[row].size(); }
	const int get(int row, int col) const { return matrix[row][col]; }
	const vector< vector<int> > getMatrix() const { return matrix; }

	void fillMatrix(); //prompt the user to fill the matrix
	Matrix gaussianElimination(const Matrix& m1, const Matrix& m2);
	Matrix inverse(const Matrix& m1);

	Matrix();
	Matrix(vector< vector<int> > matrix);
};

ostream& operator<<(ostream& os, const Matrix& m);
Matrix operator+(const Matrix& m1,const Matrix& m2);
Matrix operator-(const Matrix& m1,const Matrix& m2);
Matrix operator*(const Matrix& m1,const Matrix& m2);
Matrix operator*(const int c,const Matrix& m2);
Matrix operator/(const Matrix& m1,const Matrix& m2);
