/*
 * fib.cpp
 */
 
#include <iostream>

int fib(int n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	if (n > 1)
		return fib(n-1) + fib(n-2);
}

int main(int argc, char*argv[])
{

	for (int i = 0; i < 10;i++) {
		std::cout << fib(i) << std::endl; 
	}
}

