#include "../../std_lib_facilities.h"

int main()
{
	unsigned long long rice = 1;

	cout << "How many squares;\n";
	int squares;
	cin >> squares;

	for (int i = 1; i <= squares; i++) {		
		cout << "rice: " << rice << " for " << i << " squares\n";
		rice *= 2;
	}

	keep_window_open();
	return 0;	
}