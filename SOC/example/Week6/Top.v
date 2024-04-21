`timescale 1ns / 1ps
module Top(clk, rst, //클락
WriteReg,WriteData, //쓸 주소와 쓸 데이터
WriteEn, //쓰는거 enable
Min, //최소
Max, //최대
Valid); //output valid
    input clk;
    input rst;
    input [2:0] WriteReg;
    input WriteEn;
    input [15:0] WriteData;
    output [15:0] Min;
    output [15:0] Max;
    output Valid;
    wire Start;
    wire [2:0] ReadRegEven;
    wire [2:0] ReadRegOdd;
    wire [15:0] ReadDataEven;
    wire [15:0] ReadDataOdd;

    Counter_blue Counter_blue(.clk(clk), .rst(rst), .ReadRegEven(ReadRegEven), .ReadRegOdd(ReadRegOdd), .Start(Start));
    Counter Counter(.Start(Start), .clk(clk), .rst(rst), .WriteEn(WriteEn));
    RegisterFile RegisterFile(.WriteEn(WriteEn), .rst(rst), .WriteReg(WriteReg), .WriteData(WriteData), .ReadRegEven(ReadRegEven), .ReadRegOdd(ReadRegOdd), 
    .ReadDataEven(ReadDataEven), .ReadDataOdd(ReadDataOdd), .clk(clk));
    MinMaxFinder MinMaxFinder(.ReadDataEven(ReadDataEven), .ReadDataOdd(ReadDataOdd), .clk(clk), .Start(Start), .Min(Min), .Max(Max), .Valid(Valid), .rst(rst));
endmodule
