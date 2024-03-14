`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/05/18 16:56:58
// Design Name: 
// Module Name: RISCVpipeline
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


module RISCVpipeline(
    output [31:0] current_pc,
    output [31:0] instruction,
    
    input clk,rst
    );
    wire c;
    wire [1:0]  LED_clk;
    wire [31:0] pc, ins;
    wire ind_ctl_0, ind_ctl_1, ind_ctl_2, ind_ctl_3, ind_ctl_4, ind_ctl_5, ind_ctl_6, ind_ctl_7;
    wire exe_ctl_0, exe_ctl_1, exe_ctl_2, exe_ctl_3, exe_ctl_4, exe_ctl_5, exe_ctl_6, exe_ctl_7;
    wire [1:0] ForwardA, ForwardB;
    wire stall;
    wire mem_ctl_0, mem_ctl_1, mem_ctl_2, mem_ctl_3, mem_ctl_4, mem_ctl_5, mem_ctl_6, mem_ctl_7;
    wire wb_ctl_0, wb_ctl_1, wb_ctl_2, wb_ctl_3, wb_ctl_4, wb_ctl_5, wb_ctl_6, wb_ctl_7;
    
    wire [31:0] ind_pc, exe_pc, mem_pc;
    wire [31:0] ind_data1, ind_data2, ind_imm, exe_data2, exe_addr, exe_result, mem_addr, mem_result, mem_data, wb_data;
    wire [4:0] ind_rd, exe_rd, mem_rd, wb_rd;
    wire [6:0] ind_funct7;
    wire [2:0] ind_funct3;
    wire ind_jal, ind_jalr, exe_zero, mem_PCSrc;
    wire exe_jal, exe_jalr;
    wire mem_jal, mem_jalr;
    
    assign current_pc =pc;
    assign instruction =ins;
    
    InFetch A1_InFetch(clk, rst, mem_PCSrc, stall, mem_addr,ins, pc);
    
    Hazard_detection_unit A2_Hazard_detection(ind_ctl_3, ind_rd, ins[24:15], stall);
    
    wire [4:0] ind_rs1,ind_rs2;

    InDecode A3_InDecode(clk, rst, 
    stall, mem_PCSrc,
     wb_ctl_0,
    ind_ctl_0, ind_ctl_1, ind_ctl_2, ind_ctl_3, ind_ctl_4, ind_ctl_5, ind_ctl_6, ind_ctl_7,
     wb_rd, 
     pc,ins, wb_data,
    ind_rd, ind_rs1, ind_rs2,
    ind_pc, ind_data1, ind_data2,ind_imm,
    ind_funct7,
    ind_funct3,
    ind_jalr,ind_jal
    );
    
    Forwarding_unit A33_Forwarding_unit(exe_ctl_1, mem_ctl_1, ind_rs1, ind_rs2, exe_rd, wb_rd, ForwardA, ForwardB);
    
 
    Execution A4_Exection(clk,rst,
    mem_PCSrc,
    ind_ctl_0, ind_ctl_1, ind_ctl_2, ind_ctl_3, ind_ctl_4, ind_ctl_5, ind_ctl_6, ind_ctl_7,
    exe_ctl_0, exe_ctl_1, exe_ctl_2, exe_ctl_3, exe_ctl_4, 
    ind_rd,
    exe_rd,
    ind_jal, ind_jalr,
    exe_jal, exe_jalr,
    ind_imm, ind_data1, ind_data2,ind_pc,
    exe_result, wb_data,
    ind_funct7,
    ind_funct3,
    ForwardA, ForwardB,
    exe_zero,
    exe_result, exe_addr,exe_data2, exe_pc
    
    );
    
    Memory A6_Memory(
    rst, clk,
    exe_ctl_0, exe_ctl_1, exe_ctl_2, exe_ctl_3, exe_ctl_4, 
    mem_ctl_0, mem_ctl_1,
    exe_rd, mem_rd,
    exe_jal, exe_jalr,
    
    exe_zero,
    exe_data2,exe_result,exe_addr, exe_pc,
    mem_PCSrc,
    mem_jal, mem_jalr, 
    
    mem_data, mem_result, mem_pc,
    mem_addr   
    );
    
    WB A7_WB(
    mem_ctl_1, mem_ctl_0,
    wb_ctl_0,          
    mem_jal, mem_jalr,
    mem_pc,
    mem_rd,
    mem_data,mem_result,
    wb_rd,
    wb_data       
    
    );
endmodule
    
