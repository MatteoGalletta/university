/*
 * vector_example.cpp
 */
 
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{
	vector<float> v;
	
	v.push_back(10.3);
	v.push_back(5.2);
	v.push_back(4.1);
	v.push_back(1.4);
	
	for (int i = 0; i < v.size(); i++) {
		cout << i << " : " << v[i] << endl;
	}
	
	return 0;
}

