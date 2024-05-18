`timescale 1ns / 1ps

module RisingEdgeDetector_tb;

    reg clk;
    reg rstb;
    reg PUSH_SW_LEFT;
    reg PUSH_SW_RIGHT;

    wire LED;

    RisingEdgeDetector UUT (
        .clk(clk),
        .rstb(rstb),
        .PUSH_SW_LEFT(PUSH_SW_LEFT),
        .PUSH_SW_RIGHT(PUSH_SW_RIGHT),
        .LED(LED)
    );
    always begin
        #5 clk = ~clk; 
    end

  
    initial begin
        clk = 0;
        rstb = 0;
        PUSH_SW_LEFT = 0;
        PUSH_SW_RIGHT = 0;
        
        #10 rstb = 1;

        // 10010011 입력을 구현했습니다.
        #10 PUSH_SW_LEFT = 0; PUSH_SW_RIGHT = 1; 
        #10 PUSH_SW_LEFT = 1; PUSH_SW_RIGHT = 0; 
        #10 PUSH_SW_LEFT = 1; PUSH_SW_RIGHT = 0; 
        #10 PUSH_SW_LEFT = 0; PUSH_SW_RIGHT = 1; 
        #10 PUSH_SW_LEFT = 1; PUSH_SW_RIGHT = 0; 
        #10 PUSH_SW_LEFT = 1; PUSH_SW_RIGHT = 0; 
        #10 PUSH_SW_LEFT = 0; PUSH_SW_RIGHT = 1; 
        #10 PUSH_SW_LEFT = 0; PUSH_SW_RIGHT = 1; 

        // 종료
        #100 $finish;
    end

endmodule
