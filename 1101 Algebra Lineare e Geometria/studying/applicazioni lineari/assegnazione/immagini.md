---
type: university
date: 2022-12-10
subjectId: 1101
year: 1
semester: 1
---
#university #studying #subject-1101
### Applicazioni Lineari - Assegnazione tramite Immagini
> [!summary] Algebra Lineare e Geometria

$$\begin{cases}
f(e_1)=(0,-1,0,-1)\\
f(0,1,1)=(h+1,h+2,h+1,h+2)\\
f(1,1,0)=(h,h,h+1,h-1)
\end{cases}
$$
## Immagini $\to$ Legge

- **Soluzione 1**
	1. Si scrive un equazione del tipo: $(x,y,z)=a \cdot \mathcal{v}_{1} + b \cdot \mathcal{v}_{2} + \dots + c \cdot \mathcal{v}_{n}$, dove $v_{i}$ è il vettore della base del dominio (quello che nella definizione delle immagini viene messo a primo membro dentro la funzione lineare). Nel nostro caso:
	$$\begin{align}
	(x,y,z)&=a \cdot e_{1} + b \cdot (0,1,1) + c \cdot (1,1,0) \to \\
	\to (x,y,z)&=a \cdot (1,0,0) + b \cdot (0,1,1) + c \cdot (1,1,0)
	\end{align}
	$$
	2. A sistema si trovano $a$, $b$ e $c$.
	$$\begin{cases}
	x = a \cdot 1 + b \cdot 0 + c \cdot 1 \\
	y = a \cdot 0 + b \cdot 1 + c \cdot 1 \\
	z = a \cdot 0 + b \cdot 1 + c \cdot 0
	\end{cases}\rightarrow
	\begin{cases}
	x = a + c \\
	y = b + c \\
	z = b
	\end{cases}\rightarrow
	\begin{cases}
	a = x - y + z \\
	b = z \\
	c = y - z
	\end{cases}
	$$
	3. Si sostituiscono $a$, $b$ e $c$ all'equazione iniziale, quindi otteniamo:
	$$
	(x,y,z)=(x-y+z) \cdot (1,0,0) + z \cdot (0,1,1) + (y-z) \cdot (1,1,0)
	$$
	4. Si sostituiscono i vettori base del dominio e $(x,y,z)$ con le loro applicazioni lineari, come segue:
	$$
	f(x,y,z)=(x-y+z) \cdot f(1,0,0) + z \cdot f(0,1,1) + (y-z) \cdot f(1,1,0)
	$$
	5. Si calcolano le immagini delle applicazioni lineari precedentemente inserite (si prendono da sopra, dalle immagini che abbiamo già da consegna):
	$$
	f(x,y,z)=(x-y+z) \cdot (0,-1,0,-1) + z \cdot (h+1,h+2,h+1,h+2) + (y-z) \cdot (h,h,h+1,h-1)
	$$
	6. Si sommano i vettori con le relative incognite e si inseriscono all'interno del vettore.
$$\begin{align}
f(x,y,z)&=(0+z(h+1)+(y-z)h, (x-y+z)(-1)+z(h+2)+(y-z)h, 0+z(h+1)+(y-z)(h+1),(x-y+z)(-1)+z(h+2)+(y-z)(h-1)) \\
&=(zh+z+yh-zh, -x+y-z+zh+2z+yh-zh, zh+z+yz+y-zh-z, -x+y-z+zh+2z+yh-y-zh+z) \\
&=(z+yh, -x+y+z+yh, yz+y, -x+2z+yh)
\end{align}
$$
- **Soluzione 2** (non sono sicuro)
	1. Si trovano le basi canoniche come illustrato in [da Immagini a Matrice](<immagini#Immagini $ to$ Matrice>).
	2. Si utilizza il metodo della *matrice Z*. Il metodo è uguale a [da Combinazione Lineare a Equazione Cartesiana](<combinazione lineare#Combinazione Lineare $ to$ Equazione Cartesiana>).
- **Soluzione 3**
	1. Si trovano le basi canoniche come illustrato in [da Immagini a Matrice](<immagini#Immagini $ to$ Matrice>).
	2. Si usa il metodo [da Matrice a Legge](<matrice#Matrice $ to$ Legge>)
## Immagini $\to$ Matrice

1. Se le immagini non sono della base canonica, è necessario trovare quelle canoniche. Si trovano quindi $e_1$, $e_2$ ed $e_3$ 
	$$\begin{align}
	f(0,1,1)&=f(0e_{1}+1e_{2}+1e_{3})=f(e_2)+f(e_{3})\\
	f(1,1,0)&=f(1e_{1}+1e_{2}+0e_{3})=f(e_1)+f(e_{2})
	\end{align}
	$$
	Si ricavano quindi le basi canoniche a sistema.
$$\begin{cases}
f(e_1)=(0,-1,0,-1)\\
f(e_2)=(h,h+1,h+1,h)\\
f(e_3)=(1,1,0,2)
\end{cases}$$
2. Si mettono per colonna le immagini trovate all'interno della matrice:
$$\begin{align*}
&\quad\space\space\begin{array} -
e_{1}\space\space&e_{2}\space\space&e_{3}
\end{array}
\\
&\left(\begin{array} -
0 & h & 1 \\ -1 & h+1 & 1 \\ 0 & h+1 & 0 \\ -1 & h & 2
\end{array}\right)\end{align*}$$
