---
type: university
date: 2022-12-13
subjectId: 1101
year: 1
semester: 1
---
#university #studying #subject-1101
### Applicazioni Lineari - Calcolo Polinomio Caratteristico
> [!summary] Algebra Lineare e Geometria

> Dato un endomorfismo generico $f: V \to V$, cui matrice associata rispetto alle basi canoniche risulta
> $$
M(f)=\left(\begin{array} -
2 & 1 & 0 \\
-1 & 0 & 0 \\
2 & 1 & 0
\end{array}\right)
$$
	calcolarne il polimonio caratteristico.

1. Qualora la consegna non dovesse dare la matrice ma la legge o l'immagine, procedere rispettivamente con i metodi [da Legge a Matrice](<legge#Legge $ to$ Matrice>) e [da Immagini a Matrice](immagini#<Immagini $ to$ Matrice>).
2. Seguendo la formula otteniamo:
	$$\begin{align}
	P_{M(f)}(T)&=\det (M(f) - T\cdot I)

\\&=\left|\begin{array} -
2 & 1 & 0 \\
-1 & 0 & 0 \\
2 & 1 & 0
\end{array}
\quad-\quad
\begin{matrix}
T & 0 & 0 \\ 0 & T & 0 \\ 0 & 0 & T
\end{matrix}
\right|

\\&=\left|\begin{array} -
2-T & 1 & 0 \\
-1 & -T & 0 \\
2 & 1 & -T
\end{array}
\right|

\\&=-T(T-1)^2
\end{align}
	$$
