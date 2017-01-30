#include "../../std_lib_facilities.h"

class Input_to_high {};

int Cows(vector<int> numbers, vector<int> guess)
{
	int Cows = 0;

	for (int i = 0; i < numbers.size(); i++)
			for (int j = 0; j < numbers.size(); j++)
				if (guess[i] == numbers[j])
					Cows++;
	
	return Cows;
}

int Bulls(vector<int> numbers, vector<int> guess)
{
	
	int Bulls = 0;
	
	for (int i = 0; i < numbers.size(); i++)
		if (guess[i] == numbers[i])
			Bulls++;
	
	return Bulls;
}

void Bulls_and_Cows()
{
	srand(time(NULL));
	int number_1, number_2, number_3, number_4;

	do	// make randon number
	{
		number_1 = rand() % 9;
		number_2 = rand() % 9;
		number_3 = rand() % 9;
		number_4 = rand() % 9;
	} while (number_1 == number_2 || //numbers cannot match
		number_1 == number_3 ||
		number_1 == number_4 ||
		number_2 == number_3 ||
		number_2 == number_4 ||
		number_3 == number_4);

	vector<int> numbers = { 0,0,0,0 };
	numbers = { number_1,number_2,number_3,number_4 };
	vector<int> guess = { 0,0,0,0 };
	
	
	while (Bulls(numbers,guess) != 4)
	{
		cout << "\nguess a number: "; // make user guess
		int input;
		cin >> input;
		if (input > 9999)
			throw Input_to_high{};

		int input_1, input_2, input_3, input_4;

		input_4 = input % 10;
		input /= 10;
		input_3 = input % 10;
		input /= 10;
		input_2 = input % 10;
		input /= 10;
		input_1 = input % 10;

		guess = { input_1,input_2,input_3,input_4 };

		cout << Bulls(numbers, guess) << " Bulls\n" << Cows(numbers, guess) << " Cows\n";
	}
	if (Bulls(numbers, guess) == 4)
		cout << "You won!\n";
}

int main()
try {
	Bulls_and_Cows();

	keep_window_open();
	return 0;
}
catch (Input_to_high) {
	cout << "Error: you entered to much numbers\n";
	keep_window_open();
	return 1;
}
catch (exception& e) {
	cout << e.what() << "\n";
	keep_window_open();
	return 2;
}
catch (...) {
	cout << "Unknow error\n";
	keep_window_open();
	return -1;
}