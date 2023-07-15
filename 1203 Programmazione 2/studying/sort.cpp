#include <iostream>
#include <cstdlib>

template<typename T>
void swap(T& lhs, T& rhs) {
	T tmp = lhs;
	lhs = rhs;
	rhs = tmp;
}

int partition_qucksort(int *arr, int left, int right) {
	int pivot = arr[right];
	int count = left;
	for (int i = left; i < right; i++) {
		if (arr[i] < pivot)
			swap(arr[count++], arr[i]);
	}
	swap(arr[count], arr[right]);
	return count;
}

void quicksort(int *arr, int left, int right) {

	if (left < right) {
		
		int pivot_index = partition_qucksort(arr, left, right);
		
		quicksort(arr, left, pivot_index - 1);
		quicksort(arr, pivot_index + 1, right);
	}
}

/*
	1. Prendo il pivot (ultimo elemento dell'array)
	2. Metto gli elementi più piccoli del pivot a sinistra
	3. Metto a seguire il pivot (lo scambio)
	4. Richiamo di nuovo il quicksort sulle due parti
*/
void quicksort(int* arr, int n) {
	quicksort(arr, 0, n - 1);
}

void merge_arrays(int* arr, int left, int mid, int right) {
	int n = right - left + 1;
	int arr_tmp[n];
	
	int i = 0, cl = left, cr = mid + 1;
	while (cl <= mid && cr <= right) {
		if (arr[cl] <= arr[cr])
			arr_tmp[i++] = arr[cl++];
		else
			arr_tmp[i++] = arr[cr++];
	}
	
	while (cl <= mid) arr_tmp[i++] = arr[cl++];
	while (cr <= right) arr_tmp[i++] = arr[cr++];
	
	for (i = 0; i < n; i++)
		arr[left+i] = arr_tmp[i];
	
}

/*
	1. Prendo metà array
	2. Richiamo ricorsivamente la funzione sulle due metà
	3. Ordino le due metà
*/
void mergesort(int* arr, int left, int right) {
	if (left >= right)
		return;
	
	int mid = (right - left)/2 + left;
	
	mergesort(arr, left, mid);
	mergesort(arr, mid + 1, right);
	
	merge_arrays(arr, left, mid, right);
}
void mergesort(int* arr, int n) {
	mergesort(arr, 0, n - 1);
}

void print(int *arr, int n, std::string at_end) {
	for (int i = 0; i < n; i++)
		std::cout << arr[i] << " ";
	std::cout << at_end;
}

void random_fill(int *arr, int n) {
	for (int i = 0; i < n; i++)
		arr[i] = rand() % 11;
}

int main() {

	const int n = 10;
	int arr[n];
	
	for (int i = 0; i < 20; i++) {	
		random_fill(arr, n);
		
		print(arr, n, "-> ");
		//quicksort(arr, n);
		mergesort(arr, n);
		print(arr, n, "\n");
	}

	return 0;
}
