`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/05/01 13:49:38
// Design Name: 
// Module Name: ALU_32bit
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


module ALU_32bit(

    );
endmodule
module ALU_1bit(
    input a_in, b_in, carry_in, invert_a, invert_b, less,
    input [1:0] op,
    output result,
    output carry_out
);
    wire a_out, b_out;
    wire and_out, or_out, sum;
    
    fulladder_1bit fu(a_out, b_out, carry_in, sum, carry_out);
    mux41_case m2(op, and_out, or_out, sum, less, result);
    and(and_out, a_out, b_out);
    or(or_out, a_out,  b_out);
    xor(a_out, a_in, a_invert);
    xor(b_out, b_in, b_invert);    
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
module mux41_case(sel, a, b, c, d ,y);
    input [1:0] sel;
    input [3:0] a, b, c, d;
    output reg [3:0] y;
    
    always @(*) begin // module   input            value       ȭ       ٸ                 Ų  .
        case(sel) 
            0:  y = a;
            1:  y = b;
            2:  y = c;
            3:  y = d;
        endcase
     end
endmodule

module ALU_1bit_overflow(
    input ai, bi, ci, aiv, biv, less,
    input[1:0] op,
    output re, set, of
    
   );
   wire ao, bo, co;
   wire o1, o2, o3;
   fulladder_1bit fu(ao, bo, ci, o3, co); 
   mux41_case m2(op, o1, o2, o3, less, re);
   and(o1, ao, bo);
   or(o2, a0, b0);
   xor(ao, ai, aiv);
   xor(bo, bi, biv);
   assign set = o3;
   assign of = co^ci;
endmodule    


module ALU_32bit(
    input [31:0] a_in,
    input [31:0] b_in,
    input [3:0] op,
    output [31:0] result,
    output zero, overflow
    );
    wire [30:0] co;
    wire set;
    
    ALU_1bit u0 (a_in[0], b_in[0], op[2], op[3], op[2], set,op[1:0],result[0], co[0]);
    ALU_1bit u1 (a_in[1], b_in[1], co[0], op[3], op[2], 1'b0,op[1:0],result[1], co[1]);
    ALU_1bit u2 (a_in[2], b_in[2], co[1], op[3], op[2], 1'b0,op[1:0],result[2], co[2]);
    ALU_1bit u3 (a_in[3], b_in[3], co[2], op[3], op[2], 1'b0,op[1:0],result[3], co[3]);
    ALU_1bit u4 (a_in[4], b_in[1], co[3], op[3], op[2], 1'b0,op[1:0],result[4], co[4]);
    ALU_1bit u5 (a_in[5], b_in[2], co[4], op[3], op[2], 1'b0,op[1:0],result[5], co[5]);
    ALU_1bit u6 (a_in[6], b_in[6], co[5], op[3], op[2], 1'b0,op[1:0],result[6], co[6]);
    ALU_1bit u7 (a_in[7], b_in[7], co[6], op[3], op[2], 1'b0,op[1:0],result[7], co[7]);
    ALU_1bit u8 (a_in[8], b_in[8], co[7], op[3], op[2], 1'b0,op[1:0],result[8], co[8]);
    ALU_1bit u9 (a_in[9], b_in[9], co[8], op[3], op[2], 1'b0,op[1:0],result[9], co[9]);
    ALU_1bit u10 (a_in[10], b_in[10], co[9], op[3], op[2], 1'b0,op[1:0],result[10], co[10]);
    ALU_1bit u11 (a_in[11], b_in[11], co[10], op[3], op[2], 1'b0,op[1:0],result[11], co[11]);
    ALU_1bit u12 (a_in[12], b_in[12], co[11], op[3], op[2], 1'b0,op[1:0],result[12], co[12]);
    ALU_1bit u13 (a_in[13], b_in[13], co[12], op[3], op[2], 1'b0,op[1:0],result[13], co[13]);
    ALU_1bit u14 (a_in[14], b_in[14], co[13], op[3], op[2], 1'b0,op[1:0],result[14], co[14]);
    ALU_1bit u15 (a_in[15], b_in[15], co[14], op[3], op[2], 1'b0,op[1:0],result[15], co[15]);
    ALU_1bit u16 (a_in[16], b_in[16], co[15], op[3], op[2], 1'b0,op[1:0],result[16], co[16]);
    ALU_1bit u17 (a_in[17], b_in[17], co[16], op[3], op[2], 1'b0,op[1:0],result[17], co[17]);
    ALU_1bit u18 (a_in[18], b_in[18], co[17], op[3], op[2], 1'b0,op[1:0],result[18], co[18]);
    ALU_1bit u19 (a_in[19], b_in[19], co[18], op[3], op[2], 1'b0,op[1:0],result[19], co[19]);
    ALU_1bit u20 (a_in[20], b_in[20], co[19], op[3], op[2], 1'b0,op[1:0],result[20], co[20]);
    ALU_1bit u21 (a_in[21], b_in[21], co[20], op[3], op[2], 1'b0,op[1:0],result[21], co[21]);
    ALU_1bit u22 (a_in[22], b_in[22], co[21], op[3], op[2], 1'b0,op[1:0],result[22], co[22]);
    ALU_1bit u23 (a_in[23], b_in[23], co[22], op[3], op[2], 1'b0,op[1:0],result[23], co[23]);
    ALU_1bit u24 (a_in[24], b_in[24], co[23], op[3], op[2], 1'b0,op[1:0],result[24], co[24]);
    ALU_1bit u25 (a_in[25], b_in[25], co[24], op[3], op[2], 1'b0,op[1:0],result[25], co[25]);
    ALU_1bit u26 (a_in[26], b_in[26], co[25], op[3], op[2], 1'b0,op[1:0],result[26], co[26]);
    ALU_1bit u27 (a_in[27], b_in[27], co[26], op[3], op[2], 1'b0,op[1:0],result[27], co[27]);
    ALU_1bit u28 (a_in[28], b_in[28], co[27], op[3], op[2], 1'b0,op[1:0],result[28], co[28]);
    ALU_1bit u29 (a_in[29], b_in[29], co[28], op[3], op[2], 1'b0,op[1:0],result[29], co[29]);
    ALU_1bit u30 (a_in[30], b_in[30], co[29], op[3], op[2], 1'b0,op[1:0],result[30], co[30]);
    ALU_1bit_overflow u31 (a_in[31], b_in[31], co[30], op[3], op[2], 1'b0,op[1:0],result[31],set, overflow);
    assign zero = ~result? 1: 0;
 endmodule 
