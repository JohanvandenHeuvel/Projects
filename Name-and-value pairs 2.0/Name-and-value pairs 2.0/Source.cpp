#include "../../std_lib_facilities.h"


//------------------------------------------------------------------------------

class Name_value {
public:
	int value;
	string name;
	Name_value(string str, int val)
		:name(str), value(val) { }
};

//------------------------------------------------------------------------------

void Print_vector(vector<Name_value> entries)
{
	for (int i = 0; i < entries.size(); i++)// print entries
		cout << entries[i].name << " " << entries[i].value << '\n';
}

//------------------------------------------------------------------------------

int main()
try {
	vector<Name_value> entries;
	string name = " ";
	int value = -1;

	do{
		cout << "Enter a name and a score (seperated by 'space): ";
		cin >> name >> value;
		for (int i = 0; i < entries.size(); i++)
			if (name == entries[i].name)
				error("name occurs twice ", name);
		entries.push_back(Name_value(name,value));
	} while (cin >> name >> value && !(name == "NoName" && value == 0));

	Print_vector(entries);

	keep_window_open();
	return 0;
}
catch (exception& e) {
	cerr << "error: " << e.what() << '\n';
	keep_window_open();
	return 1;
}
catch (...) {
	cerr << "Oops: unknown exception!\n";
	keep_window_open();
	return 2;
}

//------------------------------------------------------------------------------