/*
 * test_set.cpp
 */
 
#include "set.h"

int main(int argc, char **argv)
{
	SetDuplicates s1;
	
	s1 += 10;
	s1 += 20;
	s1 += 10;
	cout << "S1: " << s1 << endl;
	
	Set s;
	
	s += 20; // s = s + 20;
	s += 2;
	s += 50;
	s += 30;
	s += 50;
	
	cout << "S: " << s << endl;
	
	Set s2;
	s2 += 10;
	s2 += 15;
	s2 += 30;
	cout << "S2: " << s2 << endl;
	
	Set s3 = s + s2;
	cout << "S3: " << s3 << endl;

/*	
	s -= 50;
	s -= 1;
	
	cout << "S: " << s << endl;

	Set s1 = s;
	
	cout << "S1: " << s1 << endl;
	
	s1 -= 20;
	cout << "S: " << s << endl;
	cout << "S1: " << s1 << endl;
	
	Set s2;
	s2 += 10;
	s2 += 15;
	s2 += 30;
	cout << "S2: " << s2 << endl;
	
	SetDuplicates s3 = s1 + s2;
	cout << "S3: " << s3 << endl;
	
	SetDuplicates s4 = s1 - s2;
	cout << "S4: " << s4 << endl;
	
	for (int i = 0; i < s.length();i++) {
		cout << s[i] << endl;
	}
	
*/	
	return 0;
}

