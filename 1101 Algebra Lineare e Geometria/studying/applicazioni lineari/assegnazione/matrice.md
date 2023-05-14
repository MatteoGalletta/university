---
type: university
date: 2022-12-10
subjectId: 1101
year: 1
semester: 1
---
#university #studying #subject-1101
### Applicazioni Lineari - Assegnazione tramite Matrice
> [!summary] Algebra Lineare e Geometria


## Matrice $\to$ Legge
1. Si moltiplica la matrice dell'applicazione per la matrice delle incognite. Ad esempio:
$$
\left(\begin{array} -
0 & h & 1 \\ -1 & h+1 & 1 \\ 0 & h+1 & 0 \\ -1 & h & 2
\end{array}\right)
\left(\begin{array} -
x \\ y \\ z
\end{array}\right) =
\left(\begin{array} -
hy+z \\ (h+1)y-x+z \\ (h+1)y \\ hy-x+2x
\end{array}\right)
$$
2. Si prende la matrice e si pone come condizione d'esistenza dell'applicazione lineare (come legge):
$$
f(x,y,z)=(hy+z,(h+1)y-x+z,(h+1)y,hy-x+2x)
$$
## Matrice $\to$ Immagini
1. I vettori immagine corrispondono alle colonne della matrice (considerando come base del dominio la canonica).
2. Si possono utilizzare gli step [da Immagini a Matrice](<immagini#Immagini $ to$ Matrice>) per trovare le basi canoniche, qualora fossero necessarie ma la base del dominio sia diversa dalla canonica.
