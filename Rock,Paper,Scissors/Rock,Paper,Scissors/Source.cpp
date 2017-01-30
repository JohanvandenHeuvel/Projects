#include  "../../std_lib_facilities.h"

int main()
{
	srand(time(NULL));
	int move = 0;

	cout << "rock, paper or scissors?\n";
	string input = " ";
	string exit = "|";

	do
	{
		cin >> input;
		move = rand() % 3 + 1;
		
		switch (move)
		{
			case 1: {	//1 is rock
				if (input == "paper")
					cout << "you win!\n";
				if (input == "scissors")
					cout << "you lose!\n";
				break;
			}

			case 2: {	//2 is paper
				if (input == "scissors")
					cout << "you win!\n";
				if (input == "rock")
					cout << "you lose!\n";
				break;
			}

			case 3: {	//3 is scissors
				if (input == "rock")
					cout << "you win!\n";
				if (input == "paper")
					cout << "you lose!\n";
				break;
			}
		}
		
	} while (input != exit);
}