#include "../../std_lib_facilities.h"

bool checkPrime(int number)
{
	for (int i = 2; i < number; i++) {
		if (number % i == 0 )
			return false;	
	}
	return true;
}

int main()
{
	vector<int> primes;

	cout << "To what number do you want to know the primes?\n";
	int size;
	cin >> size;

	for (int i = 2; i <= size; i++) { //put primes inside vector
		if (checkPrime(i))
			primes.push_back(i);
	}

	for (int i : primes)
		cout << i << '\n';

	keep_window_open();
	return 0;
}