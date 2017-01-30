/*#include "../../std_lib_facilities.h"

struct Reading {
	int hour;
	double temparature;
	char tempType;
};

int main()
{
	vector<Reading> temps{ 
		Reading{ 0,1.2,'c' },
		Reading{ 1,1.4,'f' },
		Reading{ 2,1.6,'c' },
		Reading{ 3,1.8,'f' },
		Reading{ 4,2.0,'c' },
		Reading{ 5,2.2,'f' },
		Reading{ 6,2.4,'c' },
		Reading{ 7,2.6,'f' },
		Reading{ 8,2.8,'c' },
		Reading{ 9,3.0,'f' },
		Reading{ 10,7.6,'c' },
		Reading{ 11,7.9,'f' },
		Reading{ 12,8.2,'c' },
		Reading{ 13,11.0,'c' },
		Reading{ 14,11.5,'f' },
		Reading{ 15,11.9,'c' },
		Reading{ 16,21.85,'c' },
		Reading{ 17,22.15,'f' },
		Reading{ 18,23.45,'c' },
		Reading{ 19,23.50,'c' },
		Reading{ 20,24.4,'f' },
		Reading{ 21,25.4,'c' },
		Reading{ 22,25.6,'c' },
		Reading{ 23,26.0,'f' },
		Reading{ 24,26.4,'c' },
	};

	ofstream ost{ "raw_temps.txt" };
	if (!ost) error("cant open output file");

	for (int i = 0; i < 24; i++)
		ost << '(' << temps[i].hour << ',' << temps[i].temparature << ',' << temps[i].tempType << ")\n";
} */