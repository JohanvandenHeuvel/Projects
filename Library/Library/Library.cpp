#include "Library.h"

Transaction::Transaction()
	:p{}, b{}, d{}
{
}

Transaction::Transaction(Patron entry_p, Book entry_b, Date entry_d)
	:p{ entry_p }, b{ entry_b }, d{ entry_d }
{
}

Gerne gerneChoice(int n) //fiction, nonfiction, periodical, biography, children
{
	switch (n)
	{
	case 1:
		return Gerne::fiction;
		break;
	case 2:
		return Gerne::nonfiction;
		break;
	case 3:
		return Gerne::periodical;
		break;
	case 4:
		return Gerne::biography;
		break;
	case 5:
		return Gerne::children;
		break;
	default:
		error("error not known");
		break;
	}
}

void Library::addBook()
{
	int gerne;
	string author;
	string title;
	string ISBN;
	int copyrightDate;
	cout << "Choose a genre: 1 - Fiction	2 - Non-Fiction		3 - Periodical		4 - Biography		5 - Childeren" << endl; 
	cin >> gerne;

	cout << "Enter copyrightDate: "; 
	cin >> copyrightDate;
	cin.ignore();

	cout << "Enter a author: " ; 
	getline(cin,author);

	cout << "Enter a title: "; 
	getline(cin, title);

	cout << "Enter ISBN like ' number number number character ' : "; 
	getline(cin,ISBN);
	
	book.push_back(Book(gerneChoice(gerne), ISBN, title, author, copyrightDate));
}

void Library::addPatron()
{
	string username;
	int librarycardNumber;
	cout << "Enter a use name: ";
	getline(cin, username);

	cout << "Enter library card number: ";
	cin >> librarycardNumber;

	patron.push_back(Patron(username, librarycardNumber));
}



void Library::addTransaction(Patron entry_p, Book entry_b, Date entry_d)
{
	transaction.push_back(Transaction(entry_p, entry_b, entry_d));
}

void Library::printBook(Book b)
{
	for (int i = 0; i < book.size(); i++)
	{
		if (b == book[i])
			cout << book[i];
	}
}

void Library::printPatron(Patron p)
{
	for (int i = 0; i < patron.size(); i++)
	{
		if (p == patron[i])
			cout << patron[i];
	}
}

void Library::printPatronFee()
{
	for (int i = 0; i < patronFee.size(); i++)
	{
			cout << patronFee[i];
	}
}

void Library::getFee()
{
	for (int i = 0; i < patron.size(); i++)
	{
		if (patron[i].get_libraryFee() > 0)
			patronFee.push_back(patron[i]);
	}
}

void Library::checkout(Patron p,Book b)
{
	for (int j = 0; j < patron.size(); j++)
		if(p == patron[j] && p.get_libraryFee() == 0)
			for (int i = 0; i < book.size(); i++)
			{
				if (b == book[i]) {
					b.Book::checkOut(true);
					
					cout << "Enter date of transaction" << endl;
					int year;
					string m;
					int day;
					cout << "Enter year: "; cin >> year;
					cout << "Enter month: "; cin >> m;
					Month month = monthString(m);
					cout << "Enter day:";
					cin >> day;
					Date d{ year,month,day };
					addTransaction(p, b, d);
				}
			}
}

void Library::checkin(Patron p,Book b)
{
	for (int i = 0; i < book.size(); i++)
	{
		if (b == book[i])
		b.Book::checkOut(false);
	}
}

ostream& operator<<(ostream os, const Transaction& t)
{
	return os
		<< "Book: " << t.b << endl
		<< "Patron: " << t.p << endl
		<< "Date: " << t.d << endl;
}

bool operator==(const Transaction& a, const Transaction& b)
{
	return a.b == b.b && a.d == b.d && a.p == b.p;
}
bool operator!=(const Transaction& a, const Transaction& b)
{
	return !(a.b == b.b && a.d == b.d && a.p == b.p);
}
