          MOV     R12, #0X200
          MOV     R0, #1
          MOV     R1, #2
          MOV     R2, #3
          STMIA   R12, {R0, R1, R2} ; R12가 가리키는 주소로부터 4BYTE씩 올리면서
          ;       R0, R1, R2의 값을 메모리에 저장

          LDR     R3, =TESTINFO0 ; R3에 TABLE의 주소를 전달
          LDMIA   R3, {R0, R2, R5} ; TABLE로부터 4BYTE씩 올려가면서 R0, R2, R5에 저장
          STMIA   R3, {R4, R5, R6} ; R3<R5, R6에서 4BYTE씩 올려가면서 TABLE에 저장
          LDMIB   R3, {R0, R2, R5}
          STMIB   R3, {R4, R5, R6}
          STMIA   R3, {R4-R12}
          LDMIA   R3, {R1-R2, R4-R6}



TESTINFO0 DCD     1, 2, 3, 4, 5, 6, 7, 8 ; DCD : TABLEINFO0이라는 이름의 TABLE을 만든다
