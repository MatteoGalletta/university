NS     DCD     9,3
RES    FILL    4

       MOV     R1, #NS
       LDR     R2, [R1,#4] ; R2 contiene il secondo fattore
       LDR     R1, [R1] ; R1 contiene il primo fattore
       MOV     R3, #0 ; R3 contiene il risultato del prodotto

LOOP   ADD     R3, R3, R1 ; R3=R3+R1
       SUBS    R2, R2, #1
       BNE     LOOP

       MOV     R4, #RES
       STR     R3, [R4]
