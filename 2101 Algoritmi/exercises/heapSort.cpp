#include <iostream>

using namespace std;

void heapSort(int* arr, int n);
void buildMaxHeap(int* arr, int n);
void heapify(int* arr, int n, int i);
void extractMax(int* arr, int& n);
void insert(int* arr, int &n, int k);
void increaseKey(int *arr, int i, int k);

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
	
	return 0;
}

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

