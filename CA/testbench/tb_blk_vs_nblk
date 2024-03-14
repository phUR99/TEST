`timescale 1ns / 1ps



module tb_blk_vs_nonblk();
    //input
    reg d,clk;
    //output
    wire q3;
    
    non_blk2 uut(.clk(clk), .d(d), .q3(q3));
    
    always #5 clk =~ clk;
    
    initial begin
    d= 1'b0;
    clk = 1'b0;
    #12 d=1'b1;
    end    
endmodule
