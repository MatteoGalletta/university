---
type: university
date: 2022-12-11
subjectId: 1101
year: 1
semester: 1
---
#university #studying #subject-1101
### Applicazioni Lineari - Studio Nucleo
> [!summary] Algebra Lineare e Geometria

> **Data l'applicazione $f: V \rightarrow W$ e data la matrice associata $M(f)$ rispetto alle basi canoniche studiare il nucleo ($\ker f$).**

$$
M(f) = \left(\begin{array} -
1 & h & 0 \\ 0 & 0 & 1 \\ h & h & h \\ 1 & 0 & 0
\end{array}\right)
$$

**Studiare $\ker f$ vuol dire trovare:**
- $\dim \ker f=\dim V - \dim \text{im} f$, in questo caso $=0$ ($\dim V = 3$ e $\dim \text{im} f=3$)
- le basi di $\ker f$:
	1. Si moltiplica la matrice di $f$ per la matrice delle incognite, ponendo la matrice risultante uguale alla matrice nulla:
		$$\begin{align}
		&\left(\begin{array} -
		1 & h & 0 \\ 0 & 0 & 1 \\ h & h & h \\ 1 & 0 & 0
		\end{array}\right)
		\left(\begin{array} -
		x \\ y \\ z
		\end{array}\right) =
		\left(\begin{array} -
		0 \\ 0 \\ 0 \\ 0
		\end{array}\right)
		\\ \rightarrow
		&\left(\begin{array} -
		x+hy \\ z \\ hx+hy+hz \\ x
		\end{array}\right) =
		\left(\begin{array} -
		0 \\ 0 \\ 0 \\ 0
		\end{array}\right)
		\\ \rightarrow
		&\begin{cases}
		x+hy&=0 \\
		z&=0 \\
		hx+hy+hz&=0 \\
		x&=0
		\end{cases}
		\\ \rightarrow
		&\begin{cases}
		x&=0 \\
		y&=0 \\
		z&=0 \\
		t&=0
		\end{cases}
		\rightarrow x=y=z=t=0
		\end{align}
	$$
	2.  Otteniamo quindi una sola soluzione che è $(0,0,0,0)$. Non avendo incognite libere, non abbiamo base. Qualora dovessimo ottenere ad esempio $x=2z \land y=z \land z=3t$ avremo l'elemento generico $(2z,z,3t)$. In questo caso si prosegue generando le basi utilizzando il metodo [da Elemento Generico a Combinazione Lineare](<elemento generico#Elemento Generico $ to$ Combinazione Lineare>). Avremo quindi $\mathcal{B}=\{(2,1,0),(0,0,3)\}$. In questo caso $\dim \ker f = 2$. 
- l'equazione cartesiana di $\ker f$, è riportata sopra e viene calcolata tramite sistema: è inutile ricalcolarla. Ad ogni modo, si può ricavare tramite il metodo [da Combinazioe Lineare a Equazione Cartesiana](<combinazione lineare#Combinazione Lineare $ to$ Equazione Cartesiana>). ![[combinazione lineare#Combinazione Lineare $ to$ Equazione Cartesiana]]
