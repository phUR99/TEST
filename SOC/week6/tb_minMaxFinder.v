module tb_minMaxFinder;
reg clk;
reg [2:0] WriteReg;
reg [15 :0] WriteData;
reg WriteEn;
wire [15:0] min, Max;
wire Vaild;
integer i;
Top UDT(.clk(clk), .WriteReg(WriteReg), .WriteData(WriteData), .WriteEn(WriteEn), .min(min), .Max(Max), .Vaild(Vaild));
always #5 clk = ~clk;

initial begin
    clk = 0;
    WriteData = 1;
    WriteReg = 0;
    WriteEn = 0;
    #10 WriteEn = 1;
    for (i = 1; i < 8; i = i +1) begin
        if (i ==7)  begin
        #10 WriteData = 0;
            WriteReg = i; 
        end
        else begin
        #10 WriteData = WriteData << 1;
            WriteReg = i;
        end
    end
    #100 $finish;
end
endmodule