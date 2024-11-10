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
\overrightarrow{v}(t)=\lim_{ \Delta t \to 0 } =\frac{\overrightarrow{r}(\Delta t+t)-\overrightarrow{r}(t)}{\Delta t}=\lim_{ \Delta t \to 0 } \frac{\Delta \overrightarrow{r}}{\Delta t}
$$
### 1.1.1 moto rettilineo uniforme
Ipotesi:
1. velocità costante: $\overrightarrow{v}=\text{costante}$
2. x in funzione del tempo: $x=x(t)$
3. parta da $x_0$: $x(t = 0) = x_{0}$

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
2. x in funzione del tempo: $x=x(t)$
3. parta da $x_0$ : $x(t = 0) = x_{0}$
4. parte con una velocità $v_0$ : $v(t = 0) = v_{0}$

Tesi:
$$
\text{legge oraria: }x(t)=\frac{1}{2}a_{x}t^2+ v_{0} \cdot t + x_{0}
$$

Dimostrazione:
per definizione:
$$
a_{x}=\frac{d v_{x}}{dt}=\text{costante}=\frac{d^2x}{dt^2}
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
1. viene lanciato con angolo $\theta$
2. $x_{0} = 0$
3. $y_{0} = 0$
4. $a_{y}=-g=-9,81 \frac{m}{s^2}$

dobbiamo trovare la gittata $x_g$ massima
- Per gittata si intende la distanza in ricoperta dalla particella prima di toccare terra

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
DEF: La dinamica tratta infatti le relazioni fra il moto degli oggetti e le cause (dette forze) che tale moto determinano.

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
da vedere, esotico rn.
STILL ESOTICO

## 2.3 quantità di moto / impulso
Si dice impulso:
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

Sia la spostamento:
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
& = m \frac{d \overrightarrow{v}}{dt} d \overrightarrow{s} & \left[ \frac{d \overrightarrow{s}}{dt}=\overrightarrow{v} \right]\\ \\

& = m \cdot d \overrightarrow{v} \cdot \overrightarrow{v} & \left[ \overrightarrow{v} \cdot d\overrightarrow{v} = d\left( \frac{v^2}{2} \right)\right] \\ \\

& = d \underbrace{ \left( \frac{1}{2} mv^2 \right) }_{ K } = dK
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

## 3.1 Lavoro durante lo spostamento
Supponendo che m si sposta da un punto A ad un punto B (allontandosi da M con stessa direzione di $\overrightarrow{d}$ )
![[Pasted image 20241109130207.png|300]]
Si [[3anno/FISICA/lezioni/6.pdf|dimostra]]: (to fix)
$$
L_{AB} = \underbrace{ - \frac{Gmm}{d_{A}}+\frac{Gmm}{d_{B}}<0 }_{ d_{B} > d_{A} }
$$

supponendo $d_{B}\to \infty$, e che il lavoro, a meno di una costante nell'energia potenziale, non cambia:
$$
U_{A} = - \frac{GMm}{d_{A}}+\underbrace{ U_{\infty} }_{ \text{costante} }
$$

## 3.2 Energia meccanica di $m$
$$
E =\frac{1}{2}mv^2- \frac{GMm}{d}
$$
## 3.3 Cambiamento velocità in avvicinamento $m \to M$
$m$ si trova ad un distanza infinita, per poi avvicinarsi fino ad arrivare una distanza $d$.

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

## 3.4 Velocità di fuga
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

usando:
$$
\begin{align}
v_{1}^2 = v_{0}^2+ \frac{2GM}{d} \implies

v_{F}^2&=\frac{2GM}{R_{T}}\\
v_{F}&=\sqrt{ \frac{2GM}{R_{T}} }
\end{align}

$$

# 4 Forza elastica o richiamo
![[Pasted image 20241109171256.png|500]]
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
&= m \cdot \frac{d^2 x}{dt} \\
 \\
-Kx&= m \cdot \frac{d^2 x}{dt} \\
\end{align}
$$

da cui ricaviamo la seguente equazione differenziale lineare omogenea:
$$
\begin{align}
y''+ay&=0 \\ \\
\frac{d^2x}{dt^2}+\frac{k}{m}x&=0 & [1]
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
quando $x(t)=0$ non interessa.
a noi interessa risDall'esperienza sappiamo che la traiettoria percorsa dal filo, formerà un arco della circonferenza, di raggio $r = l$.olvere:
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
x(t)=x_{0} \cdot \cos\left( \sqrt{ \frac{K}{m} }\cdot t \right)
$$

### 4.1.1 Periodo
il moto della forza elastica è un moto periodico di tempo:
$$
\begin{align}
T &= \frac{2\pi}{\omega}
\end{align}
$$
![[Pasted image 20241109184938.png|500]]
## 4.2 Lavoro forza elastica
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
&= \left( \frac{1}{2}m\cdot \underbrace{ v^2 }_{ \frac{dx}{dt} } \right) + \left( \frac{1}{2}K\cdot\underbrace{ x^2 }_{ x(t) } \right) \\
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
Data una pallina dentro un cilindro che si muove verso il basso a causa della forza peso $\overrightarrow{P}$
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
v_{y} &= - \frac{mg}{\beta} \\
|v_{y}| &=  \frac{mg}{\beta}
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
 
\dots \text{esotico rn} \\
 \\
 -mg-\beta v_{y}&=mge^{-\frac{\beta t}{m}}
\end{align}
$$


l'accelerazione sarà:
$$
\overrightarrow{a}=g \cdot e^{-\frac{\beta t}{m}}
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
\implies& E_{fin} < E_{in}
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
	- Finché $\overrightarrow{F}_{max} \leq F_{A} \implies \overrightarrow{F}_{A} = -\overrightarrow{F}{a}$

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
\implies& E_{fin} < E_{in}
\end{align}
$$


# 6 Pendolo
Un oggetto puntiforme $P$ di massa $m$ è sospeso a un filo inestensibile, di massa trascurabile e flessibile di lunghezza $l$.
![[Pasted image 20241110123339.png|400]]
- $l$: lunghezza del filo inestensibile

Si scompongono le componenti delle forze.
Consideriamo il nostro piano:
- asse X: coincide con $l$
- asse Y: coincide con la circonferenza

Per studiare il moto si pongono le seguenti equazioni sulle due assi
- asse perpendicolare: $\tau - mg \cos \theta = 0 \implies \tau = mg \cos \theta$
	- Ponendo $\theta = 0$ possiamo semplificare: $\tau = mg$
- asse parallela: dall'esperienza sappiamo che la traiettoria percorsa dal filo, formerà un arco della circonferenza, di raggio $r = l$.
$$
\begin{align}
-mg \cdot \sin \theta &= ma \\
&= m\frac{d^{2}S}{dt^{2}} \\
&= m\cdot l \frac{d^{2}\theta}{dt^{2}}  &[s=l \cdot \theta] \\
-g \cdot \sin \theta &= l \frac{d^{2}\theta}{dt^{2}} \\
\frac{d^{2} \theta}{dt^{2}} + \frac{g}{l} \cdot sin \theta &= 0
\end{align}
$$


Risolvendo questa equazione trovata troviamo $\theta(t)$.
La risolveremo tramite una guess come nella [[#4.1 Equazione del moto|forza elastica]].

Si assume che $\theta_{0} \to 0$. Siccome $\sin \theta \approx \theta \quad [\lim_{ x \to 0} \frac{\sin x}{x}=1]$, si prova che:

$$
\theta(t) = \theta_{0} \cdot \cos (wt) \quad \text{con } w=\sqrt{\frac{g}{l}}
$$

Il periodo trovato è indipendente dalla massa e dall'angolo $\theta_{0}$ (sperimentalmente si nota che vale fino a $\theta_{0} \approx 10°$)

