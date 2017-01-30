#include "../../std_lib_facilities.h"

int find_mode(vector<int>set)
{
	int mode = 0;
	int mode_times = 0;
	int temp = 0;
	int val = 0;

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

int main()
{
	vector<int> set;
	for (int val; cin >> val;)
		set.push_back(val);

	 cout << find_mode(set);

	 keep_window_open();
	 return 0;
}