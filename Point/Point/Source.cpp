#include "../../std_lib_facilities.h"

struct Point
{
	int x;
	int y;
};

int main()
{
	vector<Point> original_points;
	int x, y;

	for (int i = 0; i < 7; i++)
	{
		cout << "please enter a x-coordinate:";
		cin >> x;
		cout << "please enter a y-coordinate:";
		cin >> y;
		original_points.push_back(Point{ x, y });
	}

	ofstream ost{ "mydata" };
	if (!ost) error("cannot open output file");
	for (int i = 0; i < 7; i++)
	{
		ost << '(' << original_points[i].x << ',' << original_points[i].y << ')' << endl;
	}
}