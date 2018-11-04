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

	int c = 7;

	_itoa_s(c, b, 2);
	cout << b << endl;

	cout << (c & 1) << " " << ((c >> 1) & 1) << endl;

	return 0;
}