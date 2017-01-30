#include "../../std_lib_facilities.h"

int main()
{
	cout << "Enter miles to be converted to kilometers (followed by 'enter'):\n";
	int miles;
	cin >> miles;
	int kilometers;
	kilometers = 1.609 * miles;
	cout << miles << " Miles converted to kilometers is " << kilometers << "kilometers\n";

	keep_window_open();
	return 0;
}