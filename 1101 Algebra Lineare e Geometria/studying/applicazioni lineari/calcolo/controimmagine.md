---
type: university
date: 2022-12-12
subjectId: 1101
year: 1
semester: 1
---
#university #studying #subject-1101
## Applicazioni Lineari - Calcolo Controimmagine
> [!summary] Algebra Lineare e Geometria

> Data un'applicazione lineare generica $f: V \to W$ con $V$ e $W$ due $K$-spazi vettoriali cui legge è $f(x,y,z,t) = (x+y,z,y-t,x-t)$, trovare $f'(1,0,1,1)$.

Trovare $f'(1,0,1,1)$ vuol dire risolvere $f(x,y,z,t)=(1,0,1,1)$.
1. Si mette a sistema la legge con il vettore fornito:
	$$
	\begin{cases}
x+y=1 \\
z=0 \\
y-t=1 \\
x-t=1
\end{cases} \to \begin{cases}
x=\frac{1}{2} \\
z=0 \\
t=-\frac{1}{2} \\
y=\frac{1}{2}
\end{cases}
	$$
2. In questo caso la soluzione è una, ovvero: $f'(1,0,1,1)=(\frac{1}{2},\frac{1}{2},0,-\frac{1}{2})$.

- Se si ha la matrice da consegna, si usa [da Matrice a Legge](<matrice#Matrice $ to$ Legge>).
- Se si hanno le immagini da consegna, si usa [da Immagini a Legge](<immagini#Immagini $ to$ Legge>)
