#include <iomanip>
#include <iostream>
#include <chrono>
#include <functional>
#include <string>
#include <thread>
#include <utility>
#include <vector>

using namespace std;

//void f(bool &);
//void f2(bool &);
//void fun(const int &);
//void fun(int &&);
//
//template<class T>
//class Auto_ptr4
//{
//	T* m_ptr;
//
//public:
//	Auto_ptr4(T* ptr = nullptr)
//		: m_ptr(ptr)
//	{}
//
//	~Auto_ptr4()
//	{
//		delete m_ptr;
//	}
//
//	// Copy constructor
//	// Do deep copy of a.m_ptr to m_ptr
//	Auto_ptr4(const Auto_ptr4 &a)
//	{
//		m_ptr = new T;
//		*m_ptr = *a.m_ptr;
//	}
//
//	// Move constructor
//	// Transfer ownership of a.m_ptr to m_ptr
//	Auto_ptr4(Auto_ptr4 &&a) : m_ptr(a.m_ptr)
//	{
//		a.m_ptr = nullptr;
//	}
//
//	// Copy assignment
//	// Do deep copy of a.m_ptr to m_ptr
//	Auto_ptr4 &operator=(const Auto_ptr4 &a)
//	{
//		// Self-assignment detection
//		if (&a == this)
//			return *this;
//
//		// Release any resource we are holding
//		delete m_ptr;
//
//		// Copy the resource
//		m_ptr = new T;
//		*m_ptr = *a.m_ptr;
//
//		return *this;
//	}
//
//	// Move assignment
//	// Transfer ownership of a.m_ptr to m_ptr
//	Auto_ptr4 &operator=(Auto_ptr4 &&a)
//	{
//		// Self-assignment detection
//		if (&a == this)
//			return *this;
//
//		// Release any resource we are holding
//		delete m_ptr;
//
//		// Transfer ownership of a.m_ptr to m_ptr
//		m_ptr = a.m_ptr;
//		a.m_ptr = nullptr;
//
//		return *this;
//	}
//
//	T &operator*() const { return *m_ptr; }
//	T *operator->() const { return m_ptr; }
//	bool isNull() const { return m_ptr == nullptr; }
//};
//
//template<class T>
//class DynamicArray
//{
//	T* m_array;
//	int m_length;
//
//public:
//	DynamicArray(int length) : m_length(length), m_array(new T[length])
//	{
//	}
//
//	~DynamicArray()
//	{
//		delete[] m_array;
//	}
//
//	// Copy constructor
//	DynamicArray(const DynamicArray& arr) : m_length(arr.m_length)
//	{
//		m_array = new T[m_length];
//
//		for (int i = 0; i < m_length; ++i)
//			m_array[i] = arr.m_array[i];
//	}
//
//	// Copy assignment
//	DynamicArray &operator=(const DynamicArray& arr)
//	{
//		if (&arr == this)
//			return *this;
//
//		delete[] m_array;
//
//		m_length = arr.m_length;
//		m_array = new T[m_length];
//
//		for (int i = 0; i < m_length; ++i)
//			m_array[i] = arr.m_array[i];
//
//		return *this;
//	}
//
//	// Move constructor
//	DynamicArray(DynamicArray&& arr) : m_length(arr.m_length), m_array(arr.m_array)
//	{
//		arr.m_length = 0;
//		arr.m_array = nullptr;
//	}
//
//	// Move assignment
//	DynamicArray &operator=(DynamicArray &&arr)
//	{
//		if (&arr == this)
//			return *this;
//
//		delete[] m_array;
//
//		m_length = arr.m_length;
//		m_array = arr.m_array;
//
//		arr.m_length = 0;
//		arr.m_array = nullptr;
//		
//		return *this;
//	}
//
//	int getLength() const { return m_length; }
//	T &operator[](int index) { return m_array[index]; }
//	const T &operator[](int index) const { return m_array[index]; }
//
//};
//
//// Return a copy of arr with all the values doubled
//DynamicArray<int> cloneArrayAndDouble(const DynamicArray<int>& arr)
//{
//	DynamicArray<int> dbl(arr.getLength());
//
//	for (int i = 0; i < arr.getLength(); ++i)
//		dbl[i] = arr[i] * 2;
//
//	return dbl;
//}
//
//class Resource
//{
//public:
//	Resource() { cout << "Resource acquired\n"; }
//	~Resource() { cout << "Resource destroyed\n"; }
//
//	friend ostream &operator<<(ostream &out, const Resource &res)
//	{
//		out << "I am a resource\n";
//		
//		return out;
//	}
//};
//
//void useResource(const unique_ptr<Resource> &res)
//{
//	if (res)
//		cout << *res;
//}
//
//Auto_ptr4<Resource> generateResource()
//{
//	Auto_ptr4<Resource> res(new Resource);
//
//	return res; // this return value will invoke the move constructor
//}
//
//template<class T>
//void swap1(T& a, T& b)
//{
//	T tmp{ move(a) }; // invokes move constructor
//	a = move(b); // invokes move assignment
//	b = move(tmp); // invokes momve assignment
//}
//
//class Field
//{
//	int field[8][8];
//};
//
//class Object
//{
//	int x, y;
//	
//public:
//	void printPos()
//	{
//		cout << setw(5);
//	}
//};
//
//void main0()
//{
//	bool bin = false;
//	function<void(bool&)> fPtr = f;
//	thread t1{ fPtr, ref(bin) };
//	fPtr = f2;
//	thread t2{ fPtr, ref(bin) };
//
//	t1.join();
//	t2.join();
//}
//
//void main1()
//{
//	int &&rref = 5;
//	rref = 10;
//	cout << rref << endl;
//
//	int x0 = 5;
//	fun(x0);
//	fun(10);
//
//	Auto_ptr4<Resource> mainres;
//	mainres = generateResource();
//
//	DynamicArray<int> arr(1000000);
//
//	for (int i = 0; i < arr.getLength(); ++i)
//		arr[i] = i;
//
//	arr = cloneArrayAndDouble(arr);
//
//	string x{ "abc" };
//	string y{ "de" };
//
//	cout << "x: " << x << '\n';
//	cout << "y: " << y << '\n';
//
//	swap1(x, y);
//
//	cout << "x: " << x << '\n';
//	cout << "y: " << y << '\n';
//
//	vector<string> v;
//	string str = "Knock";
//
//	cout << "Copying str\n";
//	v.push_back(str); // calls l-value version of push_back, which makes a copy
//
//	cout << "str: " << str << '\n';
//	cout << "vector: " << v[0] << '\n';
//
//	cout << "\nMoving str\n";
//
//	v.push_back(move(str)); // calls r-value version of push_back, which does a move
//
//	cout << "str: " << str << '\n';
//	cout << "vector: " << v[0] << ' ' << v[1] << '\n';
//
//	auto ptr = make_unique<Resource>();
//	useResource(ptr);
//
//	cout << "Ending Program\n";
//
//	{
//		int daSize = 5000;
//		DynamicArray<int> da(daSize);
//		DynamicArray<int> da2(daSize);
//
//		for (int i = 0; i < daSize; ++i)
//		{
//			swap1(da, da2);
//			swap1(da2, da);
//		}
//	}
//} // Resource is destroyed here
//
//void main2()
//{
//	char buf[10];
//	cin >> setw(10) >> buf;
//	cout << buf << endl;
//	cin >> setw(10) >> buf;
//	cout << buf << endl;
//}
//
//void f(bool& bin)
//{
//	for (int i = 0; i < 10000; ++i)
//	{
//		if (bin)
//			cout << "fTrue\n";
//		else
//			cout << "fFalse\n";
//
//		for (int j = 0; j < 100000; ++j);
//	}
//}
//
//void f2(bool& bin)
//{
//	int k = 0;
//	for (int i = 0; i < 5; ++i)
//	{
//		cin >> k;
//
//		if (k)
//			bin = true;
//
//		for (int j = 0; j < 100000000; ++j);
//
//		k = 0;
//		bin = false;
//	}
//}
//
//void fun(const int &ref)
//{
//	cout << "L-Value reference to const: " << ref << endl;
//}
//
//void fun(int &&ref)
//{
//	cout << "R-Value reference: " << ref << endl;
//}

int main()
{
	/*chrono::time_point< chrono::system_clock > start, end;

	start = chrono::system_clock::now();
	main1();
	end = chrono::system_clock::now();

	cout << "Both threads done at " << chrono::duration<double>(end - start).count() << endl;

	getchar();*/

	cout << "Hello, World!" << endl;

	return 0;
}