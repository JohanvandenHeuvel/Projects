#include "../../std_lib_facilities.h"

int main()
{
	int i = 0;
	while (i < 26)
	{
		char valchar = 'a' + i;
		int valint = valchar;
		cout << valchar << "..." << valint << '\n';
		i++;
	}
	keep_window_open();
	return 0;
}
