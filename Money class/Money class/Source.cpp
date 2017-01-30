#include "Money.h"

int main()
try{
	Money m{ 123436789,"USD" }; //123.45 dollars
	Money n{ 123436789,"USD" };

	cout << m + n;
	

	keep_window_open();
	return 1;
}
catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
}
catch (...) {
	cerr << "exception\n";
}