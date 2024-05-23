`timescale 1ns / 1ps

module ADDER(
clk, rst_n, data1, data2, data3, out
    );

    input clk;
    input rst_n;
    input [7 : 0] data1, data2, data3;
    output reg [9 : 0] out;
    
    // 코드 작성
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            out <= 10'b0;
        end
        else begin
            out <= data1 + data2 + data3;
        end

    end
    
endmodule
