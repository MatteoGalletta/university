/*
Ricorsione: il campo da tennis

Si supponga di disporre di un campo da tennis, che viene regolarmente affittato ad ore. Le richieste di prenotazione del campo arrivano sempre entro le ore 19:00 del giorno precedente. Ogni giorno il campo apre alle 9:00 e chiude alle 20:00. Si supponga di aver ricevuto n richieste di prenotazione, dove l'i-esima richiesta impegnerebbe il campo dall'ora B[i] fino all'ora F[i]. Non tutte le richieste possono essere soddisfatte, poiché è possibile che alcune di esse richiedano di utilizzare il campo durante la medesima ora. Si fornisca quindi una funzione ricorsiva in grado di calcolare il massimo numero di ore in cui si riesce ad impegnare il campo da tennis, portando quindi a massimizzare il guadagno della giornata.
*/
#include <iostream>

using namespace std;

int tennisFieldMaxYield(int* B, int *F, int n);
int tennisFieldMaxYield(int* B, int *F, int n, bool* busyHours);

int main(void) {

	int B[] = {3,2,4,3,2,10,15,20};
	int F[] = {7,4,8,7,9,13,19,24};
	
	int n = sizeof(B) / sizeof(*B);
	
	cout << "n: " << n << endl
		 << "tennisFieldMaxYield: " << tennisFieldMaxYield(B, F, n) << endl;

	return 0;
}

int tennisFieldMaxYield(int* B, int *F, int n) {
	bool busyHours[24] = { false };
	return tennisFieldMaxYield(B, F, n, busyHours);
}

int tennisFieldMaxYield(int* B, int *F, int n, bool* busyHours) {
	if (n == 0) // esco se non ci sono prenotazioni
		return 0;
	
	// itero per tutte le ore della prima prenotazione
	for (int i = B[0]; i < F[0]; i++)
		if (busyHours[i]) // l'ora attuale è già occupata
			// siccome c'è almeno un ora prenotata, devo skippare per forza la prenotazione
			return tennisFieldMaxYield(B+1, F+1, n-1, busyHours);
	
	// tutte le ore della prenotazione sono libere
	
	// salto la prenotazione attuale
	int skip = tennisFieldMaxYield(B+1, F+1, n-1, busyHours);
	
	// seleziono la prenotazione attuale
	for (int i = B[0]; i < F[0]; i++) busyHours[i] = true;
	int take = tennisFieldMaxYield(B+1, F+1, n-1, busyHours) + (F[0] - B[0]);
	for (int i = B[0]; i < F[0]; i++) busyHours[i] = false;
	
	// prendo la migliore tra le due
	return max(skip, take);
}

