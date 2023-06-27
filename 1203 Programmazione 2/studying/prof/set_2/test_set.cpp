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
	
	cout << s[0] << endl;
	
	try {
		i = -1;
		while (true) {
			cout << s[i] << endl;
			i++;
		}
	}
	catch (UnderflowError & err) {
		cout << "underflow!" << err.getMessage() << endl;
	}
	catch (OverflowError & err) {
		cout << "overflow!" << err.getMessage() << endl;
	}
	
	return 0;
}

