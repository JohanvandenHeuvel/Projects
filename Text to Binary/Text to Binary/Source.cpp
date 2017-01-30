#include "../../std_lib_facilities.h"

int main()
try {
	cout << "Please enter input file name\n";
	string iname;
	cin >> iname;
	ifstream ifs{ iname };
	if (!ifs) error("can't open input file", iname);

	cout << "Please enter output file name\n";
	string oname;
	cin >> oname;
	ofstream ofs{ oname, ios_base::binary };
	if (!ofs) error("can't open output file", iname);

	vector<char> text;
	vector<int> v;
	char ch;

	while (ifs >> ch)
		text.push_back(ch);

	//do something with v

	for (int x : v)
		ofs.write(as_bytes(x), sizeof(int));
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