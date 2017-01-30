#include "../../std_lib_facilities.h"

struct Vector_values
{
	Vector_values();
	double highest;
	double lowest;
	double mean;
	double median;
};

Vector_values::Vector_values()
	:highest(0),lowest(0),mean(0),median(0){}

double maxv(const vector<double>& v)
{
	double highest = v[0]; //initialize with first value of vector so with numbers lower then initialed value of highest is not highest
	for (double x : v) {
		if (x > highest)
			highest = x;
	}
	return highest;
}

double minv(const vector<double>& v)
{
	double lowest = v[0];
	for (double x : v) {
		if (x < lowest)
			lowest = x;
	}
	return lowest;
}

double meanv(const vector<double>& v)
{
	double mean;
	double total = 0;
	for (double x : v)
		total += x;
	mean = total / v.size();
	return mean;
}

double medianv(const vector<double>& v)
{
	double median;
	if (v.size() % 2 != 0)
		median = v[(v.size()) / 2];
	else
		median = (v[(v.size()-1) / 2] + v[(v.size() - 1) / 2 + 1])/2;
	return median;
}

Vector_values get_values(const vector<double>& v)
{
	Vector_values values;
	values.highest = maxv(v);
	values.lowest = minv(v);
	values.mean = meanv(v);
	values.median = medianv(v);
	return values;
}

int main()
{
	const vector<double> v{ 3,4,5,6,7,8,10,11 };
	Vector_values values = get_values(v);

	cout << "max: "<< values.highest << endl;
	cout << "min: " << values.lowest << endl;
	cout << "mean:" << values.mean << endl;
	cout << "median: " << values.median << endl;
	keep_window_open();
	return 1;
}