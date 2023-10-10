/*
Ricorsione: Il problema del resto

Si supponga di dover implementare una procedura che sia in grado di fornire automaticamente il resto a seguito di un pagamento. A tal fine si supponga di avere a disposizione delle monete di n tagli differenti, e sia T un array di n elementi contenente il valore dei tagli disponibili. Si supponga, inoltre, sia R il valore del resto da fornire, con R maggiore o uguale a 0.
Si fornisca la definizione risorsiva utile al calcolo del minimo numero di monete necessarie per fornire esattamente un resto pari a R.
(Si supponga che, per ogni taglio T[i], siano disponibili infinite monete)
*/
#include <iostream>
#include <limits.h>

using namespace std;

int resto(int *T, int n, int R);

int main() {

	int T[] = { 1, 2, 50, 70, 100 };
	int n = sizeof(T) / sizeof(*T);
	int R = 140;

	cout << "resto()" << resto(T, n, R) << endl;

	return 0;
}

int resto(int *T, int n, int R) {
	
	cout << "R: " << R << endl;
	if (R == 0)
		return 0;
	if (n == 0)
		return INT_MAX;
	
	int m = resto(T, n - 1, R);
	if (T[n - 1] <= R) {
		m = min(m, 1 + resto(T, n, R - T[n - 1]));
	}
	
	return m;
}

/*
int resto(int *T, int n, int R) {
	
	cout << "R: " << R << endl;
	
	if (R == 0)
		return 0;
	
	int m = INT_MAX;
	for (int i = 0; i < n; i++) {
		if (T[i] <= R) {
			m = min(m, 1 + resto(T, n, R - T[i]));
		}
	}
	
	return m;
}
*/

