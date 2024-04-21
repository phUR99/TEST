`timescale 1ns / 1ps

module cnt_one_8b(rega, count);

input [7:0] rega;
output [3:0] count;
reg [7:0] temp_reg;
reg [3:0] count;

always @(rega) begin
    count = 0;
    temp_reg = rega;
    while(temp_reg) begin
        if(temp_reg[0]) count = count+1;
        temp_reg = temp_reg >> 1;
    end
end
endmodule
