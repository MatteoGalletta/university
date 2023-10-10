/*
Ricorsione: il problema della più lunga sotto-sequenza flip-max

Una sequenza numerica, di lunghezza n, si dice flip-max se l'elemento di posizione i è più grande (o uguale) dell'elemento di posizione n-1-i, per i <=n/2.
Ad esempio la sequenza <4,2,7,8,3,5,1,4> è una sequenza flip-max, mentre la sequenza <3,4,5,1,6,3,1> non lo è poiché 5 (posizione 2) è più piccolo di 6 (posizione 4).
Si fornisca una funzione ricorsiva che, data in input un sequenza numerica di lunghezza n, calcoli la lunghezza della più lunga sotto-sequenza flip-max in essa contenuta.
La funzione dovrà prendere in input solo la stringa e la sua lunghezza.
*/
#include <iostream>

int longestFlipMaxSequence(int* arr, int n);

int main(void) {

	int arr[] = {4,2,7,8,3,5,1,4};
	int n = sizeof(arr) / sizeof(*arr);
	
	std::cout << "n: " << n << std::endl
		<< "longestFlipMaxSequence(arr, n): " << longestFlipMaxSequence(arr, n) << std::endl;

	return 0;
}

int longestFlipMaxSequence(int* arr, int n) {

	if (n == 0) // per una sequenza vuota ovviamente ritorniamo 0
		return 0;
	if (n == 1) // per una sequenza con un solo elemento ritorniamo 1
		return 1;

	// se il primo elemento è maggiore uguale dell'ultimo, allora potrebbe essere il caso
	// in cui n attuale coincide con la sequenza massima.
	if (arr[0] >= arr[n - 1]) {
		// Questo può avvenire solo se la longestFlipMaxSequence escludendo il primo e
		// l'ultimo numero è uguale a n - 2.
		int res = longestFlipMaxSequence(arr+1, n-2) + 2;
		if (res == n) // Se è così, abbiamo trovato la lunghezza massima
			return n;
	}
	// Altrimenti prendiamo il massimo tra le due sequenza di lunghezza n-1 che si ottengono
	// escludendo il primo e l'ultimo elemento.
	return std::max(
		longestFlipMaxSequence(arr, n-1),
		longestFlipMaxSequence(arr+1, n-1)
	);
}

/*
// Soluzione meno performante
int longestFlipMaxSequence(int* arr, int n) {

	if (n == 0) // per una sequenza vuota ovviamente ritorniamo 0
		return 0;
	if (n == 1) // per una sequenza con un solo elemento ritorniamo 1
		return 1;

	// scorriamo gli elementi della sequenza e verifichiamo che rispettino la condizione di flipMax.
	for (int i = 0; i < n/2; i++)
		// se troviamo una coppia di elementi che non rispettano la condizione, vuol dire che sicuramente la sequenza flipMax più lunga è minore di n.
		if (arr[i] < arr[n-i-1])
			// Proviamo quindi con le due sequenza di lunghezza n-1 che si ottengono escludendo il primo e l'ultimo elemento della sequenza, e prendiamo il massimo tra le due.
			return std::max(
				longestFlipMaxSequence(arr+1, n-1),
				longestFlipMaxSequence(arr, n-1));
	
	// se scorriamo tutta la sequenza ed è valida, allora la lunghezza più lunga è quella attuale (n)
	return n;
}*/

