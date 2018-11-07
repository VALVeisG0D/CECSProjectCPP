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
	cout << b << endl;
	
	int inertia = 0;
	int position = 0;

	//cout << (a >> 1) << endl;

	for (int i = 0; i < 10; ++i)
	{
		
		inertia++;
		///_itoa_s(c, b, 2);
		//cout << b << endl;
		int change = ((inertia & 1) & ((inertia >> 1) & 1));

		cout << inertia << " " << change << endl;
		//cout << (c & 1) << " " << ((c >> 1) & 1) << endl;
		inertia >>= (change << 1); // reset inertia to 0 when inertia reaches 3
		position += change;
		cout << position << endl;
	}

	return 0;
}