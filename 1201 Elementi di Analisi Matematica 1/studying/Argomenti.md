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
- Somma e Prodotto
- Forma trigonometrica ed esponenziale
- Conversione da forma trigonometrica a esponenziale (e viceversa)
- Risoluzione di equazioni (non disequazioni, che non esistono)

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
	- Un punto $x_0$ se è estremo relativo allora $f'(x_{0}) = 0$
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
- Studio di $\phi$
- Studio di $f$
- Studio del segno di $f'$
- *procedimento da mettere*
