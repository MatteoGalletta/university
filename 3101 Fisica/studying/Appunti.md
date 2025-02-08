---
type: university
date: 2024-11-01
subjectId: 3101
year: 3
semester: 1
number headings: auto, first-level 1, max 6, 1.1
---
#university #studying #subject-3101

> [!summary] Fisica

Realizzato in collaborazione con [Kevin Speranza](https://github.com/kespers).
# 1 Cinematica del punto materiale
si occupa di descrivere il moto degli oggetti, senza porsi il problema di collegare il moto alle cause che lo determinano.

DEF: **punto materiale**
un sistema fisico è schematizzabile come punto materiale (ovvero che esso si comporta come un punto materiale) se le sue dimensioni lineari sono piccole rispetto alla precisione con cui ci interessa determinarne la posizione.

ex: nave a largo

N.B.
dato un vettore $v$ ^58131f
$$
\begin{cases}
v_{x}=v \cdot \cos \alpha \\
v_{y}=v \cdot \sin \alpha
\end{cases}
$$

prodotto scalare
1. somma dei prodotti membro a membro
2. $\overrightarrow{v_{1}} \cdot \overrightarrow{v_{2}}=v_{1}v_{2}\cos\theta$

## 1.1 legge oraria
Serve per conoscere la posizione del punto materiale in funzione del tempo.
$$
\begin{cases}
x = x(t) \\
y = y(t) \\
z=z(t)
\end{cases}
\quad
\text{oppure}
 \quad
 \overrightarrow{r}=\overrightarrow{r}(t)
$$

DEF: velocità media
$$
\overrightarrow{v}=\frac{\Delta \overrightarrow{r}}{\Delta t}
$$
DEF: velocità istantanea
$$
\overrightarrow{v}(t)=\lim_{ \Delta t \to 0 } \frac{\overrightarrow{r}(t+\Delta t)-\overrightarrow{r}(t)}{\Delta t}=\lim_{ \Delta t \to 0 } \frac{\Delta \overrightarrow{r}}{\Delta t}
$$
### 1.1.1 moto rettilineo uniforme
Ipotesi:
1. velocità costante: $\overrightarrow{v}=\text{costante}$
2. $x$ in funzione del tempo: $x=x(t)$
3. punto parte da $x_0$: $x(t = 0) = x_{0}$

Tesi:
$$
\text{legge oraria}: x(t)=v_{x} \cdot t + x_{0}
$$

Dimostrazione:
per definizione la velocità è
$$
v(t)=\frac{dx(t)}{dt}
$$
per ricavare la legge dello spostamento $x(t)$ è sufficiente integrare la velocità, che è costante:
$$
\int v_x \, dt=v_{x} \cdot t + c 
$$
per far valere l'ipotesi 3 dobbiamo imporre che:
$$
x(t=0)=x_{0}=v_{x} \cdot t + c
$$
$$
\text{legge oraria}: x(t)=v_{x} \cdot t + x_{0}
$$

### 1.1.2 moto uniformemente accelerato
Ipotesi:
1. accelerazione costante: $\overrightarrow{a}=\text{costante}$
2. $x$ in funzione del tempo: $x=x(t)$
3. punto parte da $x_0$ : $x(t = 0) = x_{0}$
4. punto parte con una velocità $v_0$ : $v(t = 0) = v_{0}$

Tesi:
$$
\text{legge oraria: }x(t)=\frac{1}{2}a_{x}t^2+ v_{0} \cdot t + x_{0}
$$

Dimostrazione:
per definizione:
$$
a_{x}=\frac{d v_{x}}{dt}=\text{costante}
$$
$$
v_{x}(t)=\int a_{x} \, dt=a_{x} \cdot t + c 
$$

imponendo l'ipotesi 4:
$$
v_{x}(t)=a_{x} \cdot t + v_{0}
$$
per ottenere la legge oraria dello spostamento
$$
\begin{align}
x(t)&=\int v_{x}(t) \, dt \\ &= \int a_{x} \cdot t + v_{0} \, dt \\&= a_{x} \frac{t^2}{2}+v_{0} \cdot t + c  \\
& = \frac{1}{2}a_{x}t^2+ v_{0} \cdot t + c\end{align}
$$

imponiamo 3:
$$
\text{legge oraria: }x(t)=\frac{1}{2}a_{x}t^2+ v_{0} \cdot t + x_{0}
$$

### 1.1.3 Esempio: moto balistico
![[Pasted image 20241101171301.png|500]]
Da ipotesi abbiamo che il proiettile si muove con legge:
$$
\begin{cases}
x(t)=v_{0x} \cdot t + x_{0} \\
y(t) = \frac{1}{2}a_{y}t^2 + v_{0y}\cdot t + y_{0}
\end{cases}
$$
inoltre:
5. viene lanciato con angolo $\theta$
6. $x_{0} = 0$
7. $y_{0} = 0$
8. $a_{y}=-g=-9,81 \frac{m}{s^2}$

dobbiamo trovare la gittata $x_g$ massima
- Per gittata si intende la distanza ricoperta dalla particella prima di toccare terra

Soluzione:
Nel momento in cui toccherà terra:
$$
y(t)=0
$$
risolvendo:
$$
\begin{align}
y(t)=&\frac{1}{2}a_{y}t^2 + v_{0y} \cdot t + \underbrace{ y_{0} }_{ = 0 } = 0 \\
\implies & \frac{1}{2}a_{y}t^2 + v_{0y} \cdot t = 0 \\
\implies &  t\left( \frac{1}{2}a_{y}t+v_{0y} \right)=0 \\ \\ 
& \text{t = 0 non ci interessa} \\ \\

\implies & \frac{1}{2}a_{y}t+v_{0y} = 0 \\
\implies & t = -\frac{2v_{0y}}{a_{y}}  \\
\implies & t = \frac{2v_{0y}}{g}
\end{align}
$$
sostituiamo nella $x(t)$
$$
\begin{align}
x_{g}=x(t =  \frac{2v_{0y}}{g})&=v_{0x} \cdot \frac{2v_{0y}}{g} + \underbrace{ x_{0} }_{ = 0 } \\
\end{align}
$$
[[#^58131f|dalla proprietà dei vettori]] e dalla seguente proprietà:
$$
2\sin \theta \cos \theta = \sin(2\theta)
$$
avremo:
$$
\begin{align}
x_{g}&=\frac{2v_{0}^2\cos \theta \sin \theta}{g} \\
& = \frac{v_{0}^2 \sin(2\theta)}{g}
\end{align}
$$


quindi $x_{g}$ è massima quando $\theta = 45°$
# 2 dinamica
DEF: La dinamica tratta le relazioni fra il moto degli oggetti e le cause (dette forze) che tale moto determinano.

## 2.1 Principi
1. Un punto materiale libero se messo in quiete rimane in quiete
2. $\overrightarrow{F} = m \cdot \overrightarrow{a}$

UNITÀ DI MISURA:
$$
F = [N] = \left[ kg \cdot \frac{m}{s^2} \right]
$$
## 2.2 Forza peso
$\overrightarrow{P} = m_{g} \cdot \overrightarrow{g}=m \cdot \overrightarrow{a}$
$$
\overrightarrow{a}= \overrightarrow{g}\cdot\frac{m_{g}}{m}
$$
si osserva sperimentalmente che il rapporto $\frac{m_{g}}{m}$ è costante, altrimenti corpi diversi subirebbero accelerazioni differenti.

per semplicità assumiamo $\frac{m_{g}}{m}=1$, risulterà:
$$
\overrightarrow{a}=\overrightarrow{g}
$$

### 2.2.1 legge oraria punto materiale su un piano
da vedere
#todo

## 2.3 quantità di moto
Si dice quantità di moto:
$$
\overrightarrow{p}= m \cdot \overrightarrow{v}
$$

### 2.3.1 forza impulso
$$
\begin{align}
\overrightarrow{F} &= m \cdot \overrightarrow{a} \\
& = m \cdot \frac{d \overrightarrow{v}}{dt} \\
& = \frac{d(m \overrightarrow{v})}{dt} & [m \cdot \overrightarrow{v}= \overrightarrow{p}] \\
& = \frac{{d \overrightarrow{p}}}{dt} \\
 \\
\overrightarrow{F} dt &= d \overrightarrow{p} \\
\int^{t_{2}}_{t_{1}}\overrightarrow{F} dt &= \int^{t_{2}}_{t_{1}}d \overrightarrow{p} \\

\end{align}
$$
denotiamo con:
$$
\overrightarrow{I}=\int^{t_{2}}_{t_{1}}\overrightarrow{F}dt
$$
scriveremo quindi la forza impulso come la variazione di quantità di moto:
$$
\begin{align}
\overrightarrow{I}&=\int_{t_{1}}^{t_{2}} d \overrightarrow{p}  \\
& = \overrightarrow{p}(t_{2})-\overrightarrow{p}(t_{1}) \\
& = \Delta \overrightarrow{p}
\end{align}
$$

## 2.4 lavoro
### 2.4.1 lavoro infinitesimo
Consideriamo dunque un punto materiale $P$ di massa $m$ che si muove in un sistema di riferimento inerziale (rispetta la prima legge della dinamica), sottoposto a una forza $\overrightarrow{F}$

Sia lo spostamento:
$$
d \overrightarrow{s} = \overrightarrow{r}(t + dt)- \overrightarrow{r}(t)
$$
- con $\overrightarrow{r}(t)$ vettore posizione

diremo lavoro elementare $dL$ relativo allo spostamento elementare $d \overrightarrow{s}$ :
$$
dL = \overrightarrow{F} \cdot d \overrightarrow{s}
$$

Unità di misura "joule": $$[N \cdot m] = [J]$$

### 2.4.2 lavoro
dati due punti A e B, per calcolare il lavoro da A a B:
$$
L_{AB}=\int^{B}_{A}dL
$$

### 2.4.3 energia cinetica: Teorema del lavoro
in quanto:
$$
\begin{align}
dL &= \overrightarrow{F} \cdot d \overrightarrow{s} \\
& = m \overrightarrow{a} \cdot d \overrightarrow{s} \\
& = m \frac{d \overrightarrow{v}}{dt} d \overrightarrow{s} \\ \\

& = m \cdot d \overrightarrow{v} \cdot \overrightarrow{v} & \left[ \frac{d \overrightarrow{s}}{dt}=\overrightarrow{v} \right]\\ \\

& = d \underbrace{ \left( \frac{1}{2} mv^2 \right) }_{ K } = dK & \left[ \overrightarrow{v} \cdot d\overrightarrow{v} = d\left( \frac{v^2}{2} \right)\right]
\end{align}
$$
definiamo K come "energia cinetica"
$$
K = \frac{1}{2}mv^2
$$

$$
\begin{align}
L_{AB}&= \int^{B}_{A}dL \\
&= \int^{B}_{A}dK  \\
&=K_{B} - K_{A} = \Delta K
\end{align}
$$

vale per qualunque tipo di forza


### 2.4.4 energia potenziale: teorema di conservazione dell'energia meccanica
Una forza si dice conservativa se il suo lavoro $L_{AB}$ dipende solo da A e B.

Se una forza è conservativa vale quindi:
$$
\begin{align}
L_{AB} &= K_{B} - K_{A} \\
&=U_{A} - U_{B} \\
\end{align}
$$

$$
K_{B} + U_{B}=K_{A} + U_{A}
$$

$$
E = K + U = \text{costante}
$$

Axx:
$$
U = m \cdot g \cdot h
$$

### 2.4.5 potenza
lavoro per unità di tempo
$$
\begin{align}
dL &= \overrightarrow{F} \cdot d \overrightarrow{s} \\
\frac{dL}{dt} &= \frac{\overrightarrow{F} \cdot d \overrightarrow{s}}{dt} & \left[ \frac{d \overrightarrow{s}}{dt} = \overrightarrow{v} \right] \\
W = \frac{dL}{dt} &= \overrightarrow{F} \cdot \overrightarrow{v}
\end{align}
$$

UNITÀ DI MISURA:
$$
[W] = \frac{[J]}{[s]} 
$$



# 3 Forza di gravità
Costante di gravitazione universale:
$$
G = 6.66 \cdot 10^{-11} \cdot \frac{N \cdot m^2}{kg^2}
$$


Dati due punti materiali $M$, $m$
Con $\overrightarrow{d}$ vettore distanza $M$ a $m$
![[Pasted image 20241109130150.png|300]]
Definiamo la forza con cui $m$ viene attratto a $M$:
$$
\overrightarrow{F_{12}} = - \frac{GMm}{d^2} \cdot \hat{d}
$$

## 3.1 Lavoro ed energia meccanica durante lo spostamento
Supponendo che m si sposta da un punto A ad un punto B (allontandosi da M con stessa direzione di $\overrightarrow{d}$ )
![[Pasted image 20241109130207.png|300]]
![[Pasted image 20250202120417.png|700]]
$$
L_{AB} = \underbrace{ - \frac{GMm}{d_{A}}+\frac{GMm}{d_{B}}<0 }_{ d_{B} > d_{A} }
$$

supponendo $d_{B}\to \infty$, e che il lavoro, a meno di una costante nell'energia potenziale, non cambia:
$$
U_{A} = - \frac{GMm}{d_{A}}+\underbrace{ U_{\infty} }_{ =0\text{ per axx} }
$$
![[Pasted image 20250202120752.png|700]]
$$
E =\frac{1}{2}mv^2- \frac{GMm}{d}
$$
## 3.2 Cambiamento velocità in avvicinamento $m \to M$
$m$ si trova ad un distanza infinita, per poi avvicinarsi fino ad arrivare a una distanza $d$.
![[Pasted image 20250202122346.png|700]]
vale questa relazione
$$
v_{1}^2 = v_{0}^2+ \frac{2GM}{d}
$$
- $v_{0}$: velocità distanza iniziale (distanza infinita)
- $v_{1}$: velocità a distanza $d$


**OSS**:
in quanto $\frac{2GM}{d}>0$, avremo:
$$
v_{1}^2>v_{0}^2 \implies v_{1} > v_{0}
$$

quindi la velocità aumenta man mano che $m$ si avvicina ad $M$.

## 3.3 Velocità di fuga
Esiste una velocità oltre la quale un corpo $m$, lanciato con tale velocità si allontanerà di una distanza infinita, non tornando più indietro.

$v_{\infty}$: velocità raggiunta dalla particella non appena esce dal campo gravitazionale
$v_{F}$: velocità di fuga
$R_{T}$: raggio del terra

$$
\begin{cases}
E_{fin} = \frac{1}{2}m\underbrace{ v_{\infty}^2 }_{ = \, 0 }=0 \\
E_{in} = \frac{1}{2}m v_{F}^2- \frac{GMm}{R_{T}}
\end{cases}
$$

siccome $E_{in} = E_{fin}\implies E_{in}=0$
La formula vista prima considerava che la velocità $v_{1}$ veniva raggiunta quando la distanza era minore, rispetto alla velocità $v_{0}$. Quindi, qui si invertono: $v_{1} = v_{F}$.
$$
\begin{align}
v_{1}^2 = v_{0}^2+ \frac{2GM}{d} \implies

v_{F}^2&=\frac{2GM}{R_{T}}\\
v_{F}&=\sqrt{ \frac{2GM}{R_{T}} }
\end{align}

$$

# 4 Forza elastica o richiamo
![[Pasted image 20241109171256.png|700]]
$$
\overrightarrow{F}=-K \cdot \overrightarrow{x}
$$
- $K$: costante elastica (dipende dal materiale), corrisponde alla forza da applicare per spostare la molla di $1m$.
	- si misura in $\left[ \frac{N}{m} \right]$
- $\overrightarrow{x}$: vettore verso cui si sposta la molla

La forza elastica richiama la particella verso il "punto di equilibrio" (punto in cui è in stato di quiete).

## 4.1 Equazione del moto
$$
\begin{align}
\overrightarrow{F} &= m \cdot \overrightarrow{a} \\
&= m \cdot \frac{d \overrightarrow{v}}{dt} \\
&= m \cdot \frac{d^2 x}{dt^{2}} \\
 \\
-Kx&= m \cdot \frac{d^2 x}{dt^{2}} \\
\end{align}
$$

da cui ricaviamo la seguente equazione differenziale lineare omogenea:
$$
\begin{align}
y''+ay&=0 \\ \\
\frac{d^2x}{dt^2}+\frac{K}{m}x&=0 & [1]
\end{align}
$$

risolviamo tramite guess:
$$
x(t)=A \cdot \cos(\omega t + \phi)
$$
- $A$: ampiezza
- $\omega$: pulsazione / frequenza
	- si misura in $[s]$
- $\phi$: fase

dobbiamo ora sostituire questa guess nell'equazione $[1]$:
- calcolo la derivata seconda

$$
\begin{align}
\frac{dx}{dt}&=-\omega A\cdot \sin(\omega t+\phi) \\ \\

\frac{d^2x}{dt^2}&=-\omega^2 \underbrace{ A\cdot \cos(\omega t+\phi) }_{ x(t) }=-\omega^2 \cdot x(t)

\end{align}
$$

- sostituisco

$$
-\omega^2 \cdot x(t)+\frac{K}{m}x(t)=0
$$

risolvo e trovo:
$$
\begin{align}
-\omega^2 \cdot x(t)+\frac{K}{m}x(t)&=0 \\ \\

x(t)\left( -\omega^2+\frac{K}{m} \right) &= 0 \\
\end{align}
$$
quando $x(t)=0$ non ci interessa.
a noi interessa risolvere:
$$
\begin{align}
\left( -\omega^2+\frac{K}{m} \right) &= 0  \\
w &= \sqrt{ \frac{K}{m} } 
\end{align}
$$

dobbiamo ora imporre le ipotesi:
1. $x(t = 0) = x_{0}$
2. $v(t = 0) = 0$

per garantire l'ipotesi 2, dobbiamo imporre che l'equazione della velocità sia uguale a zero al tempo 0:
$$
\begin{align}
\frac{dx}{dt}=-\omega A\cdot \sin(\omega t+\phi)&=0 \\
-\omega A\cdot \sin(\phi)&=0
\end{align}
$$
lo sarà quando $\phi = 0$

per garantire l'ipotesi 1:
$$
x_{0} = A \cdot \cos(\phi) \underbrace{ = }_{ \phi \, = 0 } A
$$

quindi l'equazione del moto elastico di una particella che parte dal punto $x_{0}$, da ferma è la seguente:
$$
x(t)=x_{0} \cdot \cos\left( \omega \cdot t \right) \text{ con } \omega = \sqrt{ \frac{K}{m} }
$$

### 4.1.1 Periodo
Il moto della forza elastica è un moto periodico di tempo.
$$t=T: \quad\omega T = 2 \pi \implies
\begin{align}
T &= \frac{2\pi}{\omega}
\end{align}
$$
![[Pasted image 20241109184938.png|500]]
## 4.2 Energie forza elastica
La forza elastica è conservativa.
$$
\begin{align}
L_{AB}&=\int^B_{A}\overrightarrow{F} \cdot dx  \\ \\

&=\int^B_{A}-Kx \cdot dx \\
 \\
&=-K\int^B_{A}x \cdot dx\\ \\
&=-K\left( \frac{x^2_{B}}{2}-\frac{x^2_{A}}{2} \right) \\ \\

&=\frac{Kx^2_{A}}{2}-\frac{Kx^2_{B}}{2} \\ \\
&=U_{A}-U_{B} \implies U = \frac{1}{2}Kx^2
\end{align}
$$
in quanto di forza conservativa:
$$
E_{in} = E_{fin}
$$
con:
$$
\begin{align}
E &= K + U \\
 \\
&= \left( \frac{1}{2}m\cdot \underbrace{ v^2 }_{ \frac{dx}{dt} = x'(t) } \right) + \left( \frac{1}{2}K\cdot\underbrace{ x^2 }_{ x(t) } \right) \\
 \\
&= \left( \frac{1}{2}\underbrace{ m\cdot \omega^2 }_{ K }x_{0}^2\sin^2\omega t\right) + \left( \frac{1}{2}K\cdot x_{0}^2\cos^2\omega t\right) \\
 \\
&= \left( \frac{1}{2}Kx_{0}^2\sin^2\omega t\right) + \left( \frac{1}{2}K\cdot x_{0}^2\cos^2\omega t\right) \\
 \\
&=K \cdot \frac{x_{0}^2}{2}(\underbrace{ \sin^2(\omega t)+\cos^2(\omega t) }_{ =\, 1 }) \\
 \\
E &= K \cdot \frac{x_{0}^2}{2}
\end{align}
$$



# 5 Forza di attrito
## 5.1 Forza viscosa
Primo esempio di forza d'attrito.
Consideriamo una pallina dentro un cilindro che si muove verso il basso a causa della forza peso $\overrightarrow{P}$
![[Pasted image 20241109193703.png|200]]
Se il movimento fosse dipeso solo da $\overrightarrow{P}$ sarebbe un moto uniformemente accelerato:
$$
\begin{align}
\overrightarrow{a}&=\overrightarrow{g} \\
v(t)&=v_{0}+g\cdot t
\end{align}
$$
ma dall'esperienza sappiamo:
![[Pasted image 20241109194257.png|500]]


Si osserva sperimentalmente che la velocità di un punto materiale in un liquido arriva a una velocità $V_{\text{limite}}$ per $t \to \infty$.
$$
\overrightarrow{f_{v}} = -\beta \overrightarrow{v}
$$
- $\beta$ si chiama **resistenza viscosa**, dipende dal fluido e dalla sua geometria.
- il segno meno è dato dal verso opposto rispetto a $\overrightarrow{P}$

$$
\begin{align}
\overrightarrow{F} &= m \cdot \overrightarrow{a}\\
\overrightarrow{P} + \overrightarrow{f_{v}} &= m \cdot \overrightarrow{a}\\
\\ -mg - \beta v_{y}&= m \cdot a_{y}
\\ -mg - \beta v_{y}&= m \cdot \frac{d v_{y}}{dt}

\end{align}
$$
Sperimentalmente, sappiamo che per $t \to \infty \implies \frac{d v_{y}}{dt}=0$, quindi:
$$
\begin{align}
v_{y} &= -\frac{mg}{\beta} \quad\text{ per } t \to \infty
\end{align}
$$
### 5.1.1 Equazione del moto
Si dimostra matematicamente che vale:
$$
\large
\begin{align}
v_{y}(t)&=\frac{mg}{\beta}\cdot \left( e^{- \frac{\beta t}{m}}-1 \right) & [\text{Axx}] \\
\frac{d v_{y}}{dt}&=\frac{\cancel{ m }g}{\cancel{ \beta }}\cdot e^{- \frac{\beta t}{m}} \cdot \left(-\frac{\cancel{ \beta }}{\cancel{ m }}\right)  \\
\frac{d v_{y}}{dt}&= -g \cdot e^{- \frac{\beta t}{m}} \\ \\

\frac{m \cdot d v_{y}}{dt}&= -m \cdot g \cdot e^{- \frac{\beta t}{m}} \\ \\
 
 -mg-\beta v_{y}&=-mge^{-\frac{\beta t}{m}} & [-mg - \beta v_{y}&= m \cdot \frac{d v_{y}}{dt}]
\end{align}
$$

Abbiamo quindi trovato la **forza** compiuta dalla gravità sulla particella, considerando la forza viscosa. È un altro modo di esprimere la formula precedente (sta volta più precisa)
l'accelerazione sarà la seguente (prendo la forza e divido per $m$):
$$
a=g \cdot e^{-\frac{\beta t}{m}}
$$

### 5.1.2 Lavoro
$$
\begin{align}
dL &= \overrightarrow{f}_{v} \cdot d \overrightarrow{s} \\ \\

&= -\beta \overrightarrow{v} \cdot d \overrightarrow{s} \\
&= -\beta \overrightarrow{v} \cdot \underbrace{ \frac{d\overrightarrow{s}}{dt} }_{ \overrightarrow{v} } \cdot dt \\
&=-\beta \underbrace{ \overrightarrow{v} \cdot \overrightarrow{v}  }_{ v^2 }dt \\ \\
&=-\underbrace{ \beta v^{2 } }_{ > \, 0 } dt < 0 \\
 \\
\implies& L_{v} < 0 \\
\implies& K_{fin} < K_{in}
\end{align}
$$


La forza d'attrito è una forza che si oppone al movimento della particella, rallentandone la velocità.
Vengono dette **dissipative**: dissipano energia cinetica.

## 5.2 Attrito statico
Quando si applica una forza a un oggetto serve una forza minima per farlo spostare.
![[Pasted image 20241110102810.png|500]]
L'attrito con il piano è detto **attrito statico**.

Coefficienti di attrito:
- $\mu_{s}$: coefficiente di attrito statico, ovvero quello relativo alla forza minima per fare spostare il corpo
- $\mu_{c}$: coefficiente di attrito cinematico (o dinamico), ovvero quello relativo al rallentamento del corpo in movimento (fino a fermarsi)
Vale che: $\mu_{c} \leq \mu_{s}$
I coefficienti di attrito $\mu_{c}, \mu_{s}$ sono compresi tra $[0.1, 1]$

- $\overrightarrow{N}$: Reazione vincolare o normale, ovvero la forza sviluppata dal piano
- $\overrightarrow{P}$: Forza peso 
- $\overrightarrow{F}_{max}$: Forza di attrito massima che superata fa spostare il corpo
	- $F_{max} = \mu_{s} N$
- $\overrightarrow{F_{A}}$: Forza applicata
- $\overrightarrow{F_{a}}$ o $\overrightarrow{F}_{t}$ o $\overrightarrow{F}_{\text{CRITICA}}$: Forza di attrito / forza critica.
	- Finché $\overrightarrow{F}_{A} < \overrightarrow{F}_{max} \implies \overrightarrow{F}_{A} = -\overrightarrow{F}{a}$

Il corpo è in quiete, quindi vuol dire che:
- Le forze verticali si annullano: $\overrightarrow{N} - \overrightarrow{P} = 0 \implies N = m g$
- Le forze orizzontali si annullano: $\overrightarrow{F}_{A} < \overrightarrow{F}_{max}$

## 5.3 Attrito cinematico (o dinamico)
![[Pasted image 20241110110118.png|200]]
Vale che:
$$
\overrightarrow{F}_{a}=- \mu_{c} \cdot N \cdot \hat{v}
$$
### 5.3.1 Lavoro
come la dimostrazione della [[#5.1.2 Lavoro|forza viscosa]]
$$
\begin{align}
dL &= \overrightarrow{F}_{a \\} \cdot d \overrightarrow{s} \\ \\

&= - \mu_{c} \cdot N \cdot \hat{v} \cdot d \overrightarrow{s} \\
&= - \mu_{c} \cdot N \cdot \hat{v} \cdot \underbrace{ \frac{d\overrightarrow{s}}{dt} }_{ \overrightarrow{v} } \cdot dt \\
&=- \mu_{c} \cdot N \cdot  \underbrace{ \hat{v} \cdot \overrightarrow{v}  }_{ \frac{v^2}{v}=v }dt\\ \\
&=-\underbrace{ \mu_{c} \cdot N \cdot  v \, }_{ > \, 0 } dt < 0 \\
 \\
\implies& L_{a} < 0 \\
\implies& K_{fin} < K_{in}
\end{align}
$$

## 5.4 Piano inclinato
![[Pasted image 20241110163504.png|400]]
Vogliamo cercare la condizione di $\theta$ affinché un corpo in quiete rimanga in quiete.
Quando $F_{A} < F_{\text{MAX}} \implies F_{a} = F_{A}$. quindi:

$$
\begin{align}
f_{A} &\leq F_{MAX}\\
f_{a} &\leq \mu_{s}\underbrace{ N }_{ mg\cos \theta } \\
f_{a} &\leq \mu_{s}mg\cos \theta \\ \\

\cancel{ mg }\sin \theta &\leq \mu_{s}\cancel{ mg }\cos \theta  \\
 \frac{\sin \theta}{\cos \theta} &\leq \mu_{s}\\ \\

\tan \theta &\leq \mu_{s}
\end{align}
$$

se non soddisfa vuol dire che la forza di attrito statico non è sufficiente per bilanciare il corpo.

n.b. si usa il $\cos$ al posto del ${} \sin$ perché l'angolo ${} \theta$ non è quello in alto a sinistra, ma il complementare. 
### 5.4.1 Moto del corpo nel piano inclinato
$$
\begin{align}
\overrightarrow{F} &= m \overrightarrow{a} \\
mg\sin \theta -\mu_{c}\underbrace{ N }_{ mg\cos \theta }&=ma \\ \\

\cancel{ m }g\sin \theta -\mu_{c}\cancel{ m }g\cos \theta&=\cancel{ m }a \\ \\
a &= g(\sin \theta - \mu_{c}\cos \theta)
\end{align}
$$
L'accelerazione è quindi costante, non dipende dal tempo.
$$
S = \frac{1}{2} \cdot a \cdot t^2
$$
# 6 Pendolo
## 6.1 Equazione del moto
Un oggetto puntiforme $P$ di massa $m$ è sospeso a un filo inestensibile e inflessibile, di massa trascurabile di lunghezza $l$.
![[Pasted image 20241110123339.png|400]]
- $l$: lunghezza del filo inestensibile

Si scompongono le componenti delle forze.
Consideriamo il nostro piano:
- asse X: coincide con $l$
- asse Y: coincide con la circonferenza

Per studiare il moto si pongono le seguenti equazioni sulle due assi (rispetto al moto):
- asse perpendicolare: $\tau - mg \cos \theta = 0 \implies \tau = mg \cos \theta$
	- Ponendo $\theta = 0$ possiamo semplificare: $\tau = mg$
- asse parallela: dall'esperienza sappiamo che la traiettoria percorsa dal filo, formerà un arco della circonferenza, di raggio $r = l$.
$$
\begin{align}
-mg \cdot \sin \theta &= ma \\
&= m\frac{d^{2}S}{dt^{2}} \\
&= m\cdot l \frac{d^{2}\theta}{dt^{2}}  &[S=l \cdot \theta] \\
-g \cdot \sin \theta &= l \frac{d^{2}\theta}{dt^{2}} \\
\frac{d^{2} \theta}{dt^{2}} + \frac{g}{l} \cdot \sin \theta &= 0
\end{align}
$$


Risolvendo questa equazione trovata troviamo $\theta(t)$.
La risolveremo tramite una guess come nella [[#4.1 Equazione del moto|forza elastica]]. È uguale, tranne per $\sin \theta$: si assume che $\theta_{0} \to 0$. Siccome $\sin \theta \approx \theta \quad [\lim_{ x \to 0} \frac{\sin x}{x}=1]$, si prova che:

$$
\theta(t) = \theta_{0} \cdot \cos (wt) \quad \text{con } w=\sqrt{\frac{g}{l}}
$$

Il periodo trovato è indipendente dalla massa e dall'angolo $\theta_{0}$ (sperimentalmente si nota che vale fino a $\theta_{0} \approx 10°$)

# 7 Urto elastico
Un urto si dice elastico quando valgono le seguenti condizioni:
$$
\begin{cases}
\overrightarrow{P}_{in} = \overrightarrow{P}_{fin} & \text{[qnt. moto]} \\
K_{in} = K_{fin}
\end{cases}
$$
Siano due particelle con velocità iniziale $v_{1}$ e $v_{2}$ con massa $m_{1}$ e $m_{2}$. Indichiamo con $V_{1}$ e $V_{2}$ le velocità dopo la collisione della prima particella verso la seconda. Assumiamo che $v_{2} = 0$.

Utilizzando l'ipotesi della quantità di moto:
$$
\begin{align}
\overrightarrow{P}_{in} &= \overrightarrow{P}_{fin} \\
 \\
m_{1}V_{1}&=m_{1}V_{1}+m_{2}V_{2}
\end{align}
$$

Aggiungendo la seconda ipotesi si ottiene:
$$
\begin{cases}
V_{1} = \frac{m_{1} - m_{2}}{m_{1} + m_{2}}v_{1} \\
V_{2} = \frac{2m_{1}}{m_{1} + m_{2}}v_{1}
\end{cases}
$$
## 7.1 Come il rapporto delle masse cambiano il sistema
### 7.1.1 Masse uguali $m_{1} = m_{2}$
Usando le formule si ottiene:
$$
\begin{cases}
V_{1} = 0 \\
V_{2} = v_{1}
\end{cases}
$$
Il moto (la velocità) viene trasferito dalla prima alla seconda particella.
### 7.1.2 Massa maggiore: $m_{1} \gg m_{2}$
Usando le formule si ottiene:
$$
\begin{cases}
V_{1} \approx v_{1} \\
V_{2} \approx 2 v_{1}
\end{cases}
$$
La velocità della prima particella rimane costante, mentre la seconda particella prende il doppio della velocità della prima.
### 7.1.3 Massa minore: $m_{1} \ll m_{2}$
Usando le formule si ottiene:
$$
\begin{cases}
V_{1} \approx -v_{1} \\
V_{2} \approx 0
\end{cases}
$$
La prima particella torna indietro con la stessa velocità e la seconda rimane ferma.
## 7.2 Urti completamente anelastici
Avviene quando la collisione comporta l'unione delle due particelle come se fossero un unico corpo.
Un urto si dice completamente anelastico quando vale:
$$
\overrightarrow{P}_{in} = \overrightarrow{P}_{fin}
$$

Siccome le particelle si uniscono (si fondono), $V_1=V_2$, che chiameremo $V$.

$$
\begin{cases}
P_{in}=m_{1}v_{1} \\
P_{fin}=m_{1}V+m_{2}V
\end{cases}
$$

Si trova che:
$$
V = \frac{m_{1}}{m_{1} + m_{2}} v_{1}
$$


# 8 Termodinamica
## 8.1 Principio zero
due corpi (il sistema) inizialmente in stati termici differenti, posti in contatto tra loro e isolati rispetto a tutto ciò che hanno intorno (ambiente esterno), dopo un certo tempo si trovano nello stesso stato termico.
## 8.2 Tipi di sistemi
![[Pasted image 20241130150323.png]]

Un sistema chiuso si dice in **equilibrio termodinamico** quando:
- **equilibrio meccanico**: l'insieme delle forze applicate è uguale a 0
- **equilibrio termico**: in tutti i punti del sistema la temperatura è la stessa (omogenea)
- **equilibrio chimico**: garantisce che non ci siano in corso reazioni che alterino la composizione relativa del sistema

I parametri di stato principali sono Temperatura, Pressione e Volume. C'è anche densità e altri...

## 8.3 Temperatura e caloria
**Temperatura**: grandezza fisica che quantifica lo stato termico in cui si trova un corpo

**Calore**: Energia scambiata tra due sistemi tra cui sussiste una differenza di temperatura
- Ex: pezzo di ghiaccio scaldato. La caloria corrisponde alla quantità di ghiaccio fuso in seguito al riscaldamento

**Caloria**: calore che va fornito ad un grammo di acqua per aumentare la sua temperatura da 14.5 Celsius a 15.5 Celsius
## 8.4 Trasformazioni
- **Trasformazione termodinamica**: Cambio dei parametri di stato di un sistema.
- **Trasformazione tra stati di equilibrio**: Stato iniziale e finale sono stati di equilibrio termodinamico.
- **Trasformazione ciclica**: Stato iniziale e finale coincidono. ^b9c3ae
- **Trasformazione quasi-statica**: durante la quale il sistema passa solo attraverso stati di equilibrio termodinamico
- **Trasformazione reversibile**:
	- Quando consente di tornare dallo stato finale a quello iniziale.
	- Trasformazione quasi-statica da uno stato iniziale (SI) ad uno finale (SF), per la quale è possibile andare da SF a SI ripercorrendo gli stessi stati intermedi che da SI hanno portato a SF.
- **Trasformazione irreversibile**: quando avvengono fenomeni dissipativi oppure la trasformazione non è quasi statica.
- **Trasformazione spontanea**: Trasformazione di un sistema isolato da uno stato di non equilibrio ad uno stato di equilibrio termodinamico.

## 8.5 Variabili di stato
- intensiva: se non dipende dall'estensione del sistema
	- ex: pressione, temperatura, densità
- estensiva: se dipende dall'estensione del sistema
	- ex: massa, volume

## 8.6 Gas perfetti
- Gas formato da un gran numero di molecole
- Volume molecole trascurabile
- Forze tra le molecole trascurabili
- Gli urti delle molecole con le pareti del recipiente sono elastici.

I gas rarefatti si comportano in maniera simile (approssimando).

### 8.6.1 Trasformazioni
Si parte in uno stato con pressione $P_{0}$, volume $V_{0}$ e temperatura di $0 °C$.
$P_{0}$: pressione a 0 gradi celsius
$V_{0}$: volume a 0 gradi celsius
$\alpha=\frac{1}{273.15} °C$: costante indipendente dalla natura del gas

avremo le seguenti trasformazioni:
- isocora
	- a volume costante
	- $P=P_{0}(1+\alpha \cdot T(°C))$
- isobara
	- a pressione costante
	- $V=V_{0}(1+\alpha \cdot T(°C))$
- isoterma
	- a temperatura costante
	- $PV = P_{0}V_{0}$

possiamo riscrivere queste trasformazioni usando la scala di temperatura in kelvin:
$$
T(K)= T(°C) + 273.15
$$
Quando la temperatura in gradi celsius è zero avremo:
$$
T_{0}(K)=273.15
$$

prendendo ad esempio la trasformazione a volume costante
$$
\begin{align}
P&=P_{0}(1+\alpha \cdot T(°C)) \\
&=P_{0}\left( 1+\frac{1}{273.15 °C} T(°C) \right) \\
&=P_{0}\cdot \frac{1}{273.15 °C}(273.15 °C +T(°C))  \\
&=P_{0} \cdot \frac{1}{T_{0}(K)} T(K) \implies \frac{P}{P_{0}} = \frac{T(K)}{T_{0}(K)}\\
\end{align}
$$

le trasformazioni saranno quindi:
- **a volume costante**: $P=P_{0}\frac{T}{T_{0}}$
- **a pressione costante**: $V=V_{0}\frac{T}{T_{0}}$

Si osserva sperimentalmente che a temperatura di $T=0 K$ la pressione del gas va a zero

### 8.6.2 Equazione di stato
Vengono effettuate in sequenza due trasformazioni.
1. Trasformazione isocora da $T_{0}$ a $T$
$$
P_{1}=P_{0} \frac{T}{T_{0}}
$$
2. Mantenendo la temperatura $T$ (trasformazione temperatura costante) ed effettuando la trasformazione isoterma da $V_{0}$ a $V$ avremo:
$$
P_{1}V_{0}=PV
$$

pongo le trasformazioni a sistema e ottengo:
$$
\frac{P_{0}V_{0}}{T_{0}}=\frac{PV}{T}
$$

La quantità $\frac{PV}{T}=n \cdot R$ è costante
- $n$: numero di moli
- $R = 8.314 \cdot \frac{J}{mol \cdot K}$: costante universale gas perfetti.

quindi: ^0113c8
$$
PV = n \cdot R \cdot T
$$
### 8.6.3 numero totale di atomi
$$
N_{tot}= n \cdot N_{A}
$$
- $N_{A}= 6.022 \cdot 10^{23}$: numero di Avogadro

### 8.6.4 Energia cinetica
L'energia cinetica totale sarà uguale:
$$
K_{tot}=\sum^{N_{tot}}_{i=1}\frac{mv_{i}^2}{2}
$$
- $v_{i}$: velocità i-esimo atomo


#### 8.6.4.1 relazione tra energia cinetica media e temperatura
data l'energia cinetica media:
$$
\begin{align}
\langle K\rangle &= \frac{1}{N_{tot}}\sum^{N_{tot}}_{i=1}\frac{mv_{i}^2}{2} \\
&=\frac{1}{n \cdot N_{A}}\sum^{n \cdot N_{A}}_{i=1}\frac{mv_{i}^2}{2}  \\
\langle K\rangle &= \frac{K_{tot}}{n \cdot N_{A}} & [1]
\end{align}
$$

si può dimostrare la relazione:
$$
\begin{align}
PV &= \frac{2}{3}K_{tot} \\
&= \frac{2}{3}n \cdot N_{A} \langle K\rangle & [\text{isolo nella 1}]\\
\end{align}
$$

mettendo a sistema questo risultato con il [[#^0113c8|precedente]]:
$$
\begin{cases}
PV = n \cdot R \cdot T \\
PV = \frac{2}{3}n \cdot N_{A} \langle K\rangle
\end{cases}
$$

la relazione sarà dunque:
$$
T = \frac{2}{3}\frac{N_{A}}{R} \langle K\rangle
$$

questa relazione si può riscrivere usando la costante di boltzman:
$$
k_{B}=\frac{R}{N_{A}} \approx 1.38 \cdot 10^{-23} \frac{J}{K}
$$


$$
T = \frac{2}{3k_{b}}\langle K\rangle
$$
La temperatura è una misura dell'energia cinetica media delle particelle.
## 8.7 Calore scambiato in una trasformazione termodinamica
$\delta Q$: quantità di calore scambiato
- dipende dalla trasformazione e non solo dalle temperature iniziali / finali

Tipi di calore:
- $c(T)$: calore specifico $(cal \cdot kg^{-1}K^{-1})$. Calore necessario per innalzare la temperatura di 1 kg di 1 grado Kelvin
$$
\delta Q = m \cdot c(T) \cdot dT
$$


- $C(T)$: calore molare $(cal \cdot mol^{-1}K^{-1})$. Calore necessario per innalzare la temperatura di 1 mole di 1 grado Kelvin
$$
\delta Q = n \cdot C(T) \cdot dT
$$

Approssimando:
- il calore specifico è indipendente dalla temperatura
- il calore molare è indipendente dal solido

approssimando avremo:
$$
C = 3R
$$

indichiamo con $Q$ il calore che scambia un corpo per passare da una temperatura $T_{1}$ a $T_{2}$:
$$
Q = mc(T_{2}-T_{1})=nC(T_{2}-T_{1})
$$

### 8.7.1 Equilibrio termico
Siano $T_{1}, T_{2}$ ($T_{1} > T_{2}$) le temperature di due corpi all'interno di un sistema isolato.

In quanto il sistema isolato:
$$
Q_{1} = -Q_{2}
$$
$$
\begin{align}
Q_{1} &= m_{1}c_{1}(T_{eq}-T_{1}) \\
Q_{2} &= m_{2}c_{2}(T_{eq}-T_{2})
\end{align}
$$

La temperatura di equilibrio è data dalla media pesata delle temperature dei due corpi, dove i pesi sono il prodotto tra massa e calore specifico dei corpi:
$$
T_{eq}=\frac{m_{1}c_{1}T_{1}+m_{2}c_{2}T_{2}}{m_{1}c_{1}+m_{2}c_{2}}
$$

Caso limite $m_{1}c_{1} \gg m_{2}c_{2}$:
- $T_{eq} \approx T_{1}$
- $Q_{2} \approx m_{2}c_{2}(T_{1}-T_{2})$


## 8.8 Lavoro in una trasformazione termodinamica
![[Pasted image 20241130193055.png|500]]
- S: superficie
- P: pressione

Diremo **lavoro di espansione**:
$$
\delta L = \underbrace{ PS }_{ \text{forza} }\underbrace{ dh }_{ \text{ spostamento } }
$$
Siccome:
$$
S \cdot h = V
$$
la variazione di volume dopo la trasformazione sarà (derivata del prodotto, ma l'altro membro è nullo dato che $S$ è costante):
$$
Sdh = dV
$$
quindi:
$$
\delta L = PdV
$$


il lavoro di un sistema termodinamico dipende dalla trasformazione seguita.

## 8.9 Primo principio della termodinamica
in ogni [[#^b9c3ae|trasformazione ciclica]] il rapporto tra lavoro e calore è costante:
$$
\frac{L}{Q_{cal}} = J = 4.186 \, \frac{Joule}{cal}
$$

quindi potremmo esprimere il calore Q:
- in calorie
- in Joule: moltiplicando per la costante $J$
	- $Q_{cal} = Q_{joule} \cdot J$

Dunque calore e lavoro possono essere espressi nelle stesse unità di misura: il calore è una delle forme in cui l’energia si trasmette.


Se esprimiamo il calore in Joule possiamo scrivere:
$$
\begin{align}
\frac{L}{\cancel{ J }Q_{joule}}&=\cancel{ J }  \\
\frac{L}{Q_{joule}}&=1 \\ \\

Q_{joule} - L &= 0 
\end{align}
$$

In ogni trasformazione ciclica, il calore ed il lavoro scambiato sono uguali.
Presa una qualunque trasformazione che passa tra stati intermedi di una trasformazione ciclica, $Q-L$ dipende solo dallo stato iniziale e finale:
$$
\begin{align}
Q-L &=F(A,B)
\end{align}
$$
![[Pasted image 20241201102934.png|500]]

con $U=U(P,V,T)$ misuriamo l'energia interna del sistema.
Vale per tutte le trasformazioni (reversibili e non):
$$ Q - L = U(B)-U(A)$$
### 8.9.1 Altri tipi di trasformazione
**Adiabatica**:
- $Q = 0$
- $-L = U(B)-U(A)$

nel caso di espansione adiabatica, ovvero lavoro associato a variazione di volume, se il lavoro è positivo avremo:
$$
\begin{align}
\underbrace{ \Delta U }_{ <0 } &= \underbrace{ -\underbrace{ L }_{ >0 } }_{ <0 } \\ \\

U(B)-U(A) &<0  \\
U(B) &<U(A)  \\
\end{align}
$$
Quindi il sistema compie del lavoro verso l'esterno a spese della proprie energia interna che diminuisce.

**Isocora**:
- $L=0$
- $Q = U(B)-U(A)$

nel caso di trasformazione isocora, se $Q>0$, ovvero è a contatto con un corpo più caldo (cede calore al nostro corpo)
$$
\begin{align}
\underbrace{ \Delta U }_{ >0 } &= \underbrace{ Q }_{ >0 }\\ \\

U(B)-U(A) &>0  \\
U(B) &>U(A)  \\
\end{align}
$$

quindi aumenta la propria energia interna.

Per tutte e due le trasformazioni vale il caso contrario.

### 8.9.2 Energia interna

#### 8.9.2.1 Corpo solido
Volume e pressione sono immutabili:
$$
\begin{align}
U &= U(T)\\
 \\
Q &= \Delta U &[\Delta V=0]  \\
 \\
\delta Q &= dU &[\text{derivo}] \\
 \\
dU &= mc(T)dT & [\delta Q = mc(T)dT]\\ \\
U(T_{B})-U(T_{A}) &= m \int^{T_{B}}_{T_{A}}c(T)dT \\ \\
U(T_{B})-U(T_{A}) &= mc \int^{T_{B}}_{T_{A}}dT & [c(T) \approx c] \\ \\
U(T_{B})-U(T_{A}) &\approx mc(T_{B}-T_{A})  \\ \\
\end{align}
$$

dato un $T$ generico avremo:
$$
U(T)=mcT+\text{costante}
$$

#### 8.9.2.2 Gas perfetto
Data un espansione libera e adiabatica di un gas rarefatto:
- $Q=0$: non scambia calore con l'esterno
- $L=0$: le pareti non si spostano

![[Pasted image 20241201112734.png|500]]

dal primo principio:
$$
\begin{align}
\Delta U&=0 \\
 \\
\Delta T&=0 & [\text{sperimentalmente}]\\
\end{align}
$$

l'energia interna dipenderà solo dalla temperatura:
- $P_{i}\neq P_{f}$
- $V_{i}\neq V_{f}$
- $\Delta U=0$

$$
U=U(T)
$$
Infatti, in base alla trasformazione avremo:
- trasformazione a **volume costante**:

$$
\begin{align}
\delta Q &= \underbrace{ PdV }_{ \text{lavoro} }+dU \\ \\

\delta Q &= dU & [dV=0]\\ \\

dU &= nC_{v}dT\\
\end{align}
$$


- $C_{v}$: calore molare a volume costante

dato un $T$ generico avremo:
$$
U(T)=nC_{v}T+\text{costante}
$$

per axx. la legge sopra vale sempre (non solo per trasformazione a volume costante).

- trasformazione a **pressione costante**:

$$
\large
\begin{align}
\delta Q &= \underbrace{ PdV }_{ \text{lavoro} }+dU \\ \\

\delta Q &= nC_{p}dT\\ \\
nC_{p}dT&=PdV+\underbrace{ dU }_{ =nC_{v}dT } \\ \\

&=PdV + nC_{v}dT  &[1] \\
\end{align}
$$

dai risultati precedenti abbiamo:

$$
\begin{align}
PV&=nRT & [\text{derivo rispetto al tempo}]\\
 \\
\underbrace{ \frac{d(PV)}{\cancel{ dt }} }_{ \text{der. prodotto} }&=\underbrace{ nR }_{ \text{indipendente dal tempo} }\frac{dT}{\cancel{ dt }} \\
\end{align}
$$

per ipotesi la pressione è costante quindi $dP = 0$:

$$
\begin{align}
\underbrace{ VdP }_{ =0 }+PdV &= nRdT \\
PdV &= nRdT \\ \\
\end{align}
$$

ripartendo dalla 1:

$$
\begin{align}
nC_{p}dT&=PdV + nC_{v}dT \\
\cancel{ n }C_{p}\cancel{ dT }&=\cancel{ n }R\cancel{ dT } + \cancel{ n }C_{v}\cancel{ dT } \\
 \\
C_{p}&=C_{v}+R
\end{align}
$$


#### 8.9.2.3 cosa comportano le trasformazioni
![[Pasted image 20241201132544.png|800]]

![[Pasted image 20241201132603.png|800]]

**Temperatura Costante**
si ricorda che $U=U(T)$. siccome $T$ è costante $dU=0$.
siccome
![[Pasted image 20241201132758.png|500]]
allora
![[Pasted image 20241201133113.png|800]]

![[Pasted image 20241201132640.png|800]]
## 8.10 Secondo principio termodinamica
Il Primo Principio della Termodinamica non pone limiti alla conversione di calore in
lavoro e viceversa.

In natura non esista le simmetria per cui:
$$
\Delta U=0 \implies Q = L
$$

Ex: frigorifero che ha bisogno del lavoro aggiuntivo per funzionare.

![[Pasted image 20241201155523.png|800]]

**Enunciato di Clausius**: La realizzazione di una trasformazione termodinamica il cui unico risultato sia quello di trasferire calore da un sistema a temperatura inferiore a uno con temperatura superiore è impossibile.

**Enunciato di Kelvin-Planck**: La realizzazione di una trasformazione termodinamica ciclica il cui unico risultato sia quello di assorbire calore da una sola sorgente e di trasformarlo integralmente in lavoro è impossibile.

sono equivalenti questi enunciati.

### 8.10.1 Ciclo di Carnot
Macchina termica reversibile, a gas perfetto.
Lavora con due sorgenti a temperature rispettivamente: $T_{c}$,  $T_{f}$.
![[Pasted image 20241201160351.png|800]]
![[Pasted image 20241201160441.png|800]]
In quanto è un sistema chiuso avremo che $\Delta U= 0$, quindi:
$$
\begin{align}
Q&=L \\
&= |Q_{c}|-|Q_{f}|
\end{align}
$$

#### 8.10.1.1 Rendimento
$$
\begin{align}
\eta&=\frac{L}{|Q_{c}|} \\ \\

&=\frac{|Q_{c}|-|Q_{f}|}{|Q_{c}|} & [\text{sostituisci dalla formula di prima}]\\ \\
\eta&=1-\frac{|Q_{f}|}{|Q_{c}|} \\ \\

\end{align}
$$

si può dimostrare che per il ciclo di carnot:
$$
\eta = 1 - \frac{T_{F}}{T_{C}}
$$

#### 8.10.1.2 disuguaglianza di Clausius
il teorema di carnot impone anche un limite superiore al rendimento della macchina termica reale:
$$
\eta=1 - \frac{|Q_{F}|}{|Q_{C}|}\leq 1 - \frac{T_{F}}{T_{C}}
$$

quindi:
$$
\begin{align}
\cancel{ 1 } - \frac{|Q_{F}|}{|Q_{C}|}&\leq \cancel{ 1 } - \frac{T_{F}}{T_{C}} \\  \\

\frac{|Q_{C}|}{T_{C}}&\leq \frac{|Q_{F}|}{T_{F}} \\ \\
\frac{\underbrace{ |Q_{C}| }_{ >0 }}{T_{C}}- \frac{|\underbrace{ Q_{F} }_{ <0 }|}{T_{F}} &\leq 0\\ \\
\frac{Q_{C}}{T_{C}}+ \frac{Q_{F}}{T_{F}} &\leq 0\\ \\


\end{align}
$$
questa conclusione prende il nome di **disuguaglianza di clausius**

un enunciato alternativo:
$$
\begin{align}
\sum_{i=C,F} &\frac{Q_{i}}{T_{i}}\leq 0 \\
 \\
\oint \frac{\delta Q}{T} &\leq 0
\end{align}
$$

### 8.10.2 entropia
nel caso di cicli reversibili:
$$
\begin{align}
\oint \frac{\delta Q}{T} &=0 \\

\underbrace{ \int^{B}_{A} \frac{\delta Q_{rev}}{T} }_{S(B)-S(A)}+\int^{A}_{B} \frac{\delta Q_{rev}}{T}&=0
\end{align}$$

definiremo come Entropia:
$$
S(B)-S(A)
$$
sarà una funzione che dipende solo dagli stati iniziale e finale del sistema termodinamico.
#### 8.10.2.1 trasformazioni: irreversibile, reversibile
![[Pasted image 20241212192340.png]]

$$
\begin{align}
\oint \frac{\delta Q}{T}&=\int_{I}\frac{\delta Q_{irr}}{T}+\int_{II}\frac{\delta Q_{rev}}{T} \leq 0  \\
 \\

&= \int_{I}\frac{\delta Q_{irr}}{T} - \int^{B}_{A}\frac{\delta Q_{rev}}{T} \leq 0\\
 \\
&= \int_{I}\frac{\delta Q_{irr}}{T} - (S(B)-S(A)) \leq 0 \\
 \\
&= \int_{I}\frac{\delta Q_{irr}}{T} \leq S(B)-S(A) = \Delta S \\
\end{align}
$$

#### 8.10.2.2 in una trasformazione adiabatica
se la trasformazione è reversibile, allora $\delta Q_{irr}=0$:
$$
\Delta S_{\text{adiabatica}}\geq 0
$$

#### 8.10.2.3 in un sistema isolato
se la trasformazione è reversibile, allora $\delta Q_{irr}=0$:
$$
\Delta S_{\text{Sist. isolato}}\geq 0
$$
È il secondo principio della termodinamica espresso in termini dell'entropia.
#### 8.10.2.4 caratteristiche
L’entropia di un sistema isolato non può diminuire.
- Ogni trasformazione irreversibile comporta un aumento dell’entropia dell’intero sistema.
- Ogni trasformazione reversibile non comporta una variazione di entropia dell’intero sistema.

Un sistema termodinamico + ambiente: sistema isolato.

L'entropia sarà:
$$
S = S_{\text{ambiente}} + S_{\text{sistema}}
$$

quindi:
$$
\Delta S_{\text{sistema + ambiente}}\geq 0 \quad [1]
$$

può accadere che $\Delta S_{\text{sistema}} > 0$ oppure $\Delta S_{\text{sistema}} < 0$, l'importante che la relazione $[1]$ rimanga

#### 8.10.2.5 calcolo
$$
\begin{align}
\delta Q_{rev}&=dU + \delta L_{\text{rev}} & [Q-L=\Delta U] \\
 \\
\underbrace{ \frac{\delta Q_{rev}}{T} }_{ dS }&=\frac{{dU + \delta L_{\text{rev}}}}{T} \\
dS&=\frac{{dU + \delta L_{\text{rev}}}}{T}  \\  \\
\Delta S=S(B)-S(A) &= \int^{B}_{A}\frac{{dU + \delta L_{\text{rev}}}}{T} & [1] \\
\end{align}
$$


- nel **corpo solido** (per semplicità $dV=0$):
$$
dU = mcdT \quad \quad \delta L_{\text{rev}}=0
$$

sostituendo alla $1$:
$$
\begin{align}
S(B)-S(A)&=\int^{B}_{A}\frac{{dU + \cancel{ \delta L_{\text{rev}} }}}{T} \\
S(B)-S(A)&=\int^{B}_{A}\frac{{mcdT }}{T} \\
&=mc \log \frac{T_{B}}{T_{A}}
\end{align}
$$

dato una generico $T$:
$$
S(T)=mc\log T + \text{costante}
$$


- durante uno **scambio termico**:
assumendo che $m_{1}=m_{2}=m$ e $c_{1}=c_{2}=c$

$$
\Delta S_{1}=mc \log \frac{T_{eq}}{T_{1}} \quad \quad \Delta S_{2}=mc \log \frac{T_{eq}}{T_{2}}
$$

sapendo che $T_{eq}=\frac{T_{1}+T_{2}}{2}$:
$$
\begin{align}
\Delta S_{tot}&=\Delta S_{1}+\Delta S_{2} \\
&=mc \log \frac{T_{eq}}{T_{1}}+mc \log \frac{T_{eq}}{T_{2}} \\
&=mc \log \frac{\frac{T_{1}+T_{2}}{2}}{T_{1}}+mc \log \frac{\frac{T_{1}+T_{2}}{2}}{T_{2}} \\
&=mc \log \underbrace{ \frac{(T_{1}+T_{2})^2}{4T_{1}T_{2}} }_{ \geq 1 } \geq 0 & [\text{prop. log}]
\end{align}
$$


- per un **gas perfetto**:
$$
dU = nC_{v}dT \quad \quad \delta L_{\text{rev}}=PdV=\frac{nRT}{V}dV
$$

$$
\begin{align}
S(B)-S(A)&=\int^{B}_{A}dT \frac{nC_{V}}{T}+\int^{B}_{A}dV \frac{nR}{V} \\
&=nC_{V}\log \frac{T_{B}}{T_{A}}+nR\log \frac{V_{B}}{V_{A}}
\end{align}
$$

data una $T$ generica:
$$
S(T)=nC_{V}\log T+nR\log V + \text{costante}
$$

per calcolare la variazione di entropia (assumendo che la temperatura sia costante e la trasformazione non è quasi-statica):
$$
\Delta S=nR\log \frac{V_{B}}{V_{A}}
$$

#### 8.10.2.6 probabilità termodinamica
è più corretto legare l'entropia alla probabilità termodinamica.

Equazione di Boltzman (valida solo nei sistemi isolati):
$$
S=k_{B}\log W
$$
- $W$: probabilità termodinamica. misura il numero di modi, a livello microscopico (microstati), in cui uno stato macroscopico (macrostato) può essere realizzato.

ex: modi in cui può uscire il numero 2 lanciando un dado
![[Pasted image 20241221155958.png]]


Il **secondo principio della termodinamica** sarà quindi:
> Le trasformazioni spontanee sono quelle che comportano un aumento della probabilità termodinamica.

**Equazione di Gibbs** (valida anche in sistemi non isolati):
$$
S=-k_{B}\sum^{W}_{i=1}p_{i}\log p_{i}
$$
- $p_{i}$: prob. del singolo macrostato

![[Pasted image 20241221160458.png]]


#### 8.10.2.7 nei buchi neri
Corpo celeste con campo gravitazionale molto intenso, così intenso che la sua velocità di fuga è superiore alla velocità della luce. si forma per collasso gravitazionale di stelle massicce.

![[Pasted image 20241221160840.png]]
![[Pasted image 20241221160856.png]]
![[Pasted image 20241221160949.png]]

In genere la temperatura dei buchi neri astronomici è molto piccola, ma a lungo andare la radiazione causa la loro evaporazione.

![[Pasted image 20241221161039.png]]

### 8.10.3 Terzo principio della termodinamica: irraggiungibilità dello zero assoluto
![[Pasted image 20241221161351.png]]

![[Pasted image 20241221161559.png]]
![[Pasted image 20241221161619.png]]
![[Pasted image 20241221162118.png]]


# 9 Onde
Modo di trasmettere (far propagare) energia senza un trasferimento di materia.

ex: Onde sulla superficie libera dell’acqua provocate da una perturbazione (fanno muovere solo in verticale)
- le molecole di acqua oscillano intorno alle proprie posizioni di equilibrio, per cui alla propagazione del massimo, cui corrisponde la propagazione dell’energia, non corrisponde un trasferimento di materia

Tipo di onde:
- **trasversali**: Le vibrazioni sono perpendicolari alla direzione di propagazione dell’onda (ex: sismiche ad S, corda tesa, elettromagnetiche)
	- ![[Pasted image 20241222140906.png]]
- **longitudinali**: Le vibrazioni sono concordi alla direzione di propagazione dell’onda (sismiche a P, acustiche)
	- ![[Pasted image 20241222140940.png]]


## 9.1 Onde sinusoidali
![[Pasted image 20241222141011.png]]
- $\lambda$: lunghezza d'onda (periodo spaziale dell'onda)
	- ![[Pasted image 20241222141127.png|500]]
- $T$: Periodo dell'onda (periodo temporale)
	- ![[Pasted image 20241222141139.png|500]]


velocità di propagazione:
$$
c = \frac{\lambda}{T}
$$

## 9.2 Onde di pressione
Suono: Onde di pressione generate dalle oscillazioni delle particelle del mezzo attorno alle loro posizioni di equilibrio

### 9.2.1 equazione

**VEDI SLIDE DI RUGGIERI (>>)**

Ipotesi: l'onda si sposta verso un'unica direzione.

Considerando un volume di area $A$ e uno spessore $dx$
![[Pasted image 20241222155122.png|500]]

A seguito del passaggio dell'onda questo volume può subire un'espansione o decompressione.
Quindi il suo spessore passa da $dx$ a $dx + d\xi$

Avremo una variazione di pressione:
$$
dP = \frac{\partial P}{\partial x}dx \quad [Axx]
$$

Ora ricordiamo che nei gas perfetti la pressione:
$$
\begin{align}
P &= \frac{F}{A} \\ \\
F&= PA
\end{align}
$$
per passare al prossimo passaggio ci sono due strade:
- def chat:
	- ![[Pasted image 20241222160203.png]]
- def prof:
	- metti la formula della prima riga dicendo "in quanto $F \propto - \frac{\partial P}{\partial x}$, la forza sarà opposta al gradiente della pressione"

ricapitolando, avendo quindi una variazione infinitesima avremo:
$$
\begin{align} \\
dF &=-AdP \\ \\
&=-A\frac{\partial P}{\partial x} dx \\
\\
&=-dV\frac{\partial P}{\partial x} \\ \\

\end{align}
$$
piccolo assiomino:
$$
\frac{\partial P}{\partial x} =(\frac{\partial P}{\partial \rho} )\frac{\partial P}{\partial x} 
$$

sostituendo $\frac{\partial P}{\partial x}$:
$$
\begin{align}
dF &= -dV(\frac{\partial P}{\partial \rho} )\frac{\partial P}{\partial x} & [1]
\end{align}
$$

lasciamo l'equazione 1 da parte, la useremo dopo.

Noi sappiamo che
$$
F = m \cdot a
$$

data una massa infinitesima avremo:
$$
dF = dm \cdot a
$$

per il passaggio dell'onda avremo uno spostamento:
$$
\begin{align}
dF &= dm \cdot \frac{\partial^2 \xi}{\partial t^2} & [2]
\end{align}
$$

eguagliamo le equazioni 1 e 2:
$$
\begin{align}
\underbrace{ -dV\left( \frac{\partial P}{\partial \rho}  \right)\frac{\partial P}{\partial x} }_{ 1 } &= \underbrace{ dm \cdot \frac{\partial^2 \xi}{\partial t^2} }_{ 2 } \\
 \\
-\cancel{ dV } \left( \frac{dP}{\partial \rho} \right) \frac{\partial P}{dx}&= \rho_{0}\cancel{ dV }\frac{\partial^2 \xi}{\partial t^2}  & [\text{DEF densità: }dm = \rho dV]
\end{align}
$$

$\rho_{0}$: densità a tempo $0$

vogliamo calcolare $\frac{\partial P}{\partial x}$.
Nonostante l'onda passi e il volume si espande / comprime, la massa non cambia:
$$
\text{massa}_{\text{prima}} = \text{massa}_{\text{dopo}}
$$

quindi:
$$
\begin{align} 
dm &= \rho_{0}dV \\  \\

&\underbrace{ \rho \cancel{ A } (dx + d \xi) }_{ \text{massa}_{\text{dopo}} } = \underbrace{ \rho_{0}\cancel{ A } dx }_{ \text{massa}_{\text{prima}} } \\
 \\
& \rho_{0} dx = \rho (dx + d\xi) \\
 \\
& \rho_{0}= \rho\left( 1 + \frac{d \xi}{dx} \right) \\
 \\
& \rho = \rho_{0} \frac{1}{1 + \frac{d \xi}{dx}} \\
 \\
& \rho \approx \rho_{0} \left( 1 - \frac{d\xi}{dx} \right) & \left[\text{con x piccolo: } \frac{1}{1+x} \approx 1-x \right] \\
 \\
\end{align}
$$


assiomaticando:
$$
\begin{align}
\frac{\partial \rho}{dx}&= - \rho_{0}\frac{\partial^2\xi}{dx^2} \\
 \\
-\frac{dP}{d\rho}-\cancel{ \rho_{0} }\frac{\partial^2\xi}{\partial x^2}&=\cancel{ \rho_{0} }\frac{\partial^2\xi}{\partial t^2} \\
 \\
\frac{dP}{d\rho}\frac{\partial^2\xi}{\partial x^2}-\frac{\partial^2\xi}{\partial t^2}&=0
\end{align}
$$

in quanto
$$
c^2=\frac{dP}{d\rho}
$$

concludiamo:
$$
c^2\frac{\partial^2\xi}{\partial x^2}-\frac{\partial^2\xi}{\partial t^2}=0
$$
che è soddisfatto solo per $c=\frac{\lambda}{T}$

## 9.3 Intensità
Energia per unità di superficie e di tempo trasportata da un’onda ($\frac{J}{m^2s}$)

## 9.4 Diffrazione
La diffrazione è importante quando l’ostacolo attraversato dall’onda ha dimensioni comparabili con la lunghezza d’onda
![[Pasted image 20241222164558.png]]

# 10 Meccanica Quantistica

> [!quote] *non si capisce un cazzo*

Più alta è la temperatura di un sistema, più alta è la frequenza della radiazione termica del sistema.

A noi interessa studiare il corpo nero.

Corpo nero:
- corpo in grado di assorbire tutte le radiazioni incidenti. Di qualunque lunghezza d'onda siano
- emette radiazione elettromagnetica
- c'è un equilibrio radiazione emessa/assorbita degli atomi

Ex approssimando: il sole

La radiazione del corpo dipende solo dalla temperatura

Riproduzione sperimentale:
- cavità a temperatura costante (forno)
- gli atomi all'interno emettono/assorbono radiazioni elettromagnetiche
- ci sarà un foro dove le radiazioni potranno uscire

in questo modo possiamo studiare e capire la relazione tra frequenza e intensità elettromagnetica (potere emissivo)
![[Pasted image 20250207174033 1.png|700]]

$\epsilon$: energia emessa tramite radiazione elettromagnetica dal corpo nero, per unità di tempo, unità di area e unità di lunghezza d’onda/frequenza
![[Pasted image 20250207174739 1.png]]

Secondo la fisica classica vige il **principio di equipartizione dell'energia**: l'energia totale di un sistema termodinamico si distribuisce equamente tra i suoi diversi gradi di libertà a temperatura termica di equilibrio.
![[Pasted image 20250207175822 1.png]] ^6a5f47

Arrivando ai seguenti risultati che:
- Wien:  
	- ![[Pasted image 20250207174218 1.png]]
- Boltzmann:
	- ![[Pasted image 20250207180143 1.png]]

Applicando la fisica classica si ottenevano risultati che non avevano un applicazione teorica

![[Pasted image 20250207180649 1.png]]
- Viene descritto solo l'andamento per grandi lunghezze d'onda
- Per basse lunghezze d'onda si ottiene intensità infinita (catastrofe ultravioletta)

Plank ipotizzò che l’energia di ogni modo dipende da $n$ ed è quantizzata: $h \nu,2h\nu, \dots ,Nh\nu, \dots$
Ottenendo:
![[Pasted image 20250207183510 1.png]]
![[Pasted image 20250207183647 1.png| 500]]

che è in disaccordo con la [[#^6a5f47|fisica classica]]

NB: con $h\to 0$ l'energia tende a quella prevista dalla fisica classica
![[Pasted image 20250207183619 1.png]]


![[Pasted image 20250207181253 1.png]]

## 10.1 Modelli

### 10.1.1 Thomson - modello panettone
l'atomo è costituito da una distribuzione di carica positiva diffusa all'interno della quale sono inserite le cariche negative. Nel complesso l'atomo è elettricamente neutro.

Si è dimostrato falso attraversando l'atomo con delle particelle α / raggi α.
Se la carica positiva fosse stata diffusa cioè distribuita uniformemente su tutto il volume atomico, le particelle α sarebbero dovute rimbalzare in numero molto maggiore.
### 10.1.2 Rutherford
La carica positiva dell’atomo è concentrata nel nucleo, mentre quella negativa è trasportata dagli elettroni che orbitano intorno al nucleo. Le dimensioni delle orbite elettroniche sono molto più grandi di quelle del nucleo.

![[Pasted image 20250208155014.png]]

Elettroni in orbita - radiazione elettromagnetica:
- Gli elettroni dovrebbero perdere costantemente energia, cedendola sotto forma di radiazione elettromagnetica. Questo modello atomico non spiega la stabilità degli atomi osservati in natura.

Rutherford non spiega perché le righe discrete degli spettri di emissione e assorbimento, misurate negli esperimenti.
![[Pasted image 20250208155220.png]]

### 10.1.3 Bohr
I livelli energetici dell’elettrone sono quantizzati.
Gli elettroni, anche se in orbita intorno al nucleo, possono solo cedere/assorbire quantità finite di energia: quanti.

Esiste uno stato con energia più bassa: stato fondamentale.
- L’elettrone nello stato fondamentale non può cedere energia perché non ci sono stati occupabili con energia più bassa.

>[!quote] Quindi, in questo modello l’atomo di idrogeno è stabile.

![[Pasted image 20250208155429.png]]


#### 10.1.3.1 onda de broglie
Ad ogni particella di massa m, che si muove con velocità v, è associata un’onda, la cui lunghezza d’onda, $\lambda$, è data da:
$$
\lambda=\frac{h}{mv}
$$

Per i corpi macroscopici, $\lambda$ è molto più piccola delle dimensioni dei corpi, per cui è trascurabile.
Per l’elettrone, $\lambda$ è dell’ordine delle dimensioni dell’atomo, per cui non è trascurabile.

Nell’ interpretazione moderna, l’onda di de Broglie è intesa come un’onda di probabilità.
- Così come le onde sono soggette ai fenomeni di interferenza, anche le onde di de Broglie associate alle particelle possono sperimentare interferenza, così come altri fenomeni tipici della propagazione per onde.

Abbandoniamo una descrizione particellare-deterministica delle particelle, sostituendola con una ondulatoria-probabilistica

Invece della traiettoria di una particella, introduciamo una funzione $\psi$, che chiamiamo funzione d’onda.
Rappresenta l’ampiezza di probabilità $P$, che la particella si trovi in $x$ al tempo $t$.

$$
\psi(x,t)
$$

Probabilità:
$$
P(x,y) = |\psi(x,t)|^2
$$



### 10.1.4 Esperimento due fenditure
- Caso sorgente è una pistola che spara proiettili macroscopici
![[Pasted image 20250208161949.png]]

le probabilità si sommano e otteniamo:
![[Pasted image 20250208162021.png]]

- Caso sorgente emette luce
![[Pasted image 20250208162740.png]]

avremo in aggiunta un termine di interferenza:
![[Pasted image 20250208162854.png]]

Gli elettroni negli esperimenti di doppia fenditura mostrano proprietà sia ondulatorie che corpuscolari.
Questo suggerisce che si possa parlare di dualismo onda-particella.

Al giorno d’oggi, il termine «dualismo onda-particella» ha più che altro un significato storico.

Sarebbe più opportuno affermare che le particelle elementari si comportano come «quantoni», descritti da funzioni d’onda che evolvono in accordo alle leggi della Meccanica Quantistica.
$$
\psi(x,t)
$$
Infatti, quando noi scriviamo la funzione d’onda di un sistema quantistico, non facciamo ipotesi sulla natura corpuscolare e/o ondulatoria del sistema stesso. Ci limitiamo a definire una funzione, y, la quale ci dà la probabilità che il sistema si trovi in una certa posizione ad un certo tempo.
$$
P(x,t)=|\psi(x,t)|^2
$$

## 10.2 Equazione di Schrodinger
Tutte le informazioni sullo stato del sistema sono contenute nella funzione d’onda, la cui dinamica è governata da un’equazione differenziale:
![[Pasted image 20250208164435.png]]

Con le opportune modifiche la si può paragonare all'equazione $F = m\cdot a$

Esiste una variante che risolve i problemi time-independent:
- risolvendo l'equazione di shrodinger stazionaria

## 10.3 Principio di heisenberg
Un sistema quantistico non possiede posizione e impulso (=mv) definiti con infinita precisione.

le incertezze su posizione e impulso soddisfano la relazione:
![[Pasted image 20250208165104.png]]

L’impossibilità di conoscere simultaneamente impulso e posizione non è legata al disturbo arrecato da processi di misura, ma alla natura intrinseca dello stato quantistico.

Ex: una particella con velocità definita ($\Delta p$ basso) non sapremo la posizione ($\Delta x$ alto)

Si dice particella delocalizzata quando la probabilità di trovarla nello spazio è costante:
$$
|\psi(x)|^2 = |C|^2
$$

## 10.4 Sovrapposizione di stati
Così come le onde sono soggette a sovrapposizione e interferenza, anche gli stati quantistici possono sovrapporsi e interferire.

![[Pasted image 20250208170122.png]]

	La stato-sovrapposizione non ha un valore definito della velocità, nonostante sia composto da stati con velocità definita.

![[Pasted image 20250208170338.png]]

## 10.5 Qubit
![[Pasted image 20250208170524.png]]

## 10.6 Effetto tunnel
La possibilità di accedere a regioni classicamente proibite.

In meccanica quantistica potrebbe capitare che l'energia potenziale superi quella totale.

Fissata $\omega$, ed essendo l'energia quantizzata:
![[Pasted image 20250208171822.png]]

potrebbe accadere che l'energia potenziale della particella superi quella totale, superando il turning point.
- nella meccanica classica non potrebbe accadere in quanto vi arriva con velocità nulla

Gli stati quantistici sono caratterizzati da:
- Indeterminismo intrinseco: Gli stati non hanno velocità e posizione determinati come in Meccanica Classica.
- Indistiguibilità delle particelle identiche
- Spin
- Bosoni-Fermioni

![[Pasted image 20250208172431.png]]


