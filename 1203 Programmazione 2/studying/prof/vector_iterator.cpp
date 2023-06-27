/*
 * vector_iterator.cpp
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
	
	//for (int i = 0; i < v.size(); i++) {
	//	cout << i << " : " << v[i] << endl;
	//}
	
	// iterator
	for (vector<float>::iterator it = v.begin(); it != v.end(); it++) {
		*it = *it * 10.0;
	}
	
	// const iterator
	for (vector<float>::const_iterator it = v.cbegin(); it != v.cend(); it++) {
		cout << *it << endl;
	}
	
	// reverse order
	for (vector<float>::reverse_iterator it = v.rbegin(); it != v.rend(); it++) {
		cout << *it << endl;
	}
	
	
	return 0;
}

