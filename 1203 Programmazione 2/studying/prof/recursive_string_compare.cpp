/*
 * string_compare.cpp
 */

#include <iostream>

using namespace std;
 
bool string_compare(char * s1, char * s2)
{
	if (s1[0] == 0 && s2[0] == 0)
		return true;
	if (s1[0] != s2[0])
		return false;
	else
		return string_compare(s1 + 1, s2 + 1);
}

int main(int argc, char * argv[])
{

	cout << string_compare("hello", "hello") << endl;
	cout << string_compare("hell", "hello") << endl;
	cout << string_compare("hello", "hell") << endl;
	cout << string_compare("hello", "") << endl;

	return 0;
}


