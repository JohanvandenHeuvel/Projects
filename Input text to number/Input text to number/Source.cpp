#include "../../std_lib_facilities.h";

int main()
{
	cout << "Pleae, enter a spelled-out number like 'zero' (followed by 'enter'):\n";
	string number;
	cin >> number;

	if (number == "zero") cout << "The number is 0\n";
	else if (number == "one") cout << "The number is 1\n";
	else if (number == "two") cout << "The number is 2\n";
	else if (number == "three") cout << "The number is 3\n";
	else if (number == "four") cout << "The number is 4\n";
	else cout << "not a number I know";

	keep_window_open();
	return 0;
}