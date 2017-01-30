#include "../../std_lib_facilities.h"

int main()
{
	string filename = "input.txt";
	ifstream ifs{ filename };
	if (!ifs) error("cant open file", filename);

	vector<string> fileContent;
	string buffer;
	string word = "piet";
	int counter = 0;

	while (ifs.good())
	{
		getline(ifs, buffer);
		if (buffer.find(word, 0) < buffer.length())
		{
			fileContent.push_back(buffer);
		}
			
		
	}

	ofstream ofs{ "output.txt" };
	if (!ofs) error("error: Output File");
	for (string s : fileContent)
	{
		ofs << s << endl;
	}
	keep_window_open();
}