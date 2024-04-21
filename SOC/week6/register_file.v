module register_file (
    clk, ReadRegOdd, ReadRegEven, WriteReg, WriteEn, WriteData,
    ReadDataEven, ReadDataOdd
);


    input clk;
    input WriteEn;
    input [15:0] WriteData;
    output [15:0] ReadDataEven, ReadDataOdd;
    input [1:0] ReadRegEven, ReadRegOdd;
    input [2:0] WriteReg;
        
    reg [15:0] reg_file [0:7];
    //주소에 해당하는 값을 출력해준다.
    assign ReadDataEven = reg_file[2 * ReadRegEven];
    assign ReadDataOdd = reg_file[2 * ReadRegOdd + 1];
    //주소에 해당하는 값을 register file에 작성한다.
    always @(posedge clk) begin
        if (WriteEn) reg_file[WriteReg] <= WriteData;
    end

endmodule