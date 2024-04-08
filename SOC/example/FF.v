module FF (
    q, din, clk, rst
);
    input din, clk, rst;
    output reg q;
    
always @(posedge clk or negedge rst) begin
    if (rst == 0) q <= 0;
    else q <= din;
end    


endmodule