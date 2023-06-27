/*
 * string_example.cpp
 */
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char **argv)
{
	string s1 = "Hello";
	
	s1 = s1 + " world";
	
	s1.insert(5, ",");
	
	cout << s1 << endl;
	int w_pos = s1.find('c');
	
	if (w_pos != string::npos) {
		string s2  = s1.substr(w_pos, 5); // da pos = 7, 5 caratteri

		cout << s2 << endl;
	}
	
	printf("stringa C : %s\n", s1.c_str());
	
	for (int i = 0; i < s1.length(); i++) {
		cout << s1[i] << endl;
	}
	
	s1[0] = 'h';
	cout << s1 << endl;
	
	return 0;
}

