`timescale 1ns / 1ps

module Counter_blue(
clk,
rst,
Start,
ReadRegEven,
ReadRegOdd
    ); 
    input clk;
    input rst;
    input Start;
    output reg [2:0] ReadRegEven;
    output reg [2:0] ReadRegOdd;
    
    always @(posedge clk or negedge rst) begin 
	if(!rst) begin
           ReadRegEven <= 0;
           ReadRegOdd  <= 1;
	end
	else begin
            if (Start == 1) begin //������ Counter���� 8clock�� �� ���� 1�� ���� ���(�������� ���Ͽ� ���� ��� ���� ��) 
              ReadRegOdd  <= ReadRegOdd  + 2; //clk���� �ּҰ� 2�� �����ϵ��� 
              ReadRegEven <= ReadRegEven + 2;
            end
            else begin
              ReadRegEven <= 0; //even�̹Ƿ� 0���� ����
              ReadRegOdd  <= 1; //odd�̹Ƿ� 1���� ����
            end
       end//else
    end//always
endmodule
