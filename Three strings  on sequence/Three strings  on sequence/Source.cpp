#include "../../std_lib_facilities.h"

int main()
{
	cout << "Enter the first string (followed by 'enter'):\n";
	string val1;
	cin >> val1;

	cout << "Enter the second string (followed by 'enter'):\n";
	string val2;
	cin >> val2;

	cout << "Enter the third string (followed by 'enter'):\n";
	string val3;
	cin >> val3;

	string temporary;

	if (val2 > val1)
	{
		temporary = val1;
		val1 = val2;
		val2 = temporary;
	}

	if (val3 > val2)
	{
		temporary = val2;
		val2 = val3;
		val3 = temporary;
	}

	if (val2 > val1)
	{
		temporary = val1;
		val1 = val2;
		val2 = temporary;
	}

	cout << val3 << "," << val2 << "," << val1 << '\n';
	keep_window_open();
	return 0;
}