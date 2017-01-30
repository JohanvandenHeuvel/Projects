#include "../../std_lib_facilities.h"

int FiboRecu(int n);

int main()
{
	for(int i = 0; i < 10; i++)
		cout << FiboRecu(i) << '\n';
	keep_window_open();
}

int FiboRecu(int n)
{
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else
		return(FiboRecu(n - 1) + FiboRecu(n - 2));
}