#include "../../std_lib_facilities.h"

class Name_pairs
{
	vector<string> name;
	vector<double> age;
public:
	const vector<string>& get_name() const { return name; }
	const vector<double>& get_age() const { return age; }

	void read_names();
	void read_ages();
	void print() const;
	void sort();
};

void Name_pairs::read_names()
{
	cout << "Enter name, 'NoName' to finish: ";
	string input;
	while (cin >> input && input != "NoName") {
		for (int i = 0; i<name.size(); ++i)
			if (name[i] == input) error("Name exists already: ", input);
		name.push_back(input);
	}
		
}

void Name_pairs::read_ages()
{
	for (int i = 0; i < name.size(); i++)
	{
		cout << "Enter an age for " << name[i] << " :";
		int input;
		cin >> input;
		age.push_back(input);
	}
}

void Name_pairs::print() const
{
	if (name.size() != age.size())
		error("print(): name and age must be the same size");
	for (int i = 0; i < name.size(); i++)
	{
		cout << name[i] << " " << age[i] << endl;
	}
}

void Name_pairs::sort()
{
	if (name.size() != age.size())
		error("print(): name and age must be the same size");
	vector<string> name_temp = name;
	vector<double> age_temp = age;
	std::sort(name.begin(), name.end());
	for (int i = 0; i < name.size(); i++)
		for (int ii = 0; ii < name_temp.size(); ii++)
			if (name[i] == name_temp[ii])
				age[i] = age_temp[ii];

}

ostream& operator<<(ostream& os, const Name_pairs& np)
{
	if (np.get_name().size() != np.get_age().size())
		error("<<: name and size must be the same size");
	for (int i = 0; i < np.get_name().size(); i++)
		os << '(' << np.get_name()[i] << ',' << np.get_age()[i] << ')' << endl;
	return os;
}

bool operator==(const Name_pairs& a, const Name_pairs& b)
{
	if (a.get_age().size() != b.get_age().size() || a.get_name().size() != b.get_name().size())
		return false;
	bool equal = true;
	for (int i = 0; i < a.get_name().size(); i++) {
		if (a.get_name()[i] != b.get_name()[i])
			return false;
	}
	return true;
}

bool operator!=(const Name_pairs& a, const Name_pairs& b)
{
	return !(a == b);
}

int main()
try{
	Name_pairs np1;
	np1.read_names();
	np1.read_ages();
	
	Name_pairs np2;
	np2.read_names();
	np2.read_ages();

	if (np1 == np2) cout << "Identical!\n";
	if (np1 != np2) cout << "Not identical!\n";

	keep_window_open();
	return 1;
}
catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
}
catch (...) {
	cerr << "exception\n";
}