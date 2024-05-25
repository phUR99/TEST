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

    // module RingCounterX3(clk,rst_n, en, count);
    RingCounterX3 #(Init) X(clk, rst_n, ReadEn, count);
    //module AddressEncoder(AddrIn, AddrOut);
    AddressEncoder A(count, ReadReg);
    
endmodule