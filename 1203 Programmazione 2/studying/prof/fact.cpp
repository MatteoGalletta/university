/*
 * fact.cpp
 */
 
#include <iostream>

int fact(int n)
{
	if (n == 0)
		return 1;
	if (n > 0)
		return n * fact(n-1);
}

int main(int argc, char*argv[])
{

	std::cout << fact(10) << std::endl; 

}

