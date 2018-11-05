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
	
	int c = 0;
	int position = 0;

	//cout << (a >> 1) << endl;

	for (int i = 0; i < 10; ++i)
	{
		
		c++;
		///_itoa_s(c, b, 2);
		//cout << b << endl;
		int change = ((c & 1) & ((c >> 1) & 1));

		cout << c << " " << change << endl;
		//cout << (c & 1) << " " << ((c >> 1) & 1) << endl;
		c >>= (change << 1);
		position += change;
		cout << position << endl;
	}

	return 0;
}