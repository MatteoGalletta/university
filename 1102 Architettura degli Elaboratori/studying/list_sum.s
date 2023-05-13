NR     EQU     6
LIST   DCD     1,3,3,2,1,6
SUM    FILL    4

       MOV     R1, #NR
       ;LDR     R1, [R1] ; Necessario se NE è dichiarato come DCD (indirizzo quindi e non valore)
       MOV     R2, #LIST
       MOV     R4, #0

LOOP   LDR     R3, [R2]
       ADD     R4, R4, R3
       ADD     R2, R2, #4
       SUBS    R1, R1, #1
       BNE     LOOP

       MOV     R3, #SUM
       STR     R4, [R3]
       END
