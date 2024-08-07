---
type: university
date: 2023-10-12
subjectId: 2101
year: 2
semester: 1
---
#university #in-class #subject-2101
### 2023-10-12
> [!summary] Algoritmi

L'heap viene rappresentato da un array.

Il nodo root sarà il primo elemento dell'array, le due foglie del nodo root saranno il secondo e il terzo elemento, e così via (a livelli).

Come accedere agli elementi dell'heap rappresentato da un array?

Il figlio sinistro di un nodo si calcola con $2 \times i$, dove $i$ è l'indice dell'elemento del nodo attuale. Per il figlio destro è sufficiente sommare uno, ottenendo: $2 \times i + 1$. Gli indici partono da 1.

```cpp
int left(int* A, int i)  { return A[i * 2]; } // oppure A[i << 1];
int right(int* A, int i) { return A[i * 2 + 1]; } // oppure A[(i << 1) + 1];
```

Per accedere al padre basta dividere per due (e ignorare la parte decimale).
```cpp
int parent(int* A, int i) { return A[i/2]; } // oppure A[i >> 1];
```

L'heapsize non è quindi un puntatore ma un indice che punta all'ultimo elemento dell'array. Coincide con il numero di elementi presenti nell'array.
Il length invece è il numero di celle dell'array allocate (e non necessariamente utilizzate).

Le operazioni diventano:
```cpp
// si assume che l'indice dell'array parta da 1 
class Heap {
	int *A, n, heapify;
	
	// ...

	int left(int i)   { return i * 2; }
	int right(int i)  { return i * 2 + 1; }
	int parent(int i) { return i / 2; }

	int max() {
		return A[1];
	}
	
	int heapify(int i) {
		int l = left(i);
		int r = right(i);
		int m = i;
		if (l <= heapsize && A[m] < A[l])
			m = l;
		if (r <= heapsize && A[m] < A[r])
			m = r;
		if (m != i) {
			swap(A[i], A[m]);
			heapify(m);
		}
	}

	int extract_max() {
		swap(A[1], A[heapsize--]);
		heapify(1);
	}

	void increase_key(int i, int k) {
		A[i] = k;
		int p;
		p = parent(i);
		while (i > 1 && A[p] < A[i]) {
			swap(A[i], A[p]);
			i = p;
			p = parent(i);
		}
	}

	void insert(int k) {
		increase_key(++heapsize, k);
	}
}
```

Esempio di domanda:
> Supponiamo di avere un heap vuoto e di inserire un elemento alla volta della seguente sequenza di elementi: `[2, 7, 9, 1, 2, 4, 6, 11, 8]`. Rappresentare l'heap (l'array) ad ogni passo d'inserimento.


Se si ha un array che rappresenta un albero che non rispecchia però le condizioni di ordinamento parziale (ci sono dei nodi più piccoli dei figli) dell'heap, si può utilizzare la seguente funzione:
```cpp
void buildMaxHeap(int* A, int n) {
	for (int i = n/2; i >= 0; i--)
		heapify(A, i);
}
```
La complessità è $O(n)$.

### Heapsort

1. Si richiama il buildMaxHeap sull'array da ordinare $O(n)$
2. Si fa l'extractMax sul nuovo array finché non si svuota $O(n \cdot \log n)$

```cpp
void heapSort(int *A, int n) {
	buildMaxHeap(A, n);
	for (int i = 1; i < n; i++) // n-1 iterazioni
		extractMax(A);
}
```

È comparabile al MergeSort come efficienza, ma lavora in loco.
A differenza dell'InsertionSort e MergeSort, l'heapsort non è adattivo (impiega sempre la stessa quantità di tempo anche sell'array è ordinato).

> [!question] È stabile?
> No. Controesempio:
> ```
2A 1B 2B 1A |
2B 1B 1A | 2A
1A 1B | 2B 2A
1B | 1A 2B 2A
| 1B 1A 2B 2A
> ```

