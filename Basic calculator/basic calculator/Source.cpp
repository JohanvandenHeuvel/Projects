#include "../../std_lib_facilities.h"

int main()
{
	cout << "Enter first number:\n";
	double number_1;
	cin >> number_1;

	cout << "Enter second number:\n";
	double number_2;
	cin >> number_2;

	cout << "Enter a operation (*,/,+,-):\n";
	char operation;
	cin >> operation;

	if (operation == '*')
		cout << "the product of " << number_1 << " and " << number_2 << " is " << number_1*number_2 << "\n";
	else if (operation == '/')
		cout << "the division of " << number_1 << " and " << number_2 << " is " << number_1 / number_2 << "\n";
	else if (operation == '+')
		cout << "the sum of " << number_1 << " and " << number_2 << " is " << number_1 + number_2 << "\n";
	else if (operation == '-')
		cout << "the subtraction of " << number_1 << " and " << number_2 << " is " << number_1 - number_2 << "\n";
	else
		cout << "I do not know that operation yet";

	keep_window_open();
	return 0;
}