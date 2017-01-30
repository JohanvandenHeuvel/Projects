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
try {
	string iFileName = "input.txt";
	ifstream ifs{ iFileName };
	if (!ifs) error("couln't open iFile", iFileName);

	string oFileName = "output.txt";
	ofstream ofs{ oFileName };
	if (!ofs) error("couln't open oFile", oFileName);

	int numberAlpha = 0;
	int numberDigit = 0;
	int numberAlphaNum = 0;
	int numberPunct = 0;

	while (!ifs.eof())
	{
		char ch;
		ifs >> ch;
		if (isalpha(ch))
			numberAlpha ++;
		if (isdigit(ch))
			numberDigit++;
		if (isalnum(ch))
			numberAlphaNum++;
		if (ispunct(ch))
			numberPunct++;
	}

	cout << "Letters:" << numberAlpha << endl
		<< "Numbers:" << numberDigit << endl
		<< "Alpha numbericals:" << numberAlphaNum << endl
		<< "Punctuations:" << numberPunct << endl;

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