`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/04/30 17:22:40
// Design Name: 
// Module Name: tb_mux41
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


module tb_mux41;
    //input
    reg [3:0] a;
    reg [3:0] b;
    reg [3:0] c;
    reg [3:0] d;
    reg [1:0] sel;
    //output
    wire [3:0] y;
    
    mux41_conop uut (.a(a), .b(b), .c(c), .d(d), .sel(sel), .y(y));
    
    initial begin
    
        a = 4'b0001;
        b = 4'b0010;
        c = 4'b0100;
        d = 4'b1000;
        
        #80
        a = 4'b1100;
        b = 4'b0011;
        c = 4'b0110;
        d = 4'b1001;
        
     end
    initial sel = 2'b00;
    always #20 sel=sel+1;
    
        
endmodule
