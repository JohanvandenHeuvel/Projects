#include "../../std_lib_facilities.h"

int main()
{	
	cout << "--Lowercase--\n";
	for (int i = 0; i < 26; i++) 
	{
		char valchar_lowercase = 'a' + i;
		int valint_lowercase = valchar_lowercase;
		cout << valchar_lowercase << "..." << valint_lowercase << '\n';
	}

	cout << "\n--Uppercase--\n";
	for (int i = 0; i < 26; i++) 
	{
		char valchar_uppercase = 'A' + i;
		int valint_uppercase = valchar_uppercase;
		cout << valchar_uppercase << "..." << valint_uppercase << '\n';
	}

	cout << "\n--Digits--\n";
	for (int i = 0; i <= 9; i++) 
	{
		char valchar_digit = '0' + i;
		int valint_digit = valchar_digit;
		cout << valchar_digit << "..." << valint_digit << '\n';
	}
	
	keep_window_open();
	return 0;
}
