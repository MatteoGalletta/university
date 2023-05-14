---
type: university
date: 2022-12-15
subjectId: 1101
year: 1
semester: 1
---
#university #studying #subject-1101
### Applicazioni Lineari - Calcolo Autovalore
> [!summary] Algebra Lineare e Geometria

> Data un'applicazione lineare generica $f: V \to W$, calcolarne gli autovalori.

1. Si calcola il polinomio caratteristico come da metodo [Calcolo Polinomio Caratteristico](polinomio caratteristico>).
2. Si trovano gli zeri del polinomio caratteristico, si pone quindi $P(T) = 0$.
3. Per completezza, si trova anche la **Molteplicità Algebrica**, quindi si conta il numero di volte in cui viene ripetuta una soluzione (si guarda l'esponente).
	Ad esempio, se $P(T)=(T-1)^2(T-2)(T+1)=0$ allora $m_{1}=2$, $m_{2}=1$ e $m_{-1}=1$.
	Sono utili per la [[diagonalizzazione]]:
	$$
	\begin{pmatrix}
1 & 0 & 0 & 0 \\ 0 & 1 & 0 & 0 \\ 0 & 0 & 2 & 0 \\ 0 & 0 & 0 & -1
\end{pmatrix}
$$

