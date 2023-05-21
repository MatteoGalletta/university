---
type: university
date: 2023-05-13
subjectId: 1201
year: 1
semester: 2
---
#university #studying #subject-1201
### 2023-05-13
> [!summary] Elementi di Analisi Matematica 1

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
	- Si può svolgere algebricamente scomponendo $z$ in $a+ib$ e ponendo un sistema del tipo: $$
\begin{cases}
\text{parte reale delle incognite} = \text{parte reale dei termini noti} \\
\text{parte immaginaria delle incognite} = \text{parte immaginaria dei termini noti}
\end{cases}
$$
		- La $i$ scompare, sono calcoli algebrici nel campo reale.

### Insiemi
- Definizioni di Maggiorante, Estremo Superiore, Massimo.
- Teorema dell'estremo superiore
	- di un insieme non nullo esiste sempre

### Limiti
- Definizione
- Teorema di unicità del limite
- Teorema del confronto (sono tre, il terzo è detto "Teorema dei Carabinieri")
	- se $f(x) \leq g(x)$ allora:
		- 1. se $f(x) \to l$ e $g(x) \to m$ allora $l \leq m$
		- 2. se $f(x) \to +\infty$ allora $g(x) \to +\infty$
	- se $f(x) \leq g(x) \leq h(x)$ allora:
		- 3. se $f(x) \to l$ e $h(x) \to l$ allora $g(x) \to l$
- Teorema di Weierstrass
	- Sia $f$ una funzione continua con domino uguale a un insieme $K \subseteq \mathbb{R}$ chiuso e limitato, allora $f$ ha massimo e minimo.
- Teoria degli Infinitesimi ($o$ piccolo, $o$ grande)
- Limiti Notevoli
- Sviluppi di Taylor

### Derivate
- Calcolo Derivate
	- Costante
	- Potenza
	- Somma e Prodotto (Differenza e Quoziente)
	- Funzione Composta
	- Funzione inversa
	- Funzioni varie (trigonometriche, logaritmi, ecc)
- Derivate Fondamentali
- Teorema di Fermat
	- Se un punto $x_0$ è estremo relativo allora $f'(x_{0}) = 0$
- Teorema di Rolle
	- Se in un intervallo $[a, b]$ la funzione $f$ è continua in $[a,b]$, derivabile in $]a,b[$ e $f(a)=f(b)$ allora $\exists \,c$ tale che $f'(c) = 0$
- Teorema di Lagrange
	- Se in un intervallo $[a,b]$ la funzione $f$ è continua in $[a,b]$ e derivabile in $]a,b[$ allora $\exists \,c$ tale che $f(b)-f(a)=(b-a)f'(c)$
- Teorema di De L'Hopital
	- Se $\lim_{x \to x_{0}}\frac{f(x)}{g(x)}$ porta a una forma indeterminata del tipo $\frac{0}{0}$ o $\frac{\infty}{\infty}$ allora $\lim_{x \to x_{0}} \frac{f(x)}{g(x)} = \lim_{x \to x_{0}} \frac{f'(x)}{g'(x)}$

### Studio di funzione
- Dominio
	- Frazioni: denominatore $\neq 0$
	- Logaritmi: base e argomento $> 0$, base $\neq 1$
	- arccos, arcsin, arctan: argomento in $[-1, +1]$
- Limiti nei punti di frontiera del dominio per il calcolo degli asintoti:
	- Verticale:
		- si verifica quando $\lim_{x \to x_{0}} f(x) = \pm\infty$
		- Equazione: $x = x_0$
		- Possono essere infiniti
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
	- Si studia $f'$.
	- Si studia l'intervallo del codominio rispetto a quello del dominio dove si trova $\lambda$.
		- Per farlo si calcolano massimo e minimo dell'intervallo. Si prende lo studio di $f'$ fatto precedentemente per stabilire a cosa tende la successione (tra minimo e massimo trovati)
		- Esempio: $f(]0,1[) = ]1,+\infty[$ con $\lambda \in ]0,1[$. In questo caso bisogna vedere a cosa tende la successione nell'intervallo $]1,+\infty[$ (quindi si guarda a cosa tende $\phi$)
- Se è richiesto lo studio della successione al variare di $\lambda$, si pone $\lambda \in$ a ogni intervallo di $\phi$.
