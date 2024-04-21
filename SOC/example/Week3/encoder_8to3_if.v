`timescale 1ns / 1ps

module encoder_8to3_if(i, e);

input [7:0] i;
output [2:0] e;
reg [2:0] e;

always @(*) begin
    if(i[0]) e=3'b000;
    else if(i[1]) e=3'b001;
    else if(i[2]) e=3'b010;
    else if(i[3]) e=3'b011;
    else if(i[4]) e=3'b100;
    else if(i[5]) e=3'b101;
    else if(i[6]) e=3'b110;
    else if(i[7]) e=3'b111;
    else e=3'bxxx;
end

endmodule
