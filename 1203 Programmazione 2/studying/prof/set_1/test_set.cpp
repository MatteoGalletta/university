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
		while (true) {
			cout << s[i] << endl;
			i++;
		}
	}
	catch (access_error err) {
		cout << "Errore numero " << err << endl;
	}
	
	return 0;
}

