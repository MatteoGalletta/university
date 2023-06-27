/*
 * namespace_example.cpp
 */
 #include <iostream>
 
 using namespace std;
 
 namespace calc {
 	void Min(int * a, int n, int & _min);
 	void Max(int * a, int n, int & _max);
 	void Avg(int * a, int n, float & _avg);
 	namespace test {
 		void myfunc();
 	};
 };
 
 void calc::test::myfunc()
 {
 	//...
 }
 
 void calc::Min(int * a, int n, int & _min)
{
 	_min = a[0];
 	for (int i = 1; i < n;i++) {
 		if (a[i] < _min)
 			_min = a[i];
 	}
 }
 
void calc::Max(int * a, int n, int & _max)
{
 	_max = a[0];
 	for (int i = 1; i < n;i++) {
 		if (a[i] > _max)
 			_max = a[i];
 	}
}
 
void calc::Avg(int * a, int n, float & _avg)
{
	float sum = 0;
 	for (int i = 0; i < n;i++) {
 		sum += a[i];
 	}
 	_avg = sum / n;
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
	float AVG;
	calc::Max(array, n, MAX);
	calc::Min(array, n, MIN);
	calc::Avg(array, n, AVG);
	cout << "Max is " << MAX << endl;
	cout << "Min is " << MIN << endl;
	cout << "Mean is " << AVG << endl;
	delete [] array;
	return 0;
}

