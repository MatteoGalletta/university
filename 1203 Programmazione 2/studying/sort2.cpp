#include <iostream>
#include <cstdlib>

template<typename T>
void swap(T& lhs, T& rhs) {
	T tmp = lhs;
	lhs = rhs;
	rhs = tmp;
}

int partition(int *arr, int from, int to) {
	int& pivot = arr[to];

	int count = from;
	for (int i = from; i < to; i++) {
		if (arr[i] < pivot)
			swap(arr[count++], arr[i]);
	}
	swap(arr[count], pivot);

	return count;
}

void quicksort(int *arr, int from, int to) {
	if (from >= to)
		return;
	
	int mid = partition(arr, from, to);

	quicksort(arr, from, mid - 1);
	quicksort(arr, mid + 1, to);
}

void quicksort(int *arr, int n) {
	quicksort(arr, 0, n - 1);
}

void merge(int* arr, int from, int mid, int to) {
	int size = to - from + 1;
	int tmp[size], i = 0;

	int count_left = from, count_right = mid + 1;
	while (count_left <= mid && count_right <= to) {
		tmp[i++] = (arr[count_left] < arr[count_right])
			? arr[count_left++]
			: arr[count_right++];
	}

	while (count_left <= mid)
		tmp[i++] = arr[count_left++];
	while (count_right <= to)
		tmp[i++] = arr[count_right++];
	
	for (int j = 0; j < size; j++)
		arr[j + from] = tmp[j];
}

void mergesort(int* arr, int from, int to) {
	if (from >= to)
		return;
	
	int mid = (to - from)/2 + from;
	mergesort(arr, from, mid);
	mergesort(arr, mid + 1, to);

	merge(arr, from, mid, to);
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
		quicksort(arr, n);
		//mergesort(arr, n);
		print(arr, n, "\n");
	}

	return 0;
}
