/*
Ricorsione: l'abbinamento dei piatti di portata

Si supponga di gestire un ristorante e di avere a disposizione n diversi piatti di portata. In serata tutti gli n posti a sedere disponibili nel ristorante sono stati prenotati da n clienti distinti. Nell'effettuare la prenotazione ogni cliente ha specificato le sue preferenze culinarie. In base a tali preferenze è possibile stilare una tabella (matrice) M, dove la cella M[i][j] contiene il grado di apprezzamento del cliente i-esimo nei confronti del piatto di portata j-esimo.
Si fornisca una funzione ricorsiva che riesca a definire il migliore abbinamento cliente/piatto in modo da massimizzare la somma dei gradi di apprezzamento dei clienti. La funzione calcolerà, appunto, il valore di tale somma.
Si tenga conto che ogni cliente può mangiare solo una portata e che ogni portata può essere preparata per un solo cliente.
*/
#include <iostream>

using namespace std;

#define N_MAX_PLATES 8

int restaurantPlatesMax(int M[][N_MAX_PLATES], int n);

int main(void) {

	int M[][N_MAX_PLATES] = {
		{3,2,4,3,2,10,15,20},
		{5,8,1,4,9,2,3,10},
		{1,10,3,5,8,4,10,40},
		{4,10,3,5,8,4,10,40},
		{1,10,6,5,6,4,10,15},
		{9,10,3,5,8,4,10,20},
		{2,10,3,5,8,4,12,40},
		{3,10,3,1,10,4,10,40}
	};
	
	int n = sizeof(M) / sizeof(*M);
	
	cout << "n: " << n << endl
		 << "restaurantPlatesMax: " << restaurantPlatesMax(M, n) << endl;

	return 0;
}

int restaurantPlatesMax(int M[][N_MAX_PLATES], int n) {
	if (n == 0)
		return 0;
	
	int m = 0;
	for (int i = 0; i < n; i++) {
		swap(M[i], M[n-1]);
		m = max(m, restaurantPlatesMax(M, n-1) + M[n-1][n-1]);
		swap(M[i], M[n-1]);
	}
	
	return m;
}

