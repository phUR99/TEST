`timescale  1ns/1ps

module Top (
    clk, WriteReg, WriteData, 
    WriteEn, 
    min, Max,
    Vaild
);
    input clk;
    input [2:0] WriteReg;
    input WriteEn;
    input [15:0] WriteData;
    output [15:0] min, Max;
    output Vaild;

    wire  Start;
    wire [1:0] ReadRegEven, ReadRegOdd;
    wire [15:0] ReadDataEven, ReadDataOdd;
    Counter_blue Counter_blue(.clk(clk), .ReadRegEven(ReadRegEven), .ReadRegOdd(ReadRegOdd), .Start(Start));
    Counter Counter(.Start(Start), .clk(clk), .WriteEn(WriteEn));    
    register_file register_file(.WriteEn(WriteEn), .WriteReg(WriteReg), .WriteData(WriteData), .ReadRegEven(ReadRegEven), .ReadRegOdd(ReadRegOdd), 
    .ReadDataEven(ReadDataEven), .ReadDataOdd(ReadDataOdd), .clk(clk));
    MinMaxFinder MinMaxFinder(.ReadDataEven(ReadDataEven), .ReadDataOdd(ReadDataOdd), .clk(clk), .Start(Start), .min(min), .Max(Max), .Vaild(Vaild));


endmodule