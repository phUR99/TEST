`timescale 1ns / 1ps

module mux8b_2to1_if(a, b, sel, out);
    input [7:0] a, b;
    input sel;
    output [7:0] out;
    reg [7:0] out;
    
    always@(a, b, sel) begin
        if(sel) out= b;
        else out = a;
    end
endmodule