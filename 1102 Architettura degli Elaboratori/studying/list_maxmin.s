NR      EQU     6
LIST    DCD     1,2,5,-9,6,-8
RES     FILL    8

        MOV     R1, #NR
        MOV     R2, #LIST
        LDR     R3, [R2] ; MAX
        LDR     R4, [R2] ; MIN
        SUB     R1, R1, #1
        ADD     R2, R2, #4

LOOP    LDR     R5, [R2]
        CMP     R5, R3
        BLT     NOT_MAX
        MOV     R3, R5
NOT_MAX CMP     R5, R4
        BGT     NOT_MIN
        MOV     R4, R5
NOT_MIN SUBS    R1, R1, #1
        ADD     R2, R2, #4
        BNE     LOOP

        MOV     R6, #RES
        STR     R3, [R6]
        STR     R4, [R6, #4]