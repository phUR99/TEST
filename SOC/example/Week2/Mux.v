`timescale 1ns / 1ps

module Mux(x0, x1, x2, x3, s0, s1, out);

input x0, x1, x2, x3;
input s0, s1;
output reg out;

always @(s0, s1) begin
    if(s1) begin
        if(s0)  out = x3;
        else    out = x2;
    end
    else begin
        if(s0)  out = x1;
        else    out = x0;
    end
end

always @(s0, s1) begin
    case({s1, s0}) 
        2'b00 : out = x0;
        2'b01 : out = x1;
        2'b10 : out = x2;
        2'b11 : out = x3;
    endcase
end

endmodule
