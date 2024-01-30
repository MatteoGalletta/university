> [!hint] attensions
> begin: B(T)
> insert: I(T,O,AS)
> delete: D(T,O,BS)
> update: U(T,O,BS,AS)
> commit: C(T)
> abort: A(T)
> 
> - T: transazione
> - O: oggetto da manipolare
> - BS: before state (stato db prima dell'operazione)
> - AS: after state (stato db dopo)

> [!attention] domanda
> dato il seguente log
> ```
> B(T1)
> B(T2)
> U(T2, O1, B1, A1)
> I(T1, O2, A2)
> B(T3)
> C(T1)
> B(T4)
> U(T3,O2,B3,A3)
> U(T4,O3,B4,A4)
> CK(T2,T3,T4)
> C(T4)
> B(T5)
> U(T3,O3,B5,A5)
> U(T5,O4,B6,A6)
> D(T3,O5,B7)
> A(T3)
> C(T5)
> I(T2,O6,A8)
> ```
> scrivere le operazioni effettuate in seguito ad un interrupt con il metodo di ripresa a caldo

## soluzione
1. si parte dall'interrupt e si sale fino al primo checkpoint
```
B(T1)
B(T2)
U(T2, O1, B1, A1)
I(T1, O2, A2)
B(T3)
C(T1)
B(T4)
U(T3,O2,B3,A3)
U(T4,O3,B4,A4)
CK(T2,T3,T4)  <-- salgo fino a qua
C(T4)
B(T5)
U(T3,O3,B5,A5)
U(T5,O4,B6,A6)
D(T3,O5,B7)
A(T3)
C(T5)
I(t2,O6,A8)  <-- interrupt
```


2. "SETUP": costruisco gli insiemi UNDO e REDO
undo: azioni da annullare
redo: azioni da riprendere

```
UNDO = {T2,T3,T4} // formato dagli elementi di CK
REDO = {}
```

scrivere quindi le operazioni effettuate:
```
0. UNDO = {T2,T3,T4}, REDO = {}
```

a partire dal CK si scende il log e ed effettuo le seguenti operazioni
- se un azione va in *"commit"* prima dell'interrupt viene inserita in **REDO**
- se una transazione va in *"begin"* viene inserita in **UNDO**

```
UNDO = {T2,T3,T4}
REDO = {}

B(T1)
B(T2)
U(T2, O1, B1, A1)
I(T1, O2, A2)
B(T3)
C(T1)
B(T4)
U(T3,O2,B3,A3)
U(T4,O3,B4,A4)
CK(T2,T3,T4)  <-- scendo da qua
C(T4)             // UNDO = {T2,T3}  REDO = {T4}
B(T5)             // UNDO = {T2,T3,T5}  REDO = {T4}
U(T3,O3,B5,A5)
U(T5,O4,B6,A6)
D(T3,O5,B7)
A(T3)
C(T5)            // UNDO = {T2,T3}  REDO = {T4,T5}
I(t2,O6,A8)  <-- interrupt

```

scrivere le operazioni effettuate:
```
1. C(T4) -> UNDO = {T2,T3}  REDO = {T4}
2. B(T5) -> UNDO = {T2,T3,T5} REDO = {T4}
3. C(T5) -> UNDO = {T2,T3}  REDO = {T4,T5}
```


3. Fase UNDO
```
UNDO = {T2,T3}
```
partendo dal basso, per le transazioni in "UNDO", eseguire le seguenti azioni a seconda del caso:
- se l'interrupt è accaduto durante un insert => eliminare l'oggetto inserito
- porre ogni oggetto manipolato uguale al before state (si ripristina il valore modificato)

```
B(T1)
B(T2)
U(T2, O1, B1, A1) <-- 01 = B1
I(T1, O2, A2)
B(T3)
C(T1)
B(T4)
U(T3,O2,B3,A3) <-- O2 = B3
U(T4,O3,B4,A4)
CK(T2,T3,T4)
C(T4)
B(T5)
U(T3,O3,B5,A5) <-- O3 = B5
U(T5,O4,B6,A6)
D(T3,O5,B7)  <-- pongo O5 uguale al before state (B7)
A(T3)
C(T5)            
I(t2,O6,A8)  <-- elimino l'oggetto O6
```

scrivere le operazioni effettuate:
```
4. D(O6)
5. O5 = B7
6. O3 = B5
7. O2 = B3
8. O1 = B1
```

4. Fase REDO
```
REDO = {T4,T5}
```
partendo dall'alto, per le transazioni in "REDO", si pongono gli oggetti manipolati uguali all'after state

```
B(T1)
B(T2)
U(T2, O1, B1, A1)
I(T1, O2, A2)
B(T3)
C(T1)
B(T4)
U(T3,O2,B3,A3)
U(T4,O3,B4,A4) <-- 03 = A4
CK(T2,T3,T4)
C(T4)
B(T5)
U(T3,O3,B5,A5)
U(T5,O4,B6,A6) <-- 04 = A6
D(T3,O5,B7)
A(T3)
C(T5)            
I(t2,O6,A8)
```

scrivere le operazioni effettuate:
```
9. O3 = A4
10. O4 = A6
```
