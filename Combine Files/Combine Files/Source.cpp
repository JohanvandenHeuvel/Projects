#include "../../std_lib_facilities.h"

int main()
{
	string filename_1;
	filename_1 = "test1.txt";
	ifstream ifs_1{ filename_1 };
	if (!ifs_1) error("can't open input file ", filename_1);

	string filename_2;
	filename_2 = "test2.txt";
	ifstream ifs_2{ filename_2};
	if (!ifs_2) error("can't open input file ", filename_2);

	string filename_O = filename_1.erase(filename_1.size() - 4, 3) + " + " + filename_2;
	ofstream ofs{ filename_O };

	string content_1;
	while (ifs_1.eof() != true)
	{
		content_1 += ifs_1.get();
	}
	content_1.erase(content_1.size() - 2, 1);
	ofs << content_1;

	ifs_1.close();

	string content_2;
	while (ifs_2.eof() != true)
	{
		content_2 += ifs_2.get();
	}
	content_2.erase(content_2.size() - 2, 1);
	ofs << content_2;

	ifs_2.close();
	ofs.close();

	keep_window_open();
	return 0;
}