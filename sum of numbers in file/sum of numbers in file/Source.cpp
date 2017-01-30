#include "../../std_lib_facilities.h"

int main()
try {
	
	string file_name = "intergers.txt";
	ifstream ifs{ file_name };
	if (!ifs) error("file didnt open correctly");

	vector<int> readings;
	int x;
	while (ifs >> x)
		readings.push_back(x);

	ifs.close();

	int sum = 0;
	for (int x : readings)
		sum += x;

	cout << "sum of values in " << file_name << " = " << sum << endl;

	keep_window_open();
	return 1;
}
catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
}
catch (...) {
	cerr << "exception\n";
}