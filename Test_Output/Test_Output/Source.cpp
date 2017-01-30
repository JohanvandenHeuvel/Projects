#include "../../std_lib_facilities.h"

int main()
{
	string firstName = "Johan";
	string lastName = "van den Heuvel";
	string telephoneNumber = "06-4537312";
	string eMail1 = "johanheuvel5@gmail.com";
	string eMail2 = "johanheuvel1@gmail.com";
	string eMail3 = "johanvandenheuvel@gomarus.nl";
	vector<string> eMail_adress = { eMail1,eMail2,eMail3 };
	
	int fieldLengthMail = 0;
	for (string s : eMail_adress)
		if (s.length() > fieldLengthMail)
			fieldLengthMail = s.length();

	cout << '\t' << setw(fieldLengthMail) << firstName + " " + lastName << '|' << endl
		<< '\t' << setw(fieldLengthMail) << telephoneNumber << '|' << endl
		<< '\t' << setw(fieldLengthMail) << eMail1 << '|' << endl
		<< '\t' << setw(fieldLengthMail) << eMail2 << '|' << endl
		<< '\t' << setw(fieldLengthMail) << eMail3 << '|' << endl
		<< endl;

	keep_window_open();
}