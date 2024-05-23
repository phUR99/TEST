`timescale 1ns / 1ps

module ReadAddressCounter(
clk, rst_n, ReadEn, ReadReg
    );
    parameter Init = 14;

    input clk;
    input rst_n;
    input ReadEn;
    output [3:0] ReadReg;
    
    wire [14:0] count;
    
    // �ڵ� �ۼ�
    
    // module RingCounter(count,clk,rst_n, en);
    RingCounterX3 X(count, clk, rst_n, ReadEn);
    AddressEncoder A(count, ReadReg);
    
endmodule