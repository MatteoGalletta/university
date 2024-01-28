---
type: university
date: 2023-10-17
subjectId: 2101
year: 2
semester: 1
---
#university #in-class #subject-2101
### 2023-10-17
> [!summary] Algoritmi


Il TimSort è l'algoritmo di ordinamento più veloce al momento (non lo trattiamo) basato sui confronti.

I problemi di ordinamento che utilizzano il confronto non possono fare meglio di $\Omega(n \log n)$.
### Counting Sort
Non si basa sui confronti.
Complessità: $O(n+k-h)$, con $k$ l'elemento massimo e $h$ l'elemento minimo.

`A=[4,6,2,4,4,3,2,3,7]`
`C=[2,2,3,0,1,1]`

```cpp
void countingSort(int* A, int n) {
	int k, h; // k: massimo - h: minimo
	max_min(A, n, &k, &h); // prende il massimo e il minimo dell'array
	int* C = new int[k-h+1]; // C conterrà già 0 in tutte le celle
	for (int i = 0; i < n; i++) {
		int idx = A[i]-h;
		C[idx]++;
	}

	int c = 0;
	for (int i = 0; i < k-h+1; i++) // scorro gli elementi di C
		for (int j = 0; j < C[i]; j++) {
			A[c] = i+h;
			c++;
		}

}
```

> [!warning] Nota
> L'implementazione precedente non funziona con dati satellite. L'algoritmo non è stabile.

---

Per risolvere il problema, si effettua un'ulteriore iterazione per aggiornare `C`.
`A=[4,6,2,4,4,3,2,3,7]`
`C=[2,2,3,0,1,1] -> [2,4,7,7,8,9]`

`C=[0,2,4,7,7,8]` (a fine algoritmo)
`B=[2,2,3,3,4,4,4,6,7]` (a fine algoritmo)

Adesso `C[i]` indica il numero di elementi minori o uguali a `i` in `A`.

Si può quindi scorrere `A` per trovare in `C` l'indice in cui posizionare l'elemento.
La nuova implementazione non consente più di modificare direttamente l'array `A`. È necessario un array ausiliario (che chiamiamo `B`).

```cpp
int* countingSort(int* A, int n) {
	int k, h; // k: massimo - h: minimo
	max_min(A, n, &k, &h); // prende il massimo e il minimo dell'array
	int* C = new int[k-h+1]; // C conterrà già 0 in tutte le celle
	for (int i = 0; i < n; i++) {
		int idx = A[i]-h;
		C[idx]++;
	}

	for (int i = 1; i < k-h+1; i++)
		C[i] += C[i-1];
	
	int* B = new int[n];
	for (int i = n - 1; i >= 0; i--) { // scorro A
		int idx = A[i]-h; // mi chiedo: dove cerco in C la corrispondenza?
		C[idx]--;
		int pos = C[idx]; // C[idx] contiene la posizione in cui inserire A[i]
		B[pos] = A[i];
	}
	
	return B;
}
```

> [!done] Nota
> Adesso l'algoritmo funziona con dati satellite ed è stabile (in quanto scorriamo da destra verso sinistra).
2A 1B 2B 1A