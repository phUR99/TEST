`timescale 1ns / 1ps

module tb_cnt_one();
    reg [7:0] rega;
    wire [3:0] count;
    cnt_one u0(.rega(rega), .count(count));
    
    initial begin
        $dumpfile("test.vcd");
        $dumpvars(-1, u0);
        for (rega = 0; rega <256; rega = rega +1) begin
            #20;
        end        
        $finish;                
    end
    
endmodule
