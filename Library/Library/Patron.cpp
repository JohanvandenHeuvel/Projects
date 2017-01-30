#include "Patron.h"

Patron::Patron()
	:userName{},librarycardNumber{},libraryFee{}
{
}

Patron::Patron(string entry_userName, int entry_librarycardNumber)
	:userName{entry_userName},librarycardNumber{entry_librarycardNumber}, libraryFee{0}
{
}

void Patron::increaseFee(int addedFee)
{
	libraryFee = libraryFee + addedFee;
}

bool oweFee(Patron& p)
{
	if (p.get_libraryFee() > 0)
		return true;
	else
		return false;
}

ostream& operator<<(ostream& os, const Patron& p)
{
	return os
		<< "User: " << p.get_userName() << endl
		<< "Library card number: " << p.get_librarycardNumber() << endl
		<< "Library Fee: " << p.get_libraryFee() << endl;
}

bool operator==(const Patron& a, const Patron& b)
{
	return a.get_librarycardNumber() == b.get_librarycardNumber();
}

bool operator!=(const Patron& a, const Patron& b)
{
	return !(a.get_librarycardNumber() == b.get_librarycardNumber());
}