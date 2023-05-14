---
type: university
date: 2022-12-10
subjectId: 1101
year: 1
semester: 1
---
#university #studying #subject-1101
### Vettori - Vettori Linearmente Indipendenti
> [!summary] Algebra Lineare e Geometria

> **Dato $V=R^4$, dato un'insieme di vettori $A=\{v1=(1,1,1,-1),v2=(0,1,0,1),v3=(0,0,2,0),v4=(2,0,0,1)\}$, verificare se l'insieme A è un insieme di vettori linearmente indipendenti**

- **Soluzione 1**: tramite la definizione di linearmente indipendente
	- Scrivere: $(x_i,y_i,z_i)=a_{1}\cdot v1 + a_{2}\cdot v2 + a_{3}\cdot v3 + a_{4}\cdot v4$
	- Moltiplicare i coefficenti per i vettori
	- Sommare i vettori: $(x_i,y_i,z_i)=(a_{1}v_{x1}+a_{2}v_{x2}+a_{3}v_{x3}, \dots)$
	- Porre a sistema, assegnando:
	$$\begin{cases}
	x_{i}=a_{1}v_{x1}+a_{2}v_{x2}+a_{3}v_{x3} \\
	y_{i}=\dots \\
	z_{i}=\dots
	\end{cases}$$
	- Isolare i coefficenti ($a_1$, $a_2$, $a_3$, $a_4$)
	- Se ci sono incognite libere, allora l'insieme **non è** linearmente indipendente, altrimenti lo è.
- **Soluzione 2**: tramite le matrici e il calcolo del rango
	- Si crea una matrice dove in ogni riga si posiziona un vettore.
	- Si calcola il rango
	- Il rango ($\rho$) indica il numero di vettori linearmente indipendenti, se coincide con il numero di vettori nell'insieme di partenza, allora si tratta di un insieme di vettori linearmente indipendenti.
