---
number headings: auto, first-level 1, max 6, 1.1
---
# 1 mech
## 1.1 Modelli

### 1.1.1 Thomson - modello panettone
l'atomo è costituito da una distribuzione di carica positiva diffusa all'interno della quale sono inserite le cariche negative. Nel complesso l'atomo è elettricamente neutro.

Si è dimostrato falso attraversando l'atomo con delle particelle α / raggi α.
Se la carica positiva fosse stata diffusa cioè distribuita uniformemente su tutto il volume atomico, le particelle α sarebbero dovute rimbalzare in numero molto maggiore.
### 1.1.2 Rutherford
La carica positiva dell’atomo è concentrata nel nucleo, mentre quella negativa è trasportata dagli elettroni che orbitano intorno al nucleo. Le dimensioni delle orbite elettroniche sono molto più grandi di quelle del nucleo.

![[Pasted image 20250208155014.png]]

Elettroni in orbita - radiazione elettromagnetica:
- Gli elettroni dovrebbero perdere costantemente energia, cedendola sotto forma di radiazione elettromagnetica. Questo modello atomico non spiega la stabilità degli atomi osservati in natura.

Rutherford non spiega perché le righe discrete degli spettri di emissione e assorbimento, misurate negli esperimenti.
![[Pasted image 20250208155220.png]]

### 1.1.3 Bohr
I livelli energetici dell’elettrone sono quantizzati.
Gli elettroni, anche se in orbita intorno al nucleo, possono solo cedere/assorbire quantità finite di energia: quanti.

Esiste uno stato con energia più bassa: stato fondamentale.
- L’elettrone nello stato fondamentale non può cedere energia perché non ci sono stati occupabili con energia più bassa.

>[!quote] Quindi, in questo modello l’atomo di idrogeno è stabile.

![[Pasted image 20250208155429.png]]


#### 1.1.3.1 onda de broglie
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



### 1.1.4 Esperimento due fenditure
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

## 1.2 Equazione di Schrodinger
Tutte le informazioni sullo stato del sistema sono contenute nella funzione d’onda, la cui dinamica è governata da un’equazione differenziale:
![[Pasted image 20250208164435.png]]

Con le opportune modifiche la si può paragonare all'equazione $F = m\cdot a$

Esiste una variante che risolve i problemi time-independent:
- risolvendo l'equazione di shrodinger stazionaria

## 1.3 Principio di heisenberg
Un sistema quantistico non possiede posizione e impulso (=mv) definiti con infinita precisione.

le incertezze su posizione e impulso soddisfano la relazione:
![[Pasted image 20250208165104.png]]

L’impossibilità di conoscere simultaneamente impulso e posizione non è legata al disturbo arrecato da processi di misura, ma alla natura intrinseca dello stato quantistico.

Ex: una particella con velocità definita ($\Delta p$ basso) non sapremo la posizione ($\Delta x$ alto)

Si dice particella delocalizzata quando la probabilità di trovarla nello spazio è costante:
$$
|\psi(x)|^2 = |C|^2
$$

## 1.4 Sovrapposizione di stati
Così come le onde sono soggette a sovrapposizione e interferenza, anche gli stati quantistici possono sovrapporsi e interferire.

![[Pasted image 20250208170122.png]]

La stato-sovrapposizione non ha un valore definito della velocità, nonostante sia composto da stati con velocità definita.

![[Pasted image 20250208170338.png]]

## 1.5 Qubit
![[Pasted image 20250208170524.png]]

## 1.6 Effetto tunnell
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


