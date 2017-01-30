#pragma once
#include "../../std_lib_facilities.h"

struct Currencytable
{
	string currencyFrom;
	double exchangerate;
	string currencyTo;

	void intitialize_Currencytable();
};

class Money
{
	long int cents;
	string currency;
public:
	long int get_cents() const { return cents; }
	string get_currency() const { return currency; }

	
	Money(long int entry_cents,string entry_currency);
	Money();
};

Money operator+(const Money&a, const Money& b);
Money operator-(const Money&a, const Money& b);
Money operator/(const Money&a, const Money& b);
Money operator*(const Money&a, const Money& b);

long int roundoff(const Money&a);
void convert_currency(string currencyFrom, string currencyTo, long int amount);

ostream& operator<<(ostream& os, const Money& a);
istream& operator>>(istream& is, Money& a);