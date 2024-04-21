`timescale 1ns / 1ps



module mux8b_2to1_case(a, b, sel, out);
    input [7:0] a, b;
    input sel;
    output [7:0] out;
    reg [7:0] out;
    
    always@(a, b, sel) begin
        case(sel)
            1'b0: out = a;
            1'b1: out = b;
        endcase
    end
endmodule
