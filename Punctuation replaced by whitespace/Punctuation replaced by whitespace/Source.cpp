#include "../../std_lib_facilities.h"

//removes all punctuation from a sentence except quotes and hyphens between words
string replacePunct(const string& s)
{
	string sentence = "";
	
	for (int i = 0; i < s.size(); i++)
	{
		char ch = s.at(i);
		if (ch == 'c'	//can't to cannot
			&& i + 4 < s.size()
			&& s.at(i + 1) == 'a'
			&& s.at(i + 2) == 'n'
			&& s.at(i + 3) == '\''
			&& s.at(i + 4) == 't')
		{
			sentence += "cannot";
			i += 4;
		}
		else if (ch == 'n'	//words ending on n't to not
			&& i + 2 < s.size()
			&& s.at(i + 1) == '\''
			&& s.at(i + 2) == 't')
		{
			sentence += " not";
			i += 2; 
		}
		else if (ch == '-'	//do not remove hyphens between words
			&& i != s.size()	//check if hyphen isnt first of last char
			&& i != 0
			&& isalpha(s.at(i - 1))
			&& isalpha(s.at(i + 1))
			)
			sentence += ch;
		else if (ispunct(ch) && ch != '"')	//remove remaining punctuations except quotes
			sentence += ' ';
		else
			sentence += tolower(ch); //letters to lower case
	}
	return sentence;
}

int main()
try
{
	string word;
	string sentence = "\" - don't USE the as-if rule.\"";
	
	cout << replacePunct(sentence) << endl;

	keep_window_open();
	return 0;
}
catch (exception& e)
{
	cerr << "exception:" << e.what() << endl;
} 
catch (...)
{
	cerr << "exception\n";
}