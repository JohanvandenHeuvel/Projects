#include "../../std_lib_facilities.h"

/*
vector<string>split(const string& s)
{
vector<string> substrings;
string substring;

istringstream is{ s };
while (!is.eof())
{
is >> substring;
substrings.push_back(substring);
}
return substrings;
}
*/

bool is_whitespace(char c, const string & w)
{
	for (char ch : w)
		if (c == ch || isspace(ch)) return true;
	return false;
}

string toWhiteSpaces(const string& s, const string& w)
{
	string sentence = s;
	for (char& ch : sentence)
		if (is_whitespace(ch, w))
			ch = ' ';
	return sentence;
}

// s is string, w are characters that we should split on
vector<string>split(const string& s, const string& w)
{
	vector<string> substrings;
	string substring;

	string sentence = toWhiteSpaces(s,w);
	istringstream is{ sentence };

	while (!is.eof())
	{
		is >> substring;
		substrings.push_back(substring);
	}
	return substrings;
}

int main()
try {
	string sentence = "Hoi ik ben-johan";
	string w = "-";
	vector<string> words = split(sentence,w);
	for (string s : words)
		cout << s << endl;
	keep_window_open();
}
catch (exception& e)
{
	cerr << "exception:" << e.what() << endl;
}
catch (...)
{
	cerr << "exception\n";
}