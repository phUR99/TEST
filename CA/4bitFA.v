`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/04/30 19:51:00
// Design Name: 
// Module Name: FA_4bit
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////

module FA_4bit(
    input [3:0] a, [3:0] b, cin,
    output [3:0] sum, output cout 
    );  
    wire c1, c2, c3;
    fulladder_1bit fa1(.a(a[0]), .b(b[0]), .carry_in(cin), .sum(sum[0]), .carry_out(c1));
    fulladder_1bit fa2(.a(a[1]), .b(b[1]), .carry_in(c1), .sum(sum[1]), .carry_out(c2));
    fulladder_1bit fa3(.a(a[2]), .b(b[2]), .carry_in(c2), .sum(sum[2]), .carry_out(c3));
    fulladder_1bit fa4(.a(a[3]), .b(b[3]), .carry_in(c3), .sum(sum[3]), .carry_out(cout));
endmodule

module fulladder_1bit(
    input a, b, carry_in,
    output sum, carry_out 
    );  
    wire s1,c1,c2 ;   
    half_adder ha1(.a(a), .b(b), .s(s1), .c(c1));
    half_adder ha2(.a(carry_in), .b(s1), .s(sum), .c(c2)); 
    or(carry_out, c1 , c2);
    
endmodule

module half_adder(
    input a,b,
    output s,c
    );
    xor(s, a, b);
    and(c, a, b);
endmodule 
    
