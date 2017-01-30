#include "../../std_lib_facilities.h"

void output(int number_1, int number_2, char operation)
{
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
}

int input_to_number(string input)
{
	int number = 0;
	vector<string> numbers = { "zero","one","two","three","four","five","six","seven","eight","nine" };
	
	for (int i = 0; i < numbers.size(); i++)
	{
		if (input == numbers[i])
			number = i;
	}

	if (number == 0)
		number = atof(input.c_str());
	return number;
}

int main()
{
	cout << "Enter first number:\n";
	string input_1;
	double number_1 = 0;
	cin >> input_1;

	cout << "Enter second number:\n";
	string input_2;
	double number_2 = 0;
	cin >> input_2;

	cout << "Enter a operation (*,/,+,-):\n";
	char operation;
	cin >> operation;

	number_1 = input_to_number(input_1);
	number_2 = input_to_number(input_2);

	output(number_1, number_2, operation);
	
	keep_window_open();
	return 0;
}
