`timescale 1ns / 1ps

module AddressCounter(
clk, rst_n, Start, WriteReg, ReadEn, ReadReg1, ReadReg2, ReadReg3
    );
    
    input clk, rst_n;
    input Start;    // Start : ������� ���� ���� �� Register File�� Write ����
    input ReadEn;   // ReadEn   : Register File���� Read ����
    output [3:0] WriteReg;      // WriteReg : Register File�� ������ �ּ�
    output [3:0] ReadReg1, ReadReg2, ReadReg3;  // ReadReg : Register File���� ���� �ּ�
        
    // �ڵ� �ۼ�
    //module ReadAddressCounter(clk, rst_n, ReadEn, ReadReg);

    ReadAddressCounter Readaddress1(clk, rst_n, ReadEn, ReadReg1);
    ReadAddressCounter Readaddress2(clk, rst_n, ReadEn, ReadReg2);
    ReadAddressCounter Readaddress3(clk, rst_n, ReadEn, ReadReg3);

    //module WriteAddressCounter(clk, rst_n, Start, WriteReg);
    WriteAddressCounter WriteAddress(clk, rst_n, Start, WriteReg);




endmodule
