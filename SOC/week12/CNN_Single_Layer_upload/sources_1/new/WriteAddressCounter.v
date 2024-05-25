`timescale 1ns / 1ps

module WriteAddressCounter(
clk, rst_n, Start, WriteReg
    );
    
    input clk;
    input rst_n;
    input Start;
    output [3:0] WriteReg;
    wire [14:0] count;
    // module RingCounter(count,clk,rst_n, en);
    RingCounter X(count, clk, rst_n, Start);
    // module AddressEncoder(AddrIn, AddrOut);
    AddressEncoder A(count, WriteReg);
endmodule
