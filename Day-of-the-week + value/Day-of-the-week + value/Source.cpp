#include "../../std_lib_facilities.h"

class day_unknown{};

void Print_vector(vector<int> day)
{
	for (int i = 0; i < day.size(); i++)
	{
		cout << day[i] << " ";
	}
	cout << "\n";
}

int main()
try{
	vector<int> Sunday;
	vector<int> Monday;
	vector<int> Tuesday;
	vector<int> Wednesday;
	vector<int> Thursday;
	vector<int> Friday;
	vector<int> Saturday;

	string input_day;
	int input_val;
	cout << "Enter a day followed by a value seperated by space:\n";
	while (cin >> input_day >> input_val)
		if (input_day == "Sunday")
			Sunday.push_back(input_val);
		else if (input_day == "Monday")
			Monday.push_back(input_val);
		else if (input_day == "Tuesday")
			Tuesday.push_back(input_val);
		else if (input_day == "Wednesday")
			Wednesday.push_back(input_val);
		else if (input_day == "Thursday")
			Thursday.push_back(input_val);
		else if (input_day == "Friday")
			Friday.push_back(input_val);
		else if (input_day == "Saturday")
			Saturday.push_back(input_val);
		else
			day_unknown{};

	cout << "Sunday: "		; Print_vector(Sunday);
	cout << "Monday: "		; Print_vector(Monday);
	cout << "Tuesday: "		; Print_vector(Tuesday);
	cout << "Wednesday: "	; Print_vector(Wednesday);
	cout << "Thursday: "	; Print_vector(Thursday);
	cout << "Friday: "		; Print_vector(Friday);
	cout << "Saturday: "	; Print_vector(Saturday);

	keep_window_open();
	return 0;
}
catch(day_unknown){
	cout << "Error: day_unknown\n";
	keep_window_open();
	return 1;
}
catch (exception& e) {
	cout << e.what() << '\n';
	keep_window_open();
	return 2;
}
catch (...) {
	cout << "Error unknown\n";
	keep_window_open();
	return -1;
}