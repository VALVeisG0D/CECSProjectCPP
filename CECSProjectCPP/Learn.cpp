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

	int inertia = 2;			//Range of values: -3 - +3
	int position = 0;			//Range of values: -MAXINT - +MAXINT
	int change = 0;				//Range of values: -3 - +3
	int positivePart = 0;		//Range of values: -1 - +1
	int negativePart = 0;		//Range of values: -1 - +1
	int offset = 0;

	for (int i = 0; i < 13; ++i)
	{
		change += inertia;
		offset = change + 6;
		positivePart = ((0xfe00 >> offset) & 1);
		negativePart = ((0x000f >> offset) & 1);
		position += positivePart - negativePart; //need to work for negatives too
		cout << inertia << " " << change << " " << position << " " << offset << endl;
		change += (negativePart + positivePart) * -change; // normalize the change when it crosses a threshold. need to work for negatives too
	}

	_itoa_s(8, b, 2);
	cout << ((8 >> 3) & 1) << endl;

	return 0;
}