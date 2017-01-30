#include "Chrono.h"

Date::Date(int yy, Month mm, int dd)
	:y{ yy }, m{ mm }, d{ dd }
{
	if (!is_date(yy, mm, dd)) throw Invalid();
}

const Date& default_date()
{
	static Date dd{ 2001, Month::jan, 1 };
	return dd;
}

Date::Date()
	:y{ default_date().year() },
	m{ default_date().month() },
	d{ default_date().day() }
{
}

int days_in_month(int y, Month m)
{
	int days = 31;

	switch (m)
	{
	case Month::feb:
		days = (leapyear(y)) ? 29 : 28;
		break;
	case Month::apr: case Month::jun: case Month::sep: case Month::nov:
		days = 30;
		break;
	}

	return days;
}

void Date::add_day(int n)
{
	for (int i = 0; i < n; i++)
		if (days_in_month(y, m) < n + 1)
		{
			d = 1;
			if (m == Month::dec)
			{
				add_year(1);
				m = Month::jan;			
			}
			else
				add_month(1);
		}
		else
			d++;
			
}

void Date::add_month(int n)
{
	for(int i = 0; i < n; i++)
		m = (m == Month::dec) ? Month::jan : Month(int(m) + 1);
}

void Date::add_year(int n)
{
	if (m == Month::feb && d == 29 && !leapyear(y + 1)) {
		m = Month::mar;
		d = 1;
	}
	y += n;
}

bool is_date(int y, Month m, int d)
{
	//assume y is valid
	if (d <= 0) return false;
	if (m < Month::jan || Month::dec < m)return false;
	if (days_in_month(y, m) < d) return false;	//cannot have more days in month

	return true;
}

bool leapyear(int y)
{
	if (y % 4 == 0)
		return true;
	return false;
}

bool operator==(const Date& a, const Date& b)
{
	return a.year() == b.year()
		&& a.month() == b.month()
		&& a.day() == b.day();
}

bool operator!=(const Date&a, const Date& b)
{
	return !(a == b);
}

string monthString(const Date& d)
{
	switch (d.month())
	{
	case Month::jan:
		return "jan";
		break;
	case Month::feb:
		return "feb";
		break;
	case Month::mar:
		return "mar";
		break;
	case Month::apr:
		return "apr";
		break;
	case Month::jun:
		return "jun";
		break;
	case Month::jul:
		return "jul";
		break;
	case Month::may:
		return "may";
		break;
	case Month::aug:
		return "aug";
		break;
	case Month::sep:
		return "sep";
		break;
	case Month::oct:
		return "oct";
		break;
	case Month::dec:
		return "dec";
		break;
	case Month::nov:
		return "nov";
		break;

	default:
		break;
	}
}

Month monthString(string s)
{
	if (s == "jan")
		return Month::jan;
	if (s == "feb")
		return Month::feb;
	if (s == "mar")
		return Month::mar;
	if (s == "par")
		return Month::apr;
	if (s == "jun")
		return Month::jun;
	if (s == "jul")
		return Month::jul;
	if (s == "may")
		return Month::may;
	if (s == "aug")
		return Month::aug;
	if (s == "sep")
		return Month::sep;
	if (s == "oct")
		return Month::oct;
	if (s == "nov")
		return Month::nov;
	if (s == "dec")
		return Month::dec;
}

ostream& operator<<(ostream& os, const Date& d)
{
	return os << '(' << d.year()
		<< ',' << monthString(d)
		<< ',' << d.day() << ')';
}

istream& operator >> (istream& is, Date& dd)
{
	int y, m, d;
	char ch1, ch2, ch3, ch4;
	is >> ch1 >> y >> ch2 >> m >> ch3 >> d >> ch4;
	if (!is) return is;
	if (ch1 != '(' || ch2 != ',' || ch3 != ',' || ch4 != ')') { //format error
		is.clear(ios_base::failbit);							//set the fail bit
		return is;
	}

	dd = Date(y, Month(m), d);

	return is;
}

/*
Day day_of_week(const Date& d)
{
	//...
}

Date next_Sunday(const Date& d)
{
	//...
}

Date next_weekday(const Date& d)
{
	//...
}
*/

