## intro
>[!important] perdita aggiornamento
>![[Pasted image 20240118160329.png]]

>[!important] lettura sporca
>![[Pasted image 20240118160350.png]]

>[!important] lettura incosistenti
>![[Pasted image 20240118160403.png]]

>[!important] aggiornamento fantasma
>assumento ci sia un vincolo $y+z=1000$
>![[Pasted image 20240118160422.png]]
>- adesso $s=1000$

>[!important] inserimento fantasma
>![[Pasted image 20240118160811.png]]

## glossario

### schedule
>[!important] notazione schedule
>r: operazione di read
>w: operazione di write
>
>$r_{i}(o)/w_{i }(o)$ indica la lettura/scrittura della i-esima transazione dell'oggetto o
>

>[!info] scheduler
sistema che accetta o rifiuta le operazioni richieste dalle transazioni

>[!info] schedule seriale
>le transazioni sono separate, non si sovrappongo sui dati
> - Schedule: r0(x) r0(y) w0(x) r1(y) r1(x) w1(y) r2(x) r2(y) r2(z) w2(z)

>[!info] schedule serializzabile
>produce lo stesso risultato di uno schedule seriale, date le stesse transazioni
### legge da / scrittura finale
>[!info] legge da 
$r_{i}(x)$ legge da $w_j(x)$ in uno schedule S se $w_j$ lo precede e non è presente un'altra lettura di x in mezzo

>[!info] scrittura finale
>$w_{i}(x)$ è una scrittura finale se è l'ultima scrittura dell'oggetto x in S
### VSR
>[!info] view equivalenti
> date due schedule $S_{i}\,, S_{j}$, si dicono view-equivalenti se:
> - hanno la stessa relazione legge da
> - hanno le stesse scritture finali
>   
> due schedule view equivalenti si indicano con $S_{i}\approx_{V}S_{j}$

>[!important] VSR
>uno schedule è view serializzabile se è view-equivalente ad uno schedule seriale
>
>l'insieme degli schedule view-serializzabili è indiciato con **VSR**

### CSR
>[!info] azioni in conflitto
>$a_{i}$ è conflitto $a_j$ ($i\neq j$)se operano sullo stesso dato e si trovano in uno dei due casi:
>- read-write
>- write-write
>  
> due schedule conflict equivalenti si indicano con $S_{i}\approx_{C}S_{j}$

>[!important] CSR
>l'insieme degli schedule conflict serializzabili è indicato con CSR
>- conflict serializable: conflitto equivalente ad uno schedule seriale
>- conflict equivalente: due schedule che includono stesse operazioni e ogni coppia di operazioni in conflitto compare nello stesso ordine

>[!attention] attensionpls
>ogni schedule CSR è anche VSR.
>non vale il viceversa

## verifica conflict-serializzabilità "CSR"
>[!quote] teorema verifica CSR
>Uno schedule è in CSR se e solo se il grafo dei conflitti è aciclico

>[!info] grafo dei conflitti
> - un nodo per ogni transazioni $t_{i}$
> - un arco orientato da $t_{i}\to t_{j}$ se è presente un conflitto tra un azione $a_i$ ed una $a_j$ con $a_i$ che precede $a_j$

>[!attention] come vedere se è aciclico
>1. ad occhio
>2. cutello alg:
>se tutti i nodi hanno il "grado entrata e uscita > 0" possiede un ciclo.
>se sono presenti dei nodi con il "grado entrata o uscita = 0" si eliminano iterativamente e si verifica se il sottografo ottenuto ha cicli. se si arriva ad avere solo un nodo il grafo è **aciclico**

in pratica non si usa mai questa tecnica ma si usano i "lock" (btw serve per gli esercizi kek)

### Lock e 2PL
lock manager gestisce tutti i lock (accetta/rifiuta)

>[!attention] attensionpls
>quando una transazione richiede un operazione sull'oggetto si attivano i seguenti flag:
>- r_lock: richiesta lettura
>- w_lock: richiesta scrittura 

2PL "2 phase lock": lock manager che usiamo

si basa sulla seguente tabella:
![[Pasted image 20240121174122.png]]
in base alla richiesta effettuata corrisponde un esito e uno stato successivo, a seconda dello stato in cui si trova (libera, r_lock, w_lock)

>[!attention] attensionpls
> - NO = attesa rispetto alla transazione che detiene il lock
> - lo stato dipende è dato dal fatto che potrebbero esserci altre transazione che richiederanno il lock

## esercizi

### verifica CSR / VSR
> [!question] domanda
> dato il seguente schedule:
>  r1(x)r1(y)r2(y)r3(y)w2(x)r1(z)w2(z)w1(y)r1(z)w3(y)
> stabilire se è CSR o VSR.
#### verifica CSR:
> [!info] passaggi
> 
> 
> | attributo | operazioni |
> | ---- | ---- |
> | x | r1,w2 |
> | y | r1,r2,r3,w1,w2,w3 |
> | z | r1,w2,r1 |
> ```mermaid
> stateDiagram-v2
> 
>         t1 --> t2
>         t1 --> t3
> 
> 		t2 --> t3
> 		t2 --> t1
> 		
> 		t3 --> t1
> ```
> sono presenti dei cicli quindi non è CSR.

>[!attention] attensionpls
>nel caso sia CSR è anche VSR

#### verifica VSR
>[!info] passaggi
> 1. per ogni lettere segnamo le scritture finali
> 
> | lettera | scrittura finale |
> | ---- | ---- |
> | x | w2 (x)|
> | y | w3 (y)|
> | z | w2 (z)|
> 
> 2. scriviamo i [[transazioni#legge da / scrittura finale | legge da]]: r1(x)r1(y)r2(y)r3(y)w2(x)r1(z)<u>w2(z)</u>w1(y)<u>r1(z)</u>w3(y)
> - r1(z) legge da w2(z)
> 
> 3. per ogni transazione scriviamo le operazioni che fanno:
> 
> | transazione | operazioni |
> | ---- | ---- |
> | t1 | r1(x), r1(y),r1(z),w1(y),r1(z) |
> | t2 | r2(y)w2(x)w2(z) |
> | t3 | r3(y)w3(y) |
>  
> 4. in base alle scritture finali e le operazioni che fanno le varie transazioni, scrivo l'ordine in cui mettere le transazioni. In modo tale da non avere conflitti:
> - X: oltre alla transazione 2 (scrittura finale di X) nessuno scrive su X quindi non ci sono problemi
> - Y: oltre alla transazione 3 (finale), la transazione 1 ci scrive. quindi la **t3 dovrà essere dopo la t1**
> - Z: non ci sono problemi
> 
> quindi l'ordine sarà: t1,t2,t3 oppure t2,t1,t3 (sono equivalenti basta che t3 sta dopo t1)
> 
> 5. ora scrivo tutte le operazioni con l'ordine appena deciso:
> t1,t2,t3 = r1(x)r1(y)r1(z)w1(y)r1(z)r2(y)w2(x)w2(z)r3(y)w3(y)
> 
> 
> 6. riscriviamo i legge da, se corrispondono a quelli iniziali, lo schedule è VSR
> 
> legge da: r1(x)r1(y)r1(z)**w1(y)** r1(z)r2(y)**w2(x)** **w2(z)** r3(y)**w3(y)**
> - r2(y) legge da w1(y)
> - r3(y) legge da w1(y)
>   
>   non corrispondono quindi non è VSR

### 2PL deadlock e attese

#### caso deadlock
> [!question] domanda
> dato il seguente schedule:
> r1(x)r1(y)r2(y)r3(y)w2(x)r1(z)w2(z)w1(y)r1(z)w3(y)
> Se passato ad uno scheduler 2PL ci saranno transazioni che vanno in attesa? Se si elencare quali e motivare la risposta.

##### soluzione
disporre la seguente tabella e ad ogni passo aggiornala in base alla transazione:

| lettera | r_lock | w_lock |
| ---- | ---- | ---- |
| x |  |  |
| y |  |  |
| z |  |  |

1. r1(x)
<u>r1(x)</u>r1(y)r2(y)r3(y)w2(x)r1(z)w2(z)w1(y)r1(z)w3(y)

| lettera | r_lock | w_lock |
| ---- | ---- | ---- |
| x | T1 |  |
| y |  |  |
| z |  |  |
non ci sono conflitti, si procede

2. r1(y)

r1(x)<u>r1(y)</u>r2(y)r3(y)w2(x)r1(z)w2(z)w1(y)r1(z)w3(y)

| lettera | r_lock | w_lock |
| ---- | ---- | ---- |
| x | T1 |  |
| y | T1 |  |
| z |  |  |

3. r2(y)
r1(x)r1(y)<u>r2(y)</u>r3(y)w2(x)r1(z)w2(z)w1(y)r1(z)w3(y)

| lettera | r_lock | w_lock |
| ---- | ---- | ---- |
| x | T1 |  |
| y | T1,T2 |  |
| z |  |  |
la lettura dello stesso oggetto non crea problemi, si genera un **lock_condiviso**

4. r3(y)
r1(x)r1(y)r2(y)<u>r3(y)</u>w2(x)r1(z)w2(z)w1(y)r1(z)w3(y)

| lettera | r_lock | w_lock |
| ---- | ---- | ---- |
| x | T1 |  |
| y | T1,T2,T3 |  |
| z |  |  |


5. w2(x)
r1(x)r1(y)r2(y)r3(y)<u>w2(x)</u>r1(z)w2(z)w1(y)r1(z)w3(y)

| lettera | r_lock | w_lock |
| ---- | ---- | ---- |
| x | T1 | **T2** |
| y | T1,T2,T3 |  |
| z |  |  |

**T2 va in attesa di T1 in quanto richiede una scrittura su X ma occupata da un lock_condiviso.**

Verrano bloccate tutte le operazioni di T2
- A sopra: azione che ha scatenato il blocco
- A sotto: azioni bloccate

```
                     A2
r1(x)r1(y)r2(y)r3(y)w2(x)r1(z)w2(z)w1(y)r1(z)w3(y)
                               A2
```
le azioni rimarrano bloccate fino al commit di T1

6. r1(z)
```
                     A2
r1(x)r1(y)r2(y)r3(y)w2(x)r1(z)w2(z)w1(y)r1(z)w3(y)
                               A2
```

| lettera | r_lock | w_lock |
| ---- | ---- | ---- |
| x | T1 | **T2** |
| y | T1,T2,T3 |  |
| z | T1 |  |

7. w1(y)
```
                     A2             A1
r1(x)r1(y)r2(y)r3(y)w2(x)r1(z)w2(z)w1(y)r1(z)w3(y)
                              A2         A1
```

w2(z) si salta in quanto bloccata

| lettera | r_lock | w_lock |
| ---- | ---- | ---- |
| x | T1 | **T2** |
| y | T1,T2,T3 | T1 |
| z | T1 |  |

**T1 va in attesa in quanto vuole scrivere su Y ma è presenta un lock_condiviso con T2**


8. w3(y)
 ```
                     A2             A1        A3
r1(x)r1(y)r2(y)r3(y)w2(x)r1(z)w2(z)w1(y)r1(z)w3(y)
                               A2        A1
```

r1(z) si salta in quanto bloccata

| lettera | r_lock | w_lock |
| ---- | ---- | ---- |
| x | T1 | **T2** |
| y | T1,T2,T3 | **T1*, *T3** |
| z | T1 |  |

**T3 va in attesa in quanto vuole scrivere con Y ma è presente un lock_condiviso con T2**
in quanto le transazioni sono tutte bloccate e lo schedule è terminato (non mandando nessuno in commit) si genera un deadlock.

Conclusioni:
- T2 va in attesa di T1 in quanto richiede una scrittura su X ma occupata da un lock_condiviso.
- T1 va in attesa in quanto vuole scrivere su Y ma è presenta un lock_condiviso con T2
- T3 va in attesa in quanto vuole scrivere con Y ma è presente un lock_condiviso con T2
- si genera un deadlock 


### caso senza deadlock
> [!question] domanda
> dato il seguente schedule:
> r1(x)r2(y)w1(y)r3(y)w2(z)r1(z)w1(z)w3(y)r2(z)w3(y)
> Se passato ad uno scheduler 2PL ci saranno transazioni che vanno in attesa? Se si elencare quali e motivare la risposta.

#### soluzione

1. r1(x)
```

r1(x)r2(y)w1(y)r3(y)w2(z)r1(z)w1(z)w3(y)r2(z)w3(y)


^
```

|  | r_lock | w_lock |
| ---- | ---- | ---- |
| x | t1 |  |
| y |  |  |
| z |  |  |

2. r2(y)
```

r1(x)r2(y)w1(y)r3(y)w2(z)r1(z)w1(z)w3(y)r2(z)w3(y)

      ^
```

|  | r_lock | w_lock |
| ---- | ---- | ---- |
| x | t1 |  |
| y | t2 |  |
| z |  |  |

3. w1(y)
```
           a1
r1(x)r2(y)w1(y)r3(y)w2(z)r1(z)w1(z)w3(y)r2(z)w3(y)
                          a1   a1 
           ^
```

|  | r_lock | w_lock |
| ---- | ---- | ---- |
| x | t1 |  |
| y | t2 |  |
| z |  |  |

- t1 va in attesa di t2 in quanto è presente una r_lock su y


4. r3(y)
```
           a1
r1(x)r2(y)w1(y)r3(y)w2(z)r1(z)w1(z)w3(y)r2(z)w3(y)
                          a1   a1 
                ^
```

|  | r_lock | w_lock |
| ---- | ---- | ---- |
| x | t1 |  |
| y | t2,t3 |  |
| z |  |  |


4. w2(z)
```
           a1
r1(x)r2(y)w1(y)r3(y)w2(z)r1(z)w1(z)w3(y)r2(z)w3(y)
                          a1   a1 
                     ^
```

|  | r_lock | w_lock |
| ---- | ---- | ---- |
| x | t1 |  |
| y | t2,t3 |  |
| z |  | t2 |



5. w3(y)
```
           a1                       a3
r1(x)r2(y)w1(y)r3(y)w2(z)r1(z)w1(z)w3(y)r2(z)w3(y)
                          a1   a1             a3
                                     ^
```

|  | r_lock | w_lock |
| ---- | ---- | ---- |
| x | t1 |  |
| y | t2,t3 |  |
| z |  | t2 |

- t3 va in attesa di t2 in quanto è presente un r_lock su y

5. w3(y)
```
           a1                       a3
r1(x)r2(y)w1(y)r3(y)w2(z)r1(z)w1(z)w3(y)r2(z)w3(y)
                          a1   a1             a3
                                         ^
```

|  | r_lock | w_lock |
| ---- | ---- | ---- |
| x | t1 |  |
| y | t2,t3 |  |
| z |  | t2 |

- t2 va in commit rilasciando tutti i lock, di conseguenza t1 e t3 si svegliano

|  | r_lock | w_lock |
| ---- | ---- | ---- |
| x | t1 |  |
| y | t3 |  |
| z |  |  |


6. w1(y)

>[!attention] attensionpls
>anche se t3 è sveglio le operazioni devono essere eseguite in ordine cronologico. quindi si riparte dall'inizio.

```
a1
w1(y)r1(z)w1(z)w3(y)w3(y)
      a1   a1
^
```

|  | r_lock | w_lock |
| ---- | ---- | ---- |
| x | t1 |  |
| y | t3 |  |
| z |  |  |

- t1 va in attesa di t3 in quanto è presente un r_lock su y

7. w3(y)
```
a1
w1(y)r1(z)w1(z)w3(y)w3(y)
      a1   a1
                ^
```

|  | r_lock | w_lock |
| ---- | ---- | ---- |
| x | t1 |  |
| y |  | t3 |
| z |  |  |

- lock escalation di t3 su y


8. w3(y)
```
a1
w1(y)r1(z)w1(z)w3(y)w3(y)
      a1   a1
                     ^
```

|  | r_lock | w_lock |
| ---- | ---- | ---- |
| x | t1 |  |
| y |  |  |
| z |  |  |

- t3 va in commit, svegliando t1
9. w1(y),r1(z),w1(z)
```

w1(y)r1(z)w1(z)

^
```

- t1 va in commit


conclusioni:
- t1 va in attesa di t2 in quanto è presente una r_lock su y
- t3 va in attesa di t2 in quanto è presente un r_lock su y
- t2 va in commit rilasciando tutti i lock, di conseguenza t1 e t3 si svegliano
- t1 va in attesa di t3 in quanto è presente un r_lock su y
- t3 va in commit, svegliando t1
- t1 va in commit
- non ci sono deadlock





