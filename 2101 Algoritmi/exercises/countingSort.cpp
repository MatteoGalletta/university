/*
CountingSort: Ordinamento in place
L'algoritmo CountingSort utilizza due array ausiliari: l'array C per il conteggio e l'array B per mantenere l'array ordinato. Fornire una variante del CountingSort che ordina gli elementi direttamente all'interno dell'array A (senza usare l'array B). Valutare se l'algoritmo ottenuto mantiene le stesse caratteristiche dell'algoritmo originale.
*/
#include <iostream>
#include <limits.h>

using namespace std;

void countingSort(int* arr, int n);
bool testIsSorted(int* arr, int n);

int main(void) {

	//int arr[] = {4,2,7,8,3,5,1,4};
	int arr[] = {6,5,6,9,3,7,4,5};
	int n = sizeof(arr) / sizeof(*arr);
	
	countingSort(arr, n);
	
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;

	for (int i = 0; i < 100; i++) {
		int tmp[n];
		for (int i = 0; i < n; i++) {
			arr[i] = tmp[i] = rand() % 10;
		}
		countingSort(arr, n);
		
		if (!testIsSorted(arr, n)) {
			cout << "--ARRAY NON ORDINATO--";
			cout << "INPUT: ";
			for (int i = 0; i < n; i++)
				cout << arr[i] << " ";
			cout << "OUTPUT: ";
			for (int i = 0; i < n; i++)
				cout << arr[i] << " ";
			break;
		}
	}		
	
	return 0;
}

bool testIsSorted(int* arr, int n) {
	for (int i = 1; i < n; i++)
		if (arr[i-1] > arr[i])
			return false;
	return true;
}

void countingSort(int* arr, int n) {
	// prendo max e min
	int M = INT_MIN, m = INT_MAX;
	for (int i = 0; i < n; i++) {
		M = max(M, arr[i]);
		m = min(m, arr[i]);
	}
	
	int C[M-m+1] = {0};
	
	// conto le occorrenze di ogni elemento
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
		C[arr[i]-m]++;
	}
	cout << endl;
	
	// metto in ogni posizione di C l'indice in cui andrebbe
	// posizionato l'elemento i.
	for (int i = 1; i <= M-m; i++) {
		C[i] += C[i-1];
	}
	
	// Scorro l'array A
	int i = 0;
	while (i < n) {
		// Prendo l'indice in cui andrebbe posizionato A
		cout << "i: " << i << " arr[i]: " << arr[i];;
		int newIdx = --C[arr[i]-m];
		cout << " newIdx: " << newIdx << endl;
	
		// Se l'indice in cui andrebbe posizionato è più piccolo di i
		// vuol dire che lo scambio è già stato effettuato..
		// Se invece newIdx è uguale a i allora l'elemento si trova nella giusta posizione.
		// In entrambi i casi, passiamo all'elemento successivo
		if (newIdx <= i) {
			i++;
			continue;
		}
		
		// Scambio l'elemento attuale con l'elemento che si trova
		// nella posizione corretta di quello attuale
		swap(arr[i], arr[newIdx]);
		
		// nota: non aumento il contatore perché altrimenti salterei l'elemento appena scambiato
	}	
	
	
}

