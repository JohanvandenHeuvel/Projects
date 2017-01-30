#include "../../std_lib_facilities.h"

int main()
{
	vector<double> distance;
	cout << "Enter a distance\n";
	for (double val; cin >> val;) {
		distance.push_back(val);
		cout << "Enter another distance\n";
	}

	sort(distance);

	double sum = 0;
	for (double val : distance) {
		sum += val;
	}
	cout << "the sum of all distances is: " << sum << "\n";
	cout << "the smallest distance is: " << distance[0] << "\n";
	cout << "the largest distance is: " << distance[distance.size() - 1] << "\n";
	cout << "the mean distance is :" << sum / distance.size() << "\n";
	keep_window_open();
	return 0;
}