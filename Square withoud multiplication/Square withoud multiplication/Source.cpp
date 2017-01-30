#include "../../std_lib_facilities.h"

int square(int x)
{
	int result = 0;
	for (int i = 0; i < x; i++)
	{
		result += x;
	}
	return result;
}

int main()
{
	cout << "Enter a number to square (followed by 'enter):\n";
	int x;
	cin >> x;
	cout << square(x) << '\n';

	keep_window_open();
	return 0;
}      