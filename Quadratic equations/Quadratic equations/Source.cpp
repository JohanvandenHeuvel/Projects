#include "../../std_lib_facilities.h"

double discriminant(double a, double b, double c)
{
	double D;
	D = (b*b) - 4 * (a*c);
	return D;
}

void solution(double a, double b, double c)
{
	double x1;
	double x2;
	double D;
	D = discriminant(a, b, c);

	if (D > 0) {
		x1 = (-b + sqrt(D)) / (2 * a);
		x2 = (-b - sqrt(D)) / (2 * a);
		cout << "the solutions are: " << x1 << ", " << x2 << '\n';
	}
	else if (D == 0) {
		x1 = (-b + sqrt(D)) / (2 * a);
		cout << "the solution is: " << x1 << '\n';
	}
	else
		cout << "no solutions\n";
}

int main()
{
	double a;
	double b;
	double c;
	
	cout << "Solve a quadratic equation of the form: ax^2 + bx + c = 0 \n";
	cout << "Enter a: ";
	cin >> a;
	cout << "Enter b: ";
	cin >> b;
	cout << "Enter c: ";
	cin >> c;

	solution(a, b, c);

	keep_window_open();
	return 0;
}