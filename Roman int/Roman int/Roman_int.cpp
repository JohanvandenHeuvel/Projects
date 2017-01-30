#include "Roman_int.h"

int Roman_int::as_int()
{
	return 1;
}

ostream& operator <<(ostream& os, const Roman_int& r)
{
	int value = r.get_value();
	string s = "";

	//make exception for:
	//IV = 4
	//IX = 9
	//XL = 40
	//XC = 90
	//CD = 400
	//CM = 900
	if (value >= 900)
	{
		s += "CM";
		value -= value & 900;

	}

	if (value >= 400)
	{
		s += "CD";
		value -= value % 400;
		
	}
	if (value >= 90)
	{
		s += "XC";
		value -= value % 90;
		cout << value << "wut" << endl;
	}

	if (value >=  40)
	{
		s += "XL";
		value -= value % 40;
		
	}
	

	if (value >= 4)
	{
		s += "IV";
		value -= 4 * 1;
		cout << value << endl;
	}
	if (value >= 9)
	{
		s += "IX";
		value -= 9 * 1;
		cout << value << endl;
	}
 
	while (value != 0) //	I = 1 V = 5 X = 10 L = 50 C = 100
	{
		cout << value << endl;
		
		for (int i = roman_numerals.size() - 1; i >= 0; i--)
		{
			while (value - roman_numerals[i].get_value() >= 0)
			{
				s += roman_numerals[i].get_character();
				//cout << value;
				value -= roman_numerals[i].get_value();
				//cout << " - " << roman_numerals[i].get_value() << " = " << value << endl;
			}
		}
	}
	return os << s << endl;
}

istream& operator >> (istream& is, Roman_int& r)
{
	return is;
}

