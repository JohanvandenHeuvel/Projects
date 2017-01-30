#include "../../std_lib_facilities.h"

void print(string s, vector<int> v)
{
	cout << s << endl;
	for (int x : v) {
		cout << x << endl;
	}
}

void print(string s, vector<string> v)
{
	cout << s << endl;
	for (string x : v) {
		cout << x << endl;
	}
}

int Next_fibonacci_number(int val1, int val2)
{
	if (val2 == 0) val2 = 1;
	int temp = 0;
	temp = val1 + val2;
	return temp;
}

vector<int> fibonacci(int x, int y, vector<int> v, int n)
{
	v.push_back(x);
	v.push_back(y);
	for (int i = 0; i < n; i++) {
		v.push_back(Next_fibonacci_number(x, y));
		x = v[v.size() - 1];
		if (v.size() > 1)
			y = v[v.size() - 2];
	}
	return v;
}

vector<int> reverse_copy(vector<int> v)
{
	vector<int> reversed_v(v.size());
	for (int i = v.size() - 1; i >= 0; i--)
		reversed_v[i] = v[v.size() - 1 - i];
	return reversed_v;
}

void reverse_reference(vector<int>& v)
{
	for (int i = 0; i < v.size() / 2; i++)
		swap(v[i], v[v.size() - 1 - i]);
}

void vectors_int()
{
	vector<int> empty;
	vector<int> v = fibonacci(2, 3, empty, 10);
	print("vector:", v);
	cout << endl;
	reverse_reference(v);
	print("reversed referece", v);
	cout << endl;
	print("reversed copy:", reverse_copy(v));
}

vector<string> reverse_copy(vector<string> v)
{
	vector<string> reversed_v(v.size());
	for (int i = v.size() - 1; i >= 0; i--)
		reversed_v[i] = v[v.size() - 1 - i];
	return reversed_v;
}

void reverse_reference(vector<string>& v)
{
	for (int i = 0; i < v.size() / 2; i++)
		swap(v[i], v[v.size() - 1 - i]);
}

void vectors_string()
{
	vector<string> v{ "huisje","boompje","beestje" };
	print("vector string:", v);
	cout << endl;
	reverse_reference(v);
	print("reversed referece", v);
	cout << endl;
	print("reversed copy:", reverse_copy(v));
	cout << endl;
}


int main()
try {
	vectors_string();
	vectors_int();
	
	keep_window_open();
	return 0;
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