module OZOdetector (
    input clk, rstb,
    input PUSH_SW_LEFT, PUSH_SW_RIGHT,
    output LED
);
    localparam  S0 =  2'b00,
                S1 =  2'b01,
                S2 =  2'b10,
                S3 =  2'b11;
    reg [1:0] pre_state, nxt_state;
    wire left, right;
    
    debounce_switch btn0(
        .i_clk(clk),
        .i_switch(PUSH_SW_LEFT),
        .o_switch(left)
    );
    debounce_switch btn1(
        .i_clk(clk),
        .i_switch(PUSH_SW_RIGHT),
        .o_switch(right)
    );    
    
    //LED 현재 상태가 S3 일 때 불빛이 들어오도록 했습니다.
    assign LED = (pre_state == S3) ? 1'b1 : 1'b0;


    always @(pre_state or left or right) begin
        
        /*
        left = 0, right = 1;
        0
        S0 left S0, right S1
        1
        S1 left S2, right S1
        10
        S2 left S0, right S3
        101
        S3 left S2, right S1
        */
        case (pre_state)
            S0 : if (left) nxt_state = S0; else if(right) nxt_state = S1; else nxt_state = S0;
            S1 : if (left) nxt_state = S2; else if(right) nxt_state = S1; else nxt_state = S1;
            S2 : if (left) nxt_state = S0; else if(right) nxt_state = S3; else nxt_state = S2;
            S3 : if (left) nxt_state = S2; else if(right) nxt_state = S1; else nxt_state = S3;
            default: nxt_state = S0;
        endcase
    end           

    always @(posedge clk or negedge rstb) begin
        if(!rstb) pre_state <= S0; else pre_state <= nxt_state;       
    end     


endmodule