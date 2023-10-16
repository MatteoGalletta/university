#include <iostream>
#include <limits.h>

using namespace std;

void heapSort(int* arr, int n);
void buildMaxHeap(int* arr, int n);
void heapify(int* arr, int n, int i);
void extractMax(int* arr, int& n);
void insert(int* arr, int &n, int k);
void increaseKey(int *arr, int i, int k);

void merge_heaps(int* arr1, int n1, int* arr2, int n2, int* out);

void print(int* arr, int n) {
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main(void) {

	int arr[20] = {4,2,7,8,3,5,1,6};
	int n = 8;//sizeof(arr) / sizeof(*arr);
	
	buildMaxHeap(arr, n);
	print(arr, n);
	
	cout << "max: " << arr[0] << endl;
	
	insert(arr, n, 15);
	print(arr, n);
	
	heapSort(arr, n);
	print(arr, n);
	
	int arr2[20] = {3,8,5,9,1,6,4,2};
	int out[20];
	buildMaxHeap(arr, n);
	buildMaxHeap(arr2, n);
	
	merge_heaps(arr, n, arr2, n, out);
	print(out, 2*n);
	
	
	return 0;
}

/*
int* merge_heaps(int* arr1, int n1, int* arr2, int n2) {
	int* out, iterator;
	out = iterator = malloc(sizeof(int) * (n1+n2));
	while (n1 == 0 && n2 == 0) {
		int m1 = n1 > 0 ? arr1[0] : INT_MIN;
		int m2 = n2 > 0 ? arr2[0] : INT_MIN;
		if (m1 > m2) {
			arr1++; n1--;
			iterator[0] = m1;
		}
		else {
			arr2++; n2--;
			iterator[0] = m2;
		}
		
		iterator++;
	}
	return out;
}
*/

void merge_heaps(int* arr1, int n1, int* arr2, int n2, int* out) {
	if (n1 == 0 && n2 == 0)
		return;
	
	int m1 = n1 > 0 ? arr1[0] : INT_MIN;
	int m2 = n2 > 0 ? arr2[0] : INT_MIN;
	if (m1 > m2) {
		arr1++; n1--;
		out[0] = m1;
	}
	else {
		arr2++; n2--;
		out[0] = m2;
	}
	
	merge_heaps(arr1, n1, arr2, n2, out+1);
}


/*
void merge_heaps(int* arr1, int n1, int* arr2, int n2, int* out) {
	if (n1 == 0 && n2 == 0)
		return;
	
	int m1 = n1 > 0 ? arr1[0] : INT_MIN;
	int m2 = n2 > 0 ? arr2[0] : INT_MIN;
	if (m1 > m2) {
		extractMax(arr1, n1);
		out[0] = m1;
	}
	else {
		extractMax(arr2, n2);
		out[0] = m2;
	}
	
	merge_heaps(arr1, n1, arr2, n2, out+1);
}
*/

/*
// si assume che out sia allocata con almeno n1+n2 celle
void merge_heaps(int* arr1, int n1, int* arr2, int* n2, int* out) {
	if (n1 == 0 && n2 == 0)
		return;
	
	int m1 = n1 > 0 ? arr1[0] : INT_MIN;
	int m2 = n2 > 0 ? arr2[0] : INT_MIN;
	if (m1 > m2) {
		extractMax(arr1, n1);
		out[0] = m1;
	}
	else {
		extractMax(arr2, n2);
		out[0] = m2;
	}
	
	merge_heaps(arr1, n1, arr2, n2, out+1);
}
*/

void insert(int* arr, int &n, int k) {
	increaseKey(arr, n++, k);
}

void increaseKey(int *arr, int i, int k) {
	arr[i] = k;
	int p = i;
	while (p = (p-1)/2, (i > 0 && arr[p] < arr[i])) {
		swap(arr[p], arr[i]);
		i = p;
	}
}

void extractMax(int* arr, int& n) {
	swap(arr[0], arr[--n]);
	heapify(arr, n, 0);
}

void heapify(int* arr, int n, int i) {
	int r = (i+1)*2;
	int l = r-1;
	int m = i;
	if (l < n && arr[l] > arr[m])
		m = l;
	if (r < n && arr[r] > arr[m])
		m = r;
	if (m != i) {
		swap(arr[i], arr[m]);
		heapify(arr, n, m);
	}
}

void buildMaxHeap(int* arr, int n) {
	for (int i = (n-1)/2; i >= 0; i--)
		heapify(arr, n, i);
}

void heapSort(int* arr, int n) {
	buildMaxHeap(arr, n);
	int m = n;
	for (int i = 0; i < n; i++)
		extractMax(arr, m);
}

