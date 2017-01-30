#pragma once
#include "../../std_lib_facilities.h"

class Rational
{
public:
	int numerator;
	int denominator;

	Rational(int numerator, int denominator);
};

Rational operator+(Rational a, Rational b);
Rational operator-(Rational a, Rational b);
Rational operator*(Rational a, Rational b);
Rational operator/(Rational a, Rational b);
ostream& operator<<(ostream& os,Rational& a);
bool operator==(Rational a, Rational b);
Rational simplefy(Rational a);
double todouble(Rational a);