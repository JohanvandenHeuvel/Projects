#include "../../std_lib_facilities.h"

int factorial(int n)
{
	for (int i = n - 1; i > 0; i--)
		n *= i;
	return n;
}

int permutation(int a, int b)
{
	int P;
	P = factorial(a) / factorial(a - b);
	return P;

}

int combination(int a, int b)
{
	int C = 0;
	C = permutation(a, b) / factorial(b);
	return C;
}

int main()
try{
	char input_choice;
	cout << "'P' for permutation\n"
		<< "'C' for combination\n"
		<< "q for quit\n";
	cin >> input_choice;

	int a = 0;
	int b = 0;
	
	switch (input_choice)
	{
	case 'P': {
		cout << "Enter possibilities:";
		cin >> a;
		cout << "Enter amount of choices:";
		cin >> b;
		cout << permutation(a, b) << '\n';
		break;
	}
	case 'C': {
		cout << "Enter possibilities:";
		cin >> a;
		cout << "Enter amount of choices:";
		cin >> b;
		cout << combination(a, b) << '\n';
		break;
	}
	case 'q': {
		return 0;
	}
	default:
		error("input not valid");
	}
	keep_window_open();
	return 0;
}
catch (exception& e){
	cerr << "error: " << e.what() << '\n';
	keep_window_open();
	return 1;
}
catch (...) {
	cerr << "Unknown exception";
	keep_window_open();
	return 2;
}