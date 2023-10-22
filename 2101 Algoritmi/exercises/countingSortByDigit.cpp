/*
CountingSort: Ordinamento su cifre
Si supponga di dover ordinare un insieme di n numeri interi, ciascuno dei quali è composto da k cifre, confrontando solo l'i-esima cifra di ciascun numero. Modificare l'algoritmo CountingSort affinché riesca a realizzare questo ordinamento. La procedura prende quindi in input, l'array A, la sua dimensione n, il numero di cifre k, e l'indice i della cifra sulla quale effettuare l'ordinamento.
*/
#include <iostream>
#include <limits.h>

using namespace std;

void countingSortByDigit(int* arr, int n, int k, int i);

int main(void) {

	int arr[] = {1435,20214,87012,1089,32,952,10010,3049};
	int n = sizeof(arr) / sizeof(*arr);
	
	countingSortByDigit(arr, n, 5, 2);
	
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	
	return 0;
}

void countingSortByDigit(int* arr, int n, int k, int idx) {

	// k=6, i=3, o=5
	// 105240
	// 105240 >> k-i=6-3=3	->	105 % 10 = 5

	int B[10] = {0},
		C[n];
	
	for (int i = 0; i < n; i++) {
		C[(arr[i] >> (k-idx)) % 10]++;
	}
	
	for (int i = 1; i < n; i++)
		C[i] += C[i - 1];
	
	for (int i = 0; i < n; i++)
		B[--C[(arr[i] >> (k-idx)) % 10]] = arr[i];
	
	for (int i = 0; i < n; i++)
		arr[i] = B[i];
}

