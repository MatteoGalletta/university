---
type: university
date: 2022-12-10
subjectId: 1101
year: 1
semester: 1
---
#university #studying #subject-1101
### Spazi Vettoriali - Assegnazione tramite Combinazione Lineare
> [!summary] Algebra Lineare e Geometria

## Combinazione Lineare $\to$ Equazione Cartesiana

#### Esempio matrice quadrata: $\mathfrak{L} = \{v_{1}=(1, 1, 0), v_{2}=(1, 0, 1)\}$
1. Si mettono nella matrice i vettori, uno per riga:
$$A = \left( \begin{array} -
1 & 1 & 0 \\ 1 & 0 & 1 \\ x & y & z
\end{array} \right)\begin{array} -
1 & 1 \\ 1 & 0 \\ x & y
\end{array}$$
2. Si calcola il determinante della suddetta matrice:
$$\det A = x-z-y$$
4. Il sottospazio finale sarà: $\{(x, y, z) \in \mathbb{R}^{3} \space | \space x-z-y=0 \}$

#### Esempio matrice rettangolare: $\mathfrak{L} = \{v_{1}=(-1, 0, 0, 1), v_{2}=(2, 0, 1, -1)\}$
1. Si mettono nella matrice i vettori, uno per riga:
$$
\left(\begin{array} -
-1 & 0 & 0 & 1 \\ 2 & 0 & 1 & -1 \\ x & y & z & t
\end{array}
\right)
$$
2. Si riduce per riga la suddetta matrice:
$$\begin{align}
&R_{2} \rightarrow R_{2} + 2R_{1} \\
&R_{3} \rightarrow R_{3} + xR_{1} \\
&R_{3} \rightarrow R_{3} - (t+x)R_{2}
\end{align}
$$
$$
\left(\begin{array} -
-1 & 0 & 0 & 1 \\ 0 & 0 & 1 & 1 \\ 0 & y & z-t-x & 0
\end{array}
\right)
$$
3. Si mettono a sistema gli elementi dell'ultima riga ponendoli $=0$
$$
\begin{cases}
y=0 \\
z-t-x=0
\end{cases}
\rightarrow
\begin{cases}
y=0 \\
z=x+t
\end{cases}
$$
- Quindi si ottiene: $\{(x, 0, x+t, t) \in \mathbb{R}^{3} \}$

## Combinazione Lineare $\to$ Elemento Generico

1. Uguale a [da Combinazione Lineare a Equazione Cartesiana](<combinazione lineare#Combinazione Lineare $ to$ Equazione Cartesiana>)
2. Si pongono uno uguale all'altro gli elementi dell'ultima riga: $y=z-t-x=0$
3. Diventa quindi:
	$$
	\begin{cases}
y=0 \\
z=x+t
\end{cases}
$$
