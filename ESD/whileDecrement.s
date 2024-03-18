       MOV     R0, #3
       MOV     R1, #5
       MOV     R2, #0

LOOP   
       ADD     R2, R2, R0
       SUBS    R1, R1, #1
       CMP     R1, #0
       BNE     LOOP
