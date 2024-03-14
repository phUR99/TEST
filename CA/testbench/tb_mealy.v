`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/04/30 21:41:05
// Design Name: 
// Module Name: tb_mealy
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


module tb_mealy;
    reg clk, rst, din_bit;
    
    wire dout_bit;

    mealy_fsm uut (clk, rst, din_bit, dout_bit);
    
    initial begin
        rst =1;
        #15 rst =0;
        #25 rst= 1;
        
     end
     
    
    initial  begin
        clk =0;
        forever 
        #10 clk = ~clk;
        
     end
     initial begin 
        din_bit =0;
        #35 din_bit = 0;
        #20 din_bit = 1;
        #20 din_bit = 1;
        #20 din_bit = 0;
        #20 din_bit = 0;
        #20 din_bit = 1;
        #20 din_bit = 1;
        #20 din_bit = 1;
        #20 din_bit = 0;
        #20 din_bit = 1;
        #20 din_bit = 1;
        #20 din_bit = 0;
        #20 din_bit = 1;
      end
    
endmodule
