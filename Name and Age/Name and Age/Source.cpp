#include "../../std_lib_facilities.h"

int main()
{
	cout << "Please enter your first and second names\n";
	string first;
	string second;
	cin >> first >> second;

	cout << "Please enter your age\n";
	double age;
	cin >> age;
	age = age * 12;

	cout << "Hello, " << first << " " << second << "(age " << age << " months )\n";
	keep_window_open();
	return 0;
}