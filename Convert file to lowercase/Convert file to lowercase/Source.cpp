#include "../../std_lib_facilities.h"

int main()
{
	string filename = "input.txt";
	ifstream ifs{ filename };
	if (!ifs) error("cant open file", filename);

	vector<string> fileContent;
	string buffer;

	while (ifs.good())
	{
		getline(ifs, buffer);
		transform(buffer.begin(), buffer.end(), buffer.begin(), ::tolower);
		fileContent.push_back(buffer);
	}

	ofstream ofs{ "output.txt" };
	if (!ofs) error("error: Output File");
	for (string s : fileContent)
	{
		ofs << s << endl;
	}

	keep_window_open();
}