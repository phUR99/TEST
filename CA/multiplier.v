`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/04/30 22:44:03
// Design Name: 
// Module Name: multiplier
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


module multiplier(
    input clk, rst, input[3:0] in1, input[3:0] in2, output[7:0] out);          
    reg [3:0] multiplier; reg [7:0] product, multiplicand; reg [2:0] i;      
    wire shift, addition, write;   
    
    control ctl(multiplier[0], i, shift, addition, write);   
    always @(posedge  clk, negedge rst) begin
        if (!rst) begin
            product =0;
            multiplier = in1;
            multiplicand = in2;
        end
        if (addition & rst) begin product = product + multiplicand;  end            
        if (shift & rst) begin
            multiplicand = multiplicand << 1;
            multiplier = multiplier >> 1;
        end
        i <= (!rst) ? 4 : shift ? i-1 : i;
    end
    assign out = write ? product : 0;   
endmodule
module control(
    input M,
    input [2:0] i,
    output shift, addition, write
    );    
    assign addition = M; assign shift = (i == 0) ? 0 : 1; assign write = ~shift;      
endmodule 


module multiplier_optimized(
    input clk, rst, input[3:0] in1, input[3:0] in2, output[7:0] out);          
    reg [8:0] product; reg[3:0] multiplicand; reg [2:0] i;      
    wire shift, addition, write, cout;
    wire [3:0] sum;   
    
    control ctl(product[0], i, shift, addition, write);
    FA_4bit ALU(product[7:4], multiplicand, 0, sum, cout);   
    always @(posedge  clk, negedge rst) begin
        if (!rst) begin
            product = in1;
            multiplicand = in2;
        end
        if (addition & rst) begin product[8:4] = {cout, sum};  end            
        if (shift & rst) begin
            product = product >> 1;
        end
        i <= (!rst) ? 4 : shift ? i-1 : i;
    end
    assign out = write ? product : 0;   
endmodule
module control(
    input M,
    input [2:0] i,
    output shift, addition, write
    );    
    assign addition = M; assign shift = (i == 0) ? 0 : 1; assign write = ~shift;      
endmodule 
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
