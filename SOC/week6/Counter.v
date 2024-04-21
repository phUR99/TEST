module Counter (
    Start, clk, WriteEn
);
    input clk, WriteEn;
    output Start;
    // 8번을 세는 counter
    reg [7:0] q;
    // 8번째 bit를 Start로 출력하게 했다.
    assign Start = q[7];

    // clk의 에지마다
    always @(posedge clk) begin
        // writeEn이 들어오지 않을 경우에는 0으로 초기화
        if (!WriteEn) begin
            q <= 0;
        end
        else begin
        // writeEn이 들어올 경우에는 shift를 하면서 count를 해준다.
            q[0] <= WriteEn;
            q[1] <= q[0];
            q[2] <= q[1];
            q[3] <= q[2];
            q[4] <= q[3];
            q[5] <= q[4];
            q[6] <= q[5];
            q[7] <= q[6];
        end    
    end

endmodule

module Counter_blue (
    clk, ReadRegEven, ReadRegOdd, Start
);
    input clk, Start;
    output reg [1:0] ReadRegEven, ReadRegOdd;

    always @(posedge clk)begin
        if (!Start) begin
            //start가 들어오지 않을 경우 0으로 초기화한다.
            ReadRegEven <= 2'b00;
            ReadRegOdd  <= 2'b00;            
        end
        else begin
            //start가 들어올 경우 +1을 해준다.
            ReadRegEven <= ReadRegEven + 1;
            ReadRegOdd <= ReadRegOdd + 1;
        end    
    end


endmodule