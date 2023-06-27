/*
 * test_set.cpp
 */
 
#include "set.h"

int main(int argc, char **argv)
{
	Set s;
	
	s += 20; // s = s + 20;
	s += 2;
	s += 50;
	s += 30;
	s += 50;
	
	cout << "S: " << s << endl;
	

	int i = 0;
	
	try {
		//i = -1;
		while (true) {
			cout << s[i] << endl;
			i++;
		}
	}
	catch (RangeError & err) {
		cout << "Range error!" << err.getMessage() << endl;
	}
	
	return 0;
}

