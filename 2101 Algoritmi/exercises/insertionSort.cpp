/*
Ricorsione: InsertionSort ricorsivo

Sappiamo che un array è una struttura dati elementare che può essere definita ricorsivamente. Di consueguenza, molti algoritmi che operano su array possono assumere una forma ricorsiva.
Saresti in grado di fornire una versione ricorsiva dell'algoritmo InsertionSort?
Nota bene che la procedura in questione dovrà prendere come input solo l'array e la sua lunghezza.
*/
#include <iostream>

using namespace std;

void insertionSort(int* arr, int n);

int main(void) {

	int arr[] = {4,2,7,8,3,5,1,4};
	int n = sizeof(arr) / sizeof(*arr);
	
	insertionSort(arr, n);
	
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	
	return 0;
}

void insertionSort(int* arr, int n) {

	if (n <= 1)
		return;

	insertionSort(arr, n - 1);
	
	int key = arr[n - 1];
	int i = n - 2;
	while (i >= 0 && arr[i] > key) {
		arr[i + 1] = arr[i];
		i--;
	}
	
	arr[i + 1] = key;
}

