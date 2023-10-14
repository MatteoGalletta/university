---
type: university
date: 2023-10-14
subjectId: 2103
year: 2
semester: 1
---
#university #studying #subject-2103
### Guida su Teoria ed Esercizi
> [!summary] Elementi di Analisi Matematica 2

# 1 - Integrali Indefiniti
## Primitive

> [!faq] Definizione
> Sia $f: (a, b) \to \mathbb{R}$.
> $f$ è dotata di primitive in $(a, b)$ se $\exists F: (a, b) \to \mathbb{R}$ tale che
> 1. $F$ è derivabile in $(a, b)$
> 2. $F'(x)=f(x) \quad \forall\, x \in (a, b)$

> [!warning] Nota
> - Non tutte le funzioni hanno primitive (es. la funzione segno)
> - Una funzione continua ha primitive. Una funzione non continua non implica il non avere primitive. La continuità è una condizione sufficiente, ma non necessaria.
### Caratterizzazione delle primitive di una funzione in un intervallo
> [!info] Teorema

> [!done] Enunciato
> **Ipotesi**
> $f: (a, b) \to \mathbb{R}$ dotata di primitive in $(a, b)$
> $F$ primitiva di $f$ in $(a, b)$
> 
> **Tesi**
> Tutte e sole le funzioni primitive di $f$ in $(a, b)$ sono le funzioni del tipo:
> $$ F(x) + c, \quad c \in \mathbb{R}$$

> [!quote] Dimostrazione
> $\quad 1.$ Dimostro che tutte le funzioni del tipo $F(x) + c$, con $c \in \mathbb{R}$ sono primitive di $f$ in $(a, b)$
> $$ \exists \,D[F(x)+c]=F'(x) + 0 = f(x)$$
> $\quad 2.$ Dimostro che tutte le funzioni del tipo $F(x) + c$ sono le sole primitive.
> Se $G: (a, b) \to \mathbb{R}$ è un'altra primitiva di $f$ in $(a, b)$ allora $\exists\, c \in \mathbb{R}$ tale che $G(x)=F(x)+c \quad\forall x \in (a,b)$
> Consideriamo la funzione $G(x) - F(x)$. Essa è derivabile in $(a, b)$ e
> $$ D[G(x) - F(x)] = G'(x) - F'(x)=f(x)-f(x)=0$$
> 
> Il 2° corollario di Lagrange dice: se due funzioni hanno la stessa derivata in un intervallo, esse differiscono per una costante.
> 
> Quindi, $G(x)-F(x)=\text{costante} \to G(x)=F(x)+c, \quad \forall x \in (a, b)$

## Integrale Indefinito
mettere definizione

### Integrali Indefiniti Notevoli
($c \in \mathbb{R}$)
- $\int 0 \,dx = c$
- $\int 1 \,dx = x+c$
- $\int x^{\alpha}\,dx = \frac{x^{\alpha+1}}{\alpha+1}+c, \quad\alpha \neq 0$
- $\int \frac{1}{x} \,dx = \ln|x|+c$
- $\int e^{x}\,dx = e^{x}+c$
- $\int \alpha^{x} \,dx = \frac{\alpha^{x}}{\ln|x|}, \quad \alpha \in \mathbb{R}, \alpha > 0, \alpha \neq 0$
- $\int \sin x \,dx = -\cos x + c$
- $\int \cos x \,dx = \sin x + c$
- $\int \frac{1}{1+x^{2}} = \arctan x + c$
- $\int \frac{1}{\sqrt{1-x^{2}}} = \arcsin x + c$
### Integrali di Funzioni Composte
- $\int [f(x)]^{\alpha}\cdot f'(x)\,dx = \frac{[f(x)]^{\alpha+1}}{\alpha+1}+c$
- *gli altri sono uguali a quelli notevoli ma con $x = f(x)$, tutto per $f'(x)$*.
### Proprietà di Omogeneità

> [!done] Enunciato
> **Ipotesi**
> $f: (a, b) \to \mathbb{R}$ dotata di primitive in $(a, b)$
> $k \in \mathbb{R}, k \neq 0$
> 
> **Tesi**
> 1. $k f$ è dotata di primitive in $(a, b)$
> 2. $\int k f(x) \,dx = k \int f(x) \,dx$

> [!quote] Dimostrazione
> 1. Per ipotesi $f$ è dotata di primitive in $(a ,b)$ e sia $F$ una sua primitiva.
> $$ \exists \,D[k \cdot F(x)] = k \cdot F'(x) = k \cdot f(x) \quad \forall x \in (a, b)$$
> 2. Per provare la $2$ si dimostrano le due inclusioni.
> Si prova che $\int k \cdot f(x) \,dx \subseteq k \cdot \int f(x) \,dx$
> 
> $G \in \int k \cdot f(x) \,dx$
> $\exists G'(x) = k \cdot f(x)$
> 
> Dobbiamo provare che $G \in k \cdot \int f(x) \,dx$, quindi $G = k \cdot \text{primitiva di f}$
> Se $k \neq 0$ possiamo dire che $G(x) = k \cdot \left[\frac{G(x)}{k}\right]$
> 
> Se proviamo che $\left[\frac{G(x)}{k}\right]$ è uguale a una primitiva di $f$ in $(a, b)$, allora abbiamo provato che $G(x) \in k \cdot \int f(x) \,dx$.
> 
> $D \left[\frac{G(x)}{k}\right] = \frac{1}{k} \cdot G'(x) = \frac{1}{\cancel{k}} \cdot [\cancel{k} \cdot f(x)] = f(x)$
> 
> In conclusione, $\frac{G(x)}{k}$ è primitiva di $f$ in $(a, b)$, quindi $G \in k \cdot \int f(x) \,dx$
> 
> Proviamo adesso l'altra inclusione $k \cdot \int f(x) \,dx \subseteq \int k \cdot f(x) \,dx$
> 
>
> $G \in k \int f(x) \,dx$, quindi $G(x) = k \cdot F(x)$
> 
> Devo provare che $G$ è una primitiva di $k \cdot F(x)$
>
> $G'(x)=D[k \cdot F(x)]=k \cdot F'(x)=k \cdot f(x)$
> Abbiamo dimostrato che $G$ è una primitiva di $k \cdot f$

### Proprietà di Linearità

>[!done] Enunciato
> 
> **Ipotesi**
> $f,g: (a, b) \to \mathbb{R}$ dotate di primitive in $(a, b)$
> 
> **Tesi**
> 1. $f+g$ è dotata di primitive in $(a, b)$
> 2. $\int [f(x) + g(x)] \,dx = \int f(x)\,dx + \int g(x) \,dx$
>  > [!warning] Osservazione
>  > Al secondo membro avviene la somma tra due insiemi, che di norma non è definita. Si intende invece l'insieme formato dalle funzioni che sono la somma di una delle primitive di $f$ e una delle primitive di $g$.
> 1. $\int [f(x) + g(x)] \,dx = F(x) + \int g(x) \,dx$, con $F$ primitiva di $f$
> > [!warning] Osservazione
> > Al secondo membro si intende che, quando si tratta di una somma con un integrale, è possibile omettere la costante.

### Integrazione per decomposizione in somma
da scrivere

### Integrazione indefinita per parti
da scrivere

### Integrali ciclici
> [!hint] Metodo risolutivo
> Per risolvere un integrale del tipo:
> $$\int f(x) \,dx = H(x) + \alpha \cdot \int f(x) \,dx, \quad \alpha \neq 1$$
> È sufficiente portare al primo l'integrale e risolvere l'equazione isolandolo.

### Integrali di Polinomi Trigonometrici

#### $\int \cos^{n}{x} \,dx$ oppure $\int \sin^{n}{x} \,dx$
##### $n$ dispari
##### $n$ pari
#### $\int cos^{n}x \cdot \sin^{m}x \,dx$
##### $n=m$
assioma trigonometria

##### $n\neq m$ con $n$ e $m$ entrambi pari
##### $n\neq m$ con almeno $n$ oppure $m$ dispari

