/*
 * rec_binary_search.cpp
 */
 
#include <iostream>
#include <cstdlib>

using namespace std;

template <typename T> void _swap(T& a, T& b)
{
    T tmp;

    tmp = a;
    a = b;
    b = tmp;
}

template <typename T> void selectsort(T * data, int n)
{
    for (int i = 1; i < n; i++) {
        int least_index = i;
        for (int j = i; j < n; j++) {
            if (data[j] < data[least_index])
                least_index = j;
        }
        _swap<T>(data[i-1], data[least_index]);
    }
}


template <typename T> bool Binary_search(T * data, int start, int end, T value_to_find)
{

	if (start > end)
		return false;

	int mid = (start + end) / 2;
	
	for (int i = start; i <= end; i++)
		cout << data[i] << " ";
	cout << endl;
	
	if (value_to_find == data[mid])
		return true;
		
	if (value_to_find < data[mid])
		// cerco nel sottovettore di sinistra
		return Binary_search<T>(data, start, mid - 1, value_to_find);
	else
		// cerco nel sottovettore di destra
		return Binary_search<T>(data, mid + 1, end, value_to_find);
}

template <typename T> bool Binary_search(T * data, int n, T value_to_find)
{
	return Binary_search<T>(data, 0, n - 1, value_to_find);
}


#define N 10

int main(int argc, char **argv)
{
    srand(time(NULL));
    int data[N];
    for (int i = 0; i < N; i++) {
        data[i] = (int)((float)rand() / RAND_MAX * 50);
    }
    
    selectsort<int>(data, N);
    
    for (int i = 0; i < N; i++) {
        cout << " " << data[i];
    }
    cout << endl;
    
    int val_to_search;
    cout << "Inserisci valore da cercare:";
    cin >> val_to_search;
    
    cout << Binary_search<int>(data, N, val_to_search) << endl;
    
    return 0;    

}

