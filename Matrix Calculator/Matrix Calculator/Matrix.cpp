#include "Matrix.h"

Matrix::Matrix()
	:matrix{}
{
}

Matrix::Matrix(vector< vector<int> > matrix)
	: matrix{matrix}
{
}

void Matrix::fillMatrix() //prompt the user to fill the matrix
{
	int rowEntry, colEntry;
	cout << "Enter amount of rows of matrix: ";
	cin >> rowEntry;
	cout << "Enter amount of collums of matrix: ";
	cin >> colEntry;

	for (int row = 0; row < rowEntry; row++)
	{
		vector<int> temp;
		cout << "Enter the row " << row + 1 << ":";
		for (int col = 0; col < colEntry; col++)
		{
			int entry;
			cin >> entry;
			temp.push_back(entry);
		}
		matrix.push_back(temp);
	}
}

Matrix gaussianElimination(const Matrix& m1, const Matrix& m2)
{
	return m1;
}

Matrix inverse(const Matrix& m1) //gauss elimination with Idendity matrix
{
	vector< vector<int> > idendityMatrix;

	for (int row = 0; row < m1.sizeRow(); row++)
	{
		vector<int> temp;
		for (int col = 0; col < m1.sizeCol(row); col++)
			if (col == row)
				temp.push_back(1);
			else
				temp.push_back(0);
		idendityMatrix.push_back(temp);
	}
	
	Matrix m2 = idendityMatrix;

	//----------------------------------------------------
	
	vector< vector<int> > result;

	vector<int> temp;

	//----------------------------------------------------

	return m2; //m1 goes to reduced echolon form
}

Matrix operator+(const Matrix& m1, const Matrix& m2)
{
	if (m1.sizeRow() != m2.sizeRow())
		error("matrix's not the same size");
	for(int row = 0; row < m1.sizeRow(); row++)
		if (m1.sizeCol(row) != m2.sizeCol(row))
			error("matrix's not the same size");

	vector< vector<int> > result;
	
	for (int row = 0; row < m1.sizeRow(); row++)
	{
		vector<int> temp;
		for (int col = 0; col < m1.sizeCol(row); col++)
		{
			temp.push_back(m1.get(row,col) + m2.get(row, col));
		}
		result.push_back(temp);
	}

	return result;
}

Matrix operator-(const Matrix& m1, const Matrix& m2)
{
	if (m1.sizeRow() != m2.sizeRow())
		error("matrix's not the same size");
	for (int row = 0; row < m1.sizeRow(); row++)
		if (m1.sizeCol(row) != m2.sizeCol(row))
			error("matrix's not the same size");

	vector< vector<int> > result;

	for (int row = 0; row < m1.sizeRow(); row++)
	{
		vector<int> temp;
		for (int col = 0; col < m1.sizeCol(row); col++)
		{
			temp.push_back(m1.get(row, col) - m2.get(row, col));
		}
		result.push_back(temp);
	}

	return result;
}

Matrix operator*(const Matrix& m1, const Matrix& m2) //??
{
	for (int row = 0; row < m1.sizeRow(); row++)
		if (m1.sizeRow() != m2.sizeCol(row))
			error("matrix's not the same size");

	vector< vector<int> > result;
	for (int row = 0; row < m1.sizeRow(); row++)
	{
		vector<int> temp;
		for (int col = 0; col < m2.sizeCol(1); col++)
		{
			int sum = 0;
			for (int i = 0; i < m1.sizeRow(); i++)
			{
				sum += (m1.get(row, i) * m2.get(i, col));
			}
			temp.push_back(sum);
		}
		result.push_back(temp);
	}
	
	return result;
}

Matrix operator*(const int c,const Matrix& m2) //scalar multiplication
{
	vector< vector<int> > result;

	for (int row = 0; row < m2.sizeRow(); row++)
	{
		vector<int> temp;
		for (int col = 0; col < m2.sizeCol(row); col++)
		{
			temp.push_back(c * m2.get(row, col));
		}
		result.push_back(temp);
	}

	return result;
}

Matrix operator/(const Matrix& m1, const Matrix& m2) //??
{
	return m1;
}

ostream& operator<<(ostream& os, const Matrix& m)
{
	for (int row = 0; row < m.sizeRow(); row++)
	{
		for (int col = 0; col < m.sizeCol(row); col++)
		{
			os << m.get(row,col) << " ";
		}
		os << '\n';
	}
	return os;
}