`timescale 1ns / 1ps

module RingCounter(count,clk,rst_n, en);
        
    input clk, rst_n, en;
    output reg [14:0] count;
    
    // 코드 작성
    always @(posedge clk or negedge rst_n) begin
        if(!rst_n ) count <= 15'b100_0000_0000_0000;
        else if(en) count <= {count[13:0], count[14]};
    end
    
endmodule

module RingCounterX3(clk,rst_n, en, count);
	
	parameter Init = 14;
	
    input clk, rst_n, en;
    output reg [14:0] count;

    // 코드 작성
    always @(posedge clk or negedge rst_n) begin
        if(!rst_n) count <= 15'b000_0000_0000_0001 << Init;
        else if(en) count <= {count[11:0], count[14:12]};
    end
    
 
endmodule