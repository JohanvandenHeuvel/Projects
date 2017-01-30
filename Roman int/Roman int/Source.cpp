#include "Roman_int.h"

int main()
try {
	Roman_int r = 19;
	cout << "19 " << r << endl;

	Roman_int rr = 8;
	cout << "8  " << rr << endl;
	keep_window_open();
}
catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
}
catch (...) {
	cerr << "exception\n";
}
