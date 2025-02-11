---
type: university
date: 2023-05-13
subjectId: 1201
year: 1
semester: 2
---
#university #studying #subject-1201
### Guida su Teoria e Esercizi
> [!summary] Elementi di Analisi Matematica 1

### Prerequisiti
##### Funzioni goniometriche

| Angolo | $\sin$               | $\cos$               |
|:------ | -------------------- | -------------------- |
| 30°    | $\frac{1}{2}$        | $\frac{\sqrt{3}}{2}$ |
| 45°    | $\frac{\sqrt{2}}{2}$ | $\frac{\sqrt{2}}{2}$ |
| 60°    | $\frac{\sqrt{3}}{2}$ | $\frac{1}{2}$        |

### Numeri complessi
- $i \to$ unità immaginaria
- Rappresentazione:
	- Cartesiana: $z = a + ib$
		- Parte reale: $a = \rho \cos \theta$
		- Parte immaginaria: $b = \rho \sin \theta$
	- Polare o Trigonometrica: $z = [\rho \cos \theta + i \rho \sin \theta = ]\, \rho (\cos \theta + i\sin \theta)$
		- Modulo: $|z| = \rho = \sqrt{a^{2}+b^{2}}$
		- Argomento: $$
		{\displaystyle \theta = {\begin{cases}\arctan({\frac {b}{a}}),&{\text{se }}a>0,\\\arctan({\frac {b}{a}})+\pi ,&{\text{se }}a<0,\\{\frac {\pi }{2}},&{\text{se }}a=0{\text{ e }}b>0,\\-{\frac {\pi }{2}},&{\text{se }}a=0{\text{ e }}b<0.\end{cases}}} $$
	- Esponenziale: $z = \rho e^{i\theta}$
- Somma:
	- $(a, b) + (c, d) = (a+c, b+d)$
- Prodotto:
	- $(a, b) \times (c, d) = (ac - bd, bc + ad)$
	- $\rho_{1} (\cos \theta_{1} + i\sin \theta_{1}) \times \rho_{2} (\cos \theta_{2} + i\sin \theta_{2}) = \rho_{1}\rho_{2} (\cos (\theta_{1}+\theta_{2}) + i\sin (\theta_{1}+\theta_{2}))$
- Potenza: $z = \rho e^{i\theta} \qquad z^{n} = \rho^{n} e^{in\theta} = \rho^{n} (\cos (n\theta) + \sin (n\theta))$
- Radice di $w$: $z^{n}=w \to z=\sqrt[n]{w} \qquad z=\rho e^{i\theta} \qquad w=r e^{i\phi}$
	- $|z| = \rho = \sqrt[n]{w}$
	- $\arg{z}_k = \theta_{k} = \frac{\phi}{n} + \frac{2k\pi}{n}$ con $k=0,1, \dots, n-1$
- Coniugato di $z$:
	- $z = a + ib \qquad \overline{z} = a - ib$
	- $z = \rho e^{i\theta} \qquad \overline{z} = \rho e^{-i\theta}$
- Potenza unità immaginaria $i$:
	- $i^{4n} = 1$
	- $i^{4n+1} = i$
	- $i^{4n+2} = -1$
	- $i^{4n+3} = -i$
		- $\forall n \in \mathbb{N}$
- Risoluzione Equazioni:
	- Si può usare la formula risolutiva delle equazioni di secondo grado, intendendo la radice quadrata come radice complessa.
	- Usando la definizione di potenza o radice (nel caso di $z^{\alpha} = q$ con $z,q \in \mathbb{C}$ e $\alpha \in \mathbb{N}$)
	- Scomponendo $z$ in $a+ib$ e ponendo un sistema del tipo:
		- (la $i$ scompare, sono calcoli algebrici nel campo reale)
$$
\begin{cases}
\text{parte reale del primo membro} = \text{parte reale del secondo membro} \\
\text{parte immaginaria del primo membro} = \text{parte immaginaria del secondo membro}
\end{cases}
$$

### Insiemi
- Definizioni Teoriche
	- **Maggiorante**: dato $X \subseteq \mathbb{R}$, $m \in \mathbb{R}$ è un **maggiorante** dell'insieme $X$ se $m \geq x \,\forall\, x \in X$
	- **Estremo Superiore**: dato $X \subseteq \mathbb{R}$ un insieme limitato superiormente, $y \in \mathbb{R}$ è un **estremo superiore** di $X$ se $y$ è un maggiorante di $X$ e $y$ è il più piccolo maggiorante di $X$. Di un insieme non limitato superiormente, l'estremo superiore è $+\infty$. Di un insieme vuoto è $-\infty$.
	- **Massimo** (di un insieme): dato $X \subseteq \mathbb{R}$, $y \in \mathbb{R}$ è il **massimo** di $X$ se $y$ è l'estremo superiore di $X$ e $y \in X$
	- **Massimo Assoluto** (di una funzione): data una funzione $f$. $x_0$ è un punto di massimo assoluto di $f$ (e $f(x_{0})$ è il massimo assoluto) se per ogni $x \in Dom(f)$ risulta che $f(x) \leq f(x_0)$.
	- **Massimo Relativo** (di una funzione): data una funzione $f$, $x_0$ è un punto di massimo relativo di $f$ (e $f(x_{0})$ è il massimo relativo) se esiste almeno un intorno $B(x_{0}, \delta) \subset Dom(f)$ (di raggio $\delta$ e centro in $x_0$) tale che per ogni $x \in B(x_{0}, \delta)$ risulta che $f(x) \leq f(x_{0})$.
	- **Intervallo chiuso a destra**: se l'estremo destro è incluso nell'intervallo
	- **Intervallo aperto a destra**: se l'estremo destro è escluso dall'intervallo
	- **Intervallo illimitato superiormente**: se l'estremo superiore è $+\infty$
	- **Intervallo limitato superiormente**: se l'estremo superiore è $c \in \mathbb{R}$

### Funzioni
- Logaritmo con base $> 1$ (blu) e base $< 1$ (rosso)
```functionplot
---
title: 
xLabel: 
yLabel: 
bounds: [-10,10,-10,10]
disableZoom: true
grid: true
---
f(x)=log(x)
g(x)=log(x)/log(1/2)
```
- Seno (blu), coseno (rosso) e tangente (verde)
```functionplot
---
title: 
xLabel: 
yLabel: 
bounds: [-10,10,-10,10]
disableZoom: true
grid: true
---
f(x)=sin(x)
g(x)=cos(x)
h(x)=tan(x)
```
- Potenza con base $> 1$ (blu) e base $< 1$ (rosso)
```functionplot
---
title: 
xLabel: 
yLabel: 
bounds: [-10,10,-10,10]
disableZoom: true
grid: true
---
f(x)=E^x
g(x)=(1/E)^x
```
- Radice quadrata
```functionplot
---
title: 
xLabel: 
yLabel: 
bounds: [-10,10,-10,10]
disableZoom: true
grid: true
---
f(x)=sqrt(x)
```
- Arcocoseno (blu), Arcoseno (rosso), Arcotangente (verde)
```functionplot
---
title: 
xLabel: 
yLabel: 
bounds: [-10,10,-3.5,3.5]
disableZoom: true
grid: true
---
f(x)=acos(x)
g(x)=asin(x)
h(x)=atan(x)
```

### Limiti
- Definizione
	- $\forall\, \epsilon > 0 \,\exists\, \delta > 0 : \forall x \in X, |x-x_{0}|<\delta, x \neq x_{0} \Rightarrow |f(x) - l|<\epsilon$
- Teorema di unicità del limite
- Teorema del confronto (sono tre, il terzo è detto "Teorema dei Carabinieri")
	- se $f(x) \leq g(x)$ allora:
		- 1. se $f(x) \to l$ e $g(x) \to m$ allora $l \leq m$
		- 2. se $f(x) \to +\infty$ allora $g(x) \to +\infty$
	- se $f(x) \leq g(x) \leq h(x)$ allora:
		- 3. se $f(x) \to l$ e $h(x) \to l$ allora $g(x) \to l$
- Teorema di Weierstrass
	- Sia $f$ una funzione continua con domino $K \subseteq \mathbb{R}$ chiuso e limitato, allora $f$ ha massimo e minimo.
- Teoria degli Infinitesimi ($o$ "o piccolo", $O$ "o grande")
- Limiti Notevoli
	- $\lim_{x\to0} \frac{\log_a(1+x)}{x}=\frac{1}{\ln{a}}$
	- $\lim_{x\to0} \frac{a^x-1}{x}=\ln(a)$
	- $\lim_{x\to\pm\infty} (1+\frac{1}{x})^{x} = e$
	- $\lim_{x\to0} \frac{\sin x}{x} = \lim_{x\to0} \frac{\tan x}{x} = 1$
	- $\lim_{x\to0} \frac{1 - \cos x}{x^2} = \frac{1}{2}$
- Calcolo Limiti
	- Algebra dei limiti (regole):
		- Il limite della somma è uguale alla somma dei limiti
		- Il limite del prodotto di una funzione per una costante è uguale alla costante per il limite della funzione
		- Il limite del prodotto è uguale al prodotto dei limiti
		- Il limite del rapporto è uguale al rapporto dei limiti
		- Si può passare il limite alla funzione composta
	- Risoluzione per sostituzione
		- Può avvenire se la funzione in questione è continua (e $x$ tende a un valore finito). Si utilizzano le regole dell'algebra dei limiti.
	- Se la funzione non è continua in un punto si calcolano limite destro e sinistro. Se non coincidono il limite non esiste.
- Sviluppi di Taylor

### Derivate
- Definizione (limite del rapporto incrementale)
	- $f'(x_0)=\lim_{h\to0}\frac{f(x_0+h)-f(x_0)}{h}$
- Derivate Fondamentali
	- Costante: $f(x)=k\in\mathbb{R} \to f'(x)=0$
	- Variabile: $f(x)=x \to f'(x)=1$
	- Potenza: $f(x)=x^{s}, s \in \mathbb{R} \to f'(x)=sx^{s-1}$
	- Esponenziale: $f(x)=a^{x}, a \in \mathbb{R} \to f'(x) = a^{x}\ln a$
	- Logaritmo: $f(x)=\log_{a}(x) \to f'(x)=\frac{1}{x\ln a}$
	- Valore Assoluto: $f(x)=|x| \to f'(x)=\frac{|x|}{x}$
	- Seno: $f(x)=\sin(x) \to f'(x)=\cos(x)$
	- Coseno: $f(x)=\cos(x) \to f'(x)=-\sin(x)$
	- Tangente: $f(x)=\tan(x) \to f'(x)=\frac{1}{\cos^{2}(x)}$
- Condizione di derivabilità
	- Una funzione è derivabile quando il limite del rapporto incrementale esiste ed è finito.
	- Se non è derivabile ci si ritrova (nella maggior parte dei casi) in:
		- un punto angoloso (ad esempio $|x|$)
		- una cuspide (ad esempio $\sqrt{|x|}$)
		- un punto di flesso a tangente verticale (ad esempio $\sqrt[3]{x}$)
		- Individuare i punti di non derivabilità:
			1. Se un punto non appartiene al dominio della derivata prima allora non è derivabile.
			2. Vanno verificati i "punti sospetti". I punti sospetti sono quei punti in cui la funzione potrebbe non essere derivabile. Ad esempio, se una funzione $f$ contiene $|x|$, potrebbe non essere derivabile in $x=0$ (anche se appartiene al dominio!). Si calcola il limite della derivata prima nel punto. Se quest'ultimo esiste ed è finito, allora la funzione è derivabile in quel punto. Non vale il contrario. Devono valore le ipotesi del teorema di Darboux (<u>in EAM1 dovrebbero essere sempre verificate</u>, quindi non viene enunciato)
				- I punti sospetti sono (in $x=0$) nelle funzioni: $|x|$, $\sqrt{x}$
			3. Se non sono verificate le ipotesi del teorema di Darboux, si è obbligati a calcolare il limite del rapporto incrementale. La funzione è derivabile in quel punto se e solo se esiste il limite ed è finito.
	- La somma/differenza di due funzioni derivabili è derivabile.
	- Il prodotto/quoziente di due funzioni derivabile è derivabile.
	- La composizione di due funzioni derivabili è derivabile.
- Calcolo Derivate
	- La derivata del prodotto di una costante per una funzione è uguale al prodotto della costante per la derivata della funzione
	- La derivata della somma/differenza di funzioni è uguale alla somma/differenza delle singole derivate.
	- La derivata del prodotto di due funzioni è uguale alla somma del prodotto tra la prima funzione derivata per la seconda non derivata, e la prima funzione non derivata per la seconda derivata
		- $(f(x) \cdot g(x))' = f'(x)g(x) + f(x)g'(x)$
	- La derivata del quoziente di due funzioni
		- $\left(\frac{f(x)}{g(x)}\right)' = \frac{f'(x)g(x) - f(x)g'(x)}{[g(x)]^2}$
	- La derivata della funzione composta
		- $(g(f(x)))' = g'(f(x)) \cdot f'(x)$
- Teorema di Fermat
	- Se un punto $x_0$ è estremo relativo allora $f'(x_{0}) = 0$
- Teorema di Rolle
	- Se in un intervallo $[a, b]$ la funzione $f$ è continua in $[a,b]$, derivabile in $]a,b[$ e $f(a)=f(b)$ allora $\exists \,c$ tale che $f'(c) = 0$
- Teorema di Lagrange
	- Se in un intervallo $[a,b]$ la funzione $f$ è continua in $[a,b]$ e derivabile in $]a,b[$ allora $\exists \,c$ tale che $f(b)-f(a)=(b-a)f'(c)$
- Teorema di Weierstrass
	- Se in un intervallo $[a,b]$ chiuso e limitato la funzione $f$ è continua allora $f$ ammette un massimo e un minimo (assoluti)
- Teorema di De L'Hôpital
	- Se $\lim_{x \to x_{0}}\frac{f(x)}{g(x)}$ porta a una forma indeterminata del tipo $\frac{0}{0}$ o $\frac{\infty}{\infty}$ allora $\lim_{x \to x_{0}} \frac{f(x)}{g(x)} = \lim_{x \to x_{0}} \frac{f'(x)}{g'(x)}$

### Studio di funzione
- Dominio
	- Frazioni: denominatore $\neq 0$
	- Radici a indice pari: argomento $\geq 0$
	- Logaritmi: base e argomento $> 0$, base $\neq 1$
	- arccos, arcsin: argomento in $[-1, +1]$
- Simmetria (facoltativo):
	- La funzione è "dispari" (simmetria rispetto all'origine) se $f(-x)=-f(x)$
	- La funzione è "pari" (simmetrica rispetto all'asse delle ordinate) se $f(-x)=f(x)$
	- *Individuare una simmetria porta un grosso vantaggio: consente di studiare la funzione per $x>0$ e di considerarla senza valori assoluti, se presenti.*
- Limiti nei punti di frontiera del dominio per il calcolo degli asintoti:
	- Verticale:
		- si verifica quando $\lim_{x \to x_{0}} f(x) = \pm\infty$
		- Equazione: $x = x_0$
		- Possono essere 0, qualsiasi numero o infiniti
	- Orizzontale:
		- si verifica quando $\lim_{x \to \pm\infty} f(x) = k \in \mathbb{R}$
		- Equazione: $y = k$
		- Possono essere 0, 1 o 2.
	- Obliquo:
		- esiste soltanto se non esiste un asintoto orizzontale (se lo cerco a $+\infty$ non deve esistere l'asintoto orizzontale a $+\infty$)
		- si verifica quando:
			- $\lim_{x \to \pm\infty} \frac{f(x)}{x} = m \in \mathbb{R}$
			- $lim_{x \to \pm\infty} f(x) - mx = q \in \mathbb{R}$
		- Equazione: $y = mx + q$
		- Possono essere 0, 1 o 2
- Monotonia
	- si calcola $f'(x)$ e si studia il segno.
	- Dove $f'(x) > 0$ la funzione è crescente (viceversa è decrescente).
- Convessità
	- si calcola $f''(x)$ e si studia il segno
	- Dove $f''(x) > 0$ la funzione è convessa (viceversa è concava).
		- (convessa ha il grafico simile a una **U**)
- Calcolo esplicito di qualche valore:
	- serve ad esempio per sapere il segno della funzione in un punto.

### Successioni Ricorsive
$$
\begin{cases}
a_{n} = \lambda \\ \\
a_{n+1} = f(a_{n})
\end{cases}
$$
- Cosa sono le funzioni $f$ e $\phi$
	- La funzione $f$ rappresenta la legge della successione ($a_{n+1} = f(a_{n})$)
	- La funzione $\phi(t) = f(t) - t$. Non è altro che $a_{n+1}-a_{n}$.
- Studio di $\phi$
	- La funzione $\phi$ serve per calcolare i punti fissi e la monotonia della successione.
	- **Teorema:** Se la successione non è divergente, converge a un punto fisso della successione.
	- I punti fissi si calcolano ponendo $\phi(t)=0$ (sono gli zeri di $\phi$).
	- Si studia il segno di $\phi$ per poterne studiare la monotonia.
	- La monotonia suggerisce il possibile limite della successione
- Studio degli intervalli della successione
	- Si studia $f'$ (si calcolano massimi e minimi).
	- Si studia l'intervallo del codominio rispetto a quello del dominio dove si trova $\lambda$.
		- Si calcolano massimo e minimo del codominio nell'intervallo di $\phi$ in cui si trova $\lambda$.
		- Se ad esempio otteniamo: $f(]0,1[) = ]1,+\infty[$ con $\lambda \in ]0,1[$, siamo costretti a calcolare anche massimi e minimi in $]1, +\infty[$. Se $f(]1,+\infty[)=]1,+\infty[$, allora per ricorsività tutta la successione è contenuta in $]1, +\infty[$.
		- Si guarda quindi a cosa tende la successione nell'intervallo $]1,+\infty[$ (quindi si guarda a cosa tende $\phi$)
	- Se è richiesto lo studio della successione al variare di $\lambda$, si pone $\lambda \in$ a ogni intervallo di $\phi$.

> [!Help] Come capire se c'è un errore
> Poniamo caso che $a_0=1$.
> In seguito allo studio di $f$ si scopre che $f(]0,2[)=]0,3[$
> 
> **C'è un errore di calcolo**. Quando accade che il codominio di un intervallo non è un sott'insieme di nessun intervallo, allora il metodo sopra citato non funziona. Tutti le successioni di EAM1 sono però risolvibili con questo metodo, quindi dev'esserci un errore di calcolo.
> 
> *Negli esercizi della seconda sessione 2023 risulta che il dominio dell'intervallo è un sottoinsieme del codominio. In questi casi bisogna procedere allargando arbitrariamente gli estremi dell'intervallo del dominio.*

> [!warning] Non mettere $\lambda$ in esercizi che non lo prevedono
> Anche per esercitazione, non ha senso mettere $\lambda$ in esercizi che hanno un numero finito come $a_1$. Alcuni esercizi sono risolvibili con il metodo sopra citato soltanto per alcuni valori di $a_1$.
