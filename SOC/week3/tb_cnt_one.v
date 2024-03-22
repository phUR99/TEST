`timescale 1ns / 1ps

module tb_cnt_one();
    reg [3:0] rega;
    wire [2:0] count;
    cnt_one u0(.rega(rega), .count(count));
    initial begin
        $dumpfile("test.vcd");
        $dumpvars(-1, u0);
        
        rega      = 4'b1111;
        # 20 rega = 4'b1110;
        # 20 rega = 4'b1101;
        # 1
        $finish;                
    end
    
endmodule
