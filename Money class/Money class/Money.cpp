#include "Money.h"

void Currencytable::intitialize_Currencytable()
{
	const Currencytable USD_EUR{ "USD", 0.896145677 ,"EUR" };
	const Currencytable USD_DKK{ "USD", 6.66209203,"DKK" };
	const Currencytable EUR_DKK{ "EUR", 7.43416188, "DKK" };
}


Money::Money(long int entry_cents,string entry_currency)
	:cents{ entry_cents },currency{entry_currency}
{
}

Money::Money()
	:cents{},currency{}
{
}

ostream& operator<<(ostream& os, const Money& a)
{
	return os << a.get_currency() << a.get_cents() / 100.00 << endl;
}

istream& operator >> (istream& is, Money& a)
{
	const string USD = "USD";
	const string DKK = "DKK";
	const string EUR = "EUR";

	double amount;
	char ch1, ch2, ch3; //currency name should consist of 3 characters
	
	is >> ch1 >> ch2 >> ch3 >> amount;
	string currency = "";
	currency = currency + ch1 + ch2 + ch3;

	if (!is) return is;

	if ((currency != USD) ||
		(currency != DKK) ||
		(currency != EUR))
	{
		is.clear(ios_base::failbit);							//set the fail bit
		return is;
	}
	else
		a = Money((long int)amount * 100,currency);

	return is;
}

Money operator+(const Money&a, const Money& b)
{
	if (a.get_currency() != b.get_currency())
		error("the values should be of the same currency");
	return Money(roundoff(a) + roundoff(b), a.get_currency());
}

Money operator-(const Money&a, const Money& b)
{
	if (a.get_currency() != b.get_currency())
		error("the values should be of the same currency");
	return Money(roundoff(a) - roundoff(b), a.get_currency());
}

Money operator/(const Money&a, const Money& b)
{
	if (a.get_currency() != b.get_currency())
		error("the values should be of the same currency");
	return Money(roundoff(a) / roundoff(b), a.get_currency());
}

Money operator*(const Money&a, const Money& b)
{
	if (a.get_currency() != b.get_currency())
		error("the values should be of the same currency");
	return Money(roundoff(a) * roundoff(b), a.get_currency());
}

long int roundoff(const Money& a)
{
	long int amount = a.get_cents();
	vector<int> number;
	string s = "";

	const int numberlength = 6; //we want the 6th number to be rounded off

	do										//construct vector of int
	{
		number.push_back(amount % 10);
		amount /= 10;
	} while (amount / 10 > 0);
	number.push_back(amount);

	if (number[number.size() - numberlength] > 4)	//round off number
		number[number.size() - (numberlength - 1)] = number[number.size() - (numberlength - 1)]++;

	for (int i = number.size() - 1; i > number.size() - numberlength; i--)	//constuct string from vector
		s = s + to_string(number[i]);

	amount = atoi(s.c_str());		//convert string to int
	return amount;
}

void convert_curreny(string currencyFrom, string currencyTo, long int amount)
{
	
}

