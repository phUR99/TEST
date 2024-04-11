module shift_reg (clk, rst, sin, sout);
    // 입력
    input clk, rst, sin;
    // 출력
    output sout;
    // always 구문에서 실행하기 위한 reg q
    reg [7:0] q;
    // sout은 q[7]
    assign sout = q[7];

    always @(posedge clk or negedge rst) begin
        //reset
        if(!rst) begin
            q <= 0;
        end
        //non_blocking 구문을 활용하여 갱신
        else begin
            q[0] <= sin;
            q[1] <= q[0];
            q[2] <= q[1];
            q[3] <= q[2];
            q[4] <= q[3];
            q[5] <= q[4];
            q[6] <= q[5];
            q[7] <= q[6]; 
            // q <= {q[6:0], sin};           
        end    
    end
    
endmodule