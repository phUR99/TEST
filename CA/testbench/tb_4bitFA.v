`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/04/30 20:16:24
// Design Name: 
// Module Name: tb_fulladder_4bit
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


module tb_fulladder_4bit;
    reg [3:0] a;
    reg [3:0] b;
    reg c;
    
    wire[3:0] sum;
    wire cout;
    
    integer k;
    FA_4bit uut(a, b, c, sum, cout);
    initial begin
        c =1;
        forever begin
            for(k=0;k<16;k=k+1) begin
                b=k;
                a=k/2;
                c =~c;
                #50;
             end
         end
     end
 
    
endmodule
