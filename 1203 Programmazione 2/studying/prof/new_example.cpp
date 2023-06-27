/*
 * new_example.cpp
 */
 #include <iostream>
 
 void calc_max_min(int * a, int n, int * _max, int * _min)
 {
 	*_max = a[0];
 	*_min = a[0];
 	for (int i = 1; i < n;i++) {
 		if (a[i] > *_max)
 			*_max = a[i];
 		if (a[i] < *_min)
 			*_min = a[i];
 	}
 }
 
int main(int argc, char * argv[])
{
	std::cout << "Insert array size:";
	int n;
	std::cin >> n;
	int * array = new int[n];
	for (int i = 0; i < n;i++) {
		std::cout << "Insert element "<< i << ":";
		std::cin >> array[i];
	}
	int MAX, MIN;
	calc_max_min(array, n, &MAX, &MIN);
	std::cout << "Max is " << MAX << std::endl;
	std::cout << "Min is " << MIN << std::endl;
	delete [] array;
	return 0;
}

