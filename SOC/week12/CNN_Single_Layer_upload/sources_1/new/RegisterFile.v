`timescale 1ns / 1ps

module RegisterFile(clk, rst_n, ReadReg1, ReadReg2, ReadReg3,
WriteReg, WriteEn, WriteData, ReadEn, ReadData1, ReadData2, ReadData3);
    parameter M = 4;   // number of address bits
    parameter N = 16;  // number of words, N = 2**M
    parameter W = 8;   // number of bits in a word
    
    input   clk, rst_n;
    input   WriteEn;     // RegWrite�� High�� �� register file�� data�� ����
    input   [W-1:0] WriteData; // Register file�� ������ data
    output reg [W-1:0] ReadData1, ReadData2, ReadData3;  // Register file���� ���� data
    input   ReadEn;
    input   [M-1:0] ReadReg1, ReadReg2, ReadReg3; // Register file���� ���� �ּ�
    input   [M-1:0] WriteReg; // Register file���� data�� ������ �ּ�
    
    // �ڵ� �ۼ�

    reg [W-1:0] ram[N-1:0];

    always @(posedge clk or negedge rst_n) begin
        if(!rst_n) begin
            ReadData1 <= 0;
            ReadData2 <= 0;
            ReadData3 <= 0;
        end
        else if(ReadEn) begin
            ReadData1 <= ram[ReadReg1];
            ReadData2 <= ram[ReadReg2];
            ReadData3 <= ram[ReadReg3];
        end
    end

    always @(posedge clk or negedge rst_n) begin
        if(!rst_n) begin
            ram[WriteReg] <= 0;
        end
        else if(WriteEn) begin
            ram[WriteReg] <= WriteData;
        end
    end

    
endmodule
