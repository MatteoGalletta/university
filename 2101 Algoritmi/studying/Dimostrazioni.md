---
type: university
date: 2024-02-03
subjectId: 2101
year: 2
semester: 1
---
#university #studying #subject-2101
### 2024-02-03
> [!summary] Algoritmi

Di seguito degli appunti per ripassare molto velocemente i passaggi delle varie dimostrazioni.
### Heap
#### Proprietà Invariante
#### Build Max-Heap
**Thm**: "la complessità di BuildMaxHeap è $O(n)$"
**Proof**:
- si ricorda che: un heap di $n$ elementi ha altezza $\lfloor \log n \rfloor$ e al più $\lceil \frac{n}{2^{h-1}} \rceil$ nodi radici di sotto-alberi di altezza $h$.
- si scrive $T(n)$, ovvero come somma del costo di ogni livello.
- Si sostituisce, si semplifica, e si riconduce alla serie notevole $\sum\limits_{n=0}^{+\infty} n\cdot x^{n} = \frac{x}{(1-x)^{2}}$
### Hash Maps
#### Metodo concatenazione
##### Ricerca Senza Successo
**Thm**: "Il tempo atteso di ricerca senza successo di un elemento in un hash map con metodo di concatenazione è $\Theta (1 + \alpha)$"
**Proof**:
- $1$ è il tempo di calcolare $h(x_{i})$
- $\alpha$ è il tempo necessario per scorrere tutti gli elementi.
##### Ricerca Con Successo
**Thm**: "Il tempo atteso di ricerca con successo di un elemento in un hash map con metodo di concatenazione è $\Theta (1 + \alpha)$"
**Proof**:
- Si definisce $X_{ijq}$
- Si definisce $Y_{j}$
- Si definisce $Z$
- Si cerca di calcolare $\mathbb{E}[Z]$, sostituendo $Z$, semplificando, portando fuori.
#### Metodo indirizzamento aperto
*si assume che $\alpha < 1$ (e non $\alpha\leq0$ - cioè la hash map non è piena)*
##### Ricerca Senza Successo
**Thm**: "Il numero atteso di prove in una ricerca senza successo di un elemento in un hash map a indirizzamento aperto è $\frac{1}{1-\alpha}$"
**Proof**:
- Si definisce $X$ e $A_{i}$
- Si definisce $\{X \geq i\}$
- Si calcola $\Pr[\{X \geq i\}]$
- Si calcola $\mathbb{E}[X]$, dividendo la serie in due, prendendo la serie resto.
##### Ricerca Con Successo
**Thm**: "Il numero atteso di prove in una ricerca con successo di un elemento in un hash map a indirizzamento aperto è $\frac{1}{\alpha} \cdot \ln(\frac{1}{1-\alpha})$"
**Proof**:
- Si giustifica $\frac{m}{m-1}$ "se $k$ è l'$(i+1)$-esimo elemento a essere stato inserito..."
- Si fa la media di tutte le chiavi
- Si porta fuori dalla serie, si scrive in funzione di k, si sostituisce con l'integrale, si raccoglie $m$

### Red Black Trees
#### Altezza massima
**Thm**: "Un RBT ha altezza al più $2\log (n+1)$"
**Proof**:
- si dimostra il Lemma "Il sotto-albero radicato a $x$ contiene almeno $2^{bh(x)}-1$ nodi interni"
	- si usa l'induzione
- $h^{*}$ #todo

### Programmazione Dinamica
#### Sottostruttura ottima
Si dimostra che un problema gode della proprietà della sottostruttura ottima dimostrando che ipotizzando che non utilizzi un sottoproblema non ottimo si arriva a una contraddizione.
- Rod-Cut
- Parentesizzazione Matrici
- LCS

### Programmazione Greedy

