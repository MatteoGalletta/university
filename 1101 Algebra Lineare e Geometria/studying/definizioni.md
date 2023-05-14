og---
type: university
date: 2022-12-13
subjectId: 1101
year: 1
semester: 1
---
#university #studying #subject-1101
### Definizioni
> [!summary] Algebra Lineare e Geometria

#### Algebra Lineare

$f:R \to R$ si legge "$f$ definita in $R$ a valori in $R$".

#### Strutture Algebriche
- **Insieme**: collezione di un elementi che hanno tutti una stessa caratteristica
- **Funzione**: dati due insiemi $A$ e $B$, si dice $f$ (funzione) una legge che associa ad ogni elemento di $A$ uno di $B$.
- **Gruppo**: insieme su cui è definita un'operazione * (G, \*) e valgono le proprietà:
	- **Associativa**, **Esistenza Elemento Neutro**, **Invertibilità**
	- Si dice **Abeliano** se vale anche la **Commutatività**
- **Anello**: insieme su cui sono definite due operazioni + e * (G, +, \*) e velgono le proprietà:
	- (G, +) è gruppo,
	- Con \* vale associatività
	- Con \* distributività
	- Si dice **Commutativo** se vale la **Commutatività** su \*.
	- Si dice **Unitario** se esiste l'**elemento neutro** su \*.
	- Si dice **Campo** se è **commutativo** e vale l'**Invertibilità** su \*.

##### Matrici
- **Matrice**: tabella di n-righe e m-colonne:
	- **Diagonale**: se sopra e sotto la diagonale principale ci sono tutti zero.
	- **Triangolare superiore o inferiore**: se sopra o sotto la diagonale principale ci sono tutti zero.
	- **Simmetrica**: se la matrice è uguale alla sua trasposta.
	- **Antisimmetrica**: se la matrica è uguale all'opposta della sua trasposta.
- **Determinante**: numero associato ad ogni matrice quadrata.
- **Rango**: ci sono due definizioni:
	- ordine massimo di un minore non nullo estraibile dalla matrice
	- numero di elementi speciali
- **Teorema Matrici Invertibili** dice che:
	- a) una matrice A è invertibile $\iff \det A \neq 0$
	- b) se $\det A \neq 0$ allora la matrice inversa è: $A^{-1} = \frac{1}{\det A} \cdot A_{a} = \frac{1}{\det A} \cdot (A_{ij})^{T}$
	- c) se $A$ è invertibile allora $\det A^{-1} = \frac{1}{{\det A}}$
	- **Dimostrazione** (1\*, L.7): si dimostra con il Teorema di Binet e i due Teoremi di Laplace.

##### Spazi Vettoriali
- **Spazio Vettoriale**: si dice spazio vettoriale su un campo K (K-spazio vettoriale) un insieme su cui sono definite due operazioni + e * (G, + \*) e valgono le proprietà:
	- (G, +) è gruppo
	- Con \* vale associatività.
	- Con \* esiste elemento neutro.
	- Vale distributività della somma rispetto al prodotto esterno. $(a+b)\cdot \vec v=a \vec v + b \vec v$
	- Vale distributività del prodotto esterno rispetto alla somma. $a \cdot (\vec v + \vec w)=a \vec v +a \vec w$
- **Sottospazio**: $W$ è sottospazio di $V$ se $W \subseteq V$ e  $W$ è un $K$ spazio vettoriale rispetto alle operazioni di somma e prodotto definite su $V$.
- **Intersezione tra sottospazi**: è sempre un sottospazio
- **Unione tra sottospazi**: è sottospazio solo se uno dei due è sottoinsieme dell'altro (ovvio)
- **Combinazione Lineare**: un vettore è combinazione lineare di $\vec{v_{1}}, \vec{v_{2}}, \dots, \vec{v_{n}}$ se esistono $a_{1}, a_{2}, \dots, a_{n}$ tali che $v=a_{1}\vec{ v_{1}}+a_{2}\vec{ v_{2}}+\dots+a_{n}\vec{ v_{n}}$.
- **Insieme di Generatori**: dato un K-spazio vettoriale $V$, un insieme $(v_{1}, v_{2}, \dots, v_{n})$ è detto insieme di generatori (indicato con $G \{ v_{1}, v_{2}, \dots, v_{n}\}$) se preso un qualunque vettore $\vec z \in V$ esso si può scrivere come combinazione lineare (C.L.) dei vettori di $G$. 
- **Base**: un insieme  $(v_{1}, v_{2}, \dots, v_{n})$ è detto **Base** di $V$ se ogni elemento di $V$ è combinazione lineare (C.L.) di  $v_{1}, v_{2}, \dots, v_{n}$ in modo **unico**.
	- $B$ è base $\iff$ i vettori di $B$ sono L.I. e generatori.
- **Linearmente Indipendenti**: i vettori $v_{1}, v_{2}, \dots, v_{n}$ si dicono linearmente indipendenti se quando $a_{1}\vec{ v_{1}}+a_{2}\vec{ v_{2}}+\dots+a_{n}\vec{ v_{n}}=0$ allora ne deve seguire che $a_1=a_2=\dots=a_n=0$
- **Lemma di Steinitz**: numero di vettori generatori $\geq$ numero di vettori linearmente indipendenti.
- **Teorema che caratterizza una base**: dato $B = \{ v_{1}, v_{2}, \dots, v_{n} \}$, $B$ è un insieme $\iff$ i vettori sono L.I. e generatori.
- **Teorema sulle Basi**: tutte le basi di un K-spazio vettoriale hanno lo stesso numero di elementi.
	- **Dimostrazione** (2\*, L10): Si usa il Lemma di Steinitz.

##### Sistemi Lineari
- **Sistema Lineare**: sistema di equazioni a più incognite di massimo 1° grado (c'è il termine noto)
- **Teorema di Rouchè Capelli N°1**: $\rho(A) =\rho(A,B) \iff$ Sistema possibile (ammette almeno una soluzione).
- **Teorema di Rouchè Capelli N° 2**: quando il sistema è possibile ($\rho(A) =\rho(A,B) = \rho$) allora esistono $\infty^{n-\rho}$ soluzioni. $n-\rho$ indica il numero di incognite libere.
- **Teorema di Cramer**: $\det A \neq 0 \iff$ Sistema determinato (ammette una e una sola ($\exists!$) soluzione).
	- L'unica soluzione si calcola con: 
	- $$\begin{cases}
x_{1}=\frac{\det B_{1}}{\det A} \\
x_{2}=\frac{\det B_{2}}{\det A} \\
\dots \\
x_{n}=\frac{\det B_{n}}{\det A} \\
\end{cases}$$
		- $B_{1}$ si calcola sostituendo la $1^a$ colonna di $A$ con $B$.
		- $B_{2}$ si calcola sostituendo la $2^a$ colonna di $A$ con $B$.
		- $\dots$
		- $B_{n}$ si calcola sostituendo la $n^a$ colonna di $A$ con $B$.
	- **Dimostrazione** (3\*, L13):
		- Nell'andata si dimostrano unicità, esistenza e formula.
		- L'unicità e l'esistenza si dimostrano con il **Teorema delle matrici invertibili**.
		- La formula si dimostra svolgendo l'equazione dell'esistenza.
		- Il ritorno si dimostra con il teorema di **Rouchè Capelli N°2**.
- **Sistema lineare omogeneo**: sistema lineare con $B$ nullo (non esistono termini noti).

##### Applicazioni Lineari
- **Applicazione Lineare**: corrispondenza (funzione) tra due K-spazi vettoriali.
- **Immagine** ($\text{im} f$): insieme del codominio formato dai vettori immagine dei vettori del dominio.
	- L'immagine è sottospazio del codominio, si **dimostra** (4\*. L13) provando che è chiusa rispetto alla somma e al prodotto esterno.
	- **[Studio](immagine)**
		- $\dim imf = \rho$
		- **Base**: vettori L.I. di V (gli stessi che formano il rango)
		- **Equazione Cartesiana**: metodo matrice Z (si mettono in riga i vettori base, nell'ultima riga le incognite, si calcola il determinante)
- **Nucleo** ($\ker f$): insieme del dominio formato dai vettori che hanno come immagine il vettore nullo.
	- Il nucleo è sottospazio del dominio, si **dimostra** (5\*, L14) provando che è chiusa rispetto alla somma e al prodotto esterno esterno.
	- **[Studio](nucleo)**
		- $\dim \ker f = \dim V - \dim imf$
		- **Base**: $A \cdot X=0$
		- **Equazioni Cartesiane**: ricavate dal sistema precedente (o metodo matrice Z)
- **Iniettività**: una funzione si dice iniettiva se presi due qualsiasi vettori del dominio diversi allora ne deve seguire che le loro immagini siano diverse.
- **Suriettività**: una funzione si dice suriettiva se ogni vettore del codominio è raggiunto da almeno un vettore del dominio.
- **Teorema sul Nucleo e Iniettività**: afferma che $f$ è iniettiva $\iff \ker f = \{ 0 \}$
	- **Dimostrazione** (6\*, L14)
- **Applicazione Identica**: applicazione lineare cui legge corrisponde a $i(\vec z) = \vec z$
- **Applicazione Inversa**: Date due applicazioni lineari $f: V \to W$ e $g: W \to V$ se $g \circ f = i_{v}$ e $f \circ g = i_{w}$ allora $f$ è invertibile e $g$ è detta applicazione inversa di $f \,\, (g=f^{-1})$.
	- $f$ e $g$ devono essere suriettive e iniettive.

##### Endomorfismi
- **Endomorfismo**: applicazione lineare dove dominio $=$ codominio.
- **Isomorfismo**: un'applicazione lineare biettiva (iniettiva e suriettiva), quindi necessariamente endomorfismo.
- **Autovalore**: dato un endomorfismo $f: V \to V$, $\lambda$ si dice **autovalore** se esiste un vettore $v \in V$ con $v \neq 0$ tale che $f(v)=\lambda v$. $\qquad\lambda \space\text{autovalore} \iff \exists v \in V, v \neq 0 \space|\space f(v) = \lambda v$
- **Autovettore**: dato un endomorfismo $f: V \to V$, $v \in V$, $v \neq 0$ si dice **autovettore** se esiste un $\lambda \in K$ tale che $f(v) = \lambda v$. $\qquad v \in V, v \neq 0 \space\text{autovettore} \iff \exists \lambda \in K \space|\space f(v)=\lambda v$
- **Autospazio**: dato un endomorfismo $f: V \to V$, si dice **autospazio** $V_{\lambda}$ il sottospazio di V definito nel modo seguente: $\quad V_{\lambda} = \{ v \in V \space|\space f(v)=\lambda v \} \subseteq V$
- **Polinomio Caratteristico**: data una matrice $A$ il $P.C. = \det{(A-T\cdot I)}$.
- **Molteplicità Algebrica**: per molteplicità algebrica di $\lambda$ si intende il numero di volte in cui $\lambda$ è soluzione del polinomio caratteristico.
- **Molteplicità Geometrica**: per molteplicità geometrica di $\lambda$ si intende la dimensione dell'autospazio $V_{\lambda}$.
- **Endomorfismo Associato all'Autovalore**: indichiamo con $f_{\lambda}$ l'endomorfismo associato all'autovalore $\lambda$. $f_{\lambda}(v)=f(v)-\lambda v$
- **Teorema sulle Molteplicità**: dato un endomorfismo $f: V \to W$ e un autovalore $\lambda \in K$ allora $0 < g_{\lambda} \leq m_{\lambda}$.
- **Endomorfismo Semplice**: un endomorfismo si dice semplice se esiste una base formata interamente da autovettori.
- **Matrici simili**: due matrici $A$ e $B$ si dicono simili se  $\exists \,P \in \mathbb{K}^{n,n} \,|\, P^{-1}AP=B$.
- **Teorema sulla diagonalizzazione**: una matrice $A \in \mathbb{K}^{n,n}$ è diagonalizzabile $\iff$ $f_{A} : \mathbb{K}^{n} \to \mathbb{K}^{n}$ è semplice oppure se è simile a una matrice diagonale.
	- **Matrice Diagonalizzata**: matrice che ha sulla diagonale principale le molteplicità algebriche degli autovalori.
	- **Matrice Diagonalizzante**: matrice che ha in colonna una base degli autovettori.
- **Teorema Autospazio**: sia $V$ un K-spazio vettoriale e $f: V \to W$ un endormofismo. Allora ne segue che $V_{\lambda} = \ker f_{\lambda}$.
	- **Dimostrazione** (7\*, L19): si usa la definizione dell'autospazio.

#### Geometria
- **Punto Impoprio**: $P_{\infty} (x', y', 0)$, anche detto "Punto all'infinito $P_{\infty}$"
- **Individuazione Retta nel Piano**:
	- 1°: **Retta perpendicolare a un vettore e passante per un punto**: $ax+by+c=0$
	- 2°: **Retta parallela a un vettore e passante per un punto**: $\frac{x-x_0}{l_v}=\frac{y-y_0}{m_v}$
	- 3°: **Retta passante per due punti**: $\frac{x-x_1}{x_2-x_1}=\frac{y-y_1}{y_2-y_1}$
- **Individuazione Retta nello Spazio**:
	- 1°: *non più valida*
	- 2°: $\frac{x-x_0}{l_v}=\frac{y-y_0}{m_v}=\frac{z-z_0}{n_v}$
	- 3°: $\frac{x-x_1}{x_2-x_1}=\frac{y-y_1}{y_2-y_1}=\frac{z-z_1}{z_2-z_1}$
	- 4°: **Piano nello Spazio passante per tre punti**: $ax+by+cz+d=0$
- **Retta nello spazio**: la retta nello spazio viene vista come **intersezione di piani**.
- **Rette Sghembe**: due rette si dicono sghembe se non esiste alcun piano che le contiene
- **Fascio di rette**: $\lambda \pi_{1} + \micro \pi_{2} = 0 \to \pi_{1} + K \pi_{2} = 0$ con $\lambda \neq 0$
- **Conica**: luogo geometrico dei punti del piano $Oxy$ che con le loro coordinate $(x, y)$ soddisfano l'equazione di 2° grado in $x$ e $y$: $a_{11}x^{2} + a_{22}y^{2} + a_{33} + 2a_{12}xy + 2a_{13}x + 2a_{23}y = 0$
	- **Matrice $B$**: una 3x3 simmetrica (si usa la formula sopra).
	- **Matrice $A$**: le prime due righe e colonne della matrice $B$.
	- **Classificazione**:
		- **Irriducibile** ($\det B \neq 0$, quindi $\rho (B) = 3$):
			- **Ellisse** ($\det A > 0$):
				- **Reale** ($\mathrm{Tr}A \cdot \det B < 0$)
				- **Immaginaria** ($\mathrm{Tr}A \cdot \det B > 0$)
			- **Parabola** ($\det A = 0$)
			- **Iperbole** ($\det A < 0$):
				- **Equilatera** ($\mathrm{Tr}A = 0$)
		- **Riducibile** ($\det B = 0$, quindi $\rho (B) < 3$):
			- **Rette spezzate distinte** ($\rho (B) = 2$)
			- **Rette spezzate coincidenti** ($\rho (B) = 1$)
- **Punti base**: 4 punti per cui passano infinite coniche.
- **Ellisse**: luogo geometrico dei punti del piano per cui è costante la somma della distanza da due punti fissi detti fuochi ($F_{1}$ e $F_2$).
	- **Equazioni**:
		- $\frac{X^2}{a^2}+\frac{Y^2}{b^2}=1$
			- $F_{1 x} = -F_{2 x} = \sqrt{a^2+b^2}$
			- $F_{1 y} = F_{2 y} = 0$
		- $\alpha X^{2} + \beta Y^{2} = \gamma$
			- $\alpha$ e $\beta$ sono le soluzioni del P.C. di $A$
			- $\gamma = -\frac{\det B}{\det A}$
	- **Centro**: $$
\begin{cases}
a_{11}x_{C} + a_{12}y_{C} + a_{13} = 0 \\
a_{21}x_{C} + a_{22}y_{C} + a_{23} = 0
\end{cases}
$$
- **Circonferenza**: luogo geometrico dei punti del piano per cui è costante la distanza da un punto fisso detto centro.
	- **Equazione** (due forme):
		- **1°**: $x^2+y^2+ax+by+c=0$
		- **2°**: $(x-\alpha)^2+(y-\beta)^2=r^2$
			- Centro: $(\alpha,\beta)$
			- Raggio: $r$ 
	- **Centro**: $(-\frac{a}{2}, -\frac{b}{2})$
	- **Raggio**: $\sqrt{(-\frac{a}{2})^{2} + (-\frac{b}{2})^{2} - c}$
	- **Condizioni**: $a_{11} = a_{22}\neq 0$ e $a_{12} = 0$.
- **Iperbole**: luogo geometrico dei punti del piano per cui è costante la differenza della distanza da due punti fissi detti fuochi ($F_{1}$ e $F_2$).
	- **Equazione** (due forme):
		- $\frac{X^2}{a^2}-\frac{Y^2}{b^2}=1$
			- $F_{1 x} = -F_{2 x} = \sqrt{a^2+b^2}$
			- $F_{1 y} = F_{2 y} = 0$
		- $\alpha X^{2} + \beta Y^{2} = \gamma$
			- $\alpha$ e $\beta$ sono le soluzioni del P.C. di $A$
			- $\gamma = -\frac{\det B}{\det A}$
- **Asintoti**: gli asintoti di un'iperbole sono delle rette che approssimano il comportamento dei rami dell'iperbole all'infinito. Man mano che i rami dell'iperbole si sviluppano, tendono ad avvicinarsi sempre di più agli asintoti senza mai toccarli.
- **Parabola**: luogo geometrico dei punti del piano equidistanti da un punto fisso detto fuoco e una retta detta direttrice.
	- **Equazione Canonica**: $\beta Y^{2}=2 \gamma X$.
		- $\beta = \mathrm{Tr}A$
		- $\gamma = + \sqrt{-\frac{\det B}{\mathrm{Tr}A}}$
	- **Centro**: *non esiste*

\* vedi file per le dimostrazioni.
L$n$ indica la lezione numero $n$.