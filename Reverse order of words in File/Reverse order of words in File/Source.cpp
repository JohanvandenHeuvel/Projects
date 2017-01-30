#include "../../std_lib_facilities.h"

int main()
try {
	string iFileName = "input.txt";
	ifstream ifs{ iFileName };
	if (!ifs) error("couln't open iFile", iFileName);

	string oFileName = "output.txt";
	ofstream ofs{ oFileName };
	if (!ofs) error("couln't open oFile", oFileName);

	vector<string> content;
	while (!ifs.eof())
	{
		string word;
		ifs >> word;
		content.push_back(word);
	}
	reverse(content.begin(), content.end());

	for (string word : content)
		ofs << word << " ";

}
catch (exception& e)
{
	cerr << "exception:" << e.what() << endl;
}
catch (...)
{
	cerr << "exception\n";
}