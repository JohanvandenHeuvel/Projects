#include "../../std_lib_facilities.h"

string charClass(const char& ch)
{
	string result = "";
	if (isalpha(ch))
		result += " letter";
	if (isdigit(ch))
		result += " digit";
	if (isalnum(ch))
		result += " alphanumeric";
	if (ispunct(ch))
		result += " punctuation";
	return result;
}

int main()
try{
	cout << "Enter a string:";
	string s;
	cin >> s;

	for (char ch : s)
	{
		cout << ch << charClass(ch) << endl;
	}

	keep_window_open();
	return 0;
}
catch (exception & e)
{
	cerr << "exception: " << e.what() << endl;
}
catch (...)
{
	cerr << "exception\n";
}