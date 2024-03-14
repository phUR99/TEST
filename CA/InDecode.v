`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/05/01 16:32:12
// Design Name: 
// Module Name: InDecode
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////
module Hazard_detection_unit(
    input exe_Ctl_MemRead_in, //ID/EX register에 저장되어 있는 Ctl_MemRead_in 신호
    input [4:0] Rd_in, //ID/EX 에 저장되어 있는 Rd
    input [9:0] instruction_in,
    output stall_out //Stall 여부를 결정해주는 신호
    );
    wire [4:0] Rs1_in = instruction_in[4:0];
    wire [4:0] Rs2_in = instruction_in[9:5];
    assign stall_out = (exe_Ctl_MemRead_in && (Rd_in == Rs1_in || Rd_in == Rs2_in)) ? 1:0;
endmodule


module InDecode(
    input clk, reset,
    input stall,
    input flush,
    
    input Ctl_RegWrite_in, // Reg에 WriteData를 쓸지 말지 결정하는 신호
    output reg Ctl_ALUSrc_out, Ctl_MemtoReg_out, Ctl_RegWrite_out, Ctl_MemRead_out, Ctl_MemWrite_out, Ctl_Branch_out, Ctl_ALUOpcode1_out, Ctl_ALUOpcode0_out,
    input [4:0] WriteReg, //reg에 data를 write할 때 타겟 reg 주소
    input [31:0] PC_in, instruction_in, WriteData, //WriteReg에 write할 Data 값

    output reg [4:0] Rd_out, Rs1_out, Rs2_out,
    output reg [31:0] PC_out, ReadData1_out, ReadData2_out, Immediate_out, 
    //reg[rs1 / rs2] (source가 되는 reg에서 읽어온 data 값)
    //Immediate 값 (I-type, S-type, B-type 등 instruction에서)
    output reg [6:0] funct7_out,
    output reg [2:0] funct3_out,
    output reg jalr_out, jal_out //jalr / jal instruction 여부를 결정하는 신호

    );
    wire [6:0] opcode = instruction_in[6:0];
    wire [6:0] funct7 = instruction_in[31:25];
    wire [2:0] funct3 = instruction_in[14:12];
    wire [4:0] Rd = instruction_in[11:7];
    wire [4:0] Rs1 = instruction_in[19:15];
    wire [4:0] Rs2 = instruction_in[24:20];
    wire jalr = (opcode==7'b11001_11)?1:0;
    wire jal =  (opcode==7'b11011_11)?1:0;
    
    wire [7:0] Ctl_out;
    
    Control_unit B0 (.opcode(opcode), .Ctl_out(Ctl_out), .reset(reset));
    reg [7:0] Control;
    always @(*) begin
        Control = (flush)?  1'b0:
                  (stall)?  1'b0: Ctl_out;
     end           
    parameter reg_size = 32;
    reg [31:0] Reg[0:reg_size-1];
    
    always@(posedge clk) begin
        if(reset) 
            Reg[0] <= 32'b0;
        else if(Ctl_RegWrite_in && WriteReg!=0) begin
            Reg[WriteReg] <= WriteData;
        end    
    end
    
    reg [31:0] Immediate; //signed extension한 immediate 값
    always@(*) begin
        case(opcode)
            7'b00000_11: Immediate = $signed(instruction_in[31:20]);
            7'b00100_11: Immediate = $signed(instruction_in[31:20]);
            7'b11001_11: Immediate = $signed(instruction_in[31:20]);
            7'b01000_11: Immediate = $signed({instruction_in[31:25], instruction_in[11:7]});
            7'b11000_11: Immediate = $signed({instruction_in[31],instruction_in[7],instruction_in[30:25],instruction_in[11:8]});
            7'b11011_11: Immediate = $signed({instruction_in[31],instruction_in[19:12],instruction_in[20],instruction_in[30:21]});
            default: Immediate = 32'b0;
        endcase
    end
    
    always @(posedge clk) begin
        PC_out <= (reset) ? 0 : PC_in;
        funct7_out <= (reset) ? 0 : funct7;
        funct3_out <= (reset) ? 0 : funct3;
        Rd_out <= (reset) ? 0 : Rd;
        Rs1_out <= (reset) ? 0 : Rs1;
        Rs2_out <= (reset) ? 0 : Rs2;
        ReadData1_out <= (reset) ? 0 : (Ctl_RegWrite_in&&WriteReg==Rs1)? WriteData :Reg[Rs1];
        ReadData2_out <= (reset) ? 0 : (Ctl_RegWrite_in&&WriteReg==Rs2)? WriteData :Reg[Rs2];
        jalr_out <= (reset) ? 0 : jalr;
        jal_out <= (reset) ? 0 : jal;
        
        Ctl_ALUSrc_out <= (reset) ? 0 : Control[7];
        Ctl_MemtoReg_out <= (reset) ? 0 : Control[6];
        Ctl_RegWrite_out <= (reset) ? 0 : Control[5];
        Ctl_MemRead_out <= (reset) ? 0 : Control[4];
        Ctl_MemWrite_out <= (reset) ? 0 : Control[3];
        Ctl_Branch_out <= (reset) ? 0 : Control[2];
        Ctl_ALUOpcode1_out <= (reset) ? 0 : Control[1];
        Ctl_ALUOpcode0_out <= (reset) ? 0 : Control[0];
        
        Immediate_out <= (reset) ? 0:Immediate;
    end
endmodule
/*
Ctl_ALUSrc_out, - ALU의 input 으로 ReadData를 넣을 건지, Immediate 값을 넣을 것인지 결정하는 신호
Ctl_ALUOpcode1_out, - (Ctl_ALUOpcode1,0_out) ALU에서 사용되는 ALU_ctl(이 신호에 따라 ALU동작이 달라짐)을 결정하는 신호.
Ctl_ALUOpcode0_out (Ex)

Ctl_Branch_out, - branch 여부를 결정하는 신호
Ctl_MemRead_out, - (Ctl_MemRead, MemWrite_out) mem을 read 할지, mem에 write할지 결정하는 신호
Ctl_MemWrite_out (Mem) - Mem로부터 읽은 Data를 reg에 쓸지 결정하는 신호

Ctl_MemtoReg_out,
Ctl_RegWrite_out, (WB) - Reg에 WriteData를 쓸지 말지 결정하는 신호






*/

module Control_unit(
    input [6:0] opcode,
    input reset,
    output reg [7:0] Ctl_out
    );
    
    always@(*) begin
        if (reset)
            Ctl_out = 8'b0;
        else
            case(opcode)
                7'b01100_11 : Ctl_out = 8'b001000_10;
                7'b00100_11 : Ctl_out = 8'b101000_11;
                7'b00000_11 : Ctl_out = 8'b111100_00;
                7'b01000_11 : Ctl_out = 8'b100010_00;
                7'b11000_11 : Ctl_out = 8'b000001_01;
                7'b11011_11 : Ctl_out = 8'b001001_00;
                7'b11001_11 : Ctl_out = 8'b101001_11;
                default : Ctl_out = 8'b0;
            endcase
    end
endmodule
