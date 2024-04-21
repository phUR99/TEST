`timescale 1ns / 1ps

module Counter( //빨간 카운터
WriteEn, 
Start,
clk,
rst
    );
    input clk;
    input rst;
    input WriteEn;
    output reg Start;
    reg [3:0] count;

    always @(posedge clk or negedge rst) begin
	if(!rst) begin
		Start <=0;
		count <=0;
	end
	else begin
            if (count == 7) Start <= 1; //8clock 다 셌을 때 Start는 1
            else begin
            //Start <= 0; //8clock 다 세지 않은 경우 Start는 0
               if (WriteEn) count <= count + 1; //Write가 되는 시점에서는 count되도록
            end //if(count else
	end// if(!rst else 
    end //always
endmodule


