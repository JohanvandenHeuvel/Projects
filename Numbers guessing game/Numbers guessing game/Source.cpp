#include "../../std_lib_facilities.h"

int main()
{
	int input;
	int input_max;
	int input_min;
	int number_of_guesses = 0;

	cout << "enter a number for the computer to guess and what range\n";
	cout << "number:";
	cin >> input;
	cout << "max:";
	cin >> input_max;
	cout << "min:";
	cin >> input_min;

	srand(time(NULL));

	int guess = 0;
	int max = input_max;
	int min = input_min;

	while (guess != input){
		guess = rand() % max + min;
		if (guess > input)
			max = guess - min;
		if (guess < input)
			min = guess;
		number_of_guesses++;
		cout << "min:" << min << "  max:" << max << "  guess:" << guess << '\n';
	}
	cout << "the program guessed it in: " << number_of_guesses << " guesses\n";
	keep_window_open();
	return 0;
}