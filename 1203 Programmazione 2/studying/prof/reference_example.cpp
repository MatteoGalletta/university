/*
 * new_example.cpp
 */
 #include <iostream>
 
 using namespace std;
 
 void calc_max_min(int * a, int n, int & _max, int & _min)
 {
 	_max = a[0];
 	_min = a[0];
 	for (int i = 1; i < n;i++) {
 		if (a[i] > _max)
 			_max = a[i];
 		if (a[i] < _min)
 			_min = a[i];
 	}
 }
 
int main(int argc, char * argv[])
{
	cout << "Insert array size:";
	int n;
	cin >> n;
	int * array = new int[n];
	for (int i = 0; i < n;i++) {
		cout << "Insert element "<< i << ":";
		cin >> array[i];
	}
	int MAX, MIN;
	calc_max_min(array, n, MAX, MIN);
	cout << "Max is " << MAX << endl;
	cout << "Min is " << MIN << endl;
	delete [] array;
	return 0;
}

