#include "../../std_lib_facilities.h"

int main()
{
	constexpr double yen_per_dollar = 102.25;
	constexpr double kroner_per_dollar = 6.70;
	constexpr double pounds_per_dollar = 0.73;

	double amount = 1;
	char currency = ' ';

	cout << "Please enter a amount of dollars followed by which currency (yen 'y', kroner 'k', pounds 'p'):\n";
	cin >> amount >> currency;

	switch (currency)
	{
	case 'y': cout << amount << " dollar == " << amount*yen_per_dollar << " yen\n"; break;
	case 'k': cout << amount << " dollar == " << amount*kroner_per_dollar << " kroner\n"; break;
	case 'p': cout << amount << " dollar == " << amount*pounds_per_dollar << " pounds\n"; break;
	default: cout << "Sorry, I don't know a currency called'" << currency << "'\n";
		break;
	}

	keep_window_open();
	return 0;
}