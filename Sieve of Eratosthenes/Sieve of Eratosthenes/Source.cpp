#include "../../std_lib_facilities.h"

#define true 1
#define false 0

void prime_to_max(int max)
{
	vector<int> list;

	for (int i = 0; i <= max; i++)
		list.push_back(true);

	for (int i = 0; i <= max; i++)
		for (int ii = 2; ii <= sqrt(max); ii++)
			if (list[ii] == true)
				for (int j = 1; j <= max; j++)
					if (ii*ii + j*ii == i)
						list[i] = false;

	for (int i = 2; i <= max; i++)
		if (list[i] == true)
			cout << i << " is a prime number\n";
}

bool checkPrime(int number)
{
	for (int i = 2; i < number; i++) {
		if (number % i == 0)
			return false;
	}
	return true;
}

void number_of_primes(int max)
{
	int n = 0; //number of primes
	int i = 2;
	while (n < max)
		if (checkPrime(i)) {
			cout << i << endl;
			n++; i++;
		}
		else
			i++;
		
}

int main()
{
	number_of_primes(100);

	keep_window_open();
	return 0;
}