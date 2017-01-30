#pragma once
#include "../../std_lib_facilities.h"

class Roman_numeral //	I = 1 V = 5 X = 10 L = 50 C = 100
{
	int v;
	char ch;
public:
	Roman_numeral(int entry_v,char entry_ch) : v(entry_v),ch(entry_ch){ }
	Roman_numeral() : v(), ch() { }
	const int get_value() const { return v; }
	const char get_character() const { return ch; }
};

const vector<Roman_numeral> roman_numerals = 
{
	Roman_numeral(1,'I'),
	Roman_numeral(5,'V'),
	Roman_numeral(10,'X'),
	Roman_numeral(50,'L'),
	Roman_numeral(100,'C')
};

class Roman_int
{
	int value;

public:
	Roman_int(int entry_value) : value(entry_value) {}
	int as_int();
	const int get_value() const { return value; }
};

ostream& operator <<(ostream& os,const Roman_int& r);
istream& operator >>(istream& is, Roman_int& r);