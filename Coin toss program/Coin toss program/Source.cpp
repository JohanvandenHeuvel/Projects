#include "../../std_lib_facilities.h"

int main()
{
	const int heads = 0;
	const int tails = 1;
	int random_number;
	srand(time(NULL));
	
	for (int i = 1; i <= 100; i++) {
		random_number = rand() % 2;
		if (random_number == 1) {
			cout << "1";
		}
		if (random_number == 0) {
			cout << "0";
			}
	}
	cout << endl;
	keep_window_open();
	return 1;
}