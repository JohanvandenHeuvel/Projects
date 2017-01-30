#include "../../std_lib_facilities.h"

int main()
{
	
	//string input_1 = " ";
	//string input_2 = " ";
	string input = " ";

	string unit = " ";
	string meter = "m";
	string centimeter = "cm";
	string inch = "in";
	string feet = "ft";
	//double number_1 = 0;
	//double number_2 = 0;
	double number = 0;

	double smallest = 0;
	double largest = 0;
	double sum = 0;
	vector<double> all_entries;
	int entries = 0;

	string exit = "|";
	
	do
	{
		cout << "Enter a number followed by a unit ('m','cm','in','ft') seperated by space (followed by 'enter', '|' to exit):\n";
		//cin >> input_1 >> input_2;
		cin >> input >> unit;

		//number_1 = atof(input_1.c_str());
		//number_2 = atof(input_2.c_str());
		number = atof(input.c_str());
		//cout << number_1 << ", " << number_2;
		if (unit == "km" || input == "y") {
			cout << unit << " is not accepted as a legal unit\n";
			input = exit; 
			unit = exit;
			break;
		}
		else {
			if (unit == centimeter)
				number /= 100;
			else if (unit == inch)
				number *= (2.54 / 100);
			else if (unit == feet)
				number *= (12 * 2.54 / 100);
		}

		if (smallest == 0 && largest == 0 && input != exit && unit != exit) {
			smallest = number;
			largest = number;
			cout << number << " meter is the value you entered\n";
		}
		else if (input != exit && unit != exit) {
			if (number < smallest) {
				cout << number << " meter the smallest so far\n";
				smallest = number;
			}
			else if (number > largest) {
				cout << number << " meter the largest so far\n";
				largest = number;
			}
			else
				cout << number << " meter is the value you entered\n";
		}
		
		if (input != exit && unit != exit) {
			entries++;
			all_entries.push_back(number);
			sum += number;
		}

		
		//if (number_1 == number_2)
		//	cout << "\nthe numbers are equal\n";
		//else if (number_1 - number_2 <= (1.0 / 100))
		//	cout << "\nthe numbers are almost equal\n";
		//else {
		//	if (number_1 < number_2)
		//		cout << "\nthe smaller value is " << number_1 << ", the larger value is " << number_2 << "\n";
		//	else
		//		cout << "\nthe smaller value is " << number_2 << ", the larger value is " << number_1 << "\n";
		//}
			
	//} while (input_1 != exit && input_2 != exit);
	} while (input != exit && unit != exit);
	cout << sum << " is total amount of meters entered with " << largest << " as largest and " << smallest << " as smallest in " << entries << " entries\n";
	
	sort(all_entries);
	for (double number : all_entries)
		cout << number << "\n";

	keep_window_open();
	return 0;  
}