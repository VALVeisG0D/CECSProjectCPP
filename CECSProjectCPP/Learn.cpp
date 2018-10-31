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
	int a = 4;
	char b[44];
	cout << sizeof(int) << " " << sizeof(float) << endl;

	_itoa_s(a, b, 2);
	cout << b << endl;

	a >>= 2;

	_itoa_s(a, b, 2);
	cout << b << endl;
	cout << 1.0f / 3.0f << endl;

	return 0;
}