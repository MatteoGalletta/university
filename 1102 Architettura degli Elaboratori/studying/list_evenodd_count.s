NR      EQU     5
LIST    DCD     5,2,3,-5,4
ODD_C   FILL    4
EVN_C   FILL    4

        MOV     R1, #LIST
        MOV     R5, #NR
        MOV     R2, #0 ; EVN_C

LOOP    LDR     R3, [R1]
        TST     R3, #1
        BNE     NOT_EVN
        BL      ADD_EVN
NOT_EVN ADD     R1, R1, #4
        SUBS    R5, R5, #1
        BNE     LOOP

        MOV     R4, #EVN_C
        STR     R2, [R4]

        MOV     R4, #ODD_C
        MOV     R5, #NR
        SUB     R2, R5, R2
        STR     R2, [R4]

        END

ADD_EVN ADD     R2, R2, #1
        MOV     PC, LR
