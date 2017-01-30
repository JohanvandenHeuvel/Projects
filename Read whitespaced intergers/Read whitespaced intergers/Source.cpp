#include "../../std_lib_facilities.h"

void printVector(vector<int> v);

int main()
{
	string filename = "input.txt";
	ifstream ifs{ filename };
	if (!ifs) error("cant open input file", filename);

	int temp;
	char c;
	vector<int> v;

	while (ifs.good())
	{
		ifs >> c;
		if (isdigit(c))
		{
			ifs.putback(c);
			ifs >> temp;
			v.push_back(temp);
		}
		else
			continue;
	}

	printVector(v);
	keep_window_open();
}

void printVector(vector<int> v)
{
	for (int x : v)
		cout << x << " ";
}