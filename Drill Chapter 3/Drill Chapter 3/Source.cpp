#include "../../std_lib_facilities.h"

int main()
{
	cout << "Enter the name of the person you want to write to (followed by 'enter'):\n";
	string first_name;
	cin >> first_name;

	cout << "Enter the age of the person (followed by 'enter'):\n";
	int age;
	cin >> age;
	if (age < 0 || age > 110) simple_error("you're kidding");

	cout << "Enter the name of a friend (followed by 'enter'):\n";
	string friend_name;
	cin >> friend_name;

	cout << "Enter what sex (m/f) your friend is (followed by 'enter'):\n";
	char friend_sex;
	cin >> friend_sex;
	
	cout << "Dear " << first_name << ",\n"
		<< " How are you? I am fine. I miss you.\n"
		<< "When can we meet again?\n"
		<< "I really want to so you again.\n"
		<< "Have you seen " << friend_name << " lately\n";
	if (friend_sex == 'm') cout << "If you see " << friend_name << " please ask him to call me.\n";
	if (friend_sex == 'f') cout << "If you see " << friend_name << " please ask her to call me.\n";
	cout << "I hear you just had a birthday and you are " << age << " years old.\n";
	if (age < 12) cout << "Next year you will be " << age + 1 << ".";
	if (age == 17) cout << "Next year you will be able to vote.";
	if (age > 70) cout << "I hope you are enjoying retirement";
	cout << "Yours sincerly.\n" << endl << endl << "Johan van den Heuvel\n";

	keep_window_open();
	return 0;
}