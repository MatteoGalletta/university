/*
CountingSort: Ordinamento su cifre
Si supponga di dover ordinare un insieme di n numeri interi, ciascuno dei quali è composto da k cifre, confrontando solo l'i-esima cifra di ciascun numero. Modificare l'algoritmo CountingSort affinché riesca a realizzare questo ordinamento. La procedura prende quindi in input, l'array A, la sua dimensione n, il numero di cifre k, e l'indice i della cifra sulla quale effettuare l'ordinamento.
*/
#include <iostream>
#include <limits.h>
#include <math.h>

using namespace std;

void countingSortByDigit(int* arr, int n, int k, int i);

int main(void) {

	//		     3    ,2    ,0    ,8    ,0    ,2    ,0    ,4
	int arr[] = {14350,20214,87012,10890,32000,95200,10010,30490};
	int n = sizeof(arr) / sizeof(*arr);
	
	countingSortByDigit(arr, n, 5, 3);
	
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	
	return 0;
}

void countingSortByDigit(int* arr, int n, int k, int idx) {
	// k=5, idx=2
	// 20214 -> 0

	const int DIGITS = 10;
	int B[n],
		C[DIGITS] = {0};
	
	//se idx > k si considera idx = k
	int k10Pow = pow(10, max(0,k-idx));
	for (int i = 0; i < n; i++)
		C[(arr[i] / k10Pow) % 10]++;
	
	for (int i = 1; i < DIGITS; i++)
		C[i] += C[i - 1];
	
	for (int i = n-1; i >= 0; i--)
		B[--C[(arr[i] / k10Pow) % 10]] = arr[i];
	
	for (int i = 0; i < n; i++)
		arr[i] = B[i];
}

