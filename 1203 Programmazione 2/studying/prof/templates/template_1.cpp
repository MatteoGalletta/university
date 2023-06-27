/*
 * template_1.cc
 */
 
#include <iostream>

using namespace std;

/*
float max(float a, float b)
{
	if (a > b) return a;
	else return b;
}

int max(int a, int b)
{
	if (a > b) return a;
	else return b;
}

Persona max(Persona a, Persona b)
{
	if (a > b) return a;
	else return b;
}
*/

#include <cstring>

class String {
	char * char_array;
public:
	String(const char * s) {
		char_array = new char[strlen(s) + 1];
		strcpy(char_array, s);
	};
	String(String & s) {
		char_array = new char[strlen(s.char_array) + 1];
		strcpy(char_array, s.char_array);		
	};
	~String() { delete [] char_array; };
	bool operator>(String & rhs)
	{
		return strcmp(char_array, rhs.char_array) > 0;
	}
	friend ostream& operator<<(ostream& out, String & s);
};

ostream& operator<<(ostream& out, String & s)
{
	out << s.char_array;
	return out;
}

template <typename T> T Max(T a, T b)
{
	if (a > b) return a;
	else return b;
}


int main(int argc, char ** argv)
{
	float a = Max(1.0, 3.0); // float max(float a, float b)
	int v = Max(3, 4); // int max(int a, int b)
	String s1("Corrado");
	String s2("Giuseppe");
	String s_max = Max(s1,s2);
	cout << s_max << endl;
}

