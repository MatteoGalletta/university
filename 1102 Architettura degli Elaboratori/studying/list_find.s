NR      EQU     5
TO_FIND EQU     5
LIST    DCD     2,3,-5,4,1
INDEX   FILL    4

        MOV     R1, #NR
        MOV     R2, #TO_FIND
        MOV     R3, #0
        MOV     R7, #0
        MOV     R4, #LIST

LOOP    LDR     R5, [R4, R7]
        CMP     R5, R2
        BEQ     FOUND
        ADD     R3, R3, #1
        ADD     R7, R7, #4
        CMP     R1, R3
        BNE     LOOP
        MOV     R3, #-1

FOUND   MOV     R6, #INDEX
        STR     R3, [R6]