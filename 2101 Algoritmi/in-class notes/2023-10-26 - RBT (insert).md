---
type: university
date: 2023-10-26
subjectId: 2101
year: 2
semester: 1
---
#university #in-class #subject-2101
### 2023-10-26
> [!summary] Algoritmi
## BST: Binary Search Trees
Il **BST** è posizionale. Consideriamo 4 configurazioni:
- Nodo senza figli
- Nodo con figlio destro
- Nodo con figlio sinistro
- Nodo con entrambi i figli.
Se non fosse posizionale non faremo distinzione tra figlio destro e figlio sinistro (il figlio non avrebbe una posizione rispetto al padre).

Ricordando la definizione di BST. Ogni nodo deve essere più grande di **tutti** i nodi del sotto albero sinistro e più piccolo di tutti i nodi del sotto albero di destra (l'ordinamento è totale, non parziale).

Tutte le operazioni richiedono tempo logaritmico, ma nel caso peggiore il tempo diventa lineare. Questo si può evitare realizzando una struttura dati che sia in grado di "eliminare" il caso pessimo autobilanciandosi. Queste strutture si dicono **alberi autobilancianti** (tra i più famosi, AVL, Zig-Zag Trees, RB Trees).

Gli alberi rosso neri effettuano un ribilanciamento in tempo logaritmico (a volte anche costante).

## Red-Black Trees

Ogni nodo ha un'informazione aggiuntiva: un bit che indica il colore (rosso o nero).

Le regole di un albero rosso-nero sono 5:
1. Ogni nodo dell'albero dev'essere colorato nero o rosso
2. La radice dev'essere nera
3. Tutte le foglie devono essere nere. Spesso questa regola viene *rilassata*:
	- Si assume che i figli di ogni foglia (*null*) siano neri.
	- Oppure, si crea un nodo nero e si collegano tutti i puntatori dei figli delle foglie a questo nodo unico.
4. Un nodo rosso deve avere necessariamente figli neri.
5. Tutti i cammini da ogni nodo verso ogni foglia devono avere lo stesso numero di nodi neri.

Un ramo con tutti i nodi neri si dice **compatto**.
Identifichiamo con $bh(x)$ il numero di nodi neri a partire da un nodo verso tutti i suoi cammini verso le foglie (si assume che sia un albero rosso-nero valido).
Identifichiamo con $h(x)$ l'altezza dell'albero (ovvero il numero di nodi neri e rossi a partire da un nodo verso tutti i suoi cammini verso le foglie).
$$ 2bh(x)+1 \geq h(x) \geq bh(x)$$

Grazie alle proprietà dell'albero rosso nero, vale la seguente disuguaglianza: $h \leq 2\cdot \ln (n+1)$.

Il ribilanciamento avviene attraverso delle operazioni di rotazione.

La operazioni di rotazione mantengono l'ordinamento totale, ma non garantiscono la permanenza delle 5 regole dei RBT.

#### Inserimento di un nodo
```mermaid
graph TD;
D((D))
```
##### Padre nero
Se il padre del nodo da inserire è nero, posso aggiungere il nuovo nodo come rosso, e ho risolto.
```mermaid

graph TD;

X((X))-->D((D))

style X fill:BLACK,color:WHITE
style D fill: RED
```
##### Padre rosso
Il nonno è sicuramente nero (non possono esistere due nodi rossi consecutivi).
Si aggiunge il nodo come rosso e si effettuano delle operazioni.
###### Caso 1: zio rosso
Il nonno diventa rosso
Il padre e lo zio diventano neri
Si richiama ricorsivamente la funzione `Fixup` sul nonno.
```mermaid
graph LR;
subgraph before[ ]
X((X))-->Y((Y))
X((X))-->Z((Z))
Y((Y))-->D((D))
Y((Y))-->NIL(( ))

style X fill:BLACK,color:WHITE
style D fill:RED

style NIL fill:BLACK,color:WHITE
style Y fill:RED
style Z fill:RED
end
before-->after
subgraph after[ ]

X1((X))-->Y1((Y))
X1((X))-->Z1((Z))
Y1((Y))-->D1((D))
Y1((Y))-->NIL1(( ))

style X1 fill:RED
style D1 fill:RED

style NIL1 fill:BLACK,color:WHITE
style Y1 fill:BLACK,color:WHITE
style Z1 fill:BLACK,color:WHITE
end
```
###### Caso 2: figlio esterno (sinistro), zio nero
Si effettua una rotazione destra sul padre.
Il (vecchio) nonno diventa rosso, il (vecchio) padre nero (si scambiano il colore)
```mermaid
graph LR;
subgraph before[ ]
X((X))-->Y((Y))
X((X))-->Z((Z))
Y((Y))-->D((D))
Y((Y))-->NIL(( ))

style X fill:BLACK,color:WHITE
style D fill:RED

style NIL fill:BLACK,color:WHITE
style Y fill:RED
style Z fill:BLACK,color:WHITE
end
before-->after
subgraph after[ ]

Y1((Y))-->D1((D))
Y1((Y))-->X1((X))
X1((Y))-->NIL1(( ))
X1((X))-->Z1((Z))

style X1 fill:RED
style D1 fill:RED

style NIL1 fill:BLACK,color:WHITE
style Y1 fill:BLACK,color:WHITE
style Z1 fill:BLACK,color:WHITE
end
```
###### Caso 3: figlio interno (destro), zio nero
Si effettua la rotazione sinistra sul nodo e ci si ritrova nel caso 2.
```mermaid
graph LR;
subgraph before[ ]

X1((X))-->Y1((Y))
X1((X))-->Z1((Z))
Y1((Y))-->NIL1(( ))
Y1((Y))-->D1((D))

style X1 fill:BLACK,color:WHITE
style D1 fill:RED

style NIL1 fill:BLACK,color:WHITE
style Y1 fill:RED
style Z1 fill:BLACK,color:WHITE
end
before-->after
subgraph after[ ]
D((D))-->Y((Y))
X((Y))-->D((D))
X((X))-->Z((Z))
D((D))-->NIL(( ))

style X fill:BLACK,color:WHITE
style D fill:RED

style NIL fill:BLACK,color:WHITE
style Y fill:RED
style Z fill:BLACK,color:WHITE
end

```

**I tre casi precedenti valgono in maniera speculare**.
