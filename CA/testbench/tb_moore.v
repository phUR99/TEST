`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/04/30 21:13:08
// Design Name: 
// Module Name: tb_moore
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


module tb_moore;
    reg clk, rst, bypass;
    
    wire [1:0] out;
    
    moore_fsm uut (clk, rst, bypass, out);
    
    initial begin 
        rst=1;
        #15 rst=0;
        #25 rst=1;
        
     end
     
     initial begin
        clk=0;
        forever 
        #10 clk = ~clk;
     end
    
    initial begin 
        bypass =0;
        #100 bypass =1;
        #100 bypass =0;
     end
endmodule
