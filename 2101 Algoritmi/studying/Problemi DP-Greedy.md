---
type: university
date: 2024-02-10
subjectId: 2101
year: 2
semester: 1
---
#university #studying #subject-2101
### 2024-02-10
> [!summary] Algoritmi

## Programmazione Dinamica
### LCS: Longest-Common-Subsequence
$$
dp[i, j] = \begin{cases}
0 \qquad& i=0 \lor j=0 \\
dp[i-1, j-1]+1 \qquad& i,j>0 \,\land\, x_{i}=y_{j} \\
\max(dp[i-1, j], dp[i, j-1]) \quad& i,j>0 \,\land\, x_{i}\neq y_{j}
\end{cases}
$$
#### Ricostruzione soluzione
$$\pi[i,j] = \begin{cases}
\text{nil} \qquad& \text{se } i=0 \lor j=0 \\
\nwarrow \qquad& \text{se } i,j > 0 \land x_{i}=y_{j} \\
\uparrow \qquad& \text{se } i,j > 0 \land x_{i}\neq y_{j} \,\land\, dp[i-1, j] \geq dp[i, j-1] \\
\leftarrow \qquad& \text{se } i,j > 0 \land x_{i}\neq y_{j} \,\land\, dp[i-1, j] < dp[i, j-1]
\end{cases}$$
### Rod-Cutting
$$
dp[i] = \begin{cases}
0 \qquad& \text{se } i=0\\
\max\limits_{1 \leq k \leq n}(dp[i - w_{k}] + v_{k}) \qquad& \text{se } i > 0
\end{cases}
$$
#### Ricostruzione soluzione
$$
\pi[i] = k \text{ tale che } dp[i-w_{k}]+v_{k} \text{ è il massimo}
$$
### Matrix Chain Multiplication
`[1, 5, 8, 3, 24]`
`1x5 * 5x8 * 8x3 * 3*24`
$$
dp[i,j] = \begin{cases}
0 &\text{se } i=j \\
\max\limits_{1\leq k<j}(dp[i, k]+dp[k+1, j] + m_{i-1}\cdot m_{k}\cdot m_{j})  &\text{se } i< j
\end{cases}
$$
#### Ricostruzione soluzione
$$
\pi[i, j] = k \text{ tale che } dp[i, k]+dp[k+1, j] + m_{i-1}\cdot m_{k}\cdot m_{j} \text{ è il massimo}
$$
### Knapsack 0-1
$$
dp[n, W] = \begin{cases}
0 &\text{se } n=0 \lor W=0 \\
\max(dp[n-1, W - w_{n-1}] + v_{n-1}, dp[n-1, W]) &\text{se } n,W>0 \land w_{n-1} < W
\end{cases}
$$

---
## Programmazione Greedy
### Activity Selection
si ordina per tempo di fine attività e si prende la più piccola
### Knapsack Fractional
si ordina per rapporto valore/peso e si prende il migliore
### Huffman
si prendono i due più piccoli e si crea un nuovo nodo con la somma. guarda [[Teoria_PDF#Algoritmo di Huffman|qui]].
