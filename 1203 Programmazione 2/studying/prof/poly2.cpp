/*
 * namespace_example.cpp
 */
 #include <iostream>
 
 using namespace std;
 
 namespace calc {
 	void Max(int * a, int n, int & _max);
 	void Max(float * a, int n, float & _max);
 };
 
void calc::Max(int * a, int n, int & _max)
{
	cout << "Computing Max of ints" << endl;
 	_max = a[0];
 	for (int i = 1; i < n;i++) {
 		if (a[i] > _max)
 			_max = a[i];
 	}
}
 

void calc::Max(float * a, int n, float & _max)
{
	cout << "Computing Max of floats" << endl;
 	_max = a[0];
 	for (int i = 1; i < n;i++) {
 		if (a[i] > _max)
 			_max = a[i];
 	}
}
 
int main(int argc, char * argv[])
{
	cout << "Insert array size:";
	int n;
	cin >> n;
	float * array = new float[n];
	for (int i = 0; i < n;i++) {
		cout << "Insert element "<< i << ":";
		cin >> array[i];
	}
	float MAX;
	calc::Max(array, n, MAX);
	cout << "Max is " << MAX << endl;
	delete [] array;
	return 0;
}

