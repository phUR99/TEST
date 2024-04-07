module tb_shift_reg();
    reg clk, sin, rst;
    wire sout;

    shift_reg uut(clk, rst, sin, sout);

    initial begin
        clk = 1'b0;
    
        forever   #10 clk = ~clk;       
    end
    initial begin
        rst = 1'b0;
        #5 rst = 1'b1;
    end
    initial begin
        sin = 1'b0;
        #15 sin = 1'b1; #20 sin = 1'b0;
        #20 sin = 1'b1; #20 sin = 1'b0;
        #20 sin = 1'b1; #10 sin = 1'b0;
        #20 sin = 1'b1; #10 sin = 1'b0;
        #20 sin = 1'b1; #10 sin = 1'b0;
    end    

 endmodule   