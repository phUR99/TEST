`timescale 1ns / 1ps
module Top(clk, rst, //Ŭ��
WriteReg,WriteData, //�� �ּҿ� �� ������
WriteEn, //���°� enable
Min, //�ּ�
Max, //�ִ�
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
