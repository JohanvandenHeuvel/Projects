#include "../../std_lib_facilities.h"

double Calc_Sum(vector<double> vals, int N)
{
	double Sum = 0;
	for (int i = 0; i < N; i++)
		Sum += vals[i];
	return Sum;
}

void Print_Sum(vector<double> vals, int N)
{
	if (N > vals.size())
		throw out_of_range("out_of_range");
	cout << "The sum of the first "
		<< N
		<< " numbers (";
	for (int i = 0; i < N; i++)
		cout << vals[i] << " ";
	cout << ") is "
		<< Calc_Sum(vals, N) << "\n";
}

int main()
try{
	cout << "Please enter the number of values you want to sum:\n";
	int N; //first N intergers of vector as sum
	cin >> N;

	string input;
	
	cout << "Please enter some intergers (press '|' to stop):\n";
	vector<double> vals;
	double val = 0;
	while (cin >> input) {
		if (input != "|") {
			val = atof(input.c_str());
			vals.push_back(val);
		}
		else
			break;
	}

	Print_Sum(vals, N);

	keep_window_open();
	return 0;
}
catch (exception& e) {
	cout << "Error: " << e.what() << '\n';
	keep_window_open();
	return 1;
}