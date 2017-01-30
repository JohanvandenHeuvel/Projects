#include "Library.h"

int main()
try {
	Library L;
	L.addBook();
	cout << endl;
	L.addPatron();
	cout << endl;
	vector<Book> book = L.get_book();
	vector<Patron> patron = L.get_patron();

	L.checkout(patron[0], book[0]);

	cout << endl;
	L.printBook(book[0]);
	cout << endl;
	L.printPatron(patron[0]);
	cout << endl;

	

	keep_window_open();
	return 1;
}
catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
}
catch (...) {
	cerr << "exception\n";
}