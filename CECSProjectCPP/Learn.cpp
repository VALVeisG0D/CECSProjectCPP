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

	int inertia = 1;	//Range of values: -3 - +3
	int position = 0;	//Range of values: -MAXINT - +MAXINT
	int change = 0;		//Range of values: -6 - +6
	int temp = 0;		//Range of values: -1 - +1

	for (int i = 0; i < 12; ++i)
	{
		change += inertia;
		position += temp = (0xfff8 >> change) & 1; //need to work for negatives too
		cout << inertia << " " << change << " " << position << endl;
		change -= temp * 3; // normalize the change when it crosses a threshold. need to work for negatives too
	}

	_itoa_s(((0xfff8 >> 7) & 1), b, 2);
	cout << b << endl;

	return 0;
}