#include "../../std_lib_facilities.h"

int main()
{
	vector<string> names;
	vector<int> scores;
	string input_string;
	string input;
	int input_int;

	do
	{
		cout << "Enter a name and a score (seperated by 'space): ";
		cin >> input_string >> input_int;
		for (int i = 0; i < names.size(); i++)
			if (input_string == names[i]) {
				cout << "Error";
				return 0;
			}
		if (input_string != "NoName" && input_int != 0) {
			names.push_back(input_string);
			scores.push_back(input_int);
		}		
	} while (input_string != "NoName" && input_int != 0);

	for (int i = 0; i < names.size(); i++)
		cout << names[i] << " " << scores[i] << '\n';

	keep_window_open();
	return 0;
}