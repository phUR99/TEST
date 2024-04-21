`timescale 1ns / 1ps
module RegisterFile(
clk,
rst,
WriteEn,
WriteReg,
WriteData,
ReadRegEven,
ReadRegOdd,
ReadDataEven,
ReadDataOdd
    );
    input clk;
    input rst;
    input WriteEn;
    input [2:0] WriteReg;
    input [15:0] WriteData;
    input [2:0] ReadRegEven;
    input [2:0] ReadRegOdd;
    output [15:0] ReadDataEven;
    output [15:0] ReadDataOdd;
    reg [15:0] mem[0:7];
    
    assign ReadDataEven =  mem[ReadRegEven];
    assign ReadDataOdd  =  mem[ReadRegOdd];
    always @(posedge clk or negedge rst) begin //Write될 때는 clock에 맞추어
	if(!rst)  begin
          mem[0] <=0;
          mem[1] <=0;
          mem[2] <=0;
          mem[3] <=0;
          mem[4] <=0;
          mem[5] <=0;
          mem[6] <=0;
          mem[7] <=0;
	end 
	else begin
           if (WriteEn == 1) begin //Write enable이 1일 때 write되도록
            mem[WriteReg] <= WriteData;
           end
	end  //if(!rst else
end //always
    
endmodule

