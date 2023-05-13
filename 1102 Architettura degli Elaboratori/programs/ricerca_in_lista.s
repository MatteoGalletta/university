N_ITEMS  EQU     9
LIST     DCD     1,24,12,0,10,4,21,3,5
TO_FIND  EQU     10
ITEM_IDX DCD     -1

MAIN     MOV     R1, #N_ITEMS
         MOV     R2, #LIST

LOOP     LDR     R3, [R2]
         CMP     R3, #TO_FIND
         BEQ     FOUND

         SUBS    R1, R1, #1
         ADD     R2, R2, #4
         BGT     LOOP
         END

FOUND    
         MOV     R4, #N_ITEMS
         SUB     R4, R4, R1
         MOV     R5, #ITEM_IDX
         STR     R4, [R5]
         END
