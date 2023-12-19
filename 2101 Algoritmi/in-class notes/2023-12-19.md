---
type: university
date: 2023-12-19
subjectId: 2101
year: 2
semester: 1
---
#university #in-class #subject-2101
### 2023-12-19 - label correcting
> [!summary] Algoritmi

### Algoritmo di Dijkstra
L'insieme $V$ è diviso in due sottoinsiemi: ${} S$ e $V-S$:
- $S$ contiene i nodi che sono portati a convergenza.
- In $V-S$ sono presenti sia i nodi non portati a convergenza ($d[v] > \delta(s, v)$), sia quelli portati a convergenza ancora da individuare ($d[v] = \delta(s, v)$)

L'algoritmo si basa sul'assunzione che, in seguito a tutti i rilassamenti a partire da un nodo portato a convergenza, in $V-S$ sia presente almeno un elemento portato a convergenza, e quest'ultimo coincide con il nodo per cui $d[v]$ è minimo in $V-S$.
Se esistessero archi con peso negativo questa assunzione sarebbe sbagliata.

Avendo la necessità di prendere il nodo con $d[v]$ minimo, si presta bene l'implementazione di $d$ con una coda con priorità [[2023-10-10 - heap|Min-Heap]].

*nel codice l'insieme $S$ non esiste, perché non serve salvare gli elementi. Vengono utilizzati soltanto quando vengono spostati e nel codice coincidono con la variabile `u`*
```
DIJKSTRA (G, w, s):
	FOR v IN G.V:                 O(V)
		d[v] = +INF
		PI[v] = NULL
	d[s] = 0
	Q = BuildMinHeap(G.V)         O(V)
	FOR i=1 TO |G.V|:             O(V)
		u = extractMin(Q)         O(log V)
		FOR e IN G.Adj(u):        O(E)
			RELAX(u, v, w)        O(log V)
```
La complessità è $O(|E|\log |V|+|V|\log |V|)=O((|V|+|E|)\log |V|)$.
## Complessità Algoritmi Label Correcting

| Algoritmo    | Liste        | Matrici      |
| ------------ | ------------ | ------------ |
| Dijkstra     | O((V+E) * logV) | O(V^2 * log V) | 
| Bellman-Ford | O(VE)        | O(V^3)       |
| Dag-SP       | O(V+E)       | O(V^2)       |

## Componenti Connesse
Sono dei sottografi per cui esiste un cammino da ogni nodo verso tutti gli altri (e quindi sono necessari cicli).

Si consideri un grafo formato da componenti connesse. Non possono esistere cicli da una componente all'altra.
Se esistesse, le due componenti connesse sarebbe da considerarsi come un'unica.
