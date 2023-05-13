NS     DCD     274,13
RQ     FILL    4
RR     FILL    4

       MOV     R1, #NS
       LDR     R2, [R1, #4]
       LDR     R1, [R1]
       MOV     R3, #0

LOOP   SUBS    R4, R1, R2
       BLE     STORE
       MOV     R1, R4
       ADD     R3, R3, #1
       B       LOOP

STORE  MOV     R5, #RQ
       STR     R1, [R5]
       MOV     R5, #RR
       STR     R3, [R5]
