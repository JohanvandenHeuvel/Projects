#include "../../std_lib_facilities.h"

int main()
{
	cout << "Enter a number to see if it is odd or not (followed by 'enter):\n";
	int val1;
	cin >> val1;

	if (val1 % 2 == 0) cout << "The number " << val1 << " is an even number\n";
	else cout << "The number " << val1 << " is an odd number\n";

	keep_window_open();
	return 0;
}     