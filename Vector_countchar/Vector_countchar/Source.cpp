#include "../../std_lib_facilities.h"

int count_characters(const string& s)
{
	int val = 0;
	
	for (char c : s)
		val++;

	return val;
}

int min(const vector<int>& s_values)
{
	double lowest = s_values[0];
	for (double x : s_values) {
		if (x < lowest)
			lowest = x;
	}
	return lowest;
}

int max(const vector<int>& s_values)
{
	double highest = s_values[0]; //initialize with first value of vector so with numbers lower then initialed value of highest is not highest
	for (double x : s_values) {
		if (x > highest)
			highest = x;
	}
	return highest;
}

vector<int> number_of_characters(vector<string>& s_vector)
{
	vector<int> s_values;

	for (string s : s_vector) s_values.push_back(count_characters(s));
	s_values.push_back(min(s_values));
	s_values.push_back(max(s_values));

	return s_values;
}

void vector_string_values(vector<string> s_vector)
{
	vector<int> s_values = number_of_characters(s_vector);

	for (int i = 0; i < s_values.size(); i++) {
		if (i <= s_values.size() - 3)
			cout << s_vector[i] << " = " << s_values[i] << endl;
		if (i == s_values.size() - 2)
			cout << endl << "Shortest string: " << s_values[i] << endl;
		if (i == s_values.size() - 1)
			cout << "Longest string: " << s_values[i] << endl;
	}
	sort(s_vector);
	cout << "Lexographicly first: " << s_vector[0] << endl;;
	cout << "Lexographicly last: " << s_vector[s_vector.size() - 1] << endl << endl;
}

int main()
{
	const vector<string> s_vector{"huis","paard","hallo","ok"};
	vector_string_values(s_vector);
	
	keep_window_open();
	return 1;
}