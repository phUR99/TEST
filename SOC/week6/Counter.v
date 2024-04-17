module Counter (
    Start, clk, WriteEn
);
    input clk, WriteEn;
    output Start;
    reg [7:0] q;
    assign Start = q[7];

    always @(posedge clk) begin
        if (!WriteEn) begin
            q <= 0;
        end
        else begin
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
            ReadRegEven <= 2'b00;
            ReadRegOdd  <= 2'b00;            
        end
        else begin
            ReadRegEven <= ReadRegEven + 1;
            ReadRegOdd <= ReadRegOdd + 1;
        end    
    end


endmodule