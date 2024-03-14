`timescale 1ns / 1ps


module mux41_if(
    input [1:0] sel, // 2bit selection bit
    input [3:0] a, // value a
    input [3:0] b, // value b
    input [3:0] c, // value c
    input [3:0] d, // value d
    output reg [3:0] y //  value의 값이 바로 변하는게 아니라 가지고 있으면서 유지를 해야하기 때문에 reg로 선언
    );
    always @(sel or a or b or c or d) begin // a,b,c,d,sel의 변화가 생기면 이 구문을 실행시킨다.
        if (sel ==2'b00) y =a; // output y 에 a value를 할당시킨다.
        else if (sel ==2'b01) y =b; // output y 에 a value를 할당시킨다.
        else if (sel ==2'b10) y =c; // output y 에 a value를 할당시킨다.
        else if (sel ==2'b11) y =d; // output y 에 a value를 할당시킨다.
    end    
endmodule



module mux41_case(sel, a, b, c, d ,y);
    input [1:0] sel;
    input [3:0] a, b, c, d;
    output reg [3:0] y;
    
    always @(*) begin // module의 input으로 들어오는 value에 어떤 변화라도 생긴다면 이 구문을 실행시킨다.
        case(sel) 
            0:  y = a;
            1:  y = b;
            2:  y = c;
            3:  y = d;
        endcase
     end
endmodule







module mux41_conop(sel, a, b, c, d, y);
    input [1:0] sel;
    input [3:0] a,b,c,d;
    output [3:0] y;
    
    assign y = (sel == 0) ? a: //3항 연산자를 이용한 방식 false일 경우는 다 check한 후 걸어주면 된다.
                (sel == 1) ? b:
                (sel == 2) ? c:
                (sel == 3) ? d: 4'bx; 
                
endmodule             
 
    
