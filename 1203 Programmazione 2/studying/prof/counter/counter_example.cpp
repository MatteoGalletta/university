/*
 * counter_example.cpp
 */

#include <iostream>
#include "counter.h"

using namespace std;

int main(int argc, char **argv)
{
	GenericCounter c;
	
	c.up(2);
	c += 3;
	cout << c << endl;
	
	c.down(1);
	c -= 2;
	cout << c << endl;
	
	c = 3;
	cout << c << endl;
	
	OneStepCounter c1;
	
	c1 += 1;
	c1 ++;
	
	c1 -= 1;
	cout << c1 << endl;
	
	//c1 -= 2;
	
	NonNegativeCounter c2;
	c2 += 1;
	c2 += 1;
	cout << c2 << endl;
	
	c2 -= 1;	
	cout << c2 << endl;
	c2 -= 1;	
	cout << c2 << endl;
	c2 -= 1;	
	cout << c2 << endl;
	
	
	
	return 0;
}

