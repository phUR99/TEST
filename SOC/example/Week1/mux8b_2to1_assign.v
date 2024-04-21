`timescale 1ns / 1ps


module mux8b_2to1_assign(a, b, sel, out);
    input [7:0] a, b;
    input sel;
    output [7:0] out;
    
    assign out = sel? b: a;
endmodule