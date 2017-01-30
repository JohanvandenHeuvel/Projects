#include "../../std_lib_facilities.h"

//Classes----------------------------------------------------------------------------------

enum class Gerne
{
	fiction, nonfiction, periodical, biography, children
};

class library
{
	vector<Patron> patron;
	vector<Book> book;

	struct Transaction
	{

	};
};

class Patron
{
	string userName;
	int librarycardNumber;
	int libraryFee;
public:
	Patron(string entry_userName, int entry_librarycardNumber);

	const string get_userName() const { return userName; }
	const int get_librarycardNumber() const { return librarycardNumber; }
	const int get_libraryFee() const { return libraryFee; }
	void increaseFee(int addedFee);
};

class Book 
{
	Gerne gerne;
	string ISBN;
	string title;
	string author;
	int copyrightDate;
	bool checkedOut;
public:
	void checkOut(bool checkout);
	bool checkISBN(string str);
	Book(Gerne entry_gerne,string entry_ISBN, string entry_title, string entry_author, int entry_copyrightDate);

	const Gerne get_gerne() const { return gerne; }
	const string get_ISBN() const { return ISBN; }
	const string get_title() const { return title; }
	const string get_author() const { return author; }
	const int get_copyrightDate() const { return copyrightDate; }
	const bool get_checkedOut() const { return checkedOut; }
};

//Patron Class funtions----------------------------------------------------------------

Patron::Patron(string entry_userName, int entry_librarycardNumber)
{
	userName = entry_userName;
	librarycardNumber = entry_librarycardNumber;
	libraryFee = 0;
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


//Book Class funtions-------------------------------------------------------------

Book::Book(Gerne entry_gerne,string entry_ISBN, string entry_title, string entry_author, int entry_copyrightDate)
{
	gerne = entry_gerne;
	if (checkISBN(entry_ISBN))
		ISBN = entry_ISBN;
	else
		cout << "ISBN is invalid" << endl;
	title = entry_title;
	author = entry_author;
	copyrightDate = entry_copyrightDate;
	checkedOut = false;
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

//Gerne to String------------------------------------

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

//Operator functions-------------------------------------------------------

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

//Main---------------------------------------------------------------------

int main()
try {
	Book b(Gerne::fiction,"1234 1234 1234 n","Donald Duck","Someone",1997);
	cout << b;

	Patron p("Piet", 1234);
	p.increaseFee(100);

	cout << "User: " << p.get_userName() << endl
		<< "Library card number: " << p.get_librarycardNumber() << endl
		<< "Library Fee: " << p.get_libraryFee() << endl;

	keep_window_open();
	return 1;
}
catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
}
catch (...) {
	cerr << "exception\n";
}