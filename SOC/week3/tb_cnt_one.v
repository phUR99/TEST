`timescale 1ns / 1ps

module tb_cnt_one();
    //input
    reg [7:0] rega;
    //output
    wire [3:0] count;
    //uut
    cnt_one u0(.rega(rega), .count(count));
    //0 ~ 255까지 rega의 값을 변화    
    initial begin
        for (rega = 0; rega <256; rega = rega +1) begin
            #20;
        end                 
    end
    
endmodule
