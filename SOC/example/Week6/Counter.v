`timescale 1ns / 1ps

module Counter( //���� ī����
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
            if (count == 7) Start <= 1; //8clock �� ���� �� Start�� 1
            else begin
            //Start <= 0; //8clock �� ���� ���� ��� Start�� 0
               if (WriteEn) count <= count + 1; //Write�� �Ǵ� ���������� count�ǵ���
            end //if(count else
	end// if(!rst else 
    end //always
endmodule


