#include "../../std_lib_facilities.h"

int Next_fibonacci_number(int val1, int val2)
{
	if (val2 == 0)
		val2 = 1;
	int temp = 0;
	temp = val1 + val2;
	return temp;
}

void Print_vector(vector<int> vals)
{
	cout << "1 "; //starts with 1 1
	for (int number : vals)
		cout << number << " ";
}

int main()
try{
	vector<int> fibonacci_series;
	int val1 = 5;
	int val2 = 8;

	for (int i = 0; i < 10; i++) {
		fibonacci_series.push_back(Next_fibonacci_number(val1, val2));
		val1 = fibonacci_series[fibonacci_series.size() - 1];
		if (fibonacci_series.size() > 1)
		val2 = fibonacci_series[fibonacci_series.size() - 2];
	}

	Print_vector(fibonacci_series);

	keep_window_open();
	return 0;
}
catch (exception& e){
	cout << e.what() << '\n';
	keep_window_open();
	return 1;
}