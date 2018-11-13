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
	
	int inertia = 0;
	int position = 0;
	int change = 0;

	for (int i = 0; i < 10; ++i)
	{
		change = (0xfff8 >> ++inertia) & 1;

		cout << inertia << " " << change << " " << (position += change) << endl;
		inertia >>= (change << 1); // reset inertia to 0 when inertia reaches 3 by shifting to the left by 2		
	}

	_itoa_s(((0xfff8 >> 7) & 1), b, 2);
	cout << b << endl;

	return 0;
}