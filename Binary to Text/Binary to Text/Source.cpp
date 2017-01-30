#include "../../std_lib_facilities.h"

int main()
try {
	cout << "Please enter input file name\n";
	string iname;
	cin >> iname;
	ifstream ifs{ iname, ios_base::binary };
	if (!ifs) error("can't open input file", iname);

	cout << "Please enter output file name\n";
	string oname;
	cin >> oname;
	ofstream ofs{ oname };
	if (!ofs) error("can't open output file", iname);

	vector<int> v;
	vector<char> text;

	for (int x; ifs.read(as_bytes(x), sizeof(int));)
		v.push_back(x);

	//do something with v


	for (char ch : text)
		ofs << ch;
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