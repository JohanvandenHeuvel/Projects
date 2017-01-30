#pragma once
#include "../../std_lib_facilities.h"
#include "Book.h"
#include "Patron.h"
#include "Chrono.h"

struct Transaction
{
	Book b;
	Patron p;
	Date d;

	Transaction();
	Transaction(Patron entry_p, Book entry_b, Date entry_d);
};

class Library
{
	vector<Patron> patron;
	vector<Patron> patronFee;
	vector<Book> book;
	vector<Transaction> transaction;
public:
	void addBook();
	void addPatron();
	void addTransaction(Patron p, Book b, Date d);

	void printBook(Book b);
	void printPatron(Patron p);
	void printPatronFee();
	void getFee();

	void checkout(Patron p, Book b);
	void checkin(Patron p, Book b);

	const vector<Book> get_book() const { return book; }
	const vector<Patron> get_patron() const { return patron; }
	const vector<Transaction> get_transaction() const { return transaction; }
};

Gerne gerneChoice(int n);

ostream& operator<<(ostream os, const Transaction& t);
bool operator==(const Transaction& a, const Transaction& b);
bool operator!=(const Transaction& a, const Transaction& b);
