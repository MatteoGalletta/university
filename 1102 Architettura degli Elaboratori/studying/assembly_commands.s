NR      EQU 5       ; Definizione Costante (define)
LIST    DCD 1,2,3,5 ; Dichiarazione Lista in Memoria
ADD R1, R2, R3      ; Somma: R1=R2+R3
ADDS R1, R2, R3     ; Somma: R1=R2+R3 impostando PS
SUB R1, R2, R3      ; ^~
SUBS R1, R2, R3     ; ^~
LDR R1, [R3]        ; LOAD (leggi l'indirizzo puntato da R3 e scrivilo in R1)
LDR R1, [R3,#5]     ; ^~ con spiazzamento
STR R1, [R3]        ; STORE (scrivi nell'indirizzo puntato da R3 il valore letto da R1)
STR R1, [R3,#5]     ; ^~ con spiazzamento
NR FILL 4           ; RESERVE (lascia 4 byte vuoti)
MOV R1, #NR         ; Salva in R1 l'indirizzo con etichetta NR
CMP R1, [R2,#5]     ; Imposta il PS di conseguenza
END                 ; Termina il programma

; Salti
B                   ; Salto Incondizionato
BL                  ; Salto Incondizionato con Salvataggio di LR
BLE                 ; <= 0
BLT                 ; < 0
BGE                 ; >= 0
BGT                 ; > 0
BEQ                 ; == 0
