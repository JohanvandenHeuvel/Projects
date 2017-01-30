#include "../../std_lib_facilities.h"

int main()
try {
	ifstream ifs{ "input.txt" };
	if (!ifs) error("couldnt open ifile");
	ofstream ofs{ "output.txt" };
	if (!ofs) error("couldnt open ofile");

	vector<char> fileContent;
	while (!ifs.eof())
	{
		char ch;
		ifs >> ch;
		fileContent.push_back(ch);
	}

	reverse(fileContent.begin(), fileContent.end());

	string content;

	for (char ch : fileContent)
	{
		content += ch;
	}

	ofs << content; //ofs doens't work
		
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