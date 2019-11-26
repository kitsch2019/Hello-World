// MathClient.cpp : Client app for MathLibrary DLL.
// #include "pch.h" Uncomment for Visual Studio 2017 and earlier
#include <iostream>
#include <windows.h>
using namespace std;
typedef void(*PINIT)(const unsigned long long a, const unsigned long long b);
typedef bool(*NEXT)();
typedef unsigned(*INDEX)();
typedef unsigned long long(*CURRENT)();
int main()
{
	HMODULE hDLL = LoadLibrary(L"../../../DLL/MathLibrary/Debug/MathLibrary.dll");
	if (hDLL == NULL) {
		cout << "获取动态链接库失败";
	}
		PINIT fibonacci_init = (PINIT)GetProcAddress(hDLL, "fibonacci_init");
		INDEX fibonacci_index = (INDEX)GetProcAddress(hDLL, "fibonacci_index");
		NEXT fibonacci_next = (NEXT)GetProcAddress(hDLL, "fibonacci_next");
		CURRENT fibonacci_current = (CURRENT)GetProcAddress(hDLL, "fibonacci_current");
	// Initialize a Fibonacci relation sequence.
	fibonacci_init(1, 1);
	// Write out the sequence values until overflow.
	do {
		std::cout << fibonacci_index() << ": "
			<< fibonacci_current() << std::endl;
	} while (fibonacci_next());
	// Report count of values written before overflow.
	std::cout << fibonacci_index() + 1 <<
		" Fibonacci sequence values fit in an " <<
		"unsigned 64-bit integer." << std::endl;
	FreeLibrary(hDLL);
	return  0;
}