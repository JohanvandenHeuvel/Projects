#include "../../std_lib_facilities.h"

int main()
{
	char first_char = ' ';
	char second_char = ' ';
	char terminate = '|';

	cout << "Terminate with |";

	while (first_char != terminate && second_char != terminate)
	{
		cout << "Enter two numbers (followed by 'enter):\n";
		cin >> first_char >> second_char;
		
		int first_int = first_char - 48;
		int second_int = second_char - 48;
		cout << "First number " << first_int << ", second number " << second_int << '\n';
	}
	return 0;
}