#include "../../std_lib_facilities.h"

double calculate_index(vector<double> price, vector<double> weight)
{
	if (price.size() != weight.size())
		error("sizes of the vectors are not the same");
	double index = 0;
	for (int i = 0; i < price.size(); i++)
	{
		index += price[i] * weight[i];
	}
	return index;
}

int main()
{
	vector<double> price{ 3,4,5 };
	vector<double> weight{ 3,4,5 };

	cout << calculate_index(price, weight) << endl;
	keep_window_open();
	return 1;
}