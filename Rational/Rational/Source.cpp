#include "Rational.h"
#include "../../std_lib_facilities.h"

int main()
{
	Rational a{ 1,2 };
	Rational b{ 2,4 };
	Rational c{ 3,5 };

	if (a == b)
		cout << a << " = " << b << endl;

	keep_window_open();
	return 1;
}