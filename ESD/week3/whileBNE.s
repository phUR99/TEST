       MOV     R1, #54
       MOV     R2, #36


LOOP   
       CMP     R1, R2
       SUBGT   R1, R1, R2
       SUBLE   R2, R2, R1
       CMP     R1, R2
       BNE     LOOP
