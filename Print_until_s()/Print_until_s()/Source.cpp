#include "../../std_lib_facilities.h"

void print_until_s(vector<string> v, string quit)
{
	int s_occurance = 0;
	for (string s : v) {
		if (s == quit) s_occurance++;
		if (s_occurance == 2) return;
		cout << s << '\n';
	}
}

int main()
{
	vector<string> v{ "hoi", "hallo", "quit", "of toch niet", "quit" };
	print_until_s(v, "quit");
	keep_window_open();
}