---
type: university
date: 2025-01-17
subjectId: 3101
year: 3
semester: 1
---
#university #studying #subject-3101
### Formulario
> [!summary] Fisica

## Dinamica
### Costanti
- Accelerazione gravitazionale: $9,81 \frac{m}{s^{2}}9,81 \frac{m}{s^{2}}$
- Costante di gravitazione universale: $G = 6.66 \cdot 10^{-11} \cdot \frac{N \cdot m^2}{kg^2}$
- Velocità della luce: $c=$
- #todo
### Unità di misura
- km/h -> m/s
- c -> k
- #todo
### Formule
- Forza: $\overrightarrow{F} = m \cdot \overrightarrow{a}$
- Quantità di moto: $\overrightarrow{p}= m \cdot \overrightarrow{v}$
- Forza Impulso: $\overrightarrow{I} = \overrightarrow{p}(t_{2})-\overrightarrow{p}(t_{1})$
- Lavoro: $L_{AB}=\int^{B}_{A}dL = K_{B} - K_{A}$ (vale per ogni forza)
	- Se la forza è conservativa: $L_{AB} = U_{A} - U_{B} = - \Delta U$
- Energia cinetica: $\frac{1}{2} m v^{2}$ (vale sempre)
	- Energia potenziale:
	- $U = m \cdot g \cdot h$
	- $U = -\frac{GMm}{d}$
	- $U = \frac{1}{2}Kx^2$
- Energia totale:
	- $E = K + U$
	- Forza elastica: $E = K \cdot \frac{x_{0}^2}{2}$
- Forza conservativa: ${} E_{in} = E_{fin} {}$
- Potenza: $W = \frac{dL}{dt} = \overrightarrow{F} \cdot \overrightarrow{v}$
- Forza di attrazione con cui $m$ è attratto a $M$: $\overrightarrow{F_{12}} = - \frac{GMm}{d^2} \cdot \hat{d}$
- Cambiamento velocità in $m$ (da $\infty$) verso $M$: $v_{1}^2 = v_{0}^2+ \frac{2GM}{d}$
- Velocità di Fuga: $v_{F}=\sqrt{ \frac{2GM}{R_{T}} }$
- Forza elastica: $\overrightarrow{F}=-K \cdot \overrightarrow{x}$
- Equazione della molla:
	- Guess: $x(t)=A \cdot \cos(\omega t + \phi)$
	- $x(t)=x_{0} \cdot \cos\left( \sqrt{ \frac{K}{m} }\cdot t \right)$
	- Periodo: $T = \frac{2\pi}{\omega}$
- Forza viscosa: $\overrightarrow{f_{v}} = -\beta \overrightarrow{v}$
	- Velocità:
		- con dimostrazione: $v_{y} = \frac{mg}{\beta} \quad\text{ per } t \to \infty$
		- in generale: $v_{y}(t)=\frac{mg}{\beta}\cdot \left( e^{- \frac{\beta t}{m}}-1 \right)$
	- Accelerazione: $\overrightarrow{a}=g \cdot e^{-\frac{\beta t}{m}}$
- Attrito:
	- forza di attrito massima che fa spostare il corpo: $F_{max} = \mu_{s} N$
	- forza di attrito: $\overrightarrow{F}_{a}=- \mu_{c} \cdot N \cdot \hat{v}$
- Moto piano inclinato: $a = g(\sin \theta - \mu_{c}\cos \theta)$
- Moto pendolo: $\theta(t) = \theta_{0} \cdot \cos (wt) \quad \text{con } w=\sqrt{\frac{g}{l}}$ ($\theta_{0} \to 0$)
- Urto elastico: se vale  $$
\begin{cases}
\overrightarrow{P}_{in} = \overrightarrow{P}_{fin} & \text{[qnt. moto]} \\
K_{in} = K_{fin}
\end{cases}
$$
- Urto anelastico: se vale $$\overrightarrow{P}_{in} = \overrightarrow{P}_{fin}$$
## Termodinamica
- Trasformazioni termodinamiche:
	- isocora (volume costante):
		- $P=P_{0}(1+\alpha \cdot T(°C))$
		- $P=P_{0}\frac{T}{T_{0}}$
	- isobara (pressione costante):
		- $V=V_{0}(1+\alpha \cdot T(°C))$
		- $V=V_{0}\frac{T}{T_{0}}$
	- isoterma (temperature costante):
		- $PV = P_{0}V_{0}$
- Equazione di stato: $\frac{P_{0}V_{0}}{T_{0}}=\frac{PV}{T}$
	- $\frac{PV}{T}=n \cdot R$ è costante
	- $R = 8.314 \cdot \frac{J}{mol \cdot K}$: costante universale gas perfetti.
- Numero totale di atomi: $N_{tot}= n \cdot N_{A}$
	- Numero di Avogadro: $N_{A}= 6.022 \cdot 10^{23}$
- Energia cinetica media: $\langle K\rangle = \frac{K_{tot}}{n \cdot N_{A}}$
- Relazione tra energia cinetica e temperatura: $T = \frac{2}{3k_{b}}\langle K\rangle$
	- Costante di Boltzman: $k_{B}=\frac{R}{N_{A}} \approx 1.38 \cdot 10^{-23} \frac{J}{K}$
- Calore:
	- Quantità di calore scambiato:
		- con calore specifico: $\delta Q = m \cdot c(T) \cdot dT$
		- con calore molare: $\delta Q = n \cdot C(T) \cdot dT$
			- $C \approx 3R$
	- Trasferimento da temperatura $T_{1}$ a $T_{2}$: $Q = mc(T_{2}-T_{1})=nC(T_{2}-T_{1})$
- Temperatura di Equilibrio: $T_{eq}=\frac{m_{1}c_{1}T_{1}+m_{2}c_{2}T_{2}}{m_{1}c_{1}+m_{2}c_{2}}$
- Lavoro di espansione: $\delta L = PdV$
- Rapporto tra lavoro e calore: $\frac{L}{Q} = J = 4.186 \, \frac{Joule}{cal}$
- Energia interna: $U=U(P,V,T)$
- Primo Principio della Termodinamica: $Q - L = U(B)-U(A)$
- Altre trasformazioni:
	- adiabatica:
		- $Q = 0$
		- $-L = U(B)-U(A)$
	- isocora:
		- $L=0$
		- $Q = U(B)-U(A)$
- Energia interna: 
	- nel corpo solido: $U(T)=mcT+\text{costante}$
	- nel gas: ${} U(T)=nC_{v}T+\text{costante}$
		- $U = U(T)$
- Equazione calore molare: $C_{p} = C_{v}+R$
	- Calore molare a pressione costante: $C_{p}$
	- Calore molare a volume costante: $C_{v}$
- Ciclo di Carnot:  $Q=L = |Q_{c}|-|Q_{f}|$
	- Rendimento $\eta=1-\frac{|Q_{f}|}{|Q_{c}|}$
- Disuguaglianza di Clausius: $\oint \frac{\delta Q}{T} \leq 0$
- Entropia
	- $\Delta S_{\text{Sist. isolato}}\geq 0$
	- nel corpo solido: $S(T)=mc\log T + \text{costante}$
	- in un gas perfetto: $S(T)=nC_{V}\log T+nR\log V + \text{costante}$
- Equazione di Boltzman: $S=k_{B}\log W$
	- $W$: probabilità termodinamica
- Equazione di Gibbs: $S=-k_{B}\sum^{W}_{i=1}p_{i}\log p_{i}$
	- $p_{i}$: probabilità del singolo macrostato
- Entropia del buco nero: $S_{\text{buco nero}} = \frac{A}{4}$
	- $A$: area del buco nero
