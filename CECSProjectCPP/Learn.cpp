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
	int offset = 0;

	for (int i = 0; i < 12; ++i)
	{
		change += inertia;
		offset = change + 3;
		position += temp = (((int)0xffffffff) & (1 >> offset)) + ((0xff20 >> offset) & 1);
		position += temp = (0xfff8 >> change) & 1; //need to work for negatives too
		cout << inertia << " " << change << " " << position << endl;
		change -= temp * 3; // normalize the change when it crosses a threshold. need to work for negatives too
	}

	_itoa_s(-1, b, 2);
	cout << 0xffffffff << endl;

	return 0;
}