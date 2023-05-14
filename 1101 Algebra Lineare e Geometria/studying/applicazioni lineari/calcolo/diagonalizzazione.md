---
type: university
date: 2022-12-15
subjectId: 1101
year: 1
semester: 1
---
#university #studying #subject-1101
### Applicazioni Lineari - Calcolo Diagonalizzazione
> [!summary] Algebra Lineare e Geometria

> Data un'applicazione lineare generica $f: V \to W$ calcolarne la sua **diagonalizzazione**

Metodo 1:
1. Se $M(f)$ e $I$ sono [simili](simile) allora $M(f)$ è diagonalizzabile. $M(f) \text{ è diagonalizzabile} \iff M(f)$ è [semplice](semplicità).
2. Si calcola quindi la semplicità di $M(f)$, se è semplice allora la **matrice diagonalizzata** è uguale a una matrice diagonale con gli elementi nella diagonale principale che corrispondono alle molteplicità algebriche degli autovalori. Ad esempio, se $m_{\lambda_{1}}=2$ e $m_{\lambda_{2}}=1$, allora la matrice sarà:
	$$ \begin{pmatrix}
\lambda_{1} & 0 & 0 \\
0 & \lambda_{1} & 0 \\
0 & 0 & \lambda_{2}
\end{pmatrix} $$
3. Per calcolare la **matrice diagonalizzante** invece si riportano in colonna le basi degli autospazi che compongono la base del dominio. L'ordine deve coincidere con l'ordine d'inserimento degli autovalori nella matrice diagonalizzata.
	$$
\begin{pmatrix}
u_1 & u_2 & u_3
\end{pmatrix} $$
