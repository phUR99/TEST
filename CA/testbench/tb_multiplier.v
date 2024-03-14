`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/04/30 23:02:49
// Design Name: 
// Module Name: tb_multiplier
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


module tb_multiplier;
    
    reg clk;
    reg rst;
    reg [3:0] in1;
    reg [3:0] in2;
    
    wire [7:0] out;
   
    multiplier_optimized uut(clk, rst, in1, in2, out);
    
    initial begin
    
        clk =0;
        in1 =0;
        in2 = 0;
        
        #100;
        in1 =7;
        in2 =10;
        #15 rst= 1;
        #10 rst= 0;
        #10 rst= 1;
        
     end
     
     always #10 clk = ~clk;
endmodule
