Gentilmente offerto da [Kevin Speranza](https://github.com/kespers).
>[!attention] attensionplis 
> - se lo schema è in BCNF allora è anche 3NF
> - dipendenza banale: $X \to X$
> - prima di effettuare le verifiche:
> 	- applicare l'algorimo di [[ricoprimento minimale]]
# Boyce Codd (BCNF)
> [!info] definizione
> Uno schema relazionale è in **BCNF** se per ogni dipendenza non banale di $F^+$, saranno del tipo $X\to A$
> - X superchiave (è una chiave o la contiene)
## Algoritmo
>[!info] output algoritmo
> Dato uno schema R e dipendenze funzionali F, l'algortimo restituisce una decomposizione in BCNF che preserva i dati

>[!attention] finezza da scrivere
>"la decomposizione trovata non è l’unica, dipende dall’ordine con cui vengono analizzate le dipendenze"

> [!hint] passaggi
> ad ogni chiamata si decompone F in 2 sottorelazionicon annessi insiemi di dipendenze funzionali e ricorsivamente si controllano le condizioni BCNF.
> 
> Sia X->A la dipendenza che viola:
> $$
> \begin{align}
> &R_{i}=X^+\\
> & F_{i} = \pi_{R_{i}}(F) \\
>  \\
> & R_{i+1}=R - (R_{i}-X) \\
> & F_{i+1}=\pi_{R_{i+1}}(F-F_{i})
> \end{align}
> $$
> - R: insieme di attributi controllato
> - F: insieme di dipendenze funzionali

>[!example] Esempio
> ```
> R(A,B,C,D,E,F)
> F = {
> 	A-> B,
> 	C -> DE,
> 	F->A
> }
> ```
> la chiave è CF. si calcola con l'[[algoritmo chiavi]].
> 
> A->B viola la bcnf (A non è una chiave).
> ```
> R1 = X+ = A+ = {A,B}
> F1(A->B) [rispetta BCNF]
> 
> R2 = R - (R1 - X) = {A,B,C,D,E,F} - {A,B - A} = {A,B,C,D,E,F} - {B} = {A,C,D,E,F}
> F2(C -> DE, F->A)
> ```
> 
> in R2 "C->DE" viola la bcnf:
> ```
> R2 = C+={cde}
> F2(c->de) [rispetta BCNF]
> 
> R3 = {acdef} - (cde - c) = {acdef} - {de} = {acf}
> F3(F->A)
> ```
> 
> in R3 "F -> A" viola la bcnf:
> ```
R3 = X+ = F+ = {AF}
F3 = {F -> A} [rispetta BCNF]
> 
> R4 = R - (R3 - X) = {acf} - (af - f) = acf - a = {cf}
> F4 = {} [rispetta BCNF]
> ```
> la decomposizione finale sarà la seguente:
> ```
> R1(a,b) F1(a->b)
> R2(c,d,e) F2(c->de)
> R3(a,f) F3(f->a)
> R4(c,f) F4()
> ```
# Terza forma normale (3NF)
>[!info] definizione
>Uno schema relazionale è in **3NF** se per ogni dipendenza $X\to A$ non banale
> -  $X$ è una superchiave
> oppure
> -  $A$ è primo (appartiene a qualche chiave)

## Algoritmo

$$
F = \begin{cases}
A_{1},A_{2}\to A_{4} \\
A_{1}\to A_{3}
\end{cases}
$$
$$
R = \{A_{1},A_{2},A_{3},A_{4},A_{5},A_{6}\}
$$

trasformare in 3NF

1. creo una tabella formata dagli attributi non presenti in F
$$
R_{1}=\{A_{5},A_{6}\}
$$
2. per ogni dipendenza di F creo una tabella apposita
$$
R_{2}=\{A_{1},A_{2},A_{4}\} \quad R_{3} = \{A_{1},A_{3}\}
$$

>[!attention] "X" ridondanti
> nel caso in cui F sia del tipo
> $$
> F = \begin{cases}
> A_{1},A_{2}\to A_{4} \\
> A_{1}\to A_{3} \\
> A_{1} \to A_{7}
> \end{cases}
> $$
> 
> al posto di creare un ulteriore tabella, unisco l'attributo alla tabella già esistente
> $$
> \cancel{ R_{4}=\{A_{1},A_{7}\} } \implies R_{3}=\{A_{1},A_{3},A_{7}\}
> $$

>[!attention] preservazione dati
>se vogliamo far preservare i dati, creiamo una tabella che contiene una chiave:
>$$R_{4}=\{\text{chiave}\}$$

## Verifica forma normale con più decomposizioni

>[!hint] soluzione generale
>nel caso chieda di verificare se la decomposizione sia in qualche forma normale (avendo più di una decomposizione) sarà necessario per ogni decomposizione: 
>1. estendere l'insieme di dipendenze funzionali
>2. verificare le condizioni della forma normale in question (con F estesa)
>   
> per ogni decomposizione calcolare:
> $$
> F_{i}=\pi_{R_{i}}(F)
> $$
> e verificare se $F_{i}$ rispetta la forma normale rispetto ad $R_i$

### esempio di domanda
> [!question] data la decomposizione
> ```
> R1(A,B)
> R2(B,D,E)
> R3(B,C)
> ```
> e le dipendenze
> ```
> F = {
> b->c,
> c->de
> }
> ```
> 
> - È in qualche forma conosciuta? motivare la risposta ed stendere gli schemi con le rispettive dipendenze funzionali

### soluzione

#### estendo F
##### calcolo $F_1$
1. calcolo le seguenti chiusure:
$$
\begin{align}
& A^+=\{A\} \\
& B^+=\{B,C,D,E\} \\
& AB^+=\{A,B,C,D,E\}
\end{align}
$$
2. tolgo la lettera che li rappresenta:
$$
\begin{align}
& A^+=\{\cancel{ A }\} \\
& B^+=\{\cancel{ B },C,D,E\} \\
& AB^+=\{\cancel{ A,B },C,D,E\}
\end{align}
$$
3. vado a prendere per ogni insieme solo gli elementi che stanno in R1
$$
\begin{align}
& A^+=\{\cancel{ A }\} \\
& B^+=\{\cancel{ B },\cancelto{ \neq \{A,B\} }{ C,D,E }\} \\
& AB^+=\{\cancel{ A,B },\cancelto{ \neq \{A,B\} }{ C,D,E }\}
\end{align}

\implies

F_{1}=\pi_{R_{1}}(F)=\pi_{\{A,B\}}(F)=\{\emptyset\}
$$
per ogni insieme $R_i=\{r_{1},\dots,r_{n}\}$ considerare la dipendenza "$R_{i}\to a_{1},\dots,a_{n}$"

in questo caso, $F_1$ rispetta la bcnf
##### calcolo $F_2$
$$
F_{1}=\pi_{R_{2}}(F)=\pi_{\{B,D,E\}}(F)
$$

1. calcolo le seguenti chiusure:
$$
\begin{align}
& B^+=\{B,C,D,E\} \\
& D^+=\{D\} \\
& E^+=\{E\} \\
& BD^+=\{BCDE\} \\
& BE=\{BCDE\} \\
& DE=\{DE\} \\
& BDE=\{BCDE\}
\end{align}
$$
2. tolgo la lettera che li rappresenta:
$$
\begin{align}
& B^+=\{\cancel{ B },C,D,E\} \\
& D^+=\{\cancel{ D }\} \\
& E^+=\{\cancel{ E }\} \\
& BD^+=\{\cancel{ B }C\cancel{ D }E\} \\
& BE^+=\{\cancel{ B }CD\cancel{ E }\} \\
& DE^+=\{\cancel{ DE }\} \\
& BDE^+=\{\cancel{ BC }D\cancel{ E }\}
\end{align}
$$
3. vado a prendere per ogni insieme solo gli elementi che stanno in R2
$$
\begin{align}
& B^+=\{\cancelto{ \neq \{B,D,E\} }{ C },D,E\} \\
& D^+=\{\} \\
& E^+=\{\} \\
& BD^+=\{\cancelto{ \neq \{B,D,E\} }{ C }E\} \\
& BE^+=\{\cancelto{ \neq \{B,D,E\} }{ C }D\} \\
& DE^+=\{\} \\
& BDE^+=\{D\}
\end{align}

\implies

F_{2}= \begin{cases}
& B\to D,E \\
& BD\to E \\
& BE \to D \\
& BDE\to D
\end{cases}
$$

$F_2$ rispetta

##### calcolo $F_{3}$
$$
F_{3} = \{B\to C\} \implies \text{rispetta}
$$


in conclusione la decomposizione generale rispetta la BCNF.