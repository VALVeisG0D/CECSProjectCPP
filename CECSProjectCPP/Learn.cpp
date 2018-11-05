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

	//cout << (a >> 1) << endl;

	for (int i = 0; i < 10; ++i)
	{
		
		c++;
		///_itoa_s(c, b, 2);
		//cout << b << endl;

		cout << c << endl;
		//cout << (c & 1) << " " << ((c >> 1) & 1) << endl;
		c >>= (((c & 1) & ((c >> 1) & 1)) << 1);
	}

	return 0;
}