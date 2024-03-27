`timescale 1ns / 1ps

module tb_encoder();
    //input 
    reg[7:0] i;
    //output
    wire[2:0] e;
    //uut
    encoder u0(.i(i), .e(e));
    //input의 값을 0~255까지 변화
    initial begin
        for (i = 0; i <256; i = i +1) begin
            #20;
        end        
    end
endmodule