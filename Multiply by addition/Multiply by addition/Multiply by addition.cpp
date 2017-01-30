// Multiply by addition.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../../std_lib_facilities.h"

int multiply(int a, int b)
{
	int ab = 0;
	for (int i = b; i > 0; i--)
	{
		ab += a;
	}
	return ab;
}

int main()
{
	cout << (int)'9' << '\n';
	cout << (int)'A' << '\n';
	keep_window_open();
    return 0;
}

