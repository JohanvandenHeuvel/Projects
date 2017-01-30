#include "../../std_lib_facilities.h"

int main()
{
	cout << "How many names do you want to enter:";
	int size;
	cin >> size;
	if (size <= 0)
		return 1;
	vector<string> name;
	string input_string;
	for (int i = 0; i < size; i++)
	{
		cout << "Enter a name:";
		cin >> input_string;
		name.push_back(input_string);
	}

	vector<double> age(name.size());
	double input_age;
	for (int i = 0; i < name.size(); i++) {
		cout << "Enter the age of " << name[i] << ":";
		cin >> input_age;
		age[i] = input_age;
	}
	
	cout << endl << "Not sorted:" <<endl;
	for (int i = 0; i < name.size(); i++) {
		cout << name[i] << " " << age[i] << endl;
	}

	vector<string> name_notsorted = name;
	vector<double> age_notsorted = age;
	sort(name.begin(), name.end());
	for (int i = 0; i < name.size(); i++)
		for (int ii = 0; ii < name.size(); ii++){
			if (name[i] == name_notsorted[ii])
				age[i] = age_notsorted[ii];
	}

	cout << endl << "sorted:" << endl;
	for (int i = 0; i < name.size(); i++) {
		cout << name[i] << " " << age[i] << endl;
	}
	
	keep_window_open();
	return 0;
}