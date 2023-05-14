---
type: university
date: 2022-12-11
subjectId: 1101
year: 1
semester: 1
---
#university #studying #subject-1101
### Applicazioni Lineari - Studio Immagine
> [!summary] Algebra Lineare e Geometria


> **Data l'applicazione $f: V \rightarrow W$ e data la legge $f(x,y)=(x+y,3x-y,-2x+4y)$ studiare l'immagine ($im f$).**

1. Si calcola la matrice utilizzando [da Legge a Matrice](<legge#Legge $ to$ Matrice>).
	$$\left(\begin{array} -
	1 & 1 \\ 3 & -1 \\ -2 & 4
	\end{array}\right)
	$$
2. Si calcola il rango della matrice, in questo caso, essendo rettangolare, si riduce per riga e si contano gli elementi speciali (sono 2).
	$$\left(\begin{array} -
	1 & 1 \\ 4 & 0 \\ 0 & 0
	\end{array}\right)
	$$
3. **Studiare l'$im f$ vuol dire trovare:**
	- $\dim \space im f=\rho(M(f))$, in questo caso $=2$ ($\rho=2$)
	- le basi di $im f$, ovvero si prendono le colonne linearmente indipendenti di $M(f)$. Il numero di elementi della base deve coincidere con il $\rho$. In questo caso, sono: $\mathcal{B}=\{(1,3,-2),(1,-1,4)\}$.
	- l'equazione cartesiana di $im f$, si utilizza il metodo [da Combinazione Lineare a Equazione Cartesiana](<combinazione lineare#Combinazione Lineare $ to$ Equazione Cartesiana>) (le basi non sono altro che la combinazione lineare). ![[combinazione lineare#Combinazione Lineare $ to$ Equazione Cartesiana]] Otteniamo:
	$$\det \left(\begin{array} -
	1 & 3 & -2 \\ 1 & -1 & 4 \\ x & y & z
	\end{array}\right) = 10x-6y-4x=0$$
