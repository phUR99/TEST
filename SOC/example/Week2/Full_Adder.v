`timescale 1ns / 1ps

module Full_Adder(x, y, c_in, sum, c_out);

input [3:0] x, y;
input c_in;
output [3:0] sum;
output c_out;

    assign {c_out, sum} = x + y + c_in;
    
endmodule
