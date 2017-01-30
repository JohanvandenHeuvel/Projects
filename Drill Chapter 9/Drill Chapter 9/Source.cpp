//define Date today June 25, 1978
//define Date tommorow today + add_day()
//output today and tommorow using << as in par.9.8
//month in [1-12] date
//day in [1-31] range
//test with [2004,13,-5]
//make from 9.4.1 , 9.4.2 , 9.4.3 , 9.7.1 , 9.7.4

#include "../../std_lib_facilities.h"

//Date type --------------------------------------------------
enum class Month
{
	jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};


class Date
{
private:
	int year;
	Month month;
	int day;
public:
	Date(int y, Month m, int d);		//year, month, day

	void print();

	void add_day(int n);			//n is how many days to add
	void add_month();
	void add_year();

	int y() { return year; }
	Month m() { return month; }
	int d() { return day; }
};

//Check date --------------------------------------------------

bool check_day(const int& year,const Month& month, const int& day)
{
	switch (month)
	{
	case Month::jan: case Month::mar: case Month::may: case Month::jul: case Month::aug: case Month::oct: case Month::dec:		
	{
		if (day <= 0 || day > 31)
			return false;
		break;
	}
	case Month::feb:	
	{
		if (year % 4 == 0)		//leap year
		{
			if (day <= 0 || day > 29)	//29 in leap year
				return false;
			break;
		}
		else 
		{
			if (day <= 0 || day > 28) 
				return false;
			break;
		}
	}
	case Month::apr: case Month::jun: case Month::sep: case Month::nov: 	
	{
		if (day <= 0 || day > 30)
			return false;
		break;
	}
	default:
		break;
	}

	return true;
}

//Make and add to date --------------------------------------------------
Date::Date(int y, Month m, int d):year(y),month(m),day(d) //Date constuctor
{
	if (!check_day(year, month, day))
		error("day is not valid");
}

void Date::add_year()
{
	year += 1;
}

void Date::add_month()
{
	switch (month)
	{
	case Month::jan:
		month = Month::feb;
		break;
	case Month::feb:
		month = Month::mar;
		break;
	case Month::mar:
		month = Month::apr;
		break;
	case Month::apr:
		month = Month::may;
		break;
	case Month::may:
		month = Month::jun;
		break;
	case Month::jun:
		month = Month::jul;
		break;
	case Month::jul:
		month = Month::aug;
		break;
	case Month::aug:
		month = Month::sep;
		break;
	case Month::sep:
		month = Month::oct;
		break;
	case Month::oct:
		month = Month::nov;
		break;
	case Month::nov:
		month = Month::dec;
		break;
	case Month::dec:
		month = Month::jan;
		break;
	default:
		break;
	}
}

void Date::add_day(int n)
{
	for (int i = 1; i <= n; i++)
	{
		if (check_day(year, month, day + 1)) //check if day isnt last day of the month
		{
			day += 1;
		}
		else if (month != Month::dec)	//check if month isnt december
		{
			add_month();
			day = 1;
		}
		else
		{
			add_year();
			add_month();
			day = 1;
		}
	}
}

//Month-to-String and String-to-Month --------------

string nameMonth(Month m) //month type to name
{
	switch (m)
	{
	case Month::jan:
		return "january";
	case Month::feb:
		return "february";
	case Month::mar:
		return "march";
	case Month::apr:
		return "april";
	case Month::may:
		return "may";
	case Month::jun:
		return "june";
	case Month::jul:
		return "july";
	case Month::aug:
		return "august";
	case Month::sep:
		return "september";
	case Month::oct:
		return "october";
	case Month::nov:
		return "november";
	case Month::dec:
		return "december";
	default:
		break;
	}
}

Month nameMonth(string s)  //name to month type
{
	if (s == "january")
		return  Month::jan;
	if (s == "february")
		return Month::feb;
	if (s == "march")
		return Month::mar;
	if (s == "april")
		return Month::apr;
	if (s == "may")
		return Month::may;
	if (s == "june")
		return  Month::jun;
	if (s == "july")
		return Month::jul;
	if (s == "august")
		return Month::aug;
	if (s == "september")
		return Month::sep;
	if (s == "october")
		return Month::oct;
	if (s == "november")
		return Month::nov;
	if (s =="december")
		return  Month::dec;
}

//Print --------------------------------------------------------

void Date::print()
{
	cout << "year: " << year << endl;
	cout << "month: " << nameMonth(month) << endl;
	cout << "day: " << day << endl;
}

//Date function --------------------------------------------------

void f()  // !!! Make '<<' operator for today !!!
{
	Date today {1978, nameMonth("june"), 28 };
	today.add_day(1);

	today.print();
}

//Main --------------------------------------------------

int main()
try{
	f();
	keep_window_open();
	return 1;
}
catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
	char c;
	while (cin >> c && c != ';'); // ??? read input into cin till ';' 
	return 1;
}
catch (...) {
	cerr << "exception\n";
	char c;
	while (cin >> c && c != ';'); // ??? read input into cin till ';'
	return 2;
}