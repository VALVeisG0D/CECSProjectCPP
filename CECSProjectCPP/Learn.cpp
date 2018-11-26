#include <iomanip>
#include <iostream>
#include <chrono>
#include <functional>
#include <string>
#include <thread>
#include <utility>
#include <vector>

using namespace std;

int main()
{
	int a = 8;
	char b[44];
	cout << sizeof(int) << " " << sizeof(float) << endl;

	_itoa_s(a, b, 2);
	cout << b << endl << endl;

	int inertia = 2;	//Range of values: -3 - +3
	int position = 0;	//Range of values: -MAXINT - +MAXINT
	int change = 3;		//Range of values: -6 - +6
	int temp = 0;		//Range of values: -1 - +1
	int offset = 0;

	for (int i = 0; i < 12; ++i)
	{
		change -= inertia;
		position += (1 >> change);
		//offset = change + 4;
		//position += temp = -(1 >> offset) + ((0xff80 >> offset) & 1); //need to work for negatives too
		cout << inertia << " " << change << " " << position << " " << temp << endl;
		change += (1 >> change) * 3; // normalize the change when it crosses a threshold. need to work for negatives too
	}

	_itoa_s(-(0xffc0 >> 0), b, 2);
	cout << -(1 >> 0) << endl;

	return 0;
}