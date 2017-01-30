#include "../../std_lib_facilities.h"

int main()
{
	string exit = "|";
	string input = " ";
	int input_int = 0;
	vector<string> numbers = { "zero","one","two","three","four","five","six","seven","eight","nine" };

	do
	{
		cout << "Enter a number to spell it out, or enter a spelled out number to get its digit('|' to exit):\n";
		cin >> input;
		if (input != exit) {
			for (int i = 0; i < numbers.size(); i++)
			{
				if (input == numbers[i])
					cout << i << '\n';
			}

			stringstream convert(input); // stringstream used for the conversion initialized with the contents of input

			if (!(convert >> input_int))
				input_int = 0;
			else
				cout << numbers[input_int] << '\n';	
		}
	} while (input != exit);
}