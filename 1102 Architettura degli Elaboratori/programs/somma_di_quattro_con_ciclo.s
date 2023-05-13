NR     EQU     4
LISTA  DCD     10, 20, 30, 40
SOMMA  FILL    4

MAIN   MOV     R1, #0       ; Conservo in R1 il valore 0. R1 rappresenta la somma
       MOV     R2, #LISTA   ; Conservo in R2 l'indirizzo della lista dei numeri
       MOV     R3, #NR      ; Conservo in R3 il valore NR (ovvero 4)

CICLO  LDR     R4, [R2]     ; Conservo in R4 il valore puntato da R2. Carico quindi in R4 il numero della lista attuale
       ADD     R1, R1, R4   ; Sommo a R1 il numero appena letto (R4)
       SUBS    R3, R3, #1   ; Scalo di 1 il contatore (il numero di elementi iniziale). La "S" nell'op code indica l'aggiornamento del bit del registro di stato "Z".
       ADD     R2, R2, #4   ; Incremento di una parola il contatore della lista
       BGT     CICLO        ; Se il bit di stato "Z" è uguale a 0 si effettua il salto a CICLO. Ovvero, se R3 è diverso da zero

       MOV     R5, #SOMMA
       STR     R1, [R5]
