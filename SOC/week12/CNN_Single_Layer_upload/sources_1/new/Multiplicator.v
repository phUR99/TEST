`timescale 1ns / 1ps

module Multiplicator(Start, din0, din1, dout);

    input Start;
    input [3:0] din0;
    input [3:0] din1;
    output [7:0] dout;
    
    // 코드 작성
    assign dout = (Start) ? din0 * din1 : 8'b0;

endmodule