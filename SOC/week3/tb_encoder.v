`timescale 1ns / 1ps

module tb_encoder ();
    reg[7:0] i;
    wire[2:0] e;
    encoder u0(.i(i), .e(e));
    
    initial begin
        $dumpfile("test.vcd");
        $dumpvars(-1, u0); 
        for (i = 0; i <256; i = i +1) begin
            #20;
        end        
        $finish;    

    end

endmodule