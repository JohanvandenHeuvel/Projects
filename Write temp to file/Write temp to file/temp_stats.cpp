#include "../../std_lib_facilities.h"

struct Reading;

istream& operator >> (istream& is, Reading& r);

struct Reading {
	int hour;
	double temparature;
	char tempType;
};

int main()
try{
	ifstream ifs{ "raw_temps.txt" };
	if (!ifs) error("cannot open file");

	vector<Reading> temps;	

	while (true)
	{
		Reading x;
		if (ifs.eof())break;
		if (!(ifs >> x))break;
		temps.push_back(x);
	}

	ofstream ost{ "new_new_raw_temps.txt" };
	if (!ost) error("cant open output file");

	for (int i = 0; i < 24; i++)
		ost << '(' << temps[i].hour << ',' << temps[i].temparature << ',' << temps[i].tempType << ")\n";
}
catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
	keep_window_open();
}
catch (...) {
	cerr << "exception\n"; 
	keep_window_open();
}

istream& operator >> (istream& is, Reading& r)
{
	char ch1, ch2, ch3, ch4;
	int hour ;
	double temparature ;
	char tempType;

	if (is >> ch1 && ch1 != '(') {
		is.unget();
		is.clear(ios_base::failbit);
		return is;
	}

	is >> hour >> ch2 >> temparature >> ch3 >> tempType >> ch4;

	cout << hour;

	if (!is) error("bad is");
	if (ch2 != ',' || ch3 != ',' || ch4 != ')') error("bad reading");
	if (hour < 0 || hour > 24) error("invalid time");
	if ((tempType == 'f' && temparature < 0) || (tempType == 'c' && temparature < -273)) error("invalid temparature");
	if (tempType == 'c')
		temparature = temparature * 1.8 + 32; //convert from celcius to fahrenheit
	r.hour = hour;
	r.temparature = temparature;
	r.tempType = 'f';

	return is;
}