#include "../../std_lib_facilities.h"

int main()
{
	cout << "Enter a interger (followed by 'enter'):\n";
	int val1;
	cin >> val1;

	cout << "Enter a interger (followed by 'enter'):\n";
	int val2;
	cin >> val2;

	if (val1 < val2) cout << "The first interger is smaller then the second integer\n";
	else cout << "The second interger is smaller then the first integer\n";

	int sum = val1 + val2;
	cout << "The sum of the intergers is " << sum << '\n';

	int difference = val1 - val2;
	cout << "The difference of the intergers is " << difference << '\n';

	int product = val1 * val2;
	cout << "The product of the intergers is " << product << '\n';

	int ratio = val1 / val2;
	cout << "The ratio of the intergers is " << ratio << '\n';

	keep_window_open();
	return 0;
} 