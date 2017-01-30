#include "Book.h"

Book::Book()
	:gerne{}, ISBN{}, title{}, author{}, copyrightDate{}, checkedOut{}
{
}

Book::Book(Gerne entry_gerne, string entry_ISBN, string entry_title, string entry_author, int entry_copyrightDate)
	: gerne{ entry_gerne }, ISBN{entry_ISBN}, title{ entry_title }, author{entry_author}, copyrightDate{ entry_copyrightDate }, checkedOut{false}
{
	if (!checkISBN(entry_ISBN))
		error("Invalid ISBN");
}

void Book::checkOut(bool checkout)
{
	if (checkout && checkedOut)
		cout << title << " is already checked in" << endl;
	if (!checkout && !checkedOut)
		cout << title << " is already checked out" << endl;
	if (checkout && !checkedOut)
		checkedOut = true;
	if (!checkout && checkedOut)
		checkedOut = false;
}

bool Book::checkISBN(string str) //int - int - int - digit || letter
{
	int interger;
	char ch;
	if (stringstream(str) >> interger >> interger >> interger >> ch)
	{
		if (isalnum(ch) || isalpha(ch))
			return true;
		else
			return false;
	}
	else
		return false;
}

string genreString(const Book& b)
{
	switch (b.get_gerne())
	{
	case Gerne::fiction:
		return "Fiction";
		break;
	case Gerne::nonfiction:
		return"Nonfiction";
		break;
	case Gerne::periodical:
		return "Periodical";
		break;
	case Gerne::biography:
		return "Biography";
		break;
	case Gerne::children:
		return "Children";
		break;
	default:
		break;
	}
}

bool operator==(const Book& a, const Book& b)
{
	return a.get_ISBN() == b.get_ISBN();
}

bool operator!=(const Book& a, const Book& b)
{
	return !(a.get_ISBN() == b.get_ISBN());
}

ostream& operator<<(ostream& os, const Book& b)
{
	return os
		<< "Gerne: " << genreString(b) << endl
		<< "Title: " << b.get_title() << endl
		<< "Author: " << b.get_author() << endl
		<< "ISBN: " << b.get_ISBN() << endl;
}