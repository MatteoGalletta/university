NR     EQU     10
LIST   DCD     1,5,2,4,8,5,9,2,5,-1

       MOV     R1, #NR
       MOV     R2, #LIST
       MOV     R3, #1
OUTER  SUB     R5, R1, R3
       MOV     R4, #0
       MOV     R7, #0

INNER  ADD     R6, R7, #4
       LDR     R9, [R2, R6]
       LDR     R10, [R2, R7]
       CMP     R9,R10
       BGT     KEEP

       STR     R9, [R2, R7]
       STR     R10, [R2, R6]

KEEP   ADD     R7, R7, #4
       ADD     R4, R4, #1
       CMP     R4, R5
       BNE     INNER
       ADD     R3, R3, #1
       CMP     R3, R1
       BNE     OUTER

