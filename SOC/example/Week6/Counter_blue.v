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
            if (Start == 1) begin //빨간색 Counter에서 8clock을 다 세고 1을 보낸 경우(레지스터 파일에 값을 모두 썼을 때) 
              ReadRegOdd  <= ReadRegOdd  + 2; //clk마다 주소가 2씩 증가하도록 
              ReadRegEven <= ReadRegEven + 2;
            end
            else begin
              ReadRegEven <= 0; //even이므로 0부터 시작
              ReadRegOdd  <= 1; //odd이므로 1부터 시작
            end
       end//else
    end//always
endmodule
