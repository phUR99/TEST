`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2020/04/09 13:34:10
// Design Name: 
// Module Name: test_seg
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

module seven(
    input clk,
    input PUSH_SW_UP, PUSH_SW_LEFT, PUSH_SW_RIGHT, PUSH_SW_DOWN,
    input rstb,
    output reg [7:0] seg,
    output [7:0] digit  );

reg [24:0] tmp;
reg       i_clk;
reg [3:0] seg_cnt;

assign digit = 8'b10000000;
//assign seg = 8'b11111101;

//*********************************************************************
//********************  Clock Divide **********************
//*********************************************************************
always@(posedge clk) begin
    if (!rstb) begin
       tmp   <= 0;
       i_clk <= 0;
       end
       else begin
       if ( tmp == 25'h17D7840) begin
            tmp <= 0;
            i_clk <= ~i_clk;
            end
            else begin
            tmp <= tmp + 1;
            i_clk <= i_clk;
            end
         end
     end
//*********************************************************************
//*************  Segment Operation Condition Generation **************
//*********************************************************************
always@(posedge i_clk) begin
    if (!rstb) begin
       seg_cnt   <= 0;
       end
    else begin
        seg_cnt <= {PUSH_SW_DOWN, PUSH_SW_RIGHT, PUSH_SW_LEFT, PUSH_SW_UP};        
    end     
end
//*********************************************************************
//***************  Segment Operation Signal Generation ***************
//*********************************************************************
   always @(posedge i_clk) begin
      case (seg_cnt)
        4'b0000 : seg <= 8'b00111111;
        4'b0001 : seg <= 8'b00000110;
        4'b0010 : seg <= 8'b01011011;
        4'b0011 : seg <= 8'b01001111;
        4'b0100 : seg <= 8'b01100110;
        4'b0101 : seg <= 8'b01101101;
        4'b0110 : seg <= 8'b01111101;
        4'b0111 : seg <= 8'b00000111;
        4'b1000 : seg <= 8'b01111111;
        4'b1001 : seg <= 8'b01101111;
        4'b1010 : seg <= 8'b01110111;
        4'b1011 : seg <= 8'b01111100;
        4'b1100 : seg <= 8'b01011000;
        4'b1101 : seg <= 8'b01011110;
        4'b1110 : seg <= 8'b01111001;
        4'b1111 : seg <= 8'b01110001;
      endcase
    end
endmodule
