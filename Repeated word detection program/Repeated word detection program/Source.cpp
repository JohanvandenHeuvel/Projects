#include "../../std_lib_facilities.h"

int main()
{
	string previous = " ";
	string current;
	int repeatedwords = 0;
	while (cin >> current) {
		if (previous == current) {
			cout << "repeated word: " << current << '\n';
			repeatedwords++;
		}	
		previous = current;
		cout << "number of repeated words is " << repeatedwords;
	}
	
}