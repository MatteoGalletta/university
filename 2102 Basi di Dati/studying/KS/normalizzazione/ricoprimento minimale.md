Gentilmente offerto da [Kevin Speranza](https://github.com/kespers).

dato il seguente schema di attributi $R$ e dipendenze funzionali $F$
$$
R = \{A,B,C,D,E\}
$$
$$
F= \cases{
AB\to CDE, \\
	AC\to BDE,\\
	B\to CE,\\
	C\to BD\\
}
$$
calcolare il ricoprimento minimale

1. devo avere solo dipendenze del tipo $X\to Y$ con $Y$ singolo attributo.
 $$
 F= \begin{cases}
 AB\to C, \\
 	AB\to D,\\
 	AB\to E,\\
 	AC\to B.\\
 	AC\to D,\\
 	AC\to E,\\
 	B\to C,\\
 	C\to B,\\
 	C\to D,\\
 	B\to E\\
 \end{cases}
 $$

2. prendendo le dipendenze funzionali con almeno 2 attributi a sinistra, si ipotizza di ometterne uno per dimostrare che la chiusura della nuova dipendenza è uguale a quella iniziale, meno l'attributo omesso.
 ipotizzo di omettere la $A$ in $AB \to C$, calcolo $B^+$
 $$
 B^+=\{B,C,D,E\}
 $$
 potrò scrivere quindi $B\to C$.
 applico lo stesso procedimento per tutte le dipendenze con 2 o più attributi ed ottengo:
 $$
  F= \begin{cases}
 \cancelto{ B\to C }{ AB\to C }, \\
 \cancelto{ B\to D }{ AB\to D },\\
 \cancelto{ B\to E }{ AB\to E },\\
 \cancelto{ C\to E }{ AC\to B }.\\
 \cancelto{ C\to D }{ AC\to D },\\
 \cancelto{ C\to E }{ AC\to E },\\
 B\to C,\\
 C\to B,\\
 C\to D,\\
 B\to E\\
 \end{cases}
 
 \quad \implies \quad
 
  F = \begin{cases}
 B\to C \\
 B\to D \\
 B\to E \\
 C\to B \\
 C\to D \\
 C\to E \\
 B\to C,\\
 C\to B,\\
 C\to D,\\
 B\to E\\
 \end{cases}
 
 \quad \underset{ \text{elimino le ripetizioni} }{ \implies } \quad
 
 F = \begin{cases}
 B\to C \\
 B\to D \\
 B\to E \\
 C\to B \\
 C\to D \\
 C\to E \\
 \end{cases}
 
 $$

3. prendere l'insieme delle dipendenze funzionali e per ognuna dimostrare di poter implicare il secondo membro ipotizzando che la dipendenza attuale non esista
 ometto $B\to D$ e calcolo $B^+$
 $$
 B^+_{\text{iniziale}}=\{B,D,C,E\} \equiv B^+_{\text{omettendo "} B\to D \text{"}}=\{B,D,C,E\}
 $$
 
 uso lo stesso approccio per le altre dipendenze e ottengo:
 
 $$
 F = \begin{cases}
  B\to C \\
  \cancel{ B\to D } \\
  \cancel{ B\to E } \\
  C\to B \\
  C\to D \\
  C\to E \\
  \end{cases}
 
 \implies
 
 F = \begin{cases}
  B\to C \\
  C\to B \\
  C\to D \\
  C\to E \\
  \end{cases}
 $$

#attensionplis 
al fine di non perdere tempo, controllare solo le dipendenze in cui la lettera a sinistra o a destra è ripetuta più di una volta.