$$
R = \{a,b,c,d,e\}
$$
$$
F = \begin{cases}
ab\to cde,\\
	ac\to bde, \\
	b\to c,\\
	c\to b,\\
	c\to d,\\
	b\to e
\end{cases}
$$

calcolo le variabili
```
//non a destra
ND = {A} 

//sia a sx che a dx
SD = {B,C}
```

formo l'insieme:
```
// ND :: SD
cand = {
	{A} :: {B,C}
}
```

finche cand non è vuoto, estraggo il primo elemento

creo le seguenti variabili
```
//parte sx dell'elemento
X = {A}

//parte a destra
Y = {B,C}
```

vado a calcolare $X^+$ quindi $A^+$
$$
X^+=A^+=\{A\}
$$
se $X^+$ è uguale a tutti gli attributi, allore è chiave.
altrimenti, come in questo caso, calcolo la seguente formula:
$$
Y-X^+=\{B,C\}-\{A\}=Z
$$

aggiungo a cand i nuovi candidati:
$$
cand =
cand 
\cup
\begin{cases}
\{X,Z_{1}\}::\{Z_{2},Z_{3},\dots ,Z_{n}\}, \\
\{X,Z_{2}\} :: \{Z_{3},Z_{4},\dots ,Z_{n}\}, \\
\dots, \\
\{X,Z_{n}\} :: \emptyset
\end{cases}
$$

ora cand sarà uguale a:
```
cand = {
	{A,B} :: {C},
	{A,C} :: empty
}
```

si ricomincia il ciclo:
non è vuoto quindi estraggo il primo elemento
```
 {AB}::{C}
```

calcolo $AB^+$
$$
AB^+=\{A,B,C,D,E\}
$$
$AB^+$ è chiave -> riparto con il ciclo

```
cand = {
	{A,C} :: empty
}
```

estraggo e calcolo $AC^+$
$$
AC^+=\{A,C,B,D,E\}
$$
AC è chiave

ora cand è vuoto -> l'algoritmo restituisce
$$
\text{chiavi} = \{AB,AC\}
$$
