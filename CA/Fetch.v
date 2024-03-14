`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/05/01 16:22:43
// Design Name: 
// Module Name: Fetch
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


module PC(
    input clk,reset,
    input PCWrite,
    input [31:0] PC_in, //PC+4 (즉, branch/jump가 없을 때 다음 PC 값)
    output reg [31:0] PC_out //다음 PC 값
    
    );
    always @(posedge clk) begin
        if (reset) PC_out <= 0;
        else if (PCWrite) PC_out <=PC_out;
        else PC_out <= PC_in;
    end
endmodule

module iMEM(
    input clk, reset,
    input IF_ID_Write, PCSrc,
    input [31:0] PC_in, //현재 PC 값
    output reg [31:0] instruction_out //instruction이 저장되는 port

    );
    parameter ROM_size =1024;
    reg [31:0] ROM[0:ROM_size-1]; //32bit짜리 mem을 (ROM_size)개 생성
    integer i;
    initial begin
        for (i=0; i!=ROM_size; i=i+1) begin
            ROM[i] = 32'b0;
        end
        $readmemh("darksocv.rom.mem", ROM);
    end
    //BRAM
    always @(posedge clk) begin
        if(!IF_ID_Write) begin  //not stall      
            if (reset || PCSrc) instruction_out <=32'b0;
            else instruction_out <= ROM[PC_in[31:2]];
        end    
    end
endmodule

module InFetch(
    input clk,reset,PCSrc, //branch 될 때 PC+Immediate 값을 PC에 저장하기 위한 신호
    input PCWrite,
    input [31:0] PCimm_in, //PC+immediate 값
    output [31:0] instruction_out, //instruction이 저장되는 port
    output reg [31:0] PC_out //현재 PC 값
    );
    wire [31:0] PC;
    wire [31:0] PC4 = (PCSrc)? PCimm_in: PC +4;

    PC B1_PC(.clk(clk), .reset(reset), .PCWrite(PCWrite), .PC_in(PC4), .PC_out(PC));
    iMEM B2_iMEM(.clk(clk), .reset(reset),.IF_ID_Write(PCWrite),.PCSrc(PCSrc), .PC_in(PC), .instruction_out(instruction_out));
    
    
    
    always @(posedge clk) begin
        if(reset||PCSrc) PC_out <=0;
        else if (PCWrite) PC_out <= PC_out;
        else PC_out <= PC;
    end
endmodule
    
        
