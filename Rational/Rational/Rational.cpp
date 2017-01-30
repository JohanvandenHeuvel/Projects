#include "Rational.h"

Rational::Rational(int numerator, int denominator)
	:numerator(numerator), denominator(denominator)
{
}

Rational operator+(Rational a, Rational b)
{
	int numerator = (a.numerator * b.denominator) + (b.numerator * a.denominator);
	int denominator = a.denominator*b.denominator;
	Rational simplefy(Rational a);

	return simplefy(Rational(numerator, denominator));
}

Rational operator-(Rational a, Rational b)
{
	int numerator = (a.numerator * b.denominator) - (b.numerator * a.denominator);
	int denominator = a.denominator*b.denominator;
	Rational simplefy(Rational a);

	return simplefy(Rational(numerator, denominator));
}

Rational operator*(Rational a, Rational b)
{
	int numerator = a.numerator*b.numerator;
	int denominator = a.denominator*b.denominator;
	Rational simplefy(Rational a);

	return simplefy(Rational(numerator, denominator));
}

Rational operator/(Rational a, Rational b)
{
	int numerator = a.numerator*b.denominator;
	int denominator = a.denominator*b.numerator;

	return simplefy(Rational(numerator, denominator));
}

ostream& operator<<(ostream& os, Rational& a)
{
	return os << a.numerator << '/' << a.denominator;
}

Rational simplefy(Rational a)
{
	for (int i = 1; i < a.denominator; i++)
		if (a.numerator % i == 0 && a.denominator % i == 0)
		{
			a.numerator /= i;
			a.denominator /= i;
			i = 1;
		}
	return a;
}

double todouble(Rational a)
{
	return (double)a.numerator / a.denominator;
}

bool operator==(Rational a, Rational b)
{
	a = simplefy(a);
	b = simplefy(b);
	return a.numerator == b.numerator && a.denominator == a.denominator;
}
