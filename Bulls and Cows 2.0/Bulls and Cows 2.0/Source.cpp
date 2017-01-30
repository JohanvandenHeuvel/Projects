#include "../../std_lib_facilities.h"

//------------------------------------------------------------------------------

vector<char> guess = { ' ',' ',' ',' ' };
class Input_to_high {};
class Input_not_valid {};

//------------------------------------------------------------------------------

int Cows(vector<char> numbers, vector<char> guess)
{
	int Cows = 0;

	for (int i = 0; i < numbers.size(); i++)
		for (int j = 0; j < numbers.size(); j++)
			if (guess[i] == numbers[j])
				Cows++;

	return Cows;
}

//------------------------------------------------------------------------------

int Bulls(vector<char> numbers, vector<char> guess)
{

	int Bulls = 0;

	for (int i = 0; i < numbers.size(); i++)
		if (guess[i] == numbers[i])
			Bulls++;

	return Bulls;
}

//------------------------------------------------------------------------------

bool check_guess(vector<char> guess)
{
	for (int i = 0; i < guess.size(); i++)
		if (guess[i] < 97 || guess[i] > 122)
			return true;
		else return false;
}

//------------------------------------------------------------------------------

vector<char> Make_random()
{
	srand(time(NULL));
	char char_1, char_2, char_3, char_4;
	int number_1, number_2, number_3, number_4;

	do	// make random number
	{
		number_1 = 'a' + rand() % 26;
		number_2 = 'a' + rand() % 26;
		number_3 = 'a' + rand() % 26;
		number_4 = 'a' + rand() % 26;
	} while (number_1 == number_2 || //numbers cannot match
		number_1 == number_3 ||
		number_1 == number_4 ||
		number_2 == number_3 ||
		number_2 == number_4 ||
		number_3 == number_4);

	char_1 = number_1;
	char_2 = number_2;
	char_3 = number_3;
	char_4 = number_4;

	vector<char> random = { char_1,char_2,char_3,char_4 };
	vector<char> guess = { ' ',' ',' ',' ' };
	return random;
}

//------------------------------------------------------------------------------

vector<char> Make_guess()
{
	cout << "guess 4 letters:"; // make user guess

	char input_1, input_2, input_3, input_4;

	cin >> input_1 >> input_2 >> input_3 >> input_4;

	guess = { input_1,input_2,input_3,input_4 };

	if (check_guess(guess))
		throw Input_not_valid{};

	return guess;
}

//------------------------------------------------------------------------------

void Bulls_and_Cows()
{
	vector<char> random  = Make_random();

	for (int i = 0; i < random.size(); i++)
		cout << random[i];
	cout << '\n';

	while (Bulls(random, guess) != 4)
	{
		guess = Make_guess();
		cout << Bulls(random, guess) << " letters op de juiste plek\n" << Cows(random, guess) << " letters niet op de juiste plek\n\n";  //bulls is juiste plek + juiste letter, cows is juiste letter
	}
	if (Bulls(random, guess) == 4)
		cout << "You won!\n";
}

//------------------------------------------------------------------------------

int main()
try {
	Bulls_and_Cows();

	keep_window_open();
	return 0;
}
catch (Input_not_valid) {
	cout << "Error: Input is not valid\n";
	keep_window_open();
	return 1;
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

//------------------------------------------------------------------------------