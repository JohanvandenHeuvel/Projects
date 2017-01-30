#pragma once
#include "../../std_lib_facilities.h"

enum class Gerne
{
	fiction, nonfiction, periodical, biography, children
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
	
	Book();
	Book(Gerne entry_gerne, string entry_ISBN, string entry_title, string entry_author, int entry_copyrightDate);

	const Gerne get_gerne() const { return gerne; }
	const string get_ISBN() const { return ISBN; }
	const string get_title() const { return title; }
	const string get_author() const { return author; }
	const int get_copyrightDate() const { return copyrightDate; }
	const bool get_checkedOut() const { return checkedOut; }
};

bool operator==(const Book& a, const Book& b);
bool operator!=(const Book& a, const Book& b);
ostream& operator<<(ostream& os, const Book& b);