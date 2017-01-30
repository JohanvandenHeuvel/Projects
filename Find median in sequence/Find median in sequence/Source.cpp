#include "../../std_lib_facilities.h"

int main()
{
	vector<double> temps;

	cout << "Enter temperature\n";
	for (double temp; cin >> temp;)
		temps.push_back(temp);

	sort(temps);
	double median = 0;

	for (double temp : temps)
		cout << temp << '\n';

	if (temps.size() % 2 == 0) {
		double temp_1 = temps[0.5*temps.size()-1];
		double temp_2 = temps[0.5*temps.size()];

		median = (temp_1 + temp_2) / 2;
		cout << median << " is the median\n";
	}
	else if (temps.size() % 2 != 0) {
		median = temps[(temps.size() - 1) / 2];
		cout << median << " is the median\n";
	}
	keep_window_open();
	return 0;
}