---
number headings: auto, first-level 1, max 6, 1.1
---
# 1 Cinematica del punto materiale
si occupa di descrivere il moto degli oggetti, senza porsi il problema di collegare il moto alle cause che lo determinano.

DEF: **punto materiale**
un sistema fisico è schematizzabile come punto materiale (ovvero che esso si comporta come un punto materiale) se le sue dimensioni lineari sono piccole rispetto alla precisione con cui ci interessa determinarne la posizione.

ex: nave a largo

N.B.
dato un vettore $v$ ^58131f
$$
\begin{cases}
v_{x}=\cos \alpha \\
v_{y}=\sin \alpha
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
\overrightarrow{v}=\frac{\Delta \overrightarrow{r}}{dt}
$$
DEF: velocità istantanea
$$
\overrightarrow{v}(t)=\lim_{ \Delta t \to 0 } =\frac{\overrightarrow{r}(\Delta t+t)-\overrightarrow{r}(t)}{dt}=\lim_{ \Delta t \to 0 } \frac{\Delta \overrightarrow{r}}{\Delta t}
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
![[Pasted image 20241101171301.png| 500]]
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
5. 

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
$$sostituiamo nella $x(t)$
$$
\begin{align}
x_{g}=x(t =  \frac{2v_{0y}}{g})&=v_{0x} \cdot \frac{2v_{0y}}{g} + \underbrace{ x_{0} }_{ = 0 } \\
\end{align}
$$
[[#^58131f| dalla proprietà dei vettori]] e dalla seguente proprietà:
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

# dinamica
DEF: La dinamica tratta infatti le relazioni fra il moto degli oggetti e le cause (dette forze) che tale moto determinano.

## Principi
1. Un punto materiale libero se messo in quiete rimane in quiete
2. $\overrightarrow{F} = m \cdot \overrightarrow{a}$

## Forza peso
$\overrightarrow{P} = m_{g} \cdot \overrightarrow{g}=m \cdot \overrightarrow{a}$
$$
\overrightarrow{a}= \overrightarrow{g}\cdot\frac{m_{g}}{m}
$$
si osserva sperimentalmente che il rapporto $\frac{m_{g}}{m}$ è costante, altrimenti corpi diversi subirebbero accelerazioni differenti.

per semplicità assumiamo $\frac{m_{g}}{m}=1$, risulterà:
$$
\overrightarrow{a}=\overrightarrow{g}
$$

### legge oraria punto materiale su un piano
da vedere, esotico rn

## quantità di moto / impulso
Si dice impulso:
$$
\overrightarrow{p}= m \cdot \overrightarrow{v}
$$

### forza impulso
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
scriveremo quindi l'impulso come la variazione di quantità di moto:
$$
\begin{align}
\overrightarrow{I}&=\int_{t_{1}}^{t_{2}} d \overrightarrow{p}  \\
& = \overrightarrow{p}(t_{2})-\overrightarrow{p}(t_{1}) \\
& = \Delta \overrightarrow{p}
\end{align}
$$




## lavoro
### lavoro infinitesimo
Consideriamo dunque un punto materiale $P$ di massa $m$ che si muove in un sistema di riferimento inerziale, sottoposto a una forza $\overrightarrow{F}$

Sia la spostamento:
$$
d \overrightarrow{s} = \overrightarrow{r}(t + dt)- \overrightarrow{r}(t)
$$
- con $\overrightarrow{r}(t)$ vettore posizione

diremo lavoro elementare $dL$ relativo allo spostamento elementare $d \overrightarrow{s}$ :
$$
dL = \overrightarrow{F} \cdot d \overrightarrow{s}
$$

Unità di misura "joule": $[N \cdot m] = [j]$

### lavoro
dati due punti A e B, per calcolare il lavoro da A a B:
$$
L_{AB}=\int^{B}_{A}dL
$$

### energia cinetica: Teorema del lavoro
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
K = \frac{mv^2}{2}
$$

$$
\begin{align}
L_{AB}&= \int^{B}_{A}dL \\
&= \int^{B}_{A}dK  \\
&=K_{B} - K_{A} = \Delta K
\end{align}
$$

vale per qualunque tipo di forza


