#pragma once
#include "../../std_lib_facilities.h"

class Patron
{
	string userName;
	int librarycardNumber;
	int libraryFee;
public:
	Patron();
	Patron(string entry_userName, int entry_librarycardNumber);

	const string get_userName() const { return userName; }
	const int get_librarycardNumber() const { return librarycardNumber; }
	const int get_libraryFee() const { return libraryFee; }
	void increaseFee(int addedFee);
};

ostream& operator<<(ostream& os, const Patron& p);
bool operator==(const Patron& a, const Patron& b);
bool operator!=(const Patron& a, const Patron& b);