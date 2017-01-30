#include "../../std_lib_facilities.h"

class Bad_temp{};
class Case_unknown{};

double CtoK(double c)
{
	if (c < -273.15 )
		throw Bad_temp{};
	double k = c + 273.15;
	return k;
}

double KtoC(double k)
{
	if (k < 0)
		throw Bad_temp{};
	double c = k - 273.15;
	return c;
}

double CtoF(double c)
{
	if (c < -273.15)
		throw Bad_temp{};
	double f = (9 / 5)*c + 32;
	return f;
}

double FtoC(double f)
{
	if (f < -459.66)
		throw Bad_temp{};
	double c = (f - 32) / (9 / 5);
	return c;
}

int main()
try {
	cout << "1-- Celcius to Kelvin\n"
		 << "2-- Kelvin to Celcius\n"
		 << "3-- Celcius to Fahrenheit\n"
		 << "4-- Fahrenheit to Celcius\n";
	int input;
	cin >> input; //make a choice of 4 options

	double c = 0; //celcius
	double k = 0; //kelvin
	double f = 0; //fahrenheit

	switch (input)
	{
	case 1: //C to K
		cout << "Enter Celcius\n";
		cin >> c;
		k = CtoK(c);
		cout << k <<'\n';
		break;
	case 2: //K to C
		cout << "Enter Kelvin\n";
		cin >> k;
		c = KtoC(k);
		cout << c << '\n';
		break;
	case 3: //C to F
		cout << "Enter Celcius\n";
		cin >> c;
		f = CtoF(c);
		cout << f << '\n';
		break;
	case 4: //F to C
		cout << "Enter Fahrenheit\n";
		cin >> f;
		c = FtoC(f);
		cout << c << '\n';
		break;
	default:
		throw Case_unknown{};
		break;
	}
	keep_window_open();
	return 0;
}
catch(Bad_temp){
	cout << "Error: cannot go lower then 273.15 C\n";
	keep_window_open();
}
catch (Case_unknown) {
	cout << "Error: case unknown\n";
	keep_window_open();
}
