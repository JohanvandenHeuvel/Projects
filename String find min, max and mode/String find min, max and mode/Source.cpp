#include "../../std_lib_facilities.h"

string find_mode(vector<string>set)
{
	string mode = " ";
	int mode_times = 0;		
	int temp = 0;
	string val = " ";

	for (int i = 0; i < set.size(); i++) {
		val = set[i];
		temp = 0;
		for (int ii = 0; ii < set.size(); ii++)
			if (val == set[ii]) {
				temp++;
				if (temp > mode_times) {
					mode = val;
					mode_times = temp;
				}
			}

	}
	return mode;
}

string find_max(vector<string> set)
{
	sort(set);
	string max;
	max = set[set.size() - 1];
	return max;
}

string find_min(vector<string> set)
{
	sort(set);
	string min;
	min = set[0];
	return min;
}


int main()
{
	vector<string> set;
	string val;
	cout << "Enter words to be sorted ('stop' to end the program and see results)\n";

	do
	{
		cin >> val;
		if (val == "stop");
		else
			set.push_back(val);
	} while (val != "stop");

	if (set.size() > 0) {
		cout << "mode is " << find_mode(set) << '\n';
		cout << "max is " << find_max(set) << '\n';
		cout << "min is " << find_min(set) << '\n';
	}
	

	keep_window_open();
	return 0;
}