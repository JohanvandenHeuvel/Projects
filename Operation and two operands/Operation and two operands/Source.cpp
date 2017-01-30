#include "../../std_lib_facilities.h";

int main()
{
	cout << "Enter a operation (followed by 'enter'):\n";
	string operation;
	cin >> operation;

	cout << "Enter first number (followed by 'enter'):\n";
	double val1;
	cin >> val1;

	cout << "Enter second number (followed by 'enter'):\n";
	double val2;
	cin >> val2;

	if (operation == "+") cout << val1 << '+' << val2 << '=' << val1 + val2 << '\n';
	if (operation == "-") cout << val1 << '-' << val2 << '=' << val1 - val2 << '\n';
	if (operation == "*") cout << val1 << '*' << val2 << '=' << val1 * val2 << '\n';
	if (operation == "/") cout << val1 << '/' << val2 << '=' << val1 / val2 << '\n';

	keep_window_open();
	return 0;
}