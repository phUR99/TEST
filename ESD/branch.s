       MOV     R0, #0XFF
       TST     R0, #0B10000000
       MOVEQ   R1, #3
       MOVNE   R1, #2
