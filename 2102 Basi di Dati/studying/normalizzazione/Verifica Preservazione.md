Gentilmente offerto da [Kevin Speranza](https://github.com/Kespers)

---
# Preservazione Dati
## Algoritmo matrici
Verifica se la decomposizione preserva i dati
$$
R = \{A,B,C,D\}
$$
$$
F=\{A\to B\}
$$
$$
R_{1} = \{A,B\} \quad R_{2}={A,C,D}
$$

creare la seguente matrice
$$
\begin{matrix}
    & \text{A} & \text{B} & C & D \\
    \text{R1} & a_{1} & a_{2} & b_{13} & b_{14}  \\
    \text{R2} & a_{1} & b_{22} & a_{3} & a_{4} \\
\end{matrix}
$$

verifico tutte le dipendenze di F, in questo caso solo: $A\to B$.

1. mi posiziono sulle colonne A, B e faccio in modo che abbiano gli stessi elementi
$$
\begin{matrix}
    & \text{A} & \text{B} & C & D \\
    \text{R1} & a_{1} & a_{2} & b_{13} & b_{14}  \\
    \text{R2} & a_{1} & \cancelto{ a_{2} }{ b_{22} } & a_{3} & a_{4} \\
\end{matrix}

\quad \implies \quad

\begin{matrix}
    & \text{A} & \text{B} & C & D \\
    \text{R1} & a_{1} & a_{2} & b_{13} & b_{14}  \\
    \text{R2} & a_{1} & a_{2} & a_{3} & a_{4} \\
\end{matrix}
$$
al termine delle operazioni, se nella riga in cui si è effettuato lo scambio si produce la sequenza $a_{1},a_{2},\dots a_{n}$ , con $n = |R|$ la decomposizione preserva i dati
- in questo caso si è prodotta la sequenza $a_{1},a_{2},a_{3},a_{4}$

## Algoritmo insiemistico
se riesco a provare che
$$
R_{1} \cap R_{2} \to R_{1}-R_{2} \quad \text{oppure} R_{1} \cap R_{2} \to R_{2} - R_{1}
$$
allora la decomposizione preserva i dati.

### esempio positivo
$$
R=\{A,B,C,D\}
$$
$$
F=\{A\to B\}
$$
$$
R_{1}=\{A,B\} \quad R_{2}=\{A,C,D\}
$$
$$
R_{1} \cap R_{2} = \{A\}
\quad
R_{1} - R_{2} = \{B\}
$$
in questo caso $R_{1} \cap R_{2} \to R_{1}-R_{2}$

### esempio negativo
$$
R=\{A,B,C,D\}
$$
$$
F=\{A\to C\}
$$
$$
R_{1}=\{A,B\} \quad R_{2}=\{A,C,D\}
$$
$$
R_{1} \cap R_{2} = \{A\} \quad\quad R_{1} - R_{2} = \{B\}
$$
siccome in $R_{1} - R_{2}$ non è presente "C" proseguo con:
$$
R_{2} - R_{1} = \{C,D\}
$$

in quanto non esiste la dipendenza:
$$
A\to CD
$$
la decomposizione non preserva i dati



# Preservazione dipendenze
una decomposizione $d$ preserva le dipendenze se:
$$
\bigcup_{i=1}^{n} \pi_{R_{i}}(F) \equiv F
$$

Siano
$$
R = \{A,B,C\}
$$
$$
F = \begin{cases}
A\to B \\
B\to C \\
C\to A
\end{cases}
$$
$$
d = \begin{cases}
R_{1} = \{A,B\} \\
R_{2} = \{B,C\}
\end{cases}
$$
verificare se $d$ preserva le dipendenze

$$
\pi_{R_{1}}(F)={A\to B} \quad\quad \pi_{R_{2}}(F)={B\to C}
$$

$$
\pi_{R_{1}}(F) \cup \pi_{R_{2}}(F) \not\equiv F
$$

